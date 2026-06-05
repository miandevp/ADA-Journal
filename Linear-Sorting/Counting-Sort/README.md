# Counting Sort

## Idea General

Counting Sort es un algoritmo de ordenamiento que evita comparar elementos entre sí. En lugar de ello, cuenta cuántas veces aparece cada valor y utiliza esa información para construir el resultado ordenado.

## Estructuras Utilizadas

### A - Arreglo de Entrada

Contiene los datos originales que se desean ordenar.

Ejemplo:

```text
A = [2,4,5,3,1,2,3,5]
```

### B - Arreglo de Salida

Contendrá el resultado final del algoritmo.

Inicialmente está vacío.

```text
B = [_,_,_,_,_,_,_,_]
```

Al finalizar el algoritmo:

```text
B = [1,2,2,3,3,4,5,5]
```

### C - Arreglo de Conteo

Almacena información sobre la frecuencia de cada valor.

Para el arreglo:

```text
A = [2,4,5,3,1,2,3,5]
```

el arreglo de conteo será:

```text
Índice: 0 1 2 3 4 5
C:       0 1 2 2 1 2
```

Interpretación:

* El valor 1 aparece 1 vez.
* El valor 2 aparece 2 veces.
* El valor 3 aparece 2 veces.
* El valor 4 aparece 1 vez.
* El valor 5 aparece 2 veces.

## Flujo del Algoritmo

```text
A → C → B
```

1. Se leen los elementos de A.
2. Se construye C contando frecuencias.
3. Se utiliza C para ubicar correctamente cada elemento en B.
4. B contiene el arreglo ordenado.

```
```

