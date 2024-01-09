#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"



std::vector<unsigned char> generateHue(unsigned char r, unsigned char g, unsigned char b) {
	int ri = (int)r;
	ri = ri / 255;
	int gi = (int)g;
	gi = gi / 255;
	int bi = (int)b;
	bi = bi / 255;
	int Cmax = std::max(ri, gi, bi);
	int Cmin = std::min(ri, gi, bi);
	int delta = Cmax - Cmin;
	char h;
	char s;
	char v = (char)Cmax;
	std::vector<unsigned char> hsv;
	hsv.resize(3);
	if (delta == 0) {
		h =(char) 0;
		s = (char)0;
	}
	else {
		s = (char)(delta / Cmax);
		if (Cmax == ri) {
			h = (char)(60 * ((gi - bi) / delta));
		}
		else if (Cmax == gi) {
			h = (char)((60 * (((bi - ri) / delta) + 2)));

		}
		else {
			h = (char)((60 * (((ri - gi) / delta) + 4)));
		}
		hsv[0] = h;
		hsv[1] = s;
		hsv[2] = v;
	}
	return hsv;
}
void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < rgb.size(); i = i + 3) {
	  std::vector<unsigned char> hsv = generateHue(rgb[i], rgb[i+1], rgb[i+2]);
	  shifted[i] = hsv[0];
	  shifted[i + 1] = hsv[1];
	  shifted[i + 2] = hsv[2];
  }

}

