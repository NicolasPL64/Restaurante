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
        string user, pass, nombre, apellido, genero, orden, cedula;
        int puntos;
        long total;

        ///Métodos
        //Setter
        void setUser(string);
        void setPass(string);
        void setNombre(string);
        void setApellido(string);
        void setCedula(string);
        void setGenero();
        void setPuntos();
        void setOrden();
        virtual void setTotalcuenta(); //Polimorfismo

        //Getter
        string getUser();
        string getPass();
        string getNombre();
        string getApellido();
        string getCedula();
        string getGenero();
        string getOrden();
        long getPuntos();
        long getTotalcuenta();


    protected:

    private:
};

#endif // USUARIO_H
