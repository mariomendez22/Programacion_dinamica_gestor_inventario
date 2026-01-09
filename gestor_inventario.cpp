#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

// Estructura que representa un producto
struct Producto {
    int id;
    string nombre;
    double precio;
    int cantidad;
};

// Leer enteros con validación
int leerEntero(const string &msg) {
    int x;
    cout << msg;
    if (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Entrada no valida.");
    }
    return x;
}

// Leer números decimales
double leerDecimal(const string &msg) {
    double x;
    cout << msg;
    if (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Entrada no valida.");
    }
    return x;
}

// Mostrar un producto
void mostrarProducto(const Producto &p) {
    cout << "ID: " << p.id
         << " | Nombre: " << p.nombre
         << " | Precio: $" << p.precio
         << " | Cantidad: " << p.cantidad << "\n";
}

// Inicializar 10 productos
void iniciarProductos(Producto arr[], int n) {
      // Producto 0
    arr[0].id = 101;
    arr[0].nombre = "Lapiz";
    arr[0].precio = 5.50;
    arr[0].cantidad = 50;

    // Producto 1
    arr[1].id = 102;
    arr[1].nombre = "Cuaderno";
    arr[1].precio = 25.00;
    arr[1].cantidad = 30;

    // Producto 2
    arr[2].id = 103;
    arr[2].nombre = "Borrador";
    arr[2].precio = 3.20;
    arr[2].cantidad = 100;

    // Producto 3
    arr[3].id = 104;
    arr[3].nombre = "Resaltador";
    arr[3].precio = 10.00;
    arr[3].cantidad = 40;

    // Producto 4
    arr[4].id = 105;
    arr[4].nombre = "Carpeta";
    arr[4].precio = 15.00;
    arr[4].cantidad = 20;

    // Producto 5
    arr[5].id = 106;
    arr[5].nombre = "Boligrafo";
    arr[5].precio = 7.50;
    arr[5].cantidad = 60;

    // Producto 6
    arr[6].id = 107;
    arr[6].nombre = "Regla";
    arr[6].precio = 6.00;
    arr[6].cantidad = 25;

    // Producto 7
    arr[7].id = 108;
    arr[7].nombre = "Mochila";
    arr[7].precio = 350.00;
    arr[7].cantidad = 10;

    // Producto 8
    arr[8].id = 109;
    arr[8].nombre = "Calculadora";
    arr[8].precio = 199.99;
    arr[8].cantidad = 8;

    // Producto 9
    arr[9].id = 110;
    arr[9].nombre = "Agenda";
    arr[9].precio = 120.00;
    arr[9].cantidad = 12;
}

// Buscar por ID
Producto* buscarPorId(Producto arr[], int n, int id) {
    for (int i = 0; i < n; ++i) {
        if (arr[i].id == id) return &arr[i];
    }
    throw runtime_error("No se encontro un producto con ese ID.");
}

// Buscar por nombre
Producto* buscarPorNombre(Producto arr[], int n, const string &nombre) {
    for (int i = 0; i < n; ++i) {
        if (arr[i].nombre == nombre) return &arr[i];
    }
    throw runtime_error("No se encontro un producto con ese nombre.");
}

// Ordenar por precio (burbuja)
void ordenarPorPrecio(Producto arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].precio > arr[j+1].precio) {
                Producto temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Ordenar por cantidad (burbuja)
void ordenarPorCantidad(Producto arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].cantidad < arr[j+1].cantidad) {
                Producto temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Cambiar cantidad (puntero)
void cambiarCantidad(Producto *prod, int cambio) {
    if (!prod) throw runtime_error("Producto no existe.");
    int nuevaCantidad = prod->cantidad + cambio;

    if (nuevaCantidad < 0) throw runtime_error("No hay suficiente cantidad.");
    prod->cantidad = nuevaCantidad;
}

// Listar todos los productos
void mostrarTodos(Producto arr[], int n) {
    cout << "\nLista de productos:\n";
    for (int i = 0; i < n; i++) {
        mostrarProducto(arr[i]);
    }
}

// Menu principal
void mostrarMenu() {
    cout << "\n--- Sistema de Inventario ---\n";
    cout << "1. Mostrar todos los productos\n";
    cout << "2. Buscar por ID\n";
    cout << "3. Buscar por Nombre\n";
    cout << "4. Ordenar por Precio (menor a mayor)\n";
    cout << "5. Ordenar por Cantidad (mayor a menor)\n";
    cout << "6. Modificar cantidad\n";
    cout << "7. Salir\n";
    cout << "-----------------------------\n";
}

int main() {
    const int N = 10;
    Producto inventario[N];

    iniciarProductos(inventario, N);

    cout << "Bienvenido al sistema de inventario.\n";

    bool activo = true;

    while (activo) {
        try {
            mostrarMenu();
            int opcion = leerEntero("Elige una opcion: ");

            if (opcion == 1) {
                mostrarTodos(inventario, N);
            }
            else if (opcion == 2) {
                int id = leerEntero("Ingresa el ID: ");
                Producto *p = buscarPorId(inventario, N, id);
                mostrarProducto(*p);
            }
            else if (opcion == 3) {
                cout << "Ingresa nombre: ";
                string nombre;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nombre);
                Producto *p = buscarPorNombre(inventario, N, nombre);
                mostrarProducto(*p);
            }
            else if (opcion == 4) {
                ordenarPorPrecio(inventario, N);
                cout << "Ordenados por precio.\n";
                mostrarTodos(inventario, N);
            }
            else if (opcion == 5) {
                ordenarPorCantidad(inventario, N);
                cout << "Ordenados por cantidad.\n";
                mostrarTodos(inventario, N);
            }
            else if (opcion == 6) {
                int id = leerEntero("ID del producto: ");
                Producto *p = buscarPorId(inventario, N, id);
                cout << "Producto seleccionado:\n";
                mostrarProducto(*p);

                cout << "Ingresa cambio de cantidad (ej: -3 o 5): ";
                int cambio = leerEntero("");
                cambiarCantidad(p, cambio);

                cout << "Nueva informacion:\n";
                mostrarProducto(*p);
            }
            else if (opcion == 7) {
                cout << "Saliendo...\n";
                activo = false;
            }
            else {
                cout << "Opcion no valida.\n";
            }
        }
        catch (const exception &e) {
            cout << "Error: " << e.what() << "\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
