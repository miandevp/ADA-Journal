# Solución - Ejercicio 1

## a) ¿Cuál es el costo de su árbol generador mínimo?

Aplicando el algoritmo de Kruskal, las aristas seleccionadas son:

1. $$AE\;(1)$$
2. $$EF\;(1)$$
3. $$EB\;(2)$$ (o $$BF\;(2)$$)
4. $$FG\;(3)$$
5. $$GH\;(3)$$
6. $$CG\;(4)$$
7. $$GD\;(5)$$

Costo total:

$$
1+1+2+3+3+4+5=19
$$

**Respuesta:**

$$
\boxed{19}
$$

---

## b) ¿Cuántos árboles generadores mínimos existen?

La única decisión posible es escoger una de las aristas de peso 2:

$$
EB \quad \text{o} \quad BF.
$$

Ambas producen un árbol con el mismo costo.

Por lo tanto,

$$
\boxed{2}
$$

árboles generadores mínimos.

---

## c) Orden de adición de las aristas y corte que justifica su elección

| Paso | Arista | Corte |
|------|---------|--------|
|1|$$AE$$|$$\{A\}\ \mid\ \{B,C,D,E,F,G,H\}$$|
|2|$$EF$$|$$\{F\}\ \mid\ \{A,B,C,D,E,G,H\}$$|
|3|$$EB$$ (o $$BF$$)|$$\{B\}\ \mid\ \{A,C,D,E,F,G,H\}$$|
|4|$$FG$$|$$\{G\}\ \mid\ \{A,B,C,D,E,F,H\}$$|
|5|$$GH$$|$$\{H\}\ \mid\ \{A,B,C,D,E,F,G\}$$|
|6|$$CG$$|$$\{C\}\ \mid\ \{A,B,D,E,F,G,H\}$$|
|7|$$GD$$|$$\{D\}\ \mid\ \{A,B,C,E,F,G,H\}$$|

---

## Respuestas finales

**a)**

$$
\boxed{19}
$$

**b)**

$$
\boxed{2}
$$

**c)**

Un orden válido de Kruskal es:

$$
AE,\ EF,\ EB,\ FG,\ GH,\ CG,\ GD.
$$

También es válido:

$$
AE,\ EF,\ BF,\ FG,\ GH,\ CG,\ GD.
$$



## Solución 2

Sea un grafo no dirigido con $n$ vértices y $k$ componentes conexas.

Sabemos que una componente conexa con $n_i$ vértices necesita **al menos** un árbol para que todos sus vértices permanezcan conectados. Un árbol con $n_i$ vértices tiene exactamente

$$
n_i-1
$$

aristas.

La palabra **al menos** es importante, porque una componente puede tener más aristas si contiene ciclos, pero nunca menos de $n_i-1$, ya que dejaría de ser conexa.

Si las $k$ componentes tienen

$$
n_1,n_2,\ldots,n_k
$$

vértices, entonces el número mínimo de aristas del grafo es

$$
(n_1-1)+(n_2-1)+\cdots+(n_k-1).
$$

Como

$$
n_1+n_2+\cdots+n_k=n,
$$

se obtiene

$$
(n_1-1)+(n_2-1)+\cdots+(n_k-1)
=(n_1+n_2+\cdots+n_k)-k
=n-k.
$$

Por lo tanto, cualquier grafo no dirigido con $n$ vértices y $k$ componentes conexas tiene **al menos**

$$
\boxed{n-k}
$$

aristas.

Si alguna componente contiene ciclos, tendrá más de $n_i-1$ aristas, por lo que la desigualdad sigue cumpliéndose.


## Solución 3


Supongamos, por contradicción, que existen dos árboles generadores mínimos distintos, $T_1$ y $T_2$.

Como todos los pesos de las aristas son distintos, podemos ordenarlos de manera única como

$$
w(a)<w(b)<w(c)<\cdots<w(e)<w(f).
$$

Para que existan dos árboles generadores mínimos distintos, en algún paso debería existir una elección entre dos aristas, por ejemplo $e$ y $f$.

Sin embargo, por la condición anterior,

$$
w(e)\neq w(f),
$$

y además una de ellas debe cumplir

$$
w(e)<w(f)
\quad \text{o} \quad
w(f)<w(e).
$$

Por lo tanto, el algoritmo de Kruskal siempre seleccionará primero la arista de menor peso, sin posibilidad de empate.

Esto contradice la existencia de dos árboles generadores mínimos distintos.

En consecuencia,

$$
\boxed{\text{el árbol generador mínimo es único}.}
$$


## Solución 4a

Sea $e$ la arista de mayor peso del grafo. Como el grafo tiene más de $|V|-1$ aristas, existe al menos un ciclo.

