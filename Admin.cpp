#include <iostream>
using namespace std;
#include "Admin.h"

Admin::Admin()
{
    //ctor
}

Admin::~Admin()
{
    //dtor
}

//Setter
void Admin::setAdmin(bool _admin)
{
    admin = _admin;
}


//Getter
bool Admin::getAdmin()
{
    return admin;
}
