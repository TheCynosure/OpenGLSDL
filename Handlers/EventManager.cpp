/*
 * EventManager.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Jack
 */

#include <SDL/SDL.h>
#include "EventManager.h"

namespace glsdl {

int EventManager::process_events() {
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				window->quit();
				return 1; //One case it will return 1 to signal a quit.
		}
	}
	return 0;
}

EventManager::~EventManager() {
	// TODO Auto-generated destructor stub
}

} /* namespace glsdl */
