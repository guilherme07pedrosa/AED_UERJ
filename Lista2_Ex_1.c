	/******************************************************************************
	
	1. Elabore um programa que preencha um vetor de valores inteiros de 20 posições e 
	ao final faça uma busca sequencial por um valor, a ser informado pelo usuário.
	
	*******************************************************************************/
	#include <stdio.h>
	#define N 4
	
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
	int buscaSequencial (int*vet, int x){
	    int i;
	        for (i = 0; i < N; i++){
		    if (x == vet[i])
	    	    return i;
	        }
	    return -1;
	}
	
	
	
	
	
	
	
	//procedimento resultado da busca
	void resultado_busca( int x){
	
		if (x<0)
			printf ("\nO elemento procurado não está na lista");
		else 
			printf ("\nO elemento está na posição %d", x);
	}
	
	
	
	//menu de opções
	
	int menu ()
	{
	  int op;
	
	  printf ("\n\n ==== MENU DE OPCOES ====\n");
	  printf ("0 - SAIR \n");
	  printf ("1 - DIGITAR OS ELEMENTOS DO VETOR \n");
	  printf ("2 - IMPRIMIR O VETOR \n");
	  printf ("3 - BUSCAR POR UM ELEMENTO DO VETOR PELA BUSCA SEQUENCIAL\n");
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
		  
		case 3:		//busca de um elemento no vetor por busca sequancial
		  {
		    x=cadastra_elem (x);
		    buscaSequencial (vet, x);
		    printf("\nTESTE %d", buscaSequencial(vet,x));
		    res=buscaSequencial(vet,x);
		    resultado_busca(res);
		    break;
		  }
		  
	    }
		}
	  	while (op != 0);
		
	  return 0;
	
	}
