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
        int precio;
        vector <string> vIngredientes;

        ///Métodos
        //Setter
        void setIngrediente(string);
        void setNombre(string);
        void setPrecio(int);


        //Getter
        string getIngrediente();
        string getNombre();
        int getPrecio();

    protected:

    private:
};

#endif // COMIDAS_H
