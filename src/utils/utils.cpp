#include "utils.h"

bool Utils::isWhitespaceChar(char ch) {
	if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\v' || ch == '\r')
		return true;
	return false;
}