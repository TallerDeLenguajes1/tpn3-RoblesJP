#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// estructuras
typedef struct {
    int id;
    int cant; // [1, 10]
    char* tipo; // algun valor del arreglo tiposProductos
    float precioUnitario; // [10, 100]
} PRODUCTO;

typedef struct {
    int id;
    char* nombre; // ingresado por usuario
    int cantProductos; // [1, 5]
    PRODUCTO productos;
} CLIENTE;


// funciones

int main() {
    int cantClientes;
    do {
        cout << "\n>> Ingrese la cantidad de clientes: ";
        cin >> cantClientes;
        if (cantClientes < 0) {
            cout << "!Error: Cantidad ingresada incorrecta";
        }
    } while (cantClientes < 0);



    return 0;
}