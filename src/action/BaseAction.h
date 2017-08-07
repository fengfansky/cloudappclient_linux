//
// Created by Fan Feng on 2017/7/22.
//
#pragma once

#include <iostream>
#include "../util/rlog.h"
#include "../bean/BaseActionBean.h"

using string = std::string;

namespace CloudAppClient {
    template<class T>
    class BaseAction {

    public:
        const char* TAG = "BaseAction";

        enum ACTION_TYPE {
            MEDIA,
            VOICE
        };

        virtual ~BaseAction();

        virtual void processAction(const T &actionBean) {
            rokid::log::Log::d(TAG, getActionType() + " processAction + actionBean : " + actionBean);

            if (actionBean == nullptr) {
                std::cout << getActionType() + " processAction actionBean is  null! " << std::endl;
                return;
            }
            string action = actionBean.getAction();

            if (action.empty()) {
                rokid::log::Log::d(TAG, getActionType() + " action is null!");
                return;
            }

            if (action.compare(BaseActionBean::ACTION_PLAY) == 0) {
                userStartPlay(actionBean);
            } else if (action.compare(BaseActionBean::ACTION_PAUSE) == 0) {
                userPausedPlay();
            } else if (action.compare(BaseActionBean::ACTION_RESUME) == 0) {
                userResumePlay();
            } else if (action.compare(BaseActionBean::ACTION_STOP) == 0) {
                userStopPlay();
            } else if (action.compare(BaseActionBean::ACTION_FORWARD) == 0) {
                forward();
            } else if (action.compare(BaseActionBean::ACTION_BACKWARD) == 0) {
                backward();
            } else {
                rokid::log::Log::d(TAG, (" invalidate action ! " + action).c_str());
            }
        };

        virtual void userStartPlay(const T &actionBean) = 0;

        virtual void userPausedPlay() = 0;

        virtual void userStopPlay() = 0;

        virtual void userResumePlay() = 0;

        virtual void pausePlay() = 0;

        virtual void stopPlay() = 0;

        virtual void resumePlay() = 0;

        virtual void forward() = 0;

        virtual void backward() = 0;

        virtual const ACTION_TYPE &getActionType() = 0;

    };
}