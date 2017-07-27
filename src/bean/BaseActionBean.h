//
// Created by Fan Feng on 2017/7/14.
//

#include "../util/LogUtil.h"
#include "../util/TextUtil.h"

using std::string;

namespace CloudAppClient{
    class BaseActionBean {

    public:
        static const string ACTION_PLAY = "PLAY";
        static const string ACTION_PAUSE = "PAUSE";
        static const string ACTION_RESUME = "RESUME";
        static const string ACTION_STOP = "STOP";
        static const string ACTION_FORWARD = "FORWARD";
        static const string ACTION_BACKWARD = "BACKWARD";

        string action = nullptr;

        void setAction(const string &action) {
            BaseActionBean::action = action;
        }

        const string &getAction() const {
            return action;
        }

        bool isValid() {
            if (TextUtil::isEmpty(action)) {
                LogUtil::log("action is null !");
                return false;
            }
            //action 为其他操作不需要判断url/tts
            if (strcmp(ACTION_PLAY, action) && !canPlay()) {
                return false;
            }
            return true;
        }

        virtual bool canPlay();

    };
}