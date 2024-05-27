#include <stdio.h>
#include "funciones.h"


void mostrarInventario(struct Producto productos[], int size) {
    printf("\nInventario de Productos:\n");
    printf("%-2s %-30s %-10s %-10s %-10s\n", "No", "Producto", "Precio", "Peso", "Inventario");
    for (int i = 0; i < size; i++) {
        printf("%-2d %-30s $%.2f      %.2f g      %d\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].peso, productos[i].inventario);
    }
}


void actualizarInventario(struct Producto productos[], int size) {
    int indiceProducto;
    int nuevaCantidad;
    printf("Seleccione el producto cuyo inventario desea actualizar (1-%d), o 0 para terminar: ", size);
    scanf("%d", &indiceProducto);

    if (indiceProducto == 0) {
        return;
    }

    if (indiceProducto < 1 || indiceProducto > size) {
        printf("Opción inválida. Por favor, seleccione una opción válida.\n");
        return;
    }

    printf("Ingrese la nueva cantidad en inventario para %s: ", productos[indiceProducto - 1].nombre);
    scanf("%d", &nuevaCantidad);

    if (nuevaCantidad < 0) {
        printf("Cantidad inválida. Por favor, ingrese una cantidad positiva.\n");
        return;
    }

    productos[indiceProducto - 1].inventario = nuevaCantidad;
    printf("Inventario actualizado exitosamente.\n");
}


float calcularCostoEnvio(float peso, int cantidad) {

    return peso * cantidad * 0.1;
}

void imprimirFactura(struct Producto productos[], float precioProducto[], float interes, float iva, float costoEnvio, float total, int cantidad[], int numProductos) {
    printf("\nFactura de Compra:\n");
    printf("%-30s %-10s %-10s\n", "Producto", "Cantidad", "Precio");

    for (int i = 0; i < 6; i++) {
        if (cantidad[i] > 0) {
            printf("%-30s %-10d $%.2f\n", productos[i].nombre, cantidad[i], precioProducto[i] * cantidad[i]);
        }
    }

    printf("\nSubtotal: $%.2f\n", total - interes - iva - costoEnvio);
    printf("Interés: $%.2f\n", interes);
    printf("IVA: $%.2f\n", iva);
    printf("Costo de Envío: $%.2f\n", costoEnvio);
    printf("Total: $%.2f\n", total);
}
