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

#include "OptionExport.h"

namespace boost
{
    namespace program_options
    {
        class options_description;
    }
} // namespace boost

namespace CppCoverage
{
    class Options;
    class ProgramOptionsVariablesMap;

    class VCOV_OPTIONEXPORT_DLL IOptionParser
    {
      public:
        virtual ~IOptionParser() = default;

        virtual void ParseOption(const ProgramOptionsVariablesMap&, Options&) = 0;
        virtual void AddOption(boost::program_options::options_description&)  = 0;
    };
} // namespace CppCoverage
