SSC0300 - Linguagens de Programa��o e Aplica��es
Prof. Adenilso da Silva Sim�o
Trabalho 1

Aluna: Vict�ria Silva Roiz         N� USP: 8955431 
       Ana Luiza Queiroz Oliveira          8955598

-- Ferramentas de Desenvolvimento e Compila��o
Todos os programas dos Problemas 1,2,3 e 4 foram desenvolvidos em linguagem C, compilados utilizando MinGW (Compilador GCC) e testados usando plataforma Windows 8.1 via IDE Codeblocks 13.12

-- Compila��o
Para compila��o do c�digo via Codeblocks, basta utilizar o compilador interno clicando em Build.
O c�digo pode ser compilado da seguinte maneira:

gcc problemaX.c -o problemaX

Substituindo X pelo numero do problema selecionado.

-- Execu��o
Para utilizar o programa dos problemas 1 a 3, o usu�rio dever� inserir inicialmente um valor N (numeros de valores que ser�o inseridos e em seguida os n valores para serem testados no respectivo problema desejado.
Assim que o usu�rio terminar de inserir os valores a sa�da esperada ser� mostrada na tela.

Para utilizar o programa do problema 4, o usu�rio dever� inserir inicialmente um valor N (numeros de pontos que ser�o inseridos e em seguida os n pontos para serem testados na forma X Y (Ex: 2 10).
Assim que o usu�rio terminar de inserir os pontos a sa�da esperada ser� mostrada na tela, neste caso os pontos que compoem o pol�gono convexo que de menor �rea que englobe todos os pontos dados.

O usu�rio tamb�m pode colocar suas entradas em um bloco de notas seguindo o exemplo encontrado na pasta do problema e ent�o executar:
problemaX.exe < suaentrada.txt > suasaida.txt
e ent�o a sa�da desejada estar� no arquivo suasaida.txt

-- Recursos Externos

Para realizar os c�digos foram utilizados os Algoritmos de Ordena��o Insertion Sort e Bubble Sort e no problema 4 foi usado o Algoritmo Monotone Chain para encontrar o poligono desejado. Para compreender melhor o funcionamento do algoritimo usado foram usados os seguintes recursos:
-> https://www.youtube.com/watch?v=LTCt81qAEnE
-> http://www.algorithmist.com/index.php/Monotone_Chain_Convex_Hull

-- FIM --