#include<iostream>
#include<limits>
#include <assert.h>     /* assert */

/*
https://leetcode.com/problems/powx-n/
*/
namespace myPow {
    
    /*
    Implementation of fast power algorithm - Recursive approach,
    that perform division of the power in every iteration.
    Time Complexity: O(log(n)).
    */
    double myPow_recursive(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        else {
            if (n % 2 != 0) {
                n = n - 1;
                return x * myPow_recursive(x * x, n / 2);
            }
            return myPow_recursive(x * x, n / 2);
        }
    }

    /*
    Implementation of fast power algorithm - Iterative approach, 
    that perform division of the power in every iteration.
    Time Complexity: O(log(n)). 
    */
    double myPow(double x, int n) {
        
        double res = 1;
        bool is_neg = n < 0 ? true : false;
        
        //The case n is INT_MIN.
        if (n == INT_MIN) {
            n = n / 2;
            x = x * x;
        }
        n = abs(n);

        while (n > 1)
        {
            if (n % 2 == 1) {
                n = n - 1;
                res = res * x;
            }
            
            n = n / 2;
            x = x * x;
        }

        if (is_neg)
            return 1 / (res * x);
        return res * x;
    }


    //Check all the test-cases - check the two versions.
    bool myPow_Test() {

        //Test-case 1:
        assert(myPow(2, 3) == 8);
        assert(myPow_recursive(2, 3) == 8);

        //Test-case 2:
        assert(myPow(2.00000, 10) == 1024.00000);
        assert(myPow_recursive(2.00000, 10) == 1024.00000);

        //Test-case 3:
        double res = 9.2610000000000010;
        assert(myPow(2.10000, 3) == res);
        assert(myPow_recursive(2.10000, 3) == res);

        //Test-case 4:
        assert(myPow(2.00000, -2) == 0.25000);
        assert(myPow_recursive(2.00000, -2) == 0.25000);

        //Test-case 5:
        assert(myPow(1e-05, INT_MAX) == 0.0);
        assert(myPow_recursive(1e-05, INT_MAX) == 0.0);

        //Test-case 6:
        assert(myPow(2.00000, INT_MIN) == 0.0);
        assert(myPow_recursive(2.00000, INT_MIN) == 0.0);

        std::cout << "All test-cases for myPow method passed." << std::endl;
        return true;
    }

};