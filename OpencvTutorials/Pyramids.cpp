#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace cv;

/// Global variables
Mat src, dst, tmp;
String window_name = "Pyramids Demo";


/*
* @function main
*/
int main(int argc, char** argv)
{
	/// General instructions
	printf("\n Zoom In-Out demo  \n ");
	printf("------------------ \n");
	printf(" * [u] -> Zoom in  \n");
	printf(" * [d] -> Zoom out \n");
	printf(" * [ESC] -> Close program \n \n");

	/// Test image - Make sure it s divisible by 2^{n}
	src = imread("Necromancer.jpg");
	if (!src.data)
	{
		printf(" No data! -- Exiting the program \n");
		return -1;
	}

	tmp = src;
	dst = tmp;

	/// Create window
	namedWindow(window_name, WINDOW_AUTOSIZE);
	imshow(window_name, dst);

	/// Loop
	while (true)
	{
		int c;
		c = waitKey(10);

		if ((char)c == 27)
		{
			break;
		}
		if ((char)c == 'u')
		{
			pyrUp(tmp, dst, Size(tmp.cols * 2, tmp.rows * 2));
			printf("** Zoom In: Image x 2 \n");
		}
		else if ((char)c == 'd')
		{
			pyrDown(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2));
			printf("** Zoom Out: Image / 2 \n");
		}

		imshow(window_name, dst);
		tmp = dst;
	}
	return 0;
}