Supongamos, por contradicción, que $e$ pertenece a un árbol generador mínimo (MST).

Como $e$ pertenece a un ciclo, existe otro camino entre los extremos de $e$ formado por las demás aristas del ciclo.

Además, como $e$ es la arista de mayor peso, se cumple que para cualquier otra arista $f$ del ciclo,

$$
w(f)<w(e).
$$

Por lo tanto, es posible eliminar $e$ y reemplazarla por una arista de menor peso del mismo ciclo, manteniendo el grafo conectado y obteniendo un árbol con menor costo.

Esto contradice que el árbol original fuera un árbol generador mínimo.

En consecuencia,

$$
\boxed{\text{La arista de mayor peso no pertenece a ningún árbol generador mínimo.}}
$$

## Solución 4b

La afirmación es **verdadera**.

Sea $e$ la arista de menor peso del grafo. Como su peso es único, no existe otra arista con un peso menor o igual.

Al ejecutar el algoritmo de Kruskal, las aristas se consideran en orden creciente de peso. Por lo tanto, la primera arista evaluada será $e$.

Como al inicio del algoritmo no existe ningún ciclo, la arista $e$ será agregada al árbol.

En consecuencia, $e$ pertenece a todo árbol generador mínimo.

$$
\boxed{\text{La afirmación es verdadera.}}
$$

## Solución 4c

La afirmación es **verdadera**.

Supongamos que la arista $e$ pertenece a un árbol generador mínimo (MST).

Si eliminamos la arista $e$, el árbol se divide en dos componentes conexas, las cuales definen un corte del grafo.

Supongamos, por contradicción, que existe otra arista $f$ que cruza ese mismo corte y cumple

$$
w(f)<w(e).
$$

Entonces podríamos reemplazar la arista $e$ por la arista $f$. El grafo seguiría siendo un árbol generador, pero tendría un costo menor.

Esto contradice que el árbol original sea un árbol generador mínimo.

Por lo tanto, no puede existir una arista de menor peso que cruce ese corte. En consecuencia, $e$ debe ser una arista de peso mínimo a través de algún corte de $G$.

$$
\boxed{\text{La afirmación es verdadera.}}
$$


## Solución 4d

La afirmación es **falsa**.

Considere el siguiente grafo:

```text
      2
A -------- B
 \        /
1 \      / 1
   \    /
     C
```

Los pesos de las aristas son:

$$
w(AB)=2,\qquad w(AC)=1,\qquad w(CB)=1.
$$

Entre los vértices $A$ y $B$ existen dos caminos más cortos con el mismo costo:

- $A-B$, de costo

$$
2,
$$

- $A-C-B$, de costo

$$
1+1=2.
$$

El único árbol generador mínimo está formado por las aristas $AC$ y $CB$, con costo total

$$
1+1=2.
$$

Por lo tanto, el camino $A-B$, aunque es un camino más corto entre $A$ y $B$, **no pertenece a ningún MST**.

Esto contradice la afirmación.

En consecuencia,

$$
\boxed{\text{La afirmación es falsa.}}
$$


# Propiedades de los Árboles Generadores Mínimos (MST)

## 1. Propiedad del corte (Cut Property)

Sea $(S,V-S)$ un corte del grafo.

La arista de menor peso que cruza ese corte pertenece a algún árbol generador mínimo.

Si dicha arista es la única de menor peso que cruza el corte, entonces pertenece a todo MST.

---

## 2. Propiedad del ciclo (Cycle Property)

Sea un ciclo del grafo.

La arista de mayor peso del ciclo no puede pertenecer a ningún árbol generador mínimo.

Si es la única arista de peso máximo del ciclo, entonces no pertenece a ningún MST.

---

## 3. Propiedad de Kruskal

El algoritmo de Kruskal considera las aristas en orden creciente de peso.

Una arista se agrega al árbol únicamente si no forma un ciclo con las aristas ya seleccionadas.

El algoritmo termina cuando el árbol tiene

$$
|V|-1
$$

aristas.

---

## 4. Propiedad de los árboles

Todo árbol con

$$
n
$$

vértices tiene exactamente

$$
n-1
$$

aristas.

---

## 5. Propiedad de los grafos conexos

Todo grafo conexo con más de

$$
n-1
$$

aristas contiene al menos un ciclo.

---

## 6. Propiedad de unicidad del MST

Si todos los pesos de las aristas son distintos, entonces el árbol generador mínimo es único.

---

## 7. Propiedad de intercambio

Si un MST contiene una arista $e$ y existe otra arista $f$ que conecta las mismas componentes con menor peso,

