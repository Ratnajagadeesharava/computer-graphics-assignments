#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>
using namespace std;
bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    // Open a file for writing in binary mode
  std::ofstream ppmFile(filename, std::ios::binary);
  //ppm header
  ppmFile << "P6\n";
  ppmFile << width << " " << height << "\n";
  ppmFile << "255\n";
  ppmFile.write(reinterpret_cast<const char*>(data.data()), data.size());
  ppmFile.close();
  std::cout << filename<<"Created";
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
