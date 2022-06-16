#include <iostream>
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H
#include "Cliente.h"


class Admin : public Cliente
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
