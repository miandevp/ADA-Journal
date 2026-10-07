# EJERCICIOS

### Numero1:

Supongamos que realizamos una secuencia de operaciones (PUSH y POP)
sobre una pila cuyo tama˜no nunca excede k. Despu´es de cada k operaciones, hacemos una
copia completa de la pila con fines de respaldo. Demuestre que el costo de n operaciones de
pila, incluyendo las copias de respaldo, es O(n), asignando costos amortizados adecuados a
las distintas operaciones de la pila


# Ejercicio 1

Sea (n) el número total de operaciones (`PUSH` y `POP`) y sea (k) el tamaño máximo que puede tener la pila.

Al inicio puede parecer que debemos analizar cómo se llena la pila, pero en realidad lo importante es separar dos tipos de costos.

## 1. Costo de las operaciones normales

Cada `PUSH` o `POP` cuesta una unidad.

Como se realizan (n) operaciones en total, el costo de todas las operaciones normales es:

$$
1 + 1 + \cdots + 1 = n.
$$

No importa si primero se hicieron (k) `PUSH`, luego `POP`, o cualquier otra combinación; mientras haya (n) operaciones, su costo total es:

$$
n.
$$

## 2. Costo de los respaldos (backups)

Después de cada (k) operaciones se realiza una copia completa de la pila.

Una copia cuesta como máximo (k), porque la pila nunca contiene más de (k) elementos.

En (n) operaciones se realizan aproximadamente:

$$
\frac{n}{k}
$$

backups.

Si consideramos el peor caso, cada backup copia exactamente (k) elementos. Por lo tanto, el costo total de todos los backups es:

$$
\frac{n}{k}\cdot k = n.
$$

## 3. Costo total

Sumando ambos costos obtenemos:

$$
n + \frac{n}{k}k
= n + n
= 2n.
$$

Por lo tanto, el costo total de una secuencia de (n) operaciones es:

$$
O(n).
$$

Finalmente, el costo amortizado por operación es:

$$
\frac{2n}{n} = 2 = O(1).
$$

La idea clave es que, aunque un backup individual pueda costar (k), dicho costo solo ocurre una vez cada (k) operaciones. Por ello, ese costo se distribuye entre esas mismas operaciones y el promedio por operación permanece constante.


## Numero 2

Suponga que tenemos un algoritmo OPERACION(T, k) que recibe un ´arbol
binario completo T y un nodo k de dicho ´arbol y realiza un n´umero de pasos proporcional al
n´umero de descendientes de k (recuerde que un nodo es descendiente de s´ı mismo). Dado un
´arbol binario completo T con conjunto de nodos 1, . . . n, invocamos a OPERACION(T, k) n
veces consecutivas, una para cada k = 1 . . . n.
¿Cual es el costo amortizado, en notaci´on O-grande, de cada llamada a OPERACION?
Justifique adecuadamente.

# Ejercicio 2

## Idea aprendida

En análisis amortizado es común escribir el costo total como:

$$
(\text{cantidad}) \times (\text{costo unitario}).
$$

Luego, si queremos el costo amortizado, dividimos entre el número total de operaciones.

Esta es exactamente la misma idea utilizada en el Ejercicio 1.

---

## Aplicación al Ejercicio 2

La operación `OPERACION(T,k)` se ejecuta una vez para cada nodo del árbol.

Por lo tanto, existen exactamente:

$$
n
$$

llamadas.

El costo de una llamada es proporcional al número de descendientes del nodo correspondiente.

---

## Agrupando por niveles

En un árbol binario completo:

* En el nivel (d) existen aproximadamente

$$
2^d
$$

nodos.

* Cada nodo de ese nivel tiene aproximadamente

$$
\left\lfloor \frac{n}{2^d}\right\rfloor
$$

descendientes.

Por lo tanto, el costo del nivel (d) es:

$$
(\text{cantidad de nodos})
\times
(\text{costo por nodo})
=

2^d
\left\lfloor \frac{n}{2^d}\right\rfloor.
$$

