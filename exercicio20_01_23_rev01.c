/*Faça um sistema para gerenciar os produtos (código, nome e preço)
de um supermercado utilizando uma lista simplesmente encadeada,
apresentando ao usuário as seguintes opções:
	1- Cadastrar produto
	2- Exibir a lista de produtos
	3- Buscar um produto
	4- Remover um produto
	5- Sair
Você deve implementar procedimentos e/ou funções para as funcionalidades de
uma lista encadeada.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no{
    int codigo;
    char *nome;
    float preco;
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

void inserirInicio(int codigo, char *nome, float preco){
    no *aux;
    aux = (no*) malloc(sizeof(no));
    if (aux != NULL){
        aux ->codigo= codigo;
        aux ->nome= nome;
        aux ->preco= preco;
        aux -> prox = inicioL;
        inicioL = aux;
    }
}

void percorrer () {
    if(!lista_vazia()){
        no * aux;
        aux = inicioL;
        while (aux!= NULL) {
            printf("\n%d", aux->codigo);
            printf("\n%s", aux->nome);
            printf("\n%f", aux->preco);
            aux = aux->prox;
        }
    }
    else{
        printf("\n Lista vazia!\n");
    }
}


void BuscaProduto(int valor){
     if(!lista_vazia()){
        int resposta=0;
		no * aux;
        aux = inicioL;
        while (aux!= NULL) {
			if (aux->codigo==valor){
				resposta=1;
				printf("\n%d", aux->codigo);
            	printf("\n%s", aux->nome);
            	printf("\n%f", aux->preco);
            	aux=aux->prox;
            }
            else 
                aux=aux->prox;
				
        }
        if (aux==NULL && resposta==0)
            printf("\n Produto nao  esta na lista ");
    
    }
}


void remover(int valor){
    no* ant = NULL;
    no* aux = inicioL;
    if (!lista_vazia() ) {
    //procura elemento na lista, guardando o anterior
        while ((aux!=NULL) && (aux->codigo!=valor)) {
        ant = aux;
        aux = aux -> prox;
        }
        if (aux == NULL)
            printf("Elemento não encontrado!");
            else{ /* retira elemento */
        if (ant == NULL)
            inicioL= aux-> prox;
        else
            ant -> prox = aux-> prox;
            free(aux);
            }
    }
    else
        printf("ista vazia!");
    }

//menu de opções
int menu ()
{
    int op;

    printf ("\n ==== MENU DE OPCOES ====\n");
    printf ("0 - SAIR \n");
    printf ("	1- Cadastrar produto\n");
    printf ("2- Exibir a lista de produtos\n");
    printf ("3- Buscar um produto\n");
    printf ("4- Remover um produto\n");
    printf ("5- Sair\n");
    printf ("O que deseja fazer? ");
    scanf ("%d", &op);
    fflush(stdin);

    return op;
}


int main (){
	int valor,op;
    inicializa_lista();
    do{
    	op=menu();
    	switch (op)
    		{
            case 0:		//5- código para sair
            break;
			case 1:		//1- Cadastrar produto
            break;
        	case 2:		//2- Exibir a lista de produtos
            break;
			case 3:		//3- Buscar um produto
           	break;
            case 4:		//4- Remover um produto
            break;  
            default:    //opção inválida
            printf ("----- OPCAO INVALIDA -----");}
		}while (op != 0);
    		return 0;
		
}

