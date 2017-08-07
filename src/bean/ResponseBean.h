//
// Created by Fan Feng on 2017/7/29.
//
#pragma once

#include "ActionBean.h"

namespace CloudAppClient {

/*    template<class T>
    class CardBean {

    private:
        string version;
        string type;
        T model;

    public:

        CardBean(const string &version, const string &type, T model) : version(version), type(type),
                                                                       model(model) {}

        virtual ~CardBean() {

        }

        bool operator==(const CardBean &rhs) const {
            return version == rhs.version &&
                   type == rhs.type &&
                   model == rhs.model;
        }

        bool operator!=(const CardBean &rhs) const {
            return !(rhs == *this);
        }

        CardBean& operator=(const CardBean &cb) {
            version = cb.version;
            type = cb.type;
            model = cb.model;
            return *this;
        }

        const string &getVersion() const {
            return version;
        }

        void setVersion(const string &version) {
            CardBean::version = version;
        }

        const string &getType() const {
            return type;
        }

        void setType(const string &type) {
            CardBean::type = type;
        }

        T getModel() const {
            return model;
        }

        void setModel(T model) {
            CardBean::model(model);
        }
    };*/

    class ResponseBean {

    public:
        const string TYPE_INTENT = "INTENT";
        const string TYPE_EVENT = "EVENT";

    private:
        string respId;
        /**
         * ONLY type INTENT and EVENT are available currently
         */
        string resType;

//        CardBean<T> card;

        ActionBean action;

    public:

        ResponseBean() {}

        ResponseBean(const string &respId, const string &resType, const ActionBean &action)
                : respId(respId), resType(resType), action(action) {}

        virtual ~ResponseBean() {

        }

        bool operator==(const ResponseBean &rhs) const {
            return respId == rhs.respId &&
                   resType == rhs.resType &&
                   action == rhs.action;
        }

        bool operator!=(const ResponseBean &rhs) const {
            return !(rhs == *this);
        }

        ResponseBean& operator=(const ResponseBean &rhs){
            respId = rhs.respId;
            resType = rhs.resType;
            action = rhs.action;
            return *this;
        }

        const string &getRespId() const {
            return respId;
        }

        void setRespId(const string &respId) {
            ResponseBean::respId = respId;
        }

        const string &getResType() const {
            return resType;
        }

        void setResType(const string &resType) {
            ResponseBean::resType = resType;
        }

  /*      const CardBean<T> &getCard() const {
            return card;
        }

        void setCard(const CardBean<T> &card) {
            ResponseBean::card = card;
        }
*/
        const ActionBean &getAction() const {
            return action;
        }

        void setAction(const ActionBean &action) {
            ResponseBean::action = action;
        }

    };

}
