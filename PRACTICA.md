# Práctica: Área y perímetro de un rectángulo

## Sobre esta práctica

**Problema:** escribir un programa en C++ que pida al usuario el ancho y el alto de un rectángulo y muestre su **área** y su **perímetro**. Si alguna medida no tiene sentido (0 o negativa), el programa debe volver a pedirla.

**Lo que vas a practicar:** entrada-proceso-salida, variables y tipos de datos, expresiones aritméticas y precedencia de operadores, iteración con decisión (volver a pedir un dato inválido), el uso de una función ya construida, y la restricción y la invariante de un algoritmo.

**Idea central:** en las prácticas anteriores te dimos parte de la receta. **Esta vez la receta es completamente tuya.** El problema es sencillo a propósito: el reto no es la fórmula, sino diseñar tú solo(a) todos los pasos antes de escribir código. Igual que antes, tu meta no es solo que el programa funcione, sino que entiendas **por qué funciona** y **cómo lo construiste**. Responde cada pregunta por escrito en tu `README.md` antes de avanzar a la siguiente fase.

**Repositorio base:** https://github.com/narizwallace/ulsa_ime_1_dp_rectangulo

**Entregable:** el enlace a tu repositorio, publicado en Google Classroom.

**El proceso que vas a seguir:**

| Fase | Qué haces |
|---|---|
| 0 | Preparar tu entorno (fork y clonar) |
| 1 | Entender el problema |
| 2 | Diseñar la solución como una receta detallada (esta vez, desde cero) |
| 3 | Implementar |
| 4 | Probar y mejorar |
| 5 | Publicar en GitHub |

**Cómo usar el `README.md`:** ya viene en el repositorio base con espacios en blanco (`_____`). Lo vas llenando fase por fase, así no tienes que preguntarte qué va en él. Cada fase de esta guía te indica qué secciones llenar. No es necesario que uses el archivo README.md, también puedes copiar el contenido y hacerlo en un editor de texto de tu elección. Solo asegúrate de subir el archivo equivalente a tu repositorio.


## Fase 0. Preparar tu entorno

1. Entra al repositorio base: https://github.com/narizwallace/ulsa_ime_1_dp_rectangulo
2. Haz clic en **Fork** (arriba a la derecha) para crear tu propia copia en tu cuenta de GitHub.
3. En tu fork, haz clic en **Code**, copia la URL y clónalo en tu computadora.

Estos son los comandos para clonar un repositorio desde tu terminal o línea de comando:
```bash
git clone <URL-de-tu-fork>
cd ulsa_ime_1_dp_rectangulo
```
También puedes hacer el clone desde GitHub Desktop como lo hemos hecho antes.


4. Abre la carpeta en tu editor y revisa los archivos:

```
ulsa_ime_1_dp_rectangulo/
├── README.md      ← plantilla con espacios en blanco para llenar
├── PRACTICA.md    ← este documento
├── RECETA.md      ← vacío: aquí escribes TU receta completa
├── main.cpp       ← punto de partida de tu programa
├── utilerias.h    ← función de apoyo para leer números (no lo modifiques)
└── .gitignore     ← evita subir el ejecutable
```

**Todo tu trabajo va dentro de esta carpeta.**

> **Nota técnica: una función hermana de `leerEntero`.**
> En la práctica anterior usaste `leerEntero`, que solo acepta enteros. Un rectángulo puede medir 2.5 cm, así que en `utilerias.h` ahora está `leerDecimal`. Funciona igual: pide un número y no avanza hasta que el usuario escriba uno válido, pero acepta decimales y devuelve un `double`. Se usa así:
> `double ancho = leerDecimal("Ancho en cm: ");`
> **Pregunta guía:** lee los comentarios de `utilerias.h`. ¿Qué recibe `leerDecimal`? ¿Qué devuelve? ¿Qué **no** revisa?

---

## Fase 1. Entender el problema

*Aquí no se escribe código. Llena las secciones 1 a 4 de tu `README.md`.*

**Preguntas guía**

