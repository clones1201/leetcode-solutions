#pragma once

#include "common.h"

//
//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update(2015 - 02 - 12) :
//	For C programmers : Try to solve it in - place in O(1) space.

//  Clarification:
//  What constitutes a word ?
//  A sequence of non - space characters constitutes a word.
//  Could the input string contain leading or trailing spaces ?
//  Yes.However, your reversed string should not contain leading or trailing spaces.
//  How about multiple spaces between two words ?
//  Reduce them to a single space in the reversed string.

void reverseWords(string &s) {
	string result = "";
	vector<string> stack;
	string token;
	for (int i = 0; i< s.size(); i++) {

		if (s[i] == ' ') {
			if (token != "") {
				stack.push_back(token);
				token = "";
			}
		}
		else if (i == s.size() - 1) {
			token = token + s[i];
			stack.push_back(token);
		}
		else {
			token = token + s[i];
		}
	}
	for (int i = stack.size() - 1; i > 0; i--) {
		result = result + stack[i].c_str() + ' ';
	}
	if (stack.size() != 0) result = result + stack[0].c_str();
	s = result;
}