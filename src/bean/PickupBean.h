//
// Created by Fan Feng on 2017/8/7.
//
#ifndef CLOUDAPPCLIENT_PICKUPBEAN_H
#define CLOUDAPPCLIENT_PICKUPBEAN_H

namespace CloudAppClient{

class PickupBean {
private:
    bool enable;
    int durationInMilliseconds;

public:
    PickupBean();
    virtual ~PickupBean();

    bool operator==(const PickupBean &rhs) const;
    bool operator!=(const PickupBean &rhs) const;
    PickupBean &operator=(const PickupBean &rhs);

    bool isEnable() const;
    void setEnable(bool enable);
    int getDurationInMilliseconds() const;
    void setDurationInMilliseconds(int durationInMilliseconds);
};

}

#endif
