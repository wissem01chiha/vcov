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
    VCOV_COMMONEXPORT_DLL std::wstring LocalToWString(const std::string&);
    VCOV_COMMONEXPORT_DLL std::wstring Utf8ToWString(const std::string&);
    VCOV_COMMONEXPORT_DLL std::string ToLocalString(const std::wstring&);
    VCOV_COMMONEXPORT_DLL std::string ToUtf8String(const std::wstring&);

    VCOV_COMMONEXPORT_DLL boost::optional<std::wstring> Try(std::function<void()>);

    template <typename Exception, typename Fct>
    decltype(auto) Try(Fct fct, std::function<std::string(const std::string&)> buildErrorMsg)
    {
        std::string error;
        try
        {
            return fct();
        }
        catch (const std::exception& e)
        {
            error = e.what();
        }
        catch (...)
        {
            error = "Unknow";
        }

        throw Exception(buildErrorMsg(error));
    }

    VCOV_COMMONEXPORT_DLL std::filesystem::path GetExecutableFolder();

    VCOV_COMMONEXPORT_DLL void ShowOutputMessage(const std::wstring&          message,
                                                 const std::filesystem::path& path);
    VCOV_COMMONEXPORT_DLL std::wstring GetSeparatorLine();

    VCOV_COMMONEXPORT_DLL void CreateParentFolderIfNeeded(const std::filesystem::path& path);
    VCOV_COMMONEXPORT_DLL bool FileExists(const std::filesystem::path& path);
} // namespace Tools
