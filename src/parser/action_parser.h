//
// Created by Fan Feng on 2017/7/28.
//
#pragma once

#include <string>
#include "../bean/CloudActionResponseBean.h"

namespace CloudAppClient {

    class action_parser {

    public:

        action_parser() {}

        virtual ~action_parser() {}

        static const char* TAG = "action_parser";

        static bool string_to_action(const std::string &action_str, CloudActionResponseBean& action_bean);

    };

}
