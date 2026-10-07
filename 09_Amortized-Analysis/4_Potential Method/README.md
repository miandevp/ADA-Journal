# The Potential Method: Entendiendo la Función Potencial

## Primera impresión

Cuando vi la fórmula del método del potencial, mi primera reacción fue:

> *"¿Qué es esa función $\Phi$? ¿Por qué le suman y restan cosas al costo real?"*

La intuición detrás del método es mucho más sencilla de lo que parece:

> **La función potencial es una forma de guardar "crédito" o "energía" para pagar operaciones costosas en el futuro.**

En lugar de analizar cada operación de manera aislada, analizamos una secuencia completa de operaciones.

---

## El problema del análisis amortizado

En algunas estructuras de datos, ciertas operaciones son muy baratas y otras son muy costosas.

Por ejemplo:

* Insertar en un arreglo dinámico suele costar

$$
O(1)
$$

* Pero cuando el arreglo se llena y debe redimensionarse, puede costar

$$
O(n).
$$

Si solo observamos la operación costosa, parecería que la estructura es ineficiente.

Sin embargo:

> Lo importante es cuánto cuesta una secuencia larga de operaciones.

Esa es precisamente la idea del **análisis amortizado**.

---

## La fórmula del método del potencial

El costo amortizado de la operación $i$ se define como

$$
\hat{c}_i
=========

c_i
+
\Phi(i)-\Phi(i-1),
$$

donde:

* $\hat{c}_i$: costo amortizado.
* $c_i$: costo real de la operación.
* $\Phi(i)$: potencial después de realizar la operación $i$.
* $\Phi(i-1)$: potencial antes de realizar la operación.

---

## ¿Qué representa $\Phi$?

La función potencial mide la cantidad de "trabajo almacenado".

Podemos imaginarla como una cuenta bancaria.

* Si $\Phi$ aumenta:

> estamos depositando crédito.

* Si $\Phi$ disminuye:

> estamos utilizando crédito previamente acumulado.

Por eso, normalmente se exige que

$$
\Phi(0)=0
$$

y además

$$
\Phi(i)\ge 0,
\quad \forall i,
$$

porque no queremos gastar más crédito del que hemos acumulado.

---

## Interpretación intuitiva

La fórmula

$$
\hat{c}_i
=========

c_i
+
\Phi(i)-\Phi(i-1)
$$

puede leerse como:

> **Costo amortizado = costo real + cambio en la energía almacenada.**

Existen tres situaciones posibles.

### Caso 1: El potencial aumenta

Si

$$
\Phi(i)>\Phi(i-1),
$$

entonces

$$
\Phi(i)-\Phi(i-1)>0.
$$

Por tanto,

$$
\hat{c}_i>c_i.
$$

Interpretación:

> Estamos pagando un poco más ahora para ahorrar crédito para el futuro.

---

### Caso 2: El potencial disminuye

Si

$$
\Phi(i)<\Phi(i-1),
$$

entonces

$$
\Phi(i)-\Phi(i-1)<0.
$$

Por tanto,

$$
\hat{c}_i<c_i.
$$

Interpretación:

> Estamos usando el crédito acumulado anteriormente para cubrir parte del costo actual.

---

### Caso 3: El potencial no cambia

Si

$$
\Phi(i)=\Phi(i-1),
$$

entonces

$$
\hat{c}_i=c_i.
$$

Interpretación:

> El costo amortizado coincide exactamente con el costo real.

---

## Diferencia de potencial

La diapositiva define

$$
\Delta\Phi(i)
=============

\Phi(i)-\Phi(i-1).
$$

Por lo tanto, la fórmula puede escribirse de manera más compacta como

$$
\hat{c}_i
=========

c_i+\Delta\Phi(i).
$$

Esta forma deja claro que lo único que importa es cuánto cambia el potencial entre dos operaciones consecutivas.

---

## ¿Por qué funciona?

Si sumamos el costo amortizado de $n$ operaciones obtenemos

$$
\sum_{i=1}^{n}\hat{c}_i
=======================

\sum_{i=1}^{n}c_i
+
\sum_{i=1}^{n}
\left(
\Phi(i)-\Phi(i-1)
\right).
$$

La segunda suma se simplifica a

$$
\sum_{i=1}^{n}\hat{c}_i
=======================

\sum_{i=1}^{n}c_i
+
\bigl(\Phi(n)-\Phi(0)\bigr).
$$

Esto ocurre porque los términos intermedios se cancelan:

$$
(\Phi(1)-\Phi(0))
+
(\Phi(2)-\Phi(1))
+
(\Phi(3)-\Phi(2))
+\cdots+
(\Phi(n)-\Phi(n-1)).
$$

Todo desaparece excepto

$$
\Phi(n)-\Phi(0).
$$

Este fenómeno se conoce como una **suma telescópica**.

---

## Consecuencia importante

Como

$$
\Phi(0)=0
$$

y

$$
\Phi(n)\ge 0,
$$

entonces

$$
\sum_{i=1}^{n}\hat{c}*i
\ge
\sum*{i=1}^{n}c_i.
$$

Es decir,

> El costo amortizado total es una cota superior del costo real total.

Por eso podemos analizar el costo amortizado sin subestimar el trabajo realmente realizado.

---

## Ejemplo intuitivo: una alcancía

Imaginemos que cada operación barata cuesta realmente

$$
1
$$

moneda.

Sin embargo, decidimos cobrar amortizadamente

$$
2
$$

monedas.

Entonces:

* 1 moneda paga la operación actual.
* La otra moneda se guarda como potencial.

Después de muchas operaciones, cuando ocurre una operación muy costosa, utilizamos las monedas ahorradas para pagarla.

---

## Reflexión personal

Al principio veía la función potencial como una expresión matemática misteriosa.

Ahora me parece más natural pensar que:

> La función potencial es simplemente una medida del crédito acumulado por la estructura de datos.

El método del potencial no cambia el costo real de las operaciones.

Lo único que hace es redistribuir ese costo a lo largo del tiempo, cobrando un poco más cuando es conveniente y utilizando ese excedente para cubrir operaciones excepcionalmente costosas.

En otras palabras,

> **El análisis amortizado no intenta hacer que las operaciones sean más baratas; intenta explicar por qué, en promedio, una secuencia larga de operaciones sigue siendo eficiente.**
