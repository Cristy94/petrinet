#include "PetriNetworksApp.h"

//Constructor
PetriNetworksApp::PetriNetworksApp(){
	arcs = new vector<Arcs*>();
	places = new vector<Place*>();
	transitions = new vector<Transition*>();
	step_count = 0;
}

