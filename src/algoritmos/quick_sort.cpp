#include <utility>

using namespace std;

// versao 1
void particao_v1(int* vetor, int esq, int dir, int& i, int& j) {
    i = esq;
    j = dir;

    int pivo = vetor[esq]; // primeiro elemento

    do {
        while (vetor[i] < pivo) i++;
        while (vetor[j] > pivo) j--;

        if (i <= j) {
            swap(vetor[i], vetor[j]);
            i++;
            j--;
        }
    } while (i <= j);
}

// versao 2
void particao_v2(int* vetor, int esq, int dir, int& i, int& j) {
    i = esq;
    j = dir;

    // calcula a média para o pivo
    double soma = 0;

    for (int k = esq; k <= dir; k++)
        soma += vetor[k];

    double pivo = soma / (dir - esq + 1);

    do {
        while (vetor[i] < pivo) i++;
        while (vetor[j] > pivo) j--;

        if (i <= j) {
            swap(vetor[i], vetor[j]);
            i++;
            j--;
        }

    } while (i <= j);
}


void quickSort(int* vetor, int tamanho, int versao) {

    // lambda recursiva para realizar a ordenação dependendo da versao escolhida
    // tambem controla os limites esquerdo e direito de cada part.
    auto ordena = [&](auto&& self, int esq, int dir) -> void {
        while (esq < dir) {
            int i, j;

            if (versao == 1)
                particao_v1(vetor, esq, dir, i, j);
            else if (versao == 2)
                particao_v2(vetor, esq, dir, i, j);

            int tamEsq = j - esq + 1;
            int tamDir = dir - i + 1;

            if (tamEsq < tamDir) {
                if (esq < j)
                    self(self, esq, j);

                esq = i;
            } else {
                if (i < dir)
                    self(self, i, dir);

                dir = j;
            }
        }
    };

    if (tamanho > 1 && (versao == 1 || versao == 2))
        ordena(ordena, 0, tamanho - 1);
}