1. Explica el problema con tus palabras, en una o dos frases.
2. ¿Cuáles son las entradas? ¿Cuántas son y de qué tipo de dato?
3. ¿Cuáles son las salidas? ¿Cuántas son?
4. ¿Cómo se calcula el área? ¿Y el perímetro? Escribe las fórmulas y explícalas con un dibujo en papel: ¿de dónde sale cada una?
5. ¿Entiendes el problema? Compruébalo: explícaselo a un compañero en 1 minuto, sin mirar tus notas.
6. ¿Dónde aparece este cálculo en mecatrónica? (el área de una placa de circuito, la lámina que se debe cortar para un gabinete, el perímetro de un marco...).

**Restricciones: ¿qué debe cumplirse?**

- ¿Puede un rectángulo medir 0 de ancho? ¿Y -3? ¿Qué debe hacer tu programa si el usuario los escribe?
- `leerDecimal` acepta decimales. ¿Por qué tiene sentido para medir un rectángulo, a diferencia de la práctica anterior?
- ¿En qué unidades trabaja tu programa? ¿Qué unidades tiene el área y cuáles el perímetro?

**Resuelve a mano 3 casos:** uno normal, un cuadrado y uno con decimales. Los usarás como pruebas más adelante.

> **Nota técnica: una fórmula no es un programa.**
> Saber que el área es ancho × alto resuelve solo una pequeña parte del problema. El resto es decidir qué pedir, en qué orden, qué hacer con datos inválidos y cómo mostrar el resultado. Eso es lo que vas a diseñar en la Fase 2.

---

## Fase 2. Diseñar la receta

*Escribe tu receta completa en `RECETA.md`. Llena las secciones 3 y 5 de tu `README.md`.*

> **Nota técnica: esta vez no hay espacios en blanco.**
> En las prácticas anteriores completabas una receta ya iniciada. Ahora partes de una hoja vacía. Es normal que tu primera versión tenga huecos o pasos de más; para eso existe la prueba a mano. Una receta que corregiste tres veces no es un fracaso: es exactamente el proceso.

**Preguntas que te ayudan a construir la receta**

- ¿Qué es lo primero que ve el usuario al ejecutar el programa?
- ¿Qué datos pides y en qué orden?
- Si el usuario escribe 0 o un negativo, ¿cómo vuelves a pedir el dato? ¿El ciclo debe revisar la condición antes o después de leer?
- ¿Cuántas veces puede equivocarse el usuario? ¿Tu receta lo soporta?
- ¿El cálculo se hace antes o después de validar? ¿Por qué importa el orden?
- ¿Qué muestras al final y con qué mensaje? ¿Incluyes las unidades?

**Vocabulario de pseudocódigo** (úsalo como referencia, no es una receta):

```
MOSTRAR "mensaje"                LEER variable
variable ← expresión             variable ← leerDecimal("mensaje")
SI condición ENTONCES ... SINO ... FIN SI
MIENTRAS condición HACER ... FIN MIENTRAS
REPETIR ... HASTA QUE condición
```

**¿Cómo sé si mi receta es buena?** Revísala con estas preguntas:

- ¿Otra persona podría seguirla sin preguntarte nada?
- ¿Cada paso hace una sola cosa?
- ¿Cubre qué pasa con un dato inválido?
- ¿Tiene un inicio y un fin claros?

> **Nota técnica: dos niveles de validación.**
> `leerDecimal` revisa el **formato**: que lo escrito sea un número (rechaza `abc` o `12abc`). Pero `-3` sí es un número, así que lo deja pasar. Revisar el **rango** (que la medida tenga sentido para un rectángulo) es trabajo tuyo. Pregúntate siempre: ¿quién detecta este error, la función o mi programa?

> **Nota técnica: la invariante sin contador.**
> En las prácticas anteriores la invariante vivía en un ciclo con contador. Aquí, tu ciclo de validación también tiene una.
> **Pregunta guía:** cuando el programa sale del ciclo que pide el ancho, ¿qué es seguro sobre el valor de `ancho`? Escríbelo como una frase que siempre se cumple. ¿Por qué esa frase te permite calcular el área sin preocuparte?

**Prueba tu receta a mano** con tus 3 casos y con un caso inválido (por ejemplo, ancho = -2 y luego ancho = 5). Anota cómo cambia cada variable paso a paso. Si algo no cuadra, corrige la receta ahora, no el código después.

---

## Fase 3. Implementar

*Trabaja sobre `main.cpp`. Llena las secciones 6, 7, 8 y 11 de tu `README.md`.*

**Preguntas guía**

