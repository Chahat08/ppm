#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

bool isWhitespaceChar(char ch) {
	if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\v' || ch == '\r')
		return true;
	return false;
}

void fillMap(std::map<std::string, std::string>& headers, std::string str, int line) {
	if (line == 0) headers["magic number"] = str;
	else if (line == 1) headers["width"] = str;
	else if (line == 2) headers["height"] = str;
	else headers["maxVal"] = str;
}
