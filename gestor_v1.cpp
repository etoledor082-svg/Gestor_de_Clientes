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
        static float accederIngreso();
};

class Cliente:protected numeroRegistro
{
    string email;
    int telefono;
    Fecha apertura;
    int antiguedad;
    public:
        void asignaFecha(Fecha fa, int d, int m, int a);
        void asignaAntiguedad();
        void setemail();
        string getemail();
        void settelefono();
        int gettelefono();
        int calcAntiguedad();

};

class Servicio:protected numeroRegistro
{
    float costo;

    public:
        void setprecio();
        float getprecio();
        void descuento();
};

class Producto:private Servicio
{
    int unidades;

    public:
        void verUnidades();
        void venta();
        void stock();
};

int numeroRegistro::accederRegistro()
{
    return contador;
};

float numeroRegistro::accederIngreso()
{
    return ingreso;
}

void numeroRegistro::setregistro(int r)
{
    // Validar la opción de hacer que el número de registro lo brindemos nosotros
    registro = r;
}

int numeroRegistro::getregistro()
{
    return registro;
}

void Cliente::asignaFecha(Fecha fa, int d, int m, int a)
{
    cout << "Dia: ";
    cin >> d;
    cout << "Mes: ";
    cin >> m;
    cout << "Año: ";
    cin >> a;
}
