#include <iostream>
using namespace std;
#ifndef COMIDAS_H
#define COMIDAS_H
#include "vector"

class Comidas
{
    public:
        Comidas();
        virtual ~Comidas();

        ///Atributos
        string ingrediente, nombre;
        int precio, posicion;
        vector <string> vIngredientes;

        ///M�todos
        //Setter
        void setIngrediente(string);
        void setNombre(string);
        void setPrecio(int);
        void setPosicion(int);


        //Getter
        string getIngrediente();
        string getNombre();
        int getPrecio();
        int getPosicion();

    protected:

    private:
};

#endif // COMIDAS_H
