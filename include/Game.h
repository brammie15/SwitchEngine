#pragma once
#include "Engine/BaseGame.h"

class Game : public BaseGame {
public:
    explicit Game(const Window& window);
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    Game(Game&& other) = delete;
    Game& operator=(Game&& other) = delete;

    ~Game();
    void Start();
    void Update(float elapsedSec) override;
    void Draw() const override;


    // Event handling

private:
    // FUNCTIONS
    void Initialize();
    void InitializeWorld();
    void Cleanup();
    void ClearBackground() const;


    int test{ 0 };
};
