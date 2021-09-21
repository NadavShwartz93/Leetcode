#include<string>
#include<iostream>

/*
https://leetcode.com/problems/implement-strstr/
*/
namespace strStr {

    int strStr(const std::string& haystack, const std::string& needle) {

        //The case that needle is empty.
        if (needle.length() == 0)
            return 0;

        //The case that haystack is empty.
        if (haystack.empty())
            return -1;

        auto ch1 = haystack.begin();
        auto ch2 = needle.begin();

        int res = -1;
        bool in_sequence = false;

        for (int i = 0; i < haystack.length(); i++)
        {
            if (not in_sequence && *ch1 == *ch2) {
                ++ch1;
                ++ch2;

                res = i;
                in_sequence = true;
                if (ch2 == needle.end())
                    return res;
            }
            else if (in_sequence && *ch1 != *ch2) {
                ch2 = needle.begin();
                ch1 = haystack.begin() + res + 1;
                i = res;

                res = -1;
                in_sequence = false;
            }
            else if (in_sequence and *ch1 == *ch2) {
                ++ch1;
                ++ch2;

                if (ch2 == needle.end())
                    return res;
            }
            else if (not in_sequence && *ch1 != *ch2) {
                ++ch1;;
            }
        }

        return -1;
    }


    //Check all the test-cases.
    bool strStr_Test() {

        //Test-case 1:
        if (strStr("lello", "ll") != 2)
            return false;

        //Test-case 2:
        if (strStr("lelo", "ll") != -1)
            return false;

        //Test-case 3:
        if (strStr("leol", "ll") != -1)
            return false;

        //Test-case 4:
        if (strStr("aaaaa", "bba") != -1)
            return false;

        //Test-case 5:
        if (strStr("", "") != 0)
            return false;

        //Test-case 6:
        if (strStr("abcd", "") != 0)
            return false;

        //Test-case 7:
        if (strStr("", "abcd") != -1)
            return false;

        //Test-case 8:
        if (strStr("mississippi", "issip") != 4)
            return false;

        //Test-case 9:
        if (strStr("mississippi", "si") != 3)
            return false;            

        std::cout << "All test-cases for strStr method passed." << std::endl;
        return true;
    }
}