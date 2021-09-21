#include<string>
#include<iostream>
#include<vector>

/*
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/
namespace arrayStringsAreEqual {

    bool arrayStringsAreEqual(const std::vector<std::string>& word1, 
        const std::vector<std::string>& word2) {

        //Create str1 - concatenate all strings from word1. 
        std::string str1 ("");
        for (size_t i = 0; i < word1.size(); i++)
        {
            str1 = str1 + word1[i];
        }

        //Create str2 - concatenate all strings from word2. 
        std::string str2 ("");
        for (size_t i = 0; i < word2.size(); i++)
        {
            str2 = str2 + word2[i];
        }

        //Check if the generated strings are equals.
        return str1 == str2;
    }


    //Check all the test-cases.
    bool arrayStringsAreEqual_Test() {

        //Test-case 1:
        if (not arrayStringsAreEqual({ "ab", "c" }, { "a", "bc" }))
            return false;

        //Test-case 2:
        if (arrayStringsAreEqual({ "a", "cb" }, { "ab", "c" }))
            return false;

        //Test-case 3:
        if (not arrayStringsAreEqual({ "abc", "d", "defg" }, { "abcddefg" }))
            return false;

        std::cout << "All test-cases for arrayStringsAreEqual method passed." << std::endl;
        return true;
    }

}