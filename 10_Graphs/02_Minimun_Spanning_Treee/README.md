# Minimum Spanning Trees (MST)

## Definición de un grafo

Un grafo se define como

$$
G = (V, E),
$$

donde:

- $V$ es el conjunto de vértices (nodos).
- $E$ es el conjunto de aristas (conexiones entre pares de vértices).

---

## ¿Qué es un Spanning Tree?

Dado un grafo conectado $G=(V,E)$, un **spanning tree** es un subgrafo

$$
T = (V, E_T),
$$

tal que

$$
E_T \subseteq E,
$$

y cumple las siguientes propiedades:

1. Conecta todos los vértices.
2. No contiene ciclos.

En otras palabras, utiliza todos los vértices del grafo original, pero posiblemente menos aristas.

---

## ¿Puede el spanning tree ser el mismo grafo?

Sí.

Si el grafo original ya es un árbol (es decir, está conectado y no tiene ciclos), entonces:

$$
T = G.
$$

En ese caso, el propio grafo es su único spanning tree.

---

## Propiedad fundamental

Todo árbol con $|V|$ vértices tiene exactamente

$$
|E_T| = |V| - 1
$$

aristas.

Intuición:

- Si tuviera menos aristas, no estaría conectado.
- Si tuviera más aristas, existiría al menos un ciclo.

---

## Peso de una arista

Sea

$$
w : E \rightarrow \mathbb{R},
$$

una función que asigna un peso a cada arista.

Para una arista $(u,v)$,

$$
w(u,v)
$$

representa el costo de conectar los vértices $u$ y $v$.

Dependiendo del problema, este costo puede representar:

- distancia,
- dinero,
- tiempo,
- longitud de cable,
- latencia.

---

## Peso de un árbol

El peso total de un spanning tree $T$ se define como

$$
\mathrm{weight}(T)
=
\sum_{(u,v)\in E_T} w(u,v).
$$

Esta expresión significa:

> "Sumar el costo de todas las aristas que pertenecen al árbol."

Es importante notar que esta fórmula **no define el MST**; únicamente calcula cuánto cuesta un árbol dado.

---

## ¿Dónde aparece el "minimum"?

Mi duda inicial fue:

> Si estamos hablando de un *Minimum* Spanning Tree, ¿no debería aparecer un mínimo en la fórmula?

La respuesta es sí.

La diapositiva define primero el costo de un árbol cualquiera:

$$
\mathrm{weight}(T)
=
\sum_{(u,v)\in E_T} w(u,v),
$$

pero el verdadero problema del MST consiste en encontrar el árbol cuyo costo total sea mínimo.

Formalmente,

$$
T^{*}
=
\arg\min_{T}
\sum_{(u,v)\in E_T} w(u,v),
$$

sujeto a que:

$$
T \text{ sea conectado},
$$

y

$$
T \text{ no contenga ciclos}.
$$

Equivalentemente,

$$
T^{*}
=
\arg\min_{T \in \mathcal{S}}
\mathrm{weight}(T),
$$

donde $\mathcal{S}$ representa el conjunto de todos los spanning trees posibles del grafo.

---

## Interpretación personal

Al principio pensé que un MST consistía en "construir un árbol".

Sin embargo, ahora me parece más preciso entenderlo así:

> Un MST toma una red ya existente y elimina todas las conexiones redundantes, manteniendo la conectividad completa con el menor costo posible.

Desde esta perspectiva, algoritmos como **Kruskal** y **Prim** no crean arbitrariamente un árbol; más bien, descubren cuáles son las conexiones verdaderamente esenciales para mantener la red funcionando al menor costo.