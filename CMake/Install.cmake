include(GNUInstallDirs)
include(CPack)

configure_package_config_file(
    "${CMAKE_SOURCE_DIR}/CMake/VcovConfig.cmake.in"
    "${CMAKE_BINARY_DIR}/VcovConfig.cmake"
    INSTALL_DESTINATION share/vcov
)

write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/VcovConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_file(
    "${PROJECT_SOURCE_DIR}/vcov.pc.in"
    "${CMAKE_BINARY_DIR}/vcov.pc"
    @ONLY
)

set(CPACK_PACKAGE_VENDOR "vcov")
set(CPACK_PACKAGE_DESCRIPTION_FILE ${CMAKE_SOURCE_DIR}/README.md)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE.md)
set(CPACK_RESOURCE_FILE_README ${CMAKE_SOURCE_DIR}/README.md)
set(CPACK_COMPONENTS_ALL Development Documentation Runtime)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" 
    CACHE PATH "Installation prefix" FORCE)
endif()

if(VCOV_INSTALL)
    install(FILES ${vcov_public_headers}
      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/vcov
    )
endif()