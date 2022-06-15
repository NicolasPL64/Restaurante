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
        long puntos;
        int orden;

        ///Métodos
        //Setter
        void setPuntos(long);
        void setOrden();

        //Getter
        long getPuntos();
        int getOrden();


    protected:

    private:
};

#endif // CLIENTE_H
