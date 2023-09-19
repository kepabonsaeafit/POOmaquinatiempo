#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "eventos.h"

int main() {
    eventos listaEventos;

    // Genera eventos
    for (int i = 0; i < 10; i++) {
        int datos = rand() % 100; // Genera datos aleatorios (puedes ajustar el rango)
        std::string cientifico = "Einstein"; // Cambia el cientÃ­fico segÃºn sea necesario
        listaEventos.agregarEvento(datos, cientifico);
    }

    // Muestra los eventos antes de aplicar restricciones
    std::cout << "Nodos =\n";
    listaEventos.mostrarEventos();
    std::cout << std::endl;

    // Aplica restricciones
    listaEventos.aplicarRestricciones();

    // Muestra la lista de eventos despuÃ©s de aplicar restricciones
    std::cout << "Nodos =\n";
    listaEventos.mostrarListaEventos();

    // Muestra el total de eventos en el formato solicitado con "Nodos ="
    std::cout << "Nodos = ";
    listaEventos.mostrarTotalEventos("Numero|Cientifico|Datos -> ");
    std::cout << std::endl;

    return 0;
}
