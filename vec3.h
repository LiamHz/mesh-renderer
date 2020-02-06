class vec3 {
public:
    int x, y, z;
    vec3(float p0, float p1, float p2) { x = p0; y = p1; x = p2; };
    // inline float x() const { return p[0]; };
    // inline float y() const { return p[1]; };
    // inline float z() const { return p[2]; };

    inline float operator [](int i) const {
        if (i == 0) return x;
        else if (i == 1) return y;
        else if (i == 2) return z;
    }

    inline vec3 operator -() const { return vec3(-x, -y, -z); }
    inline vec3 operator +(const vec3 &v) const { return vec3(x+v.x, y+v.y, z+v.z); }
    inline vec3 operator -(const vec3 &v) const { return vec3(x-v.x, y-v.y, z-v.z); }
    inline vec3 operator *(const float f) const { return vec3(x*f, y*f, z*f); }
    inline vec3 operator /(const float f) const { return vec3(x/f, y/f, z/f); }

    // Hadarmard product
    inline vec3 operator *(const vec3 &v) const { return vec3(x*v.x, y*v.y, z*v.z); }
};

inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

inline std::istream& operator>>(std::istream &is, vec3 &v) {
    is >> v.x >> v.y >> v.z;
    return is;
}
inline std::ostream& operator<<(std::ostream &os, vec3 &v) {
    os << v.x << " " << v.y << " " << v.z;
    return os;
}


