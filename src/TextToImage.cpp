// TextToImage.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <ostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <fstream>

namespace
{
	std::string gInputFile;
	std::string gFontFile;
	int gSize=0;
	TTF_Font * pFont;
	static TTF_Font * LoadFont(std::string path, int size)
	{
		return TTF_OpenFont((path).c_str(),size);
	}
	SDL_Surface* GetSurface(std::string text)
	{
		SDL_Color black = {0,0,0};
		SDL_Surface * pSurface = TTF_RenderText_Solid( pFont, text.c_str(),black);
		return pSurface;
	}
}


int main(int argc, char* argv[])
{
	if(argc != 4)
	{
		std::cout<<"ERROR: missing parameters."<<std::endl;
		system("PAUSE");
		return 0;
	}
	gInputFile = std::string(argv[1]);
	gFontFile = std::string(argv[2]);
	gSize = atoi(argv[3]);
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	pFont = LoadFont(gFontFile,gSize);
	std::string line;
	std::ifstream iFile (gInputFile);
	if (iFile.is_open())
	{
		while ( getline (iFile,line) )
		{
			SDL_Surface *pSurface = GetSurface(line);
			SDL_SaveBMP(pSurface,(std::string(line)+".bmp").c_str());
			SDL_FreeSurface(pSurface);
		}
		iFile.close();
	}
	TTF_CloseFont(pFont);
	return 0;
}

