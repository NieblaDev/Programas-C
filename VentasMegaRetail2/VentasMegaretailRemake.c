#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct VentasMegaretailRemake {
    char nombre[25];
    int precio;
    int unidades;
}Producto;

int ingresarIntRango(int a, int b);
int ingresarIntMinimo(int a);
void mostrarMenuPrincipal(void);
void procesarVentas(Producto productos[], int* total_ventas);
void procesarExistencias(Producto productos[]);
void procesarVentasTotales(int* total_ventas);
void procesarBoleta(Producto carro[], int* total_ventas);

int main(void) {
    Producto productos[16] = {
        {"Zapato A"            , 25000,  8}, //.nombre//.precio//.unidades
        {"Zapato B"            , 60000,  4},
        {"Zapatilla A"         , 33000,  6},
        {"Zapatilla B"         , 72000,  6},
        {"Pantalon femenino A" , 12000, 15},
        {"Pantalon femenino B" , 15000, 15},
        {"Polera femenina A"   ,  7000, 12},
        {"Polera femenina B"   , 12000,  5},
        {"Poleron femenino A"  , 20000, 10},
        {"Poleron fememino B"  , 21000, 20},
        {"Pantalon masculino A", 15000,  8},
        {"Pantalon masculino B", 20000,  6},
        {"Polera masculina A"  , 10000, 12},
        {"Polera masculina B"  , 12000, 20},
        {"Poleron masculino A" , 18000, 10},
        {"Poleron masculino B" , 20000, 10},
    };
    int total_ventas = 0;
    while (1) {
        mostrarMenuPrincipal();
        switch (ingresarIntRango(1, 4)) {
        case 1:
            procesarVentas(productos, &total_ventas);
            break;
        case 2:
            procesarExistencias(productos);
            break;
        case 3:
            procesarVentasTotales(&total_ventas);
            break;
        case 4:
            return 0;
            break;
        }
        system("cls");
    }
}
void mostrarMenuPrincipal(void) {
    printf("_____________________________________________\n");
    printf("     Bienvenido a Ventas Megaretail v.3      \n");
    printf("_____________________________________________\n");
    printf(" 1. Procesar venta\n");
    printf(" 2. Existencias\n");
    printf(" 3. Total ventas\n");
    printf(" 4. Salir\n");
    printf("_____________________________________________\n");
    printf(" // Ingrese opcion #(1-4):\n >> ");
}
void procesarVentas(Producto productos[], int* total_ventas) {
    Producto carro[16] = { {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0}, {" ", 0, 0} };
    int producto_a_comprar, cantidad_a_comprar;

    do {
        system("cls");
        printf("_____________________________________________\n");
        printf("           MENU: *PROCESAR VENTAS*           \n");
        printf("_____________________________________________\n");
        printf(" N# |PRODUCTO               |PRECIO     |UND \n");
        for (int i = 0; i < 16; i++) {
            printf(" %-3d|%-23s|$%10d|%3d\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].unidades);
        }
        printf("_____________________________________________\n");
        printf(" // Ingrese producto #(1-16):\n >> ");
        producto_a_comprar = ingresarIntRango(1, 16);
        producto_a_comprar--;
        printf(" // Ingrese cantidad deseada #(max %d):\n >> ", productos[producto_a_comprar].unidades);
        cantidad_a_comprar = ingresarIntMinimo(0);
        if (cantidad_a_comprar == 0) {
            printf(" // NO se ha agregado nada a la compra!\n");
        }
        else if (cantidad_a_comprar > productos[producto_a_comprar].unidades) {
            printf(" // ERROR: La cantidad maxima es %d\n", productos[producto_a_comprar].unidades);
        }
        else {
            printf(" // El producto ha sido agregado a la compra!\n");
            productos[producto_a_comprar].unidades -= cantidad_a_comprar;
            carro[producto_a_comprar].unidades += cantidad_a_comprar;
            carro[producto_a_comprar].precio += productos[producto_a_comprar].precio * cantidad_a_comprar;
            strcpy(carro[producto_a_comprar].nombre, productos[producto_a_comprar].nombre);
        }
        printf(" // 1.Seguir Comprando / 2.Imprimir Boleta\n >> ");
    } while (ingresarIntRango(1, 2) == 1);

    procesarBoleta(carro, total_ventas);
}
void procesarExistencias(Producto productos[]) {
    system("cls");
    printf("_____________________________________________\n");
    printf("        MENU:  *PROCESAR EXISTENCIAS*        \n");
    printf("_____________________________________________\n");
    printf(" N# |PRODUCTO                      |UNIDADES \n");
    for (int i = 0; i < 16; i++) {
        printf(" %-3d|%-30s|%9d\n", i + 1, productos[i].nombre, productos[i].unidades);
    }
    printf("_____________________________________________\n >> ");
    system("pause");
}
void procesarVentasTotales(int* total_ventas) {
    system("cls");
    printf("_____________________________________________\n");
    printf("           MENU:  *VENTAS TOTALES*           \n");
    printf("_____________________________________________\n");
    printf(" TOTAL VENDIDO : %28d\n", *total_ventas);
    printf(" TOTAL FALTANTE: %28d\n", 3219000 - *total_ventas);
    printf(" TOTAL MAXIMO  : %28d\n", 3219000);
    printf("_____________________________________________\n >> ");
    system("pause");
}
void procesarBoleta(Producto carro[], int* total_ventas) {
    int total = 0;
    for (int i = 0; i < 16; i++) {
        total += carro[i].precio;
    }
    system("cls");
    printf("_____________________________________________\n");
    printf("            *BOLETA  ELECTRONICA*            \n");
    printf("_____________________________________________\n");
    printf(" Razon social:         Megaretail y Cia S.A. \n");
    printf(" RUT:                           99.999.999-9 \n");
    printf(" Giro:                       Grandes tiendas \n");
    printf(" Direccion:    Avenida Fake 1202, concepcion \n");
    printf(" Telefono:                       41 222 3333 \n");
    printf(" Email:           contacto@megaretailycia.cl \n");
    printf("_____________________________________________\n");
    printf(" N# |PRODUCTO               |PRECIO     |UND \n");
    for (int i = 0; i < 16; i++) {
        if (carro[i].unidades > 0) {
            printf(" %-3d|%-23s|$%10d|%3d\n", i + 1, carro[i].nombre, carro[i].precio, carro[i].unidades);
        }
    }
    printf("_____________________________________________\n");
    printf(" >> |Total neto:            |$%.2f           \n", total - (total * 0.19));
    printf(" >> |Iva 19%%:               |$ %.2f         \n", total * 0.19);
    printf(" >> |Total:                 |$%.2f           \n", (float)total);
    printf("_____________________________________________\n");
    *total_ventas += total;
    system("pause");
}
int ingresarIntRango(int a, int b) {
    int numero;
    do
    {
        scanf("%d", &numero);
    } while (numero < a || numero > b);
    return numero;
}
int ingresarIntMinimo(int a) {
    int numero;
    do
    {
        scanf("%d", &numero);
    } while (numero < a);
    return numero;

}