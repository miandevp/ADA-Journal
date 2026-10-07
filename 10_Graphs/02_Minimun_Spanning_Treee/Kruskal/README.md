# Kruskal's Algorithm: Entendiendo Qué Hace Realmente

## La idea principal

Después de definir el problema del **Minimum Spanning Tree (MST)**, surge una pregunta natural:

> ¿Cómo encontramos el árbol de menor costo sin tener que probar todos los árboles posibles?

Kruskal responde esta pregunta con una idea sorprendentemente simple:

> **Tomar las conexiones más baratas disponibles, siempre que no generen ciclos.**

---

## ¿Qué problema está resolviendo?

Dado un grafo conectado, no dirigido y ponderado,

$$
G=(V,E),
$$

queremos encontrar un árbol generador mínimo:

$$
T^*
===

\arg\min_{T\in\mathcal{S}}
\sum_{(u,v)\in E_T} w(u,v),
$$

donde:

* $\mathcal{S}$ es el conjunto de todos los spanning trees posibles,
* $E_T$ son las aristas del árbol,
* $w(u,v)$ es el peso de la arista que conecta los vértices $u$ y $v$.

En otras palabras,

> Queremos conectar todos los vértices gastando lo menos posible.

---

## ¿Cuál es la intuición de Kruskal?

Al principio pensé que Kruskal intentaba construir todos los árboles y escoger el mejor.

Sin embargo, la estrategia real es mucho más elegante:

> Si una conexión es barata y no introduce redundancia, probablemente vale la pena conservarla.

Por eso, Kruskal actúa de manera **greedy** (codiciosa):

> Toma la mejor decisión local esperando obtener una solución global óptima.

---

## ¿Qué hace el algoritmo?

### Paso 1: Ordenar las aristas

Se toman todas las aristas del grafo y se ordenan por peso creciente.

Por ejemplo:

| Arista  | Peso |
| ------- | ---: |
| $(A,D)$ |    1 |
| $(D,C)$ |    2 |
| $(B,C)$ |    3 |
| $(A,B)$ |    4 |
| $(A,E)$ |    5 |
| $(D,E)$ |    6 |

---

### Paso 2: Revisarlas una por una

Se empieza desde la arista más barata.

Para cada arista:

* Si **no forma un ciclo**, se agrega al MST.
* Si **forma un ciclo**, se descarta.

---

### Paso 3: Detenerse cuando el árbol esté completo

Un árbol con $|V|$ vértices tiene exactamente

$$
|V|-1
$$

aristas.

Por lo tanto, el algoritmo termina cuando ya se han seleccionado

$$
|V|-1
$$

aristas.

---

## Ejemplo intuitivo

Supongamos el siguiente orden:

1. $(A,D)$ peso $1$
2. $(D,C)$ peso $2$
3. $(B,C)$ peso $3$
4. $(A,B)$ peso $4$
5. $(A,E)$ peso $5$

Kruskal haría lo siguiente:

* Agrega $(A,D)$.
* Agrega $(D,C)$.
* Agrega $(B,C)$.
* Descubre que agregar $(A,B)$ produciría un ciclo y la descarta.
* Agrega $(A,E)$.

Al llegar a

$$
|V|-1
$$

aristas, el MST está completo.

---

## ¿Por qué evita ciclos?

Un ciclo representa una conexión redundante.

Por ejemplo,

```text
A ----- B
|       |
|       |
D ----- C
```

Si ya existe un camino entre dos vértices, agregar otra conexión entre ellos no mejora la conectividad.

Solo aumenta el costo.

Por eso, Kruskal rechaza cualquier arista que produzca ciclos.

---

## El verdadero corazón del algoritmo

Al principio parece que el problema difícil es encontrar la arista más barata.

Pero eso es sencillo: basta con ordenar.

La pregunta realmente importante es:

> **¿Cómo sabe la computadora si una arista crea un ciclo?**

La respuesta es la estructura de datos **Union-Find** o **Disjoint Set Union (DSU)**.

Union-Find permite responder eficientemente:

> "¿Estos dos vértices ya pertenecen al mismo componente conectado?"

* Si pertenecen al mismo conjunto, agregar la arista formaría un ciclo.
* Si pertenecen a conjuntos distintos, la arista es segura y puede añadirse.

---

## Complejidad temporal

Ordenar las aristas cuesta

$$
O(E\log E),
$$

y las operaciones de Union-Find son prácticamente constantes.

Por ello, Kruskal tiene una complejidad total de

$$
O(E\log E),
$$

que también suele escribirse como

$$
O(E\log V).
$$

---

## Reflexión personal

Antes de entender Kruskal, pensaba que encontrar un MST implicaba explorar muchísimas combinaciones posibles.

Ahora lo veo de otra manera:

> Kruskal no intenta construir todos los árboles y escoger el mejor.

Más bien,

> **recorre las conexiones de menor costo y se pregunta constantemente: "¿Esta conexión es realmente necesaria o solo introduce redundancia?"**

Si la respuesta es que la conexión ayuda sin crear ciclos, la conserva.

Si no, la descarta.

Al final, lo que queda es exactamente la red más barata capaz de mantener todos los vértices conectados.
