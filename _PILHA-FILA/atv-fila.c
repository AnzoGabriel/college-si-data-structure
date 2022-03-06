// --------- LIBRARIES ---------//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
// -----------------------------//

#define SIZEFILA 4 // Define o tamanho da fila

int fila[SIZEFILA]; // Cria vetor com tamanho da fila definido

int start = 0, // Inicializa a fila na posição 0
    end = 0;   // Informa o final da fila

/**
 * FUNÇÃO PARA CABEÇALHO
 */
void header()
{
    system("clear||cls"); // LIMPA O TERMINAL
}

// --------- CONFIG DE CORES E EFEITOS --------- //

/********* CORES *********/
#define C_RED "\033[1;31m"
#define C_GREEN "\033[1;32m"
#define C_YELLOW "\033[0;33m"
#define C_BLUE "\033[1;34m"

/********* EFEITOS *********/
#define NONE "\033[0m"

/********* SETTINGS *********/
#define ERRO "erro"
#define AVISO "aviso"
#define SUCESSO "sucesso"
#define INFO "info"

// --------------------------------------------- //

/**
 * FUNÇÃO RESPONSÁVEL PELA EXIBIÇÃO DE MENSAGENS PERSONALIZADAS
 */
void msg(const char *type_msg, const char *str)
{

    if (strcmp(type_msg, "erro") == 0)
    {
        printf("%s%s%s", C_RED, str, NONE);
        return;
    }
    else if (strcmp(type_msg, "aviso") == 0)
    {
        printf("%s%s%s", C_YELLOW, str, NONE);
        return;
    }
    else if (strcmp(type_msg, "sucesso") == 0)
    {
        printf("%s%s%s", C_GREEN, str, NONE);
        return;
    }
    else if (strcmp(type_msg, "info") == 0)
    {
        printf("%s%s%s", C_BLUE, str, NONE);
        return;
    }
    else
    {
        printf("\n\n#!\n%smessage type undefined - function: msg%s\n\t#!\n\n", C_BLUE, NONE);
        return;
    }
    return;
}

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
            msg(ERRO, "# - Error: Informe uma opção VÁLIDA - #\n\n");
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
        msg(INFO, "\n\n>> A FILA ESTÁ VAZIA! <<\n\n\n");
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
        msg(AVISO, "\n\n>> A FILA ESTÁ COMPLETAMENTE CHEIA! <<\n\n\n");
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
        msg(SUCESSO, "\n>> ELEMENTO ADICIONADO COM SUCESSO <<\n\n");
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
        msg(SUCESSO, "\n\n>> ELEMENTO REMOVIDO COM SUCESSO <<\n\n");
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

    printf("____________________________________________\n\n");
    printf("\tEXERCÍCIO DE FILAS\n");
    printf("____________________________________________\n\n");

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
                msg(ERRO, "# - Error: Informe umas das opção validas ABAIXO - #\n\n");
            }
            break;
        }
    } while (menuOption != 4);

    return 0;
}