Para simplificar el análisis asintótico:

$$
2^d
\left\lfloor \frac{n}{2^d}\right\rfloor
=

O\left(
2^d\frac{n}{2^d}
\right)
=
O(n).
$$

---

## Costo total

Sumando todos los niveles:

$$
\sum_{d=0}^{\lfloor \log_2 n \rfloor}
2^d
\left\lfloor \frac{n}{2^d}\right\rfloor.
$$

Aproximando:

$$
\sum_{d=0}^{\lfloor \log_2 n \rfloor}
2^d
\frac{n}{2^d}
=

\sum_{d=0}^{\lfloor \log_2 n \rfloor}
n.
$$

Como existen aproximadamente

$$
\lfloor \log_2 n \rfloor + 1
$$

niveles, obtenemos:

$$
n(\lfloor \log_2 n \rfloor + 1).
$$

Por lo tanto, el costo total es:

$$
O(n\log n).
$$

---

## Costo amortizado

Como hubo exactamente (n) llamadas a `OPERACION`, el costo amortizado por llamada es:

$$
\frac{O(n\log n)}{n}
=

O(\log n).
$$

---

## Relación con el Ejercicio 1

En el Ejercicio 1 también usamos el mismo patrón:

$$
(\text{cantidad de backups})
\times
(\text{costo de cada backup})
=

\frac{n}{k}\cdot k.
$$

En este ejercicio usamos:

$$
(\text{cantidad de nodos por nivel})
\times
(\text{costo de cada nodo})
=

2^d\cdot \frac{n}{2^d}.
$$

En ambos casos, la estrategia consiste en identificar:

1. Cuántas veces ocurre algo.
2. Cuánto cuesta cada ocurrencia.
3. Multiplicar para obtener el costo total.
4. Dividir entre el número de operaciones para obtener el costo amortizado.


## NUMERO 3:

# Ejercicio 3

Se ejecutan (n) operaciones. La operación (i) tiene costo:

* (i), si (i) es una potencia de 2.
* (1), en caso contrario.

Se pide determinar el costo amortizado usando el **método de recargas (Accounting Method)**.

## Búsqueda del costo amortizado

Probamos asignar un costo amortizado constante a cada operación.

Consideremos las primeras operaciones:

| Operación (i) | Costo real |
| ------------- | ---------: |
| 1             |          1 |
| 2             |          2 |
| 3             |          1 |
| 4             |          4 |
| 5             |          1 |
| 6             |          1 |
| 7             |          1 |
| 8             |          8 |

Si cobramos amortizadamente 2 unidades por operación, el banco eventualmente se vuelve negativo. Por ejemplo, en la operación 8 no se acumulan suficientes créditos para pagar el costo real.

Por lo tanto, una recarga de 2 no es suficiente.

Ahora probamos cobrando 3 unidades por operación.

## Justificación general

Entre dos potencias consecutivas de 2, es decir, entre

$$
2^{m-1}
\quad\text{y}\quad
2^m,
$$

existen exactamente

$$
2^m-2^{m-1}=2^{m-1}
$$

operaciones.

Cada operación que cuesta 1 deja almacenados

$$
3-1=2
$$

créditos en el banco.

Por lo tanto, antes de llegar a la siguiente operación costosa se acumulan al menos

$$
2\cdot 2^{m-1}=2^m
$$

créditos.

La operación costosa correspondiente tiene costo real

$$
2^m,
$$

por lo que los créditos acumulados son suficientes para pagarla completamente sin que el banco se vuelva negativo.

Así, el saldo del banco nunca es negativo y la recarga de 3 unidades es válida.

## Conclusión

Podemos asignar un costo amortizado constante igual a

$$
3
$$

a cada operación.

Como 3 es una constante, el costo amortizado por operación es

$$
O(1).
$$

Por lo tanto, el costo amortizado de cada operación es:

$$
\boxed{O(1)}.
$$

## NUMERO 4

