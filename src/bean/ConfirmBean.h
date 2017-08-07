//
// Created by Fan Feng on 2017/8/7.
//

#pragma once

#include <vector>
#include "../action/BaseAction.h"

namespace CloudAppClient {

    class ConfirmBean {
    private:
        std::string confirmIntent;
        std::string confirmSlot;
        std::vector<string> optionWords;

    public:
        ConfirmBean() {}

        virtual ~ConfirmBean() {

        }

        bool operator==(const ConfirmBean &rhs) const {
            return confirmIntent == rhs.confirmIntent &&
                   confirmSlot == rhs.confirmSlot &&
                   optionWords == rhs.optionWords;
        }

        bool operator!=(const ConfirmBean &rhs) const {
            return !(rhs == *this);
        }

        ConfirmBean&operator=(const ConfirmBean &rhs){
            confirmIntent = rhs.confirmIntent;
            confirmSlot = rhs.confirmSlot;
            optionWords = rhs.optionWords;
            return *this;
        }

        const string &getConfirmIntent() const {
            return confirmIntent;
        }

        void setConfirmIntent(const string &confirmIntent) {
            ConfirmBean::confirmIntent = confirmIntent;
        }

        const string &getConfirmSlot() const {
            return confirmSlot;
        }

        void setConfirmSlot(const string &confirmSlot) {
            ConfirmBean::confirmSlot = confirmSlot;
        }

        const std::vector<string> &getOptionWords() const {
            return optionWords;
        }

        void setOptionWords(const std::vector<string> &optionWords) {
            ConfirmBean::optionWords = optionWords;
        }

    };
}
