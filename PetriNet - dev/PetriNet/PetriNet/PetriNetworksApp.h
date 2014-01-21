#ifndef __PETRINETWORKS_H_
#define __PETRINETWORKS_H_

#include "IElement.h"
#include "Arc.h"
#include "Place.h"
#include "Transition.h"

class PetriNetworksApp {
    private:
	    vector<Arcs*> *arcs;
	    vector<Place*> *places;
	    vector<Transition*> *transitions;

	    int step_count;

    public:
	    PetriNetworksApp() 
	    {
		    arcs = new vector<Arcs*>();
		    places = new vector<Place*>();
		    transitions = new vector<Transition*>();
		    step_count = 0;
	    }

	    void init()
	    {
		    arcs = new vector<Arcs*>();
		    places = new vector<Place*>();
		    transitions = new vector<Transition*>();
		    step_count = 0;
	    }

        //Creates and adds a new place to the network
        //Returns the index
	    int addPlace(int x, int y)
	    {
            Place *newPlace = new Place(new Point(x,y));
		    places->push_back(newPlace);

            return places->size() - 1;
	    }

        //Creates and adds a new transition to the network
        //Returns the index
	    int addTransition(int x, int y)
	    {
            Transition *newTransition = new Transition(new Point(x,y));
		    transitions->push_back(newTransition);

            return transitions->size() - 1;
	    }


	    void addPlaceTransitionArc(unsigned int placeIdx, unsigned int transitionIdx)
	    {            
            Arcs *newArc = new Arcs(places->at(placeIdx), transitions->at(transitionIdx));
            arcs->push_back(newArc);
	    }

	    void next_step()
	    {
		    step_count++;
	    }

	    void start_app();
	
	    void stop_app();
};

#endif