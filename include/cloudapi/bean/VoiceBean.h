//
// Created by Fan Feng on 2017/7/17.
//
#ifndef CLOUDAPPCLIENT_VOICEBEAN_H
#define CLOUDAPPCLIENT_VOICEBEAN_H

#include "BaseActionBean.h"

using namespace std;

namespace CloudAppClient{

class VoiceItemBean {

private:
    string tts;

public:

    VoiceItemBean();
    VoiceItemBean(const string &tts);
    virtual ~VoiceItemBean();
    bool operator==(const VoiceItemBean &rhs) const;
    bool operator!=(const VoiceItemBean &rhs) const;
public:
    VoiceItemBean &operator=(const VoiceItemBean &rhs);
    const string &getTts() const;
    void setTts(const string &tts);
};

class VoiceBean : public BaseActionBean {

private:
    VoiceItemBean voiceItemBean;

public:

    VoiceBean();
    VoiceBean(const string &action);
    VoiceBean(const string &action, const VoiceItemBean &voiceItemBean);
    virtual ~VoiceBean();

    bool operator==(const VoiceBean &rhs) const;
    bool operator!=(const VoiceBean &rhs) const;
    VoiceBean &operator=(const VoiceBean &vb);

    const VoiceItemBean &getVoiceItemBean() const;
    void setVoiceItemBean(const VoiceItemBean &voiceItemBean);
    bool canPlay();

};

}

#endif
