//
// Created by Fan Feng on 2017/7/19.
//

#include <string>
#include <map>
#include "VoiceBean.h"
#include "MediaBean.h"
#include "ActionBean.h"

using std::string;
using map_string = std::map<string, string>;

namespace CloudAppClient {

    class CloudActionResponseBean {

    private:
        string appId;
        string version;
        SessionBean session;
        ResponseBean response;

    public:
        const string &getAppId() const {
            return appId;
        }

        void setAppId(const string &appId) {
            CloudActionResponseBean::appId = appId;
        }

        const string &getVersion() const {
            return version;
        }

        void setVersion(const string &version) {
            CloudActionResponseBean::version = version;
        }

        const SessionBean &getSession() const {
            return session;
        }

        void setSession(const SessionBean &session) {
            CloudActionResponseBean::session = session;
        }

        const ResponseBean &getResponse() const {
            return response;
        }

        void setResponse(const ResponseBean &response) {
            CloudActionResponseBean::response = response;
        }
    };

    class SessionBean {

    private:
        string sessionId;
        /**
         * indicates whether it is a new session
         */

        bool newSession;

        string applicationId;

        /**
         * session attributes set by CloudApp in Response
         */
        map_string attributes;

    public:
        const string &getSessionId() const {
            return sessionId;
        }

        void setSessionId(const string &sessionId) {
            SessionBean::sessionId = sessionId;
        }

        bool isNewSession() const {
            return newSession;
        }

        void setNewSession(bool newSession) {
            SessionBean::newSession = newSession;
        }

        const string &getApplicationId() const {
            return applicationId;
        }

        void setApplicationId(const string &applicationId) {
            SessionBean::applicationId = applicationId;
        }

        const map_string &getAttributes() const {
            return attributes;
        }

        void setAttributes(const map_string &attributes) {
            SessionBean::attributes = attributes;
        }
    };

    class ResponseBean {

    public:
        static const string TYPE_INTENT = "INTENT";
        static const string TYPE_EVENT = "EVENT";

    private:
        string respId;
        /**
         * ONLY type INTENT and EVENT are available currently
         */
        string resType;

        CardBean card;
        ActionBean action;

    public:
        const string &getRespId() const {
            return respId;
        }

        void setRespId(const string &respId) {
            ResponseBean::respId = respId;
        }

        const string &getResType() const {
            return resType;
        }

        void setResType(const string &resType) {
            ResponseBean::resType = resType;
        }

        const CardBean &getCard() const {
            return card;
        }

        void setCard(const CardBean &card) {
            ResponseBean::card = card;
        }

        const ActionBean &getAction() const {
            return action;
        }

        void setAction(const ActionBean &action) {
            ResponseBean::action = action;
        }

        template<class T>
        class CardBean {

        private:
            string version;
            string type;
            T model;

        public:
            const string &getVersion() const {
                return version;
            }

            void setVersion(const string &version) {
                CardBean::version = version;
            }

            const string &getType() const {
                return type;
            }

            void setType(const string &type) {
                CardBean::type = type;
            }

            T getModel() const {
                return model;
            }

            void setModel(T model) {
                CardBean::model = model;
            }
        };
    };
}
