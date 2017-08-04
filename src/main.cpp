#include "json/json.h"
#include "util/rlog.h"
#include "bean/NLPBean.h"
#include "parser/nlp_parser.h"
#include "parser/action_parser.h"

using std::string;
using json = nlohmann::json;

int main(void) {

    const std::string &nlp_str = "{  \n"
            "   \"nlp\":{  \n"
            "      \"appId\":\"R70897F43CBC4BF2A735166AED3FEE64\",\n"
            "      \"cloud\":true,\n"
            "      \"intent\":\"play_random\",\n"
            "      \"pattern\":\"$iwant?$play$one?$great?$de?$keyword$okma?$\",\n"
            "      \"confirm\":\"are you sure ?\",\n"
            "      \"posStart\":1234,\n"
            "      \"slots\":{  \n"
            "\n"
            "      }\n"
            "   }\n"
            "}";

    const std::string &action_str = "  \"action\":  \n"
            "      \"appId\":\"R70897F43CBC4BF2A735166AED3FEE64\",\n"
            "      \"response\":{  \n"
            "         \"action\":{  \n"
            "            \"form\":\"cut\",\n"
            "            \"media\":{  \n"
            "               \"action\":\"PLAY\",\n"
            "               \"item\":{  \n"
            "                  \"offsetInMilliseconds\":40,\n"
            "                  \"type\":\"AUDIO\",\n"
            "\t\t  \"url\":\"https://music-proxy.rokid-inc.com/content/01/996/1996340-MP3-320K-FTD.mp3?sign=AOOe8iGUknH60JrIK/L3rFL8VyRhPTEwMDM5ODY3Jms9QUtJRE1Fdm53SXdwNFlqUlU1NHhxd3VLQlRYMExOOWdJVFNRJmU9MTUwMTQwMTY2MCZ0PTE1MDEyMjg4NjAmcj0xNTk3NjkyNzIyJmY9L2NvbnRlbnQvMDEvOTk2LzE5OTYzNDAtTVAzLTMyMEstRlRELm1wMyZiPXVsdGltYXRl&transDeliveryCode=RK@19573446@1501228860@S\"\n"
            "               }\n"
            "            },\n"
            "            \"shouldEndSession\":false,\n"
            "            \"type\":\"NORMAL\",\n"
            "            \"version\":\"2.0.0\",\n"
            "            \"voice\":{  \n"
            "               \"action\":\"PLAY\",\n"
            "               \"item\":{  \n"
            "                  \"tts\":\"为你播放发如雪\"\n"
            "               }\n"
            "            }\n"
            "         },\n"
            "         \"resType\":\"INTENT\",\n"
            "         \"respId\":\"EBA7F77685744C71B7A83050D9E417B4\"\n"
            "      },\n"
            "      \"startWithActiveWord\":false,\n"
            "      \"version\":\"2.0.0\"\n"
            "   }\n"
            "}";

    CloudAppClient::NLPBean nlpBean;
    CloudAppClient::CloudActionResponseBean cloudActionResponseBean;


    CloudAppClient::nlp_parser::string_to_nlp(nlp_str, nlpBean);

    CloudAppClient::action_parser::string_to_action(action_str, cloudActionResponseBean);


//    rokid::log::Log::d("test_json", nlp_str.c_str());
    //2. test network


    return 0;
}