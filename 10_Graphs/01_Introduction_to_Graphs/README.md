# Introducción a los Grafos

La teoría de grafos es una rama de las matemáticas discretas que estudia estructuras compuestas por entidades y las relaciones existentes entre ellas. Estas estructuras permiten modelar una gran variedad de problemas, como redes de comunicación, rutas de transporte, circuitos electrónicos y redes sociales.

## Definición Formal

Un grafo se define como un par ordenado:

$$
G=(V,E)
$$

donde:

* $V$ es un conjunto no vacío de vértices (o nodos).
* $E$ es un conjunto de aristas que conectan pares de vértices pertenecientes a $V$.

Los vértices representan las entidades u objetos del problema, mientras que las aristas representan las relaciones o conexiones entre dichas entidades.

## Conceptos Básicos

### Orden del Grafo

El orden de un grafo corresponde a la cantidad de vértices que posee:

$$
|V|
$$

### Tamaño del Grafo

El tamaño de un grafo corresponde a la cantidad de aristas presentes:

$$
|E|
$$

### Grado de un Vértice

El grado de un vértice $v$, denotado por:

$$
d(v)
$$

representa la cantidad de aristas incidentes en dicho vértice.

Por ejemplo, si un vértice está conectado a tres aristas, entonces:

$$
d(v)=3
$$

## Lema del Apretón de Manos (Handshaking Lemma)

Una propiedad fundamental de los grafos establece que la suma de los grados de todos los vértices es igual al doble del número de aristas:

$$
\sum_{v \in V} d(v)=2|E|
$$

Esta propiedad se cumple porque cada arista conecta exactamente dos vértices y, por tanto, contribuye con una unidad al grado de cada uno de sus extremos.

De forma equivalente, el número de aristas puede obtenerse mediante:

$$
|E|=\frac{\sum_{v \in V} d(v)}{2}
$$

## Nota

El conjunto de vértices debe ser no vacío, ya que constituye la base de la estructura del grafo. Sin vértices no existirían elementos que relacionar ni estudiar.

Por otro lado, el conjunto de aristas puede ser vacío. En ese caso, el grafo está formado únicamente por vértices aislados y sigue siendo un grafo válido.

Esta característica refleja la naturaleza discreta de los grafos: los vértices son elementos que pueden identificarse y contarse individualmente, mientras que las aristas representan únicamente la existencia de una relación entre ellos.
