#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	void rotate(vector<int>& nums, int k) {
		vector<int>::iterator it;
		int temp, size = 0;

		size = nums.size();
		it = nums.begin();
		for (int i = 0; i < k; i++) {			
			temp = nums[size-1];
			nums.pop_back();
			it = nums.insert(it, temp);
		}
	}
};

