/*2. Com base nas funções básicas para manipulação de pilhas, faça um programa que leia 15 
números e proceda, para cada um deles, como segue:
- se o número for par, insira-o na pilha;
- se o número lido for ímpar, retire um número da pilha;
- Ao final, esvazie a pilha imprimindo os elementos.
*/
#include <stdio.h>
#define MAX 3

//estrutura pelha
typedef struct pilhaSeq{
int valores[MAX];
int topo;
} pilhaSeq;

//inicializa uma pilha 
void inicializa_pilha(int *topo){
*topo = -1;
}

//verifica se a pila esta cheia
int pilha_cheia(int topo){
	return(topo==MAX-1);
}

//verifica se a pilha esta vazia
int pilha_vazia(int topo){
	return(topo==-1);
}

//mostra o topo da pelha
int mostra_valor_topo(pilhaSeq *pilha){
	if(!pilha_vazia(pilha->topo)){
		printf("\nTopo da pilha: %d\n",pilha->valores[pilha->topo]);
	}	
	else{
		printf("\nPilha vazia.\n");
	}
}

//empilha
void empilha(pilhaSeq *pilha, int valor){
	if(!pilha_cheia(pilha->topo)){
		(pilha->topo)++;
		pilha->valores[pilha->topo]=valor;
		printf("\nValor empilhado!\n");
	}
	else{
		printf("\nPilha cheia!\n");
	}
}

//desempliha
void desempilha(pilhaSeq *pilha){
	if(!pilha_vazia(pilha->topo)){
		printf("\nValor %d dempilhado!\n",pilha->valores[pilha->topo]);
		(pilha->topo)--;
	}
	else{
		printf("\nPilha vazia!\n");
	}
}



//ImprimirPilha
void imprimirPilha(pilhaSeq *pilha){
	int i;
	int tam=0;
	for (i=0;i<(pilha->topo);i++)
		tam++;
	
	printf("Valores da pilha ");
	for (i=0;i<=tam;i++)
		printf("\n %d ", pilha->valores[i]);
}

//menu

int menu(){
	int op;
	printf ("\n ==== MENU DE OPCOES ====\n");
    printf ("0 - SAIR \n");
    printf ("1 - EMPLILHAR \n");
    printf ("2 - DESEMPILHAR \n");
    printf ("3 - MOSTRAR TOPO \n");
    printf ("4 - IMPRIMIR VALORES DA PILHA \n");
    printf ("O que deseja fazer? ");
    scanf ("%d", &op);
    fflush(stdin);

    return op;
	}

//função principal
int main()
{
    pilhaSeq pilha;
    int topo;
    int op;
    int valor;
    inicializa_pilha(&topo);
    do{
    		op=menu();
    		switch(op){
    			case 0:{
					break;
				}
				case 1:{
    				printf("\nInforme o valor a empilhar: ");
					scanf("%d",&valor);
						if ((valor%2)==0)
							empilha(&pilha,valor);
						else 
							printf("/n valores impares não são emplihados");
					break;
				}
    			case 2:{
					desempilha(&pilha);
					break;
				}
				case 3:{
					printf("\nO topo da pilha é");
					mostra_valor_topo(&pilha);
					break;
				}
				case 4:{
					imprimirPilha(&pilha);
					break;
				}
				default:{
					printf("\nOpção inválida");
					break;
				}
    			
			}
		}
	while (op!=0);
	return 0;
	} 
	
	
	


