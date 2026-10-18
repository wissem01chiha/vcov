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

#include "FilterPCH.h"
#include "FilterExport.h"
#include "ICoverageFilterManager.hpp"
#include "LineFilter.hpp"
#include "UnifiedDiffCoverageFilterManager.hpp"
#include "WildcardCoverageFilter.hpp"

namespace FileFilter
{
    class ReleaseCoverageFilter;
}

namespace CppCoverage
{
    class CoverageFilterSettings;
    class UnifiedDiffSettings;

    class VCOV_FILTEREXPORT_DLL CoverageFilterManager : public ICoverageFilterManager
    {
      public:
        explicit CoverageFilterManager(const CoverageFilterSettings&,
                                       const std::vector<UnifiedDiffSettings>&,
                                       const std::vector<std::wstring>& excludedLineRegexes,
                                       bool                             useReleaseCoverageFilter);

        ~CoverageFilterManager();

        bool IsModuleSelected(const std::wstring& filename) const override;
        bool IsSourceFileSelected(const std::wstring& filename) override;
        bool IsLineSelected(const FileFilter::ModuleInfo&, const FileFilter::FileInfo&,
                            const FileFilter::LineInfo&) override;

        std::vector<std::wstring> ComputeWarningMessageLines(size_t maxUnmatchPaths) const;

      private:
        CoverageFilterManager(const CoverageFilterManager&)            = delete;
        CoverageFilterManager& operator=(const CoverageFilterManager&) = delete;

        const WildcardCoverageFilter     wildcardCoverageFilter_;
        UnifiedDiffCoverageFilterManager unifiedDiffCoverageFilterManager_;
        FileFilter::LineFilter           lineFilter_;

        const std::unique_ptr<FileFilter::ReleaseCoverageFilter> optionalReleaseCoverageFilter_;
    };
} // namespace CppCoverage
