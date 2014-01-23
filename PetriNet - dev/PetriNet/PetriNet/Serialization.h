#ifndef __SERIALIZATION_H_
#define __SERIALIZATION_H_
#include "PetriNetworksApp.h"
#include <fstream>
#include <file/text_iarchive.hpp>
#include <file/text_oarchive.hpp>


class Serialization : PetriNetworksApp
{
	const char* fileName = "PetriNetworks.txt";

	void saveNetwork() 
	{
		ofstream ofs(fileName);
		text_oarchive ar(ofs);

		// save data
		ar & getArcs & getTransitions & getPlaces;
	}

	void loadNetwork()
	{
		ifstream ifs(fileName);
		text_oarchive ar(ifs);
	
		// load data
		ar & setArcs & setTransitions & setPlaces;
	}
};

#endif