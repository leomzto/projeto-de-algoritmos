#include "utils/menu.hpp"
#include "utils/gerador.hpp"
#include "utils/arquivos.hpp"
#include "utils/tempo.hpp"

#include <iostream>
#include <functional>

using namespace std;

// void executarAlgoritmo(void (*algoritmo)(int*, int), const string& nomeAlgoritmo, const string& caminhoBase, const string& caminhoCSV)

// para lambda: function<void(int*, int)> // variavel capaz de armazenar uma funcao ou lambda *#include <functional>*
void executarAlgoritmo(function<void(int*, int)> algoritmo,
                    const string& nomeAlgoritmo, const string& caminhoBase, const string& caminhoCSV) {

    int tipo = escolherTipoInstancia();
    int tamanho = escolherTamanhoInstancia();

    cout << "\nGerando instancia...\n";
    int* vetor = gerarInstancia(tipo, tamanho);

    if (vetor == nullptr) {
        cout << "Erro ao gerar instancia.\n";
        return;
    }

    const string nomeInstancia = obterNomeInstancia(tipo);
    const string nomeArquivo = nomeInstancia + "_" + to_string(tamanho) + ".txt";

    const string caminhoEntradaBase = caminhoBase + "arquivos_de_entrada/";
    const string caminhoSaidaBase = caminhoBase + "arquivos_de_saida/";
    const string caminhoTempoBase = caminhoBase + "arquivos_de_tempo/";

    criarDiretorios(caminhoEntradaBase, caminhoSaidaBase,
                    caminhoTempoBase, nomeInstancia);

    const string caminhoEntrada = caminhoEntradaBase + nomeInstancia + "/" + nomeArquivo;
    const string caminhoSaida = caminhoSaidaBase + nomeInstancia + "/" + nomeArquivo;
    const string caminhoTempo = caminhoTempoBase + nomeInstancia + "/" + nomeArquivo;

    cout << "Salvando instancia de Arquivos de Entrada...\n";
    salvarVetor(caminhoEntrada, vetor, tamanho);

    cout << "Executando " << nomeAlgoritmo << "...\n";
    double tempo = calcularTempo(algoritmo, vetor, tamanho);

    cout << "Salvando instancia de Arquivos de Saida...\n";
    salvarVetor(caminhoSaida, vetor, tamanho);

    cout << "Salvando Arquivos de Tempo...\n";
    salvarTempo(caminhoTempo, tamanho, tempo);
    salvarCSV(caminhoCSV, tamanho, nomeInstancia, tempo);

    cout << "\n===== EXECUCAO CONCLUIDA =====\n";
    cout << "Algoritmo: " << nomeAlgoritmo << "\n";
    cout << "Tipo: " << nomeInstancia << "\n";
    cout << "Tamanho: " << tamanho << "\n";
    cout << "Tempo: " << tempo << " segundos\n";

    cout << "\nArquivos gerados:\n";
    cout << "Entrada: " << caminhoEntrada << "\n";
    cout << "Saida:   " << caminhoSaida << "\n";
    cout << "Tempo:   " << caminhoTempo << "\n";
    cout << "CSV:     " << caminhoCSV << "\n";

    delete[] vetor;
}