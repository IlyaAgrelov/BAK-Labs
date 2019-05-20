#include "spring.h"
#include "vector.h"
#include "point.h"
#include "cmath"

Vector :: Vector() {
    x = 0;
    y = 0;
    z = 0;
}

Vector :: Vector(double g) {
    x = 0;
    y = g;
    z = 0;
}

Vector :: Vector(double u, double v) {
    x = u;
    y = v;
    z = 0;
}

Vector operator+(const Vector& v, const Vector& u) {
    Vector r(v.x + u.x, v.y + u.y);
    return r;
}

Vector operator-(const Vector& v, const Vector& u) {
    Vector r(v.x - u.x, v.y - u.y);
    return r;
}

Vector operator*(const double& a, Vector& u) {
    u.x *= a;
    u.y *= a;
    return u;
}

Vector operator/(Vector& u, const double& a) {
   if (a != 0.0) {
       u.x /= a;
       u.y /= a;
   }
   return u;
}

double Vector :: abs() {
    return sqrt(x*x + y*y + z*z);
}

double Vector :: Length() {
    return sqrt(x*x + y*y + z*z);
}
