//
// Created by Fan Feng on 2017/7/14.
//

#include <cstdlib>
#include "../util/LogUtil.h"
#include "BaseAction.h"

namespace cloudappclient {
    template<class T>
    class MediaAction : public BaseAction {

    private:
        static MediaAction *instance = nullptr;

        MediaAction::MediaAction() {
            //TODO init RKAudioPlayer
        }

        MediaAction::~MediaAction() {
            delete instance;
        }

    public:
        static MediaAction *getInstance() {
            if (instance == nullptr) {
                instance = new MediaAction();
            }

            return instance;
        }

    public:

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
            return ACTION_TYPE ::MEDIA;
        }

    };
}
