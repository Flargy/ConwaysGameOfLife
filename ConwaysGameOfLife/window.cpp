#include "window.h"

Window::Window(const std::string& title, int width, int height) :
	_title(title), _width(width), _height(height) 
{

	_closed = !Init();
}

Window::~Window() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Window::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);

	if (_window == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (_renderer == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	return true;

}

void Window::RenderAndPresent() {

	SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);
	SDL_RenderClear(_renderer);

	SDL_Rect rect;
	rect.w = 10;
	rect.h = 10;
	rect.x = _width / 2 - 5;
	rect.y = _height / 2 - 5;
	SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
	SDL_RenderFillRect(_renderer, &rect);
	

	SDL_Rect rect2;
	rect2.w = 10;
	rect2.h = 10;
	rect2.x = _width / 2 + 5;
	rect2.y = _height / 2 + 5;
	SDL_SetRenderDrawColor(_renderer, 0, 200, 200, 255);
	SDL_RenderFillRect(_renderer, &rect2);
	SDL_RenderPresent(_renderer);
}


void Window::PollEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			_closed = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				_closed = true;
				break;
			default:
				break;
			}

		default:
			break;
		}
	}
}
