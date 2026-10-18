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

#include "HtmlExport.h"
#include "HtmlPCH.h"

namespace Exporter
{
    class VCOV_HTMLEXPORT_DLL HtmlFile
    {
      public:
        HtmlFile(std::filesystem::path absolutePath, std::filesystem::path relativeLinkPath);
        HtmlFile(const HtmlFile&) = default;

        const std::filesystem::path& GetAbsolutePath() const;
        const std::filesystem::path& GetRelativeLinkPath() const;

      private:
        HtmlFile& operator=(const HtmlFile&) = delete;

        std::filesystem::path absolutePath_;
        std::filesystem::path relativeLinkPath_;
    };
} // namespace Exporter
