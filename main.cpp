#include <iostream>
#include <vector>
#include <conio.h>
#include "fstream"
#include "sstream"
#include "algorithm"
#include "ctime"

#include "Usuario.h"
#include "Cliente.h"
#include "Admin.h"
#include "Comidas.h"
#include "Pedidos.h"


using namespace std;

vector <Comidas> vComidas; //Vector comidas
vector <Admin> vUsers; //Vector usuarios
vector <Pedidos> vPedidos; //Vector pedidos

int ENTER = 13, BACKSPACE = 8, INTENTOS = 3; //Códigos ASCII para ENTER y BACKSPACE. Cantidad de intentos para INTENTOS.



///    ---- Declaración de voids ----    ////
//Misc
void F5_usuarios(); /*Se usa para refrescar los usuarios (por ejemplo
después de modificar o registrar un usuario, etc.)*/
void F5_comidas(); /*Se usa para refrescar los menús (por ejemplo
después de modificar o añadir un menú, etc.)*/
void F5_pedidos(); /*Se usa para refrescar los pedidos (por ejemplo
después de eliminar o hacer un pedido, etc.)*/

//Para el registro/logueo o menú de bienvenida
void menuBienvenida();
void registrarse();
void loguearse();
void acercaDe();

//Menú usuario normal
void menuUser(Admin _user);
void hacer_pedido(Admin _user);

//Menú admin
void menuAdmin(Admin _user);
void submenu_usuarios(Admin _user);
void listaUsuarios();
void modificar();

//Comidas
void submenu_comidas(Admin _user);
void agregarComida();
void imprimir_menu();


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

        <<"-------------------------------- Créditos -----------------------------------"<<endl
        <<"Código del sistema de registro y logueo adaptado de https://bit.ly/2Plcea8"<<endl
        <<"Separar strings por caracter https://java2blog.com/cpp-split-string-by-comma/"<<endl
        <<"Código para sacar fecha usando strftime() adaptado de https://bit.ly/3tC0cdq"<<endl<<endl;
}

void F5_usuarios()
{
    vUsers.clear(); //Limpia el vector para comenzar en 0, como dicen en las gasolineras jeje
    ifstream usuarios("usuarios.csv", ios::in);
    ofstream usuariosAdmin("usuarios.csv", ios::app);
    if (!usuarios)
    {
        cout << "Aviso: Error al leer el documento. No existe, se creará un nuevo archivo 'usuarios.csv'"<<endl;
        //Si no existe 'usuarios.csv', se creará un admin automáticamente:
        usuariosAdmin<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<0<<";"<<boolalpha<<true<<";"<<-1<<";"<<true<<";"<<"admin"<<endl;
        usuariosAdmin.close();
    }
    else
    {
        Admin obj;
        string registro, user, pass, nom, ape, cc, activoString, puntos, adminString, direccion;
        bool activo, admin, existeAdmin = false;
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
            getline(token, direccion, ';');

            if (activoString == "true") activo = true; //Conversión de string a bool
            else activo = false;

            if (adminString == "true") admin = true; //Conversión de string a bool
            else admin = false;

            //Comprueba si ya existe 'admin' o no
            if (user=="admin" && pass=="admin" && nom=="admin" && ape=="admin" && cc=="0" && activo==true && puntos=="-1" && admin==true && direccion=="admin")
            {
                existeAdmin = true;
            }

            obj.setUser(user);
            obj.setPass(pass);
            obj.setNombre(nom);
            obj.setApellido(ape);
            obj.setCedula(cc);
            obj.setActivo(activo);
            obj.setPuntos(stol(puntos)); //stol (string to long)
            obj.setAdmin(admin);
            obj.setDireccion(direccion);
            vUsers.push_back(obj);
        }
        usuarios.close();
        if (!existeAdmin)
        {
            //Crea un usuario 'admin'. Esto se ejecuta cuando no hay usuarios pero el archivo 'usuarios.csv' ya existe.
            ofstream usuariosAdmin("usuarios.csv", ios::app);
            usuariosAdmin<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<0<<";"<<boolalpha<<true<<";"<<-1<<";"<<true<<";"<<"admin"<<endl;
            usuariosAdmin.close();
        }
    }
}

