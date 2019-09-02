#pragma once

#include<iostream>


class ImageOperations
{
public:
	ImageOperations();

	~ImageOperations();

	int** thresholdByValue(int** imageMatrix, int nRows, int nCols, int threshold);

	void thresholdOtsu();

	void getConnectedComponents(int method);
};
