#ifndef __IELEMENT_H_
#define __IELEMENT_H_
#include <vector>

#include "Token.h"
#include "point.h"

using namespace std;

//Base class for PetriNet elements: Places and Transitions
class IElement {

    public: 
	    Point *position;
        vector<Token*> *tokens;	

    public:

        bool selected;

	    IElement()
	    {
		    position = new Point();
            selected = 0;
	    }

	   	void setNumberOfTokens(int number)
	    {
		    tokens->resize(number);
	    }
	
        //Sets top-left position of the element
	    void setPosition(int x, int y)
	    {
		    position->setX(x);
		    position->setY(y);
	    }

		Point *getPosition()
		{
			return this->position;
		}

        bool hasTokens(){
            return tokens->size() > 0;
        }

        void addToken(){
            tokens->push_back(new Token());
        }

        void removeToken(){
            tokens->pop_back();
        }

        int getTokenCount(){
            return tokens->size();
        }

        void makeNthTokenActive(int idx){
            int i = 1;
            for(vector<Token*>::iterator it = tokens->begin(); it != tokens->end(); ++it, ++i){
                if(idx  == i){
                    (*it)->activate();
                    break;
                }
            }
        }

        void deactivateAllTokens(){

             for(vector<Token*>::iterator it = tokens->begin(); it != tokens->end(); ++it){
                    (*it)->deactivate();
             }
                            
        }

        virtual Point* centerPosition() = 0;
};


#endif 