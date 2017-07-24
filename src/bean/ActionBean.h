//
// Created by Fan Feng on 2017/7/19.
//

#include <string>
#include "VoiceBean.h"
#include "MediaBean.h"

using std::string;

namespace cloudappclient {
    class ActionBean {

    public:
        static const string PROTOCOL_VERSION = "2.0.0";
        /**
* When type is NORMAL , voice , display and media will be executed concurrently
*/
        static const string TYPE_NORMAL = "NORMAL";
        /**
         * When type is EXIT , the action will be shut down immediately.
         * In this case, voice , display and media will be ignored.
         */
        static const string TYPE_EXIT = "EXIT";

        static const string FORM_SCENE = "scene";
        static const string FORM_CUT = "cut";
        static const string FORM_SERVICE = "service";

    private:
        /**
        * 表明 action 协议版本，当前版本为: 2.0.0.
        */
        string version;
        /**
         * 前action的类型：NORMAL 或 EXIT。 当 type 是 NORMAL 时，voice 和 media 会同时执行；当 type      * 是 EXIT 时，action会立即退出，并且在这种情况下，voice 和 media 将会被会被忽略
         */
        string type;
        /**
         * 表明当此次返回的action执行完后 CloudAppClient 是否要退出，同时，当 shouldEndSession 为 true     * 时，CloudAppClient 将会忽略 EventRequests，即在action执行过程中不会产生 EventRequest。
         */
        bool shouldEndSession;
        /**
        * 当前action的展现形式：scene、cut、service。scene的action会在被打断后压栈，cut的action会在被打    * 断后直接结束，service会在后台执行，但没有任何界面。该字段在技能创建时被确定，无法由cloud app更改。
        */
        string form;

        VoiceBean voice;

        MediaBean media;

        //TODO display and confirm

    public:
        const string &getVersion() const {
            return version;
        }

        void setVersion(const string &version) {
            ActionBean::version = version;
        }

        const string &getType() const {
            return type;
        }

        void setType(const string &type) {
            ActionBean::type = type;
        }

        bool isShouldEndSession() const {
            return shouldEndSession;
        }

        void setShouldEndSession(bool shouldEndSession) {
            ActionBean::shouldEndSession = shouldEndSession;
        }

        const string &getForm() const {
            return form;
        }

        void setForm(const string &form) {
            ActionBean::form = form;
        }

        const VoiceBean &getVoice() const {
            return voice;
        }

        void setVoice(const VoiceBean &voice) {
            ActionBean::voice = voice;
        }

        const MediaBean &getMedia() const {
            return media;
        }

        void setMedia(const MediaBean &media) {
            ActionBean::media = media;
        }

    };
}