#include <iostream>
#include "gui.h"
#include "Serialization.h"

int main(){

	GUI PetriNetFLTKWindow;
	PetriNetFLTKWindow.init();
	Serialization *serialization = new Serialization();


    return 0;
}