#include <iostream>
using namespace std;
#include "Domiciliario.h"

Domiciliario::Domiciliario()
{
    esDomi = false;
}

Domiciliario::~Domiciliario()
{
    //dtor
}

//Setters
void Domiciliario::setDomiciliario(bool _esDomi){
    esDomi = _esDomi;
}

//Getters
bool Domiciliario::getDomiciliario(){
    return esDomi;
}
