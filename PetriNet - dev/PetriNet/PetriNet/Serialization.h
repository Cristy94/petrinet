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

	}
	void saveNetwork() 
	{
		freopen("PetriNetworks.txt", "w", stdout);
		cout << getPlaces()->size() << " " << getTransitions()->size() << " " << getArcs()->size() << endl;	// places, transitions, arcs
		

		// serialize position and tokens of every place
		for(int i = 0; i < getPlaces()->size(); ++i)
		{
			// position
			cout << places->at(i)->getPosition()->getX() << endl;
			cout << places->at(i)->getPosition()->getY() << endl;

			cout << places->at(i)->getTokenCount() << endl;
		}

		// serialize position and tokens of every transition
		for(int i = 0; i < getTransitions()->size(); ++i)
		{
			// position
			cout << transitions->at(i)->getPosition()->getX() << endl;
			cout << transitions->at(i)->getPosition()->getY() << endl;

			cout << transitions->at(i)->getTokenCount() << endl;

		}

		// serialize position and tokens of every arc, we must serialize source and destination
		for(int i = 0; i < getArcs()->size(); ++i)
		{
			bool isPlaceSource = false;
			bool isPlaceDestination = false;
			for(std::vector<Place*>::iterator it = places->begin(); it != places->end(); ++it)
			{
				if(*it == arcs->at(i)->source)
				{
					cout << "P " << i << endl;
					isPlaceSource = true;
				}
			}
			if(!isPlaceSource)
			{
				for(std::vector<Transition*>::iterator it = transitions->begin(); it != transitions->end(); ++it)
				{
					if(*it == arcs->at(i)->source)
					{
						cout << "T " << i << endl;
					}
				}
			}

			for(std::vector<Place*>::iterator it = places->begin(); it != places->end(); ++it)
			{
				if(*it == arcs->at(i)->destination)
				{
					cout << "P " << i << endl;
					isPlaceDestination = true;
				}
			}
			if(!isPlaceDestination)
			{
				for(std::vector<Transition*>::iterator it = transitions->begin(); it != transitions->end(); ++it)
				{
					if(*it == arcs->at(i)->destination)
					{
						cout << "T " << i << endl;
					}
				}
			}

			cout << arcs->at(i)->destination->getTokenCount() << endl;
			cout << arcs->at(i)->source->getTokenCount() << endl;

		}
	}

	void loadNetwork()
	{
		int arcsSize, placesSize, transitionsSize, x, y, state, tokensCount, xSource, ySource, xDestination, yDestination, tokensSource, tokensDestination;
		bool stateSource, stateDestination;
		freopen("PetriNetworks.txt", "r", stdin);

		cin >> placesSize >> transitionsSize >> arcsSize;

		for(int i = 0; i < placesSize; ++i)
		{
			// position
			cin >> x >> y;
			cin >> tokensCount;

			places->at(i)->position->setX(x);
			places->at(i)->position->setY(y);
			places->at(i)->tokens->resize(tokensCount);
		}

		for(int i = 0; i < transitionsSize; ++i)
		{
			// position
			cin >> x >> y;
			cin >> tokensCount;

			transitions->at(i)->position->setX(x);
			transitions->at(i)->position->setY(y);
			transitions->at(i)->tokens->resize(tokensCount);

		}

		// serialize position and tokens of every arc, we must serialize source and destination
		for(int i = 0; i < arcsSize; ++i)
		{
			char sourceType, destinationType;
			int indexSource, indexDestination;

			cin >> sourceType;
			cin >> indexSource;
			cin >> destinationType;
			cin >> indexDestination;
			cin >> tokensDestination;
			cin >> tokensSource;

			// position
			if(sourceType == 'P')
				arcs->at(i)->source = places->at(indexSource);
			else
				arcs->at(i)->source = transitions->at(indexSource);

			if(destinationType == 'P')
				arcs->at(i)->destination = places->at(indexDestination);
			else
				arcs->at(i)->destination = transitions->at(indexDestination);

			arcs->at(i)->destination->tokens->resize(tokensDestination);
			arcs->at(i)->source->tokens->resize(tokensSource);
		}
	}
};
#endif