Ejercicio 4. Considere una tabla din´amica que duplica su capacidad cuando est´a llena y
adem´as, cuando el n´umero de elementos almacenados cae por debajo de un cuarto de la
capacidad, la capacidad se reduce a la mitad. La tabla soporta las siguientes operaciones:
Insert(x): inserta el elemento x en la tabla.
Delete(): elimina un elemento de la tabla.
1. Muestre que una estrategia ingenua que reduce la capacidad a la mitad cada vez que
la tabla llega a estar medio vac´ıa puede llevar a un costo amortizado no constante.
2. Analice la estrategia que reduce la capacidad a la mitad solo cuando el n´umero de
elementos almacenados es menor que un cuarto de la capacidad.
3. Demuestre que tanto Insert como Delete tienen costo amortizado O(1) bajo esta
estrategia


# Ejercicio 4

## (a) Estrategia ingenua: reducir cuando la tabla está medio vacía

Supongamos una tabla con:

$$
\text{capacidad}=k,
\qquad
\text{elementos}=\frac{k}{2}.
$$

La estrategia ingenua reduce la capacidad a la mitad cuando la tabla está medio vacía. Por lo tanto:

$$
(k,;k/2)
\longrightarrow
(k/2,;k/2).
$$

La nueva tabla queda completamente llena.

Si realizamos un `Insert`, la tabla debe expandirse:

$$
(k/2,;k/2)
\longrightarrow
(k,;k/2+1).
$$

Luego, si realizamos un `Delete`, obtenemos:

$$
(k,;k/2+1)
\longrightarrow
(k,;k/2).
$$

Como la tabla vuelve a estar medio vacía, se reduce nuevamente:

$$
(k,;k/2)
\longrightarrow
(k/2,;k/2).
$$

Se regresa exactamente al estado inicial, por lo que la secuencia

$$
\text{Insert, Delete, Insert, Delete, }\ldots
$$

provoca expansiones y reducciones continuas.

Cada redimensionamiento copia aproximadamente

$$
\frac{k}{2}
$$

elementos. En solo dos operaciones se incurre en un costo de

$$
\Theta\left(\frac{k}{2}\right)
+
\Theta\left(\frac{k}{2}\right)
=

\Theta(k).
$$

Por lo tanto, el costo amortizado es

$$
\frac{\Theta(k)}{2}
=

\Theta(k),
$$

el cual no es constante.

---

## (b) Estrategia del cuarto

Ahora se reduce la capacidad únicamente cuando el número de elementos es menor que un cuarto de la capacidad.

Supongamos que acaba de ocurrir una reducción:

$$
\text{capacidad}=k/2,
\qquad
\text{elementos}=k/4-1.
$$

Para volver a expandir, la tabla de capacidad (k/2) debe llenarse. Por lo tanto, se requieren aproximadamente

$$
\frac{k}{2}-\left(\frac{k}{4}-1\right)
=

\frac{k}{4}+1
$$

inserciones.

De manera similar, después de una expansión, se requieren aproximadamente

$$
\frac{k}{4}+1
$$

eliminaciones antes de que pueda ocurrir una nueva reducción.

Por lo tanto, entre dos redimensionamientos consecutivos existen

$$
\Theta(k)
$$

operaciones.

---

## (c) Costo amortizado

Consideremos una expansión.

Las operaciones realizadas antes de la expansión cuestan aproximadamente

$$
\frac{k}{4}+1.
$$

Además, la expansión copia aproximadamente

$$
\frac{k}{2}
$$

elementos.

Por lo tanto, el costo total del bloque es

$$
\left(\frac{k}{4}+1\right)
+
\frac{k}{2}.
$$

El término dominante es

$$
\Theta(k).
$$

Este costo se distribuye entre aproximadamente

$$
\frac{k}{4}+1
=

\Theta(k)
$$

operaciones.

Así, el costo amortizado es

$$
\frac{\Theta(k)}{\Theta(k)}
=

\Theta(1).
$$

El mismo razonamiento aplica a las reducciones.

