#include<iostream>

#include "Config.h"
#include "ImageIO.h"
#include "ImageOperations.h"


using namespace std;

char* imagePath = NULL;
int threshold = THRESHOLD;
int method = METHOD;


void parseArguments(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "Please provide the path to the input pgm file." << endl;
		exit(0);
	}

	for (int i = 1; i < argc; i++)
	{
		switch (i)
		{
		case 1: imagePath = argv[i]; 
			break;
		case 2: threshold = atoi(argv[i]); 
			break;
		case 3: method = atoi(argv[i]); 
			break;
		default: 
			break;
		}
	}

	if (DEBUG)
	{
		cout << "imagePath:\t" << imagePath << endl;
		cout << "threshold:\t" << threshold << endl;
		cout << "method:\t\t" << method << endl;
	}
}


int main(int argc, char** argv)
{
	parseArguments(argc, argv);

	if (imagePath != NULL)
	{
		ImageIO imageIO = ImageIO(imagePath);
		char** imageMatrix = imageIO.readImage();

		ImageOperations imgOperator = ImageOperations(imageMatrix, imageIO.nRows, imageIO.nCols, imageIO.maxIntensityLevel);
		int otsuThreshold = imgOperator.getOtsuThreshold();
		char** threshImg = imgOperator.thresholdByValue(otsuThreshold);

		imageIO.writeImage(threshImg);
	}

	cout << endl;
	system("pause");

	return 0;
}
