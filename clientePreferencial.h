#include <iostream>
using namespace std;
#ifndef CLIENTEPREFERENCIAL_H
#define CLIENTEPREFERENCIAL_H
#include "Cliente.h"


class clientePreferencial: public Cliente
{
    public:
        bool cliente;
        clientePreferencial();
        virtual ~clientePreferencial();
        //setter
        void setTotalcuenta(long);
        void setCliente(bool);
        void setPuntos(long);

        //getter
        long getPuntos();
        bool getCliente();

    protected:

    private:
       long puntos;

};

#endif // CLIENTEPREFERENCIAL_H
