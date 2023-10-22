/*
Seccion 1
Renato Acosta Ormeño: 21.608.086-6
Benjamin Jara Soto: 21.659.326-k
*/
#include <stdio.h>
#include <stdlib.h>
//Funciones declaradas (para que sea más compatible con el compilador dev++)
int ventas();
int existencias();
int totalventas();
int boleta();
int salir();
// Variables globales
int modo, categoria, producto, cantidad;
// Zapatos y Zapatillas
int existencias_zapatoA = 6, existencias_zapatoB = 2, existencias_zapatillaA = 4, existencias_zapatillaB = 2;
int valor_zapatoA = 25000, valor_zapatoB = 60000, valor_zapatillaA = 33000, valor_zapatillaB = 72000;
// Moda Mujer
int existencias_pantalonA_M = 10, existencias_pantalonB_M = 10, existencias_poleraA_M = 8, existencias_poleraB_M = 10, existencias_poleronA_M = 5, existencias_poleronB_M = 6;
int valor_pantalonA_M = 12000, valor_pantalonB_M = 15000, valor_poleraA_M = 7000, valor_poleraB_M = 12000, valor_poleronA_M = 20000, valor_poleronB_M = 21000;
// Moda Hombre
int existencias_pantalonA_H = 5, existencias_pantalonB_H = 5, existencias_poleraA_H = 10, existencias_poleraB_H = 10, existencias_poleronA_H = 6, existencias_poleronB_H = 6;
int valor_pantalonA_H = 15000, valor_pantalonB_H = 20000, valor_poleraA_H = 10000, valor_poleraB_H = 12000, valor_poleronA_H = 18000, valor_poleronB_H = 20000;
// Linea Blanca y Electronica
int existencias_aspiradora = 2, existencias_microondas = 3, existencias_cocina = 1, existencias_lavadora = 1, existencias_referigerador = 1;
int valor_aspiradora = 50000, valor_microondas = 55000, valor_cocina = 200000, valor_lavadora = 350000, valor_referigerador = 250000;
// Computacion
int existencias_pcescritorio = 1, existencias_pcgamer = 2, existencias_notebook = 1, existencias_notebookgamer = 2;
int valor_pcescritorio = 500000, valor_pcgamer = 800000, valor_notebook = 220000, valor_notebookgamer = 999990;
// Existencias totales 
int existencias_zapatosyzapatillas, existencias_modamujer, existencias_modahombre, existencias_lineablanca, existencias_computacion, existencias_totales;
// Monto total de ventas
float ventas_maximas_totales = 7225980, ventas_maximas_zapatosyzapatillas = 546000, ventas_maximas_modamujer = 672000, ventas_maximas_modahombre = 623000, ventas_maximas_lineablanca = 1065000, ventas_maximas_computacion = 4319980;
float ventas_totales = 0, ventas_zapatosyzapatillas = 0, ventas_modamujer = 0, ventas_modahombre = 0, ventas_lineablanca = 0, ventas_computacion = 0;
// Boleta
int numero_boleta = 0;
float iva = 0.19, precio_unitario, precio_neto_unitario, precio_iva_unitario, neto_total, iva_total, total_boleta;
int nombre_producto = 0; // char *nombre_producto;

