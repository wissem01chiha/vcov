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

#include "CoverageExport.h"
#include "CoveragePCH.h"
#include "CoverageFilterSettings.hpp"
#include "StartInfo.hpp"
#include "SubstitutePdbSourcePath.hpp"
#include "UnifiedDiffSettings.hpp"

namespace CppCoverage
{
    class VCOV_COVERAGEEXPORT_DLL RunCoverageSettings
    {
      public:
        RunCoverageSettings(const StartInfo&, const CoverageFilterSettings&,
                            const std::vector<UnifiedDiffSettings>&,
                            const std::vector<std::wstring>& excludedLineRegexes,
                            const std::vector<SubstitutePdbSourcePath>&);

        RunCoverageSettings(const RunCoverageSettings&)            = delete;
        RunCoverageSettings& operator=(const RunCoverageSettings&) = delete;

        void SetCoverChildren(bool);
        void SetContinueAfterCppException(bool);
        void SetStopOnAssert(bool);
        void SetMaxUnmatchPathsForWarning(size_t);
        void SetOptimizedBuildSupport(bool);

        const StartInfo&                            GetStartInfo() const;
        const CoverageFilterSettings&               GetCoverageFilterSettings() const;
        const std::vector<UnifiedDiffSettings>&     GetUnifiedDiffSettings() const;
        bool                                        GetCoverChildren() const;
        bool                                        GetContinueAfterCppException() const;
        bool                                        GetStopOnAssert() const;
        size_t                                      GetMaxUnmatchPathsForWarning() const;
        bool                                        GetOptimizedBuildSupport() const;
        const std::vector<std::wstring>&            GetExcludedLineRegexes() const;
        const std::vector<SubstitutePdbSourcePath>& GetSubstitutePdbSourcePaths() const;

      private:
        StartInfo                            startInfo_;
        CoverageFilterSettings               coverageFilterSettings_;
        std::vector<UnifiedDiffSettings>     unifiedDiffSettings_;
        bool                                 coverChildren_;
        bool                                 continueAfterCppException_;
        bool                                 stopOnAssert_;
        size_t                               maxUnmatchPathsForWarning_;
        bool                                 optimizedBuildSupport_;
        std::vector<std::wstring>            excludedLineRegexes_;
        std::vector<SubstitutePdbSourcePath> substitutePdbSourcePath_;
    };
} // namespace CppCoverage
