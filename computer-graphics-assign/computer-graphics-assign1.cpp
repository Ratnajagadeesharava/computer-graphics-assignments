// computer-graphics-assign1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "includes/read_rgba_from_png.h"
#include "includes/rgba_to_rgb.h"
#include "includes/rgb_to_gray.h"
#include "includes/reflect.h"
#include "includes/rotate.h"
#include "includes/write_ppm.h"
#include "includes/over.h"
#include "includes/simulate_bayer_mosaic.h"
#include "includes/desaturate.h"
#include "includes/desaturate.h"
#include "includes/hue_shift.h"
#include "includes/demosaic.h"

#include <vector>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "includes/stb_image.h"
inline bool read_rgba_from_png(
    const std::string& filename,
    std::vector<unsigned char>& rgba,
    int& width,
    int& height)
{
    // read a RGBA .png
    int n;
    unsigned char* rgba_raw = stbi_load(filename.c_str(), &width, &height, &n, 4);
    if (rgba_raw == NULL)
    {
        std::cout << "NO RGBA";
        return false;
    }
    // copy into vector
    rgba.reserve(height * width * 4);
    std::copy(rgba_raw, rgba_raw + height * width * 4, std::back_inserter(rgba));
    return true;
}
int main(int argc,char *argv[])
{
    std::vector<std::string> input_filenames(argv + 1, argv + argc);
    int num_inputs = argc - 1;

    if (num_inputs == 0)
    {
        const std::vector<std::string> default_input_file_names = {
    "./data/dog.png",
    "./data/glasses.png",
    "./data/laser-beams.png",
    "./data/sparkles.png"
        };
        input_filenames = default_input_file_names;
        num_inputs = 4;
        std::cout << "Hello World!\n";
    }
    // read a RGBA .png
    int width, height;
    std::vector<unsigned char> rgba;
    read_rgba_from_png(input_filenames[0], rgba, width, height);

    // Convert to RGB
    std::vector<unsigned char> rgb;
    rgba_to_rgb(rgba, width, height, rgb);

    // Write to .ppm file format
    write_ppm("rgb.ppm", rgb, width, height, 3);

    // Reflection
    std::vector<unsigned char> reflected;
    reflect(rgb, width, height, 3, reflected);
    write_ppm("reflected.ppm", reflected, width, height, 3);

    // Rotation
    std::vector<unsigned char> rotated;
    rotate(rgb, width, height, 3, rotated);
    write_ppm("rotated.ppm", rotated, height, width, 3);

    //// Convert to gray
    //std::vector<unsigned char> gray;
    //rgb_to_gray(rgb, width, height, gray);
    //write_ppm("gray.ppm", gray, width, height, 1);

    //// Create fake bayer mosaic image
    //std::vector<unsigned char> bayer;
    //simulate_bayer_mosaic(rgb, width, height, bayer);
    //write_ppm("bayer.ppm", bayer, width, height, 1);

    //// Demosaic that output
    //std::vector<unsigned char> demosaicked;
    //demosaic(bayer, width, height, demosaicked);
    //write_ppm("demosaicked.ppm", demosaicked, width, height, 3);

    //// Shift the hue of the image by 180°
    //std::vector<unsigned char> shifted;
    //hue_shift(rgb, width, height, 180.0, shifted);
    //write_ppm("shifted.ppm", shifted, width, height, 3);

    //// Partially desaturate an image by 25%
    //std::vector<unsigned char> desaturated;
    //desaturate(rgb, width, height, 0.25, desaturated);
    //write_ppm("desaturated.ppm", desaturated, width, height, 3);

    //// Alpha composite multiple images (if present)
    //std::vector<unsigned char> composite_rgba;
    //read_rgba_from_png(input_filenames[0], composite_rgba, width, height);
    //for (int f = 1; f < num_inputs; f++)
    //{
    //    std::vector<unsigned char> next_rgba;
    //    int next_height, next_width;
    //    read_rgba_from_png(input_filenames[f], next_rgba, next_width, next_height);
    //    assert(height == next_height && "height must match");
    //    assert(width == next_width && "width must match");
    //    over(next_rgba, composite_rgba, width, height, composite_rgba);
    //}
    //std::vector<unsigned char> composite;
    //rgba_to_rgb(composite_rgba, width, height, composite);
    //write_ppm("composite.ppm", composite, width, height, 3);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
