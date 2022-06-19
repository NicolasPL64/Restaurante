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

        ///Métodos
        //Setters
        void setDomiciliario(bool);

        //Getters
        bool getDomiciliario();

    protected:

    private:
        ///Atributos
        bool esDomi;
};

#endif // DOMICILIARIO_H
