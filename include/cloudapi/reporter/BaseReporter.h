//
// Created by Fan Feng on 2017/7/22.
//
#ifndef CLOUDAPPCLIENT_BASEREPORTER_H
#define CLOUDAPPCLIENT_BASEREPORTER_H
#include <string>
#include "../http/BaseUrlConfig.h"


using namespace std;

namespace CloudAppClient {

class BaseReporter {
public:
    BaseReporter();
    BaseReporter(string appID, string event);
    BaseReporter(string appID, string event, string extra);
    virtual ~BaseReporter();

    string report();

private:
    string mAppID;
    string mEvent;
    string mExtra;
};

}

#endif
