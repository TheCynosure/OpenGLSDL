/*
 * Main.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Jack
 */

#include <SDL/SDL.h>
#include <iostream>

#include "Handlers/EventManager.h"
#include "Video/Window.h"

int main(int argc, char* args[]) {
	bool quit = false;

	glsdl::Window window;
	glsdl::EventManager event_manager(&window);

	while(!quit) {
		if(event_manager.process_events() > 0) {
			quit = true;
		}
		//Drawing
		window.gl_update();
	}
	return 0;
}



