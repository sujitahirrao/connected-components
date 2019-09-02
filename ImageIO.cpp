#include "ImageIO.h"


using namespace std;


ImageIO::ImageIO()
{
	nRows = 0;
	nCols = 0;
}


ImageIO::ImageIO(char* imgPath)
{
	imagePath = imgPath;
}


ImageIO::~ImageIO()
{
	for (int i = 0; i < nRows; ++i)
		delete[] imageMatrix[i];
	delete[] imageMatrix;
}


char** ImageIO::readImage()
{
	stringstream ss;
	string version = "", comment = "", iline = "";

	ifstream imgFile(imagePath, ios::binary);

	try
	{
		getline(imgFile, version);
		getline(imgFile, comment);

		ss << imgFile.rdbuf();
		ss >> nRows >> nCols;

		int max_intensity_val;
		ss >> max_intensity_val;
		ss.ignore();

		if (DEBUG)
		{
			cout << "Version:\t" << version << endl;
			cout << "Comment:\t" << comment << endl;
			cout << "Rows:\t\t" << nRows << endl;
			cout << "Columns:\t" << nCols << endl;
			cout << "Max level:\t" << max_intensity_val << endl;
		}

		unsigned char pval;

		imageMatrix = new char*[nRows];
		for (int i = 0; i < nRows; i++)
		{
			imageMatrix[i] = new char[nCols];
		
			for (int j = 0; j < nCols; j++)
			{
				//ss >> pval;
				ss.read((char*)&pval, 1);
				imageMatrix[i][j] = pval;
				//cout << imageMatrix[row][col] << " ";
			}
			//cout << endl;
		}
	}
	catch (char* e)
	{
		cout << "Exception caught in ImageIO.readImage()" << e << endl;
	}
	catch (...)
	{
		cout << "Exception in ImageIO.readImage()" << endl;
	}

	imgFile.close();

	return imageMatrix;
}


void ImageIO::writeImage(char** imageToWrite)
{
	ofstream binImgFile(outImgPath, ios::binary);		// , ios::binary
	//ofstream pixelValFile("..\\..\\data\\output\\pValues.txt");

	binImgFile << "P5" << "\n";
	binImgFile << "# Created by ImageIO" << "\n";
	binImgFile << nRows << " " << nCols << "\n";
	binImgFile << "255" << "\n";

	unsigned char pval;

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			pval = imageToWrite[i][j];
			binImgFile << pval;
			//cout << imageToWrite[i][j] << " ";
			//pixelValFile << pval << " ";
		}
		//pixelValFile << ";" << endl;
	}

	binImgFile.close();
	//pixelValFile.close();

	return;
}
