#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------
#define tamanho 2 // tamanho maximo da FILA
#define tamanho2 5 //tamanho colunas

/* -----------------------------------------------------------------------------
Estrutura FILA ESTATICA
------------------------------------------------------------------------------*/
typedef struct fila
{
    int item[tamanho];
    int inicio, fim;
} T_FILA;
int inicializa(T_FILA *f);
int verifica_vazio(T_FILA f);
int remover(T_FILA *f);
int verifica_cheio(T_FILA f);
int insere(T_FILA *f, int x);
int listar(T_FILA f);

/* -----------------------------------------------------------------------------
Estrutura pilha
------------------------------------------------------------------------------*/
typedef struct no_pilha
{
    int dado;
    struct no_pilha *prox;
} Tno_pilha;
int Inicializar_pilha(Tno_pilha **inicio);
int Inicializar2_pilha(Tno_pilha **inicio);
int Inserir_topo(Tno_pilha **inicio, int info);
int Remover_topo(Tno_pilha **inicio);
int Obter_topo(Tno_pilha *inicio, int *dado);
int Verifica_vazio(Tno_pilha *inicio, int *resp);
int Juntar_pilhas(Tno_pilha **P1, Tno_pilha **P2, Tno_pilha **P3);

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES

    Dicionário da semana;
    Segunda = 1; Terça = 2; Quarta = 3; Quinta = 4; Sexta = 5
------------------------------------------------------------------------------*/
typedef struct no_ls
{
    char dado[100];
    struct no_ls *prox;
} Tno_ls;

int Inicializar_LS(Tno_ls **P_inicio);
int Inserir_inicio_LS(Tno_ls **P_inicio, int info);
int Remover_inicio_LS (Tno_ls **inicio);
int Remover_fim_LS (Tno_ls **inicio);
int Remover_meio_LS (Tno_ls **inicio, int pos);
int Inserir_fim_LS(Tno_ls **P_inicio, char info[100]);
int Inserir_meio_LS(Tno_ls **P_inicio, int info, int pos);
int Remover_inicio_LS(Tno_ls **P_inicio);
int Listar_LS (Tno_ls *inicio, int posicao);
int Obter_pos_LS(Tno_ls *CP_inicio, int dado, int *pos);
int Obter_Tamanho_LS(Tno_ls *CP_inicio, int *tam);
int Inverte_LS(Tno_ls **P_inicio);
int cadastrarNovoFolheto(Tno_ls *mtrFolhetos[tamanho][tamanho2], int lin, int col, Tno_ls *inicio);

