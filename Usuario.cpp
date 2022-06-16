#include <iostream>
using namespace std;
#include "Usuario.h"



Usuario::Usuario()
{
    user = pass = nombre = apellido = cedula = "-";
    activo = true;
}

Usuario::~Usuario()
{
    //dtor
}


//Setter
void Usuario::setUser(string u)
{
    user = u;
}

void Usuario::setPass(string p)
{
    pass = p;
}

void Usuario::setNombre(string _nombre)
{
    nombre = _nombre;
}

void Usuario::setApellido(string _apellido)
{
    apellido = _apellido;
}

void Usuario::setCedula(string _cedula)
{
    cedula = _cedula;
}

void Usuario::setActivo(bool _activo)
{
    activo = _activo;
}


//Getter
string Usuario::getUser()
{
    return user;
}

string Usuario::getPass()
{
    return pass;
}

string Usuario::getNombre()
{
    return nombre;
}

string Usuario::getApellido()
{
    return apellido;
}

string Usuario::getCedula()
{
    return cedula;
}

bool Usuario::getActivo()
{
    return activo;
}



