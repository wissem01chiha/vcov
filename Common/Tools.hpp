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

#define TARGET_FILE_NAME std::filesystem::u8path("../../bin/Debug/OpenCppCoverage.exe");

extern "C"
{
    void VCOV_COMMONEXPORT_DLL TestUnloadDll();
}

namespace Testing
{
    std::filesystem::path VCOV_COMMONEXPORT_DLL GetTestUnloadDllFilename();
    std::filesystem::path VCOV_COMMONEXPORT_DLL GetOutputBinaryPath();

    void VCOV_COMMONEXPORT_DLL CreateEmptyFile(const std::filesystem::path&);

    std::string VCOV_COMMONEXPORT_DLL RunProcess(const std::filesystem::path&    program,
                                                 const std::vector<std::string>& args);

    std::filesystem::path VCOV_COMMONEXPORT_DLL GetVisualStudioPath();

    //-------------------------------------------------------------------------
    template <typename ExceptionType, typename Fct>
    void AssertThrow(Fct fct, std::function<void(const ExceptionType&)> exceptionCheck)
    {
        try
        {
            fct();
        }
        catch (const ExceptionType& e)
        {
            exceptionCheck(e);
            return;
        }
        catch (...)
        {
            throw std::runtime_error("Expected exception not raised.");
        }
        throw std::runtime_error("No exception raised.");
    }
} // namespace Testing
