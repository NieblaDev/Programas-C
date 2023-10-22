
//21.659.326-k. Benjamin Jara Soto  , seccion 1 
//21.608.086-6. Renato Acosta Ormeño, seccion 1

#include <stdio.h>
#include <stdlib.h>
//Version Finalizada wena wena
int ingresar_entero_mayor_o_igual(int minimo);
int ingresar_entero_rango(int minimo, int maximo);
void procesar_ventas(int valores_productos[], int existencias_productos[], int* total_ventas);
void mostrar_existencias(int existencias_productos[]);
void mostrar_monto_total_ventas(int* total_ventas);
void mostrar_boleta(int valores_productos_en_el_carro[], int cantidad_productos_en_el_carro[], int* total_ventas);
int main()
{
    int valores_productos[17] = { 0, 25000, 60000, 33000, 72000, 12000, 15000, 7000, 12000, 20000, 21000, 15000, 20000, 10000, 12000, 18000, 20000 };
    int existencias_productos[17] = { 0, 8, 4, 6, 6, 15, 15, 12, 5, 10, 20, 8, 6, 12, 20, 10, 10 };
    int total_ventas = 0;
    do {
        system("cls");
        printf("_____________________________________________\n");
        printf(" >>   BIENVENIDO A VENTAS MEGARETAIL V2   << \n");
        printf("_____________________________________________\n");
        printf(" 1. Procesar Ventas.                         \n");
        printf(" 2. Mostrar Cantidad Existencias             \n");
        printf(" 3. Mostrar Monto Total Ventas               \n");
        printf(" 4. Salir Del Programa                       \n");
        printf("_____________________________________________\n");
        printf(" >> Seleccione opcion por numero:            \n");
        switch (ingresar_entero_rango(1, 4))
        {
        case 1:
            procesar_ventas(valores_productos, existencias_productos, &total_ventas);
            break;
        case 2:
            mostrar_existencias(existencias_productos);
            break;
        case 3:
            mostrar_monto_total_ventas(&total_ventas);
            break;
        case 4:
            printf("Muchas gracias, wena. :)\n");//firma del auto
            system("pause");
            return 0;

            break;
        }
    } while (1);
}

void procesar_ventas(int valores_productos[], int existencias_productos[], int* total_ventas)
{
    int opcion_producto, opcion_cantidad;
    int valores_productos_en_el_carro[17] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int cantidad_productos_en_el_carro[17] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    do
    {
        system("cls");
        printf("_____________________________________________\n");
        printf(">>             PROCESAR VENTAS             <<\n");
        printf("_____________________________________________\n");
        printf("1.  Zapato A              $25.000   stock: %d\n", existencias_productos[1]);
        printf("2.  Zapato B              $60.000   stock: %d\n", existencias_productos[2]);
        printf("3.  Zapatilla A           $33.000   stock: %d\n", existencias_productos[3]);
        printf("4.  Zapatilla B           $72.000   stock: %d\n", existencias_productos[4]);
        printf("5.  Pantalon femenino A   $12.000   stock: %d\n", existencias_productos[5]);
        printf("6.  Pantalon femenino B   $15.000   stock: %d\n", existencias_productos[6]);
        printf("7.  Polera femenina A     $ 7.000   stock: %d\n", existencias_productos[7]);
        printf("8.  Polera femenina B     $12.000   stock: %d\n", existencias_productos[8]);
        printf("9.  Poleron femenino A    $20.000   stock: %d\n", existencias_productos[9]);
        printf("10. Poleron femenino B    $21.000   stock: %d\n", existencias_productos[10]);
        printf("11. Pantalon masculino A  $15.000   stock: %d\n", existencias_productos[11]);
        printf("12. Pantalon masculino B  $20.000   stock: %d\n", existencias_productos[12]);
        printf("13. Polera masculina A    $10.000   stock: %d\n", existencias_productos[13]);
        printf("14. Polera masculina B    $12.000   stock: %d\n", existencias_productos[14]);
        printf("15. Poleron masculino A   $18.000   stock: %d\n", existencias_productos[15]);
        printf("16. Poleron masculino B   $20.000   stock: %d\n", existencias_productos[16]);
        printf("_____________________________________________\n");
        printf(">>  Ingrese el numero del producto a comprar:\n");
        opcion_producto = ingresar_entero_rango(1, 16);
        printf(">>  Ingrese la cantidad deseada:             \n");
        opcion_cantidad = ingresar_entero_mayor_o_igual(0);

        if (opcion_cantidad == 0)
        {
            printf(">> NO SE AGREGO NADA A LA COMPRA! \n");
        }
        else if (opcion_cantidad > existencias_productos[opcion_producto])
        {
            printf(">> SIN STOCK: Ingrese una cantidad menor o igual a %d!\n", existencias_productos[opcion_producto]);
        }
        else
        {
            printf(">> EL PRODUCTO HA SIDO AGREGADO A SU LISTA DE COMPRA! \n");
            cantidad_productos_en_el_carro[opcion_producto] += opcion_cantidad;//1
            existencias_productos[opcion_producto] -= opcion_cantidad;//2
            valores_productos_en_el_carro[opcion_producto] += opcion_cantidad * valores_productos[opcion_producto];//3
        }
        printf("_____________________________________________\n");
        printf(">> 1.SEGUIR COMPRANDO / 2. IMPRIMIR BOLETA: \n");

    } while (ingresar_entero_rango(1, 2) == 1);
    mostrar_boleta(valores_productos_en_el_carro, cantidad_productos_en_el_carro, total_ventas);
}

