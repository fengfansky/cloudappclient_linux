//
// Created by Fan Feng on 2017/7/17.
//
#pragma once

#include <string>
#include "BaseActionBean.h"

using std::string;

namespace CloudAppClient {

    class MediaItemBean {

    private:
        string token;
        string type;
        string url;
        int offsetInMilliseconds;

    public:

        MediaItemBean() : offsetInMilliseconds(0) {}

        MediaItemBean(const string &token, const string &type, const string &url, int offsetInMilliseconds) : token(
                token), type(type), url(url), offsetInMilliseconds(offsetInMilliseconds) {}

        virtual ~MediaItemBean() {

        }

        bool operator==(const MediaItemBean &rhs) const {
            return token == rhs.token &&
                   type == rhs.type &&
                   url == rhs.url &&
                   offsetInMilliseconds == rhs.offsetInMilliseconds;
        }

        bool operator!=(const MediaItemBean &rhs) const {
            return !(rhs == *this);
        }

        MediaItemBean& operator=(const MediaItemBean &mib){
            token = mib.token;
            type = mib.type;
            url = mib.type;
            offsetInMilliseconds = mib.offsetInMilliseconds;
            return *this;
        }

        const string &getToken() const {
            return token;
        }

        void setToken(const string &token) {
            MediaItemBean::token = token;
        }

        const string &getType() const {
            return type;
        }

        void setType(const string &type) {
            MediaItemBean::type = type;
        }

        const string &getUrl() const {
            return url;
        }

        void setUrl(const string &url) {
            MediaItemBean::url = url;
        }

        int getOffsetInMilliseconds() const {
            return offsetInMilliseconds;
        }

        void setOffsetInMilliseconds(int offsetInMilliseconds) {
            MediaItemBean::offsetInMilliseconds = offsetInMilliseconds;
        }
    };

    class MediaBean : public BaseActionBean {

    private:
        MediaItemBean mediaItemBean;

    public:
        MediaBean() {}

        MediaBean(const string &action) : BaseActionBean(action) {}

        MediaBean(const string &action, const MediaItemBean &mediaItemBean)
                : BaseActionBean(action), mediaItemBean(mediaItemBean) {

        }

        virtual ~MediaBean() {

        }

        bool operator==(const MediaBean &rhs) const {
            return static_cast<const MediaBean &>(*this) == static_cast<const MediaBean &>(rhs) &&
                   mediaItemBean == rhs.mediaItemBean;
        }

        bool operator!=(const MediaBean &rhs) const {
            return !(rhs == *this);
        }

        MediaBean& operator=(const MediaBean &mb){
            mediaItemBean = mb.mediaItemBean;
            return *this;
        }


        const MediaItemBean &getItem() const {
            return mediaItemBean;
        }

        void setItem(const MediaItemBean &item) {
            MediaBean::mediaItemBean = item;
        }

    private:
        bool canPlay() {
            return !mediaItemBean.getUrl().empty();
        }

    };

}