#include <iostream>
using namespace std;
#include "Cliente.h"

Cliente::Cliente()
{
    puntos = orden = 0;
}

Cliente::~Cliente()
{
    //dtor
}

//Setter
void Cliente::setPuntos(long _puntos)
{
    puntos = _puntos;
}

void Cliente::setOrden()
{
}

//Getters
long Cliente::getPuntos()
{
    return puntos;
}

int Cliente::getOrden()
{
    return orden;
}
