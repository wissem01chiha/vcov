// Copyright (C) 2026 Vcov contributors 
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// Copyright (C) 2014 OpenCppCoverage
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "FilterExport.h"
#include "FilterPCH.h"

namespace FileFilter
{
    class UnifiedDiffCoverageFilter;
    class FileInfo;
    class LineInfo;
} // namespace FileFilter

namespace CppCoverage
{
    class UnifiedDiffSettings;

    class VCOV_FILTEREXPORT_DLL UnifiedDiffCoverageFilterManager
    {
      public:
        explicit UnifiedDiffCoverageFilterManager(const std::vector<UnifiedDiffSettings>&);

        using UnifiedDiffCoverageFilters =
            std::vector<std::unique_ptr<FileFilter::UnifiedDiffCoverageFilter>>;

        explicit UnifiedDiffCoverageFilterManager(UnifiedDiffCoverageFilters&&);

        ~UnifiedDiffCoverageFilterManager();

        bool IsSourceFileSelected(const std::wstring& filename);
        bool IsLineSelected(const FileFilter::FileInfo&, const FileFilter::LineInfo&);

        std::vector<std::wstring> ComputeWarningMessageLines(size_t maxUnmatchPaths) const;

      private:
        UnifiedDiffCoverageFilterManager(const UnifiedDiffCoverageFilterManager&) = delete;
        UnifiedDiffCoverageFilterManager&
        operator=(const UnifiedDiffCoverageFilterManager&) = delete;

        std::vector<std::wstring>
        ComputeWarningMessageLines(const std::set<std::filesystem::path>& unmatchPaths,
                                   size_t                                 maxUnmatchPaths) const;

        const std::set<int>&             GetExecutableLinesSet(const FileFilter::FileInfo&);
        const UnifiedDiffCoverageFilters unifiedDiffCoverageFilters_;

        struct ExecutableLineCache
        {
            std::filesystem::path currentFilePath;
            std::set<int>         executableLinesSet;
        };

        ExecutableLineCache executableLineCache_;
    };
} // namespace CppCoverage
