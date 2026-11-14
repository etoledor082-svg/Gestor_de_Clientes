#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

#define tam 5

class Cliente;
class Fecha;

class Fecha
{
    int dia, mes, año;

    public:
        Fecha(int d, int m, int a);
        Fecha();
        friend void visualizarCuenta(Cliente *ptr);
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
        void setregistro();
        int getregistro();
        static int accederRegistro();
        // static float accederIngreso();
        friend void visualizarCuenta(Cliente *ptr);
};

class Cliente:protected numeroRegistro, public Fecha
{
    Fecha fa;
    string email;
    string nombre;
    string telefono;
    int antiguedad;
    int matricula1;

    public:
        Cliente();
        void asignaFecha(Cliente *ptr, int d, int m, int a);
        void asignaAntiguedad(int ant);
        void setemail(string em);
        string getemail();
        void settelefono(string tel);
        string gettelefono();
        int calcAntiguedad();
        Fecha getFecha();
        void asignaNombre(string pn, string pa);
        string getnombre();
        friend void visualizarCuenta(Cliente *ptr);

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

Fecha::Fecha()
{
    dia = 0;
    mes = 0;
    año = 0;
}

Fecha::Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    año = a;
    cout << "hola" << endl;
}

Fecha Cliente::getFecha()
{
    return fa;
}

int numeroRegistro::accederRegistro()
{
    return contador;
};

/*float numeroRegistro::accederIngreso()
{
    return ingreso;
}*/

void numeroRegistro::setregistro()
{
    // Validar la opción de hacer que el número de registro lo brindemos nosotros
    registro = 1000000 + rand() % 9000000;
    contador++;
}

int numeroRegistro::getregistro()
{
    return registro;
}

Cliente::Cliente()
{
    email = ' ';
    telefono = ' ';
}

void Cliente::asignaFecha(Cliente *ptr, int d, int m, int a)
{
    // Valorar la opción de implementar un constructor con herencia para guardar las fechas
    cout << "Introduzca la fecha del día de hoy: " << endl;
    cout << "Dia: ";
    cin >> d;
    cout << "Mes: ";
    cin >> m;
    cout << "Año: ";
    cin >> a;

    fa = Fecha(d, m, a);
    (ptr + numeroRegistro::accederRegistro())->setregistro();
    (ptr + numeroRegistro::accederRegistro())->getregistro();

}

void Cliente::asignaNombre(string pn, string pa)
{
    cout << "Primer Nombre: " << endl;
    cin >> pn;
    cout << "Primer Apellido: " << endl;
    cin >> pa;    
    nombre = pn + " " + pa;
}

string Cliente::getnombre()
{
    return nombre;
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

void Cliente::settelefono(string tel)
{
    telefono = tel;
}

string Cliente::gettelefono()
{
    return telefono;
}

/*int Cliente::calcAntiguedad()
{
    // Añadir un atributo para que el usuario al entrar ingrese la fecha actual y este método se encargará
    // de calcular el tiempo que ha estado registrado.
}*/

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

void visualizarCuenta(Cliente *ptr)
{
    cout << "┌───────────┬────────────────────────┐" << endl;
    cout << "│  Cuenta   │    Datos ingresados    │" << endl;
    cout << "├───────────┼────────────────────────┤" << endl;

    for (int i = 0; i < numeroRegistro::accederRegistro(); i++)
    {
    string imp_nombre = (ptr + i)->getnombre();
    string imp_email = (ptr + i)->getemail();
    string imp_telefono = (ptr + i)->gettelefono();
    string imp_matricula = to_string((ptr + i)->getregistro());
    string imp_fecha_ap = to_string((ptr + i)->getFecha().dia) + "/" + to_string((ptr + i)->getFecha().mes) + "/" + to_string((ptr + i)->getFecha().año);

    cout << left 
         << setw(13) << "│ Nombre    │" << right << setw(24) << imp_nombre << "│" << endl
         << "├───────────┼────────────────────────┤" << endl 
         << setw(13) << "│ Matrícula │" << right << setw(24) << imp_matricula << "│" << endl
         << "├───────────┼────────────────────────┤" << endl
         << setw(13) << "│ Email     │" << right << setw(24) << imp_email << "│" << endl
         << "├───────────┼────────────────────────┤" << endl
         << setw(13) << "│ Telefono  │" << right << setw(24) << imp_telefono << "│" << endl
         << "├───────────┼────────────────────────┤" << endl
         << setw(13) << "│ Fecha Apt │" << right << setw(24) << imp_fecha_ap << "│" << endl;
    }
    cout << "└───────────┴────────────────────────┘" << endl;
}

void menu(Cliente *ptr, string em, string pn, string pa, string tel, int d, int m, int a)
{
    int eleccion;
    do
    {
        cout << "Bienvenido usuario, selecciona la opción deseada." << endl;
        cout << "1. Crear Cuenta." << endl;
        cout << "2. Iniciar Sesión." << endl;
        cout << "0. Salir." << endl;
        cout << "Número de acción a realizar: ";
        cin >> eleccion;


        if (eleccion == 1)
        {
            cout << "Email: ";
            cin >> em;
            cout << "Teléfono: ";
            cin >> tel;

            (ptr + numeroRegistro::accederRegistro())->asignaNombre(pn, pa);
            (ptr + numeroRegistro::accederRegistro())->setemail(em);
            (ptr + numeroRegistro::accederRegistro())->settelefono(tel);
            (ptr + numeroRegistro::accederRegistro())->asignaFecha(ptr, d, m, a);
            

            // cout << "Email: " << (ptr + numeroRegistro::accederRegistro())->getemail() << endl;
            // cout << "Telefono: " << (ptr + numeroRegistro::accederRegistro())->gettelefono() << endl;

            visualizarCuenta(ptr);

        }
        else if (eleccion == 2)
        {
            cout << "Hola" << endl;
        }
        else if (eleccion == 0)
        {
            cout << "Gracias por tu preferencia." << endl;
        }
        else
        {
            cout << "Opción inválida." << endl;
        }
    }
    while (eleccion != 0);
}

int numeroRegistro::contador = 0;

int main()
{
    // Agregar una función de menú para elegir si aperturar, consultar o cancelar una cuenta

    srand(static_cast<unsigned>(time(nullptr)));

    Cliente obj[tam];
    Cliente *ptr;
    ptr = &obj[0];
    string em, pn, pa, tel;
    int d, m, a;

    menu(ptr, em, pn, pa, tel, d, m, a);

    return 0;
}
