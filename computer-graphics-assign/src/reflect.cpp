#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  std::vector<std::vector<unsigned char>> storage;
  storage.resize(width * height);
  int input_size = input.size();
  
  for (int i = 0; i < height; i++) {
	 /* for (int j = width+i*width; j >= i*width; j--) {
		  storage[i][j-width] = 
		}*/
  }
}
