#pragma once

#include <string>

using namespace std;

class TimeConversion {
private:
	string doubleLengthFormat(int);
public:
	string timeConversion(string p_input);
};
