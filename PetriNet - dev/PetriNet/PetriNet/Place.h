#ifndef __PLACE_H_
#define __PLACE_H_
#include "Token.h"
#include "Position.h"
#include <vector> 
#include "IElement.h"
#include "Arc.h"

class Place : IElement
{
	vector<Token*> *tokens;
	vector<Arcs*> *in_arcs;
	vector<Arcs*> *out_arcs;

public:
	Place()
	{
		this->position = NULL;
		this->tokens = new vector<Token*>();
		this->in_arcs = new vector<Arcs*>();
		this->out_arcs = new vector<Arcs*>();
	}

	Place(Position *position)
	{
		this->position = position;
		this->in_arcs = new vector<Arcs*>();
		this->out_arcs = new vector<Arcs*>();
	}

	void setNumberOfTokens(int number)
	{
		tokens->resize(number);
	}
};

#endif
	