void mostrar_existencias(int existencias_productos[])
{
    system("cls");
    printf("_____________________________________________\n");
    printf(" >>          MOSTRAR EXISTENCIAS          << \n");
    printf("_____________________________________________\n");
    printf(" 1.  Zapato A                      stock: %d \n", existencias_productos[1]);
    printf(" 2.  Zapato B                      stock: %d \n", existencias_productos[2]);
    printf(" 3.  Zapatilla A                   stock: %d \n", existencias_productos[3]);
    printf(" 4.  Zapatilla B                   stock: %d \n", existencias_productos[4]);
    printf(" 5.  Pantalon femenino A           stock: %d \n", existencias_productos[5]);
    printf(" 6.  Pantalon femenino B           stock: %d \n", existencias_productos[6]);
    printf(" 7.  Polera femenina A             stock: %d \n", existencias_productos[7]);
    printf(" 8.  Polera femenina B             stock: %d \n", existencias_productos[8]);
    printf(" 9.  Poleron femenino A            stock: %d \n", existencias_productos[9]);
    printf(" 10. Poleron femenino B            stock: %d \n", existencias_productos[10]);
    printf(" 11. Pantalon masculino A          stock: %d \n", existencias_productos[11]);
    printf(" 12. Pantalon masculino B          stock: %d \n", existencias_productos[12]);
    printf(" 13. Polera masculina A            stock: %d \n", existencias_productos[13]);
    printf(" 14. Polera masculina B            stock: %d \n", existencias_productos[14]);
    printf(" 15. Poleron masculino A           stock: %d \n", existencias_productos[15]);
    printf(" 16. Poleron masculino B           stock: %d \n", existencias_productos[16]);
    printf("_____________________________________________\n");
    printf(" >> ");
    system("pause");
}

void mostrar_monto_total_ventas(int* total_ventas)
{
    system("cls");
    printf("_____________________________________________\n");
    printf(" >>          MONTO TOTAL VENDIDO          << \n");
    printf("_____________________________________________\n");
    printf(" Total de lo vendido:  $%d                   \n", *total_ventas);
    printf(" Ventas restantes:     $%d                   \n", 3219000 - *total_ventas);//3.219.000 es el total de ventas maximo que se pueden realizar
    printf("_____________________________________________\n");
    system("pause");
}

void mostrar_boleta(int valores_productos_en_el_carro[], int cantidad_productos_en_el_carro[], int* total_ventas)
{
    int total = 0;
    for (int i = 1; i < 17; i++) {
        total += valores_productos_en_el_carro[i];
    }
    system("cls");
    printf("_____________________________________________\n");
    printf(" *           BOLETA  ELECTRONICA           * \n");
    printf("_____________________________________________\n");
    printf(" Razon social:         Megaretail y Cia S.A. \n");
    printf(" RUT:                           99.999.999-9 \n");
    printf(" Giro:                       Grandes tiendas \n");
    printf(" Direccion:    Avenida Fake 1202, concepcion \n");
    printf(" Telefono:                       41 222 3333 \n");
    printf(" Email:           contacto@megaretailycia.cl \n");
    printf("_____________________________________________\n");
    printf(" Producto              Cantidad   Precio     \n");
    printf("_____________________________________________\n");
    for (int i = 1; i < 17; i++)
    {
        if (cantidad_productos_en_el_carro[i] > 0)
        {
            switch (i)
            {
            case 1:
                printf(" Zapato A              %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 2:
                printf(" Zapato B              %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 3:
                printf(" Zapatilla A           %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 4:
                printf(" Zapatilla B           %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 5:
                printf(" Pantalon femenino A   %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 6:
                printf(" Pantalon femenino B   %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 7:
                printf(" Polera femenina A     %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 8:
                printf(" Polera femenina B     %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 9:
                printf(" Poleron femenino A    %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 10:
                printf(" Poleron femenino B    %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 11:
                printf(" Pantalon masculino A  %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 12:
                printf(" Pantalon masculino B  %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 13:
                printf(" Polera masculina A    %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 14:
                printf(" Polera masculina B    %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 15:
                printf(" Poleron masculino A   %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            case 16:
                printf(" Poleron masculino B   %d           $%d    \n", cantidad_productos_en_el_carro[i], valores_productos_en_el_carro[i]);
                break;
            }
        }
    }
    printf("_____________________________________________\n");
    printf(" Total neto:          $%.2f                  \n", total - (total * 0.19));
    printf(" Total Iva (0.19):    $ %.2f                 \n", total * 0.19);
    printf(" Total:               $%d.00                 \n", total);
    printf("_____________________________________________\n");
    system("pause");
    *total_ventas += total;
}

int ingresar_entero_rango(int minimo, int maximo)
{
    int entero;
    do
    {
        scanf("%d", &entero);
    } while (entero < minimo || entero > maximo);

    return entero;
}

int ingresar_entero_mayor_o_igual(int minimo)
{
    int entero;
    do
    {
        scanf("%d", &entero);
    } while (entero < minimo);
    return entero;
}

//muchas gracias :), wena.