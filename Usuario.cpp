#include <iostream>
using namespace std;
#include "Usuario.h"



Usuario::Usuario()
{
    user = pass = nombre = apellido = orden = "-";
    total = cedula = 0;
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

void Usuario::setCedula(long _cedula)
{
    cedula = _cedula;
}

void Usuario::setActivo(bool _activo){
    activo = _activo;
}

void Usuario::setTotalcuenta()
{
    cout<<"Ingrese el valor de compra: "<<endl;
    cin>>total;
}

void Usuario::setOrden()
{
    fflush(stdin);
    cout<<"Ingrese la orden del cliente: "<<endl;
    getline(cin, orden);
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

long Usuario::getCedula()
{
    return cedula;
}

bool Usuario::getActivo(){
    return activo;
}

string Usuario::getOrden()
{
    return orden;
}

long Usuario::getTotalcuenta()
{
    return total;
}


