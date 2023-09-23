#include "rotate.h"
#include <iostream>
using namespace std;
vector<vector<unsigned char>> columnOfMatrix(vector<vector<vector<unsigned char>>>& matrix, int j, int height);
void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
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
	  vector<vector<vector<unsigned char>>> rotatedStorage;
	  rotatedStorage.resize(width);
	  // rotating logic 
	  for (int i = 0; i < width; i++) {
		  vector<vector<unsigned char>>  row = columnOfMatrix(storage,i,height);
		  //cout<<i <<"     " << row.size() << endl;
		  rotatedStorage[i]=row;
	  }



	  for (int i = 0; i < width; i++) {
		  for (int j = 0; j < height; j++) {
			  for (int l = 0; l < num_channels; l++) {
				  rotated[k] = rotatedStorage[i][j][l];
				  k++;
			  }
		  }
	  }
	  cout << "Rotated of the image is created" << endl;
  }
  catch (const exception e) {
	  /*cout << e.what() << endl;*/
  }
}

vector<vector<unsigned char>> columnOfMatrix(vector<vector<vector<unsigned char>>>& matrix, int j,int height){
	vector<vector<unsigned char>> row;
	for (int i = 0; i < height; i++) {
		row.push_back(matrix[i][j]);
	}
	return row;
}
