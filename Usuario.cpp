#include <iostream>
using namespace std;
#include "Usuario.h"



Usuario::Usuario()
{
    user = pass = nombre = apellido = genero = orden = cedula = "-";
    total = 0;
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

void Usuario::setGenero()
{
    fflush(stdin);
    cout<<"Ingrese el genero del cliente: "<<endl;
    getline(cin, genero);
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

string Usuario::getGenero()
{
    return genero;
}

string Usuario::getOrden()
{
    return orden;
}

long Usuario::getTotalcuenta()
{
    return total;
}

string Usuario::getCedula()
{
    return cedula;
}
