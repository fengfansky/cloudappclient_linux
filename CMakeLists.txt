cmake_minimum_required(VERSION 3.7)
project(CloudAppClient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/action/BaseAction.h
        src/action/BaseAction.cpp
        src/action/MediaAction.h
        src/action/MediaAction.cpp
        src/action/VoiceAction.h
        src/action/VoiceAction.cpp
        src/bean/ActionBean.h
        src/bean/ActionBean.cpp
        src/bean/ActionNode.h
        src/bean/ActionNode.cpp
        src/bean/BaseActionBean.h
        src/bean/BaseActionBean.cpp
        src/bean/CloudActionResponseBean.h
        src/bean/CloudActionResponseBean.cpp
        src/bean/ConfirmBean.h
        src/bean/ConfirmBean.cpp
        src/bean/MediaBean.h
        src/bean/MediaBean.cpp
        src/bean/NLPBean.h
        src/bean/NLPBean.cpp
        src/bean/PickupBean.h
        src/bean/PickupBean.cpp
        src/bean/ResponseBean.h
        src/bean/ResponseBean.cpp
        src/bean/SessionBean.h
        src/bean/SessionBean.cpp
        src/bean/VoiceBean.h
        src/bean/VoiceBean.cpp
        src/http/BaseUrlConfig.h
        src/http/BaseUrlConfig.cpp
        src/http/HttpClientWrapper.h
        src/http/HttpClientWrapper.cpp
        src/json/json.h
        src/parser/ActionParser.h
        src/parser/ActionParser.cpp
        src/parser/NLPParser.h
        src/parser/NLPParser.cpp
        src/proto/SendEvent.pb.h
        src/proto/SendEvent.pb.cc
        src/reporter/BaseReporter.h
        src/reporter/BaseReporter.cpp
        src/state/AppStateMachine.h
        src/state/AppStateMachine.cpp
        src/state/BaseAppState.h
        src/state/BaseAppState.cpp
        src/state/CutAppState.h
        src/state/CutAppState.cpp
        src/state/SceneAppState.h
        src/state/SceneAppState.cpp
        src/state/StateCallback.h
        src/util/rlog.h
        src/util/log.cc
        src/util/md5.h
        src/util/md5.cpp
        src/util/MD5Utils.h
        src/util/MD5Utils.cpp)


link_directories("/usr/local/lib/")
link_directories("/usr/local/Cellar/protobuf/3.3.0/lib")
add_executable(CloudAppClient ${SOURCE_FILES})
target_link_libraries(CloudAppClient PocoNet PocoFoundation
        PocoJSON
        PocoCrypto
        protobuf.13
        protobuf protobuf-lite
        protoc
        )
