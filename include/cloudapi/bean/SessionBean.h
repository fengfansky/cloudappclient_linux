//
// Created by Fan Feng on 2017/7/29.
//
#ifndef CLOUDAPPCLIENT_SESSIONBEAN_H
#define CLOUDAPPCLIENT_SESSIONBEAN_H

#include <string>
#include <map>


using namespace std;

namespace CloudAppClient{

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
    string attributes;

public:

    SessionBean();

    SessionBean(const string &sessionId, bool newSession, const string &applicationId, const string &attributes);
    virtual ~SessionBean();

    bool operator==(const SessionBean &rhs) const;

    bool operator!=(const SessionBean &rhs) const;

    SessionBean& operator=(const SessionBean &rhs);

    const string &getSessionId() const;

    void setSessionId(const string &sessionId);

    bool isNewSession() const;

    void setNewSession(bool newSession);

    const string &getApplicationId() const;

    void setApplicationId(const string &applicationId);

    const string &getAttributes() const;

    void setAttributes(const string &attributes);
};

}

#endif
