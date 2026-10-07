# Entendiendo BFS (Breadth First Search)

La idea principal de BFS es recorrer un grafo por niveles utilizando una cola (Queue).

## ¿Cómo lo pienso?

1. Empiezo en un nodo inicial.
2. Lo marco como visitado.
3. Lo meto en una cola.
4. Mientras la cola tenga elementos:

   * Saco el primer nodo de la cola.
   * Reviso todos sus vecinos.
   * Si algún vecino no fue visitado:

     * Lo marco como visitado.
     * Lo agrego al final de la cola.

## Forma intuitiva

Pienso que la cola guarda los nodos que descubrí pero que todavía no he explorado.

Por ejemplo:

A tiene como vecinos B y C.

Empiezo en A.

Cola:
[A]

Saco A y reviso sus vecinos.

Cola:
[B, C]

Ahora saco B porque fue el primero en entrar.

Reviso los vecinos de B y encuentro D y E.

Cola:
[C, D, E]

Ahora saco C.

Reviso los vecinos de C y encuentro F.

Cola:
[D, E, F]

Luego saco D.

Después E.

Después F.

Y así sucesivamente.

## Lo más importante

BFS NO hace esto:

A -> B -> D -> H -> ...

Eso sería DFS.

BFS hace esto:

Nivel 0:
A

Nivel 1:
B, C

Nivel 2:
D, E, F

Nivel 3:
...

Es decir, primero visita todos los nodos cercanos y luego los más lejanos.

## Regla mental

"Saco un nodo de la cola, descubro sus vecinos y los agrego al final de la cola."

Repito ese proceso hasta que la cola quede vacía.

# Breadth-First Search (BFS)

## Representación del Grafo

Antes de entender BFS, es importante comprender cómo se almacena el grafo.

```cpp
class Graph {

private:
    int V;
    vector<vector<int>> adj;

};
```

### Variable V

```cpp
int V;
```

Representa la cantidad de vértices (nodos) del grafo.

Por ejemplo:

```cpp
Graph g(6);
```

Significa que el grafo tiene 6 nodos:

```text
0, 1, 2, 3, 4, 5
```

---

### Lista de Adyacencia

```cpp
vector<vector<int>> adj;
```

Es una lista de adyacencia.

Cada posición del vector almacena los vecinos de un nodo.

Por ejemplo:

```text
0 --- 1
|     |
|     |
2     3
```

Se almacena como:

```text
adj[0] = [1,2]
adj[1] = [0,3]
adj[2] = [0]
adj[3] = [1]
```

La idea principal es:

```text
adj[i] = vecinos del nodo i
```

---

### Constructor

```cpp
Graph(int vertices) {
    V = vertices;
    adj.resize(V);
}
```

Al crear:

```cpp
Graph g(6);
```

Se reserva espacio para almacenar los vecinos de los 6 nodos.

Inicialmente:

```text
adj[0] = []
adj[1] = []
adj[2] = []
adj[3] = []
adj[4] = []
adj[5] = []
```

---

### Agregar Aristas

```cpp
void addEdge(int u, int v) {

    adj[u].push_back(v);
    adj[v].push_back(u);

}
```

Por ejemplo:

```cpp
g.addEdge(0,1);
```

Produce:

```text
adj[0] = [1]
adj[1] = [0]
```

Al finalizar todas las inserciones:

```cpp
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,3);
g.addEdge(1,4);
g.addEdge(2,5);
```

La lista de adyacencia queda:

```text
adj[0] = [1,2]
adj[1] = [0,3,4]
adj[2] = [0,5]
adj[3] = [1]
adj[4] = [1]
adj[5] = [2]
```

---

# BFS (Breadth-First Search)

BFS es un algoritmo que recorre un grafo por niveles utilizando una cola (Queue).

La cola almacena los nodos descubiertos pero que aún no han sido explorados.

## Idea Intuitiva

1. Elegimos un nodo inicial.
2. Lo marcamos como visitado.
3. Lo agregamos a la cola.
4. Sacamos un nodo de la cola.
5. Revisamos todos sus vecinos.
6. Los vecinos no visitados se marcan y se agregan al final de la cola.
7. Repetimos hasta que la cola quede vacía.

## Forma de Pensarlo

Si comenzamos en A:

```text
A
├── B
└── C

B
├── D
└── E

C
└── F
```

Proceso:

```text
Cola = [A]

Saco A
Agrego B y C

Cola = [B,C]

Saco B
Agrego D y E

Cola = [C,D,E]

Saco C
Agrego F

Cola = [D,E,F]

Saco D
Saco E
Saco F
```

Observa que BFS no profundiza inmediatamente.

Primero visita todos los nodos cercanos y luego los más lejanos.

## Regla Mental

```text
Saco un nodo de la cola.
Reviso sus vecinos.
Los vecinos no visitados se agregan al final de la cola.
Repito hasta vaciar la cola.
```

## Complejidad

```text
Tiempo: O(V + E)

V = cantidad de vértices
E = cantidad de aristas
```
