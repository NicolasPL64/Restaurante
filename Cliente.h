#include <iostream>
using namespace std;
#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "vector"

class Cliente : public Usuario
{
    public:
        Cliente();
        virtual ~Cliente();

        ///Atributos
        long puntos, total;
        vector <string> vPedidosClase;
        string orden, direccion, numOrden;

        ///Métodos
        //Setter
        void setPuntos(long);
        void setOrden(string);
        void setDireccion(string);

        void setNumOrden(string);
        virtual void setTotalcuenta(long); //Polimorfismo

        //Getter
        long getPuntos();
        string getOrden();
        string getDireccion();
        long getTotalcuenta();
        string getNumOrden();

    protected:

    private:
};

#endif // CLIENTE_H
