#include <iostream>
using namespace::std;
#include "clientePreferencial.h"


clientePreferencial::clientePreferencial()
{
    puntos = 0;
    clientePref = false; //ctor
}

clientePreferencial::~clientePreferencial()
{
    //dtor
}

//setter

void clientePreferencial::setClientePref(bool _clientePref)
{
    clientePref = _clientePref;
}

void clientePreferencial::setPuntos(int _puntos)
{
    puntos = _puntos;
}

void clientePreferencial::setTotalcuenta(long _total)
{
    total = _total;
}

//getter

bool clientePreferencial::getClientePref()
{
    return clientePref;
}

int clientePreferencial::getPuntos()
{
    return puntos;
}
