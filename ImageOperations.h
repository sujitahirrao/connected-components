#pragma once

#include<iostream>

#include "Config.h"


class ImageOperations
{

public:
	ImageOperations();

	~ImageOperations();

	int getOtsuThreshold(char** imageMatrix, int nRows, int nCols, int maxIntensityLevel);

	char** thresholdByValue(char** imageMatrix, int nRows, int nCols, int maxIntensityLevel, int thresh);

	void getConnectedComponents(int method);
};
