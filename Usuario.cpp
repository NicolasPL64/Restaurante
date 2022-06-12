#include <iostream>
using namespace std;
#include "Usuario.h"



Usuario::Usuario()
{
    user = pass = "-";
}

Usuario::~Usuario()
{
    //dtor
}

void Usuario::setUser(string u){
    user = u;
}

void Usuario::setPass(string p){
    pass = p;
}


string Usuario::getUser(){
    return user;
}

string Usuario::getPass(){
    return pass;
}
