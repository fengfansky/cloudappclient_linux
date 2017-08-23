//
// Created by Fan Feng on 2017/7/22.
//
#include <sstream>
#include <map>
#include "../util/MD5Utils.h"
#include "BaseUrlConfig.h"


using std::string;
using rokid::log::Log;

namespace CloudAppClient {

    const char *BaseUrlConfig::TAG = "BaseUrlConfig";
    const char *BaseUrlConfig::BASE_HTTP = "https://";
    const char *BaseUrlConfig::DEFAULT_HOST = "apigwrest.open.rokid.com";
    const char *BaseUrlConfig::SEND_EVENT_PATH = "/v1/skill/dispatch/sendEvent";

    const char *BaseUrlConfig::KEY_HOST = "event_req_host";

    const char *BaseUrlConfig::PARAM_KEY_KEY = "key";
    const char *BaseUrlConfig::PARAM_KEY_DEVICE_TYPE_ID = "device_type_id";
    const char *BaseUrlConfig::PARAM_KEY_DEVICE_ID = "device_id";
    const char *BaseUrlConfig::PARAM_KEY_SERVICE = "service";
    const char *BaseUrlConfig::PARAM_VALUE_SERVICE = "rest";
    const char *BaseUrlConfig::PARAM_KEY_VERSION = "version";
    const char *BaseUrlConfig::PARAM_KEY_TIME = "time";
    const char *BaseUrlConfig::PARAM_KEY_SIGN = "sign";
    const char *BaseUrlConfig::PARAM_KEY_SECRET = "secret";

    string mHost;

    std::map<string, string> deviceMap;
    std::vector<std::pair<string, string>> params;

    BaseUrlConfig::BaseUrlConfig() {

    }

    BaseUrlConfig::~BaseUrlConfig() {

    }

    void BaseUrlConfig::putParams(const std::string key, const std::string value) {
        if (key.empty()) {
            Log::d(TAG, "param key invalid !");
            return;
        }

        if (value.empty()) {
            Log::d(TAG, "param value invalid !");
            return;
        }

        auto param = std::make_pair(key, value);

        params.push_back(param);
    }

    //TODO get device info
    void BaseUrlConfig::initDeviceInfo() {

        /*   IBinder runtimeBinder;
           try {
               Class< ?> clazz = Class.forName("android.os.ServiceManager");
               Method
               method = clazz.getMethod("getService", String.
               class);
               runtimeBinder = (IBinder) method.invoke(null, "runtime_java");
           } catch (Exception e) {
               e.printStackTrace();
               return;
           }

           if (runtimeBinder == null) {
               Logger.d(" runtime binder is null ");
               return;
           }
           rokid.os.IRuntimeService runtime = rokid.os.IRuntimeService.Stub.asInterface(runtimeBinder);
           try {
               deviceMap = runtime.getPlatformAccountInfo();
           } catch (Exception e) {
               e.printStackTrace();
           }
           if (deviceMap == null || deviceMap.isEmpty()) {
               Logger.d(" deviceMap is null ");
               return;
           }

           Logger.d(" deviceMap is " + deviceMap.toString());*/

        mHost = deviceMap[KEY_HOST];

    }

    const string& BaseUrlConfig::getUrl() {

        if (mHost.empty()) {
            mHost = DEFAULT_HOST;
        }

        string path = BASE_HTTP + mHost + SEND_EVENT_PATH;

        return path;
    }



    const string& BaseUrlConfig::getAuthorization() {

//        if (deviceMap.empty()) {
//            Log::d(TAG, " deviceMap is null ");
//            return nullptr;
//        }
//
//        putParams(PARAM_KEY_KEY, deviceMap[PARAM_KEY_KEY]);
//        putParams(PARAM_KEY_DEVICE_TYPE_ID, deviceMap[PARAM_KEY_DEVICE_TYPE_ID]);
//        putParams(PARAM_KEY_DEVICE_ID, deviceMap[PARAM_KEY_DEVICE_ID]);
//
//        putParams(PARAM_KEY_SERVICE, PARAM_VALUE_SERVICE);
//        putParams(PARAM_KEY_VERSION, deviceMap["api_version"]);
//        //获取的时间戳秒转换成毫秒
//        putParams(PARAM_KEY_TIME, "" + time(NULL)*1000);
//        string sign;
//        MD5Utils::generateMD5(sign,params, deviceMap[PARAM_KEY_SECRET]);
//        putParams(PARAM_KEY_SIGN, sign);

        string sign;
        putParams(PARAM_KEY_KEY, "9C4D6BEB6448468FB73E75A2C33E6ADE");
        putParams(PARAM_KEY_DEVICE_TYPE_ID, "98EA4B548AEB4A329D21615B9ED060E5");
        putParams(PARAM_KEY_DEVICE_ID, "02010217020001F4");

        putParams(PARAM_KEY_SERVICE, PARAM_VALUE_SERVICE);
        putParams(PARAM_KEY_VERSION, "1");
        putParams(PARAM_KEY_TIME, "1502952999092");

        MD5Utils::generateMD5(sign ,params, "32F7A304CE8740C5BD61F587F7DD7B88");
        putParams(PARAM_KEY_SIGN, sign);

        if (params.empty()) {
            Log::d(TAG, "param is null !");
            return nullptr;
        }

        string authorization;
        for (auto it = params.begin(); it != params.end(); ++it) {
            if (it < params.end() - 1){
                authorization.append(it->first).append("=").append(it->second).append(";");
            } else if (it == params.end() - 1){
                authorization.append(it->first).append("=").append(it->second);
            }
        }

        Log::d(TAG, (" authorization: " + authorization).c_str());
        return authorization;
    }

}
