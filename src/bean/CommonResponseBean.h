//
// Created by Fan Feng on 2017/7/19.
//

#include <iostream>
#include <map>
#include "CloudActionResponseBean.h"
#include "NLPBean.h"

using std::string;
using map_string = std::map<string, string>;

namespace CloudAppClient {
    class CommonResponseBean {
    private:
        /**
         * corresponding asr result for current response
         */
        string asr;

        /**
         * corresponding nlp result for current response
         */
        NLPBean nlp;

        /**
         * corresponding CloudActionResponse for current response
         */
        CloudActionResponseBean action;

    public:
        const string &getAsr() const {
            return asr;
        }

        void setAsr(const string &asr) {
            CommonResponseBean::asr = asr;
        }

        const NLPBean &getNlp() const {
            return nlp;
        }

        void setNlp(const NLPBean &nlp) {
            CommonResponseBean::nlp = nlp;
        }

        const CloudActionResponseBean &getAction() const {
            return action;
        }

        void setAction(const CloudActionResponseBean &action) {
            CommonResponseBean::action = action;
        }
    };
}