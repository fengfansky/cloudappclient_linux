//
// Created by Fan Feng on 2017/7/16.
//
#include "../bean/ActionNode.h"

namespace cloudappclient {
    class AppStateCallBack {
    public:
        virtual void onNewIntentActionNode(const ActionNode &actionNode) = 0;

        virtual void onNewEventActionNode(const ActionNode &actionNode) = 0;

        virtual void onAppPaused() = 0;

        virtual void onAppResume() = 0;

        virtual void onAppDestory() = 0;
    };

    class MediaStateCallBack {

    public:
        virtual void onMediaStart() = 0;

        virtual void onMediaPause(const int position) = 0;

        virtual void onMediaResume() = 0;

        virtual void onMediaStop() = 0;

        virtual void onMediaError(const int errorCode) = 0;
    };

    class VoiceStateCallBack {
    public:
        virtual void onVoiceStart() = 0;

        virtual void onVoiceStop() = 0;

        virtual void onVoiceCancled() = 0;

        virtual void onVoiceError() = 0;
    };
}
