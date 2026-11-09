#ifndef PROJETO_DE_ALGORITIMO_EXECUTAR_HPP
#define PROJETO_DE_ALGORITIMO_EXECUTAR_HPP

#include <string>
#include <functional>

// alteracoes para uso de lambda no menu:
// para lambda: std::function<void(int*, int)> // variavel capaz de armazenar uma funcao ou lambda *#include <functional>*
//
// no shell:
// teria que alterar em tempo.cpp/hpp, executar.cpp/hpp tambem
// isso para a labda poder capturar o divisor, para alterar o divisor do gap do shell sort

using namespace std;

/*
void executarAlgoritmo(void (*algoritmo)(int*, int), const string& nomeAlgoritmo,
                              const string& caminhoBase, const string& caminhoCSV);
*/

void executarAlgoritmo(function<void(int*, int)> algoritmo,
            const string& nomeAlgoritmo, const string& caminhoBase, const string& caminhoCSV);

#endif
