//
// Created by Fan Feng on 2017/7/13->
//
#pragma once

#include <iostream>
#include <map>

using std::string;
using map_string = std::map<string, string>;

namespace CloudAppClient {
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
        string intent;
        /**
         * indicate whether the action should execute: YES or NO
         */
        string confirm;
        /**
         * parameters for the intent key value string pairs
         */
        map_string slots;
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
        string voice;

        /**
         * forward content
         */
        string forwardContent;

        /**
        * indicates the nlp is a cloud call
        */
        bool cloud = true;

    public:
        NLPBean() {}

        virtual ~NLPBean() {

        }

        bool operator==(const NLPBean &rhs) const {
            return asr == rhs.asr &&
                   appId == rhs.appId &&
                   intent == rhs.intent &&
                   confirm == rhs.confirm &&
                   slots == rhs.slots &&
                   posStart == rhs.posStart &&
                   posEnd == rhs.posEnd &&
                   confidence == rhs.confidence &&
                   pattern == rhs.pattern &&
                   version == rhs.version &&
                   voice == rhs.voice &&
                   forwardContent == rhs.forwardContent &&
                   cloud == rhs.cloud;
        }

        bool operator!=(const NLPBean &rhs) const {
            return !(rhs == *this);
        }

        NLPBean& operator=(const NLPBean &rhs){
            asr = rhs.asr;
            appId = rhs.appId;
            intent = rhs.intent;
            confirm = rhs.confirm;
            slots = rhs.slots;
            posStart = rhs.posStart;
            posEnd = rhs.posEnd;
            confidence = rhs.confidence;
            pattern = rhs.pattern;
            version = rhs.version;
            voice = rhs.voice;
            forwardContent = rhs.forwardContent;
            cloud = rhs.cloud;
            return  *this;
        }

        const string &getAsr() const {
            return asr;
        }

        void setAsr(const string &asr) {
            NLPBean::asr = asr;
        }

        const string &getAppId() const {
            return appId;
        }

        void setAppId(const string &appId) {
            NLPBean::appId = appId;
        }

        const string &getIntent() const {
            return intent;
        }

        void setIntent(const string &intent) {
            NLPBean::intent = intent;
        }

        const string &getConfirm() const {
            return confirm;
        }

        void setConfirm(const string &confirm) {
            NLPBean::confirm = confirm;
        }

        const map_string &getSlots() const {
            return slots;
        }

        void setSlots(const map_string &slots) {
            NLPBean::slots = slots;
        }

        int getPosStart() const {
            return posStart;
        }

        void setPosStart(int posStart) {
            NLPBean::posStart = posStart;
        }

        int getPosEnd() const {
            return posEnd;
        }

        void setPosEnd(int posEnd) {
            NLPBean::posEnd = posEnd;
        }

        float getConfidence() const {
            return confidence;
        }

        void setConfidence(float confidence) {
            NLPBean::confidence = confidence;
        }

        const string &getPattern() const {
            return pattern;
        }

        void setPattern(const string &pattern) {
            NLPBean::pattern = pattern;
        }

        const string &getVersion() const {
            return version;
        }

        void setVersion(const string &version) {
            NLPBean::version = version;
        }

        const string &getVoice() const {
            return voice;
        }

        void setVoice(const string &voice) {
            NLPBean::voice = voice;
        }

        const string &getForwardContent() const {
            return forwardContent;
        }

        void setForwardContent(const string &forwardContent) {
            NLPBean::forwardContent = forwardContent;
        }

        bool isCloud() const {
            return cloud;
        }

        void setCloud(bool cloud) {
            NLPBean::cloud = cloud;
        }

    };
}
