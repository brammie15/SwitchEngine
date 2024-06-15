#include "Engine/BaseGame.h"
#include <SDL_image.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <unistd.h>

#include <switch.h>

BaseGame::BaseGame(const Window &window) : m_Window{window}, m_Viewport{0, 0, window.width, window.height}, m_pWindow{nullptr}, m_Initalized{false}
{
    Initialize();
}

BaseGame::~BaseGame()
{
    Cleanup();
}

void BaseGame::Initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
    {
        SDL_Log("SDL_Init: %s\n", SDL_GetError());
        return;
    }

    m_pWindow = SDL_CreateWindow("sdl_gles2", 0, 0, int(m_Window.width), int(m_Window.height), 0);
    if (!m_pWindow)
    {
        SDL_Log("SDL_CreateWindow: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_pRenderer)
    {
        SDL_Log("SDL_CreateRenderer: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        if (SDL_JoystickOpen(i) == NULL)
        {
            SDL_Log("SDL_JoystickOpen: %s\n", SDL_GetError());
            SDL_Quit();
            return;
        }
    }

    int imgFlags = IMG_INIT_PNG;
    if (!IMG_Init(imgFlags) & imgFlags)
    {
        SDL_Log("IMG_Init: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    socketInitializeDefault();
    nxlinkStdio();
    printf("Hello world\n");

    m_Initalized = true;
}

void BaseGame::Cleanup()
{
    printf("Bye\n");
    socketExit();
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}
void BaseGame::Run()
{
    if (!m_Initalized)
    {
        printf("[ERROR]: BaseGame::Run() not initialized correctly");
        return;
    }

    m_t1 = std::chrono::steady_clock::now();

    while (!m_Quit)
    {
        Loop();
    }
}

void BaseGame::Loop()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0)
    {
        switch (e.type)
        {
        case SDL_QUIT:
            m_Quit = true;
            break;
        case SDL_JOYBUTTONDOWN:
            if (e.jbutton.which == 0)
            {
                if (e.jbutton.button == 10)
                {
                    m_Quit = true;
                }
            }
            break;
        }
    }
    if (!m_Quit)
    {
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();

        float elapsedSeconds = std::chrono::duration<float>(t2 - m_t1).count();

        m_t1 = t2;

        // elapsedSeconds = std::min(elapsedSeconds)

        this->Update(elapsedSeconds);

        this->Draw();

        // SDL_RenderPresent(m_pRenderer);

        SDL_GL_SwapWindow(m_pWindow);
    }
}
