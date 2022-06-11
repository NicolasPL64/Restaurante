#ifndef MEMBRESIA_H
#define MEMBRESIA_H
#include"DefinicionCliente.h"


class membresia: public DefinicionCliente
{
    public:
        membresia();
        virtual ~membresia();

        void setTotalcuenta();

    protected:

    private:
};

#endif // MEMBRESIA_H
