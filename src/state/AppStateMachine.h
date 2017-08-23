//
// Created by Fan Feng on 2017/7/25.
//
#ifndef CLOUDAPPCLIENT_APPSTATEMACHINE_H
#define CLOUDAPPCLIENT_APPSTATEMACHINE_H

#include <string>
#include "SceneAppState.h"
#include "CutAppState.h"
#include "../bean/ActionNode.h"

using namespace std;
namespace CloudAppClient {

class AppStateMachine {
private:
    AppStateMachine *instance;
    AppStateMachine();
    ~AppStateMachine();
    CutAppState* cutAppState;
    SceneAppState* sceneAppState;

public:
    AppStateMachine *getInstance();
    void processSceneEnter(const ActionNode &actionNode);
    void processCutEnter(const ActionNode &actionNode);
    void processSceneExit();
    void processCutExit();
};

}

#endif
