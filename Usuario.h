#include <iostream>
using namespace std;
#ifndef USUARIO_H
#define USUARIO_H


class Usuario
{
    public:
        string user;
        string pass;

        Usuario();
        virtual ~Usuario();

        void setUser(string);
        void setPass(string);

        string getUser();
        string getPass();

    protected:

    private:
};

#endif // USUARIO_H
