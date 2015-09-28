#include <stdio.h>
#include <stdlib.h>

/*
    Aluna: Victória Silva Roiz
    Nº USP:
    Problema 3: Distribuição de Frequência (Frequency distribution) - Dado um conjunto de n itens, identifique quais elementos ocorrem em maior número.
*/

/* Função a seguir recebe o vetores de elementos a serem analisados e o tamanho do vetor e então imprime
    na saída padrão o elemento  que mais se repete.
*/

void distribuicao_de_frequencia(int tam, int vetor[]){
    int i, j, selecionado, numero_repeticoes, maior_numero_repeticoes, elemento;

    //Ordenação do vetor pelo algoritmo de inserção (Insertion Sort)
    for (i = 1; i < tam; i++){
        selecionado = vetor[i];
        j = i - 1;
        while (j >= 0 && selecionado < vetor[j]) {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = selecionado;
    };


    //Verifica a ocorrência dos elementos com base no elemento anterior
    i = 1;
    numero_repeticoes = 1;
    maior_numero_repeticoes = 1;
    while(i < tam){
        if(vetor[i] == vetor[i-1]){
            numero_repeticoes++;
        }
        else{
            numero_repeticoes = 1;
        };

        if(numero_repeticoes > maior_numero_repeticoes){
            elemento = vetor[i];
            maior_numero_repeticoes = numero_repeticoes;
        };
        i++;
    };
    printf("%d", elemento);
}

// API PRINCIPAL

int main(){
    int n,i;
    int *vet;
    // Receber Tamanho do Vetor
    scanf("%d",&n);
    //Alocar memoria para o vetor
    vet = (int*)malloc(n*sizeof(int));
    // Receber os n valores
    for(i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }
    // Executar a funçao
    distribuicao_de_frequencia(n, vet);
    // Liberar a memória
    free(vet);
    return 0;
}
