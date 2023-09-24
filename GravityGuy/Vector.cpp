/**********************************************************************************
// Vector (Codigo Fonte)
// 
// Criação:     18 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Classe para representar um vetor
//
**********************************************************************************/

#include "Vector.h"

// ------------------------------------------------------------------------------

const double Vector::PI = 3.1415926535;

// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------

Vector::Vector()
{
    angle = 0;
    magnitude = 0;
}

// ------------------------------------------------------------------------------

Vector::Vector(float ang, float mag)
{
    angle = ang;
    magnitude = mag;
}

// ------------------------------------------------------------------------------

void Vector::setXY(float x, float y)
{
    this->x = x;
    this->y = y;
    magnitude = sqrt((x * x) + y * y);
    angle = double(atan2(y, x)) * 180.0f / PI;
}

void Vector::setPolar(float ang, float mag)
{
    this->magnitude = magnitude;
    this->angle = angle;
    x = magnitude * cos(angle * PI / 180.0f);
    y = magnitude * sin(angle * PI / 180.0f);
}

void Vector::Rotate(float theta)
{
    angle -= theta;

    // mantém o ângulo entre 0 e 359 graus
    while (angle < 0 || angle >= 360)
        angle += (angle >= 360 ? -360.0f : 360.0f);
}

// ------------------------------------------------------------------------------

void Vector::Scale(float factor)
{
    magnitude *= factor;
}

void Vector::Add(const Vector& v)
{
    float rx, ry;

    rx = XComponent() + v.XComponent();
    ry = YComponent() + v.YComponent();

    magnitude = sqrt(pow(rx, 2.0f) + pow(ry, 2.0f));

    // ajusta o ângulo de acordo com o quadrante do vetor resultante
    if (rx > 0)
    {
        // 1o Quadrante
        if (ry >= 0)
        {
            // acha o ângulo em radianos
            angle = atan(ry / rx);
            // converte de radianos para graus
            angle = float((180.0 * angle) / PI);
        }
        // 4o Quadrante
        else // (ry < 0)
        {
            // acha o ângulo em radianos
            angle = atan(ry / rx);
            // converte de radianos para graus
            angle = float((180.0 * angle) / PI) + 360.0f;
        }
    }
    // 2o e 3o Quadrante
    else if (rx < 0)
    {
        // acha o ângulo em radianos
        angle = atan(ry / rx);
        // converte de radianos para graus
        angle = float((180.0 * angle) / PI) + 180.0f;
    }
    else // (rx == 0)
    {
        if (ry > 0)
            angle = 90.0f;
        else if (ry < 0)
            angle = 270.0f;
        else // (ry == 0)
            angle = v.angle;
    }
}

// ------------------------------------------------------------------------------

Vector Vector::operator+(const Vector* vector)
{
    Vector result;
    result.setXY(this->x + vector->x, this->y + vector->y);
    return result;
}

// ------------------------------------------------------------------------------

Vector Vector::operator*(float scalar)
{
    Vector result;
    result.setXY(this->x * scalar, this->y * scalar);
    return result;
}

// ------------------------------------------------------------------------------

Vector Vector::operator=(const Vector* vector)
{
    this->setXY(vector->x, vector->y);
    return *this;
}
