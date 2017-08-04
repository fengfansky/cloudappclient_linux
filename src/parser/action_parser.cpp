//
// Created by Fan Feng on 2017/7/28.
//

#include "action_parser.h"
#include "../json/json.h"

namespace CloudAppClient {

    bool action_parser::string_to_action(const std::string &action_str, CloudActionResponseBean &action_bean) {

        rokid::log::Log::d(TAG, " parse action ");

        if (action_str.empty()) {
            rokid::log::Log::d(TAG, " action_str : null ! return !");
            return false;
        }

        //初始化
        auto jsonDom = nlohmann::json::parse("{}");

        try {
            jsonDom = nlohmann::json::parse(action_str);
        } catch (nlohmann::json::exception json_exception) {
            rokid::log::Log::e(TAG, json_exception.what());
            return false;
        }

        auto action = jsonDom["action"];

        if (action == nullptr) {
            rokid::log::Log::d(TAG, "action : null ! return !");
            return false;
        }

        if (action["appId"] != nullptr && !(action["appId"].get<string>()).empty()) {
            action_bean.setAppId(action["appId"].get<string>());
            rokid::log::Log::d(TAG, (" appId : " + action_bean.getAppId()).c_str());
        } else {
            rokid::log::Log::d(TAG, " appId : null! return !");
            return false;
        }

        auto version = action["version"];
        if (version != nullptr && !(version.get<string>()).empty()) {
            action_bean.setVersion(version.get<string>());
            rokid::log::Log::d(TAG, ("version : " + action_bean.getVersion()).c_str());
        } else {
            rokid::log::Log::d(TAG, "version : null ! return !");
            return false;
        }

        auto response = action["response"];

        ResponseBean response_bean;

        if (response == nullptr) {
            rokid::log::Log::d(TAG, "response : null! return !");
            return false;
        }

        auto resType = response["resType"];


        if (resType != nullptr && !resType.get<string>().empty()) {
            response_bean.setResType(resType.get<string>());
            rokid::log::Log::d(TAG, ("resType : " + response_bean.getResType()).c_str());
        } else {
            rokid::log::Log::d(TAG, "resType : null ! return !");
            return false;
        }

        auto respId = response["respId"];

        if (respId != nullptr && !respId.get<string>().empty()) {
            response_bean.setRespId(respId.get<string>());
            rokid::log::Log::d(TAG, ("respId : " + response_bean.getRespId()).c_str());
        }

        auto action_inner = response["action"];

        ActionBean action_bean_inner;

        if (action_inner == nullptr) {
            rokid::log::Log::d(TAG, "action : null ! return !");
            return false;
        }

        auto form = action_inner["form"];

        if (form != nullptr && !form.get<string>().empty()) {
            action_bean_inner.setForm(form.get<string>());
            rokid::log::Log::d(TAG, ("action form : " + action_bean_inner.getForm()).c_str());
        } else {
            rokid::log::Log::d(TAG, "form is null ! return !");
            return false;
        }

        auto media = action_inner["media"];

        if (media != nullptr) {
            auto media_action = media["action"];

            auto media_item = media["item"];

            MediaBean media_bean;

            MediaItemBean media_item_bean;

            if (media_action != nullptr && !media_action.get<string>().empty()) {
                media_bean.setAction(media_action.get<string>());
                rokid::log::Log::d(TAG, ("media action : " + media_bean.getAction()).c_str());
            } else {
                rokid::log::Log::d(TAG, "media action : null!");
            }

            if (media_item != nullptr) {

                auto offsetInMilliseconds = media_item["offsetInMilliseconds"];

                if (offsetInMilliseconds != nullptr) {
                    media_item_bean.setOffsetInMilliseconds(offsetInMilliseconds.get<int>());
                } else {
                    rokid::log::Log::d(TAG, "media action offsetInMilliseconds : null !");
                }

                auto media_item_type = media_item["type"];

                if (media_item_type != nullptr && !media_item_type.get<string>().empty()) {
                    media_item_bean.setType(media_item_type.get<string>());
                    rokid::log::Log::d(TAG, ("media item type : " + media_item_bean.getType()).c_str());
                } else {
                    rokid::log::Log::d(TAG, "media item type : null !");
                }

                auto url = media_item["url"];

                if (url != nullptr && !url.get<string>().empty()) {
                    media_item_bean.setUrl(url.get<string>());
                    rokid::log::Log::d(TAG, ("media item url : " + url.get<string>()).c_str());
                } else {
                    rokid::log::Log::d(TAG, "media item type : null !");
                }

                media_bean.setItem(media_item_bean);

            } else {
                rokid::log::Log::d(TAG, "media item : null !");
            }
            action_bean_inner.setMedia(media_bean);
        } else {
            rokid::log::Log::d(TAG, "media : null!");
        }

        auto voice = action_inner["voice"];

        VoiceBean voice_bean;

        if (voice != nullptr) {
            auto voice_action = voice["action"];
            auto voice_item = voice["item"];

            if (voice_action != nullptr && !voice_action.get<string>().empty()) {
                voice_bean.setAction(voice_action.get<string>());
                rokid::log::Log::d(TAG, ("voice action : " + voice_bean.getAction()).c_str());
            } else {
                rokid::log::Log::d(TAG, "voice action : null!");
            }

            if (voice_item != nullptr) {
                VoiceItemBean voice_item_bean;

                auto voice_item_tts = voice_item["tts"];
                if (voice_item_tts != nullptr && !voice_item_tts.get<string>().empty()) {
                    voice_item_bean.setTts(voice_item_tts.get<string>());
                    rokid::log::Log::d(TAG, ("voice item tts : " + voice_item_bean.getTts()).c_str());
                } else {
                    rokid::log::Log::d(TAG, "voice item tts : null!");
                }
                voice_bean.setVoiceItemBean(voice_item_bean);
            } else {
                rokid::log::Log::d(TAG, "voice item : null!");
            }
            action_bean_inner.setVoice(voice_bean);
        } else {
            rokid::log::Log::d(TAG, "voice : null !");
        }

        auto type = action_inner["type"];

        if (type != nullptr && !type.get<string>().empty()) {
            action_bean_inner.setType(type.get<string>());
            rokid::log::Log::d(TAG, ("type : " + action_bean_inner.getType()).c_str());
        }

        auto action_version = action_inner["version"];

        if (action_version != nullptr && !action_version.get<string>().empty()) {
            action_bean_inner.setVersion(action_version.get<string>());
            rokid::log::Log::d(TAG, ("version : " + action_bean_inner.getVersion()).c_str());
        }

        auto shouldEndSession = action_inner["shouldEndSession"];

        if (shouldEndSession != true) {
            action_bean_inner.setShouldEndSession(shouldEndSession.get<bool>());
            string isShouldEndSession = action_bean_inner.isShouldEndSession() ? "true" : "false";
            rokid::log::Log::d(TAG, ("shouldEndSession : " + isShouldEndSession).c_str());
        }

        response_bean.setAction(action_bean_inner);

        action_bean.setResponse(response_bean);

        SessionBean session_bean;

        auto sessionId = action["sessionId"];

        if (sessionId != nullptr && !sessionId.get<string>().empty()) {
            session_bean.setSessionId(sessionId.get<string>());
            rokid::log::Log::d(TAG, (" sessionId is " + session_bean.getSessionId()).c_str());
        }

        auto newSession = action["newSession"];

        if (newSession != nullptr) {
            session_bean.setNewSession(newSession.get<bool>());
        }

        auto applicationId = action["applicationId"];

        if (applicationId != nullptr && !newSession.get<string>().empty()) {
            session_bean.setApplicationId(newSession.get<string>());
            rokid::log::Log::d(TAG, ("applicationId : " + session_bean.getApplicationId()).c_str());
        }

        auto attributes = action["attributes"];

        if (attributes != nullptr && !attributes.get<std::map<string, string>>().empty()) {
            session_bean.setAttributes(newSession.get<std::map<string, string>>());
        }

        action_bean.setSession(session_bean);

        return true;
    }

}