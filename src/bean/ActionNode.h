//
// Created by Fan Feng on 2017/7/16.
//
#ifndef CLOUDAPPCLIENT_ACTIONNODE_H
#define CLOUDAPPCLIENT_ACTIONNODE_H

#include <string>
#include "NLPBean.h"
#include "VoiceBean.h"
#include "MediaBean.h"
#include "ConfirmBean.h"
#include "PickupBean.h"

using namespace std;

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
    ActionNode();
    virtual ~ActionNode();
    bool operator==(const ActionNode &rhs) const;
    bool operator!=(const ActionNode &rhs) const;
    ActionNode& operator=(const ActionNode &rhs);
    void setAsr(const string &asr);
    void setNlp(const NLPBean &nlp);
    const ConfirmBean &getConfirm() const;
    void setConfirm(const ConfirmBean &confirm);
    const PickupBean &getPickup() const;
    void setPickup(const PickupBean &pickup);
    const string &getAsr() const ;
    const NLPBean &getNlp() const;
    const string &getRespId() const;

    void setRespId(const string &respId);
    const string &getResType() const;
    void setResType(const string &resType);
    const string &getAppId() const;
    void setAppId(const string &appId);
    const string &getForm() const;
    void setForm(const string &form);
    const string & getActionType()const;
    void setActionType(const string &actionType);

    bool isShouldEndSession() const;

    void setShouldEndSession(bool shouldEndSession);

    const VoiceBean &getVoice() const;

    void setVoice(const VoiceBean &voice);

    const MediaBean &getMedia() const;

    void setMedia(const MediaBean &media);
};

}

#endif
