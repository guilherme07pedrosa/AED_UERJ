/******************************************************************************

Elabore um programa que, considerando um vetor de 10 posições de
inteiros, apresente as seguintes opções de operações para o usuárioi:
1- Preencher o vetor
2- Buscar por um valor:
a) tipo de busca 1 (a definir)
b) tipo de busca 2 (a definir)
3- Ordenar o vetor:
a) tipo de ordenação 1 (a definir)
b) tipo de ordenação 2 (a definir)
4- Sair

*******************************************************************************/
#include <stdio.h>
//#include <conio.h>
#define N 10




typedef struct listaSeq{
    int valores[N];
    int n;
}listaSeq;

//função para inicializar a lista
void inicializar (listaSeq* L){
	L->n =0;
} 

//Inserir elementos
void inserir(listaSeq *L, int valor)
{
    L->valores[L->n] = valor;
    (L->n)++;
}

//Exibir elementos do vetor
void exibirLista(listaSeq L){
    int i;
	printf("\nVetor: [");
    if(L.n > 0)
    {
        for(i = 0; i < L.n ; i++)
        {
            if(i < L.n - 1)
            {
                printf("%d, ",L.valores[i]);
            }
            else
            {
                printf("%d]\n",L.valores[i]);
            }
        } 
    }
    else
    {
        printf("\nLista vazia!");
    }
}

//função para cadastrar os numeros do vetor
void cadastra_vet(listaSeq * vet, int n)
{
    int v,i;
    vet->n = 0;
    printf("\n");

    for (i = 0; i < N; i++)
    {
        printf ("Entre com o numero do vetor: ");
        scanf("%d", &v);
        fflush(stdin);
        inserir(vet, v);
    }
}


//função para cadastrar os numeros do vetor
int cadastra_elem (int x)
{
    printf ("\nEntre com elemento desejado: ");
    scanf ("%d", &x);
    return x;
}

//função para buscar um elemento na lista
int busca (listaSeq vet, int x){
    int i;
	for (i = 0; i < N; i++)
    {
        if (x == vet.valores[i])
        return i;
    }
    return -1;
}

//função para busca binaria
int buscaBinaria(listaSeq * vet, int elem){
    int i, inicio, meio, final;
    inicio=0;
    final=N-1;
    while(inicio<=final){
        meio=(inicio+final)/2;
        if (elem<vet->valores[meio])
            final = meio-1;
        else 
            if (elem>vet->valores[meio])
                inicio =meio +1;
            else 
                return meio;
    }
    
return -1;	
    
}

// função para ordenar um vetor
void selectionSort(listaSeq * vet)
{
    int i, j, menor, troca;
    for (i=0;i<N-1;i++)
    {
        menor = i;
        for (j = i + 1; j < N; j++)
        {
            if(vet->valores[j] < vet->valores[menor])
            {
                menor = j;
            } 
        }

        if(menor != i)
        {
            troca = vet->valores[i];
            vet->valores[i] =vet->valores[menor];
            vet->valores[menor] = troca;
        }
    }
}	

//procedimento resultado da busca
void resultado_busca(int res, int x){

	if (res < 0)
		printf ("\nO elemento procurado nao esta na lista\n");
	else 
		printf ("\nO elemento %d esta na posicao %d\n", x, res);
}

//procedimento quickSort
void quickSort(listaSeq * vet, int inicio, int fim)
{
    int pivo;
    if (fim > inicio)
    {
        pivo = particiona(vet->valores, inicio, fim);
        quickSort(vet, inicio, pivo - 1);
        quickSort(vet, pivo + 1, fim);
    }
}

int particiona(listaSeq*vet, int inicio, int final){
    int esq, dir, pivo, aux;
    esq=inicio;
    dir=final;
    pivo=vet->valores[inicio];
    while (esq<dir){
        while (vet->valores[esq]<=pivo)
            esq++;
        while (vet->valores[dir]>pivo)
            dir--;
        if (esq<dir){
            aux=vet->valores[esq];
            vet->valores[esq]=vet->valores[dir];
            vet->valores[dir]=aux;
        }
    }
    vet->valores[inicio]=vet->valores[dir];
    vet->valores[dir]=pivo;
    return dir;
}

//menu de opções
int menu ()
{
    int op;

    printf ("\n ==== MENU DE OPCOES ====\n");
    printf ("0 - SAIR \n");
    printf ("1 - CADASTRAR UM NOVO VETOR\n");
    printf ("2 - IMPRIMIR O VETOR\n");
    printf ("3 - BUSCAR POR UM ELEMENTO DO VETOR PELA BUSCA SIMPLES\n");
    printf ("4 - BUSCAR POR UM ELEMENTO DO VETOR PELA BUSCA BINARIA\n");
    printf ("5 - ORDENAR O VETOR POR SELECTIONSORT\n");
    printf ("6 - ORDENAR O VETOR POR QUICKSORT\n");
    printf ("O que deseja fazer? ");
    scanf ("%d", &op);
    fflush(stdin);

    return op;
}

int main()
{
    listaSeq vet;
	int res;
    int op;
    int x;
    int inicio=0;
    int fim =N-1;
    inicializar (& vet);

    cadastra_vet(&vet, N);

    do{
        op = menu();
        switch (op)
        {
            case 0:		//código para sair
            break;

            case 1:		//código para cadastrar
                cadastra_vet(&vet, N);
                break;
                
            case 2:		//Imprimir o vetor
                exibirLista(vet);
                break;
        
        case 3:		//busca de um elemento no vetor por busca simples
            x = cadastra_elem(x);
            busca(vet, x);
            res = busca(vet,x);
            resultado_busca(res, x);
            exibirLista(vet);
            break;
            
        case 4:	//busca de um elemento no vetor por busca binaria
            x = -1;
            printf("\nPara o busca binaria o vetor precisa ser ordenado, deseja continuar?\n");
            do{
                printf("1 para Sim 0 para Nao: ");
                scanf("%d", &x);
                if(x < 0 || x > 1)
                {
                    printf("Opcao invalida:\n");
                }
            }while(x < 0 || x > 1);
            
            if(x == 1)
            {
                do{
                    printf("\n0 - ORDENAR O VETOR POR SELECTIONSORT\n"
                    "1 - ORDENAR O VETOR POR QUICKSORT\n"
                    "O que deseja fazer? ");
                    scanf("%d", &res);

                    if(x < 0 || x > 1)
                    {
                        printf("Opcao invalida:\n");
                    }
                }while(x < 0 || x > 1);

                if(x == 1)
                {
                    selectionSort(&vet);
                }
                else
                {
                    quickSort(&vet, inicio, fim);
                }
                printf("\nVetor ordenado: \n");
                x = cadastra_elem(x);
                res = buscaBinaria(&vet, x);
                exibirLista(vet);
                resultado_busca(res, x);
            }
            break;

        case 5:		//ordenar o vetor por selectionSort
            selectionSort(&vet);
            exibirLista(vet);
            break;

        case 6:		//ordenar o vetor por quickSort

            quickSort(&vet, inicio, fim);
            exibirLista(vet);
            break; 
  
        default:    //opção inválida
            printf ("----- OPCAO INVALIDA -----");
        }
    }while (op != 0);

    return 0;

}
