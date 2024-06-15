#include "structs.h"
#include <chrono>
#include <SDL.h>

class BaseGame{
public:
    explicit BaseGame(const Window& window);
    BaseGame(const BaseGame& other) = delete;
    BaseGame& operator=(const BaseGame& other) = delete;
    BaseGame(BaseGame&& other) = delete;
    BaseGame& operator=(BaseGame&& other) = delete;
    virtual ~BaseGame();

    void Run();

    virtual void Update(float elapsedSec)
    {

    }

    virtual void Draw() const
    {

    }

    // Event handling
    virtual void ProcessJoyButtonDownEvent(const SDL_JoyButtonEvent& e)
    {

    }
    virtual void ProcessJoyButtonUpEvent(const SDL_JoyButtonEvent& e)
    {

    }

    const Rectf& GetViewPort() const
    {
        return m_Viewport;
    }
        
protected:
    SDL_Renderer* m_pRenderer;
    const Window m_Window;

private:
    const Rectf m_Viewport;

    SDL_Window* m_pWindow;

    bool m_Initalized;

    void Initialize();
    void Cleanup();

    void Loop();

    bool m_Quit{ false };
    std::chrono::steady_clock::time_point m_t1;
};