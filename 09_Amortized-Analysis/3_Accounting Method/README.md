# The Accounting Method

A diferencia de Aggregate Analysis, donde primero se calcula el costo total \(T(n)\) y luego se divide entre \(n\), el Accounting Method asigna directamente un costo amortizado a cada operación.

La idea es cobrar un poco más a algunas operaciones para ahorrar crédito y utilizarlo posteriormente cuando aparezcan operaciones más costosas.

---

## Intuición

Supongamos tres operaciones con costos reales:

$$
1,\;3,\;5
$$

En lugar de cobrar exactamente su costo real, decidimos cobrar:

$$
3,\;3,\;3
$$

| Operación | Costo Real | Cobro | Crédito |
|------------|------------|--------|----------|
| 1 | 1 | 3 | +2 |
| 2 | 3 | 3 | 0 |
| 3 | 5 | 3 | -2 |

La primera operación utiliza únicamente 1 unidad de trabajo y guarda 2 unidades de crédito.

Más adelante, la tercera operación necesita 5 unidades de trabajo, pero solo paga 3. La diferencia es cubierta utilizando el crédito ahorrado anteriormente.

La idea es redistribuir el costo entre operaciones para que todas parezcan tener un costo similar.

---

## Intuición del Banquero

Una forma clásica de interpretar este método es mediante un banco.

Cada operación paga una tarifa amortizada.

- Una parte del dinero se utiliza para ejecutar la operación.
- El dinero sobrante se deposita en el banco.
- Las operaciones costosas pueden retirar dinero del banco.

La condición fundamental es:

> El saldo del banco nunca debe ser negativo.

Si el banco queda negativo, significa que hemos cobrado menos dinero del necesario para cubrir los costos reales.

---

## Notación Formal

Sea:

$$
t(i)
$$

el costo real (*true cost*) de la operación \(i\).

Sea:

$$
c(i)
$$

el costo amortizado (*amortized cost*) asignado a la operación \(i\).

La diferencia:

$$
c(i)-t(i)
$$

representa el crédito que se deposita en el banco cuando es positiva.

---

## Condición de Validez

Para que el método sea correcto, el crédito acumulado nunca debe ser negativo.

Equivalentemente:

$$
\sum_{i=1}^{n} t(i)
\le
\sum_{i=1}^{n} c(i)
$$

donde:

- \(t(i)\) representa el costo real.
- \(c(i)\) representa el costo amortizado.

Esto significa que el costo amortizado total debe ser suficiente para cubrir el costo real total.

---

### Relación con la Notación Formal

En el ejemplo anterior:

$$
t(i)
$$

representa el costo real de la operación.

$$
c(i)
$$

representa el costo amortizado que decidimos cobrar.

Por ejemplo:

| Operación | \(t(i)\) | \(c(i)\) | Crédito generado |
|------------|------------|------------|------------|
| 1 | 1 | 3 | \(3-1=2\) |
| 2 | 3 | 3 | \(3-3=0\) |
| 3 | 5 | 3 | \(3-5=-2\) |

La primera operación genera un crédito de:

$$
3-1=2
$$

que se deposita en el banco.

La segunda operación no genera ni consume crédito:

$$
3-3=0
$$

La tercera operación necesita dos unidades adicionales:

$$
3-5=-2
$$

por lo que utiliza las dos unidades de crédito que habían sido almacenadas previamente.

El saldo acumulado del banco sería:

$$
+2
$$

después de la primera operación,

$$
+2
$$

después de la segunda,

y finalmente:

$$
+2-2=0
$$

después de la tercera.

Como el saldo nunca fue negativo, el costo amortizado asignado es válido.

Esta es precisamente la idea del Accounting Method: algunas operaciones pagan más de lo que consumen para financiar operaciones futuras que consumen más de lo que pagan.

# Stack Operations using the Accounting Method

Recordemos los costos reales de las operaciones:

$$
t(\text{PUSH})=1
$$

$$
t(\text{POP})=1
$$

$$
t(\text{MULTIPOP}(k))=k
$$

La idea del Accounting Method es cobrar más a las operaciones frecuentes y utilizar ese crédito para pagar operaciones costosas en el futuro.

## Estrategia

Asignamos los siguientes costos amortizados:

$$
c(\text{PUSH})=2
$$

$$
c(\text{POP})=0
$$

$$
c(\text{MULTIPOP})=0
$$

Es decir, cada operación PUSH paga 2 unidades, mientras que POP y MULTIPOP no pagan nada.

---

## ¿Por qué cobrar 2 al PUSH?

El costo real de un PUSH es:

$$
t(\text{PUSH})=1
$$

pero le cobramos:

$$
c(\text{PUSH})=2
$$

Por lo tanto:

$$
2-1=1
$$

unidad de crédito queda disponible.

Ese crédito se almacena junto al elemento insertado.

Visualmente:

```text
PUSH(A)

[A, $1]
```

El elemento A queda almacenado junto con una unidad de crédito.

---

## ¿Qué ocurre durante un POP?

Supongamos que posteriormente ejecutamos:

```text
POP()
```

El costo real es:

$$
t(\text{POP})=1
$$

Sin embargo:

$$
c(\text{POP})=0
$$

La operación no paga nada.

