#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include "MatrizBase.h"

template <typename T>
class MatrizDinamica : public MatrizBase<T> {
private:
    T** datos;
    std::string nombre; // Para identificar en los mensajes

    void asignarMemoria() {
        datos = new T*[this->filas];
        for (int i = 0; i < this->filas; ++i)
            datos[i] = new T[this->columnas]{};
    }

    void liberarMemoria() {
        if (datos) {
            std::cout << "Liberando memoria de " << nombre << " (Matriz Dinámica)...\n";
            for (int i = 0; i < this->filas; ++i)
                delete[] datos[i];
            delete[] datos;
            datos = nullptr;
        }
    }

public:
    MatrizDinamica(int f, int c, const std::string& n = "Matriz") 
        : MatrizBase<T>(f, c), nombre(n) {
        asignarMemoria();
    }

    ~MatrizDinamica() override {
        std::cout << "Llamando al destructor de " << nombre << "...\n";
        liberarMemoria();
    }

    // Regla de los cinco
    MatrizDinamica(const MatrizDinamica& otra) 
        : MatrizBase<T>(otra.filas, otra.columnas), nombre(otra.nombre) {
        asignarMemoria();
        for (int i = 0; i < this->filas; ++i)
            for (int j = 0; j < this->columnas; ++j)
                datos[i][j] = otra.datos[i][j];
    }

    MatrizDinamica& operator=(const MatrizDinamica& otra) {
        if (this != &otra) {
            liberarMemoria();
            this->filas = otra.filas;
            this->columnas = otra.columnas;
            nombre = otra.nombre;
            asignarMemoria();
            for (int i = 0; i < this->filas; ++i)
                for (int j = 0; j < this->columnas; ++j)
                    datos[i][j] = otra.datos[i][j];
        }
        return *this;
    }

    MatrizDinamica(MatrizDinamica&& otra) noexcept 
        : MatrizBase<T>(otra.filas, otra.columnas), datos(otra.datos), nombre(otra.nombre) {
        otra.datos = nullptr;
        otra.filas = 0;
        otra.columnas = 0;
    }

    MatrizDinamica& operator=(MatrizDinamica&& otra) noexcept {
        if (this != &otra) {
            liberarMemoria();
            this->filas = otra.filas;
            this->columnas = otra.columnas;
            datos = otra.datos;
            nombre = otra.nombre;
            otra.datos = nullptr;
            otra.filas = 0;
            otra.columnas = 0;
        }
        return *this;
    }

    void set(int i, int j, T valor) override { datos[i][j] = valor; }
    T get(int i, int j) const override { return datos[i][j]; }

    void imprimir() const override {
        for (int i = 0; i < this->filas; ++i) {
            std::cout << "| ";
            for (int j = 0; j < this->columnas; ++j)
                std::cout << datos[i][j] << " | ";
            std::cout << "\n";
        }
    }

    MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
        if (this->filas != otra.getFilas() || this->columnas != otra.getColumnas()) {
            std::cerr << "Error: dimensiones incompatibles.\n";
            return nullptr;
        }

        auto* resultado = new MatrizDinamica<T>(this->filas, this->columnas, "C");
        for (int i = 0; i < this->filas; ++i)
            for (int j = 0; j < this->columnas; ++j)
                resultado->set(i, j, datos[i][j] + otra.get(i, j));

        return resultado;
    }
};

#endif
