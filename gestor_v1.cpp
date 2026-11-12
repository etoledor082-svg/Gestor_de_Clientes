#include <iostream>
using namespace std;

class Fecha
{
    int dia, mes, año;
};

class Ingreso
{
    float ingreso;
};

class numeroRegistro
{
    int registro;
    static int contador;
    static float ingreso;
    
    public:
        void setregistro(int r);
        int getregistro();
        static int accederRegistro();
        static int accederIngreso();
};

class Cliente:protected numeroRegistro
{
    string email;
    int telefono;

};
