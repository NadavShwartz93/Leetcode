#ifndef ROMAN_TO_INTEGER_
#define ROMAN_TO_INTEGER_
#include<string>
#include <map>

namespace roman_to_integer {

    class Roman_class
    {
        std::map<char, int> Roman_map;
    public:
        Roman_class();
        bool romanToInt_Test();
    private:
        int romanToInt(std::string s);
    };

};

#endif // !ROMAN_TO_INTEGER_
