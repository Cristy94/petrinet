#ifndef __SERIALIZATION_H_
#define __SERIALIZATION_H_
#include "PetriNetworksApp.h"
#include <iostream>
#include <cstdio>
#include <string>


class Serialization : public PetriNetworksApp
{
public:
	Serialization(){
		freopen("PetriNetworks.txt", "r", stdin);
		freopen("PetriNetworks.txt", "w", stdout);
	}
	void saveNetwork() 
	{
		cout << getPlaces()->size() << " " << getTransitions()->size() << " " << getArcs()->size() << endl;	// places, transitions, arcs
		

		// serialize position and tokens of every place
		for(int i = 0; i < getPlaces()->size(); ++i)
		{
			// position
			cout << places->at(i)->getPosition()->getX() << endl;
			cout << places->at(i)->getPosition()->getY() << endl;

			cout << places->at(i)->getTokenCount() << endl;

			// tokens state for each place
			for(int j = 0; j < places->at(i)->getTokenCount(); ++i)
			{
				cout << places->at(i)->tokens->at(j)->getState() << endl;
			}
		}

		// serialize position and tokens of every transition
		for(int i = 0; i < getTransitions()->size(); ++i)
		{
			// position
			cout << transitions->at(i)->getPosition()->getX() << endl;
			cout << transitions->at(i)->getPosition()->getY() << endl;

			cout << transitions->at(i)->getTokenCount() << endl;

			// tokens state for each transition
			for(int j = 0; j < transitions->at(i)->getTokenCount(); ++j)
			{
				cout << transitions->at(i)->tokens->at(j)->getState() << endl;
			}
		}

		// serialize position and tokens of every arc, we must serialize source and destination
		for(int i = 0; i < getArcs()->size(); ++i)
		{
			// position
			cout << arcs->at(i)->source->getPosition()->getX() << endl;
			cout << arcs->at(i)->source->getPosition()->getY() << endl;

			cout << arcs->at(i)->destination->getPosition()->getX() << endl;
			cout << arcs->at(i)->destination->getPosition()->getY() << endl;

			cout << arcs->at(i)->destination->getTokenCount() << endl;
			cout << arcs->at(i)->source->getTokenCount() << endl;

			// tokens state for each arc(source and destination)	
			for(int j = 0; j < arcs->at(i)->source->getTokenCount(); ++j)
			{
				cout << arcs->at(i)->source->tokens->at(j)->getState() << endl;
			}

			for(int j = 0; j < arcs->at(i)->destination->getTokenCount(); ++j)
			{
				cout << arcs->at(i)->destination->tokens->at(j)->getState() << endl;
			}
		}
	}

	void loadNetwork()
	{
		int arcsSize, placesSize, transitionsSize, x, y, state, tokensCount, xSource, ySource, xDestination, yDestination, tokensSource, tokensDestination;
		bool stateSource, stateDestination;

		cin >> placesSize >> transitionsSize >> arcsSize;

		for(int i = 0; i < placesSize; ++i)
		{
			// position
			cin >> x >> y;
			cin >> tokensCount;

			places->at(i)->position->setX(x);
			places->at(i)->position->setY(y);

			// tokens state for each place
			for(int j = 0; j < tokensCount; ++i)
			{
				cin >> state;
				places->at(i)->tokens->at(j)->setState(state);
			}
		}

		for(int i = 0; i < transitionsSize; ++i)
		{
			// position
			cin >> x >> y;
			cin >> tokensCount;

			transitions->at(i)->position->setX(x);
			transitions->at(i)->position->setY(y);

			// tokens state for each transitions
			for(int j = 0; j < tokensCount; ++j)
			{
				cin >> state;
				transitions->at(i)->tokens->at(j)->setState(state);
			}
		}

		// serialize position and tokens of every arc, we must serialize source and destination
		for(int i = 0; i < arcsSize; ++i)
		{
			// position
			cin >> xSource >> ySource >> xDestination >> yDestination;
			cin >> tokensDestination >> tokensSource;
			// position
			arcs->at(i)->source->position->setX(xSource);
			arcs->at(i)->source->position->setY(ySource);

			arcs->at(i)->destination->position->setX(xDestination);
			arcs->at(i)->destination->position->setY(yDestination);

			arcs->at(i)->destination->tokens->resize(tokensDestination);
			arcs->at(i)->source->tokens->resize(tokensSource);

			// tokens state for each arc(source and destination)	
			for(int j = 0; j < tokensSource; ++j)
			{
				cin >> stateSource;

				arcs->at(i)->source->tokens->at(j)->setState(stateSource);
			}

			for(int j = 0; j < tokensDestination; ++j)
			{
				cin >> stateDestination;

				arcs->at(i)->destination->tokens->at(j)->setState(stateDestination);
			}
		}
	}
};
#endif