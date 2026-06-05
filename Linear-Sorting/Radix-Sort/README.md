# Radix Sort

## Idea General

Radix Sort es un algoritmo de ordenamiento que procesa los números dígito por dígito, comenzando por el menos significativo (unidades) hasta llegar al más significativo.

En lugar de comparar elementos entre sí, utiliza Counting Sort como subrutina para ordenar los elementos según el dígito que se está procesando en cada iteración.

Gracias a ello, puede ordenar números de diferentes tamaños manteniendo una complejidad lineal respecto al número de elementos para cada dígito procesado.

---

## Estructuras Utilizadas

### Arr - Arreglo Principal

Contiene los datos originales que se desean ordenar.

Ejemplo:

```text
Arr = [170,45,75,90,802,24,2,66]
```

Durante la ejecución, este arreglo se actualiza después de cada pasada para almacenar el resultado parcial del ordenamiento.

---

### B - Arreglo Temporal

Es generado por Counting Sort.

Su función es almacenar el resultado ordenado según el dígito actualmente procesado.

Ejemplo:

```text
B = [170,90,802,2,24,45,75,66]
```

Al finalizar cada iteración, su contenido es copiado nuevamente a `Arr`.

---

### C - Arreglo de Conteo

Utilizado internamente por Counting Sort.

Almacena frecuencias y posteriormente posiciones acumuladas para determinar dónde debe colocarse cada elemento dentro de `B`.

---

## Preprocesamiento

Antes de iniciar el algoritmo principal, se realizan dos tareas.

### Paso 1: Encontrar el valor máximo

Se recorre el arreglo para identificar el número más grande.

Ejemplo:

```text
Arr = [170,45,75,90,802,24,2,66]

max = 802
```

Este valor permite conocer cuántos dígitos debe procesar el algoritmo.

---

### Paso 2: Calcular la cantidad de dígitos

Se divide repetidamente el valor máximo entre 10 hasta llegar a cero.

Ejemplo:

```text
802 / 10 = 80
80 / 10 = 8
8 / 10 = 0
```

Resultado:

```text
d = 3
```

Esto indica que será necesario realizar tres pasadas:

```text
Unidades
Decenas
Centenas
```

---

## Flujo del Algoritmo

### Paso 1: Procesar cada posición decimal

Se comienza con:

```text
exp = 1
```

Posteriormente:

```text
exp = 10
exp = 100
exp = 1000
...
```

Cada valor de `exp` permite extraer un dígito específico de todos los números.

La extracción se realiza mediante:

```cpp
(A[i] / exp) % 10
```

---

### Paso 2: Ordenar por el dígito actual

Para cada valor de `exp`, se ejecuta Counting Sort.

Por ejemplo:

```text
Arr = [802,34,1234]
```

Con:

```text
exp = 1
```

los dígitos observados serán:

```text
[2,4,4]
```

Con:

```text
exp = 10
```

los dígitos observados serán:

```text
[0,3,3]
```

Con:

```text
exp = 100
```

los dígitos observados serán:

```text
[8,0,2]
```

Counting Sort utiliza estos dígitos para decidir la posición de cada elemento dentro de `B`, pero siempre mueve el número completo.

Por ejemplo:

```text
B = [802,34,1234]
```

y no:

```text
B = [2,4,4]
```

---

### Paso 3: Copiar el resultado

Una vez finalizado Counting Sort, el arreglo `B` contiene todos los números ordenados según el dígito actual.

Entonces se copia:

```text
B → Arr
```

para que la siguiente iteración continúe trabajando sobre el resultado previamente obtenido.

---

### Paso 4: Repetir para todos los dígitos

El proceso continúa hasta procesar todos los dígitos del número más grande.

Por ejemplo:

```text
exp = 1     → unidades
exp = 10    → decenas
exp = 100   → centenas
```

Al finalizar la última pasada, el arreglo queda completamente ordenado.

---

## ¿Cómo maneja números de diferente tamaño?

Radix Sort no necesita que todos los números tengan la misma cantidad de dígitos.

Cuando un número no posee una determinada posición decimal, la división entera produce automáticamente un cero.

Ejemplo:

```text
45
8
```

Para las decenas:

```text
(45 / 10) % 10 = 4
(8 / 10) % 10 = 0
```

Resultado:

```text
45 → 4
8  → 0
```

Es equivalente a pensar que:

```text
45 = 45
8  = 08
```

De manera implícita, los números más pequeños se comportan como si estuvieran rellenados con ceros a la izquierda.

Gracias a esto, Radix Sort puede ordenar correctamente números de diferentes longitudes.

---

## Complejidad

Si:

```text
n = cantidad de elementos
d = cantidad de dígitos del número más grande
```

Entonces:

```text
Counting Sort  → O(n)
Radix Sort     → O(d · n)
```

Por cada dígito se ejecuta un Counting Sort completo, por lo que el costo total depende tanto de la cantidad de elementos como de la cantidad de dígitos procesados.
