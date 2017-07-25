//
// Created by Fan Feng on 2017/7/19.
//

#include "../action/MediaAction.h"
#include "../action/VoiceAction.h"
#include "../bean/CloudActionResponseBean.h"
#include "StateCallback.h"

namespace cloudappclient {
    class BaseAppStateManager : AppStateCallBack, MediaStateCallBack, VoiceStateCallBack {

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

        mutex mutex_lock;

        MEDIA_STATE media_state;
        VOICE_STATE voice_state;

        USER_MEDIA_CONTROL_TYPE user_media_control_type;
        USER_VOICE_CONTROL_TYPE user_voice_control_type;

        TaskProcessCallback task_process_callback;

        const ActionNode &get_action_node() const {
            return action_node;
        }

        void set_action_node(const ActionNode &mActionNode) {
            BaseAppStateManager::action_node = mActionNode;
        }

        const string &get_app_Id() const {
            return app_Id;
        }

        void set_app_Id(const string &mAppId) {
            BaseAppStateManager::app_Id = mAppId;
        }

        bool is_shouldendsession() const {
            return shouldendsession;
        }

        void set_shouldendsession(bool shouldEndSession) {
            BaseAppStateManager::shouldendsession = shouldEndSession;
        }

        void set_task_process_callback(const TaskProcessCallback &taskProcessCallback) {
            BaseAppStateManager::task_process_callback = taskProcessCallback;
        }

        MEDIA_STATE get_media_state() const {
            return media_state;
        }

        void set_media_state(MEDIA_STATE currentMediaState) {
            BaseAppStateManager::media_state = currentMediaState;
        }

        VOICE_STATE get_voice_state() const {
            return voice_state;
        }

        void set_voice_state(VOICE_STATE currentVoiceState) {
            BaseAppStateManager::voice_state = currentVoiceState;
        }

        USER_MEDIA_CONTROL_TYPE get_user_media_contro_type() const {
            return user_media_control_type;
        }

        void set_user_control_type(USER_MEDIA_CONTROL_TYPE user_media_control_type1) {
            BaseAppStateManager::user_media_control_type = user_media_control_type1;
        }

        USER_VOICE_CONTROL_TYPE get_usr_media_type() const {
            return user_voice_control_type;
        }

        void setUserVoiceControlType(USER_VOICE_CONTROL_TYPE user_voice_control_type1) {
            BaseAppStateManager::user_voice_control_type = user_voice_control_type1;
        }


    public:
        /** onAppStateCallback **/
        void new_intent_action_node(const ActionNode &actionNode) override {
            mutex_lock.lock();
            if (&actionNode != nullptr) {
                if (TextUtil::isEmpty(actionNode.getAppId())) {
                    checkAppState();
                    return;
                }

                if (!strcmp(app_Id, actionNode.getAppId())) {
                    LogUtil::log("new_event_action_node the appId is the not the same with lastAppId");
                    MediaAction::getInstance()->stopPlay();
                    VoiceAction::getInstance()->stopPlay();
                    media_state = nullptr;
                    voice_state = nullptr;
                }
                BaseAppStateManager::action_node = actionNode;
                BaseAppStateManager::app_Id = actionNode.getAppId();
                BaseAppStateManager::shouldendsession = actionNode.isShouldEndSession();

                process_action_node(actionNode);
            }
            mutex_lock.unlock();
        }


