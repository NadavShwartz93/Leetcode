#include<string>
#include<iostream>
#include <assert.h>     /* assert */

/*
https://leetcode.com/problems/is-subsequence/
*/
namespace isSubsequence {
    //Version 1: Recursion version
    bool isSubsequence_Rec(const std::string& s, const std::string& t) {

        if (s.empty() and t.empty())
            return true;
        if (s.empty())
            return true;
        if (not s.empty() and t.empty())
            return false;

        if (s[0] == t[0]) {
            std::string s_new (s.begin() + 1, s.end());
            std::string t_new(t.begin() + 1, t.end());
            return isSubsequence_Rec(s_new, t_new);
        }
        else {
            std::string t_new(t.begin() + 1, t.end());
            return isSubsequence_Rec(s, t_new);
        }
    }

    //version 2: Iterative Version.
    bool isSubsequence(std::string& s, std::string& t) {

        //Save old values:
        const std::string str1 = s;
        const std::string str2 = t;
        bool res;

        while (true)
        {
            if (s.empty() and t.empty()){
                res = true;
                break;
            }
            if (s.empty()){
                res = true;
                break;
            }
            if (not s.empty() and t.empty()){
                res = false;
                break;
            }
            if (s[0] == t[0]) {
                s.erase(s.begin());
            }
            t.erase(t.begin());
        }

        //Restore the old values:
        s = str1;
        t = str2;
        return res;
    }


    //Check all the test-cases.
    bool isSubsequence_Test(){

        std::string str1;
        std::string str2;
        
        //Test-case 1:
        str1 = "abc";
        str2 = "ahbgdc";
        if (isSubsequence(str1, str2) != true)
            return false;
        assert(isSubsequence_Rec("abc", "ahbgdc"));

        //Test-case 2:
        str1 = "axc";
        str2 = "ahbgdc";
        if (isSubsequence(str1, str2) != false)
            return false;
        assert(not isSubsequence_Rec("axc", "ahbgdc"));

        //Test-case 3:
        str1 = "abc";
        str2 = "";
        if (isSubsequence(str1, str2) != false)
            return false;
        assert(not isSubsequence_Rec("abc", ""));

        //Test-case 4:
        str1 = "";
        str2 = "abc";
        if (isSubsequence(str1, str2) != true)
            return false;
        assert(isSubsequence_Rec("", "abc"));


        std::cout << "All test-cases for isSubsequence method passed." << std::endl;
        return true;
    }
}