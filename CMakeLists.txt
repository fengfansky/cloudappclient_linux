cmake_minimum_required(VERSION 3.7)
project(CloudAppClient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp
        src/bean/NLPBean.h
        src/action/BaseAction.h
        src/action/MediaAction.h
        src/action/VoiceAction.h
        src/bean/BaseActionBean.h
        src/bean/ActionNode.h
        src/bean/VoiceBean.h
        src/bean/MediaBean.h
        src/bean/CommonResponseBean.h
        src/bean/CloudActionResponseBean.h
        src/bean/ActionBean.h
        src/reporter/BaseReporter.h
        src/http/BaseParameter.h
        src/state/StateCallback.h
        src/util/LinkedHashMap.h
        src/util/LogUtil.h
        src/util/TextUtil.h
        src/util/BaseUrlConfig.h
        src/util/BaseUrlConfig.h
        src/state/BaseAppState.h
        src/state/SceneAppState.h
        src/state/CutAppState.h
        src/state/AppStateMachine.h
        src/parser/DataParser.h
        src/http/HttpClientWarper.h)

set ( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ~/cpp-netlib-build )
find_package ( cppnetlib 0.11.0 REQUIRED )
include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )

add_executable(CloudAppClient ${SOURCE_FILES})
target_link_libraries ( CloudAppClient ${CPPNETLIB_LIBRARIES} )
