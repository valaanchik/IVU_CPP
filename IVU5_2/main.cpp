#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char * argv [])
{
  int minX = -15, maxX = 20;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
  const float Width = 1280;
  const float Height = 720;
 SDL_Window *w = SDL_CreateWindow("Snow", 63, 126, Width, Height, 0);
 SDL_Renderer *r = SDL_CreateRenderer(w, -1, SDL_RENDERER_PRESENTVSYNC);

  bool isRunning = true, aDirection = true;
 SDL_Event e;
  while (isRunning)
  {
    SDL_PollEvent(&e);
    if ((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
        isRunning = false;
    switch (e.type)
    {
      case SDL_QUIT:
        SDL_DestroyWindow(w);
        SDL_Quit();
        return 0;
        break;
    }
    if (aDirection && maxX > 100)
 aDirection = false;
    else if (!aDirection && maxX < 10)
 aDirection = true;
    else if (aDirection)
 maxX++;
    else
      maxX--;

    float scaleX = Width / (maxX - minX);
    float scaleY = Height / (maxX - minX);

    SDL_SetRenderDrawColor(r, 250, 204, 200, 200);
    SDL_RenderClear(r);

    SDL_SetRenderDrawColor(r, 0, 255, 250, 0xff);

    SDL_RenderDrawLineF(r, Width / 2 - 5 * scaleX, Height / 2, Width / 2 + 5 * scaleX, Height / 2);


    SDL_RenderDrawLineF(r, Width / 2, Height / 2 - 5 * scaleY, Width / 2, Height / 2 + 5 * scaleY);

    SDL_RenderDrawLineF(r, Width / 2 - 5 * scaleX, Height / 2 + 5 * scaleY, Width / 2 + 5 * scaleX,
                        Height / 2 - 5 * scaleY);
    SDL_RenderDrawLineF(r, Width / 2 + 5 * scaleX, Height / 2 + 5 * scaleY, Width / 2 - 5 * scaleX,
                        Height / 2 - 5 * scaleY);
    SDL_RenderDrawLineF(r, Width / 2 - 5 * scaleX, Height / 2 + 5 * scaleY, Width / 2 + 5 * scaleX,
                        Height / 2 - 5 * scaleY);
    SDL_RenderDrawLineF(r, Width / 2 + 5 * scaleX, Height / 2 + 5 * scaleY, Width / 2 - 5 * scaleX,
                        Height / 2 - 5 * scaleY);

    for (size_t i = 0; i < 5; i++)
    {
      SDL_RenderDrawLineF(r, Width / 2 - (5 - i) * scaleX, Height / 2 + (5 - i) * scaleY, Width / 2 - (5 - i) * scaleX,
 Height / 2 + (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 - (5 - i) * scaleX, Height / 2 + (5 - i) * scaleY,
 Width / 2 - (4.375 - i) * scaleX, Height / 2 + (5 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 + (5 - i) * scaleX, Height / 2 + (5 - i) * scaleY, Width / 2 + (5 - i) * scaleX,
 Height / 2 + (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 + (5 - i) * scaleX, Height / 2 + (5 - i) * scaleY,
 Width / 2 + (4.375 - i) * scaleX, Height / 2 + (5 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 - (5 - i) * scaleX, Height / 2 - (5 - i) * scaleY, Width / 2 - (5 - i) * scaleX,
 Height / 2 - (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 - (5 - i) * scaleX, Height / 2 - (5 - i) * scaleY,
 Width / 2 - (4.375 - i) * scaleX, Height / 2 - (5 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 + (5 - i) * scaleX, Height / 2 - (5 - i) * scaleY, Width / 2 + (5 - i) * scaleX,
 Height / 2 - (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 + (5 - i) * scaleX, Height / 2 - (5 - i) * scaleY,
 Width / 2 + (4.375 - i) * scaleX, Height / 2 - (5 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 + (5 - i) * scaleX, Height / 2 - (5 - i) * scaleY,
 Width / 2 + (4.375 - i) * scaleX, Height / 2 - (5 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 - (5 - i) * scaleX, Height / 2 + (5 - i) * scaleY, Width / 2 - (5 - i) * scaleX,
 Height / 2 + (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 - (5 - i) * scaleX, Height / 2 + (5 - i) * scaleY,
 Width / 2 - (4.375 - i) * scaleX, Height / 2 + (5 - i) * scaleY);
    }

    for (size_t i = 0; i < 5; i++)
    {
      SDL_RenderDrawLineF(r, Width / 2, Height / 2 + (5 - i) * scaleY, Width / 2 + 0.75 * scaleX,
 Height / 2 + (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2, Height / 2 + (5 - i) * scaleY, Width / 2 + 0.75 * scaleX,
 Height / 2 + (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2, Height / 2 + (5 - i) * scaleY, Width / 2 - 0.75 * scaleX,
 Height / 2 + (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2, Height / 2 - (5 - i) * scaleY, Width / 2 + 0.75 * scaleX,
 Height / 2 - (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2, Height / 2 - (5 - i) * scaleY, Width / 2 - 0.75 * scaleX,
 Height / 2 - (4 - i) * scaleY);
      SDL_RenderDrawLineF(r, Width / 2 - (5 - i) * scaleX, Height / 2, Width / 2 - (4 - i) * scaleX,
 Height / 2 + scaleY);
      SDL_RenderDrawLineF(r, Width / 2 - (5 - i) * scaleX, Height / 2, Width / 2 - (4 - i) * scaleX,
 Height / 2 - scaleY);
      SDL_RenderDrawLineF(r, Width / 2 + (5 - i) * scaleX, Height / 2, Width / 2 + (4 - i) * scaleX,
 Height / 2 + scaleY);
      SDL_RenderDrawLineF(r, Width / 2 + (5 - i) * scaleX, Height / 2, Width / 2 + (4 - i) * scaleX,
 Height / 2 - scaleY);
      SDL_RenderDrawLineF(r, Width / 2 + (5 - i) * scaleX, Height / 2, Width / 2 + (4 - i) * scaleX,
 Height / 2 - scaleY);
    }

    SDL_RenderPresent(r);
  }
}
