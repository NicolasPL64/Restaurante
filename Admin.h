#include <iostream>
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H
#include "clientePreferencial.h"


class Admin : public clientePreferencial
{
    public:
        Admin();
        virtual ~Admin();

        ///Atributos
        bool admin;

        ///Métodos
        //Setter
        void setAdmin(bool);

        //Getter
        bool getAdmin();

    protected:

    private:

};

#endif // ADMIN_H
