#include <iostream>
#include <vector>
#include <conio.h>
#include "fstream"
#include "sstream"

#include "DefinicionCliente.h"
#include "Usuario.h"
#include "Cliente.h"
#include "Admin.h"


using namespace std;

vector <DefinicionCliente> vecCliente;
vector <Usuario> vUsers; //Vector usuarios

int ENTER = 13, BACKSPACE = 8, INTENTOS = 3; //Códigos ASCII para ENTER y BACKSPACE. Cantidad de intentos para INTENTOS.




///Declaración de voids
void F5_usuarios(); /*Se usa para refrescar los usuarios (por ejemplo
después de modificar o registrar un usuario, etc.)*/

//Para el registro/logueo o menú de bienvenida
void menuBienvenida();
void registrarse();
void loguearse();
void acercaDe();

//Menú usuario normal
void menuUser(Usuario _user);

//Menú admin
void menuAdmin(Usuario _user);


//Para menú principal morbid
void ingresar();
void lista();
void buscarCliente();
void eliminarCliente();
void menu();


///    ---- Métodos ----    ////

//Misc
void acercaDe()
{

    cout<<"------ Trabajo final del segundo semestre de IPOO ------"<<endl
        <<"Realizado por: Nicolás Prado León              202160073"<<endl
        <<"               Kevin Estiven Gil Salcedo       202159863"<<endl
        <<"               Miguel Ángel Rueda Colonia      202159896"<<endl
        <<"               Kevin Alexander Marín Henao     202160364"<<endl<<endl

        <<"-------------------------------- Créditos --------------------------------"<<endl
        <<"Código del sistema de registro y logueo adaptado de https://bit.ly/2Plcea8"<<endl<<endl;
}

void F5_usuarios()
{
    vUsers.clear(); //Limpia el vector para comenzar en 0, como dicen en las gasolineras jeje
    ifstream usuarios("usuarios.csv", ios::in);
    ofstream usuariosAdmin("usuarios.csv", ios::app);
    if (!usuarios)
    {
        cout << "Aviso: Error al leer el documento. No existe, se creará un nuevo archivo 'usuarios.csv'"<<endl;
        //Si no existe ningún usuario, se creará un admin automáticamente:
        usuariosAdmin<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<0<<";"<<boolalpha<<true<<";"<<-1<<";"<<true<<endl;
        usuariosAdmin.close();
    }
    else
    {
        Cliente obj;
        string registro, user, pass, nom, ape, cc, activoString, puntos, adminString;
        bool activo, admin;
        while(getline(usuarios, registro))
        {
            stringstream token(registro);

            getline(token, user, ';');
            getline(token, pass, ';');
            getline(token, nom, ';');
            getline(token, ape, ';');
            getline(token, cc, ';');
            getline(token, activoString, ';');
            getline(token, puntos, ';');
            getline(token, adminString, ';');

            if (activoString == "true") activo = true; //Conversión de string a bool
            else activo = false;

            if (adminString == "true") admin = true; //Conversión de string a bool
            else admin = false;

            obj.setUser(user);
            obj.setPass(pass);
            obj.setNombre(nom);
            obj.setApellido(ape);
            obj.setCedula(stol(cc)); //stol (string to long)
            obj.setActivo(activo);
            obj.setPuntos(stol(puntos));
            obj.setAdmin(admin);
            vUsers.push_back(obj);
        }
        usuarios.close();
    }
}


//Para el registro/logueo
void menuBienvenida()
{
    int opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido!"<<endl<<endl
            <<"1. Iniciar sesión"<<endl
            <<"2. Registrarse"<<endl
            <<"3. Acerca de..."<<endl
            <<"0. Salir"<<endl<<endl
            <<"Seleccione una opción: ";
        cin>>opc;

        switch(opc)
        {
        case 1:
            system("cls");
            loguearse();
            break;
        case 2:
            system("cls");
            registrarse();
            break;
        case 3:
            system("cls");
            acercaDe();
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            cout<<"¡Hasta pronto!"<<endl;
            break;
        default:
            system("cls");
            cout<<"Opción incorrecta"<<endl<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc != 0);
}

