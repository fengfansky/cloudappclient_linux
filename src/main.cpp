#include "json/json.h"
//#include "parser/nlp_parser.h"
#include "util/rlog.h"

using std::string;
using json = nlohmann::json;

int main(void) {

        const string nlp_str = "{  \\n\"\n"
                "                                                    \"   \\\"nlp\\\":{  \\n\"\n"
                "                                                    \"      \\\"appId\\\":\\\"R4AB842832E84BBD8B2DD6537DAFF790\\\",\\n\"\n"
                "                                                    \"      \\\"cloud\\\":true,\\n\"\n"
                "                                                    \"      \\\"intent\\\":\\\"playnews\\\",\\n\"\n"
                "                                                    \"      \\\"pattern\\\":\\\"($iwant|$can?$forMe|$can)?$play$newsmode?的?$newstype?类?$keyword\\\",\\n\"\n"
                "                                                    \"      \\\"slots\\\":{  \\n\"\n"
                "                                                    \"         \\\"keyword\\\":\\\"新闻\\\"\\n\"\n"
                "                                                    \"      }\\n\"\n"
                "                                                    \"   }\\n\"\n"
                "                                                    \"}";

//        CloudAppClient::NLPBean nlpBean;
//
//        CloudAppClient::nlp_parser::string_to_nlp(nlp_str, nlpBean);


       rokid::log::Log::d("test_json",nlp_str.c_str());

    //2. test network


    return 0;
}