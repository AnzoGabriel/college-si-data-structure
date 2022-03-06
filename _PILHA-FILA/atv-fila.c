// --------- LIBRARIES ---------//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// -----------------------------//

#define SIZEFILA 4 // Define o tamanho da fila

int fila[SIZEFILA]; // Cria vetor com tamanho da fila definido
int start = 0,      // Inicializa a fila na posição 0
    end = 0;        // Informa o final da fila

/**
 * FUNÇÃO PARA CABEÇALHO
 */
void header()
{
    system("clear||cls");
    printf("\n\n");
}

// --------- CONFIG DE CORES E EFEITOS --------- //

/********* CORES *********/
#define C_RED "\033[31m"
#define C_GREEN "\033[1;33m"
#define C_YELLOW "\033[33m"
#define C_BLUE "\033[34m"

/********* EFEITOS *********/
#define NONE "\033[0m"
#define BOLD "\033[1m"

// --------------------------------------------- //

/**
 * FUNÇÃO PARA VERIFICAR CONTINUIDADE DA OPERAÇÃO
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
            printf("\n\n## Error: Entrada Inválida!\n\n");
            return 0;
        }
        break;
    }
    return 0;
}

/**
 * FUNÇÃO PARA VERIFICAR SE A FILA ESTA VAZIA
 */
int filaVazia()
{
    if (start == end)
    {
        header();
        printf(">> A FILA ESTÁ VAZIA! << \n\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * FUNÇÃO PARA VERIFICAR SE A FILA ESTA CHEIA
 */
int filaCheia()
{
    if (end == SIZEFILA)
    {
        header();
        printf("\n\n\n>> A FILA ESTÁ COMPLETAMENTE CHEIA! << \n\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * FUNÇÃO PARA ENFILEIRAR ELEMENTOS
 */
void enfileirarElemento(int elemento)
{
    if (filaCheia() == 1)
    {
        filaCheia();
    }
    else
    {
        fila[end] = elemento;
        end++;
        printf("\033[32m\n\nElemento Adicionado\n\n\033[0m");
    }
}

/**
 * FUNÇÃO PARA DESENFILEIRAR ELEMENTOS
 */
void desenfileirarElemento()
{
    // int backup = fila[0]; // ARMAZENA A POSIÇÃO INICIAL DO VETOR

    if (filaVazia() == 1)
    {
        filaVazia();
    }
    else
    {
        for (int i = 0; i < end; i++)
        {
            fila[i] = fila[i + 1];
        }
        end--;
    }
}

/**
 * FUNÇÃO PARA IMPRIMIR A FILA
 */

void imprimirFila()
{
    for (int i = start; i < end; i++)
    {
        printf("%dº\t%d\n", i + 1, fila[i]);
    }
}

int main()
{

    // ----- LIBRARY CONFIGURATION TO USE ACCENT----//
    setlocale(LC_ALL, "Portuguese_Brazil");
    // ---------------------------------------------//

    int menuOption; // ARMAZENA A OPÇÃO FORNECIDA

    do
    {
        printf("*********************************************\n");
        printf("\t     MENU  DE OPERAÇÕES\n");
        printf("*********************************************\n\n");

        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Exibir Fila\n");
        printf("4 - Sair da aplicação.\n\n");

        printf("Informe a Operação Deseja: ");
        scanf("%d", &menuOption);
        header();

        switch (menuOption)
        {

            int elemento; // ARMAZENA O VALOR PARA ENFILEIRAR

        // --------- ENFILEIRAR --------- //
        case 1:;

            int doneEnfileirar; // Armazena o valor da opção (1 - Sim / 2 - Não) para continuar Empilhando

            do
            {
                header();
                if (filaCheia() == 1)
                {
                    filaCheia();
                    break;
                }
                else
                {
                    // Inserir valores no velor (Empilhar valores)
                    printf("Digite o valor que deseja adicionar na Fila: ");
                    scanf("%d", &elemento);
                    enfileirarElemento(elemento);

                    printf("Deseja Enfileirar outro valor. (1 - Sim | 2 - Não)? ");
                    scanf("%d", &doneEnfileirar);

                    checkContinuity(doneEnfileirar);
                }

            } while (doneEnfileirar == 1);
            break;

        // --------- DESENFILEIRAR --------- //
        case 2:;

            if (filaVazia() == 1)
                filaVazia();
            else
                desenfileirarElemento();

            break;

        // --------- VIZUALIZAR FILA --------- //
        case 3:;
            if (filaVazia() == 1)
            {
                filaVazia();
            }
            else
            {
                header();
                imprimirFila();
            }

            break;

        default:
            if (menuOption != 4)
            {
                header();
                printf("%s %s\n\n## Error: Informe umas das opção validas abaixo\n\n%s", BOLD, C_YELLOW, NONE);
            }
            break;
        }
    } while (menuOption != 4);

    return 0;
}