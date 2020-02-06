// DONE Implement Vec3 library
// DONE Import TGA library
// TODO Implement display of points
// TODO Implement line drawing
// TODO Implement triangle drawing
// TODO Implement mesh rendering

#include <iostream>
#include "vec3.h"
#include "tga.h"

using std::cout;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

int main() {
    TGAImage image(100, 100, TGAImage::RGB);
    image.set(52, 41, red);

    // Set origin at bottom left instead of top right of image
    image.flip_vertically();

    image.write_tga_file("output.tga");

    return 0;
}
