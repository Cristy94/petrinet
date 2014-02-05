#include <iostream>
#include <cmath>

#define TOKEN_RADIUS 7

#include "drawable.h"

//Helper function to draw different objects
void Drawable::draw(){

    Fl_Box::draw();


    //Draw places
    for(vector <Place*>::iterator it = PetriNet->places->begin(); it != PetriNet->places->end(); ++it){
        
        //Draw stroke
        fl_color(fl_rgb_color(110,110,110));
        //Red stroke color if element is selected
        if( (*it)->selected )
            fl_color(fl_rgb_color(255,110,110));
        fl_pie(x() + (*it)->position->getX(), y() + (*it)->position->getY(), (*it)->radius,(*it)->radius, 0, 360);

        //Draw filled shape
        fl_color(fl_rgb_color(200,200,200));
        fl_pie(x() + (*it)->position->getX() + 2, y() + (*it)->position->getY() + 2, (*it)->radius - 4,(*it)->radius - 4, 0, 360);

        //Draw tokens
        fl_color(FL_BLACK);
        int nrTokens = (*it)->tokens->size();
        Point *p =  new Point((*it)->centerPosition());

        //When there's only one token, display in center
        if(nrTokens == 1){
            fl_pie(x() + p->getX()- TOKEN_RADIUS , y() + p->getY() - TOKEN_RADIUS , TOKEN_RADIUS * 2, TOKEN_RADIUS * 2, 0, 360);
        }
        //Else display them 360 degrees
        else {
            for(int i = 0; i < nrTokens; ++i){
                   
                double step = (double)i/nrTokens * 3.14 * 2;

                int X = p->getX() + ((*it)->radius-TOKEN_RADIUS*2)/2 * cos(step);
                int Y = p->getY() + ((*it)->radius-TOKEN_RADIUS*2)/2 * sin(step);
            
                fl_pie(x() + X - TOKEN_RADIUS , y() + Y - TOKEN_RADIUS , TOKEN_RADIUS * 2, TOKEN_RADIUS * 2, 0, 360);
            }
        }
    }

    //Draw transitions
    for(vector <Transition*>::iterator it = PetriNet->transitions->begin(); it != PetriNet->transitions->end(); ++it){
        
        //Draw stroke
        fl_color(fl_rgb_color(110,110,110));
        //Red stroke color if element is selected
        if( (*it)->selected )
            fl_color(fl_rgb_color(255,110,110));
        fl_rectf(x() + (*it)->position->getX(), y() + (*it)->position->getY(), (*it)->width,(*it)->height);

        //Draw filled shape
        fl_color(fl_rgb_color(200,200,200));
        //If transition active
        int nrTokens = (*it)->tokens->size();
        if(nrTokens >= 1)
            fl_color(fl_rgb_color(255,110,110));
        fl_rectf(x() + (*it)->position->getX() + 2, y() + (*it)->position->getY() + 2, (*it)->width - 4,(*it)->height - 4);


    }

    //Draw arcs
    for(vector <Arcs*>::iterator it = PetriNet->arcs->begin(); it != PetriNet->arcs->end(); ++it){

        //Draw the line
        fl_color(fl_rgb_color(110,110,110));
        fl_line_style(FL_JOIN_MITER, 3);
        fl_line(x() + (*it)->startPosition()->getX(), y() + (*it)->startPosition()->getY(),
                x() + (*it)->endPosition()->getX(), y() + (*it)->endPosition()->getY());

        //Draw the oriented arrow
        fl_pie(x() + (*it)->endPosition()->getX() - 3, y() + (*it)->endPosition()->getY() - 3, 6, 6, 0, 360);
    }
}

//Bind click events
int Drawable::handle(int event){
    switch(event){

        case FL_PUSH:
            PetriNet->selectElement(Fl::event_x() - x() ,Fl::event_y() - y());   
               if(Fl::event_button() == FL_RIGHT_MOUSE){
                mouseDown = true;
            }
        break;

        case FL_RELEASE:            
            if(Fl::event_button() == FL_RIGHT_MOUSE){
                mouseDown = false;
            }
        break;

        case FL_DRAG:
            if(mouseDown){
                PetriNet->moveSelected(Fl::event_x() - x() ,Fl::event_y() - y());  
            }
        break;
        default:
            return Fl_Box::handle(event);

    }

    redraw();
}