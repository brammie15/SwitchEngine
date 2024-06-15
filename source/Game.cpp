#include "Game.h"
#include <iostream>
#include <SDL_opengl.h>

Game::Game(const Window &window)
        : BaseGame{window} {
    Initialize();
}

Game::~Game() {
    Cleanup();
}

void Game::Initialize() {
    // we need these to enable drawing stuff with depth
    // glEnable(GL_DEPTH_TEST);
    // glDepthFunc(GL_LEQUAL);
    // glEnable(GL_ALPHA_TEST);
    // glAlphaFunc(GL_GREATER, 0.25f);
    // load resources here

}

void Game::Cleanup() {
}

void Game::Update(float deltaTime) {
}

void Game::Draw() const {
    // ClearBackground();

    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(m_pRenderer);

    // glClearColor(0.f, 0.0f, 0.0f, 1.0f);

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(m_pRenderer, test, 0, m_Window.width, m_Window.height);
    
    SDL_RenderDrawLine(m_pRenderer, m_Window.width - test, 0, 0, m_Window.height);

}