#include <memory>
#include <map>
#include <algorithm>
#include <chrono>
#include "global.h"
#include "window.h"


Window window("Conway's game of life", 750, 750);
GridManager manager(25, 25, &window, 30);

int main(int args, char** argv) {
	
	//manager.DebugGrid();
	manager.CreateConnections(); // this works now. had weird problems with pointers and references

	using namespace std::chrono;
	bool quit = false;
	bool play = false;
	double t = 0.0;
	double dt = 1.0 / 5.0;
	double accumulator = 0.0;
	steady_clock::time_point currentTime = steady_clock::now();


	while (!window.IsClosed()) {

		steady_clock::time_point newTime = steady_clock::now();
		double frameTime = duration_cast<duration<double>>(newTime - currentTime).count();
		currentTime = newTime;

		accumulator += frameTime;
		window.SetBackground();
		if (window.PollEvents()) {
			play = !play;
		}

		while (accumulator >= dt) {// TODO: draw each cell in an effective way. update the cells
			//Do physics here (based on t i think?)

			t += dt;
			accumulator -= dt;
			if (play == true) {
				manager.CheckStatus();
				manager.UpdateStatus();
			}
		}
			manager.DrawCells();
			window.PresentRenderer();

	}

	return 0;
}