#ifndef TEMPO_HPP
#define TEMPO_HPP

#include <functional>

using namespace std;

// double calcularTempo(void (*algoritmo)(int*, int), int* vetor, int tamanho);

double calcularTempo(function<void(int*, int)> algoritmo, int* vetor, int tamanho);
#endif