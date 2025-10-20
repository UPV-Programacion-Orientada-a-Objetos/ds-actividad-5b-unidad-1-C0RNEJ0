#ifndef MATRIZ_BASE_H
#define MATRIZ_BASE_H

#include <iostream>

template <typename T>
class MatrizBase {
protected:
    int filas;
    int columnas;

public:
    MatrizBase(int f, int c) : filas(f), columnas(c) {}
    virtual ~MatrizBase() = default;

    virtual void set(int i, int j, T valor) = 0;
    virtual T get(int i, int j) const = 0;
    virtual void imprimir() const = 0;
    virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const = 0;

    MatrizBase<T>* operator+(const MatrizBase<T>& otra) const {
        return this->sumar(otra);
    }

    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
};

#endif
