#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para gerar vetor de inteiros aleatórios
vector<int> gerarVetorAleatorio(int tamanho, int min, int max) {
    vector<int> vetor;
    srand(time(0));  // Inicializar a semente
    for (int i = 0; i < tamanho; i++) {
        vetor.push_back(rand() % (max - min + 1) + min);
    }
    return vetor;
}

// Função para imprimir o vetor
void imprimirVetor(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

// Insertion Sort (algoritmo simples)
void insertionSort(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

int main() {
    vector<int> vetor = gerarVetorAleatorio(50, 1, 500);

    cout << "Vetor original:\n";
    imprimirVetor(vetor);

    insertionSort(vetor);

    cout << "\nVetor ordenado com Insertion Sort:\n";
    imprimirVetor(vetor);

    return 0;
}
