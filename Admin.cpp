#include <iostream>
using namespace std;
#include "Admin.h"

Admin::Admin()
{
    //modificar = false;
}

Admin::~Admin()
{
    //dtor
}

/*
void Admin::modificar(){
    ifstream archivo("usuarios.csv", ios::in);
    if(!archivo){
        cout<<"Error en tratar de abrir el archivo 'usuarios.csv'"<<endl<<endl;
    }else{
        vector <string> registros;
        string registro;
        string cedula, apellido, nombre, activo;
        string cedula_buscar;
        cout<<"Ingrese la cedula a buscar: ";
        cin>>cedula_buscar;
        bool existe = false, mod = false;
        int opc = 0;

        while(getline(archivo, registro)){
            //cout<<registro<<endl;
            stringstream token(registro);

            getline(token, cedula, ';');
            getline(token, apellido, ';');
            getline(token, nombre, ';');
            getline(token, ciudad, ';');
            getline(token, correo, ';');
            getline(token, activo, ';');

            if(cedula_buscar.compare(cedula) == 0){
                existe = true;
                cout<<"Datos del usuario: "<<endl;
                cout<<"1.Numero de cedula: "<<cedula<<endl;
                cout<<"2.Apellido: "<<apellido<<endl;
                cout<<"3.Nombre: "<<nombre<<endl;
                //cout<<ciudad<<" "<<correo<<endl;
                cout<<"4.Estado: "<<activo<<endl;
                cout<<"Ninguno"<<endl;

                do{

                }while(opc!=0)
            }
        }//fin del while
        archivo.close();
        if(!existe){//if(existe == false)
            cout<<"El cliente con numero de ID "<<cedula_buscar<<
                  " no existe en el archivo"<<endl<<endl;
        }
    }
}
*/
