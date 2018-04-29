cmake_minimum_required( VERSION 3.1 )

project( codejam )

# some compiler / linker settings
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_FLAGS "-Wall -Wextra" )

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
#add_subdirectory(2017/Round2)
#add_subdirectory(2018/PracticeSession)
#add_subdirectory(2018/RoundQ)
add_subdirectory(2018/Round1b)