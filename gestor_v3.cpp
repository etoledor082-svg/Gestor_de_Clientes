#include <iostream>
using namespace std;

class Fecha
{
    int dia, mes, año;

    public:
        Fecha(int d, int m, int a);
        Fecha();
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
        Cliente();
        void asignaFecha(int d, int m, int a);
        void asignaAntiguedad(int ant);
        void setemail(string em);
        string getemail();
        void settelefono(int tel);
        int gettelefono();
        int calcAntiguedad();

};

class Servicio:protected numeroRegistro
{
    float costo;

    public:
        void setprecio(float cos);
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

void Cliente::asignaFecha(int d, int m, int a)
{
    // Valorar la opción de implementar un constructor con herencia para guardar las fechas
    cout << "Dia: ";
    cin >> d;
    cout << "Mes: ";
    cin >> m;
    cout << "Año: ";
    cin >> a;

    Fecha fa(d, m, a);
}

void Cliente::asignaAntiguedad(int ant)
{
    antiguedad = ant;
}

void Cliente::setemail(string em)
{
    email = em;
}

string Cliente::getemail()
{
    return email;
}

void Cliente::settelefono(int tel)
{
    telefono = tel;
}

int Cliente::gettelefono()
{
    return telefono;
}

int Cliente::calcAntiguedad()
{
    // Añadir un atributo para que el usuario al entrar ingrese la fecha actual y este método se encargará
    // de calcular el tiempo que ha estado registrado.
}

void Servicio::setprecio(float cos)
{
    costo = cos;
}

float Servicio::getprecio()
{
    return costo;
}

void Servicio::descuento()
{
    // El descuento dependerá de la promoción que se establezca
}

void menu()
{
    int eleccion;
    do
    {
        cout << "Bienvenido usuario, selecciona la opción deseada." << endl;
        cout << "1. Crear Cuenta." << endl;
        cout << "2. Iniciar Sesión." << endl;
        cout << "Número de acción a realizar: ";
        cin >> eleccion;

        if (eleccion == 1)
        {
            
        }
        else if (eleccion == 2)
        {

        }
        else if (eleccion == 0)
        {
            cout << "Saliendo..." << endl;
        }
        else
        {
            cout << "Opción inválida." << endl;
        }
    }
    while (eleccion != 0);
}

int main()
{
    // Agregar una función de menú para elegir si aperturar, consultar o cancelar una cuenta

    Cliente obj;
    string em;
    int tel;
    int d, m, a;

    cout << "Email: ";
    cin >> em;
    cout << "Teléfono: ";
    cin >> tel;

    obj.asignaFecha(d, m, a);
}
