#include<iostream>
using namespace::std;

#include "DefinicionCliente.h"

DefinicionCliente::DefinicionCliente()
{
    edad = total = cedula = 0;
            nombre = apellido = genero = orden = "-";
}

DefinicionCliente::~DefinicionCliente()
{
    //dtor
}

//definicion de funciones o comportamiento de la clase
        //funciones set

/*        void DefinicionCliente::setCedula (long numero){
                cedula = numero;
        }*/

        void DefinicionCliente::setCedula (){
            cout<< "ingrese el numero del documento de identidad: "<<endl;
            cin>>cedula;
        }

        void DefinicionCliente::setNombre(){
            fflush(stdin);
            cout<<"Ingrese el nombre del cliente: "<<endl;
            getline(cin, nombre);
        }

       /* void DefinicionCliente::setNombre (string nom){
                nombre = nom;
        }*/

        void DefinicionCliente::setApellido(){
            fflush(stdin);
            cout<<"Ingrese el apellido del cliente: "<<endl;
            getline(cin, apellido);
        }

       /* void DefinicionCliente::setApellido (string ape){
                apellido = ape;
        }*/

        void DefinicionCliente::setGenero(){
            fflush(stdin);
            cout<<"Ingrese el genero del cliente: "<<endl;
            getline(cin, genero);
        }

       /* void DefinicionCliente::setGenero (string gen){
                genero = gen;
        }*/

        void DefinicionCliente::setEdad(){
            cout<<"Ingrese la edad del cliente: "<<endl;
            cin>>edad;
        }

       /* void DefinicionCliente::setEdad (int ed){
                edad = ed;
        }*/

        void DefinicionCliente::setTotalcuenta(){
            cout<<"Ingrese el valor de compra: "<<endl;
            cin>>total;
        }

/*        void DefinicionCliente::setTotalcuenta (long cuen){
                total = cuen;
        }*/

        void DefinicionCliente::setOrden(){
            fflush(stdin);
            cout<<"Ingrese la orden del cliente: "<<endl;
            getline(cin, orden);
        }

       /* void DefinicionCliente::setOrden (string ord){
                orden = ord;
        }*/

/* *******************************************************************************************************************
        Definicion de funciones get */


        long DefinicionCliente::getCedula(){
            return cedula;
        }

        string DefinicionCliente::getNombre(){
            return nombre;
        }

        string DefinicionCliente::getApellido(){
            return apellido;
        }

        string DefinicionCliente::getGenero(){
            return genero;
        }

        string DefinicionCliente::getOrden(){
            return orden;
        }

        long DefinicionCliente::getTotalcuenta(){
            return total;
        }
