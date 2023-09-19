#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "eventos.h"

eventos::eventos() {
    primerEvento = nullptr;
    ultimoEvento = nullptr;
}

eventos::~eventos() {
    NodoEventos* eventoActual = primerEvento;
    while (eventoActual != nullptr) {
        NodoEventos* siguiente = eventoActual->siguienteEvento;
        delete eventoActual;
        eventoActual = siguiente;
    }
}

void eventos::agregarEvento(int datos, const std::string& cientifico) {
    auto* nuevoEvento = new NodoEventos;
    nuevoEvento->datos = datos;
    nuevoEvento->cientifico = cientifico;
    nuevoEvento->siguienteEvento = nullptr;

    if (primerEvento == nullptr) {
        primerEvento = nuevoEvento;
        ultimoEvento = nuevoEvento;
    } else {
        ultimoEvento->siguienteEvento = nuevoEvento;
        ultimoEvento = nuevoEvento;
    }
}

int eventos::calcularMCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void eventos::aplicarRestricciones() {
    std::vector<NodoEventos*> eventosTipoA;

    NodoEventos* current = primerEvento;
    while (current != nullptr) {
        if (current->cientifico == "Einstein" && esPrimo(current->datos)) {
            eventosTipoA.push_back(current);
        } else if (current->cientifico == "Rosen" && esPrimo(current->datos)) {
            if (!eventosTipoA.empty()) {
                NodoEventos* eventoTipoA = eventosTipoA.back();
                eventoTipoA->datos = obtenerNumeroCoprimo(eventoTipoA->datos);
            }
        } else if (current->cientifico == "Rosen" && !esPrimo(current->datos)) {
            if (!eventosTipoA.empty()) {
                std::cout << "Se ha producido un evento de Tipo C: " << current->datos << std::endl;
                for (auto evento : eventosTipoA) {
                    std::cout << evento->datos << "|" << evento->cientifico << "|Datos -> ";
                }
                std::cout << current->datos << "|" << current->cientifico << "|Datos ->" << std::endl;
            } else {
                std::cout << "Se ha producido un evento de Tipo C: " << current->datos << std::endl;
                std::cout << "Se ha viajado en el tiempo y No se han compartido datos" << std::endl;
            }
        }

        current = current->siguienteEvento;
    }
}
void eventos::mostrarEventos() const {
    NodoEventos* eventoActual = primerEvento;
    while (eventoActual != nullptr) {
        std::cout << "Nodos\n";
        std::cout << "Se ha producido un evento de Tipo A: __" << std::endl;
        std::cout << eventoActual->datos << "|" << eventoActual->cientifico << "|Datos ->" << std::endl;
        eventoActual = eventoActual->siguienteEvento;
    }
}

void eventos::mostrarTotalEventos(const std::string& formatoNodo) const {
    NodoEventos* eventoActual = primerEvento;
    while (eventoActual != nullptr) {
        std::cout << "Nodos\n";
        std::cout << formatoNodo << eventoActual->datos << "|" << eventoActual->cientifico << "|Datos ->" << std::endl;
        eventoActual = eventoActual->siguienteEvento;
    }
}
int eventos::obtenerNumeroCoprimo(int num) {
    int coprimo;
    do {
        coprimo = rand() % num;
    } while (calcularMCD(num, coprimo) != 1);

    return coprimo;
}


bool eventos::esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void eventos::mostrarListaEventos() {

}


