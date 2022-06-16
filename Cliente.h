#include <iostream>
using namespace std;
#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"


class Cliente : public Usuario
{
    public:
        Cliente();
        virtual ~Cliente();

        ///Atributos
        long puntos, total;
        int orden;
        string direccion;

        ///Métodos
        //Setter
        void setPuntos(long);
        void setOrden();
        void setDireccion(string);
        virtual void setTotalcuenta(); //Polimorfismo

        //Getter
        long getPuntos();
        int getOrden();
        string getDireccion();
        long getTotalcuenta();

    protected:

    private:
};

#endif // CLIENTE_H