void F5_comidas()
{
    vComidas.clear(); //Limpia el vector para comenzar en 0, como dicen en las gasolineras jeje
    ifstream comidas("comidas.csv", ios::in);
    if (!comidas) cout << "Aviso: Error al leer el documento. No existe, se creará un nuevo archivo 'comidas.csv'"<<endl;
    else
    {
        Comidas obj;
        string registroComidas, posicion, nombre, ingredientes, precio;
        while(getline(comidas, registroComidas))
        {
            stringstream token(registroComidas);
            obj.vIngredientes.clear();

            getline(token, posicion, ';');
            getline(token, nombre, ';');
            getline(token, ingredientes, ';');
            getline(token, precio, ';');

            obj.setPosicion(stoi(posicion));
            stringstream ss(ingredientes); //Para separar los ingredientes por coma en un vector
            while(ss.good()) //.good() corre el código hasta que llegue al final del string
            {
                string sub;
                getline(ss, sub, ',');
                obj.setIngrediente(sub);
            }
            obj.setNombre(nombre);
            obj.setPrecio(stoi(precio)); //stoi (String to int)
            vComidas.push_back(obj);
        }
        comidas.close();
    }
}

void F5_pedidos()
{
    vPedidos.clear(); //Limpia el vector para comenzar en 0, como dicen en las gasolineras jeje
    ifstream pedidos("pedidos.csv", ios::in);
    if (!pedidos) cout << "Aviso: Error al leer el documento. No existe, se creará un nuevo archivo 'pedidos.csv'"<<endl;
    else
    {
        Pedidos obj;
        string registroPedidos, numPedido, ordenes, nombreFull, cedula, direccion, total;
        while(getline(pedidos, registroPedidos))
        {
            stringstream token(registroPedidos);

            getline(token, numPedido, ';');
            getline(token, ordenes, ';');
            getline(token, nombreFull, ';');
            getline(token, cedula, ';');
            getline(token, direccion, ';');
            getline(token, total, ';');

            obj.setNumPedido(numPedido);
            obj.setOrdenes(ordenes);
            obj.setNombreFull(nombreFull);
            obj.setCedula(cedula);
            obj.setDireccion(direccion);
            obj.setTotal(stol(total)); //stol (String to long)
            vPedidos.push_back(obj);
        }
        pedidos.close();
    }
}


//Comidas
void agregarComida()
{
    F5_comidas();
    fflush(stdin);
    string nombre, ingredientes;
    int precio, posicion = vComidas.size()+1;
    fflush(stdin);
    Comidas obj;

    cout<<"   -- AGREGAR MENÚ --"<<endl
        <<"Ingrese el nombre del menú: ";
    getline(cin, nombre);

    cout<<endl<<"Ingrese los ingredientes (separados por comas y un espacio): ";
    getline(cin, ingredientes);
    transform(ingredientes.begin(), ingredientes.end(),ingredientes.begin(), ::tolower);

    cout<<"Ingrese el precio: ";
    cin>>precio;
    fflush(stdin);

    ofstream comidas("comidas.csv", ios::app); //Registro exitoso. Guardado del nuevo registro en el archivo "comidas.csv"
    if (!comidas) cout << "Aviso: Error al escribir en documento. No existe, se creará un nuevo archivo 'comidas.csv'"<<endl;
    else
    {
        comidas<<posicion<<";"<<nombre<<";"<<ingredientes<<";"<<precio<<endl;
        comidas.close();
        cout<<"Comida agregada con éxito."<<endl<<endl;
        system("pause");
    }
}

