#include <iostream>
using namespace std;
#include "Comidas.h"

Comidas::Comidas()
{
    ingrediente = nombre = "-";
    precio = posicion = 0;
    vIngredientes.clear();
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

//Getter
string Comidas::getIngrediente()
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
            cout<<ingrediente<<",";
        }
    }
    return "";
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
