#ifndef __GUI_H__
#define __GUI_H__

#include <cstdlib>
#include <string>

#include "drawable.h"


//Manages the creation, display and editing of FLTK elements
class GUI {
	private: 
		
        //GUI elements
        Fl_Window *win;
		Drawable *canvas;
        Fl_Button *addButton;
        Fl_Group *sidebar;

        //Example of a static facade callback
		static void exampleCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->example();
		}
        
        //Non-static real callback
		void example(){
            
		}


	public:

		GUI(){

		}

        //Init function to start FLTK
		void init(){
			
			win = new Fl_Window ( 800,600,"Polygons" );
			win->begin();
				canvas = new Drawable (300, 0, 500, 600);

                //Add point to polygon
                Point sidebarPos(0,0);
                sidebar = new  Fl_Group (sidebarPos.x,sidebarPos.y,300,600);
                    
    				addButton = new Fl_Button (sidebarPos.x+ 10, sidebarPos.y + 10, 280, 50, "&Hello world!" );
               
                    sidebar->end();
			win->end();

            //Bind callbacks
			addButton->callback(  exampleCallback, this);


            //Styling
            canvas->box(FL_PLASTIC_DOWN_BOX);
            sidebar->box(FL_UP_BOX);
			canvas->color(FL_RED);
            win->resizable(canvas);

			//Buffer window
			Fl::visual(FL_DOUBLE|FL_INDEX);
			win->show();
					
			Fl::run();

		}
};

#endif