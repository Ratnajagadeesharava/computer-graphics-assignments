#include "rgba_to_rgb.h"
#include <iostream>
void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{

	// width = 383
	//height = 385
	//total rgba values = 383*385*4
	int rgbaSize = rgba.size();
	// 
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int j = 0;
  for (int i = 0; i < rgbaSize; i++) {
	  if ((i + 1) % 4 != 0) {

		   rgb[j] = rgba[i];
		  j++;
	  }
	  
	}
  //std::cout << rgba[0] << "  rgb:" << rgb[0] << std::endl;
  ////////////////////////////////////////////////////////////////////////////
}
