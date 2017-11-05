cmake_minimum_required( VERSION 3.1 )

project( codejam-2017-1b )

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra" )

set( BINARIES
    A.cpp
    B.cpp
    C.cpp
)

foreach(BIN ${BINARIES})
    get_filename_component(EXE_NAME ${BIN} NAME_WE)
    add_executable(${EXE_NAME} ${BIN})
    install(TARGETS ${EXE_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()

