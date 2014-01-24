#ifndef __GUI_H__
#define __GUI_H__

#include <cstdlib>
#include <string>

#include "drawable.h"
#include "PetriNetworksApp.h"


//Manages the creation, display and editing of FLTK elements
class GUI {
	private: 
		
        //GUI elements
        Fl_Window *win;
		Drawable *canvas;

        Fl_Button *addTransitionButton;
        Fl_Button *addPlaceButton;
        Fl_Button *addArcButton;

        Fl_Group *sidebar;
        PetriNetworksApp *PetriNet;

        //Adds a new transition to the network
		static void addTransitionCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->addTransition();
		}
        
        //Non-static real callback
		void addTransition(){
            //Ask user for coordinates, convert them to int
            std::string answ = fl_input("Position? (space separated)", "100 100");
            int x = atoi( answ.substr(0, answ.find(" ")).c_str() );
            int y = atoi( answ.substr(answ.find(" ")).c_str() );

            PetriNet->addTransition(x, y);
        }


        //Adds a new place to the network
		static void addPlaceCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->addPlace();
		}
        
        //Non-static real callback
		void addPlace(){
            //Ask user for coordinates, convert them to int
            std::string answ = fl_input("Position? (space separated)", "100 100");
            int x = atoi( answ.substr(0, answ.find(" ")).c_str() );
            int y = atoi( answ.substr(answ.find(" ")).c_str() );

            PetriNet->addPlace(x, y);
        }


	public:

        //This GUI is specific for the PetriNet
		GUI();

        //Init function to start FLTK
		void init();
};

#endif