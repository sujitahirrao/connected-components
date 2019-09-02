#include "ImageOperations.h"


using namespace std;


ImageOperations::ImageOperations()
{
}


ImageOperations::~ImageOperations()
{
}


char** ImageOperations::thresholdByValue(char** imageMatrix, int nRows, int nCols, int maxIntensityLevel, int thresh)
{
	if (DEBUG)
	{
		//cout << "\nnRow: " << nRows << " " << "nCols: " << nCols << endl;
		//cout << "thresh: " << thresh << endl;
	}

	char** threshImg = new char*[nRows];
	for (int i = 0; i < nRows; i++)
	{
		threshImg[i] = new char[nCols];
		for (int j = 0; j < nCols; j++)
		{
			unsigned char temp = imageMatrix[i][j];
			if (temp < thresh)
				threshImg[i][j] = 0;
			else
				threshImg[i][j] = temp;
			
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


int ImageOperations::getOtsuThreshold(char** imageMatrix, int nRows, int nCols, int maxIntensityLevel)
{
	int otsuThreshold = 0;
	int totalPixels = 0;
	double maxBetween = 0.0;

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
