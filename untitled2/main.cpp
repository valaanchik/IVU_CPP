#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char * argv [])
{
    float _min = 0, _max =90 ;

    cout << " min " ;
    cin >> _min;
    cout << " max ";
    cin >> _max;
    bool isRunning = true;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
  const float Width = 1280;
  const float Height = 720;
  float scaleX = Width / (_max - _min);
  float scaleY = Height / (_max - _min);
  SDL_Window *w = SDL_CreateWindow("sqrt(sin(f)/2)", 63, 126, Width, Height, 0);
  SDL_Renderer *r = SDL_CreateRenderer(w, -1, 0);

  SDL_Event ev;
  while (isRunning)
  {SDL_WaitEvent(&ev);
      if ((ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE))
          isRunning = false;
    switch (ev.type)
    {
      case SDL_QUIT:
        SDL_DestroyWindow(w);
        SDL_Quit();
        return 0;
        break;
    }
    SDL_SetRenderDrawColor(r, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(r);

    SDL_SetRenderDrawColor(r, 0xee, 0xee, 0xee, 0xff);

    for (int i = 0; i < 64; i++) SDL_RenderDrawLine(r, (Width / 64 * i), 0, (Width / 64 * i), Height);


    for (int i = 0; i < 36; i++) SDL_RenderDrawLineF(r, 0, (Height / 36 * i), Width, (Height / 36 * i));


    SDL_SetRenderDrawColor(r, 0xee, 0x00, 0x00, 0xff);
    SDL_RenderDrawLineF(r, 0, Height / 2, Width, Height / 2);


    SDL_RenderDrawLineF(r, Width / 2, 0, Width / 2, Height);

    SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xff);
    int oldX = 0, oldY = 0;
    for (float x = _min; x < _max; x += 0.01)
    {
      float y = sqrt(sin(x) / 2);
      float newX = Width / 2 + x * scaleX, newY = Height / 2 - y * scaleY;

      oldX = newX;
      oldY = newY;
      SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xff);
      SDL_RenderDrawLineF(r, oldX, oldY, newX, newY);
    }

    SDL_RenderPresent(r);
  }
}
