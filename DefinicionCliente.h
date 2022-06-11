#include<iostream>
using namespace::std;

#ifndef DEFINICIONCLIENTE_H
#define DEFINICIONCLIENTE_H


class DefinicionCliente
{
    public:
        int puntos;
        int edad;
        long cedula, total;
        string nombre, apellido, genero, orden;

        DefinicionCliente();
        virtual ~DefinicionCliente();

        //definicion de funciones o comportamiento de la clase
        //funciones set

        void setCedula ();
       // void setCedula (long numero);
        void setNombre();
        //void setNombre (string nom);
        void setApellido();
        //void setApellido (string ape);
        void setGenero();
       // void setGenero (string gen);
        void setEdad();
       // void setEdad (int ed);
        void setPuntos();
        //void setTotalcuenta();
        //void setTotalcuenta (long cuen);
        void setOrden();
        //void setOrden (string ord);

        virtual void setTotalcuenta ();


        //definicion de funciones get

        long getCedula();
        long getPuntos();
        string getNombre();
        string getApellido();
        string getGenero();
        string getOrden();
        //long getTotalcuenta();
        int getEdad();
        long getTotalcuenta();


    protected:

    private:
};

#endif // DEFINICIONCLIENTE_H