$$
w(f)<w(e),
$$

entonces es posible reemplazar $e$ por $f$ y obtener un árbol de menor costo, lo cual contradice que el árbol inicial sea un MST.

Esta propiedad suele utilizarse en demostraciones por contradicción.

---

## 8. Propiedad del camino en un árbol

Entre dos vértices de un árbol existe un único camino simple.

---

## 9. Propiedad del camino más corto (cuando aplica)

Sea $P$ un camino más corto entre dos vértices.

Si una arista de $P$ pudiera reemplazarse por otra de menor peso que conecte las mismas componentes, existiría un camino de menor costo, contradiciendo que $P$ sea un camino más corto.

**Esta propiedad no debe aplicarse cuando existen empates entre caminos más cortos.**


## Solución 5

La afirmación es **verdadera**.

Sea $e$ una arista de peso máximo perteneciente a un ciclo de $G$.

Supongamos que un árbol generador mínimo $T$ contiene a $e$.

Al eliminar la arista $e$, el árbol $T$ se divide en dos componentes conexas.

Como $e$ pertenece a un ciclo, existe otra arista $f$ del mismo ciclo que conecta nuevamente esas dos componentes.

Además, como $e$ es una arista de peso máximo del ciclo,

$$
w(f)\leq w(e).
$$

Si reemplazamos $e$ por $f$, obtenemos nuevamente un árbol generador.

Como

$$
w(f)\leq w(e),
$$

el costo del nuevo árbol no aumenta. Por lo tanto, el nuevo árbol también es un árbol generador mínimo y no contiene la arista $e$.

En consecuencia, existe un árbol generador mínimo de

$$
G'=(V,E\setminus\{e\})
$$

que también es un árbol generador mínimo de $G$.

$$
\boxed{\text{Existe un MST que no contiene la arista } e.}
$$


## Solución 6

La afirmación es **verdadera**.

Sea $T$ un árbol generador mínimo de $G$. Como $T$ es un árbol, es conexo y no contiene ciclos.

Sea $T'$ el subgrafo inducido por $V'$. Como $T'$ es un subgrafo de un árbol, tampoco contiene ciclos. Además, por hipótesis, $T'$ es conexo. Por lo tanto, $T'$ también es un árbol.

Supongamos, por contradicción, que $T'$ no es un árbol generador mínimo de $G'$.

Entonces existe otro árbol generador $S$ de $G'$ cuyo costo total es menor que el de $T'$.

Si reemplazamos las aristas de $T'$ por las de $S$ dentro de $T$, obtenemos un árbol generador de $G$ con un costo total menor que el de $T$.

Esto contradice que $T$ sea un árbol generador mínimo de $G$.

Por lo tanto, la suposición es falsa y se concluye que

$$
\boxed{T' \text{ es un árbol generador mínimo de } G'.}
$$


# Ejercicio 7

## a) ¿Cambia el MST?

**Respuesta:** No cambia.

### Demostración

Sea $T$ un árbol generador mínimo de $G$.

Todo árbol generador posee exactamente

$$
|V|-1
$$

aristas.

Al aumentar en $1$ el peso de cada arista, el costo de cualquier árbol generador aumenta exactamente en

$$
|V|-1.
$$

Es decir, si el costo original de un árbol generador es $C$, su nuevo costo será

$$
C+(|V|-1).
$$

Como todos los árboles generadores aumentan exactamente la misma cantidad, el árbol que tenía el menor costo continúa siendo el de menor costo.

Por lo tanto,

$$
\boxed{\text{el MST no cambia}.}
$$

---

## b) ¿Cambian los caminos más cortos?

**Respuesta:** Sí, pueden cambiar.

### Contraejemplo

Considere el siguiente grafo:

```text
      3
A -------- B
 \        /
1 \      / 1
   \    /
     C
```

Los pesos iniciales son

$$
w(AB)=3,\qquad
w(AC)=1,\qquad
w(CB)=1.
$$

Inicialmente, el camino más corto entre $A$ y $B$ es

$$
A\rightarrow C\rightarrow B,
$$

con costo

$$
1+1=2.
$$

Después de aumentar todos los pesos en $1$, se obtiene

$$
w'(AB)=4,\qquad
w'(AC)=2,\qquad
w'(CB)=2.
$$

Ahora:

- El camino directo $A-B$ tiene costo

$$
4.
$$

- El camino $A-C-B$ tiene costo

$$
2+2=4.
$$

Por lo tanto, el camino más corto cambia, ya que ahora existen dos caminos mínimos con el mismo costo.

En consecuencia,

$$
\boxed{\text{los caminos más cortos sí pueden cambiar}.}
$$