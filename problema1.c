#include <stdio.h>
#include <stdlib.h>

/*
    Aluna: Victória Silva Roiz
    Nº USP:
    Problema 1: Pares mais próximos (Closest Pair) - Dado um conjunto de n números inteiros, encontre o par de números com a menor diferença entre eles
*/

/* Função a seguir recebe o vetores de elementos a serem analisados e o tamanho do vetor e então imprime
    na saída padrão o par de elementos com a menor diferença entre eles, caso haja elementos repetidos de mesma diferença apenas um será mostrado.
*/
void pares_mais_proximos(int tam, int vetor[]){
    int i, j, selecionado, posicao_elemento1, posicao_elemento2, menor_diferenca, diferenca;

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

    // Atribui um valor genérico às variáveis para evitar que elas recebam valores aleatórios
    menor_diferenca = vetor[1] - vetor[0];
    posicao_elemento1 = 0;
    posicao_elemento2 = 1;

    /*
    * Realiza a comparação entre os termos "vizinhos" do vetor em um laço de repetição
    * Se a diferença entre eles é menor que a menor diferença já registrada, a variável "menor_diferenca" recebe a nova menor
    * diferença e as variáveis posicao_elemento1 e posicao_elemento2 armazenam as posições dos elementos de menor diferença.
    */
    for(i = 1; i < tam-1; i++){
        diferenca = vetor[i+1] - vetor[i];
        if(diferenca < menor_diferenca){
            menor_diferenca = diferenca;
            posicao_elemento1 = i;
            posicao_elemento2 = i + 1;
        }
    };
    printf("%d %d", vetor[posicao_elemento1], vetor[posicao_elemento2]);
    //printf("O par com a menor diferenca e o formado pelos elementos %d e %d e a menor diferenca e: %d\n", vetor[posicao_elemento1], vetor[posicao_elemento2], menor_diferenca);
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
    pares_mais_proximos(n, vet);
    // Liberar a memória
    free(vet);
    return 0;
}
