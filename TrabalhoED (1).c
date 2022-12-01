#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//------------------------------------------------------------------------------
#define tamanho 3  // tamanho maximo da FILA
/* -----------------------------------------------------------------------------
Estrutura FILA ESTATICA
------------------------------------------------------------------------------*/
    typedef struct fila{
            int item [tamanho] ;
            int inicio, fim;
    } T_FILA;
/* -----------------------------------------------------------------------------
Estrutura pilha
------------------------------------------------------------------------------*/
    typedef struct no_pilha {
        int dado;
        struct no_pilha *prox;
    }  Tno_pilha;
/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES
------------------------------------------------------------------------------*/
    struct no_ls {
        int dado;
        struct no_ls *prox;
    };
    typedef struct no_ls Tno_ls;
/* -----------------------------------------------------------------------------
Estrutura MATRIZ
------------------------------------------------------------------------------*/
    struct matriz{
        int** elemento;
        int nlinhas;
        int ncolunas;
    };
    typedef struct matriz Matriz;
//------------------------------------------------------------------------------

int inicializa          (T_FILA *f);
int verifica_vazio      (T_FILA f);
int remover             (T_FILA *f);
int verifica_cheio      (T_FILA f);
int insere              (T_FILA *f, int x);
int listar              (T_FILA f);
int Inicializar_pilha   (Tno_pilha **inicio);
int Inicializar2_pilha  (Tno_pilha **inicio);
int Inserir_topo        (Tno_pilha **inicio, int info);
int Remover_topo        (Tno_pilha **inicio);
int Obter_topo          (Tno_pilha *inicio, int *dado);
int Verifica_vazio      (Tno_pilha *inicio, int *resp);
int Juntar_pilhas       (Tno_pilha **P1, Tno_pilha **P2, Tno_pilha **P3);
int Inicializar_LS      (Tno_ls **P_inicio);
int Inicializar2_LS     (Tno_ls **P_inicio);
int Inserir_inicio_LS   (Tno_ls **P_inicio, int info);
int Inserir_fim_LS      (Tno_ls **P_inicio, int info);
int Inserir_meio_LS     (Tno_ls **P_inicio, int info, int pos);
int Remover_inicio_LS   (Tno_ls **P_inicio);
int Listar_LS           (Tno_ls *CP_inicio);
int Obter_pos_LS        (Tno_ls *CP_inicio, int dado, int *pos);
int Obter_Tamanho_LS    (Tno_ls *CP_inicio, int *tam);
int Inverte_LS          (Tno_ls **P_inicio);
//------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    char info[20];
	int resp, pos;
	int erro; /* valor de erro retornado pelas funcoes */
    T_FILA s;
	Tno_ls *ini; // a lista esta aqui
    Tno_pilha *ini;
	Tno_pilha *P1, *P2, *P3;

	int q;  /* receber a opcao do usuario */
	erro=Inicializar_LS (&ini);

	do {
	    system("cls");
	    printf("Nome do trabalho");
		printf("\n\nOpcoes: \n\n");
		printf("1 -> Inserir novo folheto \n");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: printf("Nome do produto: ");
                    scanf("%s",&info);
                    erro=Inserir_inicio_LS (&ini, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
            case 10: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    printf("Posicao de insercao: ");
                    scanf("%d",&pos);

                    erro=Inserir_meio_LS (&ini, info, pos);

                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_fim_LS (&ini, info);
			        break;
            case 3: erro = Remover_inicio_LS (&ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover");
                    }
                    system("pause");
                    break;
			case 4: erro=Listar_LS (ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel listar");
                    }
                    system("pause");
					break;
			case 5: erro=Inicializar2_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
			case 6: erro=Inverte_LS (&ini);
                    if (erro == 1)
                        printf("\nLista vazia. Inversao nao realizada !\n");
                    else
                        printf("\nInversao realizada !\n");
                    system("pause");
					break;
			case 7: printf("Dado para pesquisa na lista: ");
                    scanf("%d",&info);
                    erro = Repete_Dado_LS (ini, info, &resp);
                    if (erro!=0)
                        printf("\nErro na opera��o");
                    else
                        printf("\nResposta (1:sim, 0:Nao) : %d \n",resp);
                    system("pause");
					break;
			case 9: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 9) );

    return 0;
}