- ¿Has pensado cómo dividir la implementación en pasos pequeños?
- ¿Qué variables necesitas y de qué tipo será cada una? ¿Con qué valor empiezan?
- ¿Cada paso de tu receta tiene su línea (o líneas) de código? Si no, ¿qué falta: la receta o el código?

**Así se ve tu punto de partida en `main.cpp`** (esta vez con menos ayuda):

```cpp
// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Por qué este include usa comillas y no < >?
#include "utilerias.h"

// ¿por qué debe existir la función main()?
int main() {
    // 1. Variables (siempre inicializadas)
    //    TODO: ¿qué variables necesitas? ¿De qué tipo? ¿Con qué valor empiezan?

    std::cout << "Area y perimetro de un rectangulo\n";

    // 2. Entrada: el ancho
    //    TODO: lee el ancho con leerDecimal("...")
    //    TODO: ¿qué haces si es 0 o negativo? ¿Cuántas veces lo vuelves a pedir?

    // 3. Entrada: el alto
    //    TODO: mismo criterio que el ancho

    // 4. Proceso
    //    TODO: calcula el área y el perímetro
    //    ¿Estás seguro(a) del orden en que C++ hace las operaciones?

    // 5. Salida
    //    TODO: muestra el área y el perímetro, con sus unidades

    // ¿Qué significa return 0;?
    return 0;
}
```

**Construye en pasos pequeños.** Compila y prueba después de cada uno:

1. Leer el ancho y el alto con `leerDecimal` y mostrarlos.
2. Calcular y mostrar el área.
3. Calcular y mostrar el perímetro (haz aquí el Experimento A).
4. Haz el Experimento B **antes** de validar.
5. Agregar la validación del ancho.
6. Agregar la validación del alto.

