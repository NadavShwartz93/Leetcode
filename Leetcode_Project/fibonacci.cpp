#include<iostream>

/*
https://leetcode.com/problems/fibonacci-number/
*/
namespace fibonacci_Number {

    int fib(const int& n) {
        int a = 0;
        int b = 1;
        
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        for (int i = 0; i < (n-1); i++)
        {
            int t = b;
            b = a + b;
            a = t;
        }
        return b;
    }


    //Check all the test-cases.
    bool fib_Test() {

        //Test-case 1:
        if (fib(0) != 0)
            return false;

        //Test-case 2:
        if (fib(1) != 1)
            return false;

        //Test-case 3:
        if (fib(2) != 1)
            return false;

        //Test-case 4:
        if (fib(3) != 2)
            return false;

        //Test-case 5:
        if (fib(4) != 3)
            return false;

        //Test-case 6:
        if (fib(5) != 5)
            return false;

        //Test-case 7:
        if (fib(6) != 8)
            return false;

        //Test-case 8:
        if (fib(30) != 832040)
            return false;

        std::cout << "All test-cases for fib method passed." << std::endl;
        return true;
    }
}
