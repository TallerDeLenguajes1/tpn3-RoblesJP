#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;

// estructuras
typedef struct {
    int id;
    int cant; // [1, 10]
    char* tipo; // algun valor del arreglo tiposProductos
    int precioUnitario; // [10, 100]
} PRODUCTO;

typedef struct {
    int id;
    char* nombre; // ingresado por usuario
    int cantProductos; // [1, 5]
    PRODUCTO* productos;
} CLIENTE;


// funciones
void cargaCliente(CLIENTE*, int, const char**);
void mostrarCliente(CLIENTE*);
void mostrar(CLIENTE*, int);
int costoProducto(PRODUCTO*);

int main() {
    srand(time(NULL));
    const char* tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    int cantClientes;
    do {
        cout << "\n>> Ingrese la cantidad de clientes: ";
        cin >> cantClientes;
        if (cantClientes < 0) {
            cout << "!Error: Cantidad ingresada incorrecta";
        }
    } while (cantClientes < 0);

    CLIENTE* clientes = new CLIENTE[cantClientes];
    cout << "\n# Arreglo de " << cantClientes << " clientes creado\n";

    cargaCliente(clientes, cantClientes, tiposProductos);
    
    mostrar(clientes, cantClientes);

    delete[] clientes;
    return 0;
}

void cargaCliente(CLIENTE* cliente, int cantClientes, const char** tiposProductos) {
    for(int i = 0; i < cantClientes; i++) {
        // cliente
        (cliente + i)->id = i + 1;

        cout << "Ingrese el nombre del cliente #" << i + 1 << ": ";
        char nombre[30];
        cin >> nombre;
        (cliente + i)->nombre = new char[strlen(nombre) + 1];
        strcpy((cliente + i)->nombre, nombre);

        (cliente + i)->cantProductos = rand() % 5 + 1;
        (cliente + i)->productos = new PRODUCTO[cliente->cantProductos];

        // productos del cliente
        for (int j = 0; j < (cliente + i)->cantProductos; j++) {
            ((cliente + i)->productos + j)->id = j + 1;
            ((cliente + i)->productos + j)->cant = rand() % 10 + 1;
            const char* tipo = *(tiposProductos + rand() % 5);
            ((cliente + i)->productos + j)->tipo = new char[strlen(tipo) + 1];
            strcpy(((cliente + i)->productos + j)->tipo, tipo);
            ((cliente + i)->productos + j)->precioUnitario = rand() % 91 + 10;
        }
    }
}

void mostrarCliente(CLIENTE* cliente) {
    int totalPago = 0;
    cout << "\n### Cliente ID: " << cliente->id;
    cout << "\nNombre: " << cliente->nombre;
    cout << "\nCantidad de productos: " << cliente->cantProductos;
    cout << "\n-Lista de productos: ";
    for (int i = 0; i < cliente->cantProductos; i++) {
        cout << "\nProducto ID: " << (cliente->productos + i)->id;
        cout << "\nCantidad: " << (cliente->productos + i)->cant;
        cout << "\nTipo: " << (cliente->productos + i)->tipo;
        cout << "\nPrecio Unitario: " << (cliente->productos + i)->precioUnitario << "$";
        totalPago += costoProducto((cliente->productos + i));
        cout << "\n";
    }
    cout << "\nTOTAL A PAGAR: " << totalPago << "$";
    cout << "\n################";
    cout << "\n";
}

void mostrar(CLIENTE* cliente, int cantClientes) {
    for (int i = 0; i < cantClientes; i++) {
        mostrarCliente(cliente + i);
    }
}

int costoProducto(PRODUCTO* producto) {
    return producto->cant * producto->precioUnitario;
}