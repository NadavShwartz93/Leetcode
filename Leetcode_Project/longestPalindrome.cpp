#include<string>
#include<vector>
#include<iostream>
#include<utility>

/*
https://leetcode.com/problems/longest-palindromic-substring/
*/
namespace longestPalindrome {

    inline bool is_Palindrome(const std::string& str) {
        int len = str.length();
        if (len == 0 || len == 1)
            return true;
        
        //Calculate the number of iterations in the for loop. 
        int stop = len % 2 == 0 ? len / 2 : len - 2;

        for (size_t i = 0; i < stop; i++)
        {
            if (str[i] != str[len - i - 1])
                return false;
        }
        return true;
    }

    std::string longestPalindrome(const std::string& s) {
        int len = s.length();
        if (len == 1)
            return s;

        std::vector<std::vector<bool>> res;

        std::string res_str;
        res_str = s[0];
        int max_len = 1;

        for (int i = 0; i < len; i++)
        {
            std::vector<bool> v(len);
            v[i] = true;

            for (int j = i+1; j < len; j++)
            {
                std::string temp(s.begin() + i, s.begin() + j+1);
                v[j] =  is_Palindrome(temp);

                if (v[j] and max_len < temp.length()) {
                    max_len = temp.length();
                    res_str = temp;
                }
            }
            res.push_back(v);
        }


        return std::move(res_str);
    }


    //Check all the test-cases.
    bool longestPalindrome_Test() {

        std::string str;

        //Test-case 1:
        str = longestPalindrome("babad");
        if (str != "bab" and str != "aba")
            return false;

        //Test-case 2:
        str = longestPalindrome("cbbd");
        if (str != "bb")
            return false;

        //Test-case 3:
        str = longestPalindrome("a");
        if (str != "a")
            return false;

        //Test-case 4:
        str = longestPalindrome("ac");
        if (str != "a")
            return false;

        //Test-case 5:
        str = longestPalindrome("abac");
        if (str != "aba")
            return false;

        //Test-case 6:
        str = longestPalindrome("abacdfgdcaba");
        if (str != "aba")
            return false;

        //Test-case 7:
        str = "aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa";
        if (longestPalindrome(str) != str)
            return false;

        std::cout << "All test-cases for longestPalindrome method passed." << std::endl;
        return true;
    }

}