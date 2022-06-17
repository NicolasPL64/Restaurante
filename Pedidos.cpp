#include <iostream>
using namespace std;
#include "Pedidos.h"

Pedidos::Pedidos()
{
    numPedido = ordenes = nombreFull = cedula = direccion = "-";
    total = posicion = 0;
}

Pedidos::~Pedidos()
{
    //dtor
}


//Setters
void Pedidos::setPosicion(int _posicion){
    posicion = _posicion;
}

void Pedidos::setNumPedido(string _numPedido){
    numPedido = _numPedido;
}

void Pedidos::setOrdenes(string _ordenes){
    ordenes = _ordenes;
}

void Pedidos::setNombreFull(string _nombreFull){
    nombreFull = _nombreFull;
}

void Pedidos::setCedula(string _cedula){
    cedula = _cedula;
}

void Pedidos::setDireccion(string _direccion){
    direccion = _direccion;
}

void Pedidos::setTotal(long _total){
    total = _total;
}

//Getters
int Pedidos::getPosicion(){
    return posicion;
}

string Pedidos::getNumPedido(){
    return numPedido;
}

string Pedidos::getOrdenes(){
    return ordenes;
}

string Pedidos::getNombreFull(){
    return nombreFull;
}

string Pedidos::getCedula(){
    return cedula;
}

string Pedidos::getDireccion(){
    return direccion;
}

long Pedidos::getTotal(){
    return total;
}
