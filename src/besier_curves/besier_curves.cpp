#include "besier_curves.h"

#include <iostream>


BesierCurve::BesierCurve(size_t checkpoint_size)
{
    _checkpoints_size = checkpoint_size;

    // pascal triangle 
    pascalLine();

    // commented trace to know if our polynomial is correct
    // std::cout << "correct polynomial: " << verifpoly() << std::endl;
    // we can now use the BesierCurve::Bernstein method to calculate the polynomial
}

BesierCurve::~BesierCurve()
{
    free(pascal_line);
}


/*
    this method calculates the corresponding pascal triangle line of our Besier Curve
*/
void BesierCurve::pascalLine(void)
{
    pascal_line = (size_t *)malloc(_checkpoints_size*sizeof(size_t));
    pascal_line[0] = 1;
    int modif;
    for (size_t line=1; line<_checkpoints_size; line++) {
        modif = 0;
        for (size_t i=1; i<=line; i++) {
            if (line == i)
                pascal_line[i] = 1;
            else {
                pascal_line[i] = pascal_line[i] + pascal_line[i-1] - modif;
                modif = pascal_line[i-1] - modif;
            }

        }
    }

}

float BesierCurve::Bernstein(size_t ind, GLfloat u)
{
    return (float(pascal_line[ind]) * std::pow(u, ind) * std::pow((1.0f - u), _checkpoints_size-1-ind));
}

bool BesierCurve::verifpoly(void)
{
    GLfloat sum = 0.0f;
    for (size_t i=0; i<_checkpoints_size; i++)
        sum += Bernstein(i, 1.f);
    return (sum==1.0f);
}