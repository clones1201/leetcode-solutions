#pragma once

#include "common.h"

//Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Here is an example :
//S = "rabbbit", T = "rabbit"
//
//Return 3.

int numDistinct(string S, string T) {
	int m = T.length();
	int n = S.length();
	if (m > n) return 0;    // impossible for subsequence

	vector<int> path(m + 1);
	for (int i = 0; i <= m; i++) path[i] = 0;
	path[0] = 1;            // initial condition

	for (int j = 1; j <= n; j++) {
		// traversing backwards so we are using path[i-1] from last time step
		for (int i = m; i >= 1; i--) {

			path[i] = path[i] + (T[i - 1] == S[j - 1] ? path[i - 1] : 0);

		}
	}

	return path[m];
}