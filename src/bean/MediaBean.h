//
// Created by Fan Feng on 2017/7/17.
//

#include <string>
#include <tkDecls.h>
#include "../util/TextUtil.h"
#include "BaseActionBean.h"

using std::string;

namespace cloudappclient {
    class MediaBean : BaseActionBean {
    private:
        MediaItemBean mediaItemBean;

    public:
        const MediaItemBean &getItem() const {
            return mediaItemBean;
        }

        void setItem(const MediaItemBean &item) {
            MediaBean::mediaItemBean = item;
        }

    private:

        bool canPlay() {
            return &mediaItemBean != nullptr && !TextUtil::isEmpty(mediaItemBean.getUrl());
        }

    };

    class MediaItemBean {

    private:
        string token;
        string type;
        string url;
        int offsetInMilliseconds;

    public:
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
}