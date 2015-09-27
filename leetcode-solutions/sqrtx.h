#pragma once

//Implement int sqrt(int x).
//
//Compute and return the square root of x.

int sqrt(int x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	long long right = 2;
	while (right * right < x / 2) {
		right = right * 2;
	}
	right = right * 2;
	long long left = 0, mid;
	while (left < right) {
		mid = (right + left) / 2;
		if (mid * mid <= x && (mid + 1)*(mid + 1) > x) return mid;
		else if (mid * mid > x) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}