#include <iostream>

class vec2 {
public:
    float x, y;
    vec2() {};
    vec2(float p0, float p1) { x = p0; y = p1; };

    inline float operator [](int i) const {
        if (i == 0) return x;
        else if (i == 1) return y;
        else throw std::invalid_argument( "index must be 0 or 1" );
    }

    inline vec2 operator -() const { return vec2(-x, -y); }
    inline vec2 operator +(const vec2 &v) const { return vec2(x+v.x, y+v.y); }
    inline vec2 operator -(const vec2 &v) const { return vec2(x-v.x, y-v.y); }
    inline vec2 operator *(const float f) const { return vec2(x*f, y*f); }
    inline vec2 operator /(const float f) const { return vec2(x/f, y/f); }

    inline bool operator ==(const vec2 &v) const { return (x == v.x && y == v.y); }
    inline bool operator !=(const vec2 &v) const { return (x != v.x || y != v.y); }

    // Hadarmard product
    inline vec2 operator *(const vec2 &v) const { return vec2(x*v.x, y*v.y); }
};

inline float dot(const vec2 &v1, const vec2 &v2) {
    return v1.x*v2.x + v1.y*v2.y;
}

inline std::istream& operator>>(std::istream &is, vec2 &v) {
    is >> v.x >> v.y;
    return is;
}
inline std::ostream& operator<<(std::ostream &os, vec2 &v) {
    os << v.x << " " << v.y;
    return os;
}
