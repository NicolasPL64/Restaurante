#include <iostream>
using namespace std;
#ifndef DOMICILIARIO_H
#define DOMICILIARIO_H
#include "Usuario.h"

class Domiciliario : public Usuario
{
    public:
        Domiciliario();
        virtual ~Domiciliario();

        ///Atributos
        bool esDomi;

        ///Métodos
        //Setters
        void setDomiciliario(bool);

        //Getters
        bool getDomiciliario();

    protected:

    private:
};

#endif // DOMICILIARIO_H
