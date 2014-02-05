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

    //First try to trigger a transition
    for(std::vector<Arcs*>::iterator it = arcs->begin(); it != arcs->end(); ++it){

        if(Transition* b = dynamic_cast< Transition* >((*it)->source))
            if((*it)->source->hasTokens()){

                (*it)->source->removeToken();
                
                //Add a token to every destination
                for(std::vector<Arcs*>::iterator d = arcs->begin(); d != arcs->end(); ++d){
                    if((*d)->source == (*it)->source){
                        (*d)->destination->addToken();
                        (*d)->destination->makeNthTokenActive((*d)->destination->getTokenCount());
                    }
                }

                return 1;
            }
    }

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

void PetriNetworksApp::removeElement(IElement *el){

    //Remove all arcs 
    bool ok;
    do {
    
        ok = 0;
        for(std::vector<Arcs*>::iterator it = arcs->begin(); it != arcs->end(); ++it){
            if((*it)->source == el || (*it)->destination == el){
                arcs->erase(it);
                ok = 1;
                break;
            }
        }

    }
    while ( ok == 1);

    //Try to remove transition
    for(std::vector<Transition*>::iterator it = transitions->begin(); it != transitions->end(); ++it){

        if( (*it) == el){
            transitions->erase(it);
            return;
        }
    }

    //Try to remove place
    for(std::vector<Place*>::iterator it = places->begin(); it != places->end(); ++it){

        if( (*it) == el){
            places->erase(it);
            return;
        }
    }

    delete el;
}

void PetriNetworksApp::selectElement(int x, int y){

    //Clicked element
    IElement *closest = NULL;
    double closestDistance = 100000.00;

    //Search for places
    for(std::vector<Place*>::iterator it = places->begin(); it != places->end(); ++it){

        Point linearDistance = Point(x - (*it)->centerPosition()->getX(), y - (*it)->centerPosition()->getY());
        
        double distance = sqrt(linearDistance.getX() * linearDistance.getX() + linearDistance.getY() * linearDistance.getY());

        if(distance < closestDistance){
            closestDistance = distance;
            closest = *it;
        }
    }

    //Search for transitions
    for(std::vector<Transition*>::iterator it = transitions->begin(); it != transitions->end(); ++it){

        Point linearDistance = Point(x - (*it)->centerPosition()->getX(), y - (*it)->centerPosition()->getY());
        
        double distance = sqrt(linearDistance.getX() * linearDistance.getX() + linearDistance.getY() * linearDistance.getY());

        if(distance < closestDistance){
            closestDistance = distance;
            closest = *it;
        }
    }

    //If an element is found add it to the last 2 selected elements queue
    if(closest != NULL && closestDistance < 100){
        
        if(selected.size() == 2){
            selected.front()->selected = false;
            selected.pop_front();
        }

        closest->selected = true;
        selected.push_back(closest);
    }
    //Else clear the queue
    else {
        while(!selected.empty()){
             selected.front()->selected = false;
            selected.pop_front();
        }
    }
}

void PetriNetworksApp::moveSelected(int x, int y){

    IElement *last = selected.back();

    if(last != NULL){

        last->setPosition(x, y);
    }
}