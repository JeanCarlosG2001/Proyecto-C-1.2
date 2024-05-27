#include <stdio.h>
#include "funciones.h"

int main() {
    struct Producto productos[6] = {
        {"Laptop", 1000, 2500, 10},
        {"Telefono inteligente", 800, 200, 20},
        {"Tableta", 500, 300, 15},
        {"Camara digital", 600, 150, 8},
        {"Auriculares inalambricos", 200, 50, 25},
        {"Smartwatch", 300, 100, 30}
    };

    int cantidad[6] = {0}; 
    float precioProducto[6] = {0}; 
    int numProductos = 0; 

    while (1) {
        printf("\nMenu de Productos Exportados de Tecnologia:\n");
        printf("%-2s %-30s %-10s %-10s %-10s\n", "No", "Producto", "Precio", "Peso", "Inventario");
        for (int i = 0; i < 6; i++) {
            printf("%-2d %-30s $%.2f      %.2f g      %d\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].peso, productos[i].inventario);
        }

        printf("Seleccione una opcion:\n");
        printf("1. Comprar productos\n");
        printf("2. Consultar inventario\n");
        printf("3. Actualizar inventario\n");
        printf("0. Salir\n");

        int opcion;
        scanf("%d", &opcion);

        if (opcion == 0) {
            break;
        }

        switch (opcion) {
            case 1:
                while (1) {
                    printf("Seleccione el producto que desea comprar (1-6), o 0 para terminar: ");
                    int indiceProducto;
                    scanf("%d", &indiceProducto);

                    if (indiceProducto == 0) {
                        break;
                    }
                    if (indiceProducto < 1 || indiceProducto > 6) {
                        printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                        continue;
                    }
                    indiceProducto--;

                    printf("Ingrese la cantidad de productos que desea comprar: ");
                    int cantidadProducto;
                    scanf("%d", &cantidadProducto);

                    if (cantidadProducto <= 0) {
                        printf("Cantidad inválida. Por favor, ingrese una cantidad positiva.\n");
                        continue;
                    }
                    if (cantidadProducto > productos[indiceProducto].inventario) {
                        printf("Cantidad no disponible en inventario. Por favor, ingrese una cantidad menor.\n");
                        continue;
                    }


                    cantidad[indiceProducto] += cantidadProducto;

                    precioProducto[indiceProducto] = productos[indiceProducto].precio;

                    productos[indiceProducto].inventario -= cantidadProducto;

                    if (cantidad[indiceProducto] == cantidadProducto) {
                        numProductos++;
                    }
                }
                break;
            case 2:
                mostrarInventario(productos, 6);
                break;
            case 3:
                actualizarInventario(productos, 6);
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    }


    float subtotal = 0;
    for (int i = 0; i < 6; i++) {
        if (cantidad[i] > 0) {
            subtotal += precioProducto[i] * cantidad[i];
        }
    }


    float interes = subtotal * (INTERES / 100);
    float iva = subtotal * IVA;
    float costoEnvio = 0;
    for (int i = 0; i < 6; i++) {
        if (cantidad[i] > 0) {
            costoEnvio += calcularCostoEnvio(productos[i].peso, cantidad[i]);
        }
    }

    float total = subtotal + interes + iva + costoEnvio;
    imprimirFactura(productos, precioProducto, interes, iva, costoEnvio, total, cantidad, numProductos);

    printf("Gracias por su compra.\n");

    return 0;
}
