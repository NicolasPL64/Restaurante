#include <iostream>
using namespace std;
#include "Comidas.h"

Comidas::Comidas()
{
    ingrediente = nombre = "-";
    ingredienteString = "";
    precio = posicion = 0;
    vIngredientes.clear();
    activo = true;
}

Comidas::~Comidas()
{
    //dtor
}


//Setter
void Comidas::setIngrediente(string _ingrediente)
{
    vIngredientes.push_back(_ingrediente);
}

void Comidas::setNombre(string _nombre)
{
    nombre = _nombre;
}

void Comidas::setPrecio(int _precio)
{
    precio = _precio;
}

void Comidas::setPosicion(int _posicion)
{
    posicion = _posicion;
}

void Comidas::setActivo(bool _activo)
{
    activo = _activo;
}


//Getter
string Comidas::getIngrediente() //Condensa todos los menús del vector en un string
{
    for (int i=0; i < vIngredientes.size(); i++)
    {
        if (i == vIngredientes.size()-1) //Condicional para agregar o no una coma
        {
            ingrediente = vIngredientes.at(i);
            cout<<ingrediente;
        }
        else
        {
            ingrediente = vIngredientes.at(i);
            cout<<ingrediente<<", ";
        }
    }
    return "";
}

string Comidas::getIngredienteString()
{
    for (int i=0; i < vIngredientes.size(); i++)
    {
        if (i == vIngredientes.size()-1) //Condicional para agregar o no una coma
        {
            ingredienteString += vIngredientes.at(i);
        }
        else
        {
            ingredienteString += vIngredientes.at(i) + ",";
        }
    }
    return ingredienteString;
}

string Comidas::getNombre()
{
    return nombre;
}

int Comidas::getPrecio()
{
    return precio;
}

int Comidas::getPosicion()
{
    return posicion;
}

bool Comidas::getActivo()
{
    return activo;
}


//Sort
bool operator<(Comidas &s1, Comidas &s2)
{
    if(s1.getPosicion() < s2.getPosicion())
        return true;
    else
        return false;
}
