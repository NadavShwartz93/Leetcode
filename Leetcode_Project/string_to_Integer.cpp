#include<iostream>
#include<string>
#include<set>
#include <algorithm>    // std::all_of
#include<limits>

/*
https://leetcode.com/problems/string-to-integer-atoi/
*/
namespace my_atoi {

    bool in(const std::set<char>& s, const char& val) {
        auto res = s.find(val);
        if (res == s.end())
            return false;
        return true;
    }

    int myAtoi(const std::string& s) {
        int neg_flag = -2;
        long long num = -1;

        char mynumbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        const std::set<char> chars_set(mynumbers, mynumbers + 10);

        int index = 0;
        bool ziro_first = false;

        //The case the string is empty OR the string contain only space.
        if (s.empty() or std::all_of(s.begin(), s.end(), 
            [](char c) {return std::isspace(c); }))
            return 0;

        for (char ch : s) {

            if (ch == ' ' and num == -1 and neg_flag == -2)	//Step 1
                continue;
            else if ((ch == '-' or ch == '+') and num == -1 and neg_flag == -2
                and s.length() != 1)	//Step 2
                neg_flag = ch == '-' ? 1 : 0;
            else if (in(chars_set, ch)) {	//Step 3
                if (index == 0) {
                    num = ch - '0';
                    index++;
                }
                else {
                    num = num * 10 + (ch - '0');

                    if (num > INT_MAX) {	//Step 5 - check num is not out of range.
                        num = neg_flag == 1 ? INT_MIN : INT_MAX;
                        break;
                    }
                }
            }
            else if (not in(chars_set, ch)) {    //Step 3
                if (num == -1)
                    return 0;
                break;
            }
        }

        if (neg_flag == 1)	//Step 4 - change the sign as necessary.
            num = -1 * num;

        return num;
    }
    
    //Check all the test-cases.
    bool myAtoi_Test() {

        std::string str;
        //Test-case 1:
        str = "42";
        if (myAtoi(str) != 42)
            return false;

        //Test-case 2:
        str = "-42";
        if (myAtoi(str) != -42)
            return false;

        //Test-case 3:
        str = "+42";
        if (myAtoi(str) != 42)
            return false;

        //Test-case 4:  leading whitespace.
        str = "     -42";
        if (myAtoi(str) != -42)
            return false;

        //Test-case 4.1.
        str = "4193   ";
        if (myAtoi(str) != 4193)
            return false;

        //Test-case 5:  number start with zero.
        str = "0042";
        if (myAtoi(str) != 42)
            return false;

        //Test-case 6:  words after the numbers.
        str = "4193 with words";
        if (myAtoi(str) != 4193)
            return false;

        //Test-case 6.1:  words before the numbers.
        str = "words and 987";
        if (myAtoi(str) != 0)
            return false;

        //Test-case 7:  number is out of range.
        str = "-91283472332";
        if (myAtoi(str) != -2147483648)
            return false;

        //Test-case 7.1:  number is out of range.
        str = "91283472332";
        if (myAtoi(str) != 2147483647)
            return false;

        //Test-case 8.
        str = "3.14159";
        if (myAtoi(str) != 3)
            return false;

        //Test-case 8.
        str = "-3.14159";
        if (myAtoi(str) != -3)
            return false;

        str = "+-12";
        if (myAtoi(str) != 0)
            return false;

        str = "00000-42a1234";
        if (myAtoi(str) != 0)
            return false;

        str = "   +0 123";
        if (myAtoi(str) != 0)
            return false;

        str = "    -a 1";
        if (myAtoi(str) != 0 and myAtoi("  +  413") != 0)
            return false;

        if (myAtoi("") != 0 and myAtoi("       ")  != 0)
            return false;

        std::cout << "All test-cases for myAtoi method passed." << std::endl;
        return true;
    }
}