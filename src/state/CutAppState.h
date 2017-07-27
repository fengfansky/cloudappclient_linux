//
// Created by Fan Feng on 2017/7/25.
//
#include "BaseAppState.h"

namespace CloudAppClient {

    class CutAppState : BaseAppState{

    private:

        CutAppState::CutAppState() {

        }

        CutAppState::~CutAppState() {
        }

    public:

        void app_paused() override {
            mutex_lock.lock();
            LogUtil::log("form: " + get_app_type() + " app_paused " + " media_state: " + media_state +
                         " voice_state " + voice_state);
            VoiceAction::getInstance() -> stopPlay();
            MediaAction::getInstance() -> stopPlay();
            mutex_lock.unlock();
        }

        void app_resumed() override {
            mutex_lock.lock();
            LogUtil::log("form: " + get_app_type() + " app_resumed " + " media_state: " + media_state +
                         " voice_state " + voice_state);
            mutex_lock.unlock();
        }

        void app_destroy() override {
            mutex_lock.lock();
            LogUtil::log("form: " + get_app_type() + " app_destroy " + " media_state: " + media_state +
                         " voice_state: " + voice_state);
            //TODO 资源回收
            mutex_lock.unlock();
        }

        string get_app_type() override {
            return ActionBean::FORM_CUT;
        }

    };

}