// ==================================================================
int inicializa (T_FILA *f)
{
  (*f).inicio = -1;
  (*f).fim = -1;
  return 0;
}
// ==================================================================
int verifica_vazio(T_FILA f)
{
    if(f.inicio==f.fim+1){
       return 0;  // fila vazia
    }else {
        return -1;
    }
}
// ==================================================================
int remover(T_FILA *f)
{
    int erro = verifica_vazio(*f);
    if (erro != 0)
    {
      (*f).inicio++;  // remocao efetuada
       return 0;
    }
    else
       return 1; // impossivel remover. Underflow
}
// ==================================================================
int verifica_cheio(T_FILA f)
{
    if (f.fim == tamanho-1 ){
        return 1;   // fila cheia
    }else{
        return 2;  // fila n�o cheia
    }
}
// ==================================================================
int insere(T_FILA *f, int x)
{
    int erro = verifica_cheio(*f);
    if (erro != 1)
    {
       (*f).fim++;
       (*f).item[(*f).fim]=x;// inser��o efetuada
       if ((*f).inicio == -1)
          (*f).inicio = 0;
       return 0;
    }
    else
       return 1; // impossivel inser��o. overflow
}
// ==================================================================
int listar(T_FILA f)
{  
    int i,erro;
    erro=verifica_vazio(f);
    if (erro!=0)
    {
       for (i=f.inicio; i<=f.fim; i++)
           printf("%d - ",f.item[i]);
       printf("\n");
       return 0;
    }
    else return 1;  // nao possivel listar pois a fila esta vazia
}
// ==================================================================
// ========================
int Listar (Tno_pilha *P1)
{
    printf ("Pilha: ");
    while (P1 != NULL)
    {
        printf ("%d - ", P1->dado);
        P1 = P1 -> prox;
    }
      printf (" \n ");
      system ("pause");
}

// ========================
int Juntar_pilhas (Tno_pilha **P1, Tno_pilha **P2, Tno_pilha **P3)
{
    Tno_pilha *P_aux;  // pilha auxiliar
    int resp, erro;
    int dado;

    erro = Inicializar_pilha (P3);
    erro = Inicializar_pilha (&P_aux);
    // renomear a p2 para ser p3
    *P3 = *P2;
    *P2 = NULL;

    Verifica_vazio  (*P1, &resp);
    while (resp == 0) // pilha n�o vazia
    {
        Obter_topo  (*P1, &dado);
        Remover_topo   (P1);
        Inserir_topo   (&P_aux, dado);
        Verifica_vazio  (*P1, &resp);
    }
    Verifica_vazio  (P_aux, &resp);
    while (resp == 0) // pilha n�o vazia
    {
        Obter_topo  (P_aux, &dado);
        Remover_topo   (&P_aux);
        Inserir_topo   (P3, dado);
        Verifica_vazio  (P_aux, &resp);
    }
    return 0;
}
int Inicializar_pilha (Tno_pilha **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */

// =================================================
int Inicializar2_pilha(Tno_pilha **inicio)
{
    Tno_pilha *percorre, *aux;
	if(*inicio != NULL)
	{
       percorre = *inicio;
	   while (percorre != NULL)
	   {
             aux = percorre;
	         percorre = percorre -> prox;
	         free(aux);
	   }
	   *inicio = NULL;
	   return 1; // inicializa apagando tudo da pilha
	}
}

/* -------------------------------------------------------------------------------------
INSER��O
---------------------------------------------------------------------------------------*/
int Inserir_topo (Tno_pilha **inicio, int info)
{
    Tno_pilha *no_novo;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_pilha *) malloc(sizeof(Tno_pilha));
    no_novo -> dado = info;

	if (*inicio==NULL)
	{    // insercao em pilha vazia
	    no_novo -> prox = NULL;
	    *inicio = no_novo;
	}
	else { // insercao em pilha nao vazia
	     no_novo -> prox = *inicio;
	    *inicio = no_novo;
	}
    return 0;
}


