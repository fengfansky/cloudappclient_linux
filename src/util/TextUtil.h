//
// Created by Fan Feng on 2017/7/14.
//

#include <string>

class TextUtil {
public:
    static bool isEmpty(std::string str) {

        if (str == nullptr || strcmp(str, "")) {
            return true;
        }

        return false;
    }
};