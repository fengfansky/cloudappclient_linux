//
// Created by Fan Feng on 2017/7/19.
//
#ifndef CLOUDAPPCLIENT_CLOUDACTIONRESPONSEBEAN_H
#define CLOUDAPPCLIENT_CLOUDACTIONRESPONSEBEAN_H

#include <string>
#include <map>
#include "VoiceBean.h"
#include "MediaBean.h"
#include "ActionBean.h"
#include "ResponseBean.h"
#include "SessionBean.h"


using namespace std;

namespace CloudAppClient{

    class CloudActionResponseBean {

    private:
        string appId;
        string version;
        SessionBean session;
        ResponseBean response;

    public:

        CloudActionResponseBean();

        CloudActionResponseBean(const string &appId, const string &version, const SessionBean &session,
                                const ResponseBean &response);

        virtual ~CloudActionResponseBean();

        bool operator==(const CloudActionResponseBean &rhs) const;

        bool operator!=(const CloudActionResponseBean &rhs) const;

        CloudActionResponseBean& operator=(const CloudActionResponseBean &carb);

        const string &getAppId() const;

        void setAppId(const string &appId);

        const string &getVersion() const;

        void setVersion(const string &version);

        const SessionBean &getSession() const;

        void setSession(const SessionBean &session);

        const ResponseBean &getResponse() const;

        void setResponse(const ResponseBean &response);


    };

}

#endif
