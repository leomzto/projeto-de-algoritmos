# Projeto de Algoritmos

Implementações e análises experimentais de algoritmos de ordenação em **C++**, desenvolvidas para a disciplina de Projeto de Algoritmos.

O programa gera instâncias de entrada, executa os algoritmos, mede o tempo de execução e armazena os arquivos de entrada, saída e tempo de cada execução. Os resultados alimentam as tabelas, os gráficos e os relatórios.

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
├── CMakeLists.txt           # configuração de build
├── README.md
├── include/
│   ├── algoritmos/          # cabeçalhos dos algoritmos (bubble_sort.hpp, ...)
│   └── utils/               # cabeçalhos utilitários
├── src/
│   ├── main.cpp             # ponto de entrada
│   ├── algoritmos/          # implementação de cada algoritmo
│   └── utils/               # implementação dos utilitários
├── dados/                   # arquivos de entrada, saída e tempo, uma pasta por algoritmo
│   ├── bubble_sort/
│   ├── insertion_sort/
│   ├── selection_sort/
│   ├── shell_sort/
│   ├── merge_sort/
│   └── quick_sort/
├── scripts/
│   └── gerar_grafico_tabela.py   # gera gráficos e tabelas a partir dos tempos
├── relatorios/              # relatórios das entregas (PDF)
└── extras/
    ├── graficos/
    ├── tabelas/
    └── tempos/
```

### Módulos utilitários (`utils`)

| Módulo | Responsabilidade |
|---|---|
| `algoritmos` | seleção e chamada dos algoritmos |
| `arquivos` | leitura e escrita dos arquivos de entrada, saída e tempo |
| `caminhos` | caminhos das pastas de dados |
| `executar` | execução dos experimentos |
| `gerador` | geração das instâncias de entrada |
| `menu` | menu interativo do programa |
| `tempo` | medição do tempo de execução |

## Requisitos

- Compilador C++17 da família GCC (por exemplo, MinGW no Windows), pois o `CMakeLists.txt` usa flags específicas do GCC
    - No Windows, uma opção é instalar o [MSYS2](https://www.msys2.org/) e, no terminal **MSYS2 UCRT64**, rodar `pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make`. Depois, adicione `C:\msys64\ucrt64\bin` ao PATH.
- [CMake](https://cmake.org/) 3.20 ou superior
- Python 3 (testado com 3.14) com `matplotlib` e `pandas`, para gerar gráficos e tabelas (dependências em `requirements.txt`)

## Como compilar

```bash
git clone https://github.com/leomzto/projeto-de-algoritmos.git
cd projeto-de-algoritmos
```

**Linux / macOS**

```bash
cmake -B cmake-build-release -DCMAKE_BUILD_TYPE=Release
cmake --build cmake-build-release
```

**Windows (MinGW)**

```powershell
cmake -B cmake-build-release -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build cmake-build-release
```

> No Windows, o `-G "MinGW Makefiles"` é necessário. Sem ele, o CMake tenta usar o NMake (Visual Studio) e a configuração falha.

Para a versão de depuração, use `-DCMAKE_BUILD_TYPE=Debug` e a pasta `cmake-build-debug`.

## Como executar

Depois de compilar, execute o programa gerado em `cmake-build-release/`:

```bash
# Linux/macOS
./cmake-build-release/Projeto_de_Algoritmo

# Windows (PowerShell)
.\cmake-build-release\Projeto_de_Algoritmo.exe
```

> **Importante:** execute sempre a partir da **raiz do projeto**. Os caminhos de `dados/` são relativos à pasta em que o programa é iniciado.

O programa abre um **menu interativo** para gerar as instâncias e executar os algoritmos. *(AJUSTAR: descreva as opções do menu.)*

## Experimentos

Os algoritmos são avaliados com:

- **Tipos de entrada:** vetores crescentes, decrescentes e aleatórios
- **Tamanhos:** de instâncias pequenas até 1.000.000 de elementos
- **Métrica:** tempo de execução

Para cada algoritmo, os arquivos de entrada, saída e tempo ficam em `dados/<nome_do_algoritmo>/`. Os tempos consolidados, tabelas e gráficos ficam em `extras/`.

Para gerar gráficos e tabelas a partir dos tempos:

```bash
python -m venv .venv
.venv\Scripts\activate          # Windows (PowerShell)
# source .venv/bin/activate     # Linux/macOS
pip install -r requirements.txt
python scripts/gerar_grafico_tabela.py
```

## Relatórios

Os relatórios com a análise dos resultados estão em [`relatorios/`](relatorios/).

## Tecnologias

- C++
- CMake
- Python (gráficos e tabelas)
- LaTeX (relatórios)

## Autor

**Leonardo Manzato** — [@leomzto](https://github.com/leomzto)