/*Considerando as fun��es definidas para uma lista simplesmente encadeada, implemente e
teste as seguintes fun��es:
1. Escreva uma fun��o que calcule a soma das chaves dos n�s de uma lista encadeada.
2. Fa�a um programa que implemente uma fun��o que calcule o n�mero de n�s de uma lista
encadeada.
3. Considere uma lista encadeada de valores inteiros e implemente uma fun��o para
retornar o n�mero de n�s da lista que possuem o campo info com valores maiores do que n.
4. Implemente uma fun��o que retorne o valor armazenado no �ltimo n� de uma lista
encadeada de n�meros inteiros.
5. Considere listas de valores inteiros e implemente uma fun��o que dada uma lista
encadeada e um valor inteiro n, retire da lista todas as ocorr�ncias de n retornando a lista
resultante. Ao final, o programa deve imprimir a lista resultante.
6. Implemente uma fun��o que dados um valor e uma posi��o, a fun��o insere o elemento
valor na posi��o pos da lista simplesmente encadeada. Para isso, um novo n� deve ser
alocado e ligado aos demais. O valor de pos � um n�mero, que ser for 2, por exemplo, indica
que o novo n� alocado ser� o segundo n� da lista.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int info;
    struct no *prox;
}no;
no *inicioL;


void inicializa_lista () {
    inicioL = NULL;
}

int lista_vazia () {
    if (inicioL== NULL)
        return 1;
    return 0;
}


void inserirInicio(int valor){
    no *aux;
    aux = (no*) malloc(sizeof(no));
    if (aux != NULL){
        aux ->info= valor;
        aux -> prox = inicioL;
        inicioL = aux;
    }
}

void percorrer () {
    if(!lista_vazia()){
        no * aux;
        aux = inicioL;
        while (aux!= NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
    else{
        printf("\n Lista vazia!\n");
    }
}

//Quest�o 1 soma dos n�s (fun��o)

int Soma_No () {
    int soma=0;
	if(!lista_vazia()){
        no * aux;
        aux = inicioL;
        while (aux!= NULL) {
            soma =soma+ aux->info;
            aux = aux->prox;
        }
    	return soma;
	}
	else 
		return 0;
}
//Quest�o 2 n�mero de n�s(fun��o)
int Numero_De_Nos () {
    int ContaNo =0;
	if(!lista_vazia()){
        no * aux;
        aux = inicioL;
        while (aux!= NULL) {
            ContaNo++;
            aux = aux->prox;
        }
		return ContaNo;
	}
	
    else
    	return 0;
        
    
}

//Quest�o 3 retorna o numero de Nos maior que 'n'(fun��o)
int Numero_De_Nos_maior_que_n (int n) {
    int ContaNoMaiorQueN =0;
    int Compara;
	if(!lista_vazia()){
        no * aux;
        aux = inicioL;
        while (aux!= NULL) {
            Compara=aux->info;
			aux = aux->prox;
        	if (Compara>n)
        		ContaNoMaiorQueN++;
        		
        }
		return ContaNoMaiorQueN;
	}
	
    else
    	return 0;
        
    
}

//Quest�o 4 ultimo No
int Ultimo_No () {
	int ultimo;
	if(!lista_vazia()){
        
		no * aux;
        aux = inicioL;
        while (aux!= NULL) {
            aux->info;
           // printf("\n%d",aux->info);
            ultimo = aux->info;
			aux = aux->prox;
        }
    	return ultimo;
	}
		
	else 
		printf("Lista vazia");
}




void inserir_fim (int valor) {
    no *aux, *p;
    aux = (no*) malloc(sizeof(no));
    if (aux != NULL){
        aux ->info= valor;
        aux -> prox = NULL;
        if (lista_vazia()){
            inicioL=aux;
        }
    else{
        p = inicioL;
        while (p->prox != NULL)
        p = p -> prox;
        p->prox = aux;
    }
    }
}

//Quest�o 5 remove todos os elementos de um dado valor
int RemoverValores(int valor){
    int loop=0;
	do {
	no* ant = NULL;
    no* aux = inicioL;
	
	if (!lista_vazia() ) {
    //procura elemento na lista, guardando o anterior
        while ((aux!=NULL) && (aux->info!=valor)) {
        ant = aux;
        aux = aux -> prox;
        }
        if (aux == NULL){
		//	printf("Elemento n�o encontrado!");
            loop=1;}
		else{ /* retira elemento */
            if (ant == NULL)
            	inicioL= aux-> prox;
        	else
            	ant -> prox = aux-> prox;
            	free(aux);
            	//printf("\nElemento removido!");
            }
    }
    else
        printf("Lista vazia!");
	}while ((loop==0)&&(lista_vazia()!=1));
	printf("\nElementos de valor  %d",valor );
	printf(" removidos da lista");
	return 0;
} 

//Quest�o 6 insere No na posi��o pos
int ContaNo () {
    int conta_no=0;
	if(!lista_vazia()){
        no * aux;
        aux = inicioL;
        while (aux!= NULL) {
            aux = aux->prox;
            conta_no++;
        }
    }
    else{
        conta_no=0;
	}
    return conta_no;
}

int InsereNaPosicao(int valor, int pos){
    int i;
	no *aux, *p;
    aux = (no*) malloc(sizeof(no));
    if (aux != NULL){
        aux ->info= valor;
        aux -> prox = NULL;
        if (lista_vazia()){
            inicioL=aux;
        }
    else 
    	if (pos==1)
    		inserirInicio(valor);
    	
		else{
        p = inicioL;
        for (i=0;i<pos-2;i++)
        	p = p -> prox;
        aux->prox=p->prox;
        p->prox=aux;
    }
    }
    return 0;
}
		
	




int main()
{
    
    int valor,op,n=2;
    inicializa_lista();
   // ContaNo();
    //inserirInicio(4);
	inserirInicio(3);
    inserirInicio(2);
    inserirInicio(1);
    ContaNo();
   // percorrer ();
    printf("\n");
  //  RemoverValores(3);
    printf("\n");
   	printf("\n\n TESTE 1");
	InsereNaPosicao(10, 1);
    printf("\n");
	percorrer ();
    printf("\n\n TESTE 2");
    InsereNaPosicao(10, 2);
    printf("\n");
	percorrer ();
    printf("\n\n TESTE 3");
    InsereNaPosicao(10, 3);
    printf("\n");
	percorrer ();
   
    return 0;
}
