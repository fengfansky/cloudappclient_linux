cmake_minimum_required(VERSION 3.7)
project(CloudAppClient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/action/BaseAction.h
        src/action/MediaAction.h
        src/action/VoiceAction.h
        src/bean/ActionBean.h
        src/bean/ActionNode.h
        src/bean/BaseActionBean.h
        src/parser/nlp_parser.h
        src/parser/nlp_parser.cpp
        src
        )

#set ( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ~/cpp-netlib-build )
#find_package ( cppnetlib 0.11.0 REQUIRED )
#include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )

#set(CMAKE_PREFIX_PATH  ${CMAKE_PREFIX_PATH} ~/ClionProjects/build/log/)
#include_directories(${})
add_executable(CloudAppClient ${SOURCE_FILES})
#target_link_libraries ( CloudAppClient ${CPPNETLIB_LIBRARIES} )
