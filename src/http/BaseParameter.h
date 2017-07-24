//
// Created by Fan Feng on 2017/7/21.
//
#include "../util/LinkedHashMap.h"

using std::string;
using std::map;

namespace CloudAppClient {

    class BaseParameter {

    private:
        static const string PARAM_KEY_KEY = "key";
        static const string PARAM_KEY_DEVICE_TYPE_ID = "device_type_id";
        static const string PARAM_KEY_DEVICE_ID = "device_id";
        static const string PARAM_KEY_SERVICE = "service";
        static const string PARAM_VALUE_SERVICE = "rest";
        static const string PARAM_KEY_VERSION = "version";
        static const string PARAM_KEY_TIME = "time";
        static const string PARAM_KEY_SIGN = "sign";
        static const string PARAM_KEY_SECRET = "secret";
        LinkedHashMap linkedHashMap;

    public:
        BaseParameter();
        virtual ~BaseParameter();

        virtual const string &getAuthorization() = 0;

    private:
        const map<string,string> &generateParams(){

        }
        const putUnEmptyParam(const string &key, const string &value);

    };

}
