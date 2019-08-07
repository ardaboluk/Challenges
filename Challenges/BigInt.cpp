
#include "BigInt.h"

void BigInt::revertString(string& s) {
	int slen = s.length();
	char tmp = 0;
	for (unsigned int i = 0; i < slen / 2; i++) {
		tmp = s[i];
		s[i] = s[slen - 1 - i];
		s[slen - 1 - i] = tmp;
	}
}

pair<string*, int> BigInt::multiplyStringsMidResults(string s1, string s2) {

	string smallLengthNum = s1.length() <= s2.length() ? s1 : s2;
	string largeLengthNum = s1.length() > s2.length() ? s1 : s2;
	string* midResults = new string[smallLengthNum.length()];

	for (int smallerDigit = (int)smallLengthNum.length() - 1; smallerDigit >= 0; smallerDigit--) {
		string currentMidResult = "";
		int carry = 0;
		int mult = 0;
		int mutlpluscarry = 0;
		for (int largerDigit = (int)largeLengthNum.length() - 1; largerDigit >= 0; largerDigit--) {
			mult = (smallLengthNum[smallerDigit] - 48) * (largeLengthNum[largerDigit] - 48);
			mutlpluscarry = mult + carry;
			if (largerDigit == 0) {
				midResults[(int)smallLengthNum.length() - 1 - smallerDigit] += (mutlpluscarry % 10) + 48;
				if ((mutlpluscarry) / 10 != 0) {
					midResults[(int)smallLengthNum.length() - 1 - smallerDigit] += (mutlpluscarry) / 10 + 48;
				}
			}
			else {
				midResults[(int)smallLengthNum.length() - 1 - smallerDigit] += ((mutlpluscarry) % 10) + 48;
				carry = (mutlpluscarry) / 10;
			}
		}
	}

	return make_pair(midResults, smallLengthNum.length());
}

string BigInt::multiplyStringsFinalResults(string* midResults, int numMidResults) {

	string result = "";

	int col = 0, row = 0, carry = 0, multpluscarry = 0;

	while (true) {
		int midSum = 0;
		for (row = 0; row < numMidResults; row++) {
			if ((row > col) || ((col - row) >= midResults[row].length())) {
				midSum += 0;
			}
			else {
				midSum += midResults[row][col - row] - 48;
			}
		}
		multpluscarry = midSum + carry;
		if ((row == numMidResults) && (col - (row - 1) == midResults[row - 1].length() - 1)) {
			result += (multpluscarry % 10) + 48;
			if (multpluscarry / 10 != 0) {
				result += (multpluscarry / 10) + 48;
			}
			break;
		}
		else {
			result += multpluscarry % 10 + 48;
			carry = multpluscarry / 10;
			col++;
		}
	}

	revertString(result);

	return result;
}

string BigInt::multiplyStrings(string s1, string s2) {

	string result = "";

	pair<string*, int> midPair = multiplyStringsMidResults(s1, s2);
	result = multiplyStringsFinalResults(midPair.first, midPair.second);
	delete[] midPair.first;

	return result;
}