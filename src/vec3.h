#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

// vec3 Class - Represents a 3D vector or point in space

class vec3 {
public:
    double e[3]; // Components of the vector: e[0] = x, e[1] = y, e[2] = z

    // Default constructor initializes vector to (0,0,0)
    vec3() : e{0, 0, 0} {}

    // Constructor to initialize vector with specific values
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // Getters for x,y,z components
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // Unary minus operator
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    // Access vector components using bracket notation (read-only)
    double operator[](int i) const { return e[i]; }

    // Access vector components using bracket notation (read/write)
    double& operator[](int i) { return e[i]; }

    // Add another vector to this one
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }
    
    // Multiply this vector by a scalar (in-place)
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // Divide this vector by a scalar
    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    // Return the square of the length (avoids expensive sqrt)
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    // Return the Euclidian length (Magnitude) of the vector
    double length() const {
        return std::sqrt(length_squared());
    }
};

// Alias for vec3 when used as a point in 3d space (semantic clarity)
using point3 = vec3;

// Utility funcs for vec3

// Ouput stream support: allows using std::cout << vec3
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

// The += operator is implemented for vec3, so we can use that
inline vec3 operator+(const vec3& u, const vec3& v) {
    vec3 result = u;
    result += v;
    return result;
}

// Vector Subtraction
inline vec3 operator-(const vec3& u, const vec3& v) {
    vec3 results = u;
    vec3 neg_v = -v;
    results += neg_v;
    return results; 
}

// Component-wise multiplication (not dot product!)
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(
        u.e[0] * v.e[0],
        u.e[1] * v.e[1],
        u.e[2] * v.e[2]
    );
}

// Scalar Multiplication (scalar on the left)
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

// Scalar multiplication (scalar on the right)
inline vec3 operator*(const vec3& v, double t) {
    return t * v; // Uses the other definition
}

// Scalar division
inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// Dot product: measures how aligned two vectors are
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[1]
    + u.e[1] * v.e[1]
    + u.e[2] * v.e[2];
}

// Cross product: gives a vector perpendicular to u and v
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(
        u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]
    );
}

// Normalize vector to unit length (length = 1)
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif

// The inline keyword tells the compiler to copy the function's code directly into the calling code, 
//instead of making a separate function call, which can improve performance.