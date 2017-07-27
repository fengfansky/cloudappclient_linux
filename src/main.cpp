#include <iostream>
#include <boost/network/protocol/http/client.hpp>
#include "../include/json.hpp"
#include "proto/SendEvent.pb.h"

using std::string;
using json = nlohmann::json;
using namespace boost::network;

int main(void) {


     // 1. Parse a JSON string into DOM.
//       auto jsonDom = json::parse("{  \n"
//                                                    "   \"nlp\":{  \n"
//                                                    "      \"appId\":\"R4AB842832E84BBD8B2DD6537DAFF790\",\n"
//                                                    "      \"cloud\":true,\n"
//                                                    "      \"intent\":\"playnews\",\n"
//                                                    "      \"pattern\":\"($iwant|$can?$forMe|$can)?$play$newsmode?的?$newstype?类?$keyword\",\n"
//                                                    "      \"slots\":{  \n"
//                                                    "         \"keyword\":\"新闻\"\n"
//                                                    "      }\n"
//                                                    "   }\n"
//                                                    "}");
//
//
//       LogUtil::log(jsonDom["nlp"]["appId"].get<string>());

    return 0;
}