void registrarse()
{
    fflush(stdin);
    F5_usuarios();
    bool existe = false, activo = true, admin = false;
    string u, p, nom, ape;
    long cc, puntos=0;
    char caracter;
    do
    {
        fflush(stdin);
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
                    i = vUsers.size(); //Fuerza la salida del bucle for
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

            cout<<endl<<"Ingrese un nombre: ";
            getline(cin, nom);

            cout<<"Ingrese un apellido: ";
            getline(cin, ape);

            cout<<"Ingrese el número de identificación (sin puntos): ";
            cin>>cc;

            if (vUsers.size() != 0) //Comprueba si existe mínimo un usuario
            {
                for (int i=0; i<vUsers.size(); i++) //Busca si el documento ingresado ya existe o no
                {
                    obj = vUsers.at(i);
                    if (cc == obj.getCedula())
                    {
                        existe = true;
                        i = vUsers.size(); //Fuerza la salida del bucle for
                    }
                    else existe = false;
                }
            }
            if (!existe) //Sigue con el registro en caso de no existir
            {
                ofstream usuarios("usuarios.csv", ios::app); //Registro exitoso. Guardado del nuevo registro en el archivo "usuarios.csv"
                if (!usuarios) cout << "Aviso: Error al escribir en documento. No existe, se creará un nuevo archivo 'usuarios.csv'"<<endl;
                else
                {
                    usuarios<<u<<";"<<p<<";"<<nom<<";"<<ape<<";"<<cc<<";"<<boolalpha<<activo<<";"<<puntos<<";"<<admin<<endl; //boolalpha fuerza el valor de un bool a true en vez de 1
                    usuarios.close();
                    cout<<"Usuario registrado con éxito."<<endl<<endl;
                    system("pause");
                }
            }
            else
            {
                cout<<"Ya existe un usuario registrado con el mismo documento."<<endl<<endl;
                system("pause");
                system("cls");
            }
        }
        else
        {
            cout<<"El usuario ya existe, pruebe un nombre diferente."<<endl<<endl;
            system("pause");
            system("cls");
        }
    }
    while(existe == true);
}

void loguearse()
{
    F5_usuarios();
    Usuario obj;
    if(vUsers.size() != 0)
    {
        string usuario, password;
        int contador = 0;
        bool ingresa = false;

        do
        {
            system("cls");
            fflush(stdin);
            if (contador > 0)
            {
                cout<<"Tiene "<<(INTENTOS-contador)<<" intentos restantes."<<endl;
            }

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

        if (!ingresa)
        {
            cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
        }
        else
        {
            cout << "\n\n\tBienvenido al sistema" << endl;
            /*
            Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas
            */
            if (obj.getAdmin() == true) menuAdmin(obj);
            //else VOID MENU NORMAL
        }

        cin.get();
    }
    else
    {
        cout<<"No existen usuarios en la base de datos. Por favor, registre un nuevo usuario."<<endl<<endl;
        system("pause");
    }
}


//Menú usuario normal
void menuUser(Usuario _user)
{
    Usuario obj;
    obj = _user;

    int opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Ver el menú"<<endl
            <<"2. Hacer un pedido"<<endl
            <<"0. Cerrar sesión"<<endl<<endl
            <<"Seleccione una opción: ";
        cin>>opc;

        switch(opc)
        {
        case 1:
            system("cls");
            //loguearse();
            break;
        case 2:
            system("cls");
            //registrarse();
            break;
        case 0:
            system("cls");
            cout<<"¡Hasta pronto!"<<endl;
            break;
        default:
            system("cls");
            cout<<"Opción incorrecta"<<endl<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc != 0);
}



//Menú admin
void menuAdmin(Usuario _user)
{
    Usuario obj;
    obj = _user;

    int opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Administrar usuarios..."<<endl
            <<"2. Administrar comidas..."<<endl
            <<"0. Cerrar sesión"<<endl<<endl
            <<"Seleccione una opción: ";
        cin>>opc;

        switch(opc)
        {
        case 1:
            system("cls");
            //loguearse();
            break;
        case 2:
            system("cls");
            //registrarse();
            break;
        case 0:
            system("cls");
            cout<<"¡Hasta pronto!"<<endl;
            break;
        default:
            system("cls");
            cout<<"Opción incorrecta"<<endl<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc != 0);
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



///Main
int main()
{
    setlocale(LC_ALL, ""); //Para soportar caracteres especiales

    menuBienvenida();
    return 0;
}
