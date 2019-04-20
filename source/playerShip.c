#include "playerShip.h"
#include "constants.h"
#include "game.h"
#include "laserBeam.h"

static GameObject playerShip;
static bool goUp;
static bool goLeft;
static bool goDown;
static bool goRight;

static void getInput();
static void setInput(float deltaTime);

const float FIRE_RATE = 0.2;
static float fireRateTimer = 0;

void initPlayerShip(SDL_Renderer* renderer)
{
    goUp = false;
    goLeft = false;
    goDown = false;
    goRight = false;
    
    createGameObject(renderer, &playerShip, "assets/playerShip1_blue.png");
    playerShip.position.x = 400;
    playerShip.position.y = 300;
}

void updatePlayerShip(SDL_Renderer* renderer, float deltaTime)
{
    getInput();
    setInput(deltaTime);
    drawCollider(renderer, playerShip);
    drawImage(renderer, &playerShip);
    
//    fireRateTimer += deltaTime;
    if (fireRateTimer >= FIRE_RATE)
    {
        fireRateTimer = 0;
        fireLaserBeam(playerShip.position);
    }
}

static void getInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_w)
                {
                    goUp = true;
                }
                if (event.key.keysym.sym == SDLK_a)
                {
                    goLeft = true;
                }
                if (event.key.keysym.sym == SDLK_s)
                {
                    goDown = true;
                }
                if (event.key.keysym.sym == SDLK_d)
                {
                    goRight = true;
                }
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_w)
                {
                    goUp = false;
                }
                if (event.key.keysym.sym == SDLK_a)
                {
                    goLeft = false;
                }
                if (event.key.keysym.sym == SDLK_s)
                {
                    goDown = false;
                }
                if (event.key.keysym.sym == SDLK_d)
                {
                    goRight = false;
                }
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    Vector2 posLeft, posRight;
                    posLeft.x = playerShip.position.x - 40;
                    posRight.x = playerShip.position.x + 40;
                    posLeft.y = posRight.y = playerShip.position.y;
                    fireLaserBeam(posLeft);
                    fireLaserBeam(posRight);
                }
                break;
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
        }
    }
}

static void setInput(float deltaTime)
{
    if (goUp)
    {
        playerShip.position.y -= deltaTime * SPEED;
    }
    if (goLeft)
    {
        playerShip.position.x -= deltaTime * SPEED;
    }
    if (goDown)
    {
        playerShip.position.y += deltaTime * SPEED;
    }
    if (goRight)
    {
        playerShip.position.x += deltaTime * SPEED;
    }
}
