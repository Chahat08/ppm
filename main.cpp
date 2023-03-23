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

std::vector<char> getImageDataAsVector(std::string filePath) {
	std::ifstream file(filePath);
	std::vector<char> data(std::istreambuf_iterator<char>(file), {});
	file.close();
	return data;
}

void printImageOnConsole(std::string filePath) {
	std::vector<char> data = getImageDataAsVector(filePath);
	for (char c : data) std::cout << c;
}

std::vector<char> getImageCommentsRemoved(std::string filePath) {
	std::vector<char> data = getImageDataAsVector(filePath);
	std::vector<char> transformed;

	for (int i = 0; i < data.size(); ++i) {
		if (data[i] == '#') {
			// comment begins, ignore till EOL.
			while (data[i++] != '\n');
		}
		transformed.push_back(data[i]);
	}

	return transformed;
}

void fillMap(std::map<std::string, std::string>& headers, std::string str, int line) {
	if (line == 0) headers["magic number"] = str;
	else if (line == 1) headers["width"] = str;
	else if (line == 2) headers["height"] = str;
	else headers["maxVal"] = str;
}

std::map<std::string, std::string> getImageHeadersAsMap(std::string filePath) {
	std::vector<char> data = getImageCommentsRemoved(filePath);
	std::map<std::string, std::string> headers;

	for (int i = 0, lines = 0; i < data.size() && lines < 4; ++i) {
		std::string str;
		while (!isWhitespaceChar(data[i])) {
			str += data[i++];
		}
		fillMap(headers, str, lines);
		lines++;
	}

	for (auto x : headers) {
		std::cout << x.first << ": " << x.second << std::endl;
	}
	return headers;
}

int main() {
	getImageHeadersAsMap("resources/example4.ppm");
}