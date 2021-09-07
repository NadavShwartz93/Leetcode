#include<vector>
#include<iostream>

/*
https://leetcode.com/problems/rotate-image/
*/
namespace rotate_image {
	void rotate(std::vector<std::vector<int>>& matrix) {
		int n = matrix.size();
		std::vector<int> v(n);
		std::vector<std::vector<int>> new_matrix(n, v);

		for (int i = 0; i < n; i++)
		{
			int index = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				new_matrix[i][index] = matrix[j][i];
				index++;
			}
		}
		matrix = new_matrix;

	}

	//Check all the test-cases.
	bool rotate_Test() {

		std::vector<std::vector<int>> A;
		std::vector<std::vector<int>> A_T;

		auto test_case = [](auto A, auto A_T) {
			rotate(A);
			if (A != A_T)
				return false;
			return true;
		};

		//Test-case 1:
		A = { {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 } };
		A_T = { {7, 4, 1},{8, 5, 2},{9, 6, 3} };
		if (not test_case(A, A_T))
			return false;

		//Test-case 2:
		A = { {5, 1, 9, 11},{2, 4, 8, 10},{13, 3, 6, 7},{15, 14, 12, 16} };
		A_T = { {15, 13, 2, 5}, { 14, 3, 4, 1 }, { 12, 6, 8, 9 }, { 16, 7, 10, 11 } };
		if (not test_case(A, A_T))
			return false;

		//Test-case 3:
		A_T = A = { {1} };
		if (not test_case(A, A_T))
			return false;

		//Test-case 4:
		A = { {1, 2}, {3, 4} };
		A_T = { {3, 1}, { 4, 2 } };
		if(not test_case(A, A_T))
			return false;

		std::cout << "All test-cases for rotate method passed." << std::endl;
		return true;
	}
};