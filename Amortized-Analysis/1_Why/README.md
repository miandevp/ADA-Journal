## Introducción

Hasta este punto hemos analizado principalmente algoritmos completos y su complejidad. Sin embargo, en esta sección cambiaremos ligeramente el enfoque.

En lugar de estudiar algoritmos, analizaremos las operaciones o acciones que se realizan sobre estructuras de datos, como inserciones, eliminaciones o búsquedas. Veremos que evaluar cada operación de manera aislada no siempre refleja el comportamiento real de la estructura.

Por ello introduciremos el concepto de **análisis amortizado**, una técnica que permite estudiar el costo de una secuencia de operaciones y obtener una estimación más representativa de su rendimiento a largo plazo.


### Estructura elegida: Stack

Un Stack es una estructura de datos que sigue el principio **LIFO (Last In, First Out)**, donde el último elemento en ingresar es el primero en salir.

Las operaciones que analizaremos son:

- `Push(x)`: inserta un elemento en la cima.
- `Pop()`: elimina el elemento de la cima.
- `MultiPop(k)`: elimina hasta `k` elementos de la cima.


Estado inicial:

[ ]

Push(1)
Push(2)
Push(3)

[1, 2, 3]

MultiPop(2)

[1]

### Motivación

Supongamos la siguiente secuencia de operaciones sobre un Stack:

```text
Push
Push
Push
Push
MultiPop(4)
```

Si conocemos los costos reales de cada operación, obtenemos:

```text
1 + 1 + 1 + 1 + 4 = 8
```

Por lo tanto, el costo total de la secuencia es 8.

Sin embargo, en análisis de algoritmos normalmente trabajamos con notaciones asintóticas. En ese caso podríamos representar la misma secuencia como:

```text
O(1) + O(1) + O(1) + O(1) + O(n)
```

lo que se simplifica a:

```text
O(n)
```

Hasta aquí no existe ningún problema.

El inconveniente aparece cuando intentamos analizar una secuencia de muchas operaciones. Dado que `MultiPop(k)` puede llegar a costar `O(n)` en el peor caso, podríamos asumir incorrectamente que todas las operaciones alcanzan dicho costo:

```text
O(n) + O(n) + O(n) + ... + O(n)
```

Si existen `n` operaciones, concluiríamos:

```text
n · O(n) = O(n²)
```

No obstante, esta conclusión resulta demasiado pesimista. Para que un `MultiPop` elimine muchos elementos, dichos elementos debieron haber sido insertados previamente mediante operaciones `Push`. En consecuencia, no todas las operaciones pueden alcanzar simultáneamente su peor caso.

Esta observación motiva la necesidad de una técnica que analice el comportamiento de una secuencia completa de operaciones en lugar de estudiar únicamente el peor caso de cada operación de forma aislada.

