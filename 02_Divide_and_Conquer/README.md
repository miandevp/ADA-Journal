# Divide and Conquer

**Divide and Conquer (Divide y Vencerás)** es una **técnica de diseño de algoritmos** que consiste en dividir un problema grande en varios **subproblemas más pequeños**, resolver cada uno de ellos y, cuando sea necesario, **combinar sus soluciones** para obtener la solución del problema original.

> **Idea principal:** en lugar de intentar resolver todo el problema de una sola vez, se divide en partes más pequeñas y se trabaja cada parte por separado.

## Ejemplo con un arreglo

Imaginemos un arreglo de 8 elementos:

    [1 2 3 4 5 6 7 8]

Podemos dividir el problema en dos:

    [1 2 3 4]    [5 6 7 8]

Y nuevamente dividir cada parte:

    [1 2] [3 4]    [5 6] [7 8]

Finalmente:

    [1] [2] [3] [4] [5] [6] [7] [8]

Cada parte es un **subproblema** del problema original.

Lo importante es que los subproblemas juntos representan nuevamente todo el problema original.

## ¿Tiene que dividirse exactamente por la mitad?

**No.**

Por ejemplo, un problema con 10 elementos podría dividirse así:

    [1 2 3]   [4 5 6 7]   [8 9 10]

Los tamaños son:

    3 + 4 + 3 = 10

No tienen que ser iguales. Tampoco es obligatorio hacer exactamente 2 subproblemas. Puede haber 2, 3 o más, dependiendo del algoritmo.

Lo importante es que estamos **separando el problema en partes más pequeñas**.

## Las 3 etapas de Divide and Conquer

### 1. Divide

Se toma el problema original y se divide en **subproblemas más pequeños**.

    [1 2 3 4 5 6 7 8]
              ↓
    [1 2 3 4]    [5 6 7 8]

### 2. Conquer

Se **resuelve cada subproblema aplicando el algoritmo o técnica correspondiente**.

Por ejemplo, si estamos haciendo **Merge Sort**, cada subproblema se vuelve a dividir y resolver hasta llegar a problemas suficientemente pequeños.

    [1 2] → resolver
    [3 4] → resolver
    [5 6] → resolver
    [7 8] → resolver

En muchos algoritmos esto se hace **recursivamente**, aplicando la misma estrategia a cada subproblema.

### 3. Combine

Una vez que tenemos las soluciones de los subproblemas, **las juntamos para construir la solución del problema original**.

Es decir, después de dividir el problema y resolver cada parte, aplicamos lo que el algoritmo haya preparado para cada subproblema y finalmente **juntamos esas soluciones**.

Por ejemplo, en Merge Sort:

    [1] [2] → [1 2]
    [3] [4] → [3 4]

    [1 2] + [3 4] → [1 2 3 4]

Luego:

    [5] [6] → [5 6]
    [7] [8] → [7 8]

    [5 6] + [7 8] → [5 6 7 8]

Finalmente:

    [1 2 3 4] + [5 6 7 8]
              ↓
    [1 2 3 4 5 6 7 8]

Ese proceso de **juntar las soluciones de los subproblemas para obtener la solución del problema completo** es lo que llamamos **Combine**.

## ¿Por qué normalmente aparece la recursividad?

Porque una vez que dividimos el problema, podemos aplicar **la misma técnica nuevamente a cada subproblema**:

    Problema
       ↓
    Dividir
       ↓
    Subproblemas
       ↓
    Dividir nuevamente cada subproblema
       ↓
    ...
       ↓
    Resolver problemas pequeños
       ↓
    Combinar

Por eso los algoritmos Divide and Conquer suelen ser recursivos.

## Lo que NO debes confundir

**Recursividad ≠ Divide and Conquer.**

Un algoritmo puede ser recursivo sin ser Divide and Conquer.

Lo que caracteriza a Divide and Conquer es la estrategia:

$$
\boxed{\text{Dividir → Resolver subproblemas → Combinar}}
$$v

La recursividad es simplemente una forma muy habitual de implementar esa estrategia.

## Idea para recordar

> **Divide and Conquer consiste en tomar un problema grande y repartirlo en problemas más pequeños que, juntos, representan el problema original; luego se resuelven esos subproblemas y se combinan sus resultados para obtener la solución final.**