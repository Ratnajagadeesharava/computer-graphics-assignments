#include "reflect.h"
#include <iostream>
using namespace std;

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
  vector<vector<vector<unsigned char>>> storage;
  storage.resize(height);
  int l = height * width;
  try {

	  int r = 0;
	  for (int i = 0; i < height; i++)
	  {
		  storage[i].resize(width);
		  int l = 0;
		  for (int j = 0; j < width * num_channels; j = j + num_channels) {
			  for (int k = 0; k < num_channels; k++) {
				  storage[i][l].push_back(input[r]);
				  r++;
			  }
			  l++;
		  }
	  }
	  int k = 0;

	  for (int i = 0; i < height; i++) {
		  reverse(storage[i].begin(), storage[i].end());
	  }
	  for (int i = 0; i < height; i++) {
		  for (int j = 0; j < width; j++) {
			  for (int l = 0; l < num_channels; l++) {
				  reflected[k] = storage[i][j][l];
				  k++;
			  }
		  }
	  }
	  cout << "Reeflection of the image is created" << endl;
  }
  catch (const exception e) {
	  /*cout << e.what() << endl;*/
  }
  
	
}
