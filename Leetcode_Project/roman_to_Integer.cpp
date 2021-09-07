#include<iostream>
#include<string>
#include <map>
#include "header/roman_to_Integer.h"


/*
https://leetcode.com/problems/roman-to-integer/
*/
namespace roman_to_integer {

    Roman_class::Roman_class() {
        Roman_map['I'] = 1;
        Roman_map['V'] = 5;
        Roman_map['X'] = 10;
        Roman_map['L'] = 50;
        Roman_map['C'] = 100;
        Roman_map['D'] = 500;
        Roman_map['M'] = 1000;
    }

   
    int Roman_class::romanToInt(std::string s) {

        int len = s.length();
        int number = 0;

        for (size_t i = 0; i < len; i++)
        {
            char temp = s[i];
            if (i == 0)
                number += Roman_map[temp];
            else {
                if ((s[i - 1] == 'I' and s[i] == 'V') or (s[i - 1] == 'I' and s[i] == 'X'))
                    number += Roman_map[temp] - 2;
                else if ((s[i - 1] == 'X' and s[i] == 'L') or (s[i - 1] == 'X' and s[i] == 'C'))
                    number += Roman_map[temp] - 20;
                else if ((s[i - 1] == 'C' and s[i] == 'D') or (s[i - 1] == 'C' and s[i] == 'M'))
                    number += Roman_map[temp] - 200;
                else
                    number += Roman_map[temp];
            }
        }
        return number;
    }

    //Check all the test-cases.
    bool Roman_class::romanToInt_Test() {
        if (romanToInt("III") != 3)
            return false;
        if (romanToInt("IV") != 4)
            return false;
        if (romanToInt("IX") != 9)
            return false;
        if (romanToInt("LVIII") != 58)
            return false;
        if (romanToInt("MCMXCIV") != 1994)
            return false;

        std::cout << "All test-cases for romanToInt method passed." << std::endl;
        return true;
    }
}