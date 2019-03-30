#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "time.h"
#include "stdbool.h"
#include "primitives.h"
#include "constants.h"
#include "fpsutils.h"
#include "SDL2_image/SDL_image.h"
#include "game.h"

//const int BOX_SIZE = 100;
//Box2D boxes[BOX_SIZE];
Triangle triangle;

int main(int argc, char* argv[])
{
    clock_t start, end;
    start = clock();
    double timePerFrame = 0;
    // SDL_Delay(16);
    srand(time(NULL));
    
    bool goUp = false;
    bool goLeft = false;
    bool goDown = false;
    bool goRight = false;
    
//    for (int i = 0; i < BOX_SIZE; i++)
//    {
//        boxes[i].position.x = rand() / (RAND_MAX + 1.0) * WIDTH;
//        boxes[i].position.y = rand() / (RAND_MAX + 1.0) * HEIGHT;
//        boxes[i].size.x = boxes[i].size.y = 10 + (rand() / (RAND_MAX + 1.0)) * 90;
//        boxes[i].color.r = 255;
//        boxes[i].color.g = 255;
//        boxes[i].color.b = 255;
//    }
    
//    triangle.position.x = 0;
//    triangle.position.y = 0;
//    triangle.size = 10;
//    triangle.color.r = 255;
//    triangle.color.g = 0;
//    triangle.color.b = 255;
    
    initGame();
    return 0;
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        initFpsutils();
        
        if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) == 0)
        {
            SDL_Surface* pngSurface = IMG_Load("assets/playerShip1_blue.png");
            SDL_Texture* pngTexture = SDL_CreateTextureFromSurface(renderer, pngSurface);
            SDL_Rect pngTextRect;
            pngTextRect.x = pngTextRect.y = 400;
            pngTextRect.w = 99;
            pngTextRect.h = 75;
//            SDL_QueryTexture(pngTexture, NULL, NULL, &pngTextRect.w, &pngTextRect.h);
            
            SDL_bool done = SDL_FALSE;
            int i = 0;
            
            while (!done)
            {
                double deltaTime = (double) (clock() - start) / CLOCKS_PER_SEC;

                start = clock();
                timePerFrame = timePerFrame + deltaTime;
                calculateFps(deltaTime);

//                for (int i = 0; i < 1000000; i++)
//                    ;
                
                triangle.position.x += deltaTime * 50;

//                if (timePerFrame < 0.0166666)
//                {
//                    continue;
//                }
//                else
//                {
//                    float f = getAverageFps();
//                    char c[50];
//                    sprintf(c, "%g", deltaTime);
//                    strcat(c, " deltaTime");
//                    timePerFrame = 0;
//                    surface = TTF_RenderText_Solid(font, c, color);
//                    texture = SDL_CreateTextureFromSurface(renderer, surface);
//                    SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
//                }
                // printf("delta time: %f\n", deltaTime);
                SDL_Event event;
                
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                
                drawTriangle(renderer, i++);
                drawTriangle2(renderer, triangle);
                if (i > WIDTH / 2)
                {
                    i = 0;
                    triangle.position.x = 0;
                }
                
//                for (int i = 0; i < BOX_SIZE; i++)
//                {
//                    drawBox(renderer, boxes[i]);
//                }
                
                drawDots(renderer);
                
                SDL_RenderCopy(renderer, pngTexture, NULL, &pngTextRect);
                SDL_RenderPresent(renderer);
                
//                updateGame();
                
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
                            break;
                        case SDL_QUIT:
                            done = SDL_TRUE;
                            break;
                        default:
                            break;
                    }
                }
//
//                if (goUp)
//                {
//                    boxes[0].position.y -= deltaTime * SPEED;
//                    pngTextRect.y -= 1;
//                }
//                if (goLeft)
//                {
//                    boxes[0].position.x -= deltaTime * SPEED;
//                    pngTextRect.x -= 1;
//                }
//                if (goDown)
//                {
//                    boxes[0].position.y += deltaTime * SPEED;
//                    pngTextRect.y += 1;
//                }
//                if (goRight)
//                {
//                    boxes[0].position.x += deltaTime * SPEED;
//                    pngTextRect.x += 1;
//                }
//
//                solvePhysics(boxes, BOX_SIZE);
                
                if (timePerFrame < 0.0166666)
                {
                    continue;
                }
                else
                {
                    float f = getAverageFps();
                    char c[50];
                    sprintf(c, "%g", deltaTime);
                    strcat(c, " deltaTime");
                    timePerFrame = 0;
                }
            }
        }
        
        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }
        if (window)
        {
            SDL_DestroyWindow(window);
        }
    }

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
