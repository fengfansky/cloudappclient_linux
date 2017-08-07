//
// Created by Fan Feng on 2017/8/7.
//
#pragma once

namespace CloudAppClient {

    class PickupBean {
    private:
        bool enable;
        int durationInMilliseconds;

    public:
        PickupBean() {}

        virtual ~PickupBean() {

        }

        bool operator==(const PickupBean &rhs) const {
            return enable == rhs.enable &&
                   durationInMilliseconds == rhs.durationInMilliseconds;
        }

        bool operator!=(const PickupBean &rhs) const {
            return !(rhs == *this);
        }

        PickupBean &operator=(const PickupBean &rhs) {
            enable = rhs.enable;
            durationInMilliseconds = rhs.durationInMilliseconds;
            return *this;
        }

        bool isEnable() const {
            return enable;
        }

        void setEnable(bool enable) {
            PickupBean::enable = enable;
        }

        int getDurationInMilliseconds() const {
            return durationInMilliseconds;
        }

        void setDurationInMilliseconds(int durationInMilliseconds) {
            PickupBean::durationInMilliseconds = durationInMilliseconds;
        }
    };
}
