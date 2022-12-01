#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//------------------------------------------------------------------------------
#define tamanho 3 // tamanho maximo da FILA

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
    int diaSemana;
    int dado;
    struct no_ls *prox;
} Tno_ls;

int Inicializar_LS(Tno_ls **P_inicio);
int Inicializar2_LS(Tno_ls **P_inicio);
int Inserir_inicio_LS(Tno_ls **P_inicio, int info);
int Inserir_fim_LS(Tno_ls **P_inicio, int info);
int Inserir_meio_LS(Tno_ls **P_inicio, int info, int pos);
int Remover_inicio_LS(Tno_ls **P_inicio);
int Listar_LS(Tno_ls *CP_inicio);
int Obter_pos_LS(Tno_ls *CP_inicio, int dado, int *pos);
int Obter_Tamanho_LS(Tno_ls *CP_inicio, int *tam);
int Inverte_LS(Tno_ls **P_inicio);

/* -----------------------------------------------------------------------------
Estrutura MATRIZ
------------------------------------------------------------------------------*/
struct matriz
{
    int **elemento;
    int nlinhas;
    int ncolunas;
};
typedef struct matriz Matriz;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
    int opcaoMenu;     /* receber a opcao do usuario do menu principal*/
    int opcaosubmenu1; /* receber a opcao do usuario do submenu mercado*/
    int opcaosubmenu2; /* receber a opcao do usuario do submenu folheto*/
    int opcaosubmenu3; /* receber a opcao do usuario do submenu modificando folheto do submenu folheto*/

    do
    {
        system("cls");
        printf("-----------------------------------------------------------------------\n");
        printf("Trabalho de Estrutura de Dados I\n");
        printf("Gerenciamento de Mercados e Folhetos para Impressao\n");
        printf("-----------------------------------------------------------------------\n");
        printf("\nEscolha uma opcao do menu: \n\n");
        printf("1 - Gerenciar Mercado \n");
        printf("2 - Gerenciar Folhetos e Imprimir\n");
        printf("0 - Sair \n\n");
        scanf("%d", &opcaoMenu); /* Ler a opcao do usuario */
        switch (opcaoMenu)
        {
        case 1:
            do
            {
                getchar(); /* Limpa o buffer de entrada */
                system("cls");
                printf("Escolha uma opcao do sub-menu: \n\n");
                printf("1 - Cadastrar Mercado \n");
                printf("2 - Consultar Mercados Cadastrados \n");
                printf("3 - Remover Mercado \n");
                printf("0 - Voltar \n\n");
                scanf("%d", &opcaosubmenu1);
                switch (opcaosubmenu1)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcao nao valida \n");
                    system("pause");
                }
            } while ((opcaosubmenu1 != 0));

            break;
        case 2:
            do
            {
                system("cls");
                printf("Escolha uma opcao do sub-menu: \n\n");
                printf("1 - Cadastrar Novo Folheto \n");
                printf("2 - Modificar Folheto Existente\n");
                printf("3 - Consultar Todos os Folhetos de um Mercado \n");
                printf("4 - Remover Folheto Especifico \n");
                printf("5 - Remover Mercado com Todos os Folhetos existentes \n");
                printf("6 - Imprimir folhetos \n");
                printf("0 - Voltar \n\n");
                scanf("%d", &opcaosubmenu2);
                switch (opcaosubmenu2)
                {
                case 1:
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        printf("\nModificando Folheto Existente: \n\n");
                        printf("1 - Inserir novo produto\n");
                        printf("2 - Remover produto\n");
                        printf("3 - Atualizar produto \n");
                        printf("4 - Consultar todos produtos cadastrados \n");
                        printf("0 - Voltar \n\n");
                        scanf("%d", &opcaosubmenu3);
                        switch (opcaosubmenu3)
                        {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
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
