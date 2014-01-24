#include "gui.h"

//Constructor
GUI::GUI(){
            
    PetriNet =  new PetriNetworksApp();

    //Add some elements, just for testing
    int p1 = PetriNet->addPlace(200,200);
    int t1 = PetriNet->addTransition(300,200);
    PetriNet->addPlaceTransitionArc(p1, t1);
}

//Init function to start FLTK
void GUI::init(){
			
	win = new Fl_Window ( 800,600,"Polygons" );
	win->begin();
		canvas = new Drawable (300, 0, 500, 600);

        //Add point to polygon
        Point sidebarPos(0,0);
        sidebar = new  Fl_Group (sidebarPos.getX(),sidebarPos.getY(),300,600);
                    
    		addPlaceButton = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 10, 280, 50, "Add new &place!" );
            addTransitionButton = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 70, 280, 50, "Add new &transition!" );
               
            sidebar->end();
	win->end();

    //Bind callbacks
    addTransitionButton->callback(addPlaceCallback, this);
	addPlaceButton->callback(addTransitionCallback, this);


    //Styling
    canvas->box(FL_DOWN_BOX);
    sidebar->box(FL_UP_BOX);
	canvas->color(fl_rgb_color(150,190,235));
    win->resizable(canvas);

	//Buffer window
	Fl::visual(FL_DOUBLE|FL_INDEX);
	win->show();
					
	Fl::run();

}