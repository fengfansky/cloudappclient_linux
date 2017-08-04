//
// Created by Fan Feng on 2017/7/25.
//
#pragma once

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
                rokid::log::Log::d(TAG,"processSceneEnter cutAppState exit");
                cutAppState->app_destroy();
                cutAppState = nullptr;
            }
            rokid::log::Log::d(TAG,"processSceneEnter sceneAppState new action node");
            sceneAppState = new std::shared_ptr<SceneAppState>();
            sceneAppState->new_intent_action_node(actionNode);
        }

        void processCutEnter(const ActionNode &actionNode) {
            if (sceneAppState != nullptr){
                rokid::log::Log::d(TAG,"processCutEnter sceneAppState pause");
                sceneAppState->app_paused();
            }
            rokid::log::Log::d(TAG,"processCutEnter cutAppState new action node");
            cutAppState = new std::shared_ptr<CutAppState>();
            cutAppState->new_intent_action_node(actionNode);
        }

        void processSceneExit() {
            if (cutAppState != nullptr){
                rokid::log::Log::d(TAG,"error : processSceneExit cutAppState is not null ! ");
                cutAppState -> app_destroy();
                cutAppState = nullptr;
            }
            if (sceneAppState != nullptr){
                rokid::log::Log::d(TAG,"processSceneExit sceneAppState exit");
                sceneAppState -> app_destroy();
                sceneAppState = nullptr;
            }
        }

        void processCutExit() {
            if (cutAppState == nullptr){
                rokid::log::Log::d(TAG,"error : processCutExit cutAppState is null ! ");
            } else{
                rokid::log::Log::d(TAG,"processCutExit cutAppState exit");
                cutAppState->app_destroy();
                cutAppState = nullptr;
                if (sceneAppState != nullptr){
                    rokid::log::Log::d(TAG,"error : processCutExit sceneAppState not null and resume ! ");
                    sceneAppState->app_resumed();
                }
            }

        }

    };

}
