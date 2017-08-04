//
// Created by Fan Feng on 2017/7/29.
//

#include <string>
#include <map>

using std::string;
using map_string = std::map<string, string>;
namespace CloudAppClient {

    class SessionBean {

    private:
        string sessionId;
        /**
         * indicates whether it is a new session
         */

        bool newSession = false;

        string applicationId;

        /**
         * session attributes set by CloudApp in Response
         */
        map_string attributes;

    public:

        SessionBean() : newSession(false) {

        }

        SessionBean(const string &sessionId, bool newSession, const string &applicationId, const map_string &attributes)
                : sessionId(sessionId), newSession(newSession), applicationId(applicationId), attributes(attributes) {}

        virtual ~SessionBean() {

        }

        bool operator==(const SessionBean &rhs) const {
            return sessionId == rhs.sessionId &&
                   newSession == rhs.newSession &&
                   applicationId == rhs.applicationId &&
                   attributes == rhs.attributes;
        }

        bool operator!=(const SessionBean &rhs) const {
            return !(rhs == *this);
        }

        SessionBean& operator=(const SessionBean &rhs){
            sessionId = rhs.sessionId;
            newSession = rhs.newSession;
            applicationId = rhs.applicationId;
            attributes = rhs.attributes;
            return *this;
        }

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

}
