#pragma once

#include "common.h"

//Find the contiguous subarray within an array(containing at least one number) which has the largest product.
//
//For example, given the array[2, 3, -2, 4],
//the contiguous subarray[2, 3] has the largest product = 6.

typedef vector<int>::iterator Iterator;
int maxProduct(vector<int>& nums) {
	Iterator iter = nums.begin();
	int ret = *iter;
	int all = *iter;
	int tail = 0;
	bool minus = *iter < 0;
	iter++;
	for (; iter != nums.end(); ++iter)
	{
		if (all == 0)
		{
			all = *iter;
			tail = 0;
			minus = *iter < 0;
		}
		else
		{
			if (minus && tail == 0)
			{
				tail = *iter;
				minus = false;
			}
			else if (*iter < 0 && tail == 0)
			{
				minus = true;
			}
			else
			{
				tail *= *iter;
			}
			all *= *iter;
		}
		ret = std::max(ret, std::max(all, tail));
	}
	return ret;
}