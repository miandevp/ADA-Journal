## Ejercicio 1

En el algoritmo original de Counting Sort, el arreglo auxiliar `C` se transforma en un arreglo acumulativo donde `C[i]` representa la cantidad de elementos menores o iguales a `i`. Esto permite obtener el ordenamiento en forma no decreciente.

Para modificar el algoritmo y obtener un ordenamiento en forma decreciente, se cambió la construcción del acumulado. En lugar de acumular de izquierda a derecha mediante:

`C[i] = C[i] + C[i-1]`

se acumula de derecha a izquierda utilizando:

`C[i] = C[i] + C[i+1]`.

De esta manera, `C[i]` pasa a representar la cantidad de elementos mayores o iguales a `i`, lo que permite ubicar primero los valores más grandes en el arreglo de salida.

Además, para mantener la estabilidad del algoritmo, se conservó el recorrido del arreglo original desde la última posición hacia la primera. Gracias a este recorrido, los elementos con claves iguales preservan el mismo orden relativo que tenían en la entrada.

Por lo tanto, el Counting Sort modificado continúa siendo estable, pero ahora produce el arreglo ordenado en forma decreciente.


## Ejercicio 2

Para resolver este problema, primero observamos que la cantidad de elementos a ordenar es

$$
N = n^2+n = \Theta(n^2).
$$

Si se aplicara Counting Sort directamente, su complejidad sería

$$
O(N+k),
$$

donde (k) corresponde al rango de los valores. En este caso,

$$
k=n^7,
$$

por lo que el costo sería

$$
O(n^2+n+n^7)=O(n^7),
$$

lo cual no satisface la complejidad requerida de (O(n^2)).

Por ello, se utiliza **Radix Sort** empleando **Counting Sort estable** como subrutina. Los números pertenecen al rango

$$
0 \leq x < n^7.
$$

Representando cada número en base (n), cualquier valor puede escribirse como

$$
x=d_6n^6+d_5n^5+d_4n^4+d_3n^3+d_2n^2+d_1n+d_0,
$$

donde cada dígito cumple

$$
0 \leq d_i < n.
$$

Por lo tanto, cada número requiere a lo sumo (7) dígitos en base (n).

En cada pasada de Radix Sort se aplica Counting Sort sobre un único dígito. Como el rango de cada dígito es (n), el costo de cada pasada es

$$
O(N+n)=O(n^2+n)=O(n^2).
$$

Además, el número de dígitos es constante,

$$
d=7.
$$

Por consiguiente, la complejidad total es

$$
O(d(N+n))
=

 O(7(n^2+n))

O(n^2).
$$

En conclusión, utilizando Radix Sort en base (n) se obtiene un algoritmo que ordena el arreglo en forma no decreciente y cumple con la complejidad requerida de

$$
O(n^2).
$$


## Ejericcio 3

Para este problema se tienen (n) enteros en el rango

$$
-1 \leq x \leq 4n^2+4n-1,
$$

y se requiere obtener el arreglo ordenado con complejidad (O(n)).

Si se aplicara Counting Sort directamente, el costo sería

$$
O(N+k),
$$

donde

$$
N=n
$$

y el tamaño del rango sería

$$
k=(4n^2+4n-1)-(-1)+1
=4n^2+4n+1
=(2n+1)^2.
$$

Por lo tanto, la complejidad obtenida sería

$$
O(n+(2n+1)^2)=O(n^2),
$$

lo cual no cumple con la restricción del problema.

Para solucionar esto, se utiliza **Radix Sort** con **Counting Sort estable** como subrutina. Primero, se desplazan todos los elementos sumando (1) a cada uno, transformando el rango en

$$
0 \leq x \leq 4n^2+4n.
$$

Observamos que

$$
4n^2+4n < (2n+1)^2.
$$

Por ello, se elige una base

$$
b=2n+1.
$$

En esta base, cualquier número del rango puede representarse utilizando a lo sumo dos dígitos:

$$
x=d_1(2n+1)+d_0,
$$

donde

$$
0 \leq d_0,d_1 < 2n+1.
$$

Cada pasada de Counting Sort trabaja únicamente sobre un dígito, cuyo rango es

$$
k=2n+1.
$$

Por lo tanto, el costo de cada pasada es

$$
O(N+k)
=

O(n+(2n+1))

O(n).
$$

Como únicamente se requieren

$$
d=2
$$

pasadas, la complejidad total es

$$
O(d(N+k))
=

O(2(n+2n+1))

O(n).
$$

En conclusión, utilizando Radix Sort en base (2n+1) y Counting Sort estable para ordenar cada dígito, se obtiene un algoritmo que retorna el arreglo ordenado cumpliendo la complejidad requerida de

$$
O(n).
$$


## Ejercicio 4
Para analizar cuál base es más eficiente en Radix Sort, utilizamos la complejidad

$$
O(d(N+k)),
$$

donde (N) es la cantidad de elementos a ordenar, (d) es el número de dígitos en la base elegida y (k) es el rango de cada dígito.

Dado que los números pertenecen al rango

$$
0 \leq x \leq n^8-1,
$$

