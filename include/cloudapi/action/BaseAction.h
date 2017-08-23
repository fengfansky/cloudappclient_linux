//
// Created by Fan Feng on 2017/7/22.
//

#ifndef CLOUDAPPCLIENT_BASEACTION_H
#define CLOUDAPPCLIENT_BASEACTION_H

#include <iostream>
#include "../bean/BaseActionBean.h"
#include "Poco/Types.h"

using namespace std;
using namespace Poco;

namespace CloudAppClient {

template<class T>
class BaseAction {

public:
    const char* TAG = "BaseAction";

    enum {
        MEDIA,
        VOICE
    };

    BaseAction() { }
    virtual ~BaseAction() { }

    virtual void processAction(const T &actionBean);

    virtual void userStartPlay(const T &actionBean) = 0;

    virtual void userPausedPlay() = 0;

    virtual void userStopPlay() = 0;

    virtual void userResumePlay() = 0;

    virtual void pausePlay() = 0;

    virtual void stopPlay() = 0;

    virtual void resumePlay() = 0;

    virtual void forward() = 0;

    virtual void backward() = 0;

    virtual const Int32 getActionType() = 0;

};

}

#endif

