	/******************************************************************************
	
	Considere que o programa do exercício anterior preencha os valores do vetor de 
	forma ordenada. Faça uma busca por um valor informado pelo usuário. Utiliza a 
	busca binária.
	
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
	      if (i>=1){
	      	if (vet[i]<vet[i-1]){
	      		printf("O vetor deve estar ordenado");
	      		i=i-1;
			  }
		  }
	      	
	    }
	}
	
	//função para cadastrar o elemento a ser procurado
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

	
	//procedimento resultado da busca

	void resultado_busca(int res, int x){

		if (res < 0)
			printf ("\nO elemento procurado nao esta na lista");
		else 
			printf ("\nO elemento %d esta na posicao %d", x, res);
}
	
	
	
	//menu de opções
	
	int menu ()
	{
	  int op;
	
	  printf ("\n\n ==== MENU DE OPCOES ====\n");
	  printf ("0 - SAIR \n");
	  printf ("1 - DIGITAR OS ELEMENTOS DO VETOR \n");
	  printf ("2 - IMPRIMIR O VETOR \n");
	  printf ("3 - BUSCAR POR UM ELEMENTO DO VETOR PELA BUSCA BINÁRIA\n");
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
		  
	
		  
		case 3:		//busca de um elemento no vetor por busca binaria
		  {
		    int x;
			printf("Entre com elemento desejado ");
			scanf("%d", &x);
			res = buscaBinaria(vet,x);
			resultado_busca(res, x);
			break;
		  } 
		
		  
		default:    //opção inválida
		  	printf ("----- OPCAO INVALIDA -----");
			}
	    }
	  while (op != 0);
	
	  return 0;
	
	}