/* -----------------------------------------------------------------------------
Estrutura MATRIZ
------------------------------------------------------------------------------*/
// struct matriz
// {
//     int **elemento;
//     int nlinhas;
//     int ncolunas;
// };
// typedef struct matriz Matriz;

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Limpa o buffer do teclado
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int main(int argc, char const *argv[])
{
    int opcaoMenu;     /* receber a opcao do usuario do menu principal*/
    int opcaosubmenu1; /* receber a opcao do usuario do submenu mercado*/
    int opcaosubmenu2; /* receber a opcao do usuario do submenu folheto*/
    int opcaosubmenu3; /* receber a opcao do usuario do submenu modificando folheto do submenu folheto*/
    Tno_ls *mtrFolhetos[tamanho][tamanho2]; /* matriz que armazena os folhetos */
    int erro; /* valor de erro retornado pelas funcoes */
    int contadorLista = 0;
    int indicemercado;
    int indicefolheto = 0, indicefolheto2 = 0, col = 0, posExclusao = 0;
    Tno_ls *ini,*ini2,*ini3,*ini4,*ini5,*ini6,*ini7,*ini8,*ini9,*ini10;
    char dado[100];
    do
    {
        system("cls");
        printf("-----------------------------------------------------------------------\n");
        printf("Trabalho de Estrutura de Dados I\n");
        printf("Gerenciamento de Mercados e Folhetos para Impressao\n");
        printf("-----------------------------------------------------------------------\n");
        printf("\nEscolha uma opcao do menu: \n\n");
        printf("1 - Gerenciar Folhetos e Imprimir\n");
        printf("0 - Sair \n\n");
        scanf("%d", &opcaoMenu); /* Ler a opcao do usuario */
        switch (opcaoMenu)
        {
        case 1:
            do
            {
                system("cls");
                printf("Escolha uma opcao do sub-menu: \n\n");
                printf("1 - Cadastrar Novo Folheto \n");
                printf("2 - Modificar Folheto Existente\n");
                printf("3 - Consultar Todos os Folhetos de um Mercado \n");
                printf("4 - Remover Folheto Especifico \n");
                printf("5 - Remover Todos os Folhetos de um mercado \n");
                printf("6 - Imprimir folhetos \n");
                printf("0 - Voltar \n\n");
                scanf("%d", &opcaosubmenu2);
                switch (opcaosubmenu2)
                {
                case 1:
                    do{
                        printf("\nDigite para qual mercado voce deseja criar um novo folheto (1 ou 2): ");
                        scanf("%d", &indicemercado);
                        if(indicemercado != 1 && indicemercado!=2){
                            printf("\nOpcao nao valida \n");
                            system("pause");
                        }
                    }while((indicemercado != 1 && indicemercado != 2));
                    indicemercado--;
                    if(contadorLista < 10){
                            if(indicemercado == 0){
                                if(indicefolheto > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS (&ini10);
                                    if(erro == 0){
                                            printf("Lista %d inializada\n",contadorLista+1);
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini10);
                                    if(erro == 0){
                                        printf("Folheto Novo Adicionado no Mercado 1\n");
                                        system("pause");
                                    }
                                    indicefolheto++;
                                }
                            }else{
                                if(indicefolheto2 > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS (&ini10);
                                    if(erro == 0){
                                            printf("Lista %d inializada\n",contadorLista+1);
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini10);
                                    if(erro == 0){
                                        printf("Folheto Novo Adicionado no Mercado 2\n");
                                        system("pause");
                                    }
                                    indicefolheto2++;
                                }
                            }
                        
                    }
                    else{
                        printf("Todos os folhetos dos dois mercados ja foram cadastrados\n");
                        system("pause");
                    }
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        printf("\nModificando Folheto Existente: \n\n");
                        printf("1 - Inserir novo produto\n");
                        printf("2 - Remover produto\n");
                        printf("3 - Consultar todos produtos cadastrados de um folheto\n");
                        printf("0 - Voltar \n\n");
                        scanf("%d", &opcaosubmenu3);
                        switch (opcaosubmenu3)
                        {
                        case 1:
                            do{
                                printf("\nDigite para qual mercado o folheto que voce ira adicionar o produto esta (1 ou 2): ");
                                scanf("%d", &indicemercado);
                                if(indicemercado != 1 && indicemercado!=2){
                                    printf("\nOpcao nao valida \n");
                                    system("pause");
                                }
                            }while(indicemercado != 1 && indicemercado != 2);
                            
                            printf("\nDigite para qual folheto do mercado %d voce ira adicionar o produto (1 ao 5): ",indicemercado);
                            scanf("%d", &col);
                            flush_in();//limpa buffer do teclado

                            printf("\nDigite o nome do produto que sera inserido: ");
                            fgets(dado,100,stdin);
                            // scanf("%s",&dado);
                            erro = Inserir_fim_LS(&mtrFolhetos[indicemercado-1][col-1],dado);
                            if(erro == 0){
                                printf("\nInsercao de produto bem sucedida!\n");
                                system("pause");
                            }
                            break;
                        case 2:
                            do{
                                printf("\nDigite para qual mercado o folheto que voce ira remover o produto esta (1 ou 2): ");
                                scanf("%d", &indicemercado);
                                if(indicemercado != 1 && indicemercado!=2){
                                    printf("\nOpcao nao valida \n");
                                    system("pause");
                                }
                            }while(indicemercado != 1 && indicemercado != 2);
                            
                            printf("\nDigite para qual folheto do mercado %d voce ira remover o produto (1 ao 5): ",indicemercado);
                            scanf("%d", &col);
                            flush_in();//limpa buffer do teclado

                            printf("\nDigite a posicao do produto que sera excluido: ");
                            scanf("%d", &posExclusao);
                            erro = Remover_meio_LS(&mtrFolhetos[indicemercado-1][col-1],posExclusao);
                            if(erro == 0){
                                printf("\nRemocao de produto bem sucedida!\n");
                                system("pause");
                            }else if(erro == 1){
                                printf("\nPosicao invalida!\n");
                                system("pause");
                            }else if(erro == 2){
                                printf("\nPosicao invalida! Acima do tamanho da lista\n");
                                system("pause");
                            }
                            break;
                        case 3:
                            do{
                                printf("\nDigite em qual mercado o folheto que voce ira consultar esta (1 ou 2): ");
                                scanf("%d", &indicemercado);
                                if(indicemercado != 1 && indicemercado!=2){
                                    printf("\nOpcao nao valida \n");
                                    system("pause");
                                }
                            }while(indicemercado != 1 && indicemercado != 2);
                            printf("\nDigite qual folheto do mercado %d voce ira listar os produtos (1 ao 5): ",indicemercado);
                            scanf("%d", &col);
                            erro = Listar_LS(mtrFolhetos[indicemercado-1][col-1],col);
                            if(erro == 0){
                                printf("\nFim da listagem dos produtos!\n");
                                system("pause");
                            }
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpcao nao valida \n");
                            system("pause");
                        }
                    } while ((opcaosubmenu3 != 0));
                    break;
                case 3:
                        
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 0:
                break;
                default:
                    printf("\nOpcao nao valida \n");
                    system("pause");
                }
            } while ((opcaosubmenu2 != 0));
            break;
        case 0:
            break;
        default:
            printf("\nOpcao nao valida \n");
            system("pause");
        }
    } while ((opcaoMenu != 0));
    return 0;
}