si se utiliza base (n), cada dígito puede tomar valores entre

$$
0,1,\ldots,n-1,
$$

por lo que

$$
k=n.
$$

Además,

$$
n^8=(n)^8,
$$

por lo que cada número requiere a lo sumo

$$
d=8
$$

dígitos. En consecuencia, la complejidad es

$$
O(8(N+n)).
$$

Por otro lado, si se utiliza base (n^2), cada dígito puede tomar valores entre

$$
0,1,\ldots,n^2-1,
$$

de modo que

$$
k=n^2.
$$

Como

$$
n^8=(n^2)^4,
$$

cada número requiere únicamente

$$
d=4
$$

dígitos. Por lo tanto, la complejidad obtenida es

$$
O(4(N+n^2)).
$$

Dado que el enunciado no especifica la cantidad de elementos (N), no es posible determinar una respuesta absoluta basándose únicamente en el término dominante de (N). Sin embargo, al comparar ambas expresiones, se observa que utilizar base (n) mantiene un arreglo auxiliar de tamaño lineal, mientras que emplear base (n^2) incrementa dicho tamaño a un orden cuadrático.

Por esta razón, y considerando únicamente la información proporcionada por el problema, resulta más conveniente utilizar la **base (n)**, ya que el costo adicional asociado a (k=n) es menor que el correspondiente a (k=n^2). Aunque la base (n^2) reduce el número de pasadas de (8) a (4), el incremento en el costo de cada Counting Sort hace que la base (n) sea la alternativa más eficiente bajo el análisis asintótico disponible.


## Ejercicio 5

Para demostrar que Radix Sort funciona correctamente, utilizamos inducción sobre el número de dígitos procesados.

Sea (d) el número total de dígitos de los elementos a ordenar. Consideremos la siguiente hipótesis de inducción:

> Después de procesar los primeros (i) dígitos menos significativos, el arreglo queda ordenado con respecto a esos (i) dígitos.

### Caso base

Para (i=1), se aplica el algoritmo de ordenamiento estable sobre el dígito menos significativo. Como dicho algoritmo ordena correctamente los elementos según este dígito, el arreglo queda ordenado respecto al último dígito. Por lo tanto, la hipótesis es verdadera para (i=1).

### Paso inductivo

Supongamos que, después de procesar (i) dígitos, el arreglo está ordenado con respecto a los (i) dígitos menos significativos.

En la iteración siguiente, se ordena el arreglo utilizando el dígito (i+1). Los elementos con distinto valor en este dígito quedan ubicados correctamente según dicho valor. Además, los elementos que poseen el mismo valor en el dígito (i+1) conservan el orden relativo que tenían antes de esta iteración debido a que el algoritmo intermedio es estable.

Por la hipótesis inductiva, ese orden relativo ya era correcto respecto a los (i) dígitos menos significativos. En consecuencia, después de esta nueva pasada, el arreglo queda ordenado respecto a los primeros (i+1) dígitos menos significativos.

Por el principio de inducción matemática, luego de procesar los (d) dígitos, el arreglo queda completamente ordenado.

### Uso de la estabilidad

La estabilidad es necesaria en el paso inductivo de la demostración. Cuando dos elementos tienen el mismo valor en el dígito que se está procesando, es indispensable preservar el orden obtenido en iteraciones anteriores. De lo contrario, podría perderse el orden correcto respecto a los dígitos menos significativos y Radix Sort dejaría de garantizar un resultado correcto.


## Ejercicio 6
Dado que se tienen

$$
N=n^2
$$

elementos distribuidos uniformemente en el intervalo ([0,1)) y se utilizan

$$
B=n
$$

buckets de igual longitud, cada elemento tiene probabilidad

$$
\frac{1}{n}
$$

de pertenecer a un bucket determinado. Por lo tanto, el número esperado de elementos en cada bucket es

$$
m=\frac{N}{B}=\frac{n^2}{n}=n.
$$

Una vez distribuidos los elementos, se aplica Insertion Sort en cada bucket. Si un bucket contiene (m) elementos, el costo de Insertion Sort es

$$
O(m^2).
$$

Como el tamaño esperado de cada bucket es

$$
m=n,
$$

el costo esperado de ordenar un bucket es

$$
O(n^2).
$$

Dado que existen

$$
n
$$

buckets, el costo esperado total de ordenar los buckets es

$$
n\cdot O(n^2)=O(n^3).
$$

El proceso de distribuir los (n^2) elementos en los buckets y concatenar posteriormente las listas ordenadas requiere además un tiempo

$$
O(n^2).
$$

Sin embargo,

$$
O(n^3)+O(n^2)=O(n^3).
$$

Por lo tanto, la complejidad esperada de esta variación de Bucket Sort es

$$
\boxed{O(n^3)}.
$$

Es importante notar que, en el Bucket Sort clásico, el comportamiento lineal se obtiene porque el tamaño esperado de cada bucket es constante. En este ejercicio, aunque los elementos están uniformemente distribuidos, cada bucket recibe en promedio (n) elementos; debido al costo cuadrático de Insertion Sort, la complejidad esperada aumenta a (O(n^3)).