Por lo tanto, el costo amortizado de `Insert` y `Delete` es

$$
\boxed{O(1)}.
$$



# Ejercicio 5

Se ejecutan (n) operaciones sobre una estructura de datos de tal manera que:

* La operación (i) cuesta (i), cuando (i) es una potencia de 3.
* La operación cuesta (2), en caso contrario.

Se pide determinar el costo amortizado utilizando el **método de recargas**.

## Identificación de las operaciones costosas

Las operaciones costosas ocurren en:

$$
1,;3,;9,;27,;81,;\ldots,;3^m,;3^{m+1},\ldots
$$

y su costo es precisamente:

$$
1,;3,;9,;27,;81,;\ldots,;3^m,;3^{m+1},\ldots
$$

## Distancia entre dos operaciones costosas

Entre dos potencias consecutivas de 3 existen aproximadamente:

$$
3^{m+1}-3^m
=

2\cdot 3^m
$$

operaciones.

Estas representan las oportunidades que tenemos para acumular créditos antes de llegar a la siguiente operación costosa.

## Determinación de la recarga

Supongamos que cobramos una cantidad amortizada constante (c) por cada operación.

Las operaciones normales tienen costo real 2, por lo que cada una deja almacenados:

$$
c-2
$$

créditos.

Para que el banco nunca sea negativo, los créditos acumulados antes de llegar a la siguiente operación costosa deben ser suficientes para pagarla.

Necesitamos entonces que:

$$
(c-2)\left(2\cdot 3^m\right)
\ge
3^{m+1}.
$$

Dividiendo entre (3^m), obtenemos:

$$
2(c-2)\ge 3.
$$

Por lo tanto,

$$
c-2\ge \frac{3}{2},
$$

es decir,

$$
c\ge \frac{7}{2}.
$$

Como buscamos una recarga constante sencilla, elegimos

$$
c=4.
$$

## Verificación

Con una recarga de 4:

* Una operación normal cuesta 2 y deja

$$
4-2=2
$$

créditos.

* Entre (3^m) y (3^{m+1}) se acumulan

$$
2\left(2\cdot 3^m\right)
=

4\cdot 3^m
$$

créditos.

* La siguiente operación costosa requiere

$$
3^{m+1}
=

3\cdot 3^m
$$

créditos.

Como

$$
4\cdot 3^m
\ge
3\cdot 3^m,
$$

el banco nunca se vuelve negativo.

## Conclusión

Existe una recarga constante igual a

$$
4,
$$

por lo que el costo amortizado de cada operación es constante.

Por lo tanto, el costo amortizado es:

$$
\boxed{O(1)}.
$$

## numero 6

Ejercicio 6. Una secuencia de n operaciones es ejecutada sobre cierta estructura de datos,
de manera tal que la operaci´on cuesta i, cuando i es un cuadrado perfecto, y 2 en caso
contrario.
¿Cual es el costo amortizado, en notaci´on O-grande, de cada operaci´on? Puede usar el
m´etodo agregado o de recargas. En cualquier caso debe justificar adecuadamente.


# Ejercicio 6

Se ejecutan (n) operaciones sobre una estructura de datos de tal manera que:

* La operación (i) cuesta (i), cuando (i) es un cuadrado perfecto.
* La operación cuesta (2), en caso contrario.

Se pide determinar el costo amortizado utilizando el método agregado o de recargas.

## Identificación de las operaciones costosas

Las operaciones costosas ocurren cuando:

$$
i=1,4,9,16,25,\ldots,m^2,(m+1)^2,\ldots
$$

y sus costos son:

$$
(m+1)^2-m^2
=
m^2+2m+1-m^2
=
2m+1.
$$

## Distancia entre dos operaciones costosas

Entre dos cuadrados consecutivos existe una diferencia de:

$$
(m+1)^2-m^2.
$$

Desarrollando:

$$
(m+1)^2-m^2
=

m^2+2m+1-m^2

2m+1.
$$

