#pragma one
#include <iostream>
#include <SDL2/SDL.h>

class Rectangle
{
public:
    Rectangle(const SDL_Rect& Rect)
    : Rect{Rect} {}

    void Render(SDL_Surface* Surface) const {
        auto [r, g, b, a]{
        isPointerHovering ? HoverColor : Color
    };
    SDL_FillRect(
        Surface, &Rect,
        SDL_MapRGB(Surface -> format, r, g, b )
    );
    };


private:
    SDL_Rect Rect;
    SDL_Color Color{255, 0, 0, 255};
    SDL_Color HoverColor{0, 0, 255, 255};

    bool isPointerHovering{false};

    bool isWithinRect(int x, int y) {
    if (x < Rect.x) return false;
    if (x > Rect.x + Rect.w) return false;
    if (y < Rect.y) return false;
    if (y > Rect.y + Rect.h) return false;
    return true;
  }
};

