class vec3 {
public:
    float p[3];
    vec3(float p0, float p1, float p2) { p[0] = p0; p[1] = p1; p[2] = p2; };
    inline float x() const { return p[0]; };
    inline float y() const { return p[1]; };
    inline float z() const { return p[2]; };

    inline vec3 operator-() const { return vec3(-p[0], -p[1], -p[2]); }
    inline float operator[](int i) const { return p[i]; }
};

inline std::istream& operator>>(std::istream &is, vec3 &v) {
    is >> v.p[0] >> v.p[1] >> v.p[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, vec3 &v) {
    os << v[0] << " " << v[1] << " " << v[2];
    return os;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

// Hadamard product
inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

// Hadamard division
inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

inline vec3 operator*(const float t, const vec3 &v) {
    return vec3(t*v[0], t*v[1], t*v[2]);
}

inline vec3 operator*(const vec3 &v, const float t) {
    return vec3(t*v[0], t*v[1], t*v[2]);
}

inline vec3 operator/(const vec3 &v, const float t) {
    return vec3(v[0]/t, v[1]/t, v[2]/t);
}

inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1[0] + v2[0]
         + v1[1] + v2[1]
         + v1[2] + v2[2];
}
