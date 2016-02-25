/*
 * EventManager.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Jack
 */

#ifndef HANDLERS_EVENTMANAGER_H_
#define HANDLERS_EVENTMANAGER_H_

#include <SDL/SDL.h>
#include "../Video/Window.h"

namespace glsdl {

class EventManager {
public:
	EventManager(Window* window): window(window) {};
	virtual ~EventManager();
	int process_events();
private:
	SDL_Event event;
	Window* window;
};

} /* namespace glsdl */

#endif /* HANDLERS_EVENTMANAGER_H_ */
