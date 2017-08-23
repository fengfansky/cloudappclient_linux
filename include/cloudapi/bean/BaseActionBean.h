//
// Created by Fan Feng on 2017/7/14.
//
#ifndef CLOUDAPPCLIENT_BASEACTIONBEAN_H
#define CLOUDAPPCLIENT_BASEACTIONBEAN_H

#include <string>

using namespace std;

namespace CloudAppClient{
class BaseActionBean {

public:
    static constexpr const char *ACTION_PLAY = "PLAY";
    static constexpr const char *ACTION_PAUSE = "PAUSE";
    static constexpr const char *ACTION_RESUME = "RESUME";
    static constexpr const char *ACTION_STOP = "STOP";
    static constexpr const char *ACTION_FORWARD = "FORWARD";
    static constexpr const char *ACTION_BACKWARD = "BACKWARD";

    string action;

    BaseActionBean();
    BaseActionBean(const string &action);
    virtual ~BaseActionBean();
    bool operator==(const BaseActionBean &rhs) const;
    bool operator!=(const BaseActionBean &rhs) const;
    BaseActionBean &operator=(const BaseActionBean &rhs);
    void setAction(const string &action);
    const string &getAction();
    bool isValid();
    bool canPlay();

};
}

#endif
