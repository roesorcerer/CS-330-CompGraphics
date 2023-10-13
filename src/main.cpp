#include <iostream>
#include "../include/application.h"




int main(int args, char** argv) {

	Application app{ "CS330 ShowcaseApp", 800, 600 };
	app.Run();
	return 0;
}