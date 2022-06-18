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
        string user, pass, nombre, apellido, cedula;
        bool activo;
        int puntos;

        ///Métodos
        //Setter
        void setUser(string);
        void setPass(string);
        void setNombre(string);
        void setApellido(string);
        void setCedula(string);
        void setActivo(bool);
        void setPuntos(int);

        //Getter
        string getUser();
        string getPass();
        string getNombre();
        string getApellido();
        string getCedula();
        bool getActivo();
        int getPuntos();

    protected:

    private:
};

#endif // USUARIO_H
