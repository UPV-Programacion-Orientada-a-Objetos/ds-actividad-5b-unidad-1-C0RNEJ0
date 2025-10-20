#ifndef MATRIZ_ESTATICA_H
#define MATRIZ_ESTATICA_H

#include "MatrizBase.h"

template <typename T, int F, int C>
class MatrizEstatica : public MatrizBase<T> {
private:
    T datos[F][C]{};

public:
    MatrizEstatica() : MatrizBase<T>(F, C) {}

    void set(int i, int j, T valor) override { datos[i][j] = valor; }
    T get(int i, int j) const override { return datos[i][j]; }

    void imprimir() const override {
        for (int i = 0; i < F; ++i) {
            std::cout << "| ";
            for (int j = 0; j < C; ++j)
                std::cout << datos[i][j] << " | ";
            std::cout << "\n";
        }
    }

    MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
        if (this->filas != otra.getFilas() || this->columnas != otra.getColumnas()) {
            std::cerr << "Error: dimensiones incompatibles.\n";
            return nullptr;
        }

        auto* resultado = new MatrizEstatica<T, F, C>();
        for (int i = 0; i < F; ++i)
            for (int j = 0; j < C; ++j)
                resultado->set(i, j, datos[i][j] + otra.get(i, j));

        return resultado;
    }
};

#endif
