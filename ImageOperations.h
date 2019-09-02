#pragma once

#include<iostream>

#include "Config.h"


class ImageOperations
{
private:
	char** imageMatrix;
	int nRows, nCols, maxIntensityLevel, otsuThreshold;

public:
	ImageOperations();
	ImageOperations(char** imageMatrix, int nRows, int nCols, int maxIntensityLevel);

	~ImageOperations();

	int getOtsuThreshold();

	char** thresholdByValue(int thresh);

	void getConnectedComponents(int method);
};
