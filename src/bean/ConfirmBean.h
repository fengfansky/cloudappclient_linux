//
// Created by Fan Feng on 2017/8/7.
//

#ifndef CLOUDAPPCLIENT_CONFIRMBEAN_H
#define CLOUDAPPCLIENT_CONFIRMBEAN_H
#include <vector>
#include "../action/BaseAction.h"

namespace CloudAppClient{

    class ConfirmBean {
    private:
        std::string confirmIntent;
        std::string confirmSlot;
        std::vector<string> optionWords;

    public:
        ConfirmBean();
        virtual ~ConfirmBean();
        bool operator==(const ConfirmBean &rhs) const;
        bool operator!=(const ConfirmBean &rhs) const;
        ConfirmBean&operator=(const ConfirmBean &rhs);
        const string &getConfirmIntent() const;
        void setConfirmIntent(const string &confirmIntent);
        const string &getConfirmSlot() const;
        void setConfirmSlot(const string &confirmSlot);
        const std::vector<string> &getOptionWords() const;
        void setOptionWords(const std::vector<string> &optionWords);

    };
}

#endif
