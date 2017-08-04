cmake_minimum_required(VERSION 3.7)
project(CloudAppClient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/action/BaseAction.h
        src/action/MediaAction.h
        src/action/VoiceAction.h
        src/bean/ActionBean.h
        src/bean/BaseActionBean.h
        src/bean/CloudActionResponseBean.h
        src/bean/CommonResponseBean.h
        src/bean/MediaBean.h
        src/bean/NLPBean.h
        src/bean/ResponseBean.h
        src/bean/SessionBean.h
        src/bean/VoiceBean.h
        src/http/BaseParameter.h
        src/http/HttpClientWarper.h
        src/json/json.h
        src/parser/action_parser.h
        src/parser/action_parser.cpp
        src/parser/nlp_parser.h
        src/parser/nlp_parser.cpp
#        src/proto/SendEvent.pb.h
#        src/proto/SendEvent.pb.cc
        src/reporter/BaseReporter.h
        src/state/AppStateMachine.h
        src/state/BaseAppState.h
        src/state/CutAppState.h
        src/state/SceneAppState.h
        src/state/StateCallback.h
        src/util/BaseUrlConfig.h
        src/util/LinkedHashMap.h
        src/util/rlog.h
        src/util/log.cc
        )

#set ( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ~/cpp-netlib-build )
#find_package ( cppnetlib 0.11.0 REQUIRED )
#include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )

#set(CMAKE_PREFIX_PATH  ${CMAKE_PREFIX_PATH} ~/ClionProjects/build/log/)
#include_directories(${})
add_executable(CloudAppClient ${SOURCE_FILES})
#target_link_libraries ( CloudAppClient ${CPPNETLIB_LIBRARIES} )
