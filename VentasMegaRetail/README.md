# VentasMegaretail
ESTA ES LA VERSION FINALIZADA DE NUESTRA TAREA: 

Comenzamos nuestro programa con el menú de bienvenida donde se muestran 4 opciones (procesar ventas o comprar
, manejo de existencias, manejo de ventas o ganacias y finalmente la opción de salir). Dependiendo de que número
 de  Modo seleccione el usuario, se limpiará la pantalla y se abrirá dicho modo.

Cada modo se subdivide en categorías (en las que se encuentran los productos en si), y también en algunos modos
 como el modo 2 y el modo 3, ("Cantidad de existencias y Monto total de ventas), se pueden apreciar datos 
generales del modo en si, como la cantidad de productos globales de todas las categorías o las ventas globales 
de todas las categorías.

Finalmente, en cada categoría se encuentran los productos u otras sub-categorías según el modo en el que se 
encuentre. Por ejemplo en el modo de "Cantidad de existencias", al seleccionar una categoría se mostrarán las
existencias por producto de esa categoría, por otro lado en el modo "Monto total de ventas", al seleccionar una
categoría se mostrarán las ventas que lleve esa categoría, cual es la meta de ventas de esa categoría y cuanto
falta para llegar a la meta.

EXPLICACION DEL PUNTERO UTILIZADO Y TAMBIEN LAS FUNCIONES A PARTE DE "main()":

Profesor, nuestra estructura de código puede que sea distinta al de la mayoría de nuestros compañeros puesto que 
utilizamos múltiples funciones en vez de usar solamente main(), esto nos fué enseñado por uno de nuestros compañeros
quien sabe programar desde antes, y nosotros decidimos usarlo ya que nos pareció la forma más práctica y estructurada
de escribir nuestro código sin usar un ciclo while desde el principio.

Ahora, con respecto al uso de "char* nombre_producto", esto fué pues teníamos la intención de declarar una variable tipo
char la cual iba a almacenar el nombre del producto seleccionado por el usuario para luego ser impreso en la boleta y que
esta variable se sobreescribiera cuando el usuario selecionara otro producto, pero el sobreescribir la variable de esta forma
no nos era posible, (no sabíamos como hacerlo funcionar), por lo que finalmente buscando el google dimos con una solución,
por lo que declarar la variable con un puntero que almacenara el string para luego poder ser sobreescrito fué la alternativa
que elegimos pese a que aún no nos hayan pasado esa materia. 

COMO TRABAJAMOS NUESTRO CÓDIGO:

El codigo lo hicimos con la extención de Visual Studio Code "live share" la cual da la funcion de que 2 o mas personas editen 
un codigo al mismo tiempo, ya que se nos hacia mucho mas sencillo hacerlo con esta extención que con Github. Pero sin embargo 
el repositorio igual fué subido a Github a modo de copia de seguridad.

GRACIAS POR SU TIEMPO Y ATENCIÓN.
