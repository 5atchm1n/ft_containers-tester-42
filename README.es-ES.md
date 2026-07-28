# 42 FT_CONTAINERS TESTER
<sub> Inspirado en [monkey_tester](https://github.com/jgiron42/ft_containers_monkey_tester) de [@jgiron42](https://github.com/jgiron42)</sub>


## Una prueba unitaria básica para el proyecto 42 containers
#### PASO - 1
¡Lee el README!   
¡Compila usando clang++!  
Modifica la variable ```$INC``` en el [Makefile](https://github.com/5atchm1n/ft_containers-tester-42/blob/master/Makefile) para que apunte a tus containers.  

NOTA - Modifica el `#include "pair.hpp"` en [srcs/_test_header.hpp](https://github.com/5atchm1n/ft_containers-tester-42/blob/master/srcs/_test_header.hpp) para que apunte a tu archivo ft::pair si deseas probar el map.


### BÁSICO
¡Solo para comenzar! Lee las secciones [PRUEBAS INDIVIDUALES](#COMPILING-INDIVIDUAL-TESTS-FOR-DEBUGGING) y [MODIFICAR PRUEBAS](#MODIFYING-THE-TESTS) para obtener detalles sobre cómo depurar errores o ejecutar pruebas individuales.

```make test_[container] ``` para probar contra std ( *ej:* `make test_vector` )

```make test_all ``` para ejecutar todas las pruebas a la vez.

NOTA - *Se proporciona una lista completa de los [comandos](#COMMANDS) más abajo*  
NOTA - *Todas las variables de prueba se pueden cambiar en el archivo [srcs/_test_header.hpp](https://github.com/5atchm1n/ft_containers-tester-42/blob/master/srcs/_test_header.hpp)*  
NOTA - *Las pruebas se pueden ejecutar con o sin ciertas opciones. ej: -fsanitize=address puede eliminarse. Por favor, revisa las [variables del makefile](#VARIABLES) para más detalles.*  
## Intro
Cada container puede ser probado por separado. Las pruebas están divididas en sus respectivos directorios:
<ul>
<li> vector_test
<li> map_test
<li> stack_test
<li> set_test
</ul>

Cada prueba se ejecuta NTEST veces e intenta modificar el container hasta un máximo de MAX_TEST_SIZE. Las pruebas se ejecutan aleatoriamente usando una SEED única y esto ocurre MAX_SEED_SIZE veces para asegurar múltiples pruebas aleatorias que puedan ejecutarse idénticamente con la librería std.  
<sub>NOTA - *Todas las variables de prueba se pueden cambiar en el archivo [srcs/_test_header.hpp](https://github.com/5atchm1n/ft_containers-tester-42/blob/master/srcs/_test_header.hpp)*</sub>

[Probar todos los containers juntos](#FULL-TESTS-SINGLE-BINARY)  
[Probar todos los containers por separado](#FULL-TEST-SEPERATE-BINARIES)  
### COMPILING INDIVIDUAL TESTS FOR DEBUGGING  
<sub> <b>AVISO - por ahora debes ejecutar make clean entre comandos </b> </sub>  
<sub>*Se proporciona una [lista completa](#COMMANDS) de las reglas más abajo*</sub>  
<sub> Por favor, revisa las [variables del makefile](#VARIABLES) </sub>

cada container puede ser compilado y probado usando la siguiente sintaxis:

```make [name]_[container]```  

por lo tanto, para probar ft vector ejecutarías:  

```make ft_vector``` y esto generaría el binario **ft_vector**.  

```make std_vector``` generaría entonces el binario **std_vector**.  

la salida de cada container puede ser probada contra la librería std usando la siguiente sintaxis:  

```make test_[container]```  

para probar vector: ```make test_vector```
## MODIFYING THE TESTS

Las pruebas pueden ejecutarse con o sin ciertas flags de compilación. La prueba const también puede eliminarse. Por favor, revisa las [variables del makefile](#VARIABLES) para más detalles.  
Cada prueba se ejecuta MAX_SEED veces diferentes - la SEED base es 42.
Cada prueba se almacena en un arreglo de punteros a funciones - y se llama aleatoriamente.
Las pruebas están envueltas en un switch case - el archivo de cabecera en cada carpeta de prueba contiene las variables necesarias para modificar la prueba. Para eliminar una prueba de la unidad, comenta el case en el archivo correspondiente y genera el binario deseado nuevamente.  

ejemplo para vector:

![scrnsht2](https://user-images.githubusercontent.com/61289826/158005653-54339d4f-d99d-497d-b0a6-cec9c4b7c27d.png)  
Siéntete libre de añadir y eliminar pruebas para adaptarlas a tus necesidades de compilación.
#### FULL TESTS - SINGLE BINARY

Los comandos básicos de make ```all``` y ```bonus``` compilarán las pruebas obligatorias y bonus respectivamente.  
Para ejecutar las pruebas de diferencia (std vs ft) ejecuta ```make test``` y, para probar la salida de los bonus, ejecuta ```make test_bonus```. Estos ejecutarán pruebas en todos los containers simultáneamente. Por favor, lee las secciones de abajo para compilar pruebas individuales.

#### FULL TESTS - SEPERATE BINARIES

Para ejecutar pruebas de diferencia en todos los binarios por separado, ejecuta ```make test_all``` y ```make test_all_bonus```; esto ejecutará todas las pruebas individualmente y te permitirá ejecutar los comandos de tiempo para verificar el tiempo de ejecución.  
Si alguna de las pruebas falla, Make lanzará un error y se detendrá.  
Los logs se envían al directorio log y todas las pruebas se ejecutan con -fsanitize=address y -fstandalone-debug  
<sub>*esto se puede cambiar, por favor lee la sección NOTES*</sub>
## COMMANDS
#### FULL PROJECT TESTING  
```make```              genera binarios ft y std (obligatorio)  
```make bonus```        genera binarios ft y std (obligatorio + bonus)  
```make test```         ejecuta prueba std vs ft  
```make test_bonus```   ejecuta prueba std vs ft (obligatorio + bonus)  
```make test_all```      ejecuta las pruebas de cada container individualmente  
```make test_all_bonus``` ejecuta las pruebas de cada container individualmente

![containers_tester](https://user-images.githubusercontent.com/61289826/158044256-5ee131c2-3317-4d57-8826-dbe8e8283ed7.png)  
#### TIME
```make time```  después de ```make test_all```  
```make time_bonus```  después de ```make test_all_bonus```
### INDIVIDUAL CONTAINERS TESTS
#### VECTOR
```make ft_vector``` para crear el ejecutable ft::vector  
```make std_vector```   para crear el ejecutable std::vector  
```make test_vector```  ejecuta la prueba de vector y guarda la salida en /log  
#### MAP
```make ft_map```		crea el ejecutable ft::map  
```make std_map```		crea el ejecutable std::map  
```make test_map```		ejecuta la prueba de map y guarda la salida en /log  
#### STACK
```make ft_stack```		crea el ejecutable ft::stack  
```make std_stack```	crea el ejecutable std::stack  
```make test_stack```	ejecuta la prueba de stack y guarda la salida en /log  
#### SET
```make ft_set```		crea el ejecutable ft::set  
```make std_set```		crea el ejecutable std::set  
```make test_set```		ejecuta la prueba de set y guarda la salida en /log  
#### Clean
```make clean```		limpia objs  
```make tclean```       limpia archivos de prueba  
```make lclean```       limpia archivos de log  
```make fclean```       limpia todo  
#### VARIABLES
puedes habilitar y deshabilitar ciertas pruebas en tiempo de compilación ejecutando el comando make utilizando ciertas variables.
<ul>
<li> <b>TMEM</b> - elimina -fsanitize=address </li>
<li> <b>TDEBUG</b> - elimina -fstandalone-debug </li>
<li> <b>TCONST</b> - elimina pruebas únicamente de const </li>
<li> <b>TALLOC</b> - establecer en 1 para añadir pruebas del allocator </li>
<li> <b>LOG</b> - envía la diferencia a stdout y a un archivo (sin logs separados)</li>
</ul>
estas variables pueden usarse juntas ej:

```make <rule_name> TMEM=0 TCONST=0 TALLOC=1```

#### NOTE - a los editores
¡Crea una rama y un pull request para fusionar en master!
