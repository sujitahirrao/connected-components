#include "ImageOperations.h"


using namespace std;


ImageOperations::ImageOperations()
{
}


ImageOperations::ImageOperations(char** _imageMatrix, int _nRows, int _nCols, int _maxIntensityLevel)
{
	otsuThreshold = NULL;
	imageMatrix = _imageMatrix;
	nRows = _nRows;
	nCols = _nCols;
	maxIntensityLevel = _maxIntensityLevel;
}


ImageOperations::~ImageOperations()
{
	for (int i = 0; i < nRows; ++i)
		delete[] imageMatrix[i];
	delete[] imageMatrix;
}


char** ImageOperations::thresholdByValue(int thresh)
{
	if (DEBUG)
	{
		//cout << "\nnRow: " << nRows << " " << "nCols: " << nCols << endl;
	}

	char** threshImg = new char*[nRows];
	for (int i = 0; i < nRows; i++)
	{
		threshImg[i] = new char[nCols];
		for (int j = 0; j < nCols; j++)
		{
			int temp = imageMatrix[i][j];
			if (temp < thresh)
				threshImg[i][j] = 0;
			else
				threshImg[i][j] = (char)temp;
			
			/*if (DEBUG)
			{
				cout << "Orig: " << imageMatrix[i][j] << " ";
				cout << "Temp: " << temp << " ";
				cout << "Thresh: " << threshImg[i][j] << endl;
			}*/
		}
	}
	return threshImg;
}


int ImageOperations::getOtsuThreshold()
{
	int totalPixels = 0;
	int* occurrences = new int[maxIntensityLevel];
	float* histogram = new float[maxIntensityLevel];

	for (int i = 0; i < maxIntensityLevel; i++)
	{
		occurrences[i] = 0;
		histogram[i] = 0;
	}

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			int pVal = imageMatrix[i][j];
			occurrences[pVal] = occurrences[pVal] + 1;
			totalPixels++;
		}
	}

	for (int i = 0; i <= maxIntensityLevel; i++) {
		histogram[i] = (float)occurrences[i] / (float)totalPixels;
	}

	double maxBetween;

	double* probability = new double[maxIntensityLevel];
	double* mean = new double[maxIntensityLevel];
	double* between = new double[maxIntensityLevel];

	for (int i = 0; i < maxIntensityLevel + 1; i++) {
		probability[i] = 0.0;
		mean[i] = 0.0;
		between[i] = 0.0;
	}

	probability[0] = histogram[0];

	for (int i = 1; i < maxIntensityLevel + 1; i++)
	{
		probability[i] = probability[i - 1] + histogram[i];
		mean[i] = mean[i - 1] + i * histogram[i];
	}

	otsuThreshold = 0;
	maxBetween = 0.0;

	for (int i = 0; i < maxIntensityLevel; i++)
	{
		if (probability[i] != 0.0 && probability[i] != 1.0)
			between[i] = pow(mean[maxIntensityLevel] * probability[i] - mean[i], 2) / (probability[i] * (1.0 - probability[i]));
		else
			between[i] = 0.0;
		if (between[i] > maxBetween)
		{
			maxBetween = between[i];
			otsuThreshold = i;
		}
	}

	cout << "\nOTSU THRESHOLD:\t" << otsuThreshold << endl;

	return otsuThreshold;
}


void ImageOperations::getConnectedComponents(int method)
{
}
