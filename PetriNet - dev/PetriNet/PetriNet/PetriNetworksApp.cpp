#include "PetriNetworksApp.h"

//Constructor
PetriNetworksApp::PetriNetworksApp(){
	arcs = new vector<Arcs*>();
	places = new vector<Place*>();
	transitions = new vector<Transition*>();
	step_count = 0;
}

//Advance the network one step
//Returns 0 if simulation has ended
int PetriNetworksApp::advanceSimulation(){

    //Iterate through all arcs, move a token if possible and stop
    for(std::vector<Arcs*>::iterator it = arcs->begin(); it != arcs->end(); ++it){

        if((*it)->source->hasTokens()){

            (*it)->source->removeToken();
            (*it)->destination->addToken();
            (*it)->destination->makeNthTokenActive((*it)->destination->getTokenCount());

            std::cout << "Moved one token!\n";
            std::cout << "Tokens left in this source: " << (*it)->source->getTokenCount() << '\n';

            return 1;
        }

    }

    return 0;
}