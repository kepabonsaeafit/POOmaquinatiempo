#ifndef EVENTOS_H
#define EVENTOS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string> // Agregada la biblioteca <string>

class eventos {
public:
    eventos();
    ~eventos();
    void agregarEvento(int datos, const std::string& cientifico);
    void aplicarRestricciones();
    void mostrarEventos() const;
    void mostrarTotalEventos(const std::string& formatoNodo) const;

    void mostrarListaEventos();

private:
    struct NodoEventos {
        int datos;
        std::string cientifico;
        NodoEventos* siguienteEvento;
    };

    NodoEventos* primerEvento;
    NodoEventos* ultimoEvento;

    int obtenerNumeroCoprimo(int num);
    static bool esPrimo(int num);

    static int calcularMCD(int a, int b);
};

#endif
