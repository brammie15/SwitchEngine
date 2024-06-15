// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_video.h>
// #include <SDL_opengl.h>


// Include the main libnx system header, for Switch development
#include <switch.h>
#include <time.h>
#include <iostream>
#include "Engine/structs.h"
#include "Game.h"
// #include <glad/glad.h>  // glad library (OpenGL loader)
#include <SDL_opengl.h>



// Main program entrypoint
int main(int argc, char *argv[]) {

    srand(static_cast<unsigned int>(time(nullptr)));

    Game* pGame{
        new Game{
            Window{
                "Hello world",
                1920, 1080
            }
        }
    };

    pGame->Run();

    delete pGame;

    // SDL_Event event;
    // SDL_Window *window;
    // SDL_Renderer *renderer;

    // bool shouldQuit{false};
    // int width{1920};
    // int height{1080};

    // printf("Hello World!\n");


    // if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
    //     SDL_Log("SDL_Init: %s\n", SDL_GetError());
    //     return -1;
    // }

    // window = SDL_CreateWindow("sdl2_gles2", 0, 0, width, height, 0);
    // if (!window) {
    //     SDL_Log("SDL_CreateWindow: %s\n", SDL_GetError());
    //     SDL_Quit();
    //     return -1;
    // }

    // // // create a renderer (OpenGL ES2)
    // renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // if (!renderer) {
    //     SDL_Log("SDL_CreateRenderer: %s\n", SDL_GetError());
    //     SDL_Quit();
    //     return -1;
    // }



    // //  // Set the Projection matrix to the identity matrix
    glMatrixMode(GL_PROJECTION); 
    // glIsTexture(GLuint(10));
    // glLoadIdentity();
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // // // Set up a two-dimensional orthographic viewing region.
    // // glOrtho(0, width, 0, height, -10, 10); // y from bottom to top

    // // // Set the viewport to the client window area
    // // // The viewport is the rectangular region of the window where the image is drawn.
    // // glViewport(0, 0, int(width), int(height));

    // // // Set the Modelview matrix to the identity matrix
    // // glMatrixMode(GL_MODELVIEW);
    // // glLoadIdentity();

    // // // Enable color blending and use alpha blending
    // // glEnable(GL_BLEND);
    // // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // // // Initialize PNG loading
    // // int imgFlags = IMG_INIT_PNG;
    // // if (!(IMG_Init(imgFlags) & imgFlags))
    // // {
    // //     std::cerr << "BaseGame::Initialize(), error when calling IMG_Init: " << IMG_GetError() << std::endl;
    // // }

    // // // Initialize SDL_ttf
    // // if (TTF_Init() == -1)
    // // {
    // //     std::cerr << "BaseGame::Initialize(), error when calling TTF_Init: " << TTF_GetError() << std::endl;
    // // }

    // // //Initialize SDL_mixer
    // // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    // // {
    // //     std::cerr << "BaseGame::Initialize(), error when calling Mix_OpenAudio: " << Mix_GetError() << std::endl;
    // // }


    // for (int i = 0; i < 2; i++) {
    //     if (SDL_JoystickOpen(i) == NULL) {
    //         SDL_Log("SDL_JoystickOpen: %s\n", SDL_GetError());
    //         SDL_Quit();
    //         return -1;
    //     }
    // }

    // while (!shouldQuit) {
    //     while (SDL_PollEvent(&event)) {
    //         switch (event.type) {
    //             case SDL_JOYBUTTONDOWN:
    //                 if (event.jbutton.which == 0) {
    //                     if (event.jbutton.button == 10) {
    //                         shouldQuit = true;
    //                     }
    //                 }
    //         }

    //     }

    //     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //     SDL_RenderClear(renderer);

    //     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //     SDL_RenderDrawLine(renderer, 0, 0, width, height);
    //     SDL_RenderDrawLine(renderer, width, 0, 0, height);

    //     SDL_RenderPresent(renderer);

    // }

    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();


    return 0;
}
