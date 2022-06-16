#include <iostream>
using namespace std;
#include "Cliente.h"

Cliente::Cliente()
{
    puntos = orden = total = 0;
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

void Cliente::setTotalcuenta(){

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

long Cliente::getTotalcuenta(){
    return total;
}