        void new_event_action_node(const ActionNode &actionNode) override {
            mutex_lock.lock();
            LogUtil::log("form: " + getFormType() + "new_event_action_node actioNode : " + " media_state: " +
                         media_state + " voice_state " + voice_state);
            if (actionNode != nullptr) {

                if (TextUtil::isEmpty(actionNode.getAppId())) {
                    LogUtil::log("new cloudAppId is null !");
                    checkAppState();
                    return;
                }

                if (strcmp(actionNode.getAppId(), app_Id)) {
                    LogUtil::log("new_event_action_node the appId is the not the same with lastAppId");
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

        void app_paused() override {
            mutex_lock.lock();
            LogUtil::log("form: " + getFormType() + " app_paused " + " media_state: " + media_state +
                         " voice_state " + voice_state);
            mutex_lock.unlock();
        }

        void app_resumed() override {
            mutex_lock.lock();
            LogUtil::log("form: " + getFormType() + " app_resumed " + " media_state: " + media_state +
                         " voice_state " + voice_state);
            mutex_lock.unlock();
        }

        void app_destroy() override {
            mutex_lock.lock();
            LogUtil::log("form: " + getFormType() + " app_destroy " + " media_state: " + media_state +
                         " voice_state: " + voice_state);
            mutex_lock.unlock();
        }

        /** onMediaStateCallback **/
        void media_started() override {
            mutex_lock.lock();
            media_state = MEDIA_STATE::MEDIA_PLAY;
            LogUtil::log(
                    "form: " + getFormType() + " media_started ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            if (TextUtil::isEmpty(app_Id)) {
                LogUtil::log(" appId is null !");
                return;
            }
            //TODO execute reporter
//            reporterManager.executeReporter(new MediaReporter(mAppId, MediaReporter.START, getExtraBean()));

            mutex_lock.unlock();
        }

        void media_paused(const int position) override {
            mutex_lock.lock();
            media_state = MEDIA_STATE::MEDIA_PAUSE;
            LogUtil::log(
                    "form: " + getFormType() + " media_paused ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            if (TextUtil::isEmpty(app_Id)) {
                LogUtil::log("appId is null");
                return;
            }
            //TODO execute reporter
//            reporterManager.executeReporter(new MediaReporter(mAppId, MediaReporter.PAUSED, getExtraBean()));
            mutex_lock.unlock();
        }

        void media_resumed() override {
            mutex_lock.lock();
            media_state = MEDIA_RESUME;
            LogUtil::log(
                    "form: " + getFormType() + " media_resumed ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            mutex_lock.unlock();
        }

        void media_stopped() override {
            mutex_lock.lock();
            media_state = MEDIA_STOP;
            LogUtil::log(
                    "form: " + getFormType() + " media_stopped ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            if (shouldendsession) {
                checkAppState();
            } else {
                if (TextUtil::isEmpty(app_Id)) {
                    LogUtil::log(" appId is null !");
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
            LogUtil::log(
                    "form: " + getFormType() + " media_error ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
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
            LogUtil::log(
                    "form: " + getFormType() + " voice_started ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            if (TextUtil::isEmpty(app_Id)) {
                LogUtil::log(" appId is null !");
                return;
            }
            //TODO execute reporter
//            reporterManager.executeReporter(new VoiceReporter(mAppId, VoiceReporter.START));
            mutex_lock.unlock();
        }

        void voice_paused() override {
            mutex_lock.lock();
            voice_state = VOICE_PAUSE;
            LogUtil::log(
                    "form: " + getFormType() + " voice_paused ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            mutex_lock.unlock();
        }

        void voice_stopped() override {
            mutex_lock.lock();
            voice_state = VOICE_STOP;
            LogUtil::log(
                    "form: " + getFormType() + " voice_stopped ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            if (shouldendsession) {
                checkAppState();
            } else {
                if (TextUtil::isEmpty(app_Id)) {
                    LogUtil::log(" appId is null !");
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
            LogUtil::log(
                    "form: " + getFormType() + " voice_cancled ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            checkAppState();
            mutex_lock.unlock();
        }

        void voice_error() override {
            mutex_lock.lock();
            voice_state = VOICE_ERROR;
            LogUtil::log(
                    "form: " + getFormType() + " voice_error ! " + " media_state: " + media_state + " voice_state " +
                    voice_state);
            //TODO promote voice error
//            promoteErrorInfo(ErrorPromoter.ERROR_TYPE.TTS_ERROR);
            mutex_lock.unlock();
        }

        virtual string getFormType();

    private:
        /**
 * To process real action
 *
 * @param actionNode the validated action
 */
    private:
        const void process_action_node(const ActionNode &actionNode) {

            if (strcmp(ActionBean::TYPE_EXIT, actionNode.getActionType())) {
                LogUtil::log("current response is a INTENT EXIT - Finish Activity");
                finishActivity();
                return;
            }

            if (strcmp(ActionBean::TYPE_NORMAL, actionNode.getActionType())) {

                if (actionNode.getVoice() != nullptr) {
                    VoiceAction::getInstance()->processAction(actionNode.getVoice());
                    //TODO 开启拾音
                    /*if (actionNode.getConfirmBean() != nullptr && task_process_callback != nullptr &&
                        task_process_callback.get() != nullptr) {
                        task_process_callback.get().openSiren();
                    }*/
                }
                if (actionNode.getMedia() != nullptr) {
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
                LogUtil::log("form: " + getFormType() + " voice stop , allTaskFinished ! finish app !");
                task_process_callback.onAllTaskFinished();
            }
        }

        void finishActivity() {
            if (&task_process_callback != nullptr){
                task_process_callback.onExitCallback();
            }
        }

    };
}