//
// Created by Fan Feng on 2017/7/25.
//
#include "BaseAppState.h"
#include "StateCallback.h"

namespace CloudAppClient {
    class SceneAppState : BaseAppState{

    private:

        SceneAppState::SceneAppState(){

        }

        SceneAppState::~SceneAppState() {

        }

    public:
        void app_paused() override {
            mutex_lock.lock();
            LogUtil::log("form: " + get_app_type() + " app_paused " + " media_state: " + media_state +
                         " voice_state " + voice_state);
            VoiceAction::getInstance() -> pausePlay();
            MediaAction::getInstance() -> pausePlay();
            mutex_lock.unlock();
        }

        void app_resumed() override {
            mutex_lock.lock();
            LogUtil::log("form: " + get_app_type() + " app_resumed " + " media_state: " + media_state +
                         " voice_state " + voice_state);
            //应用onResume的时候要考虑到用户上次操作是否是暂停
            if (media_state == MEDIA_STATE::MEDIA_PAUSE && !(user_media_control_type == USER_MEDIA_CONTROL_TYPE::MEDIA_PAUSE)) {
                LogUtil::log("scene: onAppResume resume play audio");
                MediaAction::getInstance() -> resumePlay();
            }

            if (voice_state == VOICE_STATE::VOICE_PAUSE && !(user_voice_control_type == USER_VOICE_CONTROL_TYPE::VOICE_PAUSE)) {
                LogUtil::log("scene onAppResume play voice");
                VoiceAction::getInstance() -> resumePlay();
            }
            mutex_lock.unlock();
        }

        void app_destroy() override {
            mutex_lock.lock();
            LogUtil::log("form: " + get_app_type() + " app_destroy " + " media_state: " + media_state +
                         " voice_state: " + voice_state);
            MediaAction::getInstance()->stopPlay();
            VoiceAction::getInstance()->stopPlay();
            //TODO 资源回收
            //TODO close http io
            //HttpClientWrapper.getInstance().close();
            mutex_lock.unlock();

        }

        string get_app_type() override {
            return ActionBean::FORM_SCENE;
        }

    };

}
