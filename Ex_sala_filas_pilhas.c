/******************************************************************************

Faça um programa que implemente uma fila sequencial . 
O usuários deverá informar os números inteirosd que serão iseridos na fila. Ao final da leitura de dados
, o programa deverá inverter a ordem dos elementos na fila, isto é, os últimos seão os primeiros. 
Você pode utilizar estruturas de dados auxiliares dentre as que já foram vistas. Decida que estrutura de dados poderá 
auxiliar nossa tarefa.

*******************************************************************************/
#include <stdio.h>
#define M 3

//estrutura fila
typedef struct filaSeq{
	int valores[M];
	int i, f, n;
} filaSeq;


//estrutura pilha
typedef struct pilhaSeq{
int valores[M];
int topo;
} pilhaSeq;


//inicializa uma pilha 
void inicializa_pilha(int *topo){
*topo = -1;
}


//verifica se a pila esta cheia
int pilha_cheia(int topo){
return(topo==M-1);
}

//verifica se a pilha esta vazia
int pilha_vazia(int topo){
return(topo==-1);
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


//mostra o topo da pilha
int mostra_valor_topo(pilhaSeq *pilha){
if(!pilha_vazia(pilha->topo)){
printf("\nTopo da pilha: %d\n",pilha->valores[pilha->topo]);
}
else{
printf("\nPilha vazia.\n");
}
}


//mostra o topo da pilha
int SaiPrimeiro(pilhaSeq *pilha){
if(!pilha_vazia(pilha->topo)){
printf("\n Veja quem sai primriro: %d\n",pilha->valores[pilha->topo]);
}
else{
printf("\nFim.\n");
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

//mostrar próxima da fila
void mostrar_Proximo(filaSeq *fila){
	int i;
	if(!fila_vazia(fila->n)){
		printf("\nProximo da fila: %d.\n",fila->valores[fila->i]);//alterado o código da professora
	}
	else{
		printf("\nFila vazia!\n");
	}
}


//mostrar último da fila
void mostrar_Ultimo(filaSeq *fila){
	int f;
	if(!fila_vazia(fila->n)){
		printf("\nUltimo da fila: %d.\n",fila->valores[fila->f]);//alterado o código da professora
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
		fila->valores[fila->f]=valor;//porque não no início?
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
		if(fila->n==1){//um só elemento na fila
			fila->i =-1;
			fila->f =-1;
		}
		else{//Mais de um elemento armazenado
			if(fila->i==M-1) //Última posição
				fila->i=0;
			else //Qualquer posição
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
		if(fila->n==1){//um só elemento na fila
			fila->f =-1;
			fila->i =-1;
		}
		else{//Mais de um elemento armazenado
			if(fila->f==M-1) //Última posição
				fila->f=0;
			else //Qualquer posição
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



//função principal
int main(){
	filaSeq fila[M];
	pilhaSeq pilha[M];
	int x=1,y=2,z=3, sair_primeiro;
	inicializa_fila(&fila->i,&fila->f);
	inicializa_pilha(&pilha->topo);
    enfileirar(fila,x );
    empilha(pilha, x);
    enfileirar(fila,y );
    empilha(pilha, y);
    enfileirar(fila,z );
    empilha(pilha, z);
    exibirLista(fila);
    desenfileirar(fila);
    exibirLista(fila);
    imprimirPilha(pilha);
    SaiPrimeiro(pilha);
	desempilha(pilha);
	SaiPrimeiro(pilha);
	desempilha(pilha);
	SaiPrimeiro(pilha);
    return 0;

}
