//
// Created by Fan Feng on 2017/7/13->
//
#ifndef CLOUDAPPCLIENT_NLPBEAN_H
#define CLOUDAPPCLIENT_NLPBEAN_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

namespace CloudAppClient{

class NLPBean {
private:
    /**
    * asr content
     */
    string asr;
    /**
     * intent cloudAppId
     */
    string appId;
    /**
     * intent
     */
    string mIntent;
    /**
     * indicate whether the action should execute: YES or NO
     */
    string confirm;
    /**
     * parameters for the intent key value string pairs
     */
    string slots;
    /**
    * nlp parse start position
    */
    int posStart = 0;
    /**
     * nlp parse end position
     */
    int posEnd = 0;
    /**
     * parse confidence 1.0f is the max value
     */
    float confidence = 0.0f;

    /**
     * the pattern that the sentence matched
     */
    string pattern;
    /**
     * the version of the hit xml
     */
    string version;

    /**
     * the original asr
     */
    string mVoice;

    /**
     * forward content
     */
    string forwardContent;

    /**
    * indicates the nlp is a cloud call
    */
    bool cloud = true;

public:
    NLPBean();

    NLPBean(const string &asr, const string &appId, const string &intent, const string &confirm,
            const string &slots, int posStart, int posEnd, float confidence, const string &pattern,
            const string &version, const string &voice, const string &forwardContent, bool cloud);

    virtual ~NLPBean();

    bool operator==(const NLPBean &rhs) const;

    bool operator!=(const NLPBean &rhs) const;

    NLPBean& operator=(const NLPBean &rhs);

    const string &getAsr() const;

    void setAsr(const string &asr);

    const string &getAppId() const;
    void setAppId(const string &appId);

    const string &getIntent() const;

    void setIntent(const string &intent);

    const string &getConfirm() const;

    void setConfirm(const string &confirm);

    const string &getSlots() const;

    void setSlots(const string &slots);

    int getPosStart() const;

    void setPosStart(int posStart);

    int getPosEnd() const;

    void setPosEnd(int posEnd);

    float getConfidence() const;

    void setConfidence(float confidence);

    const string &getPattern() const;

    void setPattern(const string &pattern);
    const string &getVersion() const;

    void setVersion(const string &version);

    const string &getVoice() const;
    void setVoice(const string &voice);

    const string &getForwardContent() const;

    void setForwardContent(const string &forwardContent);

    bool isCloud() const;

    void setCloud(bool cloud);

};
}

#endif
