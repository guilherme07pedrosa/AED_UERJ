/*2. Com base nas fun��es b�sicas para manipula��o de pilhas, fa�a um programa que leia 15 
n�meros e proceda, para cada um deles, como segue:
- se o n�mero for par, insira-o na pilha;
- se o n�mero lido for �mpar, retire um n�mero da pilha;
- Ao final, esvazie a pilha imprimindo os elementos.
*/
#include <stdio.h>
#define MAX 15

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



//esvazia e imprime
void imprimirPilha(pilhaSeq *pilha){
	while (!pilha_vazia(pilha->topo)){
		printf("\nValor %d dempilhado!\n",pilha->valores[pilha->topo]);
		(pilha->topo)--;
	}
	
}

//menu

int menu(){
	int op;
	printf ("\n ==== MENU DE OPCOES ====\n");
    printf ("0 - SAIR \n");
    printf ("1 - EMPLILHAR \n");
    printf ("2 - DESEMPILHAR \n");
    printf ("3 - MOSTRAR TOPO \n");
    printf ("4 - DESEMPILHAR IMPPRIMIMDO OS  VALORES DA PILHA \n");
    printf ("O que deseja fazer? ");
    scanf ("%d", &op);
    fflush(stdin);

    return op;
	}

//fun��o principal
int main()
{
    pilhaSeq pilha[MAX];
    int topo;
    int op;
    int valor;
    inicializa_pilha(&pilha->topo);
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
							empilha(pilha,valor);
						else 
							printf("/n valores impares n�o s�o emplihados");
					break;
				}
    			case 2:{
					desempilha(pilha);
					break;
				}
				case 3:{
					printf("\nO topo da pilha �");
					mostra_valor_topo(pilha);
					break;
				}
				case 4:{
					imprimirPilha(pilha);
					break;
				}
				default:{
					printf("\nOp��o inv�lida");
					break;
				}
    			
			}
		}
	while (op!=0);
	return 0;
	} 
	
	
	


