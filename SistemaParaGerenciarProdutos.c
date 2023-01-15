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
            printf("\n Dados do produto");
			printf("\nCodigo: ");
			printf("%d", aux->codigo);
			printf("\nNome: ");
            printf("%s", aux->nome);
            printf("\nPreco: ");
            printf("%0.2f",aux->preco);
            aux = aux->prox;
        }
    }
    else{
        printf("\n Lista vazia!\n");
    }
}


no *BuscaProduto(int valor){
     if(!lista_vazia()){
        no * aux;
        aux = inicioL;
        while (aux!= NULL) {
            if (aux->codigo==valor){
				printf("\n Dados do produto");
				printf("\nCodigo: ");
				printf("%d", aux->codigo);
				printf("\nNome: ");
            	printf("%s", aux->nome);
            	printf("\nPreco: ");
            	printf("%0.2f",aux->preco);
                return (aux);
        	}
        	else 
                aux=aux->prox;
        }
        if (aux==NULL)
            printf("\n Este Produto Nao esta na lista! ");
		}
		else 
			printf("\n Nenhum Produto Na Lista! ");
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
            printf("\nProduto removido!");
            }
    }
    else
        printf("Lista vazia!");
    }

//menu de opções
int menu ()
{
    int op;

    printf ("\n ==== MENU DE OPCOES ====\n");
    printf ("1- Cadastrar produto\n");
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
	int codigo,op;
	float preco;
	char nome[50], ch;
	no*aux;
	
    inicializa_lista();
    do{
    	op=menu();
    	switch (op)
    		{
            case 5:		//0- código para sair
            printf("\nPrograma fechado");
            break;
			case 1:		//1- Cadastrar produto
				printf("_________________________________\n");
				printf("Voce Selecionou Adicionar Produto\n");
				printf("_________________________________\n");
				printf("\nNome do Produto: ");
				scanf(" %[^\n]s", &nome[100]);
				printf("\nPreco do Produto: ");	
				scanf("%f", &preco);
				printf("\nCodigo do Produto: ");
				scanf("%d", &codigo);
				inserirInicio(codigo, &nome[100], preco);
				
                
			break;
        	case 2:		//2- Exibir a lista de produtos
        		printf("__________________________________\n");
				printf("Voce Selecionou Listar os Produtos\n");
				printf("__________________________________\n");
        		percorrer ();
               
            break;
			case 3:		//3- Buscar um produto
				printf("__________________________________\n");
				printf("Voce Selecionou Buscar um  Produto\n");
				printf("__________________________________\n");
				printf("\nDigite o valor do codigo do produto: ");
				scanf("%d", &codigo);
				BuscaProduto(codigo);

                
           	break;
            case 4:		//4- Remover um produto
            	printf("__________________________________\n");
				printf("Voce Selecionou Remover um  Produto\n");
				printf("__________________________________\n");
				printf("\nDigite o valor do codigo do produto: ");
				scanf("%d", &codigo);
				remover(codigo);
				
              
            break;  
            default:    //opção inválida
            printf ("----- OPCAO INVALIDA -----");}
		}while (op != 5);
    		return 0;
		
}

