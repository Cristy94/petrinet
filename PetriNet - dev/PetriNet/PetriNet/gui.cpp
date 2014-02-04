#include "gui.h"

//Constructor
GUI::GUI(){
            
    PetriNet =  new Serialization();

    //Add some elements, just for testing
    int p1 = PetriNet->addPlace(200,200);
    int t1 = PetriNet->addTransition(300,200);
    PetriNet->addPlaceTransitionArc(p1, t1);
    (*(PetriNet->arcs->begin()))->source->setNumberOfTokens(10);
}

//Init function to start FLTK
void GUI::init(){
			
	win = new Fl_Window ( WINDOW_WIDTH, WINDOW_HEIGHT, "Polygons" );
	win->begin();
		canvas = new Drawable (PetriNet, 300, 0, WINDOW_WIDTH - 300, 600);

        //Add point to polygon
        Point sidebarPos(0,0);
        sidebar = new  Fl_Group (sidebarPos.getX(),sidebarPos.getY(),300,600);
                    
    		addPlaceButton          = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 10, 280, 50, "Add new &place!" );
            addTransitionButton     = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 70, 280, 50, "Add new &transition!" );
            advanceSimulationButton = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 130, 280, 50, "&Advance simulation!" );
            
            
            saveNetworkButton       = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 350 + 190, 135, 50, "&Save network!" );
            loadNetworkButton       = new Fl_Button (sidebarPos.getX()+ 155, sidebarPos.getY() + 350 + 190, 135, 50, "&Load network!" );

            sidebar->end();
	win->end();

    //Bind callbacks
    addPlaceButton->callback(addPlaceCallback, this);
	addTransitionButton->callback(addTransitionCallback, this);
    advanceSimulationButton->callback(advanceSimulationCallback, this);
    saveNetworkButton->callback(saveNetworkCallback, this);
    loadNetworkButton->callback(loadNetworkCallback, this);

    //Styling
    canvas->box(FL_DOWN_BOX);
    sidebar->box(FL_UP_BOX);
	canvas->color(FL_WHITE);
    win->resizable(canvas);

	//Buffer window
	Fl::visual(FL_DOUBLE|FL_INDEX);
	win->show();
					
	Fl::run();

}