/*
Exerc�cio
Utilizando as funcionalidades trabalhadas sobre listas sequenciais, fa�a um programa para
gerenciar os dados dos alunos de uma turma. A capacidade m�xima de alunos � 30 e os
dados a serem armazenados s�o: matr�cula, nome, cpf, telefone. Voc� deve apresentar um
menu de op��es com as funcionalidades disponibilizadas. Considere que a lista n�o
armazena os dados de modo ordenado.
Exemplo:
*** Sistema de alunos ***
1- Cadastrar aluno
2- Buscar aluno pela matr�cula
3- Exibir os dados dos alunos
4- Remover um aluno
5- Sair*/


#include <stdio.h>
#define max 6
typedef struct Aluno{
    int matriculas[max];//chave para busca
    char *nome;
    int telefone;
    int n; //indice para percorrer o vetor
}Aluno;

//fun��o para inicializar a lista
void inicializar (Aluno* A){
	A->n =0;
}
//fun��o para exibir a lista impressa	
void exibirLista(Aluno A){
    int i,j;
    if(A.n>0){
       for(i=0;i<A.n;i++){
        printf("\n N�mero de matricula %d ",A.matriculas[i]);
		printf("\n Nome %s",A.nome);
        printf("\n Telefone %d ",A.telefone);
       } 
    }
    else{
        printf("\n Lista vazia!");
    }
}
//fun��o para buscar um aluno pela chave matricula
int buscarMatricula(Aluno A, int matricula){
	int i;
    for(i=0;i<A.n;i++){
        if(A.matriculas[i] == matricula){
            return i;
        }
    }
    return -1;
}

//fun��o para inserir um aluno 
void inserir(Aluno *A, int matricula, int telefone, char *nome){
if(A->n < max){
    if(buscarMatricula(*A,matricula)==-1){
        A->matriculas[A->n] = matricula;
        A->telefone = telefone;
        A->nome = nome;
        (A->n)++;
    }
    else{
        printf("\nElemento j� est� cadastrado!");
    }
    
}
else{
    printf("\nLista cheia!!!");

}
}	

//fun��o para remover um aluno da lista
void remover(Aluno*A, int matricula){
if(A->n>0){
    int pos = buscarMatricula(*A,matricula);
    if(pos!=-1){
        A->matriculas[pos] = A->matriculas[(A->n)-1];
        (A->n)--;
    }
    else{
        printf("\nMatricula n�o est� na lista!");
    }
}
else{
    printf("\nLista vazia!");
}
}
//menu de op��es
int menu ()
{
int op;

printf ("\n\n ==== MENU DE OPCOES ====\n");
printf ("0 - SAIR \n");
printf ("1 - CADASTRAR ALUNOS \n");
printf ("2 - BUSCAR ALUNOS PELA MATRICULA \n");
printf ("3 - EXIBIR OS DADOS DOS ALUNOS\n");
printf ("4 - REMOVER ALUNO PELA MATRICULA\n");
printf ("\nO que deseja fazer? ");
scanf ("%d", &op);

return op;
}	
//fun��o principal
int main(){
	Aluno A;
	int op;
	inicializar (&A);
	int mat, te;
	char nm[20];
	
	do
    {
        op = menu ();
        switch (op)
        {
    case 0:		//c�digo para saior
        break;

    case 1:		//cadastrar alunos

        {
        
		printf("\n Matricula: ");
		fflush(stdin);
		scanf("%d", &mat);
		printf("\n Telefone: ");
		fflush(stdin);
		scanf("%d",&te);
		printf("\n Nome: ");
		fflush(stdin);
		scanf("%s",&nm);
		fflush(stdin);
		inserir(&A, mat ,te,nm);
        break;
        }

    case 2:		//busca der um aluno pela matricula
    
        {
        printf("\n Matricula: ");
		fflush(stdin);
		scanf("%d", &mat);
		buscarMatricula(A,mat);
        break;
        }
        
    case 3:		//exibir a lista
        {
        exibirLista(A);
        break;
        }
        
     case 4:	//remover um alunio da lista
        {
        printf("\n Matricula: ");
		fflush(stdin);
		scanf("%d", &mat);
		remover(&A,mat);
        break;
        }
        
    default:    //op��o invalida
        printf ("----- OPCAO INVALIDA -----");
        }
    }
    while (op != 0);

    return 0;

}




