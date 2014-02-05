#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_draw.H>
#include <FL/Fl_Browser.H>
#include <FL/fl_ask.H>

#include "PetriNetworksApp.h"



class Drawable : public Fl_Box{

	private:
        PetriNetworksApp* PetriNet;
        bool mouseDown;

	public:

        //Constructor. We also need a pointer to the network
		Drawable(PetriNetworksApp *Network, int X,int Y,int W,int H,const char*L=0)
                    :Fl_Box(X,Y,W,H,L), PetriNet(Network){
            mouseDown = false;
        }

		void draw();
        int handle(int event);
};

#endif