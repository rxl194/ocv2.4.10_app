#include <stdio.h>
#include <string>
#include <opencv2/opencv.hpp>

#include "Config.h"

using namespace cv;

int main (int argc, char** argv)
{
  Mat image;
  if (argc != 2) {
    char imgFileName[1024];
    sprintf (imgFileName, "%s/%s", IMAGE_FOLDER, "lena.jpg");
    printf ("\n%s\n", imgFileName);
    image = imread (imgFileName, 1);
  } else {
    printf("\nargv[1]\n");
    image = imread (argv[1], 1);
  }

  if (!image.data) {
    printf ("No image data \n");
    return -1;
  }
  namedWindow ("Display Image", WINDOW_AUTOSIZE);
  imshow ("Display Image", image);

  waitKey (0);

  return 0;
}