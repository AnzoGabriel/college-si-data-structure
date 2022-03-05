// --------- LIBRARIES ---------//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// -----------------------------//

#define SIZEPILHA 5   // Tamanho da Pilha
int pilha[SIZEPILHA]; // Pilha
int topoPilha = -1;   // Inicializa��o da Pilha

/**
 * FUN��O PARA CABE�ALHO
 */
void header()
{
    system("clear||cls");
    printf("\n\n");
}

/**
 * FUN��O PARA EMPILHAR ELEMENTO
 */
void empilharElemento(int elemento)
{
    pilha[topoPilha + 1] = elemento;
    topoPilha++;
}

/**
 * FUN��O PARA DESEMPILHAR ELEMENTO
 */
void desempilharElemento(int elemento)
{
    // --------- PILHA AUX�LIAR --------- //
    int pilhaAux[1000];    // Tamanho da Pilha
    int topoPilhaAux = -1; // Inicializa��o da Pilha

    for (int i = topoPilha; i >= 0; i--)
    {
        if (pilha[topoPilha] == elemento)
        {
            topoPilha--;
            break;
        }
        else
        {
            pilhaAux[topoPilhaAux + 1] = pilha[topoPilha];
            topoPilhaAux++;
            topoPilha--;
        }
    }

    if (topoPilhaAux != -1)
    {
        for (int t = topoPilhaAux; t >= 0; t--)
        {
            empilharElemento(pilhaAux[t]);
        }
    }
}

/**
 * FUN��O PARA VERIFICAR SE A PILHA EST� VAZIA
 */
int pilhaVazia()
{
    if (topoPilha == -1)
    {
        header();
        printf(">> A PILHA EST� VAZIA! << \n\n\n");
        return -1;
    }
    else
    {
        return 0;
    }
}

/**
 * FUN��O PARA VERIFICAR SE A PILHA EST� CHEIA
 */
int pilhaCheia()
{

    if (topoPilha == SIZEPILHA - 1)
    {
        header();
        printf("\n\n\n>> A PILHA EST� CHEIA! << \n\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * FUN��O PARA A EXIBIR PILHA
 */
void rederPilha()
{

    printf(":::::::::::::::::::::::::::::::::::::::::\n");
    printf("::::::::::::::::: PILHA :::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::::::::::::\n\n");
    printf(">> Tamanho da Pilha: %d\n", SIZEPILHA);
    printf(">> Topo da Pilha: %d\n", pilha[topoPilha]);
    printf(">> Base da Pilha: %d\n\n", pilha[0]);

    for (int x = topoPilha + 1; x > 0; x--)
    {
        printf("%d�\t%d\n", x, pilha[x - 1]);
    }
    printf("\n:::::::::::::::::::::::::::::::::::::::::\n\n\n");
}

/**
 * FUN��O PARA VERIFICAR CONTINUIDADE DA OPERA��O
 */
int checkContinuity(int done)
{

    switch (done)
    {
    case 1:;
        break;

    default:;

        header();

        if (done != 2)
        {
            printf("\n\n## Error: Entrada Inv�lida!\n\n");
            return;
        }
        break;
    }
}

/**
 * FUN��O PRINCIPAL
 */
int main()
{

    // ----- LIBRARY CONFIGURATION TO USE ACCENT----//
    setlocale(LC_ALL, "Portuguese_Brazil");
    // ---------------------------------------------//

    printf("____________________________________________\n\n");
    printf("\tEXERC�CIO DE PILHAS E FILAS\n");
    printf("____________________________________________\n\n");

    int menuOption;

    // ----- MENU DE OP��ES ----//
    do
    {

        printf("*********************************************\n");
        printf("\t     MENU  DE OPERA��ES\n");
        printf("*********************************************\n\n");

        printf("1 - Empilha\n");
        printf("2 - Desempilha\n");
        printf("3 - Exibir elementos da pilha\n");
        printf("4 - Sair da aplica��o.\n\n");

        printf("Informe a Opera��o Deseja: ");
        scanf("%d", &menuOption);

        header();

        switch (menuOption)
        {

            int elemento; // Armazena o valor h� ser EMPILHADO

        // --------- EMPILHAR VALORES --------- //
        case 1:;

            int doneEmpilhar; // Armazena o valor da op��o (1 - Sim / 2 - N�o) para continuar Empilhando

            do
            {
                header();
                if (pilhaCheia() == 1)
                {
                    pilhaCheia();
                    break;
                }
                else
                {
                    // Inserir valores no velor (Empilhar valores)
                    printf("Digite o valor que deseja Empilhar: ");
                    scanf("%d", &elemento);
                    empilharElemento(elemento);

                    printf("Deseja continuar EMPILHANDO valores. (1 - Sim | 2 - N�o)? ");
                    scanf("%d", &doneEmpilhar);

                    checkContinuity(doneEmpilhar);
                }

            } while (doneEmpilhar == 1);

            break;

        // --------- DESEMPILHAR VALORES --------- //
        case 2:;

            int doneDesempilhar; // Armazena o valor da op��o (1 - Sim / 2 - N�o) para continuar Desempilhando

            do
            {
                header();

                if (pilhaVazia() == -1)
                {
                    pilhaVazia();
                }
                else
                {
                    rederPilha();
                    printf("Qual elemento deseja DESEMPILHAR: ");
                    scanf("%d", &elemento);
                    desempilharElemento(elemento);

                    printf("\n\nDeseja continuar DESEMPILHANDO valores. (1 - Sim | 2 - N�o)? ");
                    scanf("%d", &doneDesempilhar);

                    checkContinuity(doneDesempilhar);
                }

            } while (doneDesempilhar == 1);

            break;

        // --------- EXIBIR ELEMENTOS DA PILHA --------- //
        case 3:;

            header();
            if (pilhaVazia() == -1)
            {
                pilhaVazia();
            }
            else
            {
                rederPilha();
            }

            break;

        default:;

            if (menuOption != 4)
            {
                header();
                printf("\n\n## Error: Op��o Inv�lida!\n\n");
            }
            break;
        }

    } while (menuOption != 4);

    return 0;
}
