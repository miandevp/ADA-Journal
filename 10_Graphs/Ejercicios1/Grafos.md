


# Ejercicio 2 – Modificación de la condición de parada en Dijkstra

## Enunciado

Se modifica la línea 5 del algoritmo de Dijkstra (implementado con una cola de prioridad):

```text
while |Q| > 1
```

en lugar de

```text
while |Q| > 0
```

La pregunta es si el algoritmo sigue siendo correcto.

---

# Respuesta

**Sí, el algoritmo continúa siendo correcto.**

---

# Justificación

En el algoritmo original, la cola de prioridad contiene todos los vértices que aún no han sido procesados.

En cada iteración:

1. Se extrae el vértice con menor distancia.
2. Se relajan todas sus aristas.
3. Ese vértice ya no vuelve a la cola.

Después de procesar \(n-1\) vértices, únicamente queda un vértice dentro de la cola.

En ese momento:

- Todos los demás vértices ya fueron extraídos.
- La distancia del último vértice ya es definitiva.
- No existe ningún otro vértice cuya distancia pueda mejorar mediante una relajación.

Por lo tanto, procesar el último vértice únicamente intentaría relajar aristas hacia vértices que ya fueron procesados, lo cual no modifica ninguna distancia.

---

# Intuición

Supongamos la cola:

```
Q = {A,B,C,D}
```

Las extracciones son:

```
Extraer A
Extraer B
Extraer C
```

Ahora queda

```
Q = {D}
```

Con la condición

```text
while |Q| > 1
```

el algoritmo termina aquí.

La única diferencia con el algoritmo original es que **no se extrae D**.

Sin embargo, la distancia de D ya fue calculada cuando se relajaron las aristas de los demás vértices.

Extraer D únicamente serviría para intentar actualizar otros vértices, pero ya no queda ninguno pendiente.

---

# Demostración

Sea \(u\) el último vértice que permanece en la cola.

Como todos los demás vértices ya fueron extraídos:

- sus distancias son definitivas (propiedad de Dijkstra);
- todas las posibles relajaciones hacia \(u\) ya ocurrieron.

Por tanto,

\[
d(u)=\delta(s,u)
\]

antes de sacar a \(u\) de la cola.

Si se ejecutara una iteración más:

1. se extraería \(u\);
2. se intentarían relajar sus aristas.

Pero ya no existen vértices sin procesar, por lo que ninguna relajación puede modificar las distancias finales.

Así, la última iteración no afecta el resultado.

---

# Conclusión

Cambiar la condición

```text
while |Q| > 0
```

por

```text
while |Q| > 1
```

**no altera las distancias mínimas calculadas por Dijkstra**.

Únicamente elimina la última extracción, la cual no produce ninguna actualización útil.

Por ello, **el algoritmo sigue siendo correcto**.



# Ejercicio3

# Algoritmo

Entrada:
- Grafo no dirigido G=(V,E)
- Pesos no negativos ℓ
- Arista e=(u,v)

Salida:
- Longitud del circuito mínimo que contiene e.

---

Eliminar temporalmente la arista e del grafo.

Ejecutar Dijkstra desde u.

Si dist[v] = ∞
    retornar "No existe un circuito que contenga e".

En otro caso

    retornar dist[v] + ℓ(e)

---

## Pseudocódigo

CircuitoMinimo(G,e)

    (u,v) ← extremos de e

    eliminar e de G

    dist ← Dijkstra(G,u)

    restaurar e en G

    si dist[v] = ∞
        retornar ∞

    retornar dist[v] + peso(e)


## diksjtra
DIJKSTRA(G, s)

Entrada:
    G = (V, E)
    s = vértice origen

Salida:
    dist[v] = distancia mínima desde s hasta cada vértice

Para cada vértice v ∈ V hacer
    dist[v] ← ∞
    padre[v] ← NIL

dist[s] ← 0

Q ← cola de prioridad vacía

Insertar(Q, (0, s))

Mientras Q no esté vacía hacer

    (d, u) ← ExtraerMin(Q)

    Si d > dist[u] entonces
        continuar

    Para cada vecino v de u hacer

        Si dist[v] > dist[u] + peso(u,v) entonces

            dist[v] ← dist[u] + peso(u,v)

            padre[v] ← u

            Insertar(Q, (dist[v], v))

Retornar dist, padre