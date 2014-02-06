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
            addArcButton            = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 130, 135, 50, "Add &arc!" );
           
            removeArcButton         = new Fl_Button (sidebarPos.getX()+ 155, sidebarPos.getY() + 130, 135, 50, "&Remove arc!");
                
            removeElementButton     = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 190, 135, 50, "Remove &element!" );            
            setTokensButton         = new Fl_Button (sidebarPos.getX()+ 155, sidebarPos.getY() + 190, 135, 50, "Set &tokens!" );            

            advanceSimulationButton = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 250, 280, 50, "A&dvance simulation!" );            

            startSimulationButton   = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 310, 135, 50, "Start sim&ulation!" );            
            stopSimulationButton    = new Fl_Button (sidebarPos.getX()+ 155, sidebarPos.getY() + 310, 135, 50, "Stop simula&tion!" );            
            
            help                    = new Fl_Text_Display(sidebarPos.getX()+ 10, sidebarPos.getY() + 400, 280, 90, "Help" );
            saveNetworkButton       = new Fl_Button (sidebarPos.getX()+ 10, sidebarPos.getY() + 350 + 190, 135, 50, "&Save network!" );
            loadNetworkButton       = new Fl_Button (sidebarPos.getX()+ 155, sidebarPos.getY() + 350 + 190, 135, 50, "&Load network!" );

            sidebar->end();
	win->end();

    //Bind callbacks
    addPlaceButton->callback(addPlaceCallback, this);
	addTransitionButton->callback(addTransitionCallback, this);
    addArcButton->callback(addArcCallback, this);
    removeArcButton->callback(removeArcCallback, this);
    removeElementButton->callback(removeElementCallback, this);
    startSimulationButton->callback(startSimulationCallback, this);
    stopSimulationButton->callback(stopSimulationCallback, this);

    setTokensButton->callback(setTokensCallback, this);

    advanceSimulationButton->callback(advanceSimulationCallback, this);

    saveNetworkButton->callback(saveNetworkCallback, this);
    loadNetworkButton->callback(loadNetworkCallback, this);

    //Help messages
    helpBuff = new Fl_Text_Buffer();
    help->buffer(helpBuff);

    helpBuff->text("\n-> Click an element to select it\n"
                   "-> Right-click + drag to move an element\n"
                   "-> An arc can be added between last two \nselected elements");

    //Styling
    help->box(FL_FLAT_BOX);
    help->color(FL_GRAY);
    canvas->box(FL_DOWN_BOX);
    sidebar->box(FL_UP_BOX);
	canvas->color(FL_WHITE);
    win->resizable(canvas);

	//Buffer window
	Fl::visual(FL_DOUBLE|FL_INDEX);
	win->show();
					
	Fl::run();
}