El costo se cubre utilizando el crédito que había sido almacenado previamente junto al elemento.

```text
[A, $1]
   |
   +-----> paga el POP
```

---

## Ejemplo

Consideremos la secuencia:

```text
PUSH(A)
PUSH(B)
POP()
POP()
```

### PUSH(A)

Paga:

$$
2
$$

Consume:

$$
1
$$

Guarda:

$$
1
$$

Saldo:

$$
1
$$

---

### PUSH(B)

Paga:

$$
2
$$

Consume:

$$
1
$$

Guarda:

$$
1
$$

Saldo:

$$
2
$$

---

### POP()

Paga:

$$
0
$$

Utiliza el crédito almacenado por B.

Saldo:

$$
1
$$

---

### POP()

Paga:

$$
0
$$

Utiliza el crédito almacenado por A.

Saldo:

$$
0
$$

---

## Correctitud

Cada elemento insertado deja almacenado exactamente una unidad de crédito.

Además, cada elemento puede ser eliminado como máximo una vez.

Por lo tanto, el crédito almacenado al momento del PUSH es suficiente para pagar una futura operación POP o MULTIPOP que elimine dicho elemento.

Como nunca se utiliza más crédito del que ha sido almacenado previamente, el saldo del banco nunca es negativo.

---

## Conclusión

El costo amortizado asignado a cada PUSH es:

$$
c(\text{PUSH})=2
$$

mientras que POP y MULTIPOP tienen costo amortizado:

$$
0
$$

Por lo tanto, todas las operaciones tienen costo amortizado constante:

$$
O(1)
$$

lo que demuestra que las operaciones sobre un Stack tienen costo amortizado constante mediante el Accounting Method.

# Binary Counter using the Accounting Method

Recordemos que el costo real de un incremento es el número de bits que cambian de valor.

Cada cambio de bit (*bit flip*) tiene costo:

$$
1
$$

unidad de trabajo.

---

## Estrategia

Clasificamos los cambios de bit en dos grupos.

### Cambio económico

$$
0 \rightarrow 1
$$

Cada vez que ocurre este cambio cobramos:

$$
c(0 \rightarrow 1)=2
$$

aunque su costo real es:

$$
t(0 \rightarrow 1)=1
$$

Por lo tanto:

$$
2-1=1
$$

unidad de crédito queda almacenada.

---

### Cambio costoso

$$
1 \rightarrow 0
$$

Estos cambios son gratuitos desde el punto de vista amortizado:

$$
c(1 \rightarrow 0)=0
$$

Cuando ocurren, utilizan el crédito que había sido almacenado previamente.

---

## Intuición

Cada vez que un bit cambia de:

$$
0 \rightarrow 1
$$

- paga su propio cambio,
- y además guarda una unidad de crédito.

Visualmente:

```text
0000 -> 0001
          ^
          |
         $1
```

Más adelante, cuando ese mismo bit cambie de:

$$
1 \rightarrow 0
$$

utilizará el crédito que había almacenado anteriormente.

Por ello, cada bit que vale 1 puede verse como un bit que lleva asociada una unidad de crédito.

---

## Ejemplo

### Incremento

```text
0000 -> 0001
```

Cambio:

$$
0 \rightarrow 1
$$

Pagamos:

$$
2
$$

Costo real:

$$
1
$$

Crédito almacenado:

$$
1
$$

Saldo del banco:

$$
1
$$

---

### Incremento

```text
0001 -> 0010
```

Cambios:

$$
b_0 : 1 \rightarrow 0
$$

$$
b_1 : 0 \rightarrow 1
$$

El cambio:

$$
b_0 : 1 \rightarrow 0
$$

utiliza el crédito que ya tenía almacenado.

El cambio:

$$
b_1 : 0 \rightarrow 1
$$

genera un nuevo crédito.

Por lo tanto, el saldo del banco sigue siendo:

$$
1
$$

---

## Correctitud

Después de \(i\) incrementos, la cantidad de dinero almacenada en el banco es exactamente igual al número de bits con valor 1 en la representación binaria de \(i\).

La razón es simple:

- Cada vez que un bit cambia de

$$
0 \rightarrow 1
$$

se almacena una unidad de crédito.

- Cada vez que un bit cambia de

$$
1 \rightarrow 0
$$

se consume exactamente esa unidad de crédito.

Por lo tanto, existe una correspondencia uno a uno entre:

- créditos almacenados,
- bits que actualmente valen 1.

Luego:

$$
\text{Dinero en el banco}
=
\text{Número de bits en 1}
$$

Como el número de bits en 1 nunca puede ser negativo:

$$
\text{Banco} \ge 0
$$

para cualquier instante.

Por ello, el banco nunca queda en números negativos y el esquema de cobros es válido.

---

## Conclusión

Los cambios:

$$
0 \rightarrow 1
$$

pagan:

- su propio costo,
- y además dejan crédito para el futuro.

Los cambios:

$$
1 \rightarrow 0
$$

utilizan ese crédito previamente almacenado.

Como el banco nunca queda negativo:

$$
\sum_{i=1}^{n} t(i)
\le
\sum_{i=1}^{n} c(i)
$$

Por lo tanto, el costo amortizado por incremento es:

$$
O(1)
$$