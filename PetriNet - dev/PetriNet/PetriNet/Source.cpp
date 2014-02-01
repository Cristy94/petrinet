#include <iostream>
#include "gui.h"
#include "Serialization.h"

int main(){

	GUI PetriNetFLTKWindow;
	PetriNetFLTKWindow.init();
	Serialization *serialization = new Serialization();

	serialization->saveNetwork();
	serialization->loadNetwork();

    return 0;
}