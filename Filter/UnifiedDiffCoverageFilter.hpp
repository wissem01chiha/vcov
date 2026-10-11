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
#include "PathMatcher.hpp"
#include "FilterPCH.h"

namespace FileFilter
{
    class File;

    class VCOV_FILTEREXPORT_DLL UnifiedDiffCoverageFilter
    {
      public:
        UnifiedDiffCoverageFilter(const std::filesystem::path&                  unifiedDiffPath,
                                  const boost::optional<std::filesystem::path>& rootDiffFolder);

        UnifiedDiffCoverageFilter(std::vector<File>&&,
                                  const boost::optional<std::filesystem::path>& rootDiffFolder);

        bool IsSourceFileSelected(const std::filesystem::path&);
        bool IsLineSelected(const std::filesystem::path&, int lineNumber);
        std::vector<std::filesystem::path> GetUnmatchedPaths() const;

      private:
        UnifiedDiffCoverageFilter(const UnifiedDiffCoverageFilter&)            = delete;
        UnifiedDiffCoverageFilter& operator=(const UnifiedDiffCoverageFilter&) = delete;
        UnifiedDiffCoverageFilter(UnifiedDiffCoverageFilter&&)                 = delete;
        UnifiedDiffCoverageFilter& operator=(UnifiedDiffCoverageFilter&&)      = delete;

        File* SearchFile(const std::filesystem::path&);

        std::filesystem::path lastPath_;
        File*                 lastFile_;
        PathMatcher           pathMatcher_;
    };
} // namespace FileFilter
