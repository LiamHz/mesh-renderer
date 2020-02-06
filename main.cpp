// DONE Implement Vec3 library
// DONE Import TGA library
// DONE Implement display of points
// DONE Implement Bresenham's line drawing algorithm
// TODO Implement triangle drawing
// TODO Implement mesh rendering

#include <iostream>
#include <math.h>
#include "vec3.h"
#include "tga.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255,   0,   0, 255);

// Bresenham's line drawing algorithm
void line(int x0, int y0, int x1, int y1, TGAImage &img, TGAColor color) {
    bool steep = false;

    // If the line's height is greater than its width is, transpose it
    if (std::abs(x0-x1) < std::abs(y0-y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }

    // Make line left to right
    if (x0 > x1) {
        std::swap(x0, x1);
    }

    int y = y0;
    int dx = x1 - x0;
    int dy = y1 - y0;
    float error2 = 0;
    float derror2 = std::abs(dy)*2;

    for (int x=x0; x <= x1; x++) {
        if (steep) {
            img.set(y, x, color);
        } else {
            img.set(x, y, color);
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (y1 > y0 ? 1 : -1);
            error2 -= dx*2;
        }
    }
}

int main() {
    TGAImage img(100, 100, TGAImage::RGB);

    line(10, 10, 60, 50, img, white);
    line(80, 40, 13, 20, img, red);
    line(10, 10, 10, 80, img, white);

    // Set origin at bottom left instead of top right of image
    img.flip_vertically();
    img.write_tga_file("output.tga");

    return 0;
}
