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

        void BaseAction();

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

            if (strcmp(action, BaseActionBean::ACTION_PLAY) == 0) {
                userStartPlay(actionBean);
            } else if (strcmp(action, BaseActionBean::ACTION_PAUSE)) {
                userPausedPlay();
            } else if (strcmp(action, BaseActionBean::ACTION_RESUME)) {
                userResumePlay();
            } else if (strcmp(action, BaseActionBean::ACTION_STOP)) {
                userStopPlay();
            } else if (strcmp(action, BaseActionBean::ACTION_FORWARD)) {
                forward();
            } else if (strcmp(action, BaseActionBean::ACTION_BACKWARD)) {
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