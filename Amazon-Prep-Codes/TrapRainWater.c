// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it is able to trap after raining.

// Input: arr[]   = {3, 0, 2, 0, 4}
// Output: 7


// program to find maximum amount of water that can
// be trapped within given set of bars.
// Space Complexity : O(1)


#include <stdio.h>

int findWater(int arr[], int n)
{
	// initialize output
	int result = 0;

	// maximum element on left and right
	int left_max = 0, right_max = 0;

	// indices to traverse the array
	int lo = 0, hi = n - 1;

	while (lo <= hi) {
		if (arr[lo] < arr[hi]) {
			if (arr[lo] > left_max)
				// update max in left
				left_max = arr[lo];
			else
				// water on curr element = max - curr
				result += left_max - arr[lo];
			lo++;
		}
		else {
			if (arr[hi] > right_max)
				// update right maximum
				right_max = arr[hi];
			else
				result += right_max - arr[hi];
			hi--;
		}
	}

	return result;
}

int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Maximum water that can be accumulated is %d",findWater(arr, n));
}
