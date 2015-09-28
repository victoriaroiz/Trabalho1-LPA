#include <stdio.h>
#include <stdlib.h>

/*
    Aluna: Victória Silva Roiz
    Nº USP:
    Problema 2: Elemento único (Element uniqueness) - Dado um conjunto de n elementos, identifique aqueles elementos que ocorrem uma única vez.
*/

/* Função a seguir recebe o vetores de elementos a serem analisados e o tamanho do vetor e então imprime
    na saída padrão os elementos que aparecem uma única vez.
*/

void elemento_unico(int tam, int vetor[]){
    int i, j, selecionado;

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

    //Verifica se o elemento é único comparando ele com os "vizinhos"
    for(i = 0; i < tam; i++){
        if(i == 0){
            if(vetor[i] != vetor[i+1]){
                printf("%d\n", vetor[i]);
            }
        } else if(i == tam - 1){
            if(vetor[i] != vetor[i-1]){
                printf("%d\n",vetor[i]);
            }
        } else{
            if(vetor[i] != vetor[i-1] && vetor[i]!= vetor[i+1]){
                printf("%d\n",vetor[i]);
            }
        }
    }
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
    elemento_unico(n, vet);
    // Liberar a memória
    free(vet);
    return 0;
}
