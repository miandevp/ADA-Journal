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

### Paso 1: Inicializar el arreglo de conteo

Se crea el arreglo `C` y todas sus posiciones se inicializan en cero.

Objetivo:

* Preparar el arreglo que almacenará las frecuencias.
* Cada posición representa un valor posible.

Ejemplo:

```text
C = [0,0,0,0,0,0]
```

---

### Paso 2: Contar frecuencias

Se recorre el arreglo de entrada `A`.

Por cada elemento encontrado, se incrementa su contador en `C`.

Ejemplo:

```text
A = [2,4,5,3,1,2,3,5]
```

Resultado:

```text
C = [0,1,2,2,1,2]
```

Interpretación:

* 1 aparece una vez.
* 2 aparece dos veces.
* 3 aparece dos veces.
* 4 aparece una vez.
* 5 aparece dos veces.

---

### Paso 3: Acumular frecuencias

Se recorre el arreglo `C` y cada posición almacena la suma acumulada de las posiciones anteriores.

Ejemplo:

```text
Antes:

C = [0,1,2,2,1,2]

Después:

C = [0,1,3,5,6,8]
```

Interpretación:

* El último 2 debe terminar en la posición 3.
* El último 3 debe terminar en la posición 5.
* El último 4 debe terminar en la posición 6.
* El último 5 debe terminar en la posición 8.

Ahora `C` ya no almacena frecuencias, sino posiciones finales.

---

### Paso 4: Construir el arreglo ordenado

Después de acumular las frecuencias, el arreglo `C` ya no representa cuántas veces aparece cada valor. Ahora representa cuántos elementos son menores o iguales a cada valor.

Ejemplo:

```text
C = [0,1,3,5,6,8]
```

Interpretación:

```text
C[1] = 1
```

Existe 1 elemento menor o igual que 1.

```text
C[2] = 3
```

Existen 3 elementos menores o iguales que 2.

```text
C[3] = 5
```

Existen 5 elementos menores o iguales que 3.

```text
C[4] = 6
```

Existen 6 elementos menores o iguales que 4.

```text
C[5] = 8
```

Existen 8 elementos menores o iguales que 5.

---

Ahora recorremos el arreglo original `A` desde el final hacia el inicio.

Supongamos que elegimos el último elemento de `A`:

```text
A = [2,4,5,3,1,2,3,5]
                     ↑
```

El valor seleccionado es:

```text
A[i] = 5
```

Consultamos:

```text
C[5] = 8
```

Esto significa que existen 8 elementos menores o iguales que 5.

Por lo tanto, este 5 debe ocupar la posición 8 del arreglo ordenado.

```text
B[8] = 5
```

Una vez utilizada esa posición, la marcamos como ocupada:

```text
C[5]--
```

Resultado:

```text
C[5] = 7
```

Ahora la siguiente posición libre para otro valor 5 será la posición 7.

Si más adelante encontramos otro 5 en el recorrido de `A`, ese nuevo 5 se colocará en:

```text
B[7]
```

y nuevamente se reducirá el contador.

---

De esta forma, `C` actúa como una guía que indica cuál es la siguiente posición disponible para cada valor dentro del arreglo ordenado.

Los valores que no aparecen en `A` nunca ocuparán posiciones en `B`, aunque tengan un índice reservado en `C`.

Al finalizar el recorrido de `A`, todos los elementos habrán sido colocados en su posición correcta dentro de `B`, obteniendo así el arreglo ordenado.


