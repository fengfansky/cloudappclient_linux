//
// Created by Fan Feng on 2017/7/16.
//
#pragma once

#include "../bean/ActionNode.h"

namespace CloudAppClient {

    class IAppState {
    public:
        virtual void new_intent_action_node(const ActionNode &actionNode) = 0;

        virtual void new_event_action_node(const ActionNode &actionNode) = 0;

        virtual void app_paused() = 0;

        virtual void app_resumed() = 0;

        virtual void app_destroy() = 0;

        virtual string get_app_type() = 0;

    };

    class MediaStateCallBack {

    public:
        virtual void media_started() = 0;

        virtual void media_paused(const int position) = 0;

        virtual void media_resumed() = 0;

        virtual void media_stopped() = 0;

        virtual void media_error(const int errorCode) = 0;
    };

    class VoiceStateCallBack {
    public:
        virtual void voice_started() = 0;

        virtual void voice_paused() = 0;

        virtual void voice_stopped() = 0;

        virtual void voice_cancled() = 0;

        virtual void voice_error() = 0;
    };
}
