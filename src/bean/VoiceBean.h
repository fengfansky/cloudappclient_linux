//
// Created by Fan Feng on 2017/7/17.
//
#pragma once

#include "BaseActionBean.h"

namespace CloudAppClient {

    class VoiceItemBean {

    private:
        string tts;

    public:

        VoiceItemBean() {}

        VoiceItemBean(const string &tts) : tts(tts) {}

        virtual ~VoiceItemBean() {

        }

        bool operator==(const VoiceItemBean &rhs) const {
            return tts == rhs.tts;
        }

        bool operator!=(const VoiceItemBean &rhs) const {
            return !(rhs == *this);
        }

    public:

        VoiceItemBean &operator=(const VoiceItemBean &rhs) {
            tts = rhs.tts;
            return *this;
        }

        const string &getTts() const {
            return tts;
        }

        void setTts(const string &tts) {
            VoiceItemBean::tts = tts;
        }

    };

    class VoiceBean : public BaseActionBean {

    private:
        VoiceItemBean voiceItemBean;

    public:

        VoiceBean() {}

        VoiceBean(const string &action) : BaseActionBean(action) {}

        VoiceBean(const string &action, const VoiceItemBean &voiceItemBean) : BaseActionBean(action),
                                                                              voiceItemBean(voiceItemBean) {
        }

        virtual ~VoiceBean() {

        }

        bool operator==(const VoiceBean &rhs) const {
            return static_cast<const VoiceBean &>(*this) == static_cast<const VoiceBean &>(rhs) &&
                   voiceItemBean == rhs.voiceItemBean;
        }

        bool operator!=(const VoiceBean &rhs) const {
            return !(rhs == *this);
        }

        VoiceBean &operator=(const VoiceBean &vb){
            voiceItemBean = vb.voiceItemBean;
            return *this;
        };

        const VoiceItemBean &getVoiceItemBean() const {
            return voiceItemBean;
        }

        void setVoiceItemBean(const VoiceItemBean &voiceItemBean) {
            VoiceBean::voiceItemBean = voiceItemBean;
        }

        bool canPlay() {
            return !(voiceItemBean.getTts().empty());
        }

    };

}