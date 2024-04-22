prog:main.o background.o texte.o
	gcc main.o background.o texte.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf 
main.o:main.c
	gcc -c main.c -g
background.o:background.c
	gcc -c background.c -g
texte.o:texte.c
	gcc -c texte.c -g 
