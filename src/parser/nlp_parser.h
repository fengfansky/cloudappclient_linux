//
// Created by Fan Feng on 2017/7/28.
//
#pragma once

#include <string>
#include "../bean/NLPBean.h"

namespace CloudAppClient {

    class nlp_parser {

    public:

        nlp_parser() {}

        virtual ~nlp_parser() {}

        static bool string_to_nlp(const std::string &nlp_string, NLPBean &nlp_bean);

    };

}
