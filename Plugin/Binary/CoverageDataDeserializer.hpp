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

#include "BinaryPCH.h"
#include "BinaryExport.h"

namespace Plugin
{

    class CoverageData;

}

namespace Exporter
{
    class VCOV_BINARYEXPORT_DLL CoverageDataDeserializer
    {
      public:
        CoverageDataDeserializer() = default;
        Plugin::CoverageData Deserialize(const std::filesystem::path&,
                                         const std::string& errorIfNotCorrectFormat) const;

      private:
        CoverageDataDeserializer(const CoverageDataDeserializer&)            = delete;
        CoverageDataDeserializer& operator=(const CoverageDataDeserializer&) = delete;
    };
} // namespace Exporter
