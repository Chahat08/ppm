#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Image {
private:
	// headers
	std::string magicNumber;
	int width;
	int height;
	int maxVal;
	
	// path
	std::string filePath;

	// image data
	std::vector<char> imageData;

	// private methods
	void constructImageFromFilePath();
	std::vector<char> getImageDataAsVector();
	std::map<std::string, std::string> getImageHeadersAsMap();


public:
	// constructors
	Image(std::string magicNumber, int width, int height, int maxVal) :
		magicNumber(magicNumber), width(width), height(height), maxVal(maxVal) {};

	Image(std::string filePath) :filePath(filePath) {
		constructImageFromFilePath();
	}

	// getters
	std::string getMagicNumber();
	int getWidth();
	int getHeight();
	int getMaxVal();
	std::vector<char> getImageData();

	// public methods
	std::vector<char> getImageDataWithCommentsRemoved();
	void printImageOnConsole();

};
