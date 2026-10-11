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

#include "ExportExport.h"
#include "ExportPCH.h"

namespace Plugin
{
    class FileCoverage;
}

namespace Plugin
{

    class VCOV_EXPORTEXPORT_DLL ModuleCoverage
    {
      public:
        typedef std::vector<std::unique_ptr<FileCoverage>> T_FileCoverageCollection;

      public:
        explicit ModuleCoverage(const std::filesystem::path& path);
        ~ModuleCoverage();

        FileCoverage& AddFile(const std::filesystem::path& filename);

        const std::filesystem::path&    GetPath() const;
        const T_FileCoverageCollection& GetFiles() const;

      private:
        ModuleCoverage(const ModuleCoverage&)            = delete;
        ModuleCoverage& operator=(const ModuleCoverage&) = delete;

      private:
        T_FileCoverageCollection files_;
        std::filesystem::path    path_;
    };

}; // namespace Plugin
