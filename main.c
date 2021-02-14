#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/*
  SDL_RENDERER_SOFTWARE
  SDL_RENDERER_ACCELERATED
  SDL_RENDERER_PRESENTVSYNC
  SDL_RENDERER_TARGETTEXTURE
*/

void SDL_ExitWithError(const char *message);

int main(int argc, char **argv) {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  // Lancement SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    SDL_ExitWithError("Initialisation SDL");

  // Creation fenetre + Rendu
  if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");

  // -----------------------------------
  SDL_Surface *image = NULL;
  SDL_Texture *texture = NULL;
  image = SDL_LoadBMP("src/smallImg.bmp");
  if (image == NULL) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_ExitWithError("Impossible de charger l'image");
  }

  texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  if (texture == NULL) {
  }
  SDL_Rect rectangle2;

  if (SDL_QueryTexture(texture, NULL, NULL, &rectangle2.w, &rectangle2.h) != 0) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_ExitWithError("Impossible de charger la texture");    
  }
  rectangle2.x = (WINDOW_WIDTH - rectangle2.w) / 2;
  rectangle2.y = (WINDOW_HEIGHT - rectangle2.h) / 2;

  if (SDL_RenderCopy(renderer, texture, NULL, &rectangle2) != 0) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_ExitWithError("Impossible d'afficher la texture");   
  }

  if (SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
    SDL_ExitWithError("Impossible de changer la couleur pour le rendu");

  if (SDL_RenderDrawPoint(renderer, 600, 300) != 0)
    SDL_ExitWithError("Impossible dessiner un point");

  if (SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
    SDL_ExitWithError("Impossible dessiner une ligne");

  SDL_Rect rectangle;
  rectangle.x = 300;
  rectangle.y = 300;
  rectangle.w = 200;
  rectangle.h = 120;
  if (SDL_SetRenderDrawColor(renderer, 200, 200, 23, SDL_ALPHA_OPAQUE) != 0)
    SDL_ExitWithError("Impossible de changer la couleur pour le rendu");
  // if (SDL_RenderDrawRect(renderer, &rectangle) != 0)
  if (SDL_RenderFillRect(renderer, &rectangle) != 0)
    SDL_ExitWithError("Impossible dessiner un rectangle");

  SDL_RenderPresent(renderer);
  SDL_Delay(3000);
  // -----------------------------------


  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message) {
  SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
  SDL_Quit();
  exit(EXIT_FAILURE);
}
// sudo apt-get install libsdl2-dev
// gcc main.c $(sdl2-config --cflags --libs)

  /*
  SDL_version nb;
  SDL_VERSION(&nb);

  printf("SDL %d.%d.%d !\n", nb.major, nb.minor, nb.patch);

  return 0;
  */


/*
   // Execution du programme
  window = SDL_CreateWindow("Premiere fenetre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_MINIMIZED);
  if (window == NULL)
    SDL_ExitWithError("Création de fenetre echouee");

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  if (renderer == NULL)
    SDL_ExitWithError("Création rendu echouee");

  if (SDL_RenderClear(renderer) != 0)
    SDL_ExitWithError("Effacement rendu echoue");
*/