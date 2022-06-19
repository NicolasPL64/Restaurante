#include <iostream>
using namespace std;
#ifndef PEDIDOS_H
#define PEDIDOS_H

class Pedidos
{
    public:
        Pedidos();
        virtual ~Pedidos();

        ///Métodos
        //Setter
        void setPosicion(int);
        void setNumPedido(string);
        void setOrdenes(string);
        void setNombreFull(string);
        void setCedula(string);
        void setDireccion(string);
        void setTotal(long);

        //Getter
        int getPosicion();
        string getNumPedido();
        string getOrdenes();
        string getNombreFull();
        string getCedula();
        string getDireccion();
        long getTotal();


    protected:

    private:
        ///Atributos
        string numPedido, ordenes, nombreFull, cedula, direccion;
        long total;
        int posicion;
};

#endif // PEDIDOS_H