int Inicializar_LS (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */


int cadastrarNovoFolheto(Tno_ls *mtrFolhetos[tamanho][tamanho2], int lin, int col, Tno_ls *inicio){
    mtrFolhetos[lin][col] = inicio;
    return 0;
}

int Inserir_fim_LS (Tno_ls **inicio, char info[100])
{
    Tno_ls *no_novo, *percorre;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    strcpy (no_novo -> dado, info);
    no_novo -> prox = NULL;
    if (*inicio==NULL)
	{ /* lista vazia. */
	*inicio = no_novo;
        puts((*inicio)->dado);
	}
	else { /* lista nao vazia */
	     percorre = *inicio;
	     while (percorre->prox != NULL)
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;
	}
	return 0;
}

int Obter_Tamanho_LS(Tno_ls *inicio, int *tam)
{
    Tno_ls *percorre;
    *tam = 0;
    if(inicio != NULL)
    {
        percorre = inicio;
        while (percorre != NULL)
        {
            (*tam)++;
            percorre = percorre -> prox;
        }
    }
    else
    {
        *tam = 0;
    }
}

int Remover_inicio_LS (Tno_ls **inicio)
{
    Tno_ls *aux;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

int Remover_fim_LS (Tno_ls **inicio)
{
    Tno_ls *aux, *percorre;
    int tamanholista=0;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover ultimo */
    }
    else
    {
        Obter_Tamanho_LS(*inicio, &tamanholista);
        if (tamanho == 1)
        {
            Remover_inicio_LS(inicio);
        }
        else
        {
            percorre = *inicio;
            while (percorre->prox != NULL)
            {
                aux = percorre;
                percorre = percorre -> prox;
            }
            aux->prox = NULL;
            free(percorre);
            return 0;
        }
    }
}

int Remover_meio_LS (Tno_ls **inicio, int pos)
{
    int tam;
    Tno_ls *aux, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
        return 1;  /*) posicao invalida para remocao */

    Obter_Tamanho_LS(*inicio, &tam);
    if (pos > tam)
        return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */
    /* procura pela posicao de remocao */
    if (pos==1)
    {
        /* remocao no fim */
        Remover_inicio_LS(inicio);
    }
    else
    {
        if (pos == tam)
        {
            Remover_fim_LS(inicio);
        }
        else
        {
            int pos_aux=1;
            percorre = *inicio;
            while (pos_aux!=pos) /* parar uma posicao antes */
            {
                aux = percorre;
                percorre = percorre -> prox;
                pos_aux++;
            }
            aux -> prox = percorre -> prox;
            free(percorre);
        }
    }
    return 0;
}
int Listar_LS (Tno_ls *inicio, int posicao)
{
	int i;
    	int contador = 1;
	Tno_ls *aux;

	if (inicio == NULL)
	{
        return 1;  /* lista vazia */
	}
    	printf("Folheto selecionado: %d\n\n", posicao);
    	aux = inicio;
	do {
           printf("Posicao do produto no folheto => %d | Valor => ",contador);
           contador++;
           puts(inicio -> dado);
		   inicio = inicio->prox;
    	} while (inicio != NULL);

	return 0; /* sem erro */
}
