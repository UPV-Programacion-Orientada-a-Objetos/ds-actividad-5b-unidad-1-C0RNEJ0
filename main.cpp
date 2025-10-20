#include <iostream>
#include "MatrizBase.h"
#include "MatrizDinamica.h"
#include "MatrizEstatica.h"

int main() {
    std::cout << "--- Sistema genérico de Álgebra Lineal ---\n\n";
    std::cout << ">> Demostración de Genericidad (Tipo FLOAT) <<\n\n";

    MatrizBase<float>* A = new MatrizDinamica<float>(3, 2, "A");
    MatrizBase<float>* B = new MatrizEstatica<float, 3, 2>();

    A->set(0,0,1.5f); A->set(0,1,2.0f);
    A->set(1,0,0.0f); A->set(1,1,1.0f);
    A->set(2,0,4.5f); A->set(2,1,3.0f);

    B->set(0,0,0.5f); B->set(0,1,1.0f);
    B->set(1,0,2.0f); B->set(1,1,3.0f);
    B->set(2,0,1.0f); B->set(2,1,1.0f);

    std::cout << "Matriz A:\n"; A->imprimir();
    std::cout << "\nMatriz B:\n"; B->imprimir();

    MatrizBase<float>* C = (*A) + (*B);
    std::cout << "\nResultado C = A + B:\n";
    C->imprimir();

    std::cout << "\n>> Demostración de Limpieza de Memoria <<\n";
    std::cout << "Llamando al destructor de C...\n";
    delete C;

    std::cout << "Llamando al destructor de A...\n";
    delete A;

    std::cout << "Sistema cerrado.\n";
    return 0;
}
