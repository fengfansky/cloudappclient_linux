//
// Created by Fan Feng on 2017/7/25.
//

#include <boost/tr1/memory.hpp>
#include "SceneAppState.h"
#include "CutAppState.h"

namespace CloudAppClient {

    class AppStateMachine {

    private:
        static AppStateMachine *instance = nullptr;

        AppStateMachine::AppStateMachine() {

        }

        AppStateMachine::~AppStateMachine() {
            delete instance;
        }

    public:
        static AppStateMachine *getInstance() {
            if (instance == nullptr) {
                instance = new AppStateMachine();
            }

            return instance;
        }

    private:
        std::shared_ptr<CutAppState> cutAppState = nullptr;
        std::shared_ptr<SceneAppState> sceneAppState = nullptr;

    public:
        void processSceneEnter(const ActionNode &actionNode) {
            if (cutAppState != nullptr) {
                LogUtil::log("processSceneEnter cutAppState exit");
                cutAppState->app_destroy();
                cutAppState = nullptr;
            }
            LogUtil::log("processSceneEnter sceneAppState new action node");
            sceneAppState = new std::shared_ptr<SceneAppState>();
            sceneAppState->new_intent_action_node(actionNode);
        }

        void processCutEnter(const ActionNode &actionNode) {
            if (sceneAppState != nullptr){
                LogUtil::log("processCutEnter sceneAppState pause");
                sceneAppState->app_paused();
            }
            LogUtil::log("processCutEnter cutAppState new action node");
            cutAppState = new std::shared_ptr<CutAppState>();
            cutAppState->new_intent_action_node(actionNode);
        }

        void processSceneExit() {
            if (cutAppState != nullptr){
                LogUtil::log("error : processSceneExit cutAppState is not null ! ");
                cutAppState -> app_destroy();
                cutAppState = nullptr;
            }
            if (sceneAppState != nullptr){
                LogUtil::log("processSceneExit sceneAppState exit");
                sceneAppState -> app_destroy();
                sceneAppState = nullptr;
            }
        }

        void processCutExit() {
            if (cutAppState == nullptr){
                LogUtil::log("error : processCutExit cutAppState is null ! ");
            } else{
                LogUtil::log("processCutExit cutAppState exit");
                cutAppState->app_destroy();
                cutAppState = nullptr;
                if (sceneAppState != nullptr){
                    LogUtil::log("error : processCutExit sceneAppState not null and resume ! ");
                    sceneAppState->app_resumed();
                }
            }

        }

    };

}
