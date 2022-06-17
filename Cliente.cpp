#include <iostream>
using namespace std;
#include "Cliente.h"

Cliente::Cliente()
{
    puntos = total = 0;
    direccion = numOrden = "-";
    orden = "";
    vPedidosClase.clear();
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

void Cliente::setTotalcuenta(long _total)
{
    total = _total;
}

void Cliente::setDireccion(string _direccion)
{
    direccion = _direccion;
}

void Cliente::setOrden(string _orden)
{
    vPedidosClase.push_back(_orden);
}

void Cliente::setNumOrden(string _numOrden)
{
    numOrden = "#" + _numOrden;
}

//Getters
long Cliente::getPuntos()
{
    return puntos;
}

string Cliente::getOrden() //Condensa todos los pedidos del vector en un string
{
    for (int i=0; i < vPedidosClase.size(); i++)
    {
        if (i == vPedidosClase.size()-1) //Condicional para agregar o no una coma
        {
            orden += vPedidosClase.at(i);
        }
        else
        {
            orden += vPedidosClase.at(i) + ", ";
        }
    }
    return orden;
}

long Cliente::getTotalcuenta()
{
    return total;
}

string Cliente::getDireccion()
{
    return direccion;;
}

string Cliente::getNumOrden()
{
    return numOrden;
}
