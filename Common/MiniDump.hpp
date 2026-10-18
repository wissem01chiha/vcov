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

#include "CommonExport.h"
#include "CommonPCH.h"

namespace Tools
{
    VCOV_COMMONEXPORT_DLL MINIDUMP_TYPE GetMiniDumpDefaultType();

    VCOV_COMMONEXPORT_DLL void CreateMiniDump(MINIDUMP_EXCEPTION_INFORMATION& minidumpInfo,
                                              HANDLE hFile, const wchar_t* dmpFilename);

    VCOV_COMMONEXPORT_DLL LONG WINAPI
    CreateMiniDumpOnUnHandledException(PEXCEPTION_POINTERS exceptionInfo);

    VCOV_COMMONEXPORT_DLL void CreateMiniDumpOnUnHandledException();
} // namespace Tools
