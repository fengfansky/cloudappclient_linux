//
// Created by Fan Feng on 2017/7/25.
//
#ifndef CLOUDAPPCLIENT_CUTAPPSTATE_H
#define CLOUDAPPCLIENT_CUTAPPSTATE_H

#include "BaseAppState.h"

using namespace std;

namespace CloudAppClient {

class CutAppState : BaseAppState {
public:
    CutAppState();
    ~CutAppState();
    void app_paused();
    void app_resumed();
    void app_destroy();
//    shared_ptr<string> get_app_type();
};

}
#endif