int main(){ 
    system("cls");
    printf("_____________________________________________\n");
    printf("**    BIENVENIDO A MEGARETAIL Y CIA S.A    **\n");
    printf("___________________Menu:_____________________\n");
    printf("1. Procesar Ventas\n");
    printf("2. Cantidad de Existencias\n");
    printf("3. Monto Total de Ventas\n");
    printf("4. Salir\n");
    printf("_____________________________________________\n");
    printf(">> Ingrese N* de modo: ");
    scanf("%d", &modo);

    switch (modo)
    {
    case 1:
        return ventas();
        break;
    case 2:
        return existencias();
        break;
    case 3:
        return totalventas();
        break;
    case 4:
        return salir();
        break;
    default:
        return main();
        break;
    }
}
int ventas(){
    system("cls");
    printf("_____________________________________________\n");
    printf("**          MODO: PROCESAR VENTAS          **\n");
    printf("___________________Menu:_____________________\n");
    printf("1. Zapatos y Zapatillas \n");
    printf("2. Moda Mujer \n");
    printf("3. Moda Hombre \n");
    printf("4. Linea Blanca y Electronica \n");
    printf("5. Computacion\n\n");
    printf("6. Volver al Menu Principal\n");
    printf("_____________________________________________\n");
    printf(">> Ingrese el N* de categoria: ");
    scanf("%d", &categoria);
    
    system("cls");
    switch (categoria){
    case 1:// Zapatos y Zapatillas
        printf("_____________________________________________\n");
        printf("*      CATEGORIA: ZAPATOS Y ZAPATILLAS      *\n");
        printf("_____________________________________________\n");
        printf("1. Zapato A $%d, stock: %d\n", valor_zapatoA, existencias_zapatoA);
        printf("2. Zapato B $%d, stock: %d\n", valor_zapatoB, existencias_zapatoB);
        printf("3. Zapatilla A $%d, stock: %d\n", valor_zapatillaA, existencias_zapatillaA);
        printf("4. Zapatilla B $%d, stock: %d\n\n", valor_zapatillaB, existencias_zapatillaB);
        printf("5. Volver al Menu de Ventas\n");
        printf("_____________________________________________\n");
        printf(">> Seleccione N* del producto a comprar: ");
        scanf("%d", &producto);
        if (producto == 5)
        {
            return ventas();
        }
        printf(">> Ingrese la cantidad que quiera comprar: ");
        scanf("%d", &cantidad);

        if (producto == 1)
        {
            if (existencias_zapatoA > 0)
            {
                while (cantidad > existencias_zapatoA || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 1;
                precio_unitario = valor_zapatoA;
                existencias_zapatoA -= cantidad;
                ventas_zapatosyzapatillas += valor_zapatoA * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 2)
        {
            if (existencias_zapatoB > 0)
            {
                while (cantidad > existencias_zapatoB || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 2;
                precio_unitario = valor_zapatoB;
                existencias_zapatoB -= cantidad;
                ventas_zapatosyzapatillas += valor_zapatoB * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 3)
        {
            if (existencias_zapatillaA > 0)
            {
                while (cantidad > existencias_zapatillaA || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 3;
                precio_unitario = valor_zapatillaA;
                existencias_zapatillaA -= cantidad;
                ventas_zapatosyzapatillas += valor_zapatillaA * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 4)
        {
            if (existencias_zapatillaB > 0)
            {
                while (cantidad > existencias_zapatillaB || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                existencias_zapatillaB -= cantidad;
                nombre_producto = 4;
                precio_unitario = valor_zapatillaB;
                ventas_zapatosyzapatillas += valor_zapatillaB * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else
        { // el producto no existe
            printf("Producto no existente.\n");
            system("pause");
            return ventas();
        }
        break;//fin caso 1

    case 2:// Moda Mujer
        printf("_____________________________________________\n");
        printf("*           CATEGORIA: MODA MUJER           *\n");
        printf("_____________________________________________\n");
        printf("1. Pantalon A $%d, stock: %d\n", valor_pantalonA_M, existencias_pantalonA_M);
        printf("2. Pantalon B $%d, stock: %d\n", valor_pantalonB_M, existencias_pantalonB_M);
        printf("3. Polera A $%d, stock: %d\n", valor_poleraA_M, existencias_poleraA_M);
        printf("4. Polera B $%d, stock: %d\n", valor_poleraB_M, existencias_poleraB_M);
        printf("5. Poleron A $%d, stock: %d\n", valor_poleronA_M, existencias_poleronA_M);
        printf("6. Poleron B $%d, stock: %d\n\n", valor_poleronB_M, existencias_poleronB_M);
        printf("7. Volver al Menu de Ventas\n");
        printf("_____________________________________________\n");
        printf(">> Seleccione N* que quiera comprar: ");
        scanf("%d", &producto);
        if (producto == 7)
        {
            return ventas();
        }
        printf(">> Ingrese la cantidad que quiere comprar: ");
        scanf("%d", &cantidad);

        if (producto == 1)
        {
            if (existencias_pantalonA_M > 0)
            {
                while (cantidad > existencias_pantalonA_M || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 5;
                precio_unitario = valor_pantalonA_M;
                existencias_pantalonA_M -= cantidad;
                ventas_modamujer += valor_pantalonA_M * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 2)
        {
            if (existencias_pantalonB_M > 0)
            {
                while (cantidad > existencias_pantalonB_M || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 6;
                precio_unitario = valor_pantalonB_M;
                existencias_pantalonB_M -= cantidad;
                ventas_modamujer += valor_pantalonB_M * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 3)
        {
            if (existencias_poleraA_M > 0)
            {
                while (cantidad > existencias_poleraA_M || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 7;
                precio_unitario = valor_poleraA_M;
                existencias_poleraA_M -= cantidad;
                ventas_modamujer += valor_poleraA_M * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 4)
        {
            if (existencias_poleraB_M > 0)
            {
                while (cantidad > existencias_poleraB_M || cantidad <= 0)
                {

                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 8;
                precio_unitario = valor_poleraB_M;
                existencias_poleraB_M -= cantidad;
                ventas_modamujer += valor_poleraB_M * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 5)
        {
            if (existencias_poleronA_M > 0)
            {
                while (cantidad > existencias_poleronA_M || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 9;
                precio_unitario = valor_poleronA_M;
                existencias_poleronA_M -= cantidad;
                ventas_modamujer += valor_poleronA_M * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 6)
        {
            if (existencias_poleronB_M > 0)
            {
                while (cantidad > existencias_poleronB_M || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 10;
                precio_unitario = valor_poleronB_M;
                existencias_poleronB_M -= cantidad;
                ventas_modamujer += valor_poleronB_M * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else
        { // el producto no existe
            printf("Producto no existente.\n");
            system("pause");
            return ventas();
        }
        break;//Fin caso 2

    case 3:// Moda Hombre
        printf("_____________________________________________\n");
        printf("*          CATEGORIA:  MODA HOMBRE          *\n");
        printf("_____________________________________________\n");
        printf("1. Pantalon A $%d, stock: %d\n", valor_pantalonA_H, existencias_pantalonA_H);
        printf("2. Pantalon B $%d, stock: %d\n", valor_pantalonB_H, existencias_pantalonB_H);
        printf("3. Polera A $%d, stock: %d\n", valor_poleraA_H, existencias_poleraA_H);
        printf("4. Polera B $%d, stock: %d\n", valor_poleraB_H, existencias_poleraB_H);
        printf("5. Poleron A $%d, stock: %d\n", valor_poleronA_H, existencias_poleronA_H);
        printf("6. Poleron B $%d, stock: %d\n\n", valor_poleronB_H, existencias_poleronB_H);
        printf("7. Volver al menu de Ventas\n");
        printf("_____________________________________________\n");
        printf(">> Seleccione N* que quiera comprar:\n ");
        scanf("%d", &producto);
        if (producto == 7)
        {
            return ventas();
        }
        printf(">> Ingrese la cantidad que quiere comprar:\n ");
        scanf("%d", &cantidad);

        if (producto == 1)
        {
            if (existencias_pantalonA_H > 0)
            {
                while (cantidad > existencias_pantalonA_H || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 11;
                precio_unitario = valor_pantalonA_H;
                existencias_pantalonA_H -= cantidad;
                ventas_modahombre += valor_pantalonA_H * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 2)
        {
            if (existencias_pantalonB_H > 0)
            {
                while (cantidad > existencias_pantalonB_H || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 12;
                precio_unitario = valor_pantalonB_H;
                existencias_pantalonB_H -= cantidad;
                ventas_modahombre += valor_pantalonB_H * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 3)
        {
            if (existencias_poleraA_H > 0)
            {
                while (cantidad > existencias_poleraA_H || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 13;
                precio_unitario = valor_poleraA_H;
                existencias_poleraA_H -= cantidad;
                ventas_modahombre += valor_poleraA_H * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 4)
        {
            if (existencias_poleraB_H > 0)
            {
                while (cantidad > existencias_poleraB_H || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 14;
                precio_unitario = valor_poleraB_H;
                existencias_poleraB_H -= cantidad;
                ventas_modahombre += valor_poleraB_H * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 5)
        {
            if (existencias_poleronA_H > 0)
            {
                while (cantidad > existencias_poleronA_H || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 15;
                precio_unitario = valor_poleronA_H;
                existencias_poleronA_H -= cantidad;
                ventas_modahombre += valor_poleronA_H * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 6)
        {
            if (existencias_poleronB_H > 0)
            {
                while (cantidad > existencias_poleronB_H || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 16;
                precio_unitario = valor_poleronB_H;
                existencias_poleronB_H -= cantidad;
                ventas_modahombre += valor_poleronB_H * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else
        { // el producto no existe
            printf("Producto no existente.\n");
            system("pause");
            return ventas();
        }
        break;//fin caso 3

    case 4:// Linea Blanca y Electronica
        printf("_____________________________________________\n");
        printf("*   CATEGORIA: LINEA BLANCA Y ELECTRONICA   *\n");
        printf("_____________________________________________\n");
        printf("1. Aspiradora $%d, stock: %d\n", valor_aspiradora, existencias_aspiradora);
        printf("2. Microondas $%d, stock: %d\n", valor_microondas, existencias_microondas);
        printf("3. Cocina $%d, stock: %d\n", valor_cocina, existencias_cocina);
        printf("4. Lavadora $%d, stock: %d\n", valor_lavadora, existencias_lavadora);
        printf("5. Referigerador $%d, stock: %d\n\n", valor_referigerador, existencias_referigerador);
        printf("6. Volver al menu de Ventas\n");
        printf("_____________________________________________\n");
        printf(">> Seleccione N* que quiera comprar:\n ");
        scanf("%d", &producto);
        if (producto == 6)
        {
            return ventas();
        }
        printf(">> Ingrese la cantidad que quiere comprar:\n ");
        scanf("%d", &cantidad);

        if (producto == 1)
        {
            if (existencias_aspiradora > 0)
            {
                while (cantidad > existencias_aspiradora || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 17;
                precio_unitario = valor_aspiradora;
                existencias_aspiradora -= cantidad;
                ventas_lineablanca += valor_aspiradora * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 2)
        {
            if (existencias_microondas > 0)
            {
                while (cantidad > existencias_microondas || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 18;
                precio_unitario = valor_microondas;
                existencias_microondas -= cantidad;
                ventas_lineablanca += valor_microondas * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 3)
        {
            if (existencias_cocina > 0)
            {
                while (cantidad > existencias_cocina || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 19;
                precio_unitario = valor_cocina;
                existencias_cocina -= cantidad;
                ventas_lineablanca += valor_cocina * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 4)
        {
            if (existencias_lavadora > 0)
            {
                while (cantidad > existencias_lavadora || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 20;
                precio_unitario = valor_lavadora;
                existencias_lavadora -= cantidad;
                ventas_lineablanca += valor_lavadora * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 5)
        {
            if (existencias_referigerador > 0)
            {
                while (cantidad > existencias_referigerador || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 21;
                precio_unitario = valor_referigerador;
                existencias_referigerador -= cantidad;
                ventas_lineablanca += valor_referigerador * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else
        { // el producto no existe
            printf("Producto no existente.\n");
            system("pause");
            return ventas();
        }
        break;//fin caso 4

    case 5:// Computacion
        printf("_____________________________________________\n");
        printf("*          CATEGORIA:  COMPUTACION          *\n");
        printf("_____________________________________________\n");
        printf("1. Pc escritorio $%d, stock: %d\n", valor_pcescritorio, existencias_pcescritorio);
        printf("2. Pc gamer $%d, stock: %d\n", valor_pcgamer, existencias_pcgamer);
        printf("3. Notebook $%d, stock: %d\n", valor_notebook, existencias_notebook);
        printf("4. Notebook gamer $%d, stock: %d\n\n", valor_notebookgamer, existencias_notebookgamer);
        printf("5. Volver al menu de Ventas\n");
        printf("_____________________________________________\n");
        printf(">> Seleccione N* que quiera comprar:\n ");
        scanf("%d", &producto);
        if (producto == 5)
        {
            return ventas();
        }
        printf(">> Ingrese la cantidad que quiere comprar:\n ");
        scanf("%d", &cantidad);

        if (producto == 1)
        {
            if (existencias_pcescritorio > 0)
            {
                while (cantidad > existencias_pcescritorio || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 22;
                precio_unitario = valor_pcescritorio;
                existencias_pcescritorio -= cantidad;
                ventas_computacion = valor_pcescritorio * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 2)
        {
            if (existencias_pcgamer > 0)
            {
                while (cantidad > existencias_pcgamer || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 23;
                precio_unitario = valor_pcgamer;
                existencias_pcgamer -= cantidad;
                ventas_computacion += valor_pcgamer * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 3)
        {
            if (existencias_notebook > 0)
            {
                while (cantidad > existencias_notebook || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 24;
                precio_unitario = valor_notebook;
                existencias_notebook -= cantidad;
                ventas_computacion += valor_notebook * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else if (producto == 4)
        {
            if (existencias_notebookgamer > 0)
            {
                while (cantidad > existencias_notebookgamer || cantidad <= 0)
                {
                    printf(">> Cantidad no Valida, ingrese denuevo:\n");
                    scanf("%d", &cantidad);
                }
                nombre_producto = 25;
                precio_unitario = valor_notebookgamer;
                existencias_notebookgamer -= cantidad;
                ventas_computacion += valor_notebookgamer * cantidad;
            }
            else
            {
                printf("No hay stock disponible\n");
                system("pause");
                return ventas();
            }
        }
        else
        { // el producto no existe
            printf("Producto no existente.\n");
            system("pause");
            return ventas();
        }
        break;//fin caso 5

    case 6: // opcion volver al menu principal
        return main();
        break;

    default: // opcion no valida
        return ventas();
        break;
    }
    return boleta();
}
int existencias(){
    existencias_zapatosyzapatillas = existencias_zapatoA + existencias_zapatillaA + existencias_zapatoB + existencias_zapatillaB;
    existencias_modamujer = existencias_pantalonA_M + existencias_pantalonB_M + existencias_poleraA_M + existencias_poleraB_M + existencias_poleronA_M + existencias_poleronB_M;
    existencias_modahombre = existencias_pantalonA_H + existencias_pantalonB_H + existencias_poleraA_H + existencias_poleraB_H + existencias_poleronA_H + existencias_poleronB_H;
    existencias_lineablanca = existencias_aspiradora + existencias_microondas + existencias_cocina + existencias_lavadora + existencias_referigerador;
    existencias_computacion = existencias_pcescritorio + existencias_pcgamer + existencias_notebook + existencias_notebookgamer;
    existencias_totales = existencias_zapatosyzapatillas + existencias_modamujer + existencias_modahombre + existencias_lineablanca + existencias_computacion;
    system("cls");
    printf("_____________________________________________\n");
    printf("*            MODO: EXISTENCIAS              *\n");
    printf("___________________Menu:_____________________\n");
    printf("1. Zapatos y Zapatillas : %19d\n", existencias_zapatosyzapatillas);
    printf("2. Moda Mujer : %29d\n", existencias_modamujer);
    printf("3. Moda Hombre : %28d\n", existencias_modahombre);
    printf("4. Linea Blanca y Electronica : %13d\n", existencias_lineablanca);
    printf("5. Computacion : %28d\n\n", existencias_computacion);
    printf("6. Volver al menu principal\n");
    printf("_____________________________________________\n");
    printf("** Exitencias Totales : %21d\n", existencias_totales);
    printf("_____________________________________________\n");
    printf(">> Seleccione N* categoria para detalles: ");
    scanf("%d", &categoria);

    system("cls");
    switch (categoria)
    {
    case 1:
        printf("_____________________________________________\n");
        printf("*      CATEGORIA: ZAPATOS Y ZAPATILLAS      *\n");
        printf("_____________________________________________\n");
        printf("1. Zapato A, stock: %d\n", existencias_zapatoA);
        printf("2. Zapato B, stock: %d\n", existencias_zapatoB);
        printf("3. Zapatilla A, stock: %d\n", existencias_zapatillaA);
        printf("4. Zapatilla B, stock: %d\n", existencias_zapatillaB);
        printf("_____________________________________________\n>> ");
        break;
    case 2:
        printf("_____________________________________________\n");
        printf("*           CATEGORIA: MODA MUJER           *\n");
        printf("_____________________________________________\n");
        printf("1. Pantalon A, stock: %d\n", existencias_pantalonB_M);
        printf("2. Pantalon B, stock: %d\n", existencias_pantalonB_M);
        printf("3. Polera A, stock: %d\n", existencias_poleraA_M);
        printf("4. Polera B, stock: %d\n", existencias_poleraB_M);
        printf("5. Poleron A, stock: %d\n", existencias_poleronA_M);
        printf("6. Poleron B, stock: %d\n", existencias_poleronB_M);
        printf("_____________________________________________\n>> ");
        break;
    case 3:
        printf("_____________________________________________\n");
        printf("*          CATEGORIA:  MODA HOMBRE          *\n");
        printf("_____________________________________________\n");
        printf("1. Pantalon A, stock: %d\n", existencias_pantalonA_H);
        printf("2. Pantalon B, stock: %d\n", existencias_pantalonB_H);
        printf("3. Polera A, stock: %d\n", existencias_poleraA_H);
        printf("4. Polera B, stock: %d\n", existencias_poleraB_H);
        printf("5. Poleron A, stock: %d\n", existencias_poleronA_H);
        printf("6. Poleron B, stock: %d\n", existencias_poleronB_H);
        printf("_____________________________________________\n>> ");
        break;
    case 4:
        printf("_____________________________________________\n");
        printf("*   CATEGORIA: LINEA BLANCA Y ELECTRONICA   *\n");
        printf("_____________________________________________\n");
        printf("1. Aspiradora, stock: %d\n", existencias_aspiradora);
        printf("2. Microondas, stock: %d\n", existencias_microondas);
        printf("3. Cocina, stock: %d\n", existencias_cocina);
        printf("4. Lavadora, stock: %d\n", existencias_lavadora);
        printf("5. Refrigerador, stock: %d\n", existencias_referigerador);
        printf("_____________________________________________\n>> ");
        break;
    case 5:
        printf("_____________________________________________\n");
        printf("*          CATEGORIA:  COMPUTACION          *\n");
        printf("_____________________________________________\n");
        printf("1. PC Escritorio, stock: %d\n", existencias_pcescritorio);
        printf("2. PC Gamer, stock: %d\n", existencias_pcgamer);
        printf("3. Notebook, stock: %d\n", existencias_notebook);
        printf("4. Notebook Gamer, stock: %d\n", existencias_notebookgamer);
        printf("_____________________________________________\n>> ");
        break;
    case 6: // Volver al menu principal
        return main();
        break;
    default:
        return existencias();
        break;
    }
    system("pause");
    return existencias();
}
int totalventas(){
    ventas_totales = ventas_zapatosyzapatillas + ventas_modamujer + ventas_modahombre + ventas_lineablanca + ventas_computacion;
    system("cls");
    printf("_____________________________________________\n");
    printf("**            MODO: TOTAL VENTAS           **\n");
    printf("___________________Menu:_____________________\n");
    printf("** Ventas Totales: $%.0f\n", ventas_totales);
    printf("** Meta de Ventas: $%.0f\n", ventas_maximas_totales);
    printf("** Ventas Restantes: $%.0f\n", ventas_maximas_totales - ventas_totales);
    printf("_____________________________________________\n");
    printf("1. Zapatos y Zapatillas \n");
    printf("2. Moda Mujer \n");
    printf("3. Moda Hombre \n");
    printf("4. Linea Blanca y Electronica \n");
    printf("5. Computacion\n\n");
    printf("6. Volver al Menu Principal\n");
    printf("_____________________________________________\n");
    printf(">> Ingrese el N* de categoria para detalles: ");
    scanf("%d", &categoria);
    system("cls");
    switch (categoria)
    {
    case 1:
        printf("_____________________________________________\n");
        printf("*      CATEGORIA: ZAPATOS Y ZAPATILLAS      *\n");
        printf("_____________________________________________\n");
        printf("** Ventas Totales: $%.0f\n", ventas_zapatosyzapatillas);
        printf("** Meta De Ventas: $%.0f\n", ventas_maximas_zapatosyzapatillas);
        printf("** Ventas Restantes: $%.0f\n", ventas_maximas_zapatosyzapatillas - ventas_zapatosyzapatillas);
        printf("_____________________________________________\n>> ");
        break;
    case 2:
        printf("_____________________________________________\n");
        printf("*           CATEGORIA: MODA MUJER           *\n");
        printf("_____________________________________________\n");
        printf("** Ventas Totales: $%.0f\n", ventas_modamujer);
        printf("** Meta De Ventas: $%.0f\n", ventas_maximas_modamujer);
        printf("** Ventas Restantes: $%.0f\n", ventas_maximas_modamujer - ventas_modamujer);
        printf("_____________________________________________\n>> ");
        break;
    case 3:
        printf("_____________________________________________\n");
        printf("*          CATEGORIA:  MODA HOMBRE          *\n");
        printf("_____________________________________________\n");
        printf("** Ventas Totales: $%.0f\n", ventas_modahombre);
        printf("** Meta De Ventas: $%.0f\n", ventas_maximas_modahombre);
        printf("** Ventas Restantes: $%.0f\n", ventas_maximas_modahombre - ventas_modahombre);
        printf("_____________________________________________\n>> ");
        break;
    case 4:
        printf("_____________________________________________\n");
        printf("*   CATEGORIA: LINEA BLANCA Y ELECTRONICA   *\n");
        printf("_____________________________________________\n");
        printf("** Ventas Totales: $%.0f\n", ventas_lineablanca);
        printf("** Meta De Ventas: $%.0f\n", ventas_maximas_lineablanca);
        printf("** Ventas Restantes: $%.0f\n", ventas_maximas_lineablanca - ventas_lineablanca);
        printf("_____________________________________________\n>> ");
        break;
    case 5:
        printf("_____________________________________________\n");
        printf("*          CATEGORIA:  COMPUTACION          *\n");
        printf("_____________________________________________\n");
        printf("** Ventas Totales: $%.0f\n", ventas_computacion);
        printf("** Meta De Ventas: $%.0f\n", ventas_maximas_computacion);
        printf("** Ventas Restantes: $%.0f\n", ventas_maximas_computacion - ventas_computacion);
        printf("_____________________________________________\n>> ");
        break;
    case 6:
        return main();
        break;
    default:
        return totalventas();
        break;
    }
    system("pause");
    return totalventas();
}
int boleta(){
    numero_boleta++;
    precio_iva_unitario = precio_unitario * iva;
    precio_neto_unitario = precio_unitario - precio_iva_unitario;
    neto_total = precio_neto_unitario * cantidad;
    iva_total = precio_iva_unitario * cantidad;
    total_boleta = precio_unitario * cantidad;
    system("cls");
    printf("_____________________________________________\n");
    printf(" **           BOLETA  ELECTRONICA         ** \n");
    printf("               Numero Boleta: %d             \n", numero_boleta);
    printf("_____________________________________________\n");
    printf(" Razon social:         Megaretail y Cia S.A. \n");
    printf(" RUT:                           99.999.999-9 \n");
    printf(" Giro:                       Grandes tiendas \n");
    printf(" Direccion:    Avenida Fake 1202, concepcion \n");
    printf(" Telefono:                       41 222 3333 \n");
    printf(" Email:           contacto@megaretailycia.cl \n");
    printf("_____________________________________________\n");
    switch (nombre_producto)
    {
    case 1:
        printf(" Producto:                  Zapato A\n");
        break;
    case 2: 
        printf(" Producto:                  Zapato B\n");
        break;
    case 3: 
        printf(" Producto:                  Zapatilla A\n");
        break;
    case 4: 
        printf(" Producto:                  Zapatilla B\n");
        break;
    case 5: 
        printf(" Producto:                  Pantalon A\n");
        break;
    case 6: 
        printf(" Producto:                  Pantalon B\n");
        break;
    case 7: 
        printf(" Producto:                  Polera A\n");
        break;
    case 8: 
        printf(" Producto:                  Polera B\n");
        break;
    case 9: 
        printf(" Producto:                  Poleron A\n");
        break;
    case 10: 
        printf(" Producto:                  Poleron B\n");
        break;
    case 11: 
        printf(" Producto:                  Pantalon A\n");
        break;
    case 12: 
        printf(" Producto:                  Pantalon B\n");
        break;
    case 13: 
        printf(" Producto:                  Polera A\n");
        break;
    case 14: 
        printf(" Producto:                  Polera B\n");
        break;
    case 15: 
        printf(" Producto:                  Poleron A\n");
        break;
    case 16: 
        printf(" Producto:                  Poleron B\n");
        break;
    case 17: 
        printf(" Producto:                  Aspiradora\n");
        break;
    case 18: 
        printf(" Producto:                  Microondas\n");
        break;
    case 19: 
        printf(" Producto:                  Cocina\n");
        break;
    case 20: 
        printf(" Producto:                  Lavadora\n");
        break;
    case 21: 
        printf(" Producto:                  Refrigerador\n");
        break;
    case 22: 
        printf(" Producto:                  PC de escritorio\n");
        break;
    case 23: 
        printf(" Producto:                  PC gamer\n");
        break;
    case 24: 
        printf(" Producto:                  Notebook\n");
        break;
    case 25:
        printf(" Producto:                  Notebook gamer\n");
        break;
    }   
    printf(" Cantidad%-19c%d und.\n", 58, cantidad);
    printf(" Precio und%-17c$%.0f\n", 58, precio_unitario);
    printf(" Precio Neto%-16c$%.0f\n", 58, neto_total);
    printf(" Iva (19%%)%-18c$%.0f\n", 58, iva_total);
    printf("_____________________________________________\n");
    printf(" Total%-22c$%.0f\n", 58, total_boleta);
    printf(" (%d und.)\n", cantidad);
    printf("_____________________________________________\n>> ");
    system("pause");
    return ventas();
}
int salir(){
    system("cls");
    printf("_____________________________________________\n");
    printf("** GRACIAS POR PREFERIRNOS,  VUELVA PRONTO **\n");
    printf("_____________________________________________\n");
    printf("                  AUTORES:                   \n");
    printf("          ** Renato Acosta Ormeno **         \n");
    printf("           ** Benjamin Jara Soto **          \n");
    printf("_____________________________________________\n>> ");
    system("pause");
    return 0;
}
// Muchas gracias :), Wena.