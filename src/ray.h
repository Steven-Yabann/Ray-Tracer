#ifndef RAY_H
#define RAY_H

#include "vec3.h"   // We use vec3 for both origin and direction

// The ray class models a ray in 3D space
// A ray is defined bu an origin and direction vector
// The function P(t) gives the position on the ray at parameter t

class ray {
    public:
        // Default constructor
        ray () {}

        // Parametized constructor
        // Creates a ray from a given origin and direction
        ray (const point3& origin, const vec3& direction) 
            : orig(origin), dir(direction){}

        // Return orig of ray
        const point3& origin() const { return orig; }
        // Return dir of ray
        const vec3& direction() const { return dir; }

        // Return the point along the ray at distance 't'
        // Equation: P(t) = origin + t * direction
        point3 at(double t) const {
            return orig + t * dir;
        }
    
    private:
        point3 orig;
        vec3 dir;
}
#endif