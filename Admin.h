#include <iostream>
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H
#include "Usuario.h"


class Admin : public Usuario
{
    public:
        Admin();
        virtual ~Admin();

    protected:

    private:
};

#endif // ADMIN_H
