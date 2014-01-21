#ifndef __PETRINETWORKS_H_
#define __PETRINETWORKS_H_

#include "IElement.h"
#include "Arc.h"
#include "Place.h"
#include "Transition.h"

class PetriNetworksApp : IEdit
{
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

	void addPlace(Place *place)
	{
		this->places->push_back(place);
	}

	void addTransition(Transition *transition)
	{
		this->transitions->push_back(transition);
	}

	void addArc(Arcs *arc)
	{
		this->arcs->push_back(arc);
	}

	void next_step()
	{
		step_count++;
	}

	void start_app();
	
	void stop_app();
}
;

#endif