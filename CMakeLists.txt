cmake_minimum_required(VERSION 3.7)
project(CloudAppClient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        include/cloudapi/action/BaseAction.h
        src/action/BaseAction.cpp
        include/cloudapi/action/MediaAction.h
        src/action/MediaAction.cpp
        include/cloudapi/action/VoiceAction.h
        src/action/VoiceAction.cpp
        include/cloudapi/bean/ActionBean.h
        src/bean/ActionBean.cpp
        include/cloudapi/bean/ActionNode.h
        src/bean/ActionNode.cpp
        include/cloudapi/bean/BaseActionBean.h
        src/bean/BaseActionBean.cpp
        include/cloudapi/bean/CloudActionResponseBean.h
        src/bean/CloudActionResponseBean.cpp
        include/cloudapi/bean/ConfirmBean.h
        src/bean/ConfirmBean.cpp
        include/cloudapi/bean/MediaBean.h
        src/bean/MediaBean.cpp
        include/cloudapi/bean/NLPBean.h
        src/bean/NLPBean.cpp
        include/cloudapi/bean/PickupBean.h
        src/bean/PickupBean.cpp
        include/cloudapi/bean/ResponseBean.h
        src/bean/ResponseBean.cpp
        include/cloudapi/bean/SessionBean.h
        src/bean/SessionBean.cpp
        include/cloudapi/bean/VoiceBean.h
        src/bean/VoiceBean.cpp
        include/cloudapi/http/BaseUrlConfig.h
        src/http/BaseUrlConfig.cpp
        include/cloudapi/http/HttpClientWrapper.h
        src/http/HttpClientWrapper.cpp
        src/json/json.h
        include/cloudapi/parser/ActionParser.h
        src/parser/ActionParser.cpp
        include/cloudapi/parser/NLPParser.h
        src/parser/NLPParser.cpp
        include/cloudapi/proto/SendEvent.pb.h
        src/proto/SendEvent.pb.cc
        include/cloudapi/reporter/BaseReporter.h
        src/reporter/BaseReporter.cpp
        include/cloudapi/state/AppStateMachine.h
        src/state/AppStateMachine.cpp
        include/cloudapi/state/BaseAppState.h
        src/state/BaseAppState.cpp
        include/cloudapi/state/CutAppState.h
        src/state/CutAppState.cpp
        include/cloudapi/state/SceneAppState.h
        src/state/SceneAppState.cpp
        include/cloudapi/util/rlog.h
        src/util/log.cc
        include/cloudapi/util/md5.h
        src/util/md5.cpp
        include/cloudapi/util/MD5Utils.h
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
