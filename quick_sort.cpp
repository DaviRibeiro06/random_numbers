#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Função para gerar vetor aleatório
vector<int> gerarVetorAleatorio(int tamanho, int min, int max) {
    vector<int> vetor;
    srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        vetor.push_back(rand() % (max - min + 1) + min);
    }
    return vetor;
}

// Função para imprimir vetor
void imprimirVetor(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

// Particionamento do QuickSort
int particiona(vector<int>& v, int baixo, int alto) {
    int pivo = v[alto];
    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (v[j] <= pivo) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[alto]);
    return i + 1;
}

// QuickSort
void quickSort(vector<int>& v, int baixo, int alto) {
    if (baixo < alto) {
        int pi = particiona(v, baixo, alto);
        quickSort(v, baixo, pi - 1);
        quickSort(v, pi + 1, alto);
    }
}

int main() {
    vector<int> vetor = gerarVetorAleatorio(50, 1, 500);

    cout << "Vetor original:\n";
    imprimirVetor(vetor);

    // Medir tempo de execução do QuickSort
    auto inicio = high_resolution_clock::now();

    quickSort(vetor, 0, vetor.size() - 1);

    auto fim = high_resolution_clock::now();
    auto duracao = duration_cast<nanoseconds>(fim - inicio);

    cout << "\nVetor ordenado com QuickSort:\n";
    imprimirVetor(vetor);

    cout << "\nTempo de execucao: " << duracao.count() << " nanosegundos\n";

    return 0;
}
