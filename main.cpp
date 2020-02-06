// DONE Implement vec3 library
// DONE Import TGA library
// DONE Implement point drawing
// DONE Implement Bresenham's line drawing algorithm
// DONE Implement vec2 library
// DONE Implement triangle drawing
// DONE Implement scanline algorithm for filled triangles
// TODO Implement obj mesh loading

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

void triangle(vec2 v0, vec2 v1, vec2 v2, TGAImage &img, TGAColor color) {
    // Bubble sort verticies acending by y-value
    if (v0.y > v1.y) std::swap(v0, v1);
    if (v1.y > v2.y) std::swap(v1, v2);
    if (v0.y > v1.y) std::swap(v0, v1);

    // Marks partition point to create two flat sided triangles
    // Use intercept theorem and similar triangles to find v3.x
    int v3_x = static_cast<int>(v2.x + ((v1.y-v2.y)/(v0.y-v2.y) * (v0.x-v2.x)));
    vec2 v3(v3_x, v1.y);

    int total_height = v2.y - v0.y;

    for (int y=0; y<total_height; y++) {
        // Use conditionals to accound for both triangle segments
        bool second_half = y > v3.y - v0.y || v3.y == v0.y;
        int segment_height = second_half ? v2.y - v1.y : v1.y - v0.y;

        // Get the position of the left and right edge of the triangle at ypos
        float alpha = (float) y / total_height;
        float beta  = (float)(y - (second_half ? v1.y - v0.y : 0))/segment_height;
        vec2 left =                v0 + (v2 - v0) * alpha;
        vec2 right = second_half ? v1 + (v2 - v1) * beta : v0 + (v1 - v0) * beta;
        if (left.x > right.x) std::swap(left, right);

        // Line fill from left to right edge
        for (int x=left.x; x <= right.x; x++) {
            img.set(x, v0.y+y, color);
        }
    }
}

int main() {
    TGAImage img(width, height, TGAImage::RGB);

    vec2 v0[3] = {vec2(10, 70),   vec2(50, 160),  vec2(70, 80)};
    vec2 v1[3] = {vec2(180, 50),  vec2(150, 1),   vec2(70, 180)};
    vec2 v2[3] = {vec2(180, 150), vec2(120, 160), vec2(130, 180)};
    triangle(v0[0], v0[1], v0[2], img, red);
    triangle(v1[0], v1[1], v1[2], img, white);
    triangle(v2[0], v2[1], v2[2], img, green);

    // Set origin at bottom left instead of top left of image
    img.flip_vertically();
    img.write_tga_file("output.tga");

    return 0;
}
