#pragma once
#include <iostream>

using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	int hammingWeight(uint32_t n) {
		int count = 0;
		uint32_t bit = 1;
		for (int i = 0; i < 32; i++) {
			if (n & bit)
				count++;
			bit = bit << 1;
		}
		return count;
	}
};

