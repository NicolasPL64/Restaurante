#include <iostream>
using namespace std;
#include "Cliente.h"

Cliente::Cliente()
{
    puntos = orden = total = 0;
    direccion = "-";
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

void Cliente::setDireccion(string _direccion){
    direccion = _direccion;
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

string Cliente::setDireccion(){
    return direccion;;
}
