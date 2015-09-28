#include <stdio.h>
#include <stdlib.h>

/*
    Aluna: Victória Silva Roiz
    Nº USP:
    Problema 4: Fecho Convexo (Convex hull) - Dado n pontos em um plano 2D, retorne o subconjunto de pontos que forma um polígono com área mínima contendo todos os demais pontos. Um fecho convexo é como uma tira elástica colocada ao redor de um conjunto de pontos de modo que ela fique comprimindo e cercando todos os pontos desse conjunto.
*/

/*
    Para Resolver este problema será utilizado um algoritmo chamado Monotone Chain proposto por A. M Andrew
    que irá gerar a partir de uma lista de pontos ordenada uma lista de pontos de área mínima que englobem todos os demais pontos
    o algoritmo é da ordem nlogn sem levar em conta o tempo computacional para realizar a ordenação dos pontos

    Uma melhor compreensão do algoritmo pode ser verificada no seguinte link:
    https://www.youtube.com/watch?v=LTCt81qAEnE
    Onde seu funcionamento é explicado.

    O programa desenvolvido não trata entradas inválidas
*/

// Estrutura de Dados para Armazenas os Pontos
typedef struct {
  double x;
  double y;
} ponto;
typedef ponto* ptr_ponto;

/*
    Esta função retorna um valor negativo se os pontos p1 p2 p3 nesta sequencia formarem vetores que apontam sentido horário
    retorna um valor positivo caso os pontos p1 p2 p3 nesta sequencia formarem vetores que apontam sentido anti-horário
    e retorna 0 caso eles sejam colineares
 */
static double orientacao(ponto* p1, ponto* p2, ponto* p3){
  return (p2->x - p1->x)*(p3->y - p1->y) - (p2->y - p1->y)*(p3->x - p1->x);
}

/*
    Esta função irá ordenar os pontos enviados em listaDePontos utilizando um bubbleSort modificado para fazer a ordenação considerando o eixo y para desempate
    e em seguida irá gerar a lista dos pontos que formam o poligono desejado utilizando a função de orientacao de 3 pontos para fazer as comparações necessárias
*/

void gerarLista(ponto* listaDePontos, ssize_t nPontos, ptr_ponto** listaFinal, ssize_t* nPontosFinal){
    ptr_ponto* listaAuxiliar;
    ssize_t i, t, k = 0;
    listaAuxiliar = *listaFinal;
    ponto aux;

    // Aqui será realizado a ordenação dos pontos recebidos utilizando algoritmo bubble sort modificado para colocar os pontos na sequencia ascendente de eixo x e y(caso de empate)
    int j;
    for(i=nPontos-1; i >= 1; i--) {
        for(j=0; j < i ; j++) {
            if(listaDePontos[j].x > listaDePontos[j+1].x || (listaDePontos[j].x == listaDePontos[j+1].x && listaDePontos[j].y > listaDePontos[j+1].y)) {
                aux.x = listaDePontos[j].x;
                aux.y = listaDePontos[j].y;
                listaDePontos[j].x = listaDePontos[j+1].x;
                listaDePontos[j].y = listaDePontos[j+1].y;
                listaDePontos[j+1].x = aux.x;
                listaDePontos[j+1].y = aux.y;
            }
        }
    }

    // Esta seção irá compor os pontos da parte inferior do polígono
    for (i = 0; i < nPontos; ++i) {
        while (k >= 2 && orientacao(listaAuxiliar[k-2], listaAuxiliar[k-1], &listaDePontos[i]) <= 0) --k;
        listaAuxiliar[k++] = &listaDePontos[i];
    }

    // Esta seção irá compor os pontos da parte inferior do polígono
    for (i = nPontos-2, t = k+1; i >= 0; --i) {
        while (k >= t && orientacao(listaAuxiliar[k-2], listaAuxiliar[k-1], &listaDePontos[i]) <= 0) --k;
        listaAuxiliar[k++] = &listaDePontos[i];
    }
    // Salva valores de retorno para a main
    *listaFinal = listaAuxiliar;
    *nPontosFinal = k;
}

// API PRINCIPAL

int main(){
    int n,i;
    ponto *vet;
    ptr_ponto *listaFinal;

    ssize_t nPontosFinal;
    // Receber Tamanho do Vetor
    scanf("%d",&n);
    listaFinal = (ptr_ponto*)malloc(n*sizeof(ptr_ponto));
    //Alocar memoria para o vetor
    vet = (ponto*)malloc(n*sizeof(ponto));
    // Receber os n valores
    for(i=0;i<n;i++){
        scanf("%lf %lf",&vet[i].x,&vet[i].y);
    }
    // Executar a funçao
    gerarLista(vet,(ssize_t)n,&listaFinal,&nPontosFinal);
    // Liberar a memória
    for(i=0;i<nPontosFinal-1;i++){
        printf("%lf %lf\n",listaFinal[i]->x,listaFinal[i]->y);
    }
    return 0;
}
