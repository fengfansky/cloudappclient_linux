//
// Created by Fan Feng on 2017/7/14.
//
#pragma once

#include <string>
#include "../util/rlog.h"

using std::string;

namespace CloudAppClient {
    class BaseActionBean {

    public:
        static constexpr const char *ACTION_PLAY = "PLAY";
        static constexpr const char *ACTION_PAUSE = "PAUSE";
        static constexpr const char *ACTION_RESUME = "RESUME";
        static constexpr const char *ACTION_STOP = "STOP";
        static constexpr const char *ACTION_FORWARD = "FORWARD";
        static constexpr const char *ACTION_BACKWARD = "BACKWARD";

        string action;

        BaseActionBean() {}

        BaseActionBean(const string &action) : action(action) {
        }

        virtual ~BaseActionBean() {
        }

        bool operator==(const BaseActionBean &rhs) const {
            return action == rhs.action;
        }

        bool operator!=(const BaseActionBean &rhs) const {
            return !(rhs == *this);
        }

        BaseActionBean &operator=(const BaseActionBean &rhs) {
            action = rhs.action;
            return *this;
        }

        void setAction(const string &action) {
            BaseActionBean::action = action;
        }

        const string &getAction() const {
            return action;
        }

        bool isValid() {
            if (action.empty()) {
                rokid::log::Log::d("Action", "action is null !");
                return false;
            }
            //action 为其他操作不需要判断url/tts
            if (action.compare(ACTION_PLAY) != 0 && !canPlay()) {
                return false;
            }
            return true;
        }

        bool canPlay();

    };
}