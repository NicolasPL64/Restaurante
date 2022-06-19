#include <iostream>
using namespace std;
#ifndef CLIENTEPREFERENCIAL_H
#define CLIENTEPREFERENCIAL_H
#include "Cliente.h"


class clientePreferencial: public Cliente
{
    public:
        clientePreferencial();
        virtual ~clientePreferencial();

        ///Métodos
        //setter
        void setTotalcuenta(long);
        void setClientePref(bool);
        void setPuntos(int);

        //getter
        bool getClientePref();
        int getPuntos();

    protected:

    private:
        ///Atributos
        bool clientePref;
        int puntos;
};

#endif // CLIENTEPREFERENCIAL_H
