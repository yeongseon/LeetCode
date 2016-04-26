#pragma once
#include <iostream>
#include <stdint.h>

using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	uint32_t reverseBits(uint32_t n) {
		int inputarray[32] = { 0, };
		int index = 0;

		if (n == 0)
			return 0;

		while (n!= 1) {			
			inputarray[index] = n % 2;
			index++;
			n = n / 2;
		}
		inputarray[index] = n % 2;
		index++;

		uint32_t bit = 1;
		uint32_t output = 0;

		for (int i = 0; i < 32; i++) {
			if (inputarray[31 - i])
				output += bit;
			bit = bit << 1;
		}

		return output;
	}
};

