//
// Created by Fan Feng on 2017/7/14.
//
#ifndef CLOUDAPPCLIENT_MEDIAACTION_H
#define CLOUDAPPCLIENT_MEDIAACTION_H

#include <cstdlib>
#include "BaseAction.h"

namespace CloudAppClient {

template<class T>
class MediaAction : public BaseAction<T> {

private:
    static MediaAction *instance = nullptr;

    MediaAction();
    virtual ~MediaAction();

public:
    static MediaAction* getInstance();

public:

    virtual void userStartPlay(const T &actionBean);
    virtual void userPausedPlay();
    virtual void userStopPlay();
    virtual void userResumePlay();
    virtual void pausePlay();
    virtual  void stopPlay();
    virtual void resumePlay();
    virtual void forward();
    virtual void backward();
    virtual const Int32 getActionType();

};

}

#endif

