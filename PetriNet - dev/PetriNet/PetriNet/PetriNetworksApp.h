#ifndef __PETRINETWORKS_H_
#define __PETRINETWORKS_H_

#include <queue>

#include "IElement.h"
#include "Arc.h"
#include "Place.h"
#include "Transition.h"

class PetriNetworksApp {
    private:
	    vector<Arcs*> *arcs;
	    vector<Place*> *places;
	    vector<Transition*> *transitions;

        std::deque <IElement*> selected;

	    int step_count;

    public:
	    PetriNetworksApp();

		// Allow required classes to access non-public data members.
		friend class Serialization;
        friend class GUI;
        friend class Drawable;
        
        //Creates and adds a new place to the network
        //Returns the index
	    int addPlace(int x, int y)
	    {
			if(x < 0 || y < 0)
			    throw std::string("Invalid coordinates");

			Place *newPlace = new Place(new Point(x,y));
			places->push_back(newPlace);

			return places->size() - 1;
	    }

        //Creates and adds a new transition to the network
        //Returns the index
	    int addTransition(int x, int y)
	    {
			if(x < 0 || y < 0)
			    throw std::string("Invalid coordinates");
                
		    Transition *newTransition = new Transition(new Point(x,y));
		    transitions->push_back(newTransition);

		    return transitions->size() - 1;
			
	    }


	    void addPlaceTransitionArc(unsigned int placeIdx, unsigned int transitionIdx)
	    {      
			if(placeIdx >= 0 && transitionIdx >= 0)
			{
				Arcs *newArc = new Arcs(places->at(placeIdx), transitions->at(transitionIdx));
				arcs->push_back(newArc);
			}
	    }

        void addArc(IElement *source, IElement *destination){

                Arcs *newArc = new Arcs(source, destination);
                arcs->push_back(newArc);
        }

        void removeArc(IElement *source, IElement *destination){
            for(std::vector<Arcs*>::iterator it = arcs->begin(); it != arcs->end(); ++it){
                if( (*it)->source == source && (*it)->destination == destination ){
                    arcs->erase(it);
                    return;
                }
            }
        }

	    void start_app();
	
	    void stop_app();

	    template<typename Archive>
	    void serialize(Archive& ar, const unsigned version) 
		{
			ar & arcs & places & transitions;  // Simply serialize the data members of Obj
		}

		// properties used for serialization
		vector<Arcs*> *getArcs()
		{
			return arcs;
		}

		vector<Place*> *getPlaces()
		{
			return places;
		}

		vector<Transition*> *getTransitions()
		{
			return transitions;
		}

		void setArcs(vector<Arcs*>  *arcs)
		{
			this->arcs = arcs;
		}

		void setPlaces(vector<Place*> *places)
		{
			this->places = places;
		}

		void setTransitions(vector<Transition*> *transitions)
		{
			this->transitions = transitions;
		}

        void setTokens(IElement *el, int nrTokens){
            el->setNumberOfTokens(nrTokens);
        }

        int advanceSimulation();

        //Select the element closed to the click
        void selectElement(int x, int y);

        //Remove last selected element
        void removeElement(IElement *el);

        //Move last selected element
        void moveSelected(int x, int y);
};

#endif