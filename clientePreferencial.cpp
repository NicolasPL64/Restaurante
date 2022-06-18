#include <iostream>
using namespace::std;
#include "clientePreferencial.h"


clientePreferencial::clientePreferencial()
{
   puntos = 0;
   cliente = false; //ctor
}

clientePreferencial::~clientePreferencial()
{
    //dtor
}

//setter

void clientePreferencial::setCliente(bool _cliente){
    cliente = _cliente;
}

void clientePreferencial::setPuntos(long _puntos)
{
    puntos = _puntos;
}

void clientePreferencial::setTotalcuenta(long _total)
{
    total = _total;
}

//getter

