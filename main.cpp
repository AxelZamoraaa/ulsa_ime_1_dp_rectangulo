#include <iostream>

#include "utilerias.h"

int main() {

    std::cout << "Area y perimetro de un rectangulo\n";

    std::string unidad = "cm";
    double base = leerDecimal ("Escribe la base del rectangulo en " + unidad + ": ");
    while (base <=0) {
        std::cout << "la base debe ser mayor a 0. Intenta de nuevo.\n";
        base = leerDecimal ("Escribe el ancho: ");
    }

        double altura = leerDecimal ("Escribe la altura del rectangulo en " + unidad + ": ");
    while (altura <=0) {
        std::cout << "la altura debe ser mayor a 0. Intenta de nuevo.\n";
        altura = leerDecimal ("Escribe la altura: ");
    }

    double area = base * altura;
    double perimetro = 2 * (base + altura);

    std::cout << "El area:" << area << " " << unidad << "2\n" << std::endl;
    std::cout << "El perimetro:" << perimetro << " " << unidad << "\n" << std::endl;

    if (base == altura) {
        std::cout << "Tus medidas forman un cuadrado\n";
    } else {
        std::cout << "Tus medidas forman un rectangulo\n";
    }

    std::cout << "fin del programa\n";

    return 0;
}