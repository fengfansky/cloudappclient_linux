//
// Created by Fan Feng on 2017/7/19.
//
#ifndef CLOUDAPPCLIENT_ACTIONBEAN_H
#define CLOUDAPPCLIENT_ACTIONBEAN_H

#include <string>
#include "ConfirmBean.h"
#include "PickupBean.h"
#include "VoiceBean.h"
#include "MediaBean.h"

using namespace std;

namespace CloudAppClient {
    class ActionBean {

    private:
        /**
        * 表明 action 协议版本，当前版本为: 2.0.0.
        */
        string mVersion;
        /**
         * 前action的类型：NORMAL 或 EXIT。 当 type 是 NORMAL 时，voice 和 media 会同时执行；当 type      * 是 EXIT 时，action会立即退出，并且在这种情况下，voice 和 media 将会被会被忽略
         */
        string type;
        /**
         * 表明当此次返回的action执行完后 CloudAppClient 是否要退出，同时，当 shouldEndSession 为 true     * 时，parser 将会忽略 EventRequests，即在action执行过程中不会产生 EventRequest。
         */
        bool shouldEndSession = true;
        /**
        * 当前action的展现形式：scene、cut、service。scene的action会在被打断后压栈，cut的action会在被打    * 断后直接结束，service会在后台执行，但没有任何界面。该字段在技能创建时被确定，无法由cloud app更改。
        */
        string form;
        VoiceBean voice;
        MediaBean mMedia;
        ConfirmBean mConfirm;
        PickupBean mPickup;

    public:
        ActionBean();
        virtual ~ActionBean();

        static constexpr const char* PROTOCOL_VERSION = "2.0.0";
        /**
* When type is NORMAL , voice , display and media will be executed concurrently
*/
        static constexpr const char* TYPE_NORMAL = "NORMAL";
        /**
         * When type is EXIT , the action will be shut down immediately.
         * In this case, voice , display and media will be ignored.
         */
        static constexpr const char* TYPE_EXIT = "EXIT";

        static constexpr const char* FORM_SCENE = "scene";
        static constexpr const char* FORM_CUT = "cut";
        static constexpr const char* FORM_SERVICE = "service";

        bool operator==(const ActionBean &rhs) const;
        bool operator!=(const ActionBean &rhs) const;
        ActionBean&operator=(const ActionBean &rhs);

        const string& getVersion();
        void setVersion(const string& version);
        const string& getType();
        void setType(const string& type);
        bool isShouldEndSession();
        void setShouldEndSession(bool shouldEndSession);
        const string& getForm();
        void setForm(const string& form);
        const VoiceBean &getVoice();
        void setVoice(const VoiceBean& voice);
        const MediaBean& getMedia();
        const ConfirmBean& getConfirm();
        void setConfirm(const ConfirmBean& confirm);
        const PickupBean& getPickup();
        void setPickup(const PickupBean& pickup);
        void setMedia(const MediaBean& media);

    };
}

#endif
