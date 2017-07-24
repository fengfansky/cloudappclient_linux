//
// Created by Fan Feng on 2017/7/17.
//

#include "BaseActionBean.h"

namespace cloudappclient {
    class VoiceBean : BaseActionBean {

    private:
        VoiceItemBean voiceItemBean;

    public:
        const VoiceItemBean &getVoiceItemBean() const {
            return voiceItemBean;
        }

        void setVoiceItemBean(const VoiceItemBean &voiceItemBean) {
            VoiceBean::voiceItemBean = voiceItemBean;
        }

        bool canPlay() {
            return &voiceItemBean != nullptr && !TextUtil::isEmpty(voiceItemBean.getTts());
        }

    };

    class VoiceItemBean {

    private:
        string tts;

    public:
        const string &getTts() const {
            return tts;
        }

        void setTts(const string &tts) {
            VoiceItemBean::tts = tts;
        }

    };
}