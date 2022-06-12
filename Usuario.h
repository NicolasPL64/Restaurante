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
        string user, pass, nombre, apellido, orden;
        int puntos;
        long total, cedula;
        bool activo;

        ///Métodos
        //Setter
        void setUser(string);
        void setPass(string);
        void setNombre(string);
        void setApellido(string);
        void setCedula(long);
        void setPuntos();
        void setOrden();
        void setActivo(bool);
        virtual void setTotalcuenta(); //Polimorfismo

        //Getter
        string getUser();
        string getPass();
        string getNombre();
        string getApellido();
        long getCedula();
        string getOrden();
        long getPuntos();
        long getTotalcuenta();
        bool getActivo();


    protected:

    private:
};

#endif // USUARIO_H
