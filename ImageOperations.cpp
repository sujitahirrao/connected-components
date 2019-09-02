#include "ImageOperations.h"


using namespace std;


ImageOperations::ImageOperations()
{
}


ImageOperations::~ImageOperations()
{
}


int** ImageOperations::thresholdByValue(int** imageMatrix, int nRows, int nCols, int threshold)
{
	//cout << "\n***" << endl;
	//cout << "nRow: " << nRows << " " << "nCols: " << nCols << endl;
	cout << "\nthreshold: " << threshold << endl;

	int** threshImg = new int*[nRows];
	for (int i = 0; i < nRows; i++)
	{
		threshImg[i] = new int[nCols];
		for (int j = 0; j < nCols; j++)
		{
			int temp = imageMatrix[i][j];
			if (temp < threshold)
				threshImg[i][j] = 0;
			else
				threshImg[i][j] = temp;
			//cout << "Orig: " << imageMatrix[i][j] << " ";
			//cout << "Thresh: " << threshImg[i][j] << endl;
		}
	}
	return threshImg;
}


void ImageOperations::thresholdOtsu()
{
}


void ImageOperations::getConnectedComponents(int method)
{
}
