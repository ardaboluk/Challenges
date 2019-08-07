#pragma once

#include <string>
#include <utility>

using namespace std;

class BigInt {
private:
	void revertString(string&);
	pair<string*, int> multiplyStringsMidResults(string, string);
	string multiplyStringsFinalResults(string*, int);
public:
	string multiplyStrings(string, string);
};