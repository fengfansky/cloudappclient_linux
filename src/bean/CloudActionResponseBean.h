//
// Created by Fan Feng on 2017/7/19.
//
#pragma once

#include <string>
#include <map>
#include "VoiceBean.h"
#include "MediaBean.h"
#include "ActionBean.h"
#include "ResponseBean.h"
#include "SessionBean.h"

namespace CloudAppClient {

    class CloudActionResponseBean {

    private:
        string appId;
        string version;
        SessionBean session;
        ResponseBean response;

    public:

        CloudActionResponseBean() {

        }

        CloudActionResponseBean(const string &appId, const string &version, const SessionBean &session,
                                const ResponseBean &response) : appId(appId), version(version), session(session),
                                                                response(response) {}

        virtual ~CloudActionResponseBean() {

        }

        bool operator==(const CloudActionResponseBean &rhs) const {
            return appId == rhs.appId &&
                   version == rhs.version &&
                   session == rhs.session &&
                   response == rhs.response;
        }

        bool operator!=(const CloudActionResponseBean &rhs) const {
            return !(rhs == *this);
        }

        CloudActionResponseBean& operator=(const CloudActionResponseBean &carb){
            appId = carb.appId;
            version = carb.version;
            session = carb.session;
            response = carb.response;
            return *this;
        }

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

}
