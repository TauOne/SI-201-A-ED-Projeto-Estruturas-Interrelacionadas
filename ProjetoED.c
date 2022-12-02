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
int Inicializar2_LS(Tno_ls **P_inicio);
int Inicializar3_LS(Tno_ls **P_inicio);
int Inicializar4_LS(Tno_ls **P_inicio);
int Inicializar5_LS(Tno_ls **P_inicio);
int Inicializar6_LS(Tno_ls **P_inicio);
int Inicializar7_LS(Tno_ls **P_inicio);
int Inicializar8_LS(Tno_ls **P_inicio);
int Inicializar9_LS(Tno_ls **P_inicio);
int Inicializar10_LS(Tno_ls **P_inicio);

int Inserir_inicio_LS(Tno_ls **P_inicio, int info);
int Inserir_fim_LS(Tno_ls **P_inicio, char info[100]);
int Inserir_meio_LS(Tno_ls **P_inicio, int info, int pos);
int Remover_inicio_LS(Tno_ls **P_inicio);
int Listar_LS(Tno_ls *CP_inicio);
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
    int indicefolheto = 0, indicefolheto2 = 0, col = 0;
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
                printf("5 - Remover Mercado com Todos os Folhetos existentes \n");
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
                    if(contadorLista == 0){
                        erro=Inicializar_LS (&ini);
                        if(erro == 0){
                            printf("Lista 1 inializada\n");
                            if(indicemercado == 0){
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                    system("pause");
                                }
                                indicefolheto++;
                            }else{
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                    system("pause");
                                }
                                indicefolheto2++;
                            }
                            contadorLista++;
                        }
                    }
                    else if(contadorLista == 1){
                        erro=Inicializar_LS2 (&ini2);
                        if(erro == 0){
                            printf("Lista 2 inializada\n");
                            if(indicemercado == 0){
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini2);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                    system("pause");
                                }
                                indicefolheto++;
                            }else{
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini2);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                    system("pause");
                                }
                                indicefolheto2++;
                            }
                            contadorLista++;
                        }
                    }
                    else if(contadorLista == 2){
                        erro=Inicializar_LS3 (&ini3);
                        if(erro == 0){
                            printf("Lista 3 inializada\n");
                            if(indicemercado == 0){
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini3);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                    system("pause");
                                }
                                indicefolheto++;
                            }else{
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini3);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                    system("pause");
                                }
                                indicefolheto2++;
                            }
                            contadorLista++;
                        }
                    }
                    else if(contadorLista == 3){
                        erro=Inicializar_LS4 (&ini4);
                        if(erro == 0){
                            printf("Lista 4 inializada\n");
                            if(indicemercado == 0){
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini4);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                    system("pause");
                                }
                                indicefolheto++;
                            }else{
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini4);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                    system("pause");
                                }
                                indicefolheto2++;
                            }
                            contadorLista++;
                        }
                    }
                    else if(contadorLista == 4){
                        erro=Inicializar_LS5 (&ini5);
                        if(erro == 0){
                            printf("Lista 5 inializada\n");
                            if(indicemercado == 0){
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini5);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                    system("pause");
                                }
                                indicefolheto++;
                            }else{
                                erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini5);
                                if(erro == 0){
                                    printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                    system("pause");
                                }
                                indicefolheto2++;
                            }
                            contadorLista++;
                        }
                    }
                    else if(contadorLista == 5){
                            if(indicemercado == 0){
                                if(indicefolheto > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }
                                else{
                                    erro=Inicializar_LS6 (&ini6);
                                    if(erro == 0){
                                            printf("Lista 6 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini6);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                        system("pause");
                                    }
                                    indicefolheto++;
                                }
                                
                            }else{
                                if(indicefolheto2 > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }
                                else{
                                    erro=Inicializar_LS6 (&ini6);
                                    if(erro == 0){
                                            printf("Lista 6 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini6);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                        system("pause");
                                    }
                                    indicefolheto2++;   
                                }
                                
                            }
                        
                    }
                    else if(contadorLista == 6){
                            if(indicemercado == 0){
                                if(indicefolheto > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS7 (&ini7);
                                    if(erro == 0){
                                            printf("Lista 7 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini7);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                        system("pause");
                                    }
                                    indicefolheto++;
                                }
                                
                            }else{
                                if(indicefolheto2 > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS7 (&ini7);
                                    if(erro == 0){
                                            printf("Lista 7 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini7);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                        system("pause");
                                    }
                                    indicefolheto2++;
                                }
                            }
                        
                    }
                    else if(contadorLista == 7){
                            if(indicemercado == 0){
                                if(indicefolheto > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS8 (&ini8);
                                    if(erro == 0){
                                            printf("Lista 8 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini8);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                        system("pause");
                                    }
                                    indicefolheto++;
                                }
                            }else{
                                if(indicefolheto2 > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS8 (&ini8);
                                    if(erro == 0){
                                            printf("Lista 8 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini8);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                        system("pause");
                                    }
                                    indicefolheto2++;
                                }
                            }
                    }
                    else if(contadorLista == 8){
                            if(indicemercado == 0){
                                if(indicefolheto > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS9 (&ini9);
                                    if(erro == 0){
                                            printf("Lista 9 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini9);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                        system("pause");
                                    }
                                    indicefolheto++;
                                }
                            }else{
                                if(indicefolheto2 > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS9 (&ini9);
                                    if(erro == 0){
                                            printf("Lista 9 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini9);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 2\n");
                                        system("pause");
                                    }
                                    indicefolheto2++;
                                }
                            }
                    }
                    else if(contadorLista == 9){
                        
                            if(indicemercado == 0){
                                if(indicefolheto > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS10 (&ini10);
                                    if(erro == 0){
                                            printf("Lista 10 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini10);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 1\n");
                                        system("pause");
                                    }
                                    indicefolheto++;
                                }
                            }else{
                                if(indicefolheto2 > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS10 (&ini10);
                                    if(erro == 0){
                                            printf("Lista 10 inializada\n");
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini10);
                                    if(erro == 0){
                                        printf("Folheto Novo nos Folhetos do Mercado 2\n");
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
                        printf("3 - Atualizar produto \n");
                        printf("4 - Consultar todos produtos cadastrados \n");
                        printf("0 - Voltar \n\n");
                        scanf("%d", &opcaosubmenu3);
                        switch (opcaosubmenu3)
                        {
                        case 1:
                            do{
                                printf("\nDigite para qual mercado o folheto que voce ira adicionar o produto (1 ou 2): ");
                                scanf("%d", &indicemercado);
                                if(indicemercado != 1 && indicemercado!=2){
                                    printf("\nOpcao nao valida \n");
                                    system("pause");
                                }
                            }while(indicemercado != 1 && indicemercado != 2);
                            
                            printf("\nDigite para qual folheto do mercado %d voce ira adicionar o produto (1 ao 5): ",indicemercado+1);
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


int Inicializar_LS (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS2 (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS3 (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS4 (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS5 (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS6 (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS7 (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS8 (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS9 (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
int Inicializar_LS10 (Tno_ls **inicio)
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