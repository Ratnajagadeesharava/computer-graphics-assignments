#include "demosaic.h"
#include <iostream>
using namespace std;

void convert_to_2d_array(const vector<unsigned char>& bayer, vector<vector<unsigned char>>& res, const int& height, const int& width) {
	int count = 0;
	for (int i = 0; i < height; i++) {
		res[i].resize(width);
		for (int j = 0; j < width; j++) {
			res[i][j] = bayer[count++];
		}
	}
}



void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
 vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ///////////////////////////////////////////////////////////////////////////
  // 
  // GBGBGBGBGBGBGBGB
  // RGRGRGERGRGRGRGR
  // BGBGBGBGBGBGBGBG
  // RGRGRGRGRGRGRGRG 
  // 
  ////////////////////////////////////////////////////////////////////////////
	
 /* vector < vector<unsigned char>>  bayer2;
  bayer2.resize(height);
  convert_to_2d_array(bayer, bayer2, height, width);
  vector<vector<vector<unsigned char>>> storage;
  storage.resize(height);
  for (int i = 0; i < height; i++) {
	  storage[i].resize(width);
	  for (int j = 0; j < width; j++) {
		  storage[i][j].resize(3);
		  unsigned char r;
		  unsigned char b;
		  unsigned char g;
		  if (i == 0 && j == 0) {
			  g = bayer2[i][j];
			  r = bayer2[i + 1][j];
			  b = bayer2[i][j + 1];
		  }
		  else if (i == 0) {
			  if (j % 2 == 0) {
				  g = bayer2[i][j];
				  r = bayer2[i + 1][j];
				  b = (bayer2[i][j + 1] + bayer2[i][j - 1])/2;
			  }
			  else {
				  g= (bayer2[i][j + 1] + bayer2[i][j - 1]) / 2;
				  r = (bayer2[i+1][j - 1] + bayer2[i+1][j + 1]) / 2;
				  b = bayer2[i][j];
			  }
		  }
		  else if (j == 0) {
			  if(i%2==0){
				  g = bayer2[i][j];
				  r = (bayer2[i + 1][j]+bayer2[i-1][j])/2;
				  b = bayer2[i][j + 1];
			  }
			  else{
				  g = (bayer2[i + 1][j] + bayer2[i - 1][j]) / 2;
				  r = bayer2[i][j];
				  b = (bayer2[i + 1][j+1] + bayer2[i - 1][j+1]) / 2;
			  }
		  }
		  else {
			  if (i % 2 == 0) {
				  if (j % 2 == 0) {
					  g = bayer2[i][j];
					  r = 
					}
				  else {

				  }
			  }
			  else {
				  if (j % 2 == 0) {

				  }
				  else {

				  }
			  }
		  }
	  }
  }*/
}


