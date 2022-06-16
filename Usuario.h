#include <iostream>
using namespace std;
#ifndef USUARIO_H
#define USUARIO_H


class Usuario
{
    public:
        Usuario();
        virtual ~Usuario();

        ///Atributos
        string user, pass, nombre, apellido;
        long total, cedula;
        bool activo, admin;

        ///Métodos
        //Setter
        void setUser(string);
        void setPass(string);
        void setNombre(string);
        void setApellido(string);
        void setCedula(long);
        void setActivo(bool);
        void setAdmin(bool);
        virtual void setTotalcuenta(); //Polimorfismo

        //Getter
        string getUser();
        string getPass();
        string getNombre();
        string getApellido();
        long getCedula();
        long getTotalcuenta();
        bool getActivo();
        bool getAdmin();


    protected:
        //bool modificar;

    private:
};

#endif // USUARIO_H
