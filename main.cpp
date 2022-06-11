#include <iostream>
#include "DefinicionCliente.h"
#include <vector>

using namespace std;

vector<DefinicionCliente> vecCliente;

//definicion de funciones para usar los objetos

void ingresar();
void lista();
void buscarCliente();
void eliminarCliente();
void menu();

void ingresar(){//ingresar estudiantes
    system("cls");
    cout<<"Informacion del cliente: "<<endl<<endl;
    DefinicionCliente obj;

    obj.setCedula();
    obj.setNombre();
    obj.setApellido();
    obj.setGenero();
    obj.setEdad();
    obj.setOrden();
    obj.setTotalcuenta();
    vecCliente.push_back(obj);
    system ("pause");
    system("cls");
    }

void lista(){
    cout<<"Listado de clientes: "<<endl<<endl;
    DefinicionCliente obj;

    for(int i = 0; i < vecCliente.size(); i++){
        cout<<"Informacion del cliente # "<<i+1<<endl;
        obj = vecCliente.at(i);
        cout<<obj.getCedula ()<<" "<<
            obj.getApellido()<<" "<<obj.getNombre()<<" "<<
            obj.getGenero()<<" "<<
            //obj.getEdad()<<" años de edad"<<
            obj.getOrden()<<" "<<
            obj.getTotalcuenta()<<" "<<endl<<endl;

    }
}

void buscarCliente(){
    system("cls");
    bool existe = false;
    DefinicionCliente obj;
    int buscador;
    cout<<"Ingrese la cedula que desea buscar: ";
    cin>> buscador;

    int n = vecCliente.size();
    for(int i = 0; i < n; i++){
        obj = vecCliente.at(i);
        if(obj.getCedula() == buscador){
            existe = true;
            cout<<"Informacion del cliente"<<endl;
            cout<<obj.getCedula ()<<" "<<
            obj.getApellido()<<" "<<obj.getNombre()<<" "<<
            obj.getGenero()<<" "<<
           // obj.getEdad()<<" años de edad"<<
//            obj.getOrden()<<" "<<
            obj.getTotalcuenta()<<" "<<endl<<endl;
            break;
        }
    }
    if(!existe){
            cout<<"El cliente con cedula "<<buscador<<
                " no existe"<<endl;

    }
}

void eliminarCliente(){

}


void menu(){
    int opc;
    do{
        cout<<"1. Ingrese un nuevo cliente"<<endl;
        cout<<"2. Listado de clientes"<<endl;
        cout<<"3. Buscar cliente"<<endl;
        cout<<"4. Eliminar cliente"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc;

        switch(opc){
            case 1: ingresar(); break;
            case 2: lista(); break;
            case 3: buscarCliente(); break;
            case 4: eliminarCliente(); break;
            case 0: break;
            default: cout<<"Ingrese una opcion correcta"<<endl<<endl;
        }
    }while (opc != 0);
}

int main()
{
    menu();
    return 0;
}
