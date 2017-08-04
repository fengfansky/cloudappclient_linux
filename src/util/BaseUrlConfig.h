//
// Created by Fan Feng on 2017/7/22.
//
#pragma once

#include "../action/BaseAction.h"

using std::string;

namespace CloudAppClient {

    class BaseUrlConfig {
    public:
        static const string BASE_URL = "https://apigwrest.open.rokid.com";
        static const string BASE_URL_TEST = "https://apigwrest-dev.open.rokid.com";
        static bool isDev = true;
        static const string PATH = "/v1/skill/dispatch/sendEvent";

    public:
        static const string &getUrl() {
            string baseUrl;
            if (isDev) {
                baseUrl = strcmp(BASE_URL_TEST, PATH);
            } else {
                baseUrl = strcmp(BASE_URL, PATH);
            }
            return baseUrl;
        }
    };
}
