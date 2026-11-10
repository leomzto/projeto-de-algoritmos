# Projeto de Algoritmos

Implementações e análises experimentais de algoritmos de ordenação em **C++**, desenvolvidas para a disciplina de Projeto de Algoritmos.

O projeto gera instâncias de entrada, executa os algoritmos, mede o tempo de execução e armazena os arquivos de entrada e saída para análise.

## Algoritmos implementados

| Algoritmo | Melhor caso | Caso médio | Pior caso |
|---|---|---|---|
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Bubble Sort | O(n)\* | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Shell Sort (gap = n/2, n/4, ...) | O(n log n) | depende do gap | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |

\* O(n) apenas se houver parada antecipada quando nenhuma troca ocorre.

**Variações do Quick Sort**

- **V1:** pivô no primeiro elemento da partição.
- **V2:** pivô pela média aritmética dos elementos da partição.

## Estrutura do repositório

```
Projeto_de_Algoritmos/
├── main.cpp            # ponto de entrada do programa
├── CMakeLists.txt      # configuração de build
├── include/            # cabeçalhos (.hpp)
├── src/                # implementações (.cpp)
├── Algoritmos/         # AJUSTAR: descreva o conteúdo desta pasta
├── scripts/            # AJUSTAR: geração de instâncias, execução dos experimentos, etc.
├── Relatorios/         # relatórios e análises dos experimentos
├── Extras/             # AJUSTAR: descreva o conteúdo desta pasta
└── executavel/         # AJUSTAR: binários compilados
```

## Requisitos

- Compilador com suporte a C++17 ou superior (GCC, Clang ou MSVC)
- [CMake](https://cmake.org/) 3.10 ou superior *(AJUSTAR conforme o seu `CMakeLists.txt`)*

## Como compilar

```bash
git clone https://github.com/leomzto/Projeto_de_Algoritmos.git
cd Projeto_de_Algoritmos

cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Como executar

```bash
./build/NOME_DO_EXECUTAVEL
```

> AJUSTAR: substitua `NOME_DO_EXECUTAVEL` pelo nome definido no `CMakeLists.txt` e documente aqui os argumentos ou o menu do programa, se houver.

## Experimentos

Os algoritmos são avaliados com:

- **Tipos de entrada:** vetores crescentes, decrescentes e aleatórios
- **Tamanhos:** de instâncias pequenas até 1.000.000 de elementos
- **Métrica:** tempo de execução

Os arquivos de entrada e os resultados de cada execução ficam em *(AJUSTAR: caminho das pastas de entrada e saída)*.

Os resultados completos, com tabelas, gráficos e análise de complexidade, estão em [`Relatorios/`](Relatorios/).

## Tecnologias

- C++
- CMake
- LaTeX (relatórios)

## Autor

**Leonardo Manzato** — [@leomzto](https://github.com/leomzto)