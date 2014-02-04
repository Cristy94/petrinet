#ifndef __GUI_H__
#define __GUI_H__

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600

#include <cstdlib>
#include <string>

#include "drawable.h"
#include "Serialization.h"


//Manages the creation, display and editing of FLTK elements
class GUI {
	private: 
		
        //GUI elements
        Fl_Window *win;
		Drawable *canvas;

        Fl_Button *addTransitionButton, *addPlaceButton, *addArcButton;
        Fl_Button *advanceSimulationButton;
        Fl_Button *saveNetworkButton, *loadNetworkButton;

        Fl_Group *sidebar;
        Serialization *PetriNet;

        //Adds a new transition to the network
		static void addTransitionCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->addTransition();
		}
        
        //Non-static real callback
		void addTransition(){
             //Ask user for coordinates, convert them to int
            const char *result = fl_input("Position? (space separated)", "100 100");
            
            //If user clicks cancel           
            if(result == NULL)
                return;

            std::string answ = result;
            

            int x = atoi( answ.substr(0, answ.find(" ")).c_str() );
            int y = atoi( answ.substr(answ.find(" ")).c_str() );

            PetriNet->addTransition(x, y);
            canvas->redraw();
        }


        //Adds a new place to the network
		static void addPlaceCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->addPlace();
		}
        
        //Non-static real callback
		void addPlace(){
             //Ask user for coordinates, convert them to int
            const char *result = fl_input("Position? (space separated)", "100 100");
            
            //If user clicks cancel           
            if(result == NULL)
                return;

            std::string answ = result;

            int x = atoi( answ.substr(0, answ.find(" ")).c_str() );
            int y = atoi( answ.substr(answ.find(" ")).c_str() );

            PetriNet->addPlace(x, y);
            canvas->redraw();
        }

        //Calls PetriNets advanceSimulation method
		static void advanceSimulationCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->advanceSimulation();
		}

        void advanceSimulation(){
            PetriNet->advanceSimulation();
            canvas->redraw();
        }
        
        //Save the network to a text file
        static void saveNetworkCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->saveNetwork();
		}

        void saveNetwork(){
            PetriNet->saveNetwork();
        }
        
        //Load the network from a text file
        static void loadNetworkCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->loadNetwork();
		}

        void loadNetwork(){
            PetriNet->loadNetwork();
        }

	public:

        //This GUI is specific for the PetriNet
		GUI();

        //Init function to start FLTK
		void init();
};

#endif