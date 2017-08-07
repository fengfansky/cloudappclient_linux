//
// Created by Fan Feng on 2017/7/19.
//
#pragma once

#include "../action/MediaAction.h"
#include "../action/VoiceAction.h"
#include "../bean/CloudActionResponseBean.h"
#include "StateCallback.h"

namespace CloudAppClient {
    class BaseAppState : public IAppState, public MediaStateCallBack, public VoiceStateCallBack {

    public:
        enum VOICE_STATE {
            VOICE_START,
            VOICE_PAUSE,
            VOICE_STOP,
            VOICE_CANCLE,
            VOICE_ERROR
        };

        enum MEDIA_STATE {
            MEDIA_PLAY,
            MEDIA_PAUSE,
            MEDIA_RESUME,
            MEDIA_STOP,
            MEDIA_ERROR
        };
        enum USER_MEDIA_CONTROL_TYPE {
            MEDIA_PLAY,
            MEDIA_PAUSE,
            MEDIA_RESUME,
            MEDIA_STOP
        };

        enum USER_VOICE_CONTROL_TYPE {
            VOICE_START,
            VOICE_PAUSE,
            VOICE_RESUME,
            VOICE_STOP
        };

        class TaskProcessCallback {
        public:
            void openSiren();

            void onExitCallback();

            void onAllTaskFinished();
        };

    public:
        ActionNode action_node = nullptr;
        string app_Id = nullptr;
        bool shouldendsession;

        std::mutex mutex_lock;

        MEDIA_STATE media_state;
        VOICE_STATE voice_state;

        USER_MEDIA_CONTROL_TYPE user_media_control_type;
        USER_VOICE_CONTROL_TYPE user_voice_control_type;

        TaskProcessCallback task_process_callback;

        const ActionNode &get_action_node() const {
            return action_node;
        }

        void set_action_node(const ActionNode &mActionNode) {
            BaseAppState::action_node = mActionNode;
        }

        const string &get_app_Id() const {
            return app_Id;
        }

        void set_app_Id(const string &mAppId) {
            BaseAppState::app_Id = mAppId;
        }

        bool is_shouldendsession() const {
            return shouldendsession;
        }

        void set_shouldendsession(bool shouldEndSession) {
            BaseAppState::shouldendsession = shouldEndSession;
        }

        void set_task_process_callback(const TaskProcessCallback &taskProcessCallback) {
            BaseAppState::task_process_callback = taskProcessCallback;
        }

        MEDIA_STATE get_media_state() const {
            return media_state;
        }

        void set_media_state(MEDIA_STATE currentMediaState) {
            BaseAppState::media_state = currentMediaState;
        }

        VOICE_STATE get_voice_state() const {
            return voice_state;
        }

        void set_voice_state(VOICE_STATE currentVoiceState) {
            BaseAppState::voice_state = currentVoiceState;
        }

        USER_MEDIA_CONTROL_TYPE get_user_media_contro_type() const {
            return user_media_control_type;
        }

        void set_user_control_type(USER_MEDIA_CONTROL_TYPE user_media_control_type1) {
            BaseAppState::user_media_control_type = user_media_control_type1;
        }

        USER_VOICE_CONTROL_TYPE get_usr_media_type() const {
            return user_voice_control_type;
        }

        void setUserVoiceControlType(USER_VOICE_CONTROL_TYPE user_voice_control_type1) {
            BaseAppState::user_voice_control_type = user_voice_control_type1;
        }


    public:
        /** onAppStateCallback **/
        void new_intent_action_node(const ActionNode &actionNode) override {
            mutex_lock.lock();
            if (&actionNode != nullptr) {
                if (actionNode.getAppId().empty()) {
                    checkAppState();
                    return;
                }

                if (!strcmp(app_Id, actionNode.getAppId())) {
                    rokid::log::Log::d(TAG, "new_event_action_node the appId is the not the same with lastAppId");
                    MediaAction::getInstance()->stopPlay();
                    VoiceAction::getInstance()->stopPlay();
                    media_state = nullptr;
                    voice_state = nullptr;
                }
                BaseAppState::action_node = actionNode;
                BaseAppState::app_Id = actionNode.getAppId();
                BaseAppState::shouldendsession = actionNode.isShouldEndSession();

                process_action_node(actionNode);
            }
            mutex_lock.unlock();
        }


        void new_event_action_node(const ActionNode &actionNode) override {
            mutex_lock.lock();
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + "new_event_action_node actioNode : " + " media_state: " +
                               media_state + " voice_state " + voice_state).c_str());
            if (&actionNode != nullptr) {

                if (actionNode.getAppId().empty()) {
                    rokid::log::Log::d(TAG, "new cloudAppId is null !");
                    checkAppState();
                    return;
                }

                if (strcmp(actionNode.getAppId(), app_Id)) {
                    rokid::log::Log::d(TAG, "new_event_action_node the appId is the not the same with lastAppId");
                    checkAppState();
                    return;
                }

                shouldendsession = actionNode.isShouldEndSession();
                process_action_node(actionNode);
            } else {
                checkAppState();
            }
            mutex_lock.unlock();
        }

        /** onMediaStateCallback **/
        void media_started() override {
            mutex_lock.lock();
            media_state = MEDIA_STATE::MEDIA_PLAY;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " media_started ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            if (app_Id.empty()) {
                rokid::log::Log::d(TAG, " appId is null !");
                return;
            }
            //TODO execute reporter
