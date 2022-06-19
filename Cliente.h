#include <iostream>
using namespace std;
#ifndef CLIENTE_H
#define CLIENTE_H
#include "Domiciliario.h"
#include "vector"

class Cliente : public Domiciliario
{
    public:
        Cliente();
        virtual ~Cliente();

        ///Atributos
        long total;
        vector <string> vPedidosClase;
        string orden, direccion, numOrden;

        ///Métodos
        //Setter
        void setOrden(string);
        void setDireccion(string);

        void setNumOrden(string);
        virtual void setTotalcuenta(long); //Polimorfismo

        //Getter
        string getOrden();
        string getDireccion();
        long getTotalcuenta();
        string getNumOrden();

    protected:

    private:
};

#endif // CLIENTE_H
