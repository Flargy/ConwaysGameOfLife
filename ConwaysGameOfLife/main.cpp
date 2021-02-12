#include <memory>
#include <map>
#include <algorithm>
#include "window.h"
#include <chrono>
#include "gridManager.h"

int main(int args, char** argv) {
	
	Window window("Conway's game of life", 800, 600);
	GridManager manager(10, 10);
	manager.DebugGrid();

	using namespace std::chrono;
	bool quit = false;
	double t = 0.0;
	double dt = 1.0 / 2.0;
	double accumulator = 0.0;
	steady_clock::time_point currentTime = steady_clock::now();


	while (!window.IsClosed()) {

		steady_clock::time_point newTime = steady_clock::now();
		double frameTime = duration_cast<duration<double>>(newTime - currentTime).count();
		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= dt) {// TODO: draw each cell in an effective way. update the cells
			//Do physics here (based on t i think?)

			t += dt;
			accumulator -= dt;
			window.PollEvents();

		}

		window.RenderAndPresent();
	}

	return 0;
}