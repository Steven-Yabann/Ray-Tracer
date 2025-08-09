#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"   // Include the vec3 class, which also represents colors
#include <iostream> 

// Define color as an alias for vec3
// Gives semantic meaning - we use vec3 for both vectors and colors
using color = vec3;

// write_color - Outputs a pixel's color in [0, 255] format

// Parameters:
// - out: where to write the color (e.g., std::cout or a file stream)
// - pixel_color: a vec3 representing the color, with components typically in range[0,1]

void write_color(std::ostream& out, const color& pixel_color) {
    // Extract RGB components from the color vector
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Convert the color from [0,1] float range to [0, 255] integer range
    // Multiply by 255.999 to avoid rounding errors near 1.0
    int rbyte = static_cast<int>(255.999 * r);
    int gbyte = static_cast<int>(255.999 * g);
    int bbyte = static_cast<int>(255.999 * b);

    // Write the RGB color as space-separated values
    out << rbyte << ' ' << gbyte << ' ' << bbyte << "\n";
}

#endif