//            reporterManager.executeReporter(new MediaReporter(mAppId, MediaReporter.START, getExtraBean()));

            mutex_lock.unlock();
        }

        void media_paused(const int position) override {
            mutex_lock.lock();
            media_state = MEDIA_STATE::MEDIA_PAUSE;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " media_paused ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            if (app_Id.empty()) {
                rokid::log::Log::d(TAG, "appId is null");
                return;
            }
            //TODO execute reporter
//            reporterManager.executeReporter(new MediaReporter(mAppId, MediaReporter.PAUSED, getExtraBean()));
            mutex_lock.unlock();
        }

        void media_resumed() override {
            mutex_lock.lock();
            media_state = MEDIA_RESUME;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " media_resumed ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            mutex_lock.unlock();
        }

        void media_stopped() override {
            mutex_lock.lock();
            media_state = MEDIA_STOP;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " media_stopped ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            if (shouldendsession) {
                checkAppState();
            } else {
                if (app_Id.empty()) {
                    rokid::log::Log::d(TAG, " appId is null !");
                    return;
                }

                //TODO execute reporter media.finished
//                reporterManager.executeReporter(new MediaReporter(mAppId, MediaReporter.FINISHED, getExtraBean()));
            }
            mutex_lock.unlock();
        }

        void media_error(const int errorCode) override {
            mutex_lock.lock();
            media_state = MEDIA_ERROR;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " media_error ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            //TODO promote error info
            /*if (errorCode == RKAudioPlayer.MEDIA_ERROR_TIME_OUT){
                promoteErrorInfo(ErrorPromoter.ERROR_TYPE.MEDIA_TIME_OUT);
            }else {
                promoteErrorInfo(ErrorPromoter.ERROR_TYPE.MEDIA_ERROR);
            }*/
            mutex_lock.unlock();
        }

        void voice_started() override {
            mutex_lock.lock();
            voice_state = VOICE_START;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " voice_started ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            if (app_Id.empty()) {
                rokid::log::Log::d(TAG, " appId is null !");
                return;
            }
            //TODO execute reporter
//            reporterManager.executeReporter(new VoiceReporter(mAppId, VoiceReporter.START));
            mutex_lock.unlock();
        }

        void voice_paused() override {
            mutex_lock.lock();
            voice_state = VOICE_PAUSE;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " voice_paused ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            mutex_lock.unlock();
        }

        void voice_stopped() override {
            mutex_lock.lock();
            voice_state = VOICE_STOP;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " voice_stopped ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            if (shouldendsession) {
                checkAppState();
            } else {
                if (app_Id.empty()) {
                    rokid::log::Log::d(TAG, " appId is null !");
                    checkAppState();
                    return;
                }
                //TODO execute reporter
//                reporterManager.executeReporter(new VoiceReporter(mAppId, VoiceReporter.FINISHED));
            }
            mutex_lock.unlock();
        }

        void voice_cancled() override {
            mutex_lock.lock();
            voice_state = VOICE_CANCLE;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " voice_cancled ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            checkAppState();
            mutex_lock.unlock();
        }

        void voice_error() override {
            mutex_lock.lock();
            voice_state = VOICE_ERROR;
            rokid::log::Log::d(TAG,
                               ("form: " + get_app_type() + " voice_error ! " + " media_state: " + media_state +
                               " voice_state " +
                               voice_state).c_str());
            //TODO promote voice error
//            promoteErrorInfo(ErrorPromoter.ERROR_TYPE.TTS_ERROR);
            mutex_lock.unlock();
        }

    private:
        /**
 * To process real action
 *
 * @param actionNode the validated action
 */
    private:
        const void process_action_node(const ActionNode &actionNode) {

            if (strcmp(ActionBean::TYPE_EXIT, actionNode.getActionType())) {
                rokid::log::Log::d(TAG, "current response is a INTENT EXIT - Finish Activity");
                finishActivity();
                return;
            }

            if (strcmp(ActionBean::TYPE_NORMAL, actionNode.getActionType())) {

                if (&actionNode.getVoice() != nullptr) {
                    VoiceAction::getInstance()->processAction(actionNode.getVoice());
                    //TODO 开启拾音
                    /*if (actionNode.getConfirmBean() != nullptr && task_process_callback != nullptr &&
                        task_process_callback.get() != nullptr) {
                        task_process_callback.get().openSiren();
                    }*/
                }
                if (&actionNode.getMedia() != nullptr) {
                    MediaAction::getInstance()->processAction(actionNode.getMedia());
                }
            }
        }

        const bool isStateInvalid() {
            return (media_state == nullptr || media_state == MEDIA_STATE::MEDIA_STOP ||
                    media_state == MEDIA_STATE::MEDIA_ERROR) &&
                   (voice_state == nullptr || voice_state == VOICE_STATE::VOICE_STOP ||
                    voice_state == VOICE_STATE::VOICE_CANCLE || voice_state == VOICE_STATE::VOICE_ERROR)
                   && &task_process_callback != nullptr;
        }


        const void checkAppState() {
            if (isStateInvalid() && &task_process_callback != nullptr) {
                rokid::log::Log::d(TAG, ("form: " + get_app_type() + " voice stop , allTaskFinished ! finish app !").c_str());
                task_process_callback.onAllTaskFinished();
            }
        }

        void finishActivity() {
            if (&task_process_callback != nullptr) {
                task_process_callback.onExitCallback();
            }
        }

        const char *TAG = "BaseAppState";
    };
}