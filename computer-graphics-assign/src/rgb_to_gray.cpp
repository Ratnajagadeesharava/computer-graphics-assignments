#include "rgb_to_gray.h"
#include <iostream>

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // NTSC Formula gray = r*0.299+g*0.587+0.114*B
  // height = 385
  // width = 383
  // graysize = 385*383 = 147455
  // rgbsize = graysize*14755
  ////////////////////////////////////////////////////////////////////////////
  int l = rgb.size();
  //std::cout << height<<"  " << width <<"  "<< rgb.size()<< std::endl;
  int j = 0;
  for (int i = 0; i < l; i=i+3) {
	  int r =(int) rgb[i];
	  int g = (int)rgb[i + 1];
	  int b = (int)rgb[i + 2];
	  gray[j] =(char) (r * 0.299 + g * 0.587 + b * 0.114);
	  j++;
  }
  //std::cout << gray.size()<< std::endl;
  //
}


