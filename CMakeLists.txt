cmake_minimum_required(VERSION 3.20...3.31 FATAL_ERROR)

project(vcov LANGUAGES C CXX)

if(NOT WIN32)
    message(FATAL_ERROR "vcov is only supported on Windows.")
endif()

set(PROJECT_VERSION "0.9.10.0")
set(PROJECT_HOMEPAGE_URL "https://github.com/wissem01chiha/vccov")
set(PROJECT_DESCRIPTION "Open-Source Code Coverage for Visual C++ on Windows")

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

include(Option)

vcov_option(VCOV_BUILD_TESTS "Build unit tests" ON)
vcov_option(VCOV_BUILD_EXAMPLES "Build example programs" OFF)
vcov_option(VCOV_INSTALL "Enable installation targets" ON)
vcov_option(BUILD_SHARED_LIBS "Build shared libraries" ON)
vcov_option(VCOV_ASAN "Enable AddressSanitizer (ASan)" OFF)
vcov_option(VCOV_MSAN "Enable MemorySanitizer (MSan)" OFF)
vcov_option(VCOV_UBSAN "Enable UndefinedBehaviorSanitizer (UBSan)" OFF)

include(Module)
include(Sanitizer)
include(GNUInstallDirs)
if(VCOV_BUILD_TESTS)
    include(CTest)
    include(Testing)
endif()

find_package(Dia REQUIRED)
find_program(PROTOC protoc REQUIRED)
find_package(Boost 1.83 REQUIRED COMPONENTS 
    filesystem 
    program_options 
    algorithm 
    log 
    iostreams 
    locale 
    optional 
    container 
    regex 
    range 
    property_tree 
    spirit 
    uuid)
if(VCOV_BUILD_TESTS)
    find_package(GTest 1.17.0 REQUIRED)
endif()
find_package(Protobuf CONFIG REQUIRED)
find_package(CTemplate REQUIRED)
find_package(Poco REQUIRED COMPONENTS Foundation)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/VcovConfig.h.in 
    ${CMAKE_CURRENT_BINARY_DIR}/VcovConfig.h
)

if(VCOV_BUILD_TESTS)
    add_subdirectory(Utilities/Testing) 
endif()

add_subdirectory(Common)
add_subdirectory(Core)
add_subdirectory(Platform)
add_subdirectory(Export)
add_subdirectory(Option)
add_subdirectory(Filter)
add_subdirectory(Plugin/Core)
add_subdirectory(Plugin/Binary)
add_subdirectory(Coverage)
add_subdirectory(Plugin/Cobertura)
add_subdirectory(Plugin/Html)
add_subdirectory(Console)

if(VCOV_BUILD_TESTS)
   add_subdirectory(Testing)
endif()
if(VCOV_BUILD_EXAMPLES)
    add_subdirectory(Examples)
endif()
include(Install)

message(STATUS "")
message(STATUS "Vcov Build Summary")
message(STATUS "=====================================================================")
message(STATUS "Project Version:   ${PROJECT_VERSION}")
message(STATUS "Platfrom:          ${CMAKE_GENERATOR_PLATFORM}")
message(STATUS "Architecture:      ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Available Configs: ${CMAKE_CONFIGURATION_TYPES}")
message(STATUS "CMake Version:     ${CMAKE_VERSION}")
message(STATUS "Compiler:          ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Protobuf Compiler: ${Protobuf_VERSION}")
message(STATUS "CMake Generator:   ${CMAKE_GENERATOR}")
message(STATUS "Build Tests:       ${VCOV_BUILD_TESTS}")
message(STATUS "Build Examples:    ${VCOV_BUILD_EXAMPLES}")
message(STATUS "Shared Libraries:  ${BUILD_SHARED_LIBS}")
message(STATUS "Install:           ${VCOV_INSTALL}")
message(STATUS "Install Prefix:    ${CMAKE_INSTALL_PREFIX}")
message(STATUS "=====================================================================")
message(STATUS "")
