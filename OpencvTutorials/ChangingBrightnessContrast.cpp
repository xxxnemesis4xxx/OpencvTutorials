#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

double alpha;
double beta;

int main(char argc, char** argv)
{
	//Read image given by user
	Mat image = imread("Necromancer.jpg");
	Mat new_image = Mat::zeros(image.size(), image.type());

	//Initialize values
	std::cout << " Basic Linear Transforms " << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "* Enter the alpha value [1.0-3.0]: "; //0 -> Darkness 100->Brightness
	std::cin >> alpha;
	std::cout << "* Enter the beta value [0-100]: "; //The higher, the Brightner!
	std::cin >> beta;

	//Do the operation new_image(i,j) = alpha* image(i,j)+beta
	for (int y = 0; y < image.rows; ++y)
	{
		for (int x = 0; x < image.cols; ++x)
		{
			for (int c = 0; c < 3; c++)
			{
				new_image.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}

	//Create Windows
	namedWindow("Original Image",1);
	namedWindow("New Image", 1);

	//Show stuff
	imshow("Original Image", image);
	imshow("New Image", new_image);

	//Wait until user press some key
	waitKey();
	return 0;
}