void imprimir_menu()
{
    F5_comidas();
    Comidas obj;
    for (int i=0; i<vComidas.size(); i++)
    {
        obj = vComidas.at(i);

        cout<<obj.getPosicion()<<". "<<obj.getNombre()<<endl
            <<"Ingredientes: "<<obj.getIngrediente()<<endl
            <<"Precio: "<<obj.getPrecio()<<"$"<<endl
            <<"----------------------------"<<endl<<endl;
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
    string u, p, nom, ape, dir, cc;
    long puntos=0;
    char caracter;
    do
    {
        fflush(stdin);
        Admin obj;
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
                    break; //Fuerza la salida del bucle for
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
                        break; //Fuerza la salida del bucle for
                    }
                    else existe = false;
                }
            }
            if (!existe) //Sigue con el registro en caso de no existir
            {
                cout<<"Ingrese su dirección: ";
                getline(cin, dir);

                ofstream usuarios("usuarios.csv", ios::app); //Registro exitoso. Guardado del nuevo registro en el archivo "usuarios.csv"
                if (!usuarios) cout << "Aviso: Error al escribir en documento. No existe, se creará un nuevo archivo 'usuarios.csv'"<<endl;
                else
                {
                    usuarios<<u<<";"<<p<<";"<<nom<<";"<<ape<<";"<<cc<<";"<<boolalpha<<activo<<";"<<puntos<<";"<<admin<<";"<<dir<<endl; //boolalpha fuerza el valor de un bool a true en vez de 1
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
    Admin obj;
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
            if(obj.getActivo() == false)
            {
                cout<<" Usuario inactivo "<<endl;
            }
            else
            {
                cout << "\n\n\tBienvenido al sistema" << endl;

                /*
                Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas
                */
                if (obj.getAdmin() == true) menuAdmin(obj);
                else menuUser(obj);
            }
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
void menuUser(Admin _user)
{
    Admin obj;
    obj = _user;

    int opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Ver el menú"<<endl
            <<"2. Hacer un pedido"<<endl
            <<"3. Modificar mi información..."<<endl
            <<"0. Cerrar sesión"<<endl<<endl
            <<"Seleccione una opción: ";
        cin>>opc;

        switch(opc)
        {
        case 1:
            system("cls");
            imprimir_menu();
            system("pause");
            break;
        case 2:
            system("cls");
            hacer_pedido(obj);
            break;
        case 3:
            system("cls");
            //modificar();
            break;
        case 0:
            system("cls");
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

void hacer_pedido(Admin _user)
{
    Admin obj;
    obj = _user;

    F5_pedidos();
    Comidas objComida;

    int orden;
    char numOrden[10];
    char opc;
    bool existe, sigue = true;
    long totalCuenta = 0;

    imprimir_menu();
    do
    {
        time_t fecha; //Variable tipo time_t
        tm * tlocal; //Estructura tm
        time(&fecha); //La información a convertir (time)
        tlocal = localtime(&fecha);

        strftime(numOrden,10,"%j%M%S",tlocal); //Guarda el siguiente formato "Día (001-366)""Minuto""Segundo"
        obj.setNumOrden(numOrden);

        cout<<endl<<"Seleccione una comida: ";
        cin>>orden;

        for (int i=0; i<vComidas.size(); i++)
        {
            objComida = vComidas.at(i);
            existe = false;

            if (orden == objComida.getPosicion())  //Comprueba si existe el menú solicitado
            {
                existe = true;
                break;
            }
        }
        if (existe == true)  //Si existe, suma el precio del menú al TOTAL y agrega el menú al vector de la clase Cliente
        {
            totalCuenta += objComida.getPrecio();
            obj.setOrden(objComida.getNombre());
        }
        else cout<<"El menú solicitado no existe."<<endl;



        cout<<"¿Desea agregar algo más? (s/n) ";
        opc = _getch();
        switch(opc)
        {
        case 's':
        case 'S':
        {
            sigue = true;
            break;
        }
        case 'n':
        case 'N':
        {
            sigue = false;
            break;
        }
        }
    }
    while(sigue == true);
    obj.setTotalcuenta(totalCuenta);

    ofstream pedidos("pedidos.csv", ios::app); //Guardado del nuevo pedido en el archivo "pedidos.csv"
    if (!pedidos) cout << "Aviso: Error al escribir en documento. No existe, se creará un nuevo archivo 'pedidos.csv'"<<endl;
    else
    {
        pedidos<<obj.getNumOrden()<<";"<<obj.getOrden()<<";"<<obj.getNombre() + " " + obj.getApellido()<<";"<<obj.getCedula()<<";"<<obj.getDireccion()<<";"<<obj.getTotalcuenta()<<endl;
        pedidos.close();
        cout<<endl<<"Usuario registrado con éxito."<<endl<<endl;
        system("pause");

        //Verificar que el menú está activo
        //Crear archivo con pedidos, nombre de la persona y total, decir precios totales, domicilios y descuentos preferencial
    }
    F5_pedidos();
}


//Menú admin
void menuAdmin(Admin _user)
{
    Admin obj;
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
            submenu_usuarios(obj);
            break;
        case 2:
            system("cls");
            submenu_comidas(obj);
            break;
        case 0:
            system("cls");
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

void submenu_usuarios(Admin _user)
{
    Admin obj;
    obj = _user;

    int opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Listado general"<<endl
            <<"2. Listado por cédula"<<endl
            <<"3. Modificar un usuario"<<endl
            <<"0. Salir"<<endl<<endl
            <<"Seleccione una opción: ";
        cin>>opc;

        switch(opc)
        {
        case 1:
            system("cls");
            listaUsuarios();
            break;
        case 2:
            system("cls");
            //registrarse();
            break;
        case 3:
            system("cls");
            modificar();
            break;
        case 0:
            system("cls");
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

void submenu_comidas(Admin _user)
{
    Admin obj;
    obj = _user;

    int opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Agregar comida"<<endl
            <<"2. Modificar una comida"<<endl
            <<"3. Modificar un menú"<<endl
            <<"0. Salir"<<endl<<endl
            <<"Seleccione una opción: ";
        cin>>opc;

        switch(opc)
        {
        case 1:
            system("cls");
            agregarComida();
            break;
        case 2:
            system("cls");
            //registrarse();
            break;
        case 0:
            system("cls");
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



void prueba_jartadera()
{
    Comidas obj;
    string ingrediente;
    int seguir=0;
    do
    {
        cout<<"Ingrese un ingrediente: ";
        getline(cin,ingrediente);

        obj.setIngrediente(ingrediente);
        cout<<"seguir?"<<endl;
        cin>>seguir;
        fflush(stdin);

    }
    while(seguir != 0);

    cout<<obj.getIngrediente();
}

void modificar()
{
    F5_usuarios();
    char opc = 0;
    bool existe = false, activo = false, mod = false;
    string cedula_buscar;
    cout<<"Ingrese la cédula del usuario a modificar: ";
    cin>>cedula_buscar;

    int i;
    Admin obj;
    for (i=0; i<vUsers.size(); i++) //Busca si existe un usuario con dicha cédula
    {
        obj = vUsers.at(i);
        if(cedula_buscar.compare(obj.getCedula()) == 0)
        {
            existe = activo = true;
            break; //Sale del bucle
        }
    }
    if (existe == true) //Si existe, pregunta qué desea cambiar
    {
        if (obj.getUser() == "admin") //Comprueba si el usuario al que se intenta modificar es 'admin'
        {
            cout<<"El usuario 'admin' no se puede modificar."<<endl;
        }
        else
        {
            do
            {
                system("cls");
                cout<<"Datos del usuario: "<<endl;
                cout<<"Numero de cedula: "<<obj.getCedula()<<endl;
                cout<<"1. Nombre: "<<obj.getNombre()<<endl;
                cout<<"2. Apellido: "<<obj.getApellido()<<endl;
                cout<<"3. Admin: "<<boolalpha<<obj.getAdmin()<<endl;
                cout<<"4. Estado: "<<boolalpha<<obj.getActivo()<<endl;
                cout<<"0. Salir"<<endl<<endl;

                cout<<"Seleccione el dato a modificar: ";
                opc = _getch();
                fflush (stdin);

                string nom, ape;
                char admin, activ;

                switch (opc)
                {
                case '1':
                    mod = true;
                    cout<<endl<<"Ingrese el nuevo nombre: ";
                    getline(cin, nom);
                    obj.setNombre(nom);
                    break;

                case '2':
                    mod = true;
                    cout<<endl<<"Ingrese el nuevo apellido: ";
                    getline(cin, ape);
                    obj.setApellido(ape);
                    break;

                case '3':
                    mod = true;
                    if (obj.getAdmin() == true) obj.setAdmin(false);
                    else obj.setAdmin(true);
                    break;

                case '4':
                    mod = true;
                    if (obj.getActivo() == true) obj.setActivo(false);
                    else obj.setActivo(true);
                    break;

                }
                vUsers.at(i) = obj;
            }
            while(opc != '0');
            system("cls");
        }
    }
    else cout<<"El cliente con CC "<<cedula_buscar<<" no existe en el archivo"<<endl<<endl;

    if (mod == true)
    {
        ofstream usuarios("usuarios.csv");

        if (!usuarios) cout << "Aviso: Error #1 al escribir en documento. No existe, se creará un nuevo archivo 'usuarios.csv'"<<endl;
        else
        {
            usuarios.open("usuarios.csv", ofstream::out | ofstream::trunc);
            ofstream usuarios("usuarios.csv", ios::app);
            for (i=0; i<vUsers.size(); i++)
            {
                obj = vUsers.at(i);

                //boolalpha fuerza el valor de un bool a true en vez de 1
                usuarios<<obj.getUser()<<";"<<obj.getPass()<<";"<<obj.getNombre()<<";"<<obj.getApellido()<<";"<<obj.getCedula()<<";"
                        <<boolalpha<<obj.getActivo()<<";"<<obj.getPuntos()<<";"<<obj.getAdmin()<<";"<<obj.getDireccion()<<endl;
            }
            usuarios.close();
            system("cls");
            cout<<"Usuario modificado con éxito."<<endl<<endl;
        }
    }
    system("pause");
}


void listaUsuarios ()
{
    F5_usuarios();
    Admin obj;

    for(int i = 0; i < vUsers.size(); i++ )  //ciclo for implementado para enumerar los usuarios a la hora de mostrarlos en pantalla
    {
        obj = vUsers.at(i);
        cout<<"**** Usuario #"<<i+1<<" ****"<<endl;

        cout<<"Nombre del usuario: "<<obj.getUser()<<endl;
        cout<<"Contraseña del usuario: "<<obj.getPass()<<endl;
        cout<<"Nombre: "<<obj.getNombre()<<endl;
        cout<<"Apellido: "<<obj.getApellido()<<endl;
        cout<<"Cédula: "<<obj.getCedula()<<endl;
        if (obj.getActivo() == true) cout<<"Estado: Activo"<<endl;
        else cout<<"Estado: Inactivo"<<endl;
        cout<<"Puntos: "<<obj.getPuntos()<<endl;
        if (obj.getAdmin() == true) cout<<"Administrador"<<endl;
        else cout<<"Usuario estándar"<<endl;
        cout<<"Direccion: "<<obj.getDireccion()<<endl<<endl;
    }
    system("pause");
}


///Main
int main()
{
    setlocale(LC_ALL, ""); //Para soportar caracteres especiales

    //agregarComida();
    //F5_comidas();
    //imprimir_menu();
    //prueba_jartadera();
    menuBienvenida();
    //modificar();
    return 0;
}
