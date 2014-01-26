#ifndef __SERIALIZATION_H_
#define __SERIALIZATION_H_
#include "PetriNetworksApp.h"
#include <iostream>
#include <cstdio>
#include <string>


class Serialization : PetriNetworksApp
{

	Serialization(){
		freopen("PetriNetworks.txt", "r", stdin);
		freopen("PetriNetworks.txt", "w", stdout);
	}
	void saveNetwork() 
	{
		cout << "P " << getArcs()->size() << " T " << getTransitions()->size() << " A " << getArcs()->size() << endl;
		
	}

	void loadNetwork()
	{
	}
};
#endif