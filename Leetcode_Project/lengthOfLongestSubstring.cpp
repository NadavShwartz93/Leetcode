#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
namespace lengthOfLongestSubstring{
    std::vector<char>::iterator it;

    //Check if ch is in the set.
    bool in (std::vector<char>& s, const char& ch){
        it = find(s.begin(), s.end(), ch);
        if (it == s.end())
            return false;

        return true;
    }
    
    int lengthOfLongestSubstring(const std::string& s) {
        size_t len = s.length();
        size_t max_len = 0;
        std::vector<char> chars_vector;
        size_t set_len = 0;

        for(int i=0; i < len; i++){
            //the case that the char is NOT in the set. 
            if(not in(chars_vector, s[i])){
                chars_vector.push_back(s[i]);
                set_len++;
            }
            else {
                //Update max_len value.
                max_len = chars_vector.size() > max_len ? chars_vector.size() : max_len;
                //Erase the begining of the set.
                chars_vector.erase(chars_vector.begin(), it+1);
                //Insert the new char.
                chars_vector.push_back(s[i]);
                //Update set_len.
                set_len = chars_vector.size();
            }
        }

        if (set_len > max_len)
            return std::move(set_len);
        return std::move(max_len);
    }

    //Check all the test-cases.
    bool lengthOfLongestSubstring_Test() {

        //Test-case 1:
        if (lengthOfLongestSubstring("abcabcbb") != 3)
            return false;

        //Test-case 2:
        if (lengthOfLongestSubstring("bbbbb") != 1)
            return false;

        //Test-case 3:
        if (lengthOfLongestSubstring("pwwkew") != 3)
            return false;

        //Test-case 4:
        if (lengthOfLongestSubstring("") != 0)
            return false;

        //Test-case 5:
        if (lengthOfLongestSubstring(" ") != 1)
            return false;

        //Test-case 6:
        if (lengthOfLongestSubstring("aab") != 2)
            return false;

        //Test-case 7:
        if (lengthOfLongestSubstring(" ab bb ac") != 4)
            return false;

        //Test-case 8:
        if(lengthOfLongestSubstring("dvdf") != 3)
            return false;

        //Test-case 9:
        if (lengthOfLongestSubstring("ynyo") != 3)
            return false; 

        std::cout << "All test-cases for lengthOfLongestSubstring method passed." << std::endl;
        return true;
    }
}