
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "TimeConversion.h"

using namespace std;

string TimeConversion::doubleLengthFormat(int p_time) {
	stringstream sStream;
	sStream << setw(2) << setfill('0') << p_time;
	return sStream.str();
}

string TimeConversion::timeConversion(string p_input) {

	int hhi = 0, mmi = 0, ssi = 0;
	int army_hhi = 0, army_mmi = 0, army_ssi = 0;
	string army_hhs = "", army_mms = "", army_sss = "";

	hhi = stoi(p_input.substr(0, 2));
	mmi = stoi(p_input.substr(3, 2));
	ssi = stoi(p_input.substr(6, 2));

	if (p_input.substr(8, 2).compare("AM") == 0) {
		army_hhi = hhi % 12;
	}
	else {
		army_hhi = hhi % 12 + 12;
	}
	army_mmi = mmi;
	army_ssi = ssi;

	army_hhs = doubleLengthFormat(army_hhi);
	army_mms = doubleLengthFormat(army_mmi);
	army_sss = doubleLengthFormat(army_ssi);

	return army_hhs + ":" + army_mms + ":" + army_sss;
}
