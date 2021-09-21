#include<vector>
#include<string>
#include<iostream>

/*
https://leetcode.com/problems/counting-bits/
*/
namespace counting_Bits {
	
    /* Function to get # of 1 bits in binary
    representation of positive integer n */
    unsigned int num_of_ones(unsigned int n)
    {
        unsigned int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }


    std::vector<int> countBits(const int& n) {

        std::vector<int> res(n + 1);
        for (int i = 0; i <= n; i++)
        {
            res[i] = num_of_ones(i);
        }
        return res;
    }


    //Check all the test-cases.
    bool countBits_Test() {

        std::vector<int> res;

        //Test-case 1:
        res = {0,1,1};
        if(countBits(2) != res)
            return false;

        //Test-case 2:
        res = { 0,1,1,2,1,2 };
        if (countBits(5) != res)
            return false;

        //Test-case 3:
        res = { 0 };
        if (countBits(0) != res)
            return false;

        //Test-case 4:
        res = { 0,1,1,2,1,2,2,3,1,2,2 };
        auto vec = countBits(10);
        if(res != vec)
            return false;

        
        std::cout << "All test-cases for countBits method passed." << std::endl;
        return true;
    }
}