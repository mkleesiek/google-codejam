cmake_minimum_required( VERSION 3.1 )

project( codejam-2016 )

set( CMAKE_CXX_STANDARD 11 )

set( BINARIES aggrcows.cpp fractiles.cpp jamcoin.cpp pancake.cpp powerset.cpp sheep.cpp )

foreach(BIN ${BINARIES})
    get_filename_component(EXE_NAME ${BIN} NAME_WE)
    add_executable(${EXE_NAME} ${BIN})
    install(TARGETS ${EXE_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()
