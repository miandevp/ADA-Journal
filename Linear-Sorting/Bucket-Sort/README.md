
# Bucket Sort

## Descripción

Bucket Sort es un algoritmo de ordenamiento que distribuye los elementos en varios grupos llamados *buckets* (cubetas). Cada bucket almacena los elementos que pertenecen a un determinado rango de valores.

Una vez distribuidos los elementos, cada bucket se mantiene ordenado mediante una lista enlazada ordenada. Finalmente, los elementos de todos los buckets se recorren en orden y se copian nuevamente al arreglo original.

Este algoritmo funciona especialmente bien cuando los datos están distribuidos uniformemente.

---

## Estructura utilizada

```cpp
struct Node{
    float valor;
    Node* next;
};
```

Cada bucket almacena una lista enlazada de nodos.

---

## Funcionamiento

### 1. Crear los buckets

Se crea un arreglo de punteros:

```cpp
Node* bucket[numBuck];
```

Inicialmente todos apuntan a `nullptr`.

---

### 2. Distribuir los elementos

Para cada elemento del arreglo se calcula el bucket correspondiente:

```cpp
indice = valor * numBuck;
```

Por ejemplo, con 10 buckets:

```text
0.12 -> bucket 1
0.43 -> bucket 4
0.78 -> bucket 7
```

---

### 3. Insertar ordenadamente

Cada valor se almacena en una lista enlazada ordenada dentro de su bucket.

Ejemplo:

```text
bucket[4]

0.41 -> 0.43 -> 0.49
```

Si llega:

```text
0.44
```

se inserta entre:

```text
0.43 y 0.49
```

obteniendo:

```text
0.41 -> 0.43 -> 0.44 -> 0.49
```

---

### 4. Reconstruir el arreglo

Se recorren los buckets desde el primero hasta el último y se copian los valores al arreglo original.

Ejemplo:

```text
bucket[0] -> 0.05 -> 0.07
bucket[1] -> 0.12
bucket[2] -> 0.25
```

Resultado:

```text
0.05 0.07 0.12 0.25
```

---

### 5. Liberar memoria

Los nodos fueron creados dinámicamente mediante:

```cpp
new Node
```

Por ello, al finalizar el algoritmo se recorren todas las listas enlazadas y se libera la memoria utilizando:

```cpp
delete
```

---

## Complejidad

### Mejor y caso promedio

Si los elementos se distribuyen uniformemente entre los buckets:

```text
O(n)
```

### Peor caso

Si todos los elementos caen en el mismo bucket:

```text
O(n²)
```

ya que las inserciones ordenadas se realizan sobre una única lista enlazada.

