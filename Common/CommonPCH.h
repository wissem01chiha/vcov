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

#include "VcovConfig.h"

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN 
// Windows Header Files:
#include <windows.h>

// STL Headers
#include <filesystem>
#include <memory>
#include <string>
#include <fstream>
#include <tchar.h>
#include <vector>
#include <iosfwd>
#include <exception>
#include <sstream>
#include <string>
#include <set>
#include <codecvt>
#include <system_error>
#include <iostream>
#include <functional>
#include <ctime>
#include <random>
#include <DbgHelp.h>

// Boost Headers
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/trivial.hpp>
#include <boost/optional/optional_fwd.hpp>
#include <boost/locale.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/optional/optional.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

// Poco Headers
#include <Poco/Pipe.h>
#include <Poco/PipeStream.h>
#include <Poco/Process.h>

#if VCOV_BUILD_TESTS
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#endif