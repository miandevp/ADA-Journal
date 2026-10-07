# Insertion Sort

## ¿Qué es?

**Insertion Sort** es un algoritmo de ordenamiento que construye el arreglo ordenado progresivamente.

La idea es mantener una parte del arreglo **ya ordenada** y tomar los elementos restantes uno por uno para **insertarlos en la posición correcta** dentro de esa parte ordenada.

La estructura que debemos imaginar es:

**[ PARTE ORDENADA | PARTE NO ORDENADA ]**

En cada iteración, tomamos el primer elemento de la parte no ordenada y lo insertamos donde corresponde dentro de la parte ordenada.

---

## Ejemplo

Supongamos que tenemos:

    [5, 2, 4, 6, 1, 3]

Al comenzar, consideramos que el primer elemento ya está ordenado:

    [5 | 2, 4, 6, 1, 3]

Tomamos `2` y lo insertamos en la posición correcta:

    [2, 5 | 4, 6, 1, 3]

Tomamos `4`:

    [2, 4, 5 | 6, 1, 3]

Tomamos `6`:

    [2, 4, 5, 6 | 1, 3]

Tomamos `1`:

    [1, 2, 4, 5, 6 | 3]

Finalmente tomamos `3`:

    [1, 2, 3, 4, 5, 6]

El arreglo queda ordenado.

---

## ¿Cómo se realiza una inserción?

Supongamos que tenemos:

    [1, 3, 5, 5, 2]

Queremos insertar `2`.

Primero guardamos el elemento que queremos insertar:

    key = 2

La parte que ya está ordenada es:

    [1, 3, 5, 5]

Comenzamos desde el final de esa parte:

    j = 5

Comparamos:

    5 > 2

Como `5` es mayor que `2`, desplazamos `5` una posición hacia la derecha:

    [1, 3, 5, 5, 5]

Ahora retrocedemos:

    j = 3

Volvemos a comparar:

    5 > 2

Desplazamos nuevamente:

    [1, 3, 5, 5, 5]

    j = 3

Después:

    j = 2

Comparamos:

    3 > 2

Desplazamos `3`:

    [1, 3, 3, 5, 5]

Retrocedemos:

    j = 1

Ahora:

    1 > 2

es falso.

Por lo tanto, encontramos la posición correcta.

Insertamos `key` en `j + 1`:

    [1, 2, 3, 5, 5]

---

## ¿Qué hacen `key` y `j`?

### `key`

`key` guarda temporalmente el elemento que queremos insertar.

Por ejemplo:

    key = A[i]

Lo guardamos porque durante los desplazamientos podemos modificar las posiciones del arreglo.

### `j`

`j` representa la posición que estamos revisando dentro de la parte ordenada.

Comenzamos desde el elemento anterior a `key`:

    j = i - 1

Luego vamos hacia atrás:

    j--

Mientras encontremos elementos mayores que `key`, los desplazamos hacia la derecha:

    A[j + 1] = A[j]

Cuando encontramos un elemento que ya no es mayor que `key`, sabemos que encontramos la posición correcta.

Entonces:

    A[j + 1] = key

---

## Algoritmo

La idea general es:

1. Comenzar desde el segundo elemento.
2. Guardar el elemento actual en `key`.
3. Recorrer hacia atrás la parte ordenada.
4. Desplazar hacia la derecha los elementos mayores que `key`.
5. Insertar `key` en la posición encontrada.
6. Repetir hasta recorrer todo el arreglo.

Pseudocódigo:

    InsertionSort(A, n)

        para i ← 2 hasta n

            key ← A[i]
            j ← i - 1

            mientras j > 0 y A[j] > key

                A[j + 1] ← A[j]
                j ← j - 1

            A[j + 1] ← key

---

## ¿Qué está pasando en cada iteración?

Podemos visualizarlo así:

    [ PARTE ORDENADA | PARTE NO ORDENADA ]
                         ↓
                    tomar elemento
                         ↓
    [ PARTE ORDENADA + elemento ]
                         ↓
                    buscar posición
                         ↓
                    desplazar mayores
                         ↓
                       insertar

Después de cada iteración, la parte ordenada aumenta en un elemento.

---

## Complejidad

### Mejor caso

El arreglo ya está ordenado:

    [1, 2, 3, 4, 5]

En cada iteración solamente hacemos la comparación y no necesitamos desplazar elementos.

Por lo tanto:

    Θ(n)

### Peor caso

El arreglo está ordenado de forma inversa:

    [5, 4, 3, 2, 1]

Cada nuevo elemento debe desplazarse por toda la parte ordenada.

El número de operaciones crece aproximadamente como:

    1 + 2 + 3 + ... + (n - 1)

Y:

$$
1 + 2 + 3 + \cdots + (n-1)
=
\frac{n(n-1)}{2}
$$

Por lo tanto:

$$
T(n) = \Theta(n^2)
$$

### Resumen

| Caso | Complejidad |
|---|---|
| Mejor caso | $\Theta(n)$ |
| Peor caso | $\Theta(n^2)$ |
| Caso promedio | $\Theta(n^2)$ |

---

## Idea para recordar

> **Insertion Sort mantiene una parte ordenada y va tomando elementos de la parte no ordenada para insertarlos en su posición correcta.**

La operación fundamental no es intercambiar elementos, sino **desplazar los elementos mayores hacia la derecha y colocar `key` en el espacio que queda libre**.

---

## Relación con la versión recursiva

Este es el **Insertion Sort básico e iterativo**.

Más adelante podemos expresar la misma idea de forma recursiva:

    InsertionSort(A, n)

        InsertionSort(A, n - 1)

        insertar A[n] en A[1 ... n-1]

La idea sigue siendo la misma:

> Primero ordenamos los primeros `n - 1` elementos y después insertamos el elemento `n` en su posición correcta.

Esta versión recursiva permite analizar el algoritmo mediante una recurrencia como:

$$
T(n) = T(n-1) + n
$$

que lleva a:

$$
T(n) = \Theta(n^2)
$$