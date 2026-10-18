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
    class VCOV_FILTEREXPORT_DLL File
    {
      public:
        explicit File(const std::filesystem::path&);
        File(File&&)            = default;
        File& operator=(File&&) = default;

        void AddSelectedLines(const std::vector<int>&);

        const std::filesystem::path& GetPath() const;
        void                         SetPath(const std::filesystem::path&);

        bool                 IsLineSelected(int) const;
        const std::set<int>& GetSelectedLines() const;

        bool operator==(const File&) const;

      private:
        File(const File&)            = delete;
        File& operator=(const File&) = delete;

        std::filesystem::path path_;
        std::set<int>         selectedLines_;
    };
} // namespace FileFilter
