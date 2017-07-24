//
// Created by Fan Feng on 2017/7/16.
//

#include <string>
#include "NLPBean.h"
#include "VoiceBean.h"
#include "MediaBean.h"

using std::string;

namespace cloudappclient {
    class ActionNode {
    private:
        string asr;
        NLPBean nlp;
        string respId;
        string resType;
        string appId;
        string form;
        string actionType;
        bool shouldEndSession;
        VoiceBean voice;
        MediaBean media;
        //TODO confirm
//        ConfirmBean confirmBean;

    public:
        const string &getAsr() const {
            return asr;
        }

        const NLPBean &getNlp() const {
            return nlp;
        }

        const string &getRespId() const {
            return respId;
        }

        void setRespId(const string &respId) {
            ActionNode::respId = respId;
        }

        const string &getResType() const {
            return resType;
        }

        void setResType(const string &resType) {
            ActionNode::resType = resType;
        }

        const string &getAppId() const {
            return appId;
        }

        void setAppId(const string &appId) {
            ActionNode::appId = appId;
        }

        const string &getForm() const {
            return form;
        }

        void setForm(const string &form) {
            ActionNode::form = form;
        }

        const string &getActionType() const {
            return actionType;
        }

        void setActionType(const string &actionType) {
            ActionNode::actionType = actionType;
        }

        bool isShouldEndSession() const {
            return shouldEndSession;
        }

        void setShouldEndSession(bool shouldEndSession) {
            ActionNode::shouldEndSession = shouldEndSession;
        }

        const VoiceBean &getVoice() const {
            return voice;
        }

        void setVoice(const VoiceBean &voice) {
            ActionNode::voice = voice;
        }

        const MediaBean &getMedia() const {
            return media;
        }

        void setMedia(const MediaBean &media) {
            ActionNode::media = media;
        }
    };
}