/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_topo (Tno_pilha **inicio)
{
    Tno_pilha *aux;
    if (*inicio == NULL)
    {
         return 1;  /* pilha vazia, impossivel remover topo */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}
// =================================================================
int Obter_topo(Tno_pilha *inicio, int *dado)
{
    if (inicio != NULL)
    {
       *dado = inicio -> dado;
       return 0;
    }
    else
       return 1; // Pilha Vazia
}
// ================================================================
int Verifica_vazio (Tno_pilha *inicio, int *resp)
{
    if (inicio != NULL)
       *resp = 0; // Pilha nao Vazia
    else
       *resp = 1; // Pilha Vazia
    return 0;
}
int Listar_LS (Tno_ls *inicio)
{
	int i;
	Tno_ls *aux;

	if (inicio == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");
    aux = inicio;
	do {
           printf(" %d",inicio -> dado);
		   inicio = inicio->prox;
    } while (inicio != NULL);

    printf("\n");
	return 0; /* sem erro */
} /* Fim da fun��o de MOSTRAR */
/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LS (Tno_ls **inicio)
{
	*inicio= NULL;


	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
/* ================================================= */

int Inicializar2_LS(Tno_ls **inicio)
{
    Tno_ls *percorre, *aux;
	if(*inicio != NULL)
	{
       percorre = *inicio;
       do {
             aux = percorre;
	         percorre = percorre->prox;
	         free(aux);
	   } while (percorre != *inicio);
	   *inicio = NULL;
	   return 1; /* inicializa apagando tudo da listsa */
	}
	else
	{
	   return 0;
	}
}


/* ================================================= */
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

/* -------------------------------------------------------------------------------------
INSER��O
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

	if (*inicio==NULL)
	{    /* insercao em lista vazia */
	    no_novo -> prox = NULL;
	    *inicio = no_novo;
	}
	else { /* insercao em lista nao vazia */
	     no_novo -> prox = *inicio;
	    *inicio = no_novo;
	}
    return 0;
}

/* ================================================= */
int Inserir_meio_LS (Tno_ls **inicio, int info, int pos)
{
    int tam;
    Tno_ls *no_novo, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
       return 1;  /*) posicao invalida para insercao */

    Obter_Tamanho_LS(*inicio, &tam);
    if (pos > tam+1)
       return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */

    /* Alocacao do novo no */
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    /* procura pela posicao de insercao */
    if (pos==1)
    {   /* insercao no inicio */
        Inserir_inicio_LS (inicio, info);
    }
    else
    {   if (pos == tam+1)
        {
            Inserir_fim_LS (inicio, info);
        }
        else {
                int pos_aux=1;
                percorre = *inicio;
                while (pos_aux!=pos-1) /* parar uma posicao antes */
                {
                   percorre = percorre -> prox;
                   pos_aux++;
                }
                no_novo -> prox = percorre -> prox;
                percorre -> prox = no_novo;
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo, *percorre;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> prox = NULL;

    if (*inicio==NULL)
	{ /* lista vazia. */
	    *inicio = no_novo;
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

/* ================================================= */
int Obter_Pos_LS (Tno_ls *inicio, int valor, int *pos)
{
  *pos = 0;
  while (inicio != NULL)
  {
     (*pos)++;
     if (valor == inicio->dado)
       return 0;     /* dado encontrado */
     inicio = inicio -> prox;
  }
  if (inicio == NULL)
     *pos = 0;
  return 1;  /* dado nao encontrado */
}

/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
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

/* -------------------------------------------------------------------------
INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverte_LS (Tno_ls **inicio)
{
    Tno_ls *percorre,*aux_1,*aux_2,*aux_3;
    percorre=*inicio;
    if(percorre==NULL)
    {
        return 1;/*Caso a lista esteja vazia. */
    }
    else if(percorre->prox==NULL)
    {
        return 0;/*Caso a lista tenha apenas um n�. */
    }
    else
    {
        aux_1       = *inicio;        /*O ponteiro aux_a aponta para o primeiro n�, uma vez que o ponteiro "ini" passar� a apontar para o �ltimo. */
        aux_2       = aux_1->prox;    /*O ponteiro aux_p passa a apontar para o segundo n� da lista.*/
        aux_3       = aux_2->prox;    /*O ponteiro aux_v passa a apontar para o terceiro n� da lista.*/
        aux_1->prox = NULL;           /*O primeiro n� da lista passa a ser o �ltimo, apontando para NULL.*/
        aux_2->prox = aux_1;          /*O segundo n� da lista passa a apontar para o primeiro, come�ando a invers�o da lista.*/
                                      /*In�cio - Processo de invers�o.*/
        while(aux_3!=NULL)
        {
            aux_1 = aux_2;             /*O ponteiro aux_a pega o valor do n� a sua frente na lista.*/
            aux_2 = aux_3;             /*O ponteiro aux_p pega o valor do n� a sua frente na lista.*/
            aux_3 = aux_3->prox;       /*O ponteiro aux_v pega o valor do n� a sua frente na lista.*/
            aux_2->prox=aux_1;         /*O n� para o qual aux_p est� apontado passa a apontar para o n� anterior a ele na lista.*/
        }
                                       /*Fim - Processo de invers�o. */
        *inicio = aux_2;               /* atualiza��o do ponteiro de inicio */
    }

    return 0;

}
int Repete_Dado_LS   (Tno_ls *inicio, int info, int *resp)
{
    int cont=0;  /* contagem de repeticoes*/
	if (inicio == NULL)
	{
        *resp = 0;  /* Dados nao repete */
        return 1;  /* lista vazia*/
	}
    while (inicio != NULL) {
       if (inicio->dado == info)
          cont++;
       inicio = inicio->prox;
    }
    if (cont > 1)
       *resp = 1;
    else
       *resp = 0;
	return 0; /* sem erro */
}
/* -------------------------------------------------------------------------
Matriz
-------------------------------------------------------------------------*/
Matriz* inicializaMatriz(int nlinhas, int ncolunas){
    Matriz* mat = malloc(sizeof(Matriz)); //criar primeiro o elemento da estrutura
    mat->elemento = malloc(sizeof(int*) * nlinhas); //aloca a matriz dentro da estrutura
    mat->nlinhas = nlinhas; //coloca o numero de linhas dentro da estrutura
    mat->ncolunas = ncolunas; //coloca o numero de colunas dentro da estrutura

    //percorre cada linha com um for para criar as colunas
    int i;
    for (i = 0; i < nlinhas; ++i){
        mat->elemento[i] = malloc(sizeof(int) * ncolunas);
    }

    return mat;
}