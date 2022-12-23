#ifndef STRING_UTILS
#define STRING_UTILS

#include <string>
#include <map>

class StringUtilities {
public:

    static std::pair<int, int> findTwoInts(std::string str);


    static std::map<std::string, std::string> stringToMap(const std::string& slon);

    static bool isNumber(std::string s);
    static bool isDigit(char sym);

    static int hash(const std::string& str, int x = 101, int p = 15485863);
};


#endif