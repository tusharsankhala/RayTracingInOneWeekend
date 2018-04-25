#pragma once
#include <iostream>
#include <math.h>
#include <stdlib.h>

class Vec3{
    public:
        float e[3];
    public:
        Vec3() {};
        Vec3(float e0,float e1, float e2) {e[0] = e0; e[1] = e1; e[2] = e2;}
        inline float x() const { return e[0]; }
        inline float y() const { return e[1]; }
        inline float z() const { return e[2]; }
        inline float r() const { return e[0]; }
        inline float g() const { return e[1]; }
        inline float b() const { return e[2]; }

        inline const Vec3 & operator+() const { return *this; }
        inline Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
        inline float operator[] (int i) const { return e[i]; }
        inline float& operator[] (int i) { return e[i]; }
        inline Vec3& operator+=(const Vec3 & v2);
        inline Vec3& operator*=(const Vec3 & v2);
        inline Vec3& operator-=(const Vec3 & v2);
        inline Vec3& operator/=(const Vec3 & v2);
        inline Vec3& operator*=(const float t);
        inline Vec3& operator/=(const float t);

        inline float length() const {
            return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
        }

        inline float squared_length() const {
            return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
        }

        inline void make_unit_vector();
};


//输入流 输入格式
inline std::istream& operator>>(std::istream &is, Vec3 &t) {
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

//输出流 输出格式
inline std::ostream& operator<<(std::ostream &os, const Vec3 &t) {
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}

//生成单位向量 向量/向量的模
inline void Vec3::make_unit_vector() {
    float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
    e[0] *= k; e[1] *= k; e[2] *= k;
}

//两向量相加
inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

//两向量相减
inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

//两向量相乘（for colors）
inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

//两向量相除（for colors）
inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

//一个标量乘一个向量
inline Vec3 operator*(float t, const Vec3 &v) {
    return Vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

//一个向量除以一个标量
inline Vec3 operator/(Vec3 v, float t) {
    return Vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

//一个向量乘一个标量
inline Vec3 operator*(const Vec3 &v, float t) {
    return Vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

//两向量点乘（求内积，得一个常数）（for locations）
inline float dot(const Vec3 &v1, const Vec3 &v2) {
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

//两向量叉乘（求外积，得一个向量）（for locations）
inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return Vec3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
        (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
        (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}

// += 一个向量
inline Vec3& Vec3::operator+=(const Vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

// *= 一个向量
inline Vec3& Vec3::operator*=(const Vec3 &v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

// /= 一个向量
inline Vec3& Vec3::operator/=(const Vec3 &v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

// -= 一个向量
inline Vec3& Vec3::operator-=(const Vec3& v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

// *= 一个数
inline Vec3& Vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

// /= 一个数
inline Vec3& Vec3::operator/=(const float t) {
    float k = 1.0 / t;

    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
}

//归一化向量
inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}