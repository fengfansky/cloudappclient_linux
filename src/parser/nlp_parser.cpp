//
// Created by Fan Feng on 2017/7/28.
//

#include "nlp_parser.h"
#include "../util/rlog.h"
#include "../json/json.h"

namespace CloudAppClient {

    const static char* TAG = "nlp_parser";

    bool nlp_parser::string_to_nlp(const std::string &nlp_string, NLPBean &nlp_bean) {

        rokid::log::Log::d(TAG, "parse nlp ");

        if (nlp_string.empty()) {
            rokid::log::Log::d(TAG, "str is null !");
            return false;
        }

        //初始化
        auto jsonDom = nlohmann::json::parse("{}");

        try {
            jsonDom = nlohmann::json::parse(nlp_string);
        } catch (nlohmann::json::exception json_exception) {
//            rokid::log::Log::e(TAG, json_exception.what());
            return false;
        }

        auto nlp = jsonDom["nlp"];

        if (nlp == nullptr) {
            rokid::log::Log::d(TAG, " nlp is null !");
            return false;
        }

        auto asr = nlp["asr"];

        if (asr != nullptr && !asr.get<string>().empty()) {
            nlp_bean.setAsr(asr.get<string>());
            rokid::log::Log::d(TAG, ("asr : " + nlp_bean.getAsr()).c_str());
        }

        auto appId = nlp["appId"];

        if (appId != nullptr && !appId.get<string>().empty()) {
            nlp_bean.setAppId(appId.get<string>());
            rokid::log::Log::d(TAG, ("appId : " + nlp_bean.getAppId()).c_str());
        } else {
            rokid::log::Log::d(TAG, "appId is null !");
            return false;
        }

        auto cloud = nlp["cloud"];

        if (cloud != nullptr) {
            nlp_bean.setCloud(cloud.get<bool>());
            string cloud_str = cloud ? "true" : "false";
            rokid::log::Log::d(TAG, ("cloud : " + cloud_str).c_str());
        } else {
            rokid::log::Log::d(TAG, "cloud : null !");
            return false;
        }

        auto intent = nlp["intent"];

        if (intent != nullptr && !intent.get<string>().empty()) {
            nlp_bean.setIntent(intent.get<string>());
            rokid::log::Log::d(TAG, (" intent : " + nlp_bean.getIntent()).c_str());
        }

        auto pattern = nlp["pattern"];

        if (pattern != nullptr && !pattern.get<string>().empty()) {
            nlp_bean.setPattern(pattern.get<string>());
            rokid::log::Log::d(TAG, (" pattern : " + nlp_bean.getPattern()).c_str());
        }

        auto confirm = nlp["confirm"];

        if (confirm != nullptr && !confirm.get<string>().empty()) {
            nlp_bean.setConfirm(confirm.get<string>());
            rokid::log::Log::d(TAG, ("confirm : " + nlp_bean.getConfirm()).c_str());
        }

        auto posStart = nlp["posStart"];

        if (posStart != nullptr) {
            nlp_bean.setPosStart(posStart.get<int>());
        }

        auto posEnd = nlp["posEnd"];

        if (posEnd != nullptr) {
            nlp_bean.setPosEnd(posEnd.get<int>());
        }

        auto confidence = nlp["confidence"];

        if (confidence != nullptr) {
            nlp_bean.setConfidence(confidence.get<float>());
        }

        auto version = nlp["version"];

        if (version != nullptr && !version.get<string>().empty()) {
            nlp_bean.setVersion(version.get<string>());
            rokid::log::Log::d(TAG, (" confidence : " + nlp_bean.getVersion()).c_str());
        }

        auto voice = nlp["voice"];

        if (voice != nullptr && !voice.get<string>().empty()) {
            nlp_bean.setVoice(voice.get<string>());
            rokid::log::Log::d(TAG, (" voice : " + nlp_bean.getVoice()).c_str());
        }

        auto forwardContent = nlp["forwardContent"];

        if (forwardContent != nullptr && !forwardContent.get<string>().empty()) {
            nlp_bean.setForwardContent(forwardContent.get<string>());
            rokid::log::Log::d(TAG, (" forwardContent : " + nlp_bean.getForwardContent()).c_str());
        }

        auto slots = nlp["slots"];
        if (slots != nullptr) {
            nlp_bean.setSlots(slots.get<std::map<string, string>>());
        }

        return true;
    }


}