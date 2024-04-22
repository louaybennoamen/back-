#ifndef Image_H
#define Image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct
{int j,n;
	SDL_Rect pos1,pos2;
	SDL_Surface * img,*img1,*img2,*img3,*img4,*bg;
} Background;
typedef struct
{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface * img;
} image;

void initBack(Background * b);
void aficherBack(Background b, SDL_Surface * screen);
void liberer(Background a);
void scrolling (Background * b, int direction, int pasavancement);
void animerBackground( Background * e);
void sauvegarder( int score, char nomjoueur[], char nomfichier[]);
void afficheVie(image img, SDL_Surface * screen);
void initVie(image *img);
void afficheVie(image img, SDL_Surface * screen);
void liberer1(image a);
void meilleur( char * scores, int * sp, char * nj);
#endif
