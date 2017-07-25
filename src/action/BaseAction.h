//
// Created by Fan Feng on 2017/7/22.
//

#include <iostream>
#include "../bean/BaseActionBean.h"

using namespace std;
namespace cloudappclient {
    template<class T>
    class BaseAction {

    public:
        enum ACTION_TYPE {
            MEDIA,
            VOICE
        };

        void BaseAction();

        virtual ~BaseAction();

        virtual void processAction(const T &actionBean) {
            LogUtil::log(getActionType() + " processAction + actionBean : " + actionBean);

            if (actionBean == nullptr) {
                std::cout << getActionType() + " processAction actionBean is  null! " << std::endl;
                return;
            }
            string action = actionBean.getAction();

            if (TextUtil::isEmpty(action)) {
                LogUtil::log(getActionType() + " action is null!");
                return;
            }

            if (strcmp(action, BaseActionBean::ACTION_PLAY)) {
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
                LogUtil::log(" invalidate action ! " + action);
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

        virtual ACTION_TYPE &getActionType() = 0;

    };
}