// Implement Vec3 class
// Implement display of points
// Implement line drawing
// Implement triangle drawing
// Implement mesh rendering

#include <iostream>

#include "vec3.h"

using std::cout;



int main() {
    vec3 a(1, 2, 3);
    vec3 b(11, 22, 33);

    // Test vec3 lib
    float xpos = a.x();
    vec3 neg_a = -a;
    vec3 p = a+b;
    vec3 q = a-b;
    vec3 r = a*b;
    vec3 s = a/b;
    vec3 t = a/b;
    vec3 u = a*5;
    vec3 v = a/5;
    float w = dot(a, b);

    cout << xpos << std::endl;
    cout << neg_a << std::endl;
    cout << q << std::endl;
    cout << r << std::endl;
    cout << r << std::endl;
    cout << s << std::endl;
    cout << t << std::endl;
    cout << u << std::endl;
    cout << v << std::endl;
    cout << w << std::endl;
    cout << b << std::endl;

    return 0;
}
