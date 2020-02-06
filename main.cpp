// DONE Implement vec3 library
// DONE Import TGA library
// DONE Implement point drawing
// DONE Implement Bresenham's line drawing algorithm
// DONE Implement vec2 library
// DONE Implement triangle drawing
// TODO Implement Bresenham's filled triangle drawing algorithm
// TODO Implement mesh rendering

#include <iostream>
#include <math.h>
#include "vec2.h"
#include "tga.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255,   0,   0, 255);
const TGAColor green = TGAColor(0,   255, 0,   255);

const int width = 200;
const int height = 200;

// Bresenham's line drawing algorithm
void line(vec2 p0, vec2 p1, TGAImage &img, TGAColor color) {
    bool steep = false;

    // If the line's height is greater than its width is, transpose it
    if (fabs(p0.x-p1.x) < fabs(p0.y-p1.y)) {
        std::swap(p0.x, p0.y);
        std::swap(p1.x, p1.y);
        steep = true;
    }

    // Make line left to right
    if (p0.x > p1.x) {
        std::swap(p0.x, p1.x);
        std::swap(p0.y, p1.y);
    }

    int y = p0.y;
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    float error2 = 0;
    float derror2 = fabs(dy)*2;

    for (int x=p0.x; x <= p1.x; x++) {
        // De-transpose
        if (steep) {
            img.set(y, x, color);
        } else {
            img.set(x, y, color);
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (p1.y > p0.y ? 1 : -1);
            error2 -= dx*2;
        }
    }
}

void triangle(vec2 t0, vec2 t1, vec2 t2, TGAImage &img, TGAColor color) {
    line(t0, t1, img, color);
    line(t1, t2, img, color);
    line(t2, t0, img, color);
}

int main() {
    TGAImage img(width, height, TGAImage::RGB);

    vec2 t0[3] = {vec2(10, 70),   vec2(50, 160),  vec2(70, 80)};
    vec2 t1[3] = {vec2(180, 50),  vec2(150, 1),   vec2(70, 180)};
    vec2 t2[3] = {vec2(180, 150), vec2(120, 160), vec2(130, 180)};
    triangle(t0[0], t0[1], t0[2], img, red);
    triangle(t1[0], t1[1], t1[2], img, white);
    triangle(t2[0], t2[1], t2[2], img, green);

    // Set origin at bottom left instead of top left of image
    img.flip_vertically();
    img.write_tga_file("output.tga");

    return 0;
}
