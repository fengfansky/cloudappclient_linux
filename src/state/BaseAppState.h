//
// Created by Fan Feng on 2017/7/19.
//
#ifndef CLOUDAPPCLIENT_BASEAPPSTATE_H
#define CLOUDAPPCLIENT_BASEAPPSTATE_H

#include <string>
#include "Poco/Types.h"
#include "../action/MediaAction.h"
#include "../action/VoiceAction.h"
#include "../bean/CloudActionResponseBean.h"
#include "../state/StateCallback.h"

using namespace std;
using namespace Poco;

namespace CloudAppClient {

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
    USER_MEDIA_PLAY,
    USER_MEDIA_PAUSE,
    USER_MEDIA_RESUME,
    USER_MEDIA_STOP
};

enum USER_VOICE_CONTROL_TYPE {
    USER_VOICE_START,
    USER_VOICE_PAUSE,
    USER_VOICE_RESUME,
    USER_VOICE_STOP
};


class BaseAppState : public IAppState{
public:

    BaseAppState() {};
    virtual ~BaseAppState() {};

    class TaskProcessCallback {
    public:
        void openSiren();

        void onExitCallback();

        void onAllTaskFinished();
    };

    ActionNode action_node;
    string app_Id;
    bool shouldendsession;

    mutex mutex_lock;

    MEDIA_STATE media_state;
    VOICE_STATE voice_state;

    USER_MEDIA_CONTROL_TYPE user_media_control_type;
    USER_VOICE_CONTROL_TYPE user_voice_control_type;

    TaskProcessCallback task_process_callback;

    const ActionNode &get_action_node() const;
    void set_action_node(const ActionNode &mActionNode);
    const string &get_app_Id() const;
    void set_app_Id(const string &mAppId);
    bool is_shouldendsession() const;
    void set_shouldendsession(bool shouldEndSession);
    void set_task_process_callback(const TaskProcessCallback &taskProcessCallback);
    MEDIA_STATE get_media_state() const;
    void set_media_state(MEDIA_STATE currentMediaState);
    VOICE_STATE get_voice_state() const;
    void set_voice_state(VOICE_STATE currentVoiceState);
    USER_MEDIA_CONTROL_TYPE get_user_media_contro_type() const;
    void set_user_control_type(USER_MEDIA_CONTROL_TYPE user_media_control_type1);
    USER_VOICE_CONTROL_TYPE get_usr_media_type() const;
    void setUserVoiceControlType(USER_VOICE_CONTROL_TYPE user_voice_control_type1);

    /** onAppStateCallback **/
    void new_intent_action_node(const ActionNode &actionNode);
    void new_event_action_node(const ActionNode &actionNode);
    /** onMediaStateCallback **/
    void media_started();
    void media_paused(const int position);
    void media_resumed();
    void media_stopped();
    void media_error(const int errorCode);
    void voice_started();
    void voice_paused();
    void voice_stopped();
    void voice_cancled();
    void voice_error();

/**
 * To process real action
 *
 * @param actionNode the validated action
 */
private:
    const void process_action_node(const ActionNode &actionNode);
    const bool isStateInvalid();
    const void checkAppState();
    void finishActivity();
    //const char *TAG = "BaseAppState";
};

}

#endif
