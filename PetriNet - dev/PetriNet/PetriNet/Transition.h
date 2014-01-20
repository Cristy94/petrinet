#ifndef __TRANSITION_H_
#define __TRANSITION_H_
#include <vector>
#include "Token.h"
#include "Position.h"
#include <vector> 
#include "IElement.h"
#include "Arc.h"

using namespace std;

class Transition
{
	Position *position;
	vector<Token*> *tokens;
	vector<Arcs*> *in_arcs;
	vector<Arcs*> *out_arcs;
	IElement *source;
	IElement *destination;
	int step_count;
	

public:
	Transition() 
	{
		source = NULL;
		destination = NULL;
		tokens = NULL;
		in_arcs = NULL;
		out_arcs = NULL;
		position = NULL;
	}

	Transition(IElement *source, IElement *destination)
	{
		this->source = source;
		this->destination = destination;
		this->step_count = 0;
		this->position = new Position();
		this->tokens = new vector<Token*>();
		this->in_arcs = new vector<Arcs*>();
		this->out_arcs = new vector<Arcs*>();
	}

	void next_step()
	{
		step_count++;
	}
};

#endif
	