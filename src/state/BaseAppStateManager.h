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
            VOICE_STOP,
            VOICE_CANCLED,
            VOICE_ERROR
        };

        enum MEDIA_STATE {
            MEDIA_PLAY,
            MEDIA_PAUSED,
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
        ActionNode mActionNode = nullptr;
        string mAppId = nullptr;
        bool shouldEndSession;

        MEDIA_STATE currentMediaState;
        VOICE_STATE currentVoiceState;

        USER_MEDIA_CONTROL_TYPE userMediaControlType;
        USER_VOICE_CONTROL_TYPE userVoiceControlType;

        TaskProcessCallback mTaskProcessCallback;

        const ActionNode &getMActionNode() const {
            return mActionNode;
        }

        void setMActionNode(const ActionNode &mActionNode) {
            BaseAppStateManager::mActionNode = mActionNode;
        }

        const string &getMAppId() const {
            return mAppId;
        }

        void setMAppId(const string &mAppId) {
            BaseAppStateManager::mAppId = mAppId;
        }

        bool isShouldEndSession() const {
            return shouldEndSession;
        }

        void setShouldEndSession(bool shouldEndSession) {
            BaseAppStateManager::shouldEndSession = shouldEndSession;
        }

        void setTaskProcessCallback(const TaskProcessCallback &taskProcessCallback) {
            BaseAppStateManager::mTaskProcessCallback = taskProcessCallback;
        }

        MEDIA_STATE getCurrentMediaState() const {
            return currentMediaState;
        }

        void setCurrentMediaState(MEDIA_STATE currentMediaState) {
            BaseAppStateManager::currentMediaState = currentMediaState;
        }

        VOICE_STATE getCurrentVoiceState() const {
            return currentVoiceState;
        }

        void setCurrentVoiceState(VOICE_STATE currentVoiceState) {
            BaseAppStateManager::currentVoiceState = currentVoiceState;
        }

        USER_MEDIA_CONTROL_TYPE getUserMediaControlType() const {
            return userMediaControlType;
        }

        void setUserMediaControlType(USER_MEDIA_CONTROL_TYPE userMediaControlType) {
            BaseAppStateManager::userMediaControlType = userMediaControlType;
        }

        USER_VOICE_CONTROL_TYPE getUserVoiceControlType() const {
            return userVoiceControlType;
        }

        void setUserVoiceControlType(USER_VOICE_CONTROL_TYPE userVoiceControlType) {
            BaseAppStateManager::userVoiceControlType = userVoiceControlType;
        }

        /**
        * To process real action
        *
        * @param actionNode the validated action
        */
    private:
        void processActionNode(const ActionNode &actionNode) {

            if (strcmp(ActionBean::TYPE_EXIT, actionNode.getActionType())) {
                LogUtil::log("current response is a INTENT EXIT - Finish Activity");
                finishActivity();
                return;
            }

            if (strcmp(ActionBean::TYPE_NORMAL, actionNode.getActionType())) {

                if (actionNode.getVoice() != nullptr) {
                    VoiceAction::getInstance()->processAction(actionNode.getVoice());
                    //TODO 开启拾音
                    /*if (actionNode.getConfirmBean() != nullptr && mTaskProcessCallback != nullptr &&
                        mTaskProcessCallback.get() != nullptr) {
                        mTaskProcessCallback.get().openSiren();
                    }*/
                }
                if (actionNode.getMedia() != nullptr) {
                    MediaAction::getInstance()->processAction(actionNode.getMedia());
                }
            }
        }


    public:
        /** onAppStateCallback **/
        void onNewIntentActionNode(const ActionNode &actionNode) override {
            AppStateCallBack::onNewIntentActionNode(actionNode);
            if (&actionNode != nullptr) {
                if (TextUtil::isEmpty(actionNode.getAppId())) {
                    checkAppState();
                    return;
                }

                if (!strcmp(mAppId, actionNode.getAppId())) {
                    LogUtil::log("onNewEventActionNode the appId is the not the same with lastAppId");
                    MediaAction::getInstance()->stopPlay();
                    VoiceAction::getInstance()->stopPlay();
                    currentMediaState = nullptr;
                    currentVoiceState = nullptr;
                }
                BaseAppStateManager::mActionNode = actionNode;
                BaseAppStateManager::mAppId = actionNode.getAppId();
                BaseAppStateManager::shouldEndSession = actionNode.isShouldEndSession();

                processActionNode(actionNode);
            }
        }


        void onNewEventActionNode(const ActionNode &actionNode) override {
            AppStateCallBack::onNewEventActionNode(actionNode);
            LogUtil::log("form: " + getFormType() + "onNewEventActionNode actioNode : " + " currentMediaState: " +
                         currentMediaState + " currentVoiceState " + currentVoiceState);
            if (actionNode != nullptr) {

                if (TextUtil::isEmpty(actionNode.getAppId())) {
                    LogUtil::log("new cloudAppId is null !");
                    checkAppState();
                    return;
                }

                if (strcmp(actionNode.getAppId(), mAppId)) {
                    LogUtil::log("onNewEventActionNode the appId is the not the same with lastAppId");
                    checkAppState();
                    return;
                }

                shouldEndSession = actionNode.isShouldEndSession();
                processActionNode(actionNode);
            } else {
                checkAppState();
            }
        }

        void onAppPaused() override {
            AppStateCallBack::onAppPaused();
            LogUtil::log("form: " + getFormType() + " onAppPaused " + " currentMediaState: " + currentMediaState +
                         " currentVoiceState " + currentVoiceState);
        }

        void onAppResume() override {
            AppStateCallBack::onAppResume();
            LogUtil::log("form: " + getFormType() + " onAppResume " + " currentMediaState: " + currentMediaState +
                         " currentVoiceState " + currentVoiceState);
        }

        void onAppDestory() override {
            AppStateCallBack::onAppDestory();
            LogUtil::log("form: " + getFormType() + " onAppDestory " + " currentMediaState: " + currentMediaState +
                         " currentVoiceState: " + currentVoiceState);
        }

        /** onMediaStateCallback **/
        void onMediaStart() override {
            MediaStateCallBack::onMediaStart();
            currentMediaState = MEDIA_STATE::MEDIA_PLAY;
            LogUtil::log("form: " + getFormType() + " onMediaStart ! " + " currentMediaState: " + currentMediaState +
                         " currentVoiceState " + currentVoiceState);
            if (TextUtil::isEmpty(mAppId)) {
                LogUtil::log(" appId is null !");
                return;
            }
            //TODO execute reporter
        }

        void onMediaPause(int position) override {
            MediaStateCallBack::onMediaPause(position);
        }

        void onMediaResume() override {
            MediaStateCallBack::onMediaResume();
        }

        void onMediaStop() override {
            MediaStateCallBack::onMediaStop();
        }

        void onMediaError(int errorCode) override {
            MediaStateCallBack::onMediaError(errorCode);
        }

        /** onVoiceStateCallback **/
        void onVoiceStart() override {
            VoiceStateCallBack::onVoiceStart();
        }

        void onVoiceStop() override {
            VoiceStateCallBack::onVoiceStop();
        }

        void onVoiceCancled() override {
            VoiceStateCallBack::onVoiceCancled();
        }

        void onVoiceError() override {
            VoiceStateCallBack::onVoiceError();
        }

        bool isStateInvalid() {
            return (currentMediaState == nullptr || currentMediaState == MEDIA_STATE::MEDIA_STOP ||
                    currentMediaState == MEDIA_STATE::MEDIA_ERROR) &&
                   (currentVoiceState == nullptr || currentVoiceState == VOICE_STATE::VOICE_STOP ||
                    currentVoiceState == VOICE_STATE::VOICE_CANCLED || currentVoiceState == VOICE_STATE::VOICE_ERROR)
                   && &mTaskProcessCallback != nullptr;
        }

        virtual string getFormType();

        void checkAppState() {
            if (isStateInvalid() && &mTaskProcessCallback != nullptr) {
                LogUtil::log("form: " + getFormType() + " voice stop , allTaskFinished ! finish app !");
                mTaskProcessCallback.onAllTaskFinished();
            }
        }

        void finishActivity() {

        }

    };
}