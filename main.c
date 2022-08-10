#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *vet, int minimo, int maximo, int valor);
void insertion_Sort_Recursivo(int vet[], int n, int count);
void printVetor(int vet[], int tamanho);

int main(){

    int tamanho;

    scanf("%d",&tamanho);

	int *vet = (int *)malloc (tamanho*sizeof(int)); // Alocacao dinamica

    for (int i = 0; i < tamanho; i++) // Apenas leio os elementos do vetor
        scanf("%d",&vet[i]);

	insertion_Sort_Recursivo(vet, tamanho, 0); // Chamada da funcao insertionsort

	printVetor(vet, tamanho); // Simplesmente printara o vetor ja ordenado

    free(vet); // Liberacao da memoria alocada

	return 0;
}

int busca_binaria(int *vet, int minimo, int maximo, int valor){

    int meio = (minimo + maximo)/2 ; // Essa linha sempre renovara onde eu percorrirei no vetor

    if(maximo < minimo) // Aqui, eh quando a busca binaria eh encerrada. O retorno eh a posicao que devo inserir o elemento chave
        return minimo;

   if(vet[meio] == valor){ // Essa linha acontece quando se encontra a chave. Em seguida, verifico se devo pegar o indice anterior ou antecessor
    if(vet[meio] > vet[meio-1])
      return meio;
      
    else
      return meio-1;
  }

  if(vet[meio] < valor){ // Essas condicoes sao para a recursividade acontecer. Sempre eh verificado, no vetor, se o elemento chave precisa entrar na posicao ou se a recursividade podera ser feita.
    return busca_binaria(vet, meio+1, maximo, valor);
  } else {
      return busca_binaria(vet, minimo, meio-1, valor);
  }

}


void insertion_Sort_Recursivo(int vet[], int n, int count){
  int aux, indice_vet;
  
	if (n <= 1) // Caso base
		return;
    

	insertion_Sort_Recursivo(vet, n - 1, count+1); // Aqui a chamada recursiva acontecera

	int j = n-2; // Variavel criada para ter um parametro de inicio no vetor
    aux = vet[n-1]; // Variavel criada para armazenar o valor do elemento que estou comparando

	indice_vet = busca_binaria(vet, 0, n, vet[n-1]); // A funcao "busca_binaria" retornara o indice no vetor que precisarei mudar no vetor, ha cada recursividade
  
    printf("%d %d %d\n",count+1, vet[j+1], indice_vet); // Nesta linha, apenas printo o numero de recursividades (parametro "count"), o elemento chave(vet[j+1]) e o indice no vetor -obtido pela funcao "busca_binaria".

    while( j >= indice_vet){ // Nesta linha, como limitei no vetor ate qual elemento eu o percorrirei, fiz que a troca seja somente analisada ate o indice do parametro chave
        vet[j+1] = vet[j];
        j--;
    }

    vet[j+1] = aux; // Aqui simplesmente mudo o indice da chave no vetor

}


void printVetor(int vet[], int tamanho){ // Funcao simplesmente para printar o vetor ja ordenado

	for (int i = 0; i < tamanho; i++)
	    printf("%d", vet[i]);
	
    printf("\n");
}