#include "background.h"
#include "texte.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
int main (int argc, char** argv)
{
	TTF_Init();
 	SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_TIMER |SDL_INIT_AUDIO );
 	if(Mix_OpenAudio(48000,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
 		{
 			printf("%s",Mix_GetError());
 		}
 	Background b,b1;
 	int pasavancementH=0;
        int pasavancementV=0;
        int pasavancement=0;
        int direction=0;
 	SDL_Surface *screen=NULL;
 	int loop = 0;
 	SDL_Event event;
 	atexit(SDL_Quit);
 	screen = SDL_SetVideoMode(1000,500,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
 	image img;
 	
 	
 	int ii=0;
texte t,t1;
Uint32 score=0;
initTexte(&t,0,0,250,250,250,"Roboto-BoldItalic.ttf",30);
initTexte(&t1,90,0,250,250,250,"Roboto-BoldItalic.ttf",30);
initVie(&img);	 
 	if (!screen) {
 		printf("erreur %s\n",SDL_GetError());
 		return 1;}
 		
 		char zz[10];
 	char scores[12]="scores.txt";
 	int sp=0;
 	char nom[20]="louai";
 	char message[20]="looooool",ch[20];
 	char nj[20];
 		
b.n=0;
b1.n=1;
 	initBack(&b);
 	initBack(&b1);
	while(!loop) {
aficherBack(b1,screen);
aficherBack(b,screen);

scrolling (&b, direction, pasavancement);
animerBackground(&b);
animerBackground(&b1);
afficheVie(img,screen);
displaytexte(t,screen,"Score: ");
ii++;
	if(ii%100==0)
	{img.pos2.x+=62;
	if (img.pos2.x>=300) img.pos2.x=0;}
	displaytexte(t1,screen,zz);
	sprintf(zz,"%d",sp);
	 score += SDL_GetTicks()/1000;
	
	// sprintf(message, "%d", score);
SDL_Flip(screen);
		SDL_PollEvent(&event);
			switch (event.type) 
		{
			case SDL_QUIT:
				loop = 1;
				break;
			case SDL_KEYDOWN:
			{
			switch (event.key.keysym.sym) 
			{
			case SDLK_ESCAPE:
			loop=1;
			break;
                         case SDLK_w:
				direction=1;
                        if(pasavancementV>0)
                        pasavancementV-=5;
			pasavancement=pasavancementV;
			sp++;
			break;
				case SDLK_s:
				direction=1;
                        if(pasavancementV<500)
                        pasavancementV+=5;
			pasavancement=pasavancementV;
			sp++;
			break;

			case SDLK_a:
			direction=0;
			  if(pasavancementH>0)
                        pasavancementH-=5;
			pasavancement=pasavancementH;
			sp++;
			break;

			case SDLK_d:
			direction=0;
			   if(pasavancementH<1420)
                        pasavancementH+=5;
			pasavancement=pasavancementH;
			sp++;
			break;


			case SDLK_RIGHT:
                         direction=1;
                      if(pasavancementH<=60)
                        pasavancementH+=5;
                        pasavancement=pasavancementH;
                        sp++;
			
			break;
			case SDLK_LEFT:
                        direction=1;
                        if(pasavancementH>0)
                         pasavancementH-=5;
                         pasavancement=pasavancementH;
                         sp++;
                        break;
                       case SDLK_UP:
                       direction=2;
                       if(pasavancementV>0)
                       pasavancementV-=5;
                       pasavancement=pasavancementV;
                       sp++;
			break ;
			case SDLK_DOWN:
                       direction=2;
                       if(pasavancementV<=29)
                       pasavancementV+=5;
                       pasavancement=pasavancementV;
                        sp++;
                        break;
			
			  
			
		}
			}
			}
			}
			 sauvegarder( sp, nom,  scores);
	meilleur( scores, &sp, nj); 
	printf("  ******************************\n"); 
        printf("the best score %d belongs to %s\n",sp,nj) ;   
        printf("  ******************************\n");  
			liberer(b);
			liberer(b1);	
	freeTexte(t);
	freeTexte(t1);
	TTF_CloseFont(t.font);
	TTF_CloseFont(t1.font);
	liberer1(img);
	
	
	return 0;
}
