/*3. Fa�a uma fun��o/procedimento de manipula��o de listas sequenciais para cada item 
abaixo:
a) inserir um dado elemento na primeira posi��o de uma lista;
b) inserir um dado elemento na �ltima posi��o de uma lista;
c) modificar um elemento de uma lista, sendo dado a sua posi��o e o novo valor;
d) remover o primeiro elemento de uma lista;
e) remover o �ltimo elemento de uma lista;
f) remover um elemento dado o seu valor.
g) imprimir toda a lista*/
#include <stdio.h>
#define max 6
#include <stdio.h>
#define M 5

//estrutura fila
typedef struct filaSeq{
	int valores[M];
	int i, f, n;
} filaSeq;

//inicializa fila
void inicializa_fila(int *i, int *f){
	*i = -1;
	*f = -1;
}

//fila vazia
int fila_vazia(int n){
	if (n==0)
		return 1;
	return 0;
}

//fila cheia
int fila_cheia(int n){
	if (n==M)
		return 1;
	return 0;
}

//mostrar pr�xima da fila
void mostrar_Proximo(filaSeq *fila){
	int i;
	if(!fila_vazia(fila->n)){
		printf("\nProximo da fila: %d.\n",fila->valores[fila->i]);//alterado o c�digo da professora
	}
	else{
		printf("\nFila vazia!\n");
	}
}


//mostrar �ltimo da fila
void mostrar_Ultimo(filaSeq *fila){
	int f;
	if(!fila_vazia(fila->n)){
		printf("\nUltimo da fila: %d.\n",fila->valores[fila->f]);//alterado o c�digo da professora
	}
	else{
		printf("\nFila vazia!\n");
	}
}

//enfileirar
void enfileirar(filaSeq *fila, int valor ){
	if(!fila_cheia(fila->n)){
		if(fila->f==M-1)
			fila->f=0;
		else
			(fila->f)++;
		fila->valores[fila->f]=valor;//porque n�o no in�cio?
			if((fila->i)==-1)
		(fila->i)++;
		(fila->n)++;
		printf("\nValor enfileirado!\n");
	}
	else
		printf("\nFila cheia!\n");
}

//furarfila
void furarfila(filaSeq *fila, int valor ){
	if(!fila_cheia(fila->n)){
		if(fila->i==M-1)
			fila->i=0;
		else
			(fila->i)++;
		fila->valores[fila->i]=valor;
			if((fila->f)==-1)
		(fila->f)++;
		(fila->n)++;
		printf("\nValor enfileirado!\n");
	}
	else
		printf("\nFila cheia!\n");
}




//desinfileirar
void desenfileirar(filaSeq *fila){
	if(!fila_vazia(fila->n)){
		printf("\nValor %d desenfileirado!\n", fila->valores[fila->i]);
		if(fila->n==1){//um s� elemento na fila
			fila->i =-1;
			fila->f =-1;
		}
		else{//Mais de um elemento armazenado
			if(fila->i==M-1) //�ltima posi��o
				fila->i=0;
			else //Qualquer posi��o
				(fila->i)++;
			}
		(fila->n)--;
	}
	else
		printf("\nFila vazia!\n");
}


//desenfileirar pelo ultimo
void desenfileirarUltimo(filaSeq *fila){
	if(!fila_vazia(fila->n)){
		printf("\nValor %d desenfileirado!\n", fila->valores[fila->f]);
		if(fila->n==1){//um s� elemento na fila
			fila->f =-1;
			fila->i =-1;
		}
		else{//Mais de um elemento armazenado
			if(fila->f==M-1) //�ltima posi��o
				fila->f=0;
			else //Qualquer posi��o
				(fila->f)--;
			}
		(fila->n)--;
	}
	else
		printf("\nFila vazia!\n");
}



//exibir fila 
void exibirLista(filaSeq *fila)
{
	int j;
	int i, f, n;
	if (fila_vazia(fila->n))
	{
		printf("Fila vazia\n");
		return;
	}
	i = fila->i;
	n = fila->n;
	f = (i + n - 1) % M;
	printf("Inicio[%d]->",i); // imprime o ini
	for (j=i; j!=f; j=(j+1)%M)
		printf("%d ", fila->valores[j]);
	printf("%d ", fila->valores[j]); // imprime o ultimo
	printf("<-[%d]Fim\n",f); // imprime o fim
}





//fun��o principal
int main(){
	filaSeq fila[M];
	int valor, op;
	inicializa_fila(&fila->i,&fila->f);
	do{
			printf("\n1- Enfileirar");
			printf("\n2- Desenfileirar");
			printf("\n3- Mostrar proximo");
			printf("\n4- Mostrar ultimo");
			printf("\n5- Furarfila");
			printf("\n6- Desenfileirar pelo ultimo");
			printf("\n7- Exibir fila");
			printf("\n8- Sair");
			printf("\nInforme sua opcao: ");
			scanf("%d",&op);
			switch (op){
		case 1:{
			printf("\nInforme o valor a enfileirar: ");
			scanf("%d",&valor);
			enfileirar(fila,valor);
			break;
		}
		case 2:{
			desenfileirar(fila);
			break;
		}	
		case 3:{
			mostrar_Proximo(fila);
			break;
		}	
		case 4:{
			mostrar_Ultimo(fila);
			break;
		}
		case 5:{
			printf("\nInforme o valor a furalfila: ");
			scanf("%d",&valor);
			furarfila(fila,valor);
			break;
		}
		case 6:{
			desenfileirarUltimo(fila);
			break;
		}
		case 7:{
			exibirLista(fila);
			break;
		}
		case 8:{
			printf("\nFinalizando...\n");
			break;
		}
		default:{
			printf("\nOp��o invalida!\n");
			break;
		}
	}
	}
	while(op!=8);
		return 0;
}

