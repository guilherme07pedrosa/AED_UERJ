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
            printf("%d", aux->info);
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



int main()
{
    
    int valor,op,n;
    inicializa_lista();
    do{
        printf("\n1-Inserir no inicio\n2-Percorrer\n3-Soma os nos \n4-Numero de nos \n5-Numero de nos maior que n");
        printf("\n6-Ultimo elemento\n7-Inserir no fim\n8-Sair");
        printf("\nInforme sua alternativa: ");
        scanf("%d", &op);
        if (op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 && op!=7 && op!=8)
            printf("\nAlternativa incorreta");
        else 
            if(op==1){
                printf("\nValor: ");
                scanf("%dvalor", &valor);
                inserirInicio(valor);
        	}
        	else {
            	if(op==2){
                	percorrer();
                
            	}
        		else {
            		if(op==3){
                	printf("\nA soma dos nos  e : %d", Soma_No ());
                
            		}
					else {
						if (op==4){
						printf("\nO numero de nos  e : %d", Numero_De_Nos ());
						}	
        				else{
							if (op==5){
								printf("\nValor de n: ");
                				scanf("%dn", &n);
                				printf("\n Numero de nos maiores que n %d",  Numero_De_Nos_maior_que_n (n));
							}
							
							else{
								if (op==6){
									printf("\nUlimo elemento %d",  Ultimo_No ());;
								}
								else {
              						if(op==7){
                					printf("\nValor: ");
                					scanf("%dvalor", &valor);
                					inserir_fim(valor);
                					}  
                					else 
                						printf("\nEncerrado");    
						 		}	
        					}
						}		
    				}
				}
			}
		}	
	
	
	while (op!=8);
    return 0;
}

