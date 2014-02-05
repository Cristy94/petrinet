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
        Fl_Button *removeArcButton, *removeElementButton;
        Fl_Button *setTokensButton;
        Fl_Button *advanceSimulationButton;
        Fl_Button *startSimulationButton, *stopSimulationButton;
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

        //Adds a arc between selected elements
		static void addArcCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->addArc();
		}
        
        //Non-static real callback
		void addArc(){

            try {
                
                if(PetriNet->selected.size() < 2)
                    throw std::string("Invalid elements selected");
                
                //Bipartite arcs
                bool ok = 0;

                try {
                    //Place -> Transition
                    if(Place* a = dynamic_cast< Place* >(PetriNet->selected.at(0)))
                        if(Transition* b = dynamic_cast< Transition* >(PetriNet->selected.at(1)))
                            ok = 1;

                    //Transition -> Place
                    if(Place* a = dynamic_cast< Place* >(PetriNet->selected.at(1)))
                        if(Transition* b = dynamic_cast< Transition* >(PetriNet->selected.at(0)))
                            ok = 1;
                }
                catch (std::exception e){}

                if(!ok){
                    throw std::string("Invalid elements selected");
                }

                PetriNet->addArc(PetriNet->selected.at(0), PetriNet->selected.at(1));
                
                canvas->redraw();                
            }
            catch(std::string e) {
                fl_alert(e.c_str());
            }
        }

        //Remove arc between selected elements
		static void removeArcCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->removeArc();
		}
        
        //Non-static real callback
		void removeArc(){

            try {
                
                if(PetriNet->selected.size() < 2)
                    throw std::string("Invalid elements selected");

                PetriNet->removeArc(PetriNet->selected.at(0), PetriNet->selected.at(1));
                
                canvas->redraw();                
            }
            catch(std::string e) {
                fl_alert(e.c_str());
            }
        }

        //Remove selected element
		static void removeElementCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->removeElement();
		}
        
        //Non-static real callback
		void removeElement(){

            try {
                
                if(PetriNet->selected.size() < 1)
                    throw std::string("Invalid elements selected");

                PetriNet->removeElement(PetriNet->selected.back());
                
                canvas->redraw();                
            }
            catch(std::string e) {
                fl_alert(e.c_str());
            }
        }


        //Sets int number of tokens for selected element
		static void setTokensCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->setTokens();
		}
        
        //Non-static real callback
		void setTokens(){
             //Ask user for coordinates, convert them to int
            const char *result = fl_input("Number", "1");
            
            //If user clicks cancel           
            if(result == NULL)
                return;

            std::string answ = result;
            

            int x = atoi( answ.c_str() );

            try {
                
                if(PetriNet->selected.size() < 1)
                    throw std::string("Invalid elements selected");

                PetriNet->setTokens(PetriNet->selected.back(), x);
                
                canvas->redraw();                
            }
            catch(std::string e) {
                fl_alert(e.c_str());
            }
        }


        //Calls PetriNets advanceSimulation method
		static void advanceSimulationCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->advanceSimulation();
		}

        void advanceSimulation(){
            PetriNet->advanceSimulation();
            canvas->redraw();
        }

        //Auto advance every 0.5s
		static void startSimulationCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->startSimulation();
		}

        static void startSimulationTimeout(void* data){
            ((GUI*) data)-> startSimulation();
        }

        void startSimulation(){
            PetriNet->advanceSimulation();
            canvas->redraw();
            Fl::add_timeout(0.5, startSimulationTimeout, this);
        }
        
        //Stop autoplay
        static void stopSimulationCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->stopSimulation();
		}

        void stopSimulation(){
            Fl::remove_timeout(startSimulationTimeout);
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
            canvas->redraw();
        }

	public:

        //This GUI is specific for the PetriNet
		GUI();

        //Init function to start FLTK
		void init();
};

#endif