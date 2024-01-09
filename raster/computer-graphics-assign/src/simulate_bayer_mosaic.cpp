#include "simulate_bayer_mosaic.h"
#include <iostream>
using namespace std;
void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // GRGBGRBGRBGRGBGRGBGRGBGRGBG
  ////////////////////////////////////////////////////////////////////////////

  //temp storage with vector of rgb

  vector<vector<unsigned char>> tempStorage;
  tempStorage.resize(width * height);
  int c = 0;
  for (int i = 0; i < height * width * 3; i=i+3) {
	  vector<unsigned char> rgb3d;
	  rgb3d.resize(3);
	  rgb3d[0] = rgb[i];
	  rgb3d[1] = rgb[i+1];
	  rgb3d[2] = rgb[i+2];
	  tempStorage[c] = rgb3d;
	  c++;
  }
  bool flag = false;
  for (int i = 0; i < height*width; i++) {
	  if (!flag) {
		  bayer[i] = tempStorage[i][1];
		}
	  else {
		  int k = i / width;
		  if (k % 2 == 0) {
			  bayer[i] = tempStorage[i][2];
		  }
		  else {
			  bayer[i] = tempStorage[i][0];
		  }

	  }
	  flag = !flag;
  }


}
