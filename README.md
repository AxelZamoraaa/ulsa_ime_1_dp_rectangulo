# Práctica 3: Área y perímetro de un rectángulo
## 1. Descripción del problema (Fase 1)
Pide el ancho y e alto de un rectangulo para con eso se usa para poder calcular el area y el perimetro, tambien rechazando el 0 y los numeros negativos
_____

## 2. Entradas y salidas (Fase 1)

**Entradas:**
1. ancho: numero decimal con double, que tiene que ir en cm el cual es la base 
2. alto: numero decimal con double, que tiene que ir en cm el cual es la altura

**Salidas:**
1. area: numero decimal con double en cm sobre el espacio que ocupa el rectangulo
2. perimetro: numero decimal con double en cm que es todo el contorno del rectangulo

**Fórmulas** (área y perímetro):
area= base*altura
perimetro= (base + altura)* 2

## 3. Restricciones e invariante (Fase 1 y 2)

**Restricciones** (¿qué debe cumplirse?):
- la base debe ser mas que 0
- la altura debe ser mas que 0 

**¿Qué hace mi programa con una medida de 0 o negativa? ¿Por qué?**
la rechaza ya que en el codigo dice que debe ser mayor a 0 sino se pide de nuevo el numero 

**¿Quién detecta cada error?** (¿qué revisa `leerDecimal` y qué reviso yo?)
leerDecimal lee que lo que se escribió sea un numero, y yo teviso con el while que el numero sea mayor a 0

**Invariante** (al salir del ciclo que pide el ancho, ¿qué es seguro sobre `ancho`?):
que ancho sea mayor a 0 y que sea un numero

## 4. Casos resueltos a mano (Fase 1)

| Caso | Ancho | Alto | Área calculada a mano | Perímetro calculado a mano |
|---|---|---|---|---|
| 1 | rectangulo | 5 | 10 | 50 | 30 |
| 2 (cuadrado) | 10 | 10 | 100 | 40 |
| 3 (con decimales) | 2.5 | 8.2 | 20.5 | 21.4 |

## 5. Receta en pseudocódigo (Fase 2)
<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con un caso válido y uno inválido?** Sí 
**¿Tuve que corregirla?** puse el paso de que vuelva a pedir el numero cuand es 0 o negativo
**¿Cuántas versiones de mi receta escribí hasta la final?** 2 o 3 mas o menos

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o rectangulo
./rectangulo
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con un caso normal. -->

```
Area y perimetro de un rectangulo
Escribe la base del rectangulo en cm: 5
Escribe la altura del rectangulo en cm: 10
El area:50 cm2

El perimetro:30 cm

Tus medidas forman un rectangulo
fin del programa
```

## 8. Experimentos (Fase 3)

**Experimento A: ¿qué resultado dio `2 * ancho + alto` con 5 × 3? ¿Por qué?**
hace primero el 2*5 y el resultado de eso lo suma a 3, por eso se necesitan los parentesis para que primero sume y luego multiplique por 2

**Experimento B: sin validación, ¿qué mostró el programa con ancho -4 y alto 3? ¿Tiene sentido?**
puso que no se puede al poner el ancho porque el numero tiene que ser mayor a 0

**Experimento C (opcional): con `int`, ¿qué pasó con 2.5 y con 100000 × 100000?**
si solo es int al poner 2.5 se eliminan los decimales y se deja en 2, y con 10000 x 100000 no puede estar dentro de int entonces lo marca como incorrcto

## 9. Tabla de pruebas (Fase 4)

| Caso | Ancho | Alto | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|---|
| Normal | 5 | 3 | Área 15, perímetro 16 | Área 15, perímetro 16 | si |
| Cuadrado | 4 | 4 | Área 16, perímetro 16 |  Área 16, perímetro 16 | si |
| Decimales | 2.5 | 4 | Área 10, perímetro 13 | Área 10, perímetro 13 | si |
| Muy pequeño | 0.1 | 0.1 | Área 0.01, perímetro 0.4 | Área 0.01, perímetro 0.4 | si |
| Ancho cero | 0 | 3 | vuelve a pedir el ancho | se pide otra ves el numero | si |
| Alto negativo | 5 | -2 | vuelve a pedir el alto | vuelve a pedir el numero, al momento de poner el negativo  | si |
| Texto | `abc` | 3 | `leerDecimal` vuelve a pedir | se vuelve a pedir el numero porque no acepta letras | si |
| Caso propio 1 | 10 | 2.5 | area 25 perimetro 25 | area 25 perimetro 25 | si |
| Caso propio 2 |123|234| area 28782 perimetro 714 | area 28782 perimetro 714 | si |

## 10. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | al principio aceptada 0 | puse el while para que vuelva a pedir el numero | si |
| 2 | quise que se vieran las unidades al momento de ejecutarlo | puse una variable que es string unidad para q lo mostrara | si |

**Reto elegido (opcional):** _____

## 11. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| si se podria hacer que acepte 2 numeros negativos o algo parecido | nada |

## 12. Reflexión final

**¿Qué aprendí con esta práctica?**
que sirve mucho escribir la receta antes de empesar a hacer el codigo para así ya tener una base en la cual empezar a formar el codigo

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
pensar desde un principio en los casos invalidos que puedan haber como el 0 y los negativos

**¿Qué fue lo más difícil y cómo lo resolví?**
que no aceptara 0 ni negativos, usando un while para que pidiera otra vez el numero

**¿Qué pregunta me quedó sin responder?**
si se puede hacer que los 2 numeros sean negativos o algo parecido

**Diseñar la receta desde cero, ¿fue más fácil o más difícil de lo que esperaba? ¿Qué haría distinto la próxima vez?**
mas facil, si intentar empezar por la receta y por lo que yo creo que no se puede meter en la receta como el 0 y negativos en este caso

## 13. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené todas las secciones (no quedan `_____`)
- [ ] Escribí mi receta completa en `RECETA.md` antes de programar
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 3 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Entregué el enlace de mi fork en Classroom