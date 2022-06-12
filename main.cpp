///Código adaptado de https://bit.ly/2Plcea8


//gordoooo

#include <iostream>
#include <vector>
#include <conio.h>
#include "fstream"
#include "sstream"

#include "DefinicionCliente.h"
#include "Usuario.h"


using namespace std;

vector <DefinicionCliente> vecCliente;
vector <Usuario> vUsers; //Vector usuarios

int ENTER = 13, BACKSPACE = 8, INTENTOS = 3; //Códigos ASCII para ENTER y BACKSPACE. Cantidad de intentos para INTENTOS.




///Declaración de voids
//Para el registro/logueo
void registrarse();
void loguearse();
void F5_usuarios(); /*Se usa para refrescar los usuarios (por ejemplo
después de actualizar o registrar un usuario, etc.)*/

//Para menú principal
void ingresar();
void lista();
void buscarCliente();
void eliminarCliente();
void menu();


///Métodos

//Para el registro/logueo
void registrarse()
{
    bool existe = false;
    string u, p;
    char caracter;
    do
    {
        Usuario obj;
        cout<<"   -- REGISTRO --"<<endl
            <<"Ingrese el usuario: ";
        getline(cin, u);

        if (vUsers.size() != 0) //Comprueba si existe mínimo un usuario
        {
            for (int i=0; i<vUsers.size(); i++) //Busca si el usuario ingresado ya existe o no
            {
                obj = vUsers.at(i);
                if (u == obj.getUser())
                {
                    existe = true;
                    i = vUsers.size();
                }
                else existe = false;
            }
        }
        if (!existe) //Sigue con el registro en caso de no existir
        {
            cout<<"Ingrese la contraseña: "; //Mismo código que loguearse() para censurar la contraseña
            caracter = getch();
            p = "";

            while (caracter != ENTER)
            {
                if (caracter != BACKSPACE)
                {
                    p.push_back(caracter);
                    cout << "*";
                }
                else
                {
                    if (p.length() > 0)
                    {
                        cout << "\b \b";
                        p = p.substr(0, p.length() - 1);
                    }
                }
                caracter = getch();
            }

            ofstream usuarios("usuarios.csv", ios::app); //Guardado del nuevo registro en el archivo "usuarios.csv"
            if (!usuarios) cout << "Aviso: Error al escribir en documento. No existe, se creará un nuevo archivo 'usuarios.csv'"<<endl;
            else
            {
                usuarios<<u<<";"<<p<<endl;
                usuarios.close();
            }
        }
        else cout<<"El usuario ya existe, pruebe un nombre diferente."<<endl<<endl;
        system("pause");
        system("cls");
    }
    while(existe == true);
}

void loguearse()
{
    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tContraseña: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < vUsers.size(); i++)
        {
            Usuario obj;
            obj = vUsers[i];
            if (obj.getUser() == usuario && obj.getPass() == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    }
    while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\n\tBienvenido al sistema" << endl;
        /*
        Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas
        */
    }

    cin.get();
}

void F5_usuarios()
{
    vUsers.clear(); //Limpia el vector para evitar comenzar en 0, como dicen en las gasolineras jeje
    ifstream usuarios("usuarios.csv", ios::in);
    if (!usuarios) cout << "Aviso: Error al escribir en documento. No existe, se creará un nuevo archivo 'usuarios.csv'"<<endl;
    else
    {
        Usuario obj;
        string registro, u, p;
        while(getline(usuarios, registro))
        {
            stringstream token(registro);
            getline(token, u, ';');
            getline(token, p, ';');

            obj.setUser(u);
            obj.setPass(p);
            vUsers.push_back(obj);
        }
        usuarios.close();
    }
}






//test
//definicion de funciones para usar los objetos



void ingresar() //ingresar estudiantes
{
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

void lista()
{
    cout<<"Listado de clientes: "<<endl<<endl;
    DefinicionCliente obj;

    for(int i = 0; i < vecCliente.size(); i++)
    {
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

void buscarCliente()
{
    system("cls");
    bool existe = false;
    DefinicionCliente obj;
    int buscador;
    cout<<"Ingrese la cedula que desea buscar: ";
    cin>> buscador;

    int n = vecCliente.size();
    for(int i = 0; i < n; i++)
    {
        obj = vecCliente.at(i);
        if(obj.getCedula() == buscador)
        {
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
    if(!existe)
    {
        cout<<"El cliente con cedula "<<buscador<<
            " no existe"<<endl;

    }
}

void eliminarCliente()
{

}


void menu()
{
    int opc;
    do
    {
        cout<<"1. Ingrese un nuevo cliente"<<endl;
        cout<<"2. Listado de clientes"<<endl;
        cout<<"3. Buscar cliente"<<endl;
        cout<<"4. Eliminar cliente"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc;

        switch(opc)
        {
        case 1:
            ingresar();
            break;
        case 2:
            lista();
            break;
        case 3:
            buscarCliente();
            break;
        case 4:
            eliminarCliente();
            break;
        case 0:
            break;
        default:
            cout<<"Ingrese una opcion correcta"<<endl<<endl;
        }
    }
    while (opc != 0);
}

//Main
int main()
{
    setlocale(LC_ALL, ""); //Para soportar caracteres especiales
    F5_usuarios();

    registrarse();
    F5_usuarios();
    loguearse();
    menu();
    return 0;
}
