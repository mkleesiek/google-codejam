cmake_minimum_required( VERSION 3.1 )

project( codejam )

# some compiler / linker settings
set( CMAKE_CXX_STANDARD 11 )

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}" CACHE PATH "Install path prefix, prepended onto install directories." FORCE)
endif()

include_directories(include)

#add_subdirectory(2016)
#add_subdirectory(2016/Distributed-Round1)
#add_subdirectory(2017/RoundQ)
#add_subdirectory(2017/Round1a)
#add_subdirectory(2017/Round1b)
#add_subdirectory(2017/Round1c)
add_subdirectory(2017/Round2)
