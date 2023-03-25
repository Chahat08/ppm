#include "image.h"
#include "../utils/utils.h"
#include <fstream>
#include <iostream>

void Image::printImageOnConsole() {
	for (char c : imageData) std::cout << c;
}

std::vector<char> Image::getImageDataAsVector() {
	std::ifstream file(filePath);
	std::vector<char> data(std::istreambuf_iterator<char>(file), {});
	file.close();
	return data;
}

std::vector<char> Image::getImageDataWithCommentsRemoved() {
	std::vector<char> data = Image::getImageDataAsVector();
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

std::map<std::string, std::string> Image::getImageHeadersAsMap() {
	std::vector<char> data = Image::getImageDataWithCommentsRemoved();
	std::map<std::string, std::string> headers;

	for (int i = 0, lines = 0; i < data.size() && lines < 4; ++i) {
		std::string str;
		while (!Utils::isWhitespaceChar(data[i])) {
			str += data[i++];
		}
		fillMap(headers, str, lines);
		lines++;
	}

	return headers;
}

std::string Image::getMagicNumber() {
	return magicNumber;
}

int Image::getWidth() {
	return width;
}

int Image::getHeight() {
	return height;
}

int Image::getMaxVal() {
	return maxVal;
}

std::vector<char> Image::getImageData() {
	return imageData;
}

void Image::constructImageFromFilePath() {
	imageData = getImageDataAsVector();
	std::map<std::string, std::string> headers = getImageHeadersAsMap();
	
	magicNumber = headers["magic number"];
	width = stoi(headers["width"]);
	height = stoi(headers["height"]);
	maxVal = stoi(headers["maxVal"]);
}
