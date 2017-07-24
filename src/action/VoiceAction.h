//
// Created by Fan Feng on 2017/7/16.
//

#include <cstdlib>
#include "../util/LogUtil.h"
#include "BaseAction.h"

namespace cloudappclient {
    template<class T>
    class VoiceAction : public BaseAction {

        static VoiceAction *instance = nullptr;

        VoiceAction::VoiceAction() {

        }

        VoiceAction::~VoiceAction() {
            delete instance;
        }

    public:
        static VoiceAction *getInstance() {
            if (instance == nullptr) {
                instance = new VoiceAction();
            }

            return instance;
        }

        void processAction(const T &actionBean) override {
            BaseAction::processAction(actionBean);
        }

        void userStartPlay(const T &actionBean) override {

        }

        void userPausedPlay() override {

        }

        void userStopPlay() override {

        }

        void userResumePlay() override {

        }

        void pausePlay() override {

        }

        void stopPlay() override {

        }

        void resumePlay() override {

        }

        void forward() override {

        }

        void backward() override {

        }

        ACTION_TYPE &getActionType() override {
            return ACTION_TYPE ::VOICE;
        }

    };
}
