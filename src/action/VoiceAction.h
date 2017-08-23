//
// Created by Fan Feng on 2017/7/16.
//
#ifndef CLOUDAPPCLIENT_VOICEACTION_H
#define CLOUDAPPCLIENT_VOICEACTION_H

#include <cstdlib>
#include "BaseAction.h"

namespace CloudAppClient {

template<class T>
class VoiceAction : public BaseAction<T> {
private:
    static VoiceAction *instance = nullptr;
    VoiceAction();
    virtual ~VoiceAction();

public:
    static VoiceAction *getInstance();

public:
    virtual void processAction(const T &actionBean);
    virtual void userStartPlay(const T &actionBean);
    virtual void userPausedPlay();
    virtual void userStopPlay();
    virtual void userResumePlay();
    virtual void pausePlay();
    virtual void stopPlay();
    virtual void resumePlay();
    virtual void forward();
    virtual void backward();
    virtual const Int32 getActionType();

};

}

#endif
