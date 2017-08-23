//
// Created by Fan Feng on 2017/7/28.
//
#ifndef CLOUDAPPCLIENT_NLPPARSER_H
#define CLOUDAPPCLIENT_NLPPARSER_H

#include <string>
#include "../bean/NLPBean.h"

using namespace CloudAppClient;

namespace CloudAppClient {

    class NLPParser {

    public:

        NLPParser() {}

        ~NLPParser() {}

        const static char* TAG;

        static bool string_to_nlp(const std::string &nlp_string, NLPBean &nlp_bean);

    };

}
#endif