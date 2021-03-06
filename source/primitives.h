#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "SDL2/SDL.h"
#include "stdbool.h"

typedef struct ColorRGBTag
{
    int r;
    int g;
    int b;
} ColorRGB;

typedef struct Vector2Tag
{
    float x;
    float y;
} Vector2;

typedef struct Vector3Tag
{
    float x;
    float y;
    float z;
} Vector3;

typedef struct IntVector2Tag
{
    int x;
    int y;
} IntVector2;

typedef struct IntVector3Tag
{
    int x;
    int y;
    int z;
} IntVector3;

typedef struct TriangleTag
{
    Vector2 position;
    int size;
    ColorRGB color;
} Triangle;

// Obsolete, use GameObject instead
typedef struct Box2DTag
{
    Vector2 position;
    IntVector2 size;
    ColorRGB color;
    bool hasCollision;
} Box2D;

void drawBox(SDL_Renderer* renderer, Box2D box2D);
void drawDots(SDL_Renderer* renderer);

#endif
