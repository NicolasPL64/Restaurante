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
        bool activo;

        ///Métodos
        //Setter
        void setIngrediente(string);
        void setNombre(string);
        void setPrecio(int);
        void setPosicion(int);
        void setActivo(bool);


        //Getter
        string getIngrediente();
        string getNombre();
        int getPrecio();
        int getPosicion();
        bool getActivo();

    protected:

    private:
};

#endif // COMIDAS_H
