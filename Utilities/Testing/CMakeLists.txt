set(classes
    SpecialLineInfo.cpp
)
if(BUILD_SHARED_LIBS)
    add_library(Testing SHARED)
else()
    add_library(Testing STATIC)
endif()
target_sources(Testing PRIVATE ${classes})
add_library(vcov::Testing ALIAS Testing)