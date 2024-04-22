#include <SDL/SDL.h>
#include "background.h"
#include <SDL/SDL_image.h>


void initBack(Background * b)
{
 b->img= IMG_Load("bg.jpg");
 	if(b->img == NULL) {
 		printf("erreur unable to load: %s\n",SDL_GetError());
 		return;
 }
 	b->pos1.x=0;
 	b->pos1.y=0;
 	b->pos2.x=0;
 	b->pos2.y=0;
 	b->pos2.w=1000;
 	b->pos2.h=500;
 b->img1= IMG_Load("bg1.jpg");
 	if(b->img1 == NULL) {
 		printf("erreur unable to load: %s\n",SDL_GetError());
 		return;
 }
 	b->pos1.x=0;
 	b->pos1.y=0;
 	b->pos2.x=0;
 	b->pos2.y=0;
 	b->pos2.w=1000;
 	b->pos2.h=500;

 b->img2= IMG_Load("bg2.jpg");
 	if(b->img2 == NULL) {
 		printf("erreur unable to load: %s\n",SDL_GetError());
 		return;
 }
 	b->pos1.x=0;
 	b->pos1.y=0;
 	b->pos2.x=0;
 	b->pos2.y=0;
 	b->pos2.w=1000;
 	b->pos2.h=500;


 b->img3= IMG_Load("bg3.jpg");
 	if(b->img3 == NULL) {
 		printf("erreur unable to load: %s\n",SDL_GetError());
 		return;
 }
 	b->pos1.x=0;
 	b->pos1.y=0;
 	b->pos2.x=0;
 	b->pos2.y=0;
 	b->pos2.w=1000;
 	b->pos2.h=500;



 b->img4= IMG_Load("bg4.jpg");
 	if(b->img4 == NULL) {
 		printf("erreur unable to load: %s\n",SDL_GetError());
 		return;
 }
 	b->pos1.x=0;
 	b->pos1.y=0;
 	b->pos2.x=0;
 	b->pos2.y=0;
 	b->pos2.w=1000;
 	b->pos2.h=500;


 b->bg=b->img;


}

void aficherBack(Background b, SDL_Surface * screen)
{
SDL_BlitSurface(b.bg,&b.pos2,screen,&b.pos1);
}

void liberer(Background a)
{
SDL_FreeSurface(a.img);
}

scrolling (Background * b, int direction, int pasavancement)
{
if (direction==0)
{b->pos2.x=pasavancement;}
else 
{b->pos2.y=pasavancement;}
}

void animerBackground( Background * e)
{
printf("%d \n",e->j);

if(e->j==0)
 e->bg=e->img;
else if(e->j==10)
 e->bg=e->img1;
else if(e->j==20)
 e->bg=e->img2;
else if(e->j==30)
 e->bg=e->img3;
else if(e->j==40)
 e->bg=e->img4;
e->j++;
if(e->j>=50)
e->j=0;
}

void sauvegarder( int score, char nomjoueur[], char scores[])
{
FILE* f=NULL;
f=fopen(scores,"a");
if(f!=NULL)
    {
  fprintf (f,"%s %d\n",nomjoueur,score);

    fclose(f);
}
}
void meilleur( char scores[], int *score, char nomjoueur[])
{
   FILE* f=NULL;
   char player[20] ;
   int mc,s;

f=fopen(scores,"r");
if (f!=NULL)
{
mc=0;
while(fscanf(f,"%s %d\n",player,&s)!=EOF)
{
    if(mc<s)
   {
    mc=s;
    strcpy(nomjoueur,player);
   }
*score=mc;
}
}

fclose(f);
}
void initVie(image *img)
{
 	img->img = IMG_Load("vie.png");
 		if (img->img == NULL) {
 		printf("erreur unable to load: %s\n",SDL_GetError());
 			return;
 		}
 	img->pos1.x=300;
 	img->pos1.y=0;
 	img->pos1.h=49;
 	img->pos1.w=300;
 	img->pos2.x=0;
 	img->pos2.y=0;
 	img->pos2.h=img->pos1.h;
 	img->pos2.w=img->pos1.w/5;
 }
void afficheVie(image img, SDL_Surface * screen)
{
	SDL_BlitSurface(img.img,&img.pos2,screen,&img.pos1); 
}

void liberer1(image a)
{
	SDL_FreeSurface(a.img);
}
