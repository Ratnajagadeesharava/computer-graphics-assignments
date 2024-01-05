#include "rgb_to_hsv.h"

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
  ////////////////////////////////////////////////////////////////////////////



  for (int i = 0; i < rgb.size(); i = i + 3) {
	  std::vector<unsigned char> hsv = generateHue(rgb[i], rgb[i + 1], rgb[i + 2]);
	  shifted[i] = hsv[0];
	  shifted[i + 1] = hsv[1];
	  shifted[i + 2] = hsv[2];
  }
}
