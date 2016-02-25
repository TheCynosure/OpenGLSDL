/*
 * Window.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Jack
 */

#ifndef VIDEO_WINDOW_H_
#define VIDEO_WINDOW_H_

namespace glsdl {

class Window {
public:
	Window();
	virtual ~Window();
	static const int WIDTH = 640;
	static const int HEIGHT = 480;
	void gl_update();
	void quit();
private:
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_GLContext context;
	void init_sdl();
	void init_gl();
	void create_window();
	void create_surface();
	SDL_Surface* get_surface();
};

} /* namespace glsdl */

#endif /* VIDEO_WINDOW_H_ */
