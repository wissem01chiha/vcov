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

#include "CoreExport.h"
#include "ExceptionBase.hpp"
#include "CorePCH.h"

namespace CppCoverage
{
    VCOV_COREEXPORT_DLL std::wstring GetErrorMessage(int errorCode);
}

GENERATE_EXCEPTION_CLASS(CppCoverage, CppCoverageException);

#define THROW(message) THROW_BASE(CppCoverage, CppCoverageException, message)
#define THROW_LAST_ERROR(message, lastErrorCode)                                                   \
    THROW_BASE(CppCoverage, CppCoverageException,                                                  \
               message << CppCoverage::GetErrorMessage(lastErrorCode))
