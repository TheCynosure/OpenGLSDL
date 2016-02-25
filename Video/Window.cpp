/*
 * Window.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Jack
 */

#include <iostream>
#include <GL/gl.h>
#include <SDL/SDL.h>
#include <stdlib.h>

#include "Window.h"

namespace glsdl {

Window::Window() {
	// TODO Auto-generated constructor stub
	init_sdl();
	create_window();
	init_gl();
	create_surface();
}

Window::~Window() {
	// TODO Auto-generated destructor stub
	quit();
}

/*
 * Initialization Methods Below
 */
void Window::init_sdl() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}
	std::cout << "SDL Initialized" << std::endl;
}

void Window::create_window() {
	window = SDL_CreateWindow("OpenGLSDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if(window == NULL) {
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(2);
	}
	std::cout << "Window Created Successfully" << std::endl;
}

void Window::init_gl() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);
	if(context == NULL) {
		std::cout << "OpenGL Failed: " << glGetError() << std::endl;
	}
}

void Window::create_surface() {
	surface = SDL_GetWindowSurface(window);
	if(surface == NULL) {
		std::cout << "Could not get Surface: " << SDL_GetError() << std::endl;
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(3);
	}
	std::cout << "Surface Obtained Successfully" << std::endl;
}

void Window::gl_update() {
	glClearColor(rand()*1.0/RAND_MAX,rand()*1.0/RAND_MAX,rand()*1.0/RAND_MAX, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
}

/*
 * Getters and Setters
 */

SDL_Surface* Window::get_surface() {
	return surface;
}

/*
 * Destructor Methods
 */
void Window::quit() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_FreeSurface(surface);
	SDL_Quit();
	exit(0);
}

} /* namespace glsdl */
