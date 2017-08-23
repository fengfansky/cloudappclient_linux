//
// Created by Fan Feng on 2017/7/17.
//
#ifndef CLOUDAPPCLIENT_MEDIABASE_H
#define CLOUDAPPCLIENT_MEDIABASE_H

#include <string>
#include "BaseActionBean.h"

using namespace std;

namespace CloudAppClient{

    class MediaItemBean {

    private:
        string token;
        string type;
        string url;
        int offsetInMilliseconds;

    public:

        MediaItemBean();
        MediaItemBean(const string &token, const string &type, const string &url, int offsetInMilliseconds);
        virtual ~MediaItemBean();
        bool operator==(const MediaItemBean &rhs) const;
        bool operator!=(const MediaItemBean &rhs) const;
        MediaItemBean& operator=(const MediaItemBean &mib);

        const string &getToken() const;

        void setToken(const string &token);

        const string &getType() const;

        void setType(const string &type);

        const string &getUrl() const;

        void setURL(const string &url);

        int getOffsetInMilliseconds() const;

        void setOffsetInMilliseconds(int offsetInMilliseconds);
    };

    class MediaBean : public BaseActionBean {

    private:
        MediaItemBean mediaItemBean;
        bool canPlay();

    public:
        MediaBean();
        MediaBean(const string &action);
        MediaBean(const string &action, const MediaItemBean &mediaItemBean);

        virtual ~MediaBean();
        bool operator==(const MediaBean &rhs) const;
        bool operator!=(const MediaBean &rhs) const;
        MediaBean& operator=(const MediaBean &mb);
        const MediaItemBean &getItem() const;
        void setItem(const MediaItemBean &item);

    };

}

#endif
