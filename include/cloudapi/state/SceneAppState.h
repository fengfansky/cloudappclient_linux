//
// Created by Fan Feng on 2017/7/25.
//
#ifndef CLOUDAPPCLIENT_SCENEAPPSTATE_H
#define CLOUDAPPCLIENT_SCENEAPPSTATE_H

#include <string>
#include "BaseAppState.h"
#include "SceneAppState.h"
#include "../bean/ActionBean.h"

using namespace std;
namespace CloudAppClient {

class SceneAppState : BaseAppState {
public:
    SceneAppState();
    virtual ~SceneAppState();
    //const char *TAG = "SceneAppState";
    void app_paused();
    void app_resumed();
    void app_destroy();
//    shared_ptr<string> get_app_type();
};

}

#endif
