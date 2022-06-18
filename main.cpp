#include <iostream>
#include <vector>
#include <conio.h>
#include "fstream"
#include "sstream"
#include "algorithm"
#include "ctime"
#include <windows.h>
#include "cmath"
#include "iomanip"

#include "Usuario.h"
#include "Cliente.h"
#include "Admin.h"
#include "Comidas.h"
#include "Pedidos.h"
#include "clientePreferencial.h"


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
void F5_usuariosArchivo(); /*Se usa para reescribir el archivo 'usuarios'
después de una modificación*/
void F5_comidasArchivo(); /*Se usa para reescribir el archivo 'comidas'
después de una modificación*/

//Para el registro/logueo o menú de bienvenida
void menuBienvenida();
void registrarse();
void loguearse();
void acercaDe();
void gotoxy();

//Menú usuario normal
void menuUser(Admin obj);
void hacer_pedido(Admin obj);
void modificarUsuarioPROPIO(Admin _user);

//Menú admin
void menuAdmin(Admin obj);
void submenu_usuarios(Admin obj);
void listaUsuarios();
void listaxCedula();
void modificarUsuarioADMIN();

//Comidas
void submenu_comidas(Admin obj);
void imprimir_menu(bool _admin);
void agregarComida();
void modificarComida();

//Para menú principal morbid
void ingresar();
void lista();
void buscarCliente();
void eliminarCliente();
void menu();


