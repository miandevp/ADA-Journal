# Aggregate Analysis

El análisis amortizado estudia el costo promedio de una secuencia de operaciones.

Si una secuencia de \(n\) operaciones tiene un costo total de \(T(n)\), entonces el costo amortizado se define como:

$$
\text{Costo Amortizado}=\frac{T(n)}{n}
$$

Donde:

$$
T(n) = \text{Costo total de las } n \text{ operaciones}
$$

$$
n = \text{Número total de operaciones}
$$

La idea es analizar el costo promedio de toda la secuencia y no únicamente la operación más costosa.

## Ejemplo

Consideremos la siguiente secuencia:

$$
\text{PUSH}=1
$$

$$
\text{PUSH}=1
$$

$$
\text{PUSH}=1
$$

$$
\text{MULTIPOP}(3)=3
$$

El costo total es:

$$
T(4)=1+1+1+3=6
$$

Observamos que:

$$
n=4
$$

porque se realizaron cuatro operaciones:

1. PUSH
2. PUSH
3. PUSH
4. MULTIPOP

Aplicando la fórmula del costo amortizado:

$$
\frac{T(4)}{4}
=
\frac{6}{4}
=
1.5
$$

Por lo tanto, el costo promedio por operación es:

$$
1.5
$$

---

## Aggregate Analysis

Para analizar el costo amortizado de las operaciones sobre un Stack, consideremos una secuencia de (n) operaciones.

Sea:

$$
p
$$

el número de operaciones PUSH realizadas durante toda la secuencia.

Cada operación PUSH inserta un elemento en la pila y tiene costo:

$$
1
$$

Por lo tanto, el costo total de todas las inserciones es:

$$
p
$$

Ahora observemos una propiedad importante del Stack:

> Cada elemento insertado puede ser eliminado como máximo una vez.

Esto significa que si se insertaron (p) elementos, el número total de eliminaciones (ya sea mediante POP o mediante MULTIPOP) no puede superar:

$$
p
$$

Como cada eliminación tiene costo 1, el costo total de todas las eliminaciones cumple:

$$
\le p
$$

Por lo tanto, el costo total de la secuencia está acotado por:

$$
T(n)
====

\text{Costo de inserciones}
+
\text{Costo de eliminaciones}
$$

$$
T(n)
\le
p+p
=

2p
$$

La intuición detrás de esta cota es que cada elemento puede generar como máximo dos unidades de trabajo:

1. Una al ser insertado.
2. Una al ser eliminado.

Por ello, cada elemento contribuye con un costo máximo de:

$$
1+1=2
$$

Además, como las operaciones PUSH forman parte de las (n) operaciones totales:

$$
p \le n
$$

Entonces:

$$
T(n)
\le
2p
\le
2n
$$

Aplicando la definición de costo amortizado:

$$
\frac{T(n)}{n}
\le
\frac{2n}{n}
=

2
$$

Por lo tanto, el costo amortizado por operación es:

$$
O(1)
$$

### Conclusión

Aunque una operación MULTIPOP puede parecer costosa al eliminar muchos elementos en una sola ejecución, cada elemento insertado puede eliminarse como máximo una vez. Como consecuencia, el costo total de una secuencia de (n) operaciones es (O(n)), y el costo amortizado por operación es:

$$
O(1)
$$


# Binary Counter

A diferencia del Stack, el Binary Counter no es una estructura de datos. Se utiliza como un ejemplo clásico para mostrar cómo una operación puede parecer costosa de manera individual, pero tener un costo amortizado constante cuando se analiza una secuencia completa de operaciones.

La operación considerada es:

$$
\text{INCREMENT}
$$

Cada incremento aumenta en uno el valor del contador binario.

Por ejemplo:

```text
0000 -> 0001
0001 -> 0010
0010 -> 0011
0011 -> 0100
```

El costo de un incremento se define como el número de bits que cambian de valor.

## Ejemplo

```text
0000 -> 0001
```

Cambia:

$$
b_0
$$

Costo:

$$
1
$$

---

```text
0001 -> 0010
```

Cambian:

$$
b_1; b_0
$$

Costo:

$$
2
$$

---

```text
0011 -> 0100
```

Cambian:

$$
b_2; b_1; b_0
$$

Costo:

$$
3
$$

A primera vista, algunos incrementos parecen costosos porque pueden cambiar varios bits simultáneamente.

## Reorganizando el conteo

En lugar de sumar los costos fila por fila:

$$
1+2+1+3+1+2+1+4
$$

podemos contar cuántas veces cambia cada bit.

```text
Incremento      b3   b2   b1   b0
----------------------------------
0->1                          1

1->2                     1    1

2->3                          1

3->4                1    1    1

4->5                          1

5->6                     1    1

6->7                          1

7->8           1    1    1    1
----------------------------------
Total          1    2    4    8
```

Por lo tanto:

$$
T(8)=8+4+2+1
$$

Observamos un patrón:

* El bit (b_0) cambia en cada incremento.
* El bit (b_1) cambia cada dos incrementos.
* El bit (b_2) cambia cada cuatro incrementos.
* El bit (b_3) cambia cada ocho incrementos.

En general:

$$
b_0=n
$$

$$
b_1=\frac{n}{2}
$$

$$
b_2=\frac{n}{4}
$$

$$
b_3=\frac{n}{8}
$$

y así sucesivamente.

## Aggregate Analysis

El costo total después de (n) incrementos es:

$$
T(n)
=

n+\frac{n}{2}+\frac{n}{4}+\frac{n}{8}+\cdots
$$

Factorizando (n):

$$
T(n)
=

n
\left(
1+\frac12+\frac14+\frac18+\cdots
\right)
$$

La serie geométrica:

$$
1+\frac12+\frac14+\frac18+\cdots
$$

está acotada por:

$$
2
$$

Por lo tanto:

$$
T(n)<2n
$$

Aplicando la definición de costo amortizado:

$$
\frac{T(n)}{n}
<
\frac{2n}{n}
=

2
$$

Por lo tanto, el costo amortizado por incremento es:

$$
O(1)
$$

## Conclusión

Aunque algunos incrementos pueden cambiar muchos bits y parecer costosos, cada bit cambia con una frecuencia cada vez menor. Como consecuencia, el costo total de (n) incrementos es (O(n)), y el costo amortizado por incremento es:

$$
O(1)
$$
