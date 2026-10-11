set(classes
    OpenCppCoverage.cpp
)
set(headers
    OpenCppCoverage.hpp
    ConsoleExport.h
)

if(VCOV_BUILD_TESTS)
    list(APPEND classes
        VcovTestTools.cpp
    )
    list(APPEND headers
        VcovTestTools.hpp
    )
endif()

vcov_module_add_module(Console CLASSES ${classes} HEADERS ${headers})
vcov_module_add_dependencies(Console
    DEPENDENCIES 
        Common
        Core
        Coverage
        Filter
        Option
        Export
        Platform
        Cobertura
        Plugin
        Binary
        Html
)
vcov_module_add_test(Console)

add_executable(vcov  main.cpp)
target_link_libraries(vcov PRIVATE Console 
    Common
    Core
    Coverage
    Filter
    Option
    Export
    Platform
    Cobertura
    Plugin
    Binary
    Html
)