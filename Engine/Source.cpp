/*
MIT License

Copyright (c) 2018 Ben Brown

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <vector>
#include <SDL2/SDL.h>

#include "Renderer.hpp"

int main(int argc, char** argv) {
	std::vector<const char*> args;
	args.insert(args.begin(), argv, argv + argc);

	RendererDriver driver = RendererDriver::Autodetect;
	for (const char* arg : args) {
		if (std::strcmp(arg, "--d3d12") == 0)
			driver = RendererDriver::Direct3D12;
		if (std::strcmp(arg, "--vulkan") == 0)
			driver = RendererDriver::Vulkan;
	}

    SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Ivy3", 0, 0, 1024, 768, 0);

	Renderer renderer(driver);
	if (!renderer.createRendererForWindow(window))
		return -1;

    SDL_DestroyWindow(window);
    SDL_Quit();
	return 0;
}