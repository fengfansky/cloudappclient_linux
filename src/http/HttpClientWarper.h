//
// Created by Fan Feng on 2017/7/26.
//

#include <boost/network/protocol/http/client.hpp>
#include <google/protobuf/message_lite.h>
#include <string>
#include "BaseParameter.h"
#include "../proto/SendEvent.pb.h"
#include "../util/LogUtil.h"

using namespace boost::network;

namespace CloudAppClient {

    class HttpClientWarper {

    private:
        static const int CONNECTION_TIME_OUT = 3;
        static const int READ_TIME_OUT = 3;
        static const int WRITE_TIME_OUT = 3;

        static const std::string CONTENT_TYPE = "application/octet-stream";
    private:

        static HttpClientWarper *instance = nullptr;

        HttpClientWarper::AppStateMachine() {

        }

        HttpClientWarper::~AppStateMachine() {
            delete instance;
        }
    public:

        static HttpClientWarper *getInstance() {
            if (instance == nullptr) {
                instance = new HttpClientWarper();
            }
            return instance;
        }
        const static send_event_request(const std::string &url, const BaseParameter &parameter, const proto::SendEventRequest send_event_request){

            http::client client;
            http::client::request client_request;
            http::client::response client_response;
            std::ostream *ostream;

            client_request << header("Accept", "text/plain");
            client_request << header("Accept-Charset", "utf-8");
            client_request << header("Cache-Control", "no-cache");
            send_event_request.SerializeToOstream(ostream);
            client_request.uri(url);
            client_response = client.post(client_request);
            LogUtil::log("response : " + body(client_response.));
        }


    };

}
