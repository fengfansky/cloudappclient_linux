//
// Created by Fan Feng on 2017/7/16.
//

#include <string>
#include "NLPBean.h"
#include "VoiceBean.h"
#include "MediaBean.h"
#include "ConfirmBean.h"
#include "PickupBean.h"

using std::string;

namespace CloudAppClient {
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
        ConfirmBean confirm;
        PickupBean pickup;

    public:
        ActionNode() {}

        virtual ~ActionNode() {

        }

        bool operator==(const ActionNode &rhs) const {
            return asr == rhs.asr &&
                   nlp == rhs.nlp &&
                   respId == rhs.respId &&
                   resType == rhs.resType &&
                   appId == rhs.appId &&
                   form == rhs.form &&
                   actionType == rhs.actionType &&
                   shouldEndSession == rhs.shouldEndSession &&
                   voice == rhs.voice &&
                   media == rhs.media &&
                   confirm == rhs.confirm &&
                   pickup == rhs.pickup;
        }

        bool operator!=(const ActionNode &rhs) const {
            return !(rhs == *this);
        }

        ActionNode& operator=(const ActionNode &rhs){
            asr = rhs.asr;
            nlp = rhs.nlp;
            respId = rhs.respId;
            resType = rhs.resType;
            appId = rhs.appId;
            form = rhs.form;
            actionType = rhs.actionType;
            shouldEndSession = rhs.shouldEndSession;
            voice = rhs.voice;
            media = rhs.media;
            confirm = rhs.confirm;
        }

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

        void setAsr(const string &asr) {
            ActionNode::asr = asr;
        }

        void setNlp(const NLPBean &nlp) {
            ActionNode::nlp = nlp;
        }

        const ConfirmBean &getConfirm() const {
            return confirm;
        }

        void setConfirm(const ConfirmBean &confirm) {
            ActionNode::confirm = confirm;
        }

        const PickupBean &getPickup() const {
            return pickup;
        }

        void setPickup(const PickupBean &pickup) {
            ActionNode::pickup = pickup;
        }
    };
}