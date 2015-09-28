SSC0300 - Linguagens de Programação e Aplicações
Prof. Adenilso da Silva Simão
Trabalho 1

Aluna: Victória Silva Roiz         Nº USP: 8955431 
       Ana Luiza Queiroz Oliveira          8955598

-- Ferramentas de Desenvolvimento e Compilação
Todos os programas dos Problemas 1,2,3 e 4 foram desenvolvidos em linguagem C, compilados utilizando MinGW (Compilador GCC) e testados usando plataforma Windows 8.1 via IDE Codeblocks 13.12

-- Compilação
Para compilação do código via Codeblocks, basta utilizar o compilador interno clicando em Build.
O código pode ser compilado da seguinte maneira:

gcc problemaX.c -o problemaX

Substituindo X pelo numero do problema selecionado.

-- Execução
Para utilizar o programa dos problemas 1 a 3, o usuário deverá inserir inicialmente um valor N (numeros de valores que serão inseridos e em seguida os n valores para serem testados no respectivo problema desejado.
Assim que o usuário terminar de inserir os valores a saída esperada será mostrada na tela.

Para utilizar o programa do problema 4, o usuário deverá inserir inicialmente um valor N (numeros de pontos que serão inseridos e em seguida os n pontos para serem testados na forma X Y (Ex: 2 10).
Assim que o usuário terminar de inserir os pontos a saída esperada será mostrada na tela, neste caso os pontos que compoem o polígono convexo que de menor área que englobe todos os pontos dados.

O usuário também pode colocar suas entradas em um bloco de notas seguindo o exemplo encontrado na pasta do problema e então executar:
problemaX.exe < suaentrada.txt > suasaida.txt
e então a saída desejada estará no arquivo suasaida.txt

-- Recursos Externos

Para realizar os códigos foram utilizados os Algoritmos de Ordenação Insertion Sort e Bubble Sort e no problema 4 foi usado o Algoritmo Monotone Chain para encontrar o poligono desejado. Para compreender melhor o funcionamento do algoritimo usado foram usados os seguintes recursos:
-> https://www.youtube.com/watch?v=LTCt81qAEnE
-> http://www.algorithmist.com/index.php/Monotone_Chain_Convex_Hull

-- FIM --
