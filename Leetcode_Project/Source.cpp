#include<iostream>
#include<vector>
#include<chrono>		//for timer operation

#include "header/Roman_to_Integer.h"


using namespace std;
using namespace roman_to_integer;
using time_type = std::chrono::time_point<std::chrono::steady_clock>;

//Methods for timer:
namespace my_timer {
	time_type start_timer();
	void end_timer(time_type start);
};
namespace twoSum {
	vector<int> twoSum(vector<int>& nums, int target);
	bool twoSum_Test();
};
namespace reverse {
	int reverse(int x);
	bool reverse_Test();
};
namespace addTwoNumbers {
	bool addTwoNumbers_Test();
}
namespace isPalindrome {
	bool isPalindrome(int x);
	bool isPalindrome_Test();
};
namespace rotate_image {
	bool rotate_Test();
};
namespace removeNthFromEnd {
	bool removeNthFromEnd_Test();
};
namespace delete_duplicates {
	bool deleteDuplicates_Test();
};
namespace cycle_linked_list {
	bool detectCycle_Test();
}
namespace myPow {
	bool myPow_Test();
}
namespace mergeKLists {
	bool mergeKLists_Test();
}
namespace treeDepth {
	bool maxDepth_Test();
	bool minDepth_Test();
}
namespace sorted_to_BST {
	bool sortedArrayToBST_Test();
}

int main() {

	//Start counting the time.
	time_type start = my_timer::start_timer();

	if (not twoSum::twoSum_Test())
		std::cout << "twoSum failed" << std::endl;

	if(not reverse::reverse_Test())
		std::cout << "reverse failed" << std::endl;

	if (not addTwoNumbers::addTwoNumbers_Test())
		std::cout << "addTwoNumbers failed" << std::endl;

	if(not isPalindrome::isPalindrome_Test())
		std::cout << "isPalindrome failed" << std::endl;

	if(not Roman_class().romanToInt_Test())
		std::cout << "romanToInt failed" << std::endl;

	if( not rotate_image::rotate_Test())
		std::cout << "rotate failed" << std::endl;

	if (not removeNthFromEnd::removeNthFromEnd_Test())
		std::cout << "removeNthFromEnd failed" << std::endl;

	if (not delete_duplicates::deleteDuplicates_Test())
		std::cout << "deleteDuplicates failed" << std::endl;

	if(not cycle_linked_list::detectCycle_Test())
		std::cout << "detectCycle failed" << std::endl;

	if(not myPow::myPow_Test())
		std::cout << "myPow failed" << std::endl;

	if (not mergeKLists::mergeKLists_Test())
		std::cout << "mergeKLists failed" << std::endl;

	if (not treeDepth::maxDepth_Test())
		std::cout << "maxDepth failed" << std::endl;

	if(not treeDepth::minDepth_Test())
		std::cout << "minDepth failed" << std::endl;

	if(not sorted_to_BST::sortedArrayToBST_Test())
		std::cout << "sortedArrayToBST failed" << std::endl;

	//Stop the time counting, and print report.
	my_timer::end_timer(start);
	return 0;
}

namespace my_timer {
	time_type start_timer() {
		return chrono::steady_clock::now();
	}

	void end_timer(time_type start) {
		//Stop count the time.
		auto end = chrono::steady_clock::now();

		// Store the time difference between start and end
		auto diff = end - start;
		cout << "\nTotal Time Taken : \n";
		cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	}
};