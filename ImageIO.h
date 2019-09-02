#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

#include "Config.h"


class ImageIO
{
public:
	
	int nRows, nCols;
	int** imageMatrix;
	char* imagePath;
	char* outImgPath = "..\\..\\data\\output\\output.pgm";

	ImageIO();
	ImageIO(char* imgPath);

	~ImageIO();

	int** readImage();

	void writeImage(int** imageToWrite);
};
