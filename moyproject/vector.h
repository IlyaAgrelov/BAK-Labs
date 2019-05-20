
#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>

struct Vector {
    double x, y, z;
    Vector();
    Vector(double g);
    Vector(double u, double v);
    double Length();
    double abs();
};

Vector operator+(const Vector& v, const Vector& u);

Vector operator-(const Vector& v, const Vector& u);

Vector operator*(const double& a, Vector& u);

Vector operator/(Vector& u, const double& a);



#endif // VECTOR_H
