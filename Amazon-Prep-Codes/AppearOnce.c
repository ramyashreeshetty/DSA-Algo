// Given a sorted array in which all elements appear twice (one after one)and one element appears only once. 
// Find that element in O(log n) complexity.

// Input:   arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
// Output:  4

// Input:   arr[] = {1, 1, 3, 3, 4, 4, 5, 5, 7, 7, 8}
// Output:  8


// An Efficient Solution can find the required element in O(Log n) time. The idea is to use Binary Search. Below is an observation on the input array. 
// All elements before the required have the first occurrence at even index (0, 2, ..) and the next occurrence at odd index (1, 3, …). And all elements after the required elements have the first occurrence at an odd index and the next occurrence at an even index. 

// 1) Find the middle index, say ‘mid’.
// 2) If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are the same, then the required element after ‘mid’ and else before mid.
// 3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required element after ‘mid’ and else before mid.

// C program to find the element that appears only once
#include <stdio.h>

// A Binary Search based function to find the element
// that appears only once
void search(int* arr, int low, int high)
{
	// Base cases
	if (low > high)
		return;

	if (low == high) {
		printf("The required element is %d ", arr[low]);
		return;
	}

	int mid = (low + high) / 2;

	// If mid is even and element next to mid is
	// same as mid, then output element lies on
	// right side, else on left side
	if (mid % 2 == 0) {
		if (arr[mid] == arr[mid + 1])
			search(arr, mid + 2, high);
		else
			search(arr, low, mid);
	}
	else // If mid is odd
	{
		if (arr[mid] == arr[mid - 1])
			search(arr, mid + 1, high);
		else
			search(arr, low, mid - 1);
	}
}

int main()
{
	int arr[] = { 1, 1, 2, 4, 4, 5, 5, 6, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	search(arr, 0, len - 1);
	return 0;
}
