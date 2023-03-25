#include "image/image.h"

int main() {
	Image image1("resources/example1_p3.ppm");
	image1.printImageOnConsole();

	Image image2("resources/example_p2.ppm");
	image2.printImageOnConsole();

	//Image image3("resources/example_p3.ppm");
	//image3.printImageOnConsole();
}
