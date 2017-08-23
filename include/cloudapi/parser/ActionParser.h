//
// Created by Fan Feng on 2017/7/28.
//
#ifndef CLOUDAPPCLIENT_ACTIONPARSER_H
#define CLOUDAPPCLIENT_ACTIONPARSER_H

#include <string>
#include "../bean/CloudActionResponseBean.h"

using namespace CloudAppClient;

namespace CloudAppClient {

    class ActionParser {

    public:

        ActionParser() {}

        ~ActionParser() {}

        static bool strToAction(const std::string &action_str, CloudActionResponseBean &action_bean);

    };

}
#endif