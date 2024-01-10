project(Complex)

set(HEADER_FILES
        Complex.h
        )
set(SOURCE_FILES
        Complex.cpp
        )
add_library(Complex_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})