**Para compilar y ejecutar:**

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o rectangulo
./rectangulo
```

> **Nota de C++: precedencia de operadores.**
> **Experimento A (obligatorio):** escribe el perímetro como `2 * ancho + alto` y prueba con 5 × 3. ¿Qué resultado obtienes y cuál esperabas? ¿Por qué? Corrígelo con paréntesis. En C++, `*` y `/` se evalúan antes que `+` y `-`, igual que en matemáticas. Regla práctica: si dudas del orden, usa paréntesis; además hacen el código más claro para quien lo lea.

> **Nota de C++: el error más peligroso es el silencioso.**
> **Experimento B (obligatorio):** antes de agregar la validación, ejecuta con ancho = -4 y alto = 3. ¿Qué área y perímetro muestra? ¿Tienen sentido físico? El programa "funciona", no se detiene ni marca error, pero entrega un resultado incorrecto sin avisar. Por eso validamos.

> **Nota de C++: `do-while`, el ciclo que se ejecuta al menos una vez.**
> Además de `while` (revisa la condición **antes** de entrar) existe `do { ... } while (condición);`, que revisa la condición **después** de ejecutar el bloque. Piensa cuál corresponde a tu receta: ¿necesitas leer el dato al menos una vez antes de poder revisarlo? Cualquiera de los dos puede funcionar si tu receta es coherente.

> **Nota de C++: `int` vs. `double`.**
> **Experimento C (opcional):** declara `ancho` y `alto` como `int` (sigue leyéndolos con `leerDecimal`). Prueba con 2.5 × 4: ¿qué área obtienes? Observa que el compilador **no** te avisa, aunque compiles con `-Wall -Wextra`. Después prueba con 100000 × 100000: ¿el área es correcta? Investiga qué es un *desbordamiento* (overflow). Vuelve a dejar `double` al terminar.

> **Nota de C++: buenas prácticas.**
> - Usa nombres descriptivos: `ancho`, `alto`, `area`, `perimetro` (evita `a`, `b` o `x`).
> - Inicializa siempre tus variables.
> - Los mensajes al usuario deben decir qué se espera: `"Ancho en cm (mayor que 0): "`.
> - Muestra los resultados con sus unidades: `"Area: 15 cm2"`.
> - Notarás que validas el ancho y el alto casi con el mismo código. Más adelante en el curso verás cómo evitar esa repetición con funciones propias; por ahora, solo toma nota.
> - Comenta el *porqué* de lo que haces, no lo obvio.

**Bitácora de dudas:** ¿qué dudas quieres cubrir con el profesor? Anótalas en la sección 11 de tu `README.md`, junto con lo que ya intentaste para resolverlas.

---

## Fase 4. Probar y mejorar

*Llena las secciones 9 y 10 de tu `README.md`.*

**Tabla de pruebas** (en tu `README.md` completa las columnas "Obtenido" y "¿Pasó?"):

| Caso | Ancho | Alto | Resultado esperado |
|---|---|---|---|
| Normal | 5 | 3 | Área 15, perímetro 16 |
| Cuadrado | 4 | 4 | Área 16, perímetro 16 |
| Decimales | 2.5 | 4 | Área 10, perímetro 13 |
| Muy pequeño | 0.1 | 0.1 | Área 0.01, perímetro 0.4 |
| Ancho cero | 0 (luego 5) | 3 | vuelve a pedir el ancho |
| Alto negativo | 5 | -2 (luego 3) | vuelve a pedir el alto |
| Texto | `abc` (luego 5) | 3 | `leerDecimal` vuelve a pedir el número |

**Agrega al menos 2 casos propios.**

**Preguntas guía**

- En el cuadrado 4 × 4, el área y el perímetro dan el mismo número. ¿Son la misma cosa? ¿Qué los distingue?
- Si el usuario escribe un dato inválido tres veces seguidas, ¿qué hace tu programa?
- En los casos "Ancho cero" y "Texto", ¿quién detectó el error: `leerDecimal` o tu programa?
- ¿Alguna prueba falló? ¿El error estaba en la receta, en el código o en tu cálculo a mano?

**Ciclo de mejora:** identifica → cambia una sola cosa → vuelve a probar todo. Registra cada cambio en tu bitácora de mejoras.

**Retos opcionales (para tu insatisfacción positiva):**

1. Muestra un mensaje que explique **por qué** se rechazó la medida (`"El ancho debe ser mayor que 0"`).
2. Indica si el rectángulo **es un cuadrado**.
3. Calcula la **diagonal** con el teorema de Pitágoras (investiga `std::sqrt` en `<cmath>`).
4. Muestra los resultados siempre con **2 decimales** (investiga `<iomanip>`).
5. Permite calcular **varios rectángulos** hasta que el usuario decida salir.

---

## Fase 5. Publicar en GitHub

1. Verifica que tu `README.md` esté completo, sin `_____` pendientes, que tu `RECETA.md` tenga tu receta final y que tu programa compile sin advertencias.
2. Sube tus cambios a tu fork. Debes tener **al menos 3 commits** hechos durante el trabajo (no uno solo al final), con mensajes que digan qué cambió, por ejemplo: `Agrega receta completa`, `Agrega calculo de area y perimetro`, `Agrega validacion de medidas`.

Con los siguientes comandos puedes hacer un commit y publicarlo desde tu terminal o línea de comando:

```bash
git add .
git commit -m "Agrega validacion de medidas"
git push origin main
```
También puedes usar GitHub Desktop como lo hemos hecho antes.

3. Abre tu repositorio en GitHub y comprueba que ahí aparezcan tu código, tu `RECETA.md` y tu `README.md` actualizados. Tu fork tiene esta forma:
   `https://github.com/<tu-usuario>/ulsa_ime_1_dp_rectangulo`
4. Entrega en Google Classroom el enlace a **tu fork**.

> **Nota técnica: commits pequeños.**
> Cada commit es un punto al que puedes volver si algo sale mal. Confirma cambios cada vez que completes un paso pequeño que funcione, como los de la Fase 3. Te será especialmente útil en los experimentos: si algo se rompe, puedes regresar al último commit.

---

## Cierre y reflexión

*Llena la sección 12 de tu `README.md` antes de entregar.*

1. ¿Qué aprendiste con esta práctica?
2. Ahora que la terminaste, ¿qué cambiarías de tu proceso?
3. ¿Qué fue lo más difícil y cómo lo resolviste?
4. ¿Qué pregunta te quedó sin responder?
5. Diseñar la receta desde cero, ¿fue más fácil o más difícil de lo que esperabas? ¿Qué harías distinto la próxima vez?

---

## Lista de verificación antes de entregar

- [ ] Llené todas las secciones de mi `README.md` (no quedan `_____`)
- [ ] Escribí mi receta completa en `RECETA.md` antes de programar
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 3 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_rectangulo` y el código está en `main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom