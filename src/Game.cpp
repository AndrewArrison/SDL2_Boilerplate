#include "../include/Game.hpp"

Game::Game()
{
    
}

Game::~Game()
{
    std::cout << "Starting ~Game" << std::endl;
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
    std::cout << "Ended ~Game" << std::endl;
}

bool Game::init(const char* title, int w, int h)
{
    std::cout << "Starting Init" << std::endl;
    if((SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initializes SDL_INIT_VIDEO" << std::endl;
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
        return false;
    }

    m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
    if (m_Window == nullptr) {
        std::cout << "NullPointer at m_Window" << std::endl;
        SDL_Quit();
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
    if (m_Renderer == nullptr) {
        std::cout << "NullPointer at m_Renderer" << std::endl;
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
        return false;
    }
    SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
    running = true;
    std::cout << "Ended Init" << std::endl;
    return true;
}

void Game::handleEvents()
{
    // std::cout << "Started handleEvents" << std::endl;
    if (SDL_PollEvent(&m_Event) != 0)
    {
        if (m_Event.type == SDL_QUIT) {
            running = false;
        }

        if (m_Event.type == SDL_KEYDOWN) {
            if(m_Event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
            }
        }
    }
    
}

void Game::update()
{
    // std::cout << "update" << std::endl;
}

void Game::render()
{
    // std::cout << "render" << std::endl;
    SDL_RenderClear(m_Renderer);    //Clear the last frame from the memory
    //Start rendering entity

    //End rendering entity
    SDL_RenderPresent(m_Renderer);  //Render the frame currently in memory
}
