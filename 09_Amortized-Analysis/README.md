

# Amortized Analysis

## ¿Qué es?

El análisis amortizado es una técnica utilizada para determinar el costo promedio de una secuencia de operaciones.

A diferencia del análisis de peor caso, no estudia una operación aislada, sino el comportamiento de muchas operaciones ejecutadas consecutivamente.

La idea principal es que algunas operaciones pueden ser costosas ocasionalmente, pero ocurren con poca frecuencia. Por ello, su costo puede distribuirse entre todas las operaciones realizadas.

---

## Ejemplo: Vector dinámico

Supongamos un arreglo dinámico que duplica su capacidad cuando se llena.

### Inserciones normales

La mayoría de las inserciones requieren únicamente:

```text
Agregar el elemento al final
```

Costo:

```text
O(1)
```

### Redimensionamiento

Cuando el arreglo se llena:

```text
1. Crear un arreglo más grande.
2. Copiar todos los elementos.
3. Insertar el nuevo elemento.
```

Costo:

```text
O(n)
```

---

## ¿Por qué el costo amortizado sigue siendo O(1)?

Si observamos una secuencia de inserciones:

```text
Capacidad: 1
Capacidad: 2
Capacidad: 4
Capacidad: 8
Capacidad: 16
...
```

Las copias realizadas son:

```text
1 + 2 + 4 + 8 + ... + 2^(k-1)
```

y la suma es:

```math
1 + 2 + 4 + \cdots + 2^{k-1}
=
2^k - 1
```

Si se realizaron aproximadamente n inserciones:

```math
\text{Costo total} = O(n)
```

Por lo tanto:

Costo amortizado por inserción:

```math
\frac{O(n)}{n}
=
O(1)
```
## Métodos de análisis amortizado

### Aggregate Method

Calcula el costo total de una secuencia de operaciones y luego obtiene el promedio.

### Accounting Method

Asigna "créditos" a las operaciones baratas para pagar futuras operaciones costosas.

### Potential Method

Utiliza una función potencial para almacenar trabajo "acumulado" que compensará costos futuros.

---

## Diferencia con el peor caso

| Análisis   | Qué estudia                                       |
| ---------- | ------------------------------------------------- |
| Peor caso  | La operación más costosa posible                  |
| Promedio   | Un caso promedio basado en probabilidades         |
| Amortizado | El costo promedio de una secuencia de operaciones |

---

Y una fórmula bonita para probar que GitHub renderiza matemáticas:

$$
T(n)=\frac{1+2+4+\cdots+2^{k-1}}{n}
\approx O(1)
$$