Por lo tanto, entre las operaciones costosas (m^2) y ((m+1)^2) existen aproximadamente

$$
2m+1
$$

operaciones que pueden acumular créditos.

## Determinación de la recarga

Supongamos que cobramos una cantidad amortizada constante (c) por cada operación.

Las operaciones normales tienen costo real 2, por lo que cada una deja almacenados:

$$
c-2
$$

créditos.

Para pagar la siguiente operación costosa, debemos cumplir que:

$$
(c-2)(2m+1)
\ge
(m+1)^2.
$$

Despejando:

$$
c-2
\ge
\frac{(m+1)^2}{2m+1}.
$$

Sin embargo,

$$
\frac{(m+1)^2}{2m+1}
=

\frac{m^2+2m+1}{2m+1}.
$$

Para valores grandes de (m),

$$
\frac{m^2+2m+1}{2m+1}
\approx
\frac{m^2}{2m}
=

\frac{m}{2}.
$$

Por lo tanto, el ahorro necesario por operación crece con (m) y no puede ser acotado por una constante.

## Expresión en función de (n)

El último cuadrado perfecto antes de (n) cumple aproximadamente:

$$
m^2\le n.
$$

De donde se obtiene:

$$
m\le \sqrt{n}.
$$

Por lo tanto, el ahorro necesario por operación es del orden de

$$
\Theta(m)
=

\Theta(\sqrt{n}).
$$

## Conclusión

No existe una recarga constante que permita mantener el banco siempre no negativo.

El costo amortizado por operación no es (O(1)), sino que crece con el tamaño de la entrada.

Por lo tanto, el costo amortizado de cada operación es:

$$
\boxed{O(\sqrt{n})}.
$$

De manera más precisa,

$$
\boxed{\Theta(\sqrt{n})}.
$$


# Ejercicio 7

Se puede implementar el arreglo extensible mediante un **arreglo circular dinámico**.

La estructura mantiene las siguientes variables:

* `data[]`: arreglo que almacena los elementos.
* `capacity`: capacidad actual del arreglo.
* `size`: número actual de elementos almacenados.
* `front`: índice donde comienza la secuencia lógica.

## AddToFront(x)

Para insertar un elemento al inicio, no es necesario desplazar todos los elementos del arreglo.

Simplemente se actualiza el índice `front`:

```cpp
front = (front - 1 + capacity) % capacity;
data[front] = x;
size++;
```

Si el arreglo está lleno, se crea un nuevo arreglo con el doble de capacidad y se copian los elementos en orden.

La copia ocurre solo ocasionalmente, por lo que el costo amortizado es:

$$
O(1).
$$

## AddToEnd(x)

El nuevo elemento se inserta en la posición:

$$
(front + size)\bmod capacity.
$$

Es decir:

```cpp
data[(front + size) % capacity] = x;
size++;
```

Si el arreglo está lleno, se duplica la capacidad y se copian los elementos.

Por lo tanto, el costo amortizado es:

$$
O(1).
$$

## Lookup(k)

El elemento lógico número (k) se encuentra en la posición física:

$$
(front + k)\bmod capacity.
$$

Por lo tanto:

```cpp
return data[(front + k) % capacity];
```

Si (k \ge size), se devuelve `Null`.

El acceso a un arreglo es de tiempo constante, y las operaciones de suma y módulo también son constantes. Por ello, el tiempo de peor caso es:

$$
O(1).
$$

## Espacio utilizado

El arreglo mantiene una capacidad proporcional al número de elementos almacenados, ya que se duplica únicamente cuando se llena.

Por lo tanto, el espacio utilizado es:

$$
O(n),
$$

donde (n) es la longitud actual de la secuencia.

## Conclusión

Un **arreglo circular dinámico** satisface todos los requerimientos del problema:

* `AddToFront(x)` : (O(1)) amortizado.
* `AddToEnd(x)` : (O(1)) amortizado.
* `Lookup(k)` : (O(1)) en el peor caso.
* Espacio utilizado : (O(n)).
