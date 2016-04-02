#pragma once

//Determine whether an integer is a palindrome.Do this without extra space.
//
//click to show spoilers.
//
//Some hints :
//Could negative integers be palindromes ? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer.However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow.How would you handle such case ?
//
//There is a more generic way of solving this problem.

int exp10(int coff) {
	int result = 1;
	for (int i = 0; i < coff; i++) {
		result *= 10;
	}
	return result;
}
int getNum(int num, int index) {
	int result = num;
	return (num / exp10(index)) % 10;
}

bool isPalindrome(int x) {
	if (x < 0) return false;
	int coff = 0;
	int num = x;
	while (x >= 10) {
		x /= 10;
		coff++;
	}

	for (int i = 0; i < coff; i++) {
		if (getNum(num, i) != getNum(num, coff - i))
			return false;
	}
	return true;
}