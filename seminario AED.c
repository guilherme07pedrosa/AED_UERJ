	/******************************************************************************
	
	Elabore um programa que, considerando um vetor de 10 posições de
	inteiros, apresente as seguintes opções de operações para o usuárioi:
	1- Preencher o vetor
	2- Buscar por um valor:
	a) tipo de busca 1 (a definir)
	b) tipo de busca 2 (a definir)
	3- Ordenar o vetor:
	a) tipo de ordenação 1 (a definir)
	b) tipo de ordenação 2 (a definir)
	4- Sair
	
	*******************************************************************************/
	#include <stdio.h>
	#include <conio.h>
	#define N 4
	int particiona(int*vet, int inicio, int final);
	//função para cadastrar os numeros do vetor
	void cadastra_vet (int *vet)
	{
	  int i;
	  for (i = 0; i < N; i++)
	    {
	      printf ("entre com o numero do vetor;");
	      scanf ("%d", &vet[i]);
	    }
	}
	
	//função para cadastrar os numeros do vetor
	int cadastra_elem (int x)
	{
	  
	      printf ("Entre com elemento desejado ");
	      scanf ("%d", &x);
	      return x;
	    
	}
	
	
	
	//função para imprimir o vetor
	void imprime_vet (int *vet)
	{
	  int i;
	  for (i = 0; i < N; i++)
	    printf ("%d ", vet[i]);
	}
	
	//função para buscar um elemento na lista
	int busca (int*vet, int x){
	    int i;
	        for (i = 0; i < N; i++){
		    if (x == vet[i])
	    	    return i;
	        }
	    return -1;
	}
	
	//função para busca binaria
	int buscaBinaria(int*vet, int elem){
		int i, inicio, meio, final;
		inicio=0;
		final=N-1;
		while(inicio<=final){
			meio=(inicio+final)/2;
			if (elem<vet[meio])
				final = meio-1;
			else 
				if (elem>vet[meio])
					inicio =meio +1;
				else 
					return meio;
		}
		
	return -1;	
		
	}
	
	
	
	// função para ordenar um vetor
	void selectionSort(int*vet){
		int i,j,menor,troca;
		for (i=0;i<N-1;i++){
			menor=i;
			for (j=i+1;j<N;j++){
				if(vet[j]<vet[menor])
					menor=j;
				}
					if (menor != i){
					troca=vet[i];
					vet[i]=vet[menor];
					vet[menor]=troca;
				}
			}
		}	
	
	
	
	//procedimento resultado da busca
	
	void resultado_busca( int x){
	
		if (x<0)
			printf ("\nO elemento procurado não está na lista");
		else 
			printf ("\nO elemento está na posição %d, x");
	}
	
	//procedimento quickSort
	void quickSort(int*vet, int inicio, int fim){
		int pivo;
		if (fim>inicio){
			pivo = particiona(vet, inicio, fim);
			quickSort(vet, inicio, pivo-1);
			quickSort(vet, pivo+1, fim);
		}
	}
	
	int particiona(int*vet, int inicio, int final){
		int esq, dir, pivo, aux;
		esq=inicio;
		dir=final;
		pivo=vet[inicio];
		while (esq<dir){
			while (vet[esq]<=pivo)
				esq++;
			while (vet[dir]>pivo)
				dir--;
			if (esq<dir){
				aux=vet[esq];
				vet[esq]=vet[dir];
				vet[dir]=aux;
			}
		}
		vet[inicio]=vet[dir];
		vet[dir]=pivo;
		return dir;
	}
	
	
	//menu de opções
	
	int menu ()
	{
	  int op;
	
	  printf ("\n\n ==== MENU DE OPCOES ====\n");
	  printf ("0 - SAIR \n");
	  printf ("1 - DIGITAR OS ELEMENTOS DO VETOR \n");
	  printf ("2 - IMPRIMIR O VETOR \n");
	  printf ("3 - BUSCAR POR UM ELEMENTO DO VETOR PELA BUSCA SIMPLES\n");
	  printf ("4 - BUSCAR POR UM ELEMENTO DO VETOR PELA BUSCA BINÁRIA\n");
	  printf ("5 - ORDENAR O VETOR POR SELECTIONSORT\n");
	  printf ("6 - ORDENAR O VETOR POR QUICKSORT\n");
	  printf ("\nO que deseja fazer? ");
	  scanf ("%d", &op);
	
	  return op;
	}
	
	
	int
	main ()
	{
	    int res;
	    int op;
	    int vet[N];
	    int x;
		int inicio=0;
	    int fim =N-1;
	    do
	    {
	      op = menu ();
	      switch (op)
			{
		case 0:		//código para sair
		  break;
	
		case 1:		//código para cadastrar
	
		  {
		    cadastra_vet (vet);
			break;
		  }
	
		case 2:		//Imprimir o vetor
		  {
		    imprime_vet(vet);
		    break;
		  }
		  
		case 3:		//busca de um elemento no vetor por busca simples
		  {
		    x=cadastra_elem (x);
		    busca (vet, x);
		    printf("\nTESTE %d", busca(vet,x));
		    res=busca(vet,x);
		    resultado_busca(res);
		    break;
		  }
		  
		case 4:		//busca de um elemento no vetor por busca binaria
		  {
		    cadastra_elem (x);
		    selectionSort(vet);
		    buscaBinaria(vet,x);
			break;
		  } 
		  
		case 5:		//ordenar o vetor por selectionSort
		  {
		    selectionSort(vet);
		    imprime_vet(vet);
		    break;
		  }  
		 
		case 6:		//ordenar o vetor por quickSort
		  {
		    quickSort(vet, inicio, fim);
		    break;
		  }   
		  
		default:    //opção inválida
		  	printf ("----- OPCAO INVALIDA -----");
			}
	    }
	  while (op != 0);
	
	  return 0;
	
	}
