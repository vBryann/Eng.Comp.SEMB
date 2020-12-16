/*
 11/12/20
 @(#) Knapsack.c
 
 Copyright 2015 by C4learn.com 
 
 Rewritted 2020 by Vitor Bryan and Iago da Silva
 Instituto Federal de Ciência, Tecnologia e Educação do Ceará

 Este código foi desenvolvido para um trabalho da disciplina de
 Sistemas Embarcados.

*/

/*

Este código implementa umas das soluções possíveis do Problema da Mochila fracionária utilizando um algoritmo Guloso, que consiste em pegar o lucro máximo dentro da limitação de capacidade que a mochila pode suportar. O algoritmo é uma das soluções simples para o problema, pois ele seleciona as formas mais apetitosas priorizando em encontrar a solução com o valor máximo, sem se importar com a próxima iteração.

Entrada: 
 - Um valor correspondente ao número de objetos.
 - Dois vetores correspondentes ao peso e valor de cada objeto, respectivamente.
 - Um valor correspondente a capacidade da mochila.

Saida:
 - Um vetor correspondente a porcentagem do objeto contido dentro da mochila.
 - Um valor correspondente ao valor máximo obtido.

*/


# include<stdio.h>
 

void mochila(int n, float peso[], float lucro[], float capacidade) {
/*

 Função onde é realizado o método guloso, onde é selecionada a sequência de itens com maior valor específico ( valor / peso ) e colocando no Vetor X. Nas suas entradas são recebidos o N, como número de objetos; vetor peso, como os valores dos pesos de cada objeto; vetor lucro, como os valores de lucro de cada um dos objetos; e por fim a capacidade que determina a capacidade da mochila. Sua saída é pra retornar o vetor X, com a porcentagem de cada objeto contido na mochila, e a variável Tp que contém o valor da soma de todos os objetos contidos na mochila, resultando no valor máximo.
 
 */

/*
 Declaração das variáveis utilizadas na função:
  Vetor X corresponde ao vetor com a porcentagem de cada objeto que ocupará a mochila
  Tp corresponde ao valor total da soma de todos os objetos na mochila
  Variáveis I e J apenas utilizadas como indicação
  Variável U utilizada para guardar as informações da capacidade da mochila
*/
   float x[500], tp = 0;
   int i, j, u;
   u = capacidade;
 
 // Laço de repetição para zerar todo o vetor X
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
     //Aqui tentamos por o objeto inteiro dentro da mochila 
      if (peso[i] > u)
      //Caso o objeto não consiga ser colocado inteiro na mochila o for é parado
         break;
    //Caso o objeto entre dentro da mochila contabilizamos que 100% do objeto foi pra dentro da mochila nesse caso representado por 1.0 e subtraimos o peso do objeto do peso total que a mochila ainda aguenta
      else {
         x[i] = 1.0;
         tp = tp + lucro[i];
         u = u - peso[i];
      }
   }
   /*
   Aqui são tratados os casos no qual os objetos não foram colocados inteiramente dentro da mochila, isso é feito da seguinte maneira se o i que é o contador do vetor ainda for menor que o números de objetos isso significa que ainda tem objetos pra serem contabilizados, sendo assim, dividimos a capacidade atual da mochila pelo peso do objeto gerando assim um objeto que é uma fração apenas do objeto original e essa fração é multiplicada pelo valor do objeto e colocada dentro da mochila
   */

  // Condição para colocar a porcentagem de acordo com a capacidade restante da mochila
   if (i < n)
      x[i] = u / peso[i];
  
  // Aqui é onde o lucro total é calculado
   tp = tp + (x[i] * lucro[i]);
 

 // Retorno dos valores finais
   printf("\nO vetor de resultado é:");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
 
   printf("\nO lucro máximo é: %f", tp);
 
}
 
int main() {

  /*
  Declaração das variáveis na Main: 
  Vetores Peso, lucro representam respectivamente os valores dos objetos colocados na entradas
  Variavel Capacidade representa a capacidade da mochila determinada na entrada
  Variavel Num representa a quantidade de objetos existentes determinada na entrada
  Vetor Razao representa o valor específico ( Lucro / Peso ) de cada um dos objetos
  */
   float peso[500], lucro[500], capacidade;
   int num, i, j;
   float razao[500], aux;
 
   printf("\nNumero de objetos:- ");
   scanf("%d", &num);
 
   printf("\nInsira o peso e os valores de cada objeto:\n");
   for (i = 0; i < num; i++) {
      printf("\nDigite o peso do objeto %d\n", i+1);
      scanf("%f",&peso[i]);
      printf("\nDigite o valor do objeto %d\n", i+1);
      scanf("%f", &lucro[i]);
   }
 
   printf("\nInsira a capacidade da mochila:- ");
   scanf("%f", &capacidade);
 
 // Realiza a razão entre Peso e Valor de cada um dos Objetos obtidos nas entradas e preenche no vetor Razão
   for (i = 0; i < num; i++) {
      razao[i] = lucro[i] / peso[i];
   }
 
 // Após isso, é realizado um selection sort para deixar o vetor razão em ordem decrescente, e de acordo com o seu valor realizar a iteração nos outros vetores de peso e valor, como forma de deixar alinhado os valores com seus respectivos objetos.

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (razao[i] < razao[j]) {
            aux = razao[j];
            razao[j] = razao[i];
            razao[i] = aux;
 
            aux = peso[j];
            peso[j] = peso[i];
            peso[i] = aux;
 
            aux = lucro[j];
            lucro[j] = lucro[i];
            lucro[i] = aux;
         }
      }
   }
 // Chamada da função que realiza o algoritmo guloso
   mochila(num, peso, lucro, capacidade);
   return(0);
}
