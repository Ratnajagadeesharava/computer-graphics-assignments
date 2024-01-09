#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code from computer-graphics-raster-images
    std::ofstream ppmFile(filename, std::ios::binary);
    //ppm header
    if (num_channels == 3)
        ppmFile << "P3\n";
    if (num_channels == 1)
        ppmFile << "P2\n";
    ppmFile << width << " " << height << "\n";
    ppmFile << "255\n";
    int s = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < num_channels; k++) {
                int a = data.at(s);
                ppmFile << a;
                s++;
                ppmFile << " ";
            }
            ppmFile << " ";
        }
        ppmFile << "\n";
    }




    ppmFile.close();
    std::cout << filename << "   Created" << std::endl;
    return true;
  
  ////////////////////////////////////////////////////////////////////////////
}
