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

#pragma warning(push)
#pragma warning(disable : 4275) // warning C4275: non dll-interface class 'std::exception'
                                // used as base for dll-interface class

namespace FileFilter
{
    class VCOV_FILTEREXPORT_DLL UnifiedDiffParserException : public std::runtime_error
    {
      public:
        static const std::wstring ErrorContextHunks;
        static const std::wstring ErrorNoFilenameBeforeHunks;
        static const std::wstring ErrorCannotReadLine;
        static const std::wstring ErrorExpectFromFilePrefix;
        static const std::wstring ErrorInvalidHunks;

        explicit UnifiedDiffParserException(const std::wstring& message);
    };
} // namespace FileFilter

#pragma warning(pop)
