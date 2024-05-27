#ifndef FUNCIONES_H
#define FUNCIONES_H


#define IVA 0.15
#define INTERES 5.0


struct Producto {
    char nombre[30];
    float precio;
    float peso;
    int inventario; 
};


void mostrarInventario(struct Producto productos[], int size);
void actualizarInventario(struct Producto productos[], int size);
float calcularCostoEnvio(float peso, int cantidad);
void imprimirFactura(struct Producto productos[], float precioProducto[], float interes, float iva, float costoEnvio, float total, int cantidad[], int numProductos);

#endif
