//
// Created by Fan Feng on 2017/7/29.
//
#ifndef CLOUDAPPCLIENT_RESPONSEBEAN_H
#define CLOUDAPPCLIENT_RESPONSEBEAN_H

#include "ActionBean.h"


namespace CloudAppClient{

class ResponseBean {
private:
    string respId;
    /**
     * ONLY type INTENT and EVENT are available currently
     */
    string resType;
//  CardBean<T> card;
    ActionBean action;

public:
    const string TYPE_INTENT = "INTENT";
    const string TYPE_EVENT = "EVENT";

    ResponseBean();
    ResponseBean(const string &respId, const string &resType, const ActionBean &action);
    virtual ~ResponseBean();
    bool operator==(const ResponseBean &rhs) const;
    bool operator!=(const ResponseBean &rhs) const;
    ResponseBean& operator=(const ResponseBean &rhs);
    const string &getRespId() const;
    void setRespId(const string &respId);
    const string &getResType() const;
    void setResType(const string &resType);
    const ActionBean &getAction() const;
    void setAction(const ActionBean &action);
};

}

#endif