///    ---- Métodos ----    ////
//Misc
void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
/* acercaDe()
{

    cout<<"------ Trabajo final del segundo semestre de IPOO ------"<<endl
        <<"Realizado por: Nicolás Prado León              202160073"<<endl
        <<"               Kevin Estiven Gil Salcedo       202159863"<<endl
        <<"               Miguel Ángel Rueda Colonia      202159896"<<endl
        <<"               Kevin Alexander Marín Henao     202160364"<<endl<<endl

        <<"-------------------------------- Créditos -----------------------------------"<<endl
        <<"Código del sistema de registro y logueo adaptado de https://bit.ly/2Plcea8"<<endl
        <<"Separar strings por caracter https://java2blog.com/cpp-split-string-by-comma/"<<endl
        <<"Código para sacar fecha usando strftime() adaptado de https://bit.ly/3tC0cdq"<<endl
        <<"Sort con vectores tipo clase https://www.walletfox.com/course/sortvectorofcustomobjects.php"<<endl<<endl;
}
*/
void acercaDe()
{

    system("cls");

    gotoxy(18,1);
    cout<<"        **  "<<endl;
    gotoxy(18,2);
    cout<<"     *****                       * "<<endl;
    gotoxy(18,3);
    cout<<"    *  ***                      ** "<<endl;
    gotoxy(18,4);
    cout<<"       ***                      ** "<<endl;
    gotoxy(18,5);
    cout<<"      *  **    **   ****      ******** ****   ***  ****              **** "<<endl;
    gotoxy(18,6);
    cout<<"      *  **     **    ***    ******** * ***  * **** **** * ***      * **** * "<<endl;
    gotoxy(18,7);
    cout<<"     *    **    **     ****     **   *   ****   **   **** * ***    **  ****  "<<endl;
    gotoxy(18,8);
    cout<<"     *    **    **      **      **  **    **    **       *   ***  ****   "<<endl;
    gotoxy(18,9);
    cout<<"    *      **   **      **      **  **    **    **      **    ***   ***  "<<endl;
    gotoxy(18,10);
    cout<<"    *********   **      **      **  **    **    **      ********      ***  "<<endl;
    gotoxy(18,11);
    cout<<"   *        **  **      **      **  **    **    **      *******         *** "<<endl;
    gotoxy(18,12);
    cout<<"   *        **  **      **      **  **    **    **      **         ****  **  "<<endl;
    gotoxy(18,13);
    cout<<"  *****      **  ******* **     **   ******     ***     ****    * * **** * "<<endl;
    gotoxy(18,14);
    cout<<" *   ****    ** * *****   **     **   ****       ***     *******     ****  "<<endl;
    gotoxy(18,15);
    cout<<"*     **      **                                          *****      "<<endl;
    gotoxy(18,16);
    cout<<"*  "<<endl;
    gotoxy(18,17);
    cout<<" **  "<<endl<<endl;



    gotoxy(50,20);
    cout<<"Autores:"<<endl;
    gotoxy(40,21);
    cout<<"Kevin Stiven Gil Salcedo - 202159863\n";
    gotoxy(40,22);
    cout<<"Nicolas Prado Leon - 202160073\n";
    gotoxy(40,23);
    cout<<"Kevin Alexander Marín Henao - 202160364\n";
    gotoxy(40,24);
    cout<<"Miguel Angel Rueda Colonia - 202159896\n";


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
        usuariosAdmin<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<0<<";"<<boolalpha<<true<<";"<<-1<<";"<<true<<";"<<"admin"<<";"<<true<<endl;
        usuariosAdmin.close();
    }
    else
    {
        Admin obj;
        string registro, user, pass, nom, ape, cc, activoString, puntos, adminString, direccion, clientePrefString;
        bool activo, admin, clientePref, existeAdmin = false;
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
            getline(token, clientePrefString, ';');

            if (activoString == "true") activo = true; //Conversión de string a bool
            else activo = false;

            if (adminString == "true") admin = true; //Conversión de string a bool
            else admin = false;

            if (clientePrefString == "true") clientePref = true; //Conversión de string a bool
            else clientePref = false;

            //Comprueba si ya existe 'admin' o no
            if (user=="admin" && pass=="admin" && nom=="admin" && ape=="admin" && cc=="0" && activo==true && puntos=="-1" && admin==true && direccion=="admin" && clientePref==true)
            {
                existeAdmin = true;
            }

            obj.setUser(user);
            obj.setPass(pass);
            obj.setNombre(nom);
            obj.setApellido(ape);
            obj.setCedula(cc);
            obj.setActivo(activo);
            obj.setPuntos(stoi(puntos)); //stoi (string to int)
            obj.setAdmin(admin);
            obj.setDireccion(direccion);
            obj.setClientePref(clientePref);
            vUsers.push_back(obj);
        }
        usuarios.close();
        if (!existeAdmin)
        {
            //Crea un usuario 'admin'. Esto se ejecuta cuando no hay usuarios pero el archivo 'usuarios.csv' ya existe.
            ofstream usuariosAdmin("usuarios.csv", ios::app);
            usuariosAdmin<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<"admin"<<";"<<0<<";"<<boolalpha<<true<<";"<<-1<<";"<<true<<";"<<"admin"<<";"<<true<<endl;
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
        string registroComidas, posicion, nombre, ingredientes, precio, activoString;
        bool activo;
        while(getline(comidas, registroComidas))
        {
            stringstream token(registroComidas);
            obj.vIngredientes.clear();

            getline(token, posicion, ';');
            getline(token, nombre, ';');
            getline(token, ingredientes, ';');
            getline(token, precio, ';');
            getline(token, activoString, ';');

            obj.setPosicion(stoi(posicion));
            stringstream ss(ingredientes); //Para separar los ingredientes por coma en un vector
            while(ss.good()) //.good() corre el código hasta que llegue al final del string
            {
                string sub;
                getline(ss, sub, ',');
                obj.setIngrediente(sub);
            }
            obj.setNombre(nombre);
            obj.setPrecio(stoi(precio)); //stoi (String to int

            if (activoString == "true") activo = true; //Conversión de string a bool
            else activo = false;

            obj.setActivo(activo);
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

void F5_usuariosArchivo()
{
    Admin obj;
    ofstream usuarios("usuarios.csv");

    if (!usuarios) cout << "Aviso: Error #1 al escribir en documento. No existe, se creará un nuevo archivo 'usuarios.csv'"<<endl;
    else
    {
        usuarios.open("usuarios.csv", ofstream::out | ofstream::trunc);
        ofstream usuarios("usuarios.csv", ios::app);
        for (int i=0; i<vUsers.size(); i++)
        {
            obj = vUsers.at(i);

            //boolalpha fuerza el valor de un bool a 'true' en vez de '1'
            usuarios<<obj.getUser()<<";"<<obj.getPass()<<";"<<obj.getNombre()<<";"<<obj.getApellido()<<";"<<obj.getCedula()<<";"
                    <<boolalpha<<obj.getActivo()<<";"<<obj.getPuntos()<<";"<<obj.getAdmin()<<";"<<obj.getDireccion()<<";"<<obj.getClientePref()<<endl;
        }
        usuarios.close();
        system("cls");
    }
}

void F5_comidasArchivo()
{
    Comidas obj;
    ofstream comidas("comidas.csv");

    sort(vComidas.begin(),vComidas.end()); //Organiza el vector por getPosicion() en orden ascendente

    if (!comidas) cout << "Aviso: Error #1 al escribir en documento. No existe, se creará un nuevo archivo 'comidas.csv'"<<endl;
    else
    {
        comidas.open("comidas.csv", ofstream::out | ofstream::trunc);
        ofstream comidas("comidas.csv", ios::app);
        for (int i=0; i<vComidas.size(); i++)
        {
            obj = vComidas.at(i);

            //boolalpha fuerza el valor de un bool a true en vez de 1
            comidas<<obj.getPosicion()<<";"<<obj.getNombre()<<";"<<obj.getIngredienteString()<<";"<<obj.getPrecio()<<";"<<boolalpha<<obj.getActivo()<<endl;
        }
        comidas.close();
        system("cls");
        cout<<"Comida modificada con éxito."<<endl<<endl;
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

    cout<<"Ingrese los ingredientes (separados por comas y un espacio): ";
    getline(cin, ingredientes);
    transform(ingredientes.begin(), ingredientes.end(), ingredientes.begin(), ::tolower);

    cout<<"Ingrese el precio: ";
    cin>>precio;
    fflush(stdin);

    ofstream comidas("comidas.csv", ios::app); //Registro exitoso. Guardado del nuevo registro en el archivo "comidas.csv"
    if (!comidas) cout << "Aviso: Error al escribir en documento. No existe, se creará un nuevo archivo 'comidas.csv'"<<endl;
    else
    {
        comidas<<posicion<<";"<<nombre<<";"<<ingredientes<<";"<<precio<<";"<<boolalpha<<true<<endl;
        comidas.close();
        cout<<"Comida agregada con éxito."<<endl<<endl;
        system("pause");
    }
}

void imprimir_menu(bool _admin)
{
    F5_comidas();
    Comidas obj;
    for (int i=0; i<vComidas.size(); i++)
    {
        obj = vComidas.at(i);
        if (!_admin) //Comprueba si es admin o no para saber si imprimir todas las comidas
        {
            if (obj.getActivo() == true)
            {
                cout<<obj.getPosicion()<<". "<<obj.getNombre()<<endl
                    <<"Ingredientes: "<<obj.getIngrediente()<<endl
                    <<"Precio: "<<obj.getPrecio()<<"$"<<endl
                    <<"----------------------------"<<endl<<endl;
            }
        }
        else
        {
            cout<<obj.getPosicion()<<". "<<obj.getNombre()<<endl
                <<"Ingredientes: "<<obj.getIngrediente()<<endl
                <<"Precio: "<<obj.getPrecio()<<"$"<<endl;
            if (obj.getActivo() == true) cout<<">> Menú activo"<<endl;
            else cout<<">> Menú inactivo"<<endl;
            cout<<"----------------------------"<<endl<<endl;
        }
    }
}



//Para el registro/logueo
void menuBienvenida()
{
    char opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido!"<<endl<<endl
            <<"1. Iniciar sesión"<<endl
            <<"2. Registrarse"<<endl
            <<"3. Acerca de..."<<endl
            <<"0. Salir"<<endl<<endl
            <<"Seleccione una opción: ";
        opc = getch();


        switch(opc)
        {
        case '1':
            system("cls");
            loguearse();
            break;
        case '2':
            system("cls");
            registrarse();
            break;
        case '3':
            system("cls");
            acercaDe();
            system("pause");
            system("cls");
            break;
        case '0':
            system("cls");
            cout<<"Gracias por usar la aplicación."<<endl;
            break;
        default:
            system("cls");
            cout<<"Opción incorrecta"<<endl<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc != '0');
}

void registrarse()
{
    fflush(stdin);
    F5_usuarios();
    bool existe = false;
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
            fflush(stdin);

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
                    usuarios<<u<<";"<<p<<";"<<nom<<";"<<ape<<";"<<cc<<";"<<boolalpha<<true<<";"<<puntos<<";"<<false<<";"<<dir<<";"<<false<<endl; //boolalpha fuerza el valor de un bool a true en vez de 1
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
    }
    else
    {
        cout<<"No existen usuarios en la base de datos. Por favor, registre un nuevo usuario."<<endl<<endl;
        system("pause");
    }
}


//Menú usuario normal
void menuUser(Admin obj)
{
    char opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Ver el menú"<<endl
            <<"2. Hacer un pedido"<<endl
            <<"3. Modificar mi información"<<endl
            <<"0. Cerrar sesión"<<endl<<endl
            <<"Seleccione una opción: ";
        opc = getch();

        switch(opc)
        {
        case '1':
            system("cls");
            imprimir_menu(false);
            system("pause");
            break;
        case '2':
            system("cls");
            hacer_pedido(obj);
            break;
        case '3':
            system("cls");
            modificarUsuarioPROPIO(obj);
            break;
        case '0':
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
    while(opc != '0');
}

void hacer_pedido(Admin obj)
{
    F5_pedidos();
    Comidas objComida;

    int orden, totalPuntos;
    char numOrden[10];
    char opc;
    bool existe, sigue = true;
    long totalCuenta = 0;

    imprimir_menu(false);
    do
    {
        time_t fecha; //Variable tipo time_t
        tm * tlocal; //Estructura tm
        time(&fecha); //La información a convertir (time)
        tlocal = localtime(&fecha);

        strftime(numOrden,10,"%j%M%S",tlocal); //Guarda el siguiente formato "Día (001-366)""Minuto""Segundo"
        obj.setNumOrden(numOrden);

        cout<<endl<<"Seleccione una comida (posición): ";
        cin>>orden;

        for (int i=0; i<vComidas.size(); i++)
        {
            objComida = vComidas.at(i);
            existe = false;

            if (orden == objComida.getPosicion())  //Comprueba si existe el menú solicitado
            {
                //if está desactivado, que salga otro error objComida.getActivo()
                existe = true;
                break;
            }
        }
        if (existe == true)  //Si existe, suma el precio del menú al TOTAL y agrega el menú al vector de la clase Cliente
        {
            //Si variable activado está off entonces tal
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
    totalPuntos = totalCuenta/1000;
    obj.setPuntos(obj.getPuntos() + totalPuntos);

    //if totalCuenta==0, se salta todo el codigo de abajo, sale al menú

    //usar setw() para acomodar a la derecha los precios si hay tiempo
    system("cls"); //Comienzo del recibo
    cout<<"Puntos que acumula: "<<totalPuntos<<endl<<endl;
    cout<<"Total de la cuenta: "<<totalCuenta<<"$"<<endl;


    int puntosRestan = 0, descuentoPesos = totalCuenta;

    if (obj.getClientePref() == true && obj.getPuntos() >= 15) //Si es Cliente Preferencial y tiene 15 puntos o más se le aplica descuento
    {
        puntosRestan = (floor(obj.getPuntos() / 15)) * 15;
        descuentoPesos *= floor(obj.getPuntos() / 15) * 0.05;

        cout<<puntosRestan<<" puntos han sido canjeados para un descuento total de "<<floor(obj.getPuntos() / 15) * 5<<"%"<<endl;

        obj.setPuntos(obj.getPuntos() - puntosRestan); //Resta los puntos
        totalCuenta -= descuentoPesos; //Resta el descuento

        cout<<"                   -"<<descuentoPesos<<"$"<<endl; //Muestra el descuento en pesos
    }

    if (obj.getClientePref() == false && obj.getPuntos() >= 50) //Asciende al usuario a Cliente Preferencial en caso de no serlo y poseer 50 puntos o más
    {
        obj.setClientePref(true);
        cout<<"Ha sido ascendido a Cliente Preferencial por haber gastado 50000$ con nosotros. ¡Muchas gracias!"<<endl
            <<"A partir de la siguiente compra, cada 15 puntos recibirá un descuento del 5%."<<endl<<endl;
        obj.setPuntos(obj.getPuntos() - 50);
    }

    cout<<"Domicilio:         +2000$"<<endl;
    totalCuenta += 2000;
    cout<<"-------------------------------------"<<endl;
    cout<<"Total a pagar:     "<<totalCuenta<<"$"<<endl;
    system("pause");
    obj.setTotalcuenta(totalCuenta);


    ofstream pedidos("pedidos.csv", ios::app); //Guardado del nuevo pedido en el archivo "pedidos.csv"
    if (!pedidos) cout << "Aviso: Error al escribir en documento. No existe, se creará un nuevo archivo 'pedidos.csv'"<<endl;
    else
    {
        pedidos<<obj.getNumOrden()<<";"<<obj.getOrden()<<";"<<obj.getNombre() + " " + obj.getApellido()<<";"<<obj.getCedula()<<";"<<obj.getDireccion()<<";"<<obj.getTotalcuenta()<<endl;
        pedidos.close();

        cout<<"Pedido registrado con éxito."<<endl;

        //Verificar que el menú está activo
        //Crear archivo con pedidos, nombre de la persona y total, decir precios totales, domicilios y descuentos preferencial
    }

    for (int i=0; i<vUsers.size(); i++) //Busca en qué posición del vector está
    {
        Admin objComprobacion;
        objComprobacion = vUsers.at(i);

        if (obj.getCedula() == objComprobacion.getCedula()) //Guarda el obj en vUsers
        {
            vUsers.at(i) = obj;
            break;
        }
    }
    F5_usuariosArchivo();
    F5_pedidos();
}


//Menú admin
void menuAdmin(Admin obj)
{
    char opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Administrar usuarios..."<<endl
            <<"2. Administrar comidas..."<<endl
            <<"0. Cerrar sesión"<<endl<<endl
            <<"Seleccione una opción: ";
        opc = getch();

        switch(opc)
        {
        case '1':
            system("cls");
            submenu_usuarios(obj);
            break;
        case '2':
            system("cls");
            submenu_comidas(obj);
            break;
        case '0':
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
    while(opc != '0');
}

void submenu_usuarios(Admin obj)
{
    char opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Listado general"<<endl
            <<"2. Listado por cédula"<<endl
            <<"3. Modificar un usuario"<<endl
            <<"0. Salir"<<endl<<endl
            <<"Seleccione una opción: ";
        opc = getch();

        switch(opc)
        {
        case '1':
            system("cls");
            listaUsuarios();
            break;
        case '2':
            system("cls");
            listaxCedula();
            break;
        case '3':
            system("cls");
            modificarUsuarioADMIN();
            break;
        case '0':
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
    while(opc != '0');
}

void submenu_comidas(Admin obj)
{
    char opc;
    do
    {
        system("cls");
        cout<<"¡Bienvenido, "<<obj.getUser()<<"! ¿Qué desea hacer?"<<endl<<endl
            <<"1. Agregar menú"<<endl
            <<"2. Ver menú"<<endl
            <<"3. Modificar un menú"<<endl
            <<"0. Salir"<<endl<<endl
            <<"Seleccione una opción: ";
        opc = getch();

        switch(opc)
        {
        case '1':
            system("cls");
            agregarComida();
            break;
        case '2':
            system("cls");
            imprimir_menu(true);
            system("pause");
            break;
        case '3':
            system("cls");
            imprimir_menu(true);
            modificarComida();
            break;
        case '0':
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
    while(opc != '0');
}


void listaxCedula()
{
    F5_usuarios();

    bool existe = false;
    string cedula_buscar;
    cout<<"Ingrese la cedula a buscar: ";
    cin>>cedula_buscar;
    cout<<endl;

    int i;
    Admin obj;
    for (i=0; i<vUsers.size(); i++) //Busca si existe un usuario con dicha cédula
    {
        obj = vUsers.at(i);
        if(cedula_buscar.compare(obj.getCedula()) == 0)
        {
            existe = true;
            break; //Sale del bucle
        }
    }
    if (existe == true) //Si existe, pregunta qué desea cambiar
    {
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
    else cout<<"El cliente con CC "<<cedula_buscar<<" no existe en el archivo"<<endl<<endl;
    system("pause");
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

void modificarComida()
{
    F5_comidas();
    char opc = 0;
    bool existe = false, sigue, mod = false;
    int pos_modificar;
    cout<<"Ingrese la posición del menú a modificar: ";
    cin>>pos_modificar;

    int i;
    Comidas objComprobacion;
    Comidas obj;
    for (i=0; i<vComidas.size(); i++) //Busca si existe un menú con dicha posición
    {
        obj = vComidas.at(i);
        if(pos_modificar == obj.getPosicion())
        {
            existe = true;
            break; //Sale del bucle
        }
    }
    if (existe == true) //Si existe, pregunta qué desea cambiar
    {
        do
        {
            system("cls");
            cout<<"Datos del menú: "<<endl;
            cout<<"1. Posición: "<<obj.getPosicion()<<endl;
            cout<<"2. Nombre: "<<obj.getNombre()<<endl;
            cout<<"3. Ingredientes: "<<obj.getIngrediente()<<endl;
            cout<<"4. Precio: "<<obj.getPrecio()<<endl;
            cout<<"5. Estado: "<<boolalpha<<obj.getActivo()<<endl;
            cout<<"0. Salir"<<endl<<endl;

            cout<<"Seleccione el dato a modificar: ";
            opc = _getch();
            fflush (stdin);

            bool sigue = true;
            int pos;
            string nom, ingr;
            long precio;
            char activ;

            switch (opc)
            {
            case '1':
                mod = true;
                cout<<endl<<"Ingrese la nueva posición: ";
                cin>>pos;
                for (int f=0; f<vComidas.size(); f++) //Comprueba si ya existe un menú en esa posición
                {
                    objComprobacion = vComidas.at(f);
                    if (objComprobacion.getPosicion() == pos)
                    {
                        sigue = false;
                        break;
                    }
                }
                if (!sigue)
                {
                    cout<<"Ya existe un menú en esa posición, elija una diferente."<<endl<<endl;
                    system("pause");
                }
                else if (pos < 1) cout<<"No ingrese un número menor que 1."<<endl;
                else obj.setPosicion(pos);

                break;

            case '2':
                mod = true;
                cout<<endl<<"Ingrese el nuevo nombre: ";
                getline(cin, nom);
                obj.setNombre(nom);
                break;

            case '3':
                mod = true;
                cout<<endl<<"Ingrese los nuevos ingredientes (separados por una coma y un espacio): ";
                getline(cin, ingr);
                obj.vIngredientes.clear();
                transform(ingr.begin(), ingr.end(), ingr.begin(), ::tolower);
                obj.setIngrediente(ingr);
                break;

            case '4':
                mod = true;
                cout<<endl<<"Ingrese el nuevo precio: ";
                cin>>precio;
                fflush(stdin);
                obj.setPrecio(precio);
                break;

            case '5':
                mod = true;
                if (obj.getActivo() == true) obj.setActivo(false);
                else obj.setActivo(true);
                break;

            default:
                cout<<endl<<"Ingrese una opción válida"<<endl;
                break;

            }
            vComidas.at(i) = obj;
        }
        while(opc != '0');
        system("cls");

    }
    else cout<<"No existe un menú en la posición "<<pos_modificar<<"."<<endl<<endl;

    if (mod == true) F5_comidasArchivo();
    system("pause");
}


void modificarUsuarioADMIN()
{
    F5_usuarios();
    char opc = 0;
    bool existe = false, mod = false;
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
            existe = true;
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
                cout<<"3. Dirección: "<<obj.getDireccion()<<endl;
                cout<<"4. Puntos: "<<obj.getPuntos()<<endl;
                cout<<"5. Admin: "<<boolalpha<<obj.getAdmin()<<endl;
                cout<<"6. Estado: "<<boolalpha<<obj.getActivo()<<endl;
                cout<<"0. Salir"<<endl<<endl;

                cout<<"Seleccione el dato a modificar: ";
                opc = _getch();
                fflush (stdin);

                string nom, ape, dir;
                long puntos;
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
                    cout<<endl<<"Ingrese la nueva dirección: ";
                    getline(cin, dir);
                    obj.setDireccion(dir);
                    break;

                case '4':
                    mod = true;
                    cout<<endl<<"Ingrese la nueva cantidad de puntos: ";
                    cin>>puntos;
                    obj.setPuntos(puntos);
                    break;

                case '5':
                    mod = true;
                    if (obj.getAdmin() == true) obj.setAdmin(false);
                    else obj.setAdmin(true);
                    break;

                case '6':
                    mod = true;
                    if (obj.getActivo() == true) obj.setActivo(false);
                    else obj.setActivo(true);
                    break;

                default:
                    cout<<endl<<"Ingrese una opción válida"<<endl;
                    break;

                }
                vUsers.at(i) = obj;
            }
            while(opc != '0');
            system("cls");
        }
    }
    else cout<<"El cliente con CC "<<cedula_buscar<<" no existe en el archivo"<<endl<<endl;

    if (mod == true) F5_usuariosArchivo();
    system("pause");
    cout<<"Usuario modificado con éxito."<<endl<<endl;
}

void modificarUsuarioPROPIO(Admin _user)
{
    F5_usuarios();
    char opc = 0;
    bool mod = false;


    int i;
    Admin obj;
    for (i=0; i<vUsers.size(); i++) //Busca en qué posición se encuentra el usuario en el vector vUsers
    {
        obj = vUsers.at(i);
        if(_user.getCedula().compare(obj.getCedula()) == 0) break; //Sale del bucle
    }

    do
    {
        system("cls");
        cout<<"Datos de "<<obj.getUser()<<": "<<endl;
        cout<<"Numero de cedula: "<<obj.getCedula()<<endl;
        cout<<"1. Nombre: "<<obj.getNombre()<<endl;
        cout<<"2. Apellido: "<<obj.getApellido()<<endl;
        cout<<"3. Dirección: "<<obj.getDireccion()<<endl;
        cout<<"4. Admin: "<<boolalpha<<obj.getAdmin()<<endl;
        cout<<"5. Puntos: "<<obj.getPuntos()<<endl;
        cout<<"6. Estado: "<<boolalpha<<obj.getActivo()<<endl;
        cout<<"0. Salir"<<endl<<endl;

        cout<<"Seleccione el dato a modificar: ";
        opc = _getch();
        fflush (stdin);

        string nom, ape, dir;
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
            cout<<endl<<"Ingrese la nueva dirección: ";
            getline(cin, dir);
            obj.setDireccion(dir);
            break;

        case '4':
            mod = true;
            if (obj.getAdmin() == true) obj.setAdmin(false);
            else obj.setAdmin(true);
            break;

        case '5':
            mod = true;
            if (obj.getActivo() == true) obj.setActivo(false);
            else obj.setActivo(true);
            break;

        default:
            cout<<endl<<"Ingrese una opción válida"<<endl;
            break;

        }
        vUsers.at(i) = obj;
    }
    while(opc != '0');
    system("cls");

    if (mod == true) F5_usuariosArchivo();
    system("pause");
    cout<<"Usuario modificado con éxito."<<endl<<endl;
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


/*void canPuntos(){
    F5_pedidos();
    clientePreferencial objPuntos;
    //Comidas objComidas;

    int i;
    bool clienteP = false;
    int cont;
    for(i=0; i<.size(); i++){

        objComidas = vPedidos.at(i);
        clienteP = true;

        if(clienteP == true){
            cont += (objPuntos.getTotalcuenta())/1000;
            cout<<"El cliente tiene "<<cont<<" puntos"<<endl;
        }else cout<<"El cliente no es preferencial"<<endl;
    }

}*/


///Main
int main()
{
    setlocale(LC_ALL, ""); //Para soportar caracteres especiales

    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE); //Para cambiar el color del texto
    SetConsoleTextAttribute(hconsole,15); //Para cambiar el color del texto

    menuBienvenida();
    return 0;
}
