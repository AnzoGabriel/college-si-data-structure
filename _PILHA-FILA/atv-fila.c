// --------- LIBRARIES ---------//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// -----------------------------//

#define SIZEFILA 6 // Define o tamanho da fila

int fila[SIZEFILA]; // Cria vetor com tamanho da fila definido
int start = 0,      // Inicializa a fila na posi��o 0
    end = 0;        // Informa o final da fila

/**
 * FUN��O PARA CABE�ALHO
 */
void header()
{
    system("clear||cls");
    printf("\n\n");
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
            return 0;
        }
        break;
    }
    return 0;
}

/**
 * FUN��O PARA VERIFICAR SE A FILA ESTA VAZIA
 */
int filaVazia()
{
    if (start == 0)
    {
        header();
        printf(">> A PILHA EST� VAZIA! << \n\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * FUN��O PARA VERIFICAR SE A FILA ESTA CHEIA
 */
int filaCheia()
{
    if (end == SIZEFILA)
    {
        header();
        printf("\n\n\n>> A FILA EST� COMPLETAMENTE CHEIA! << \n\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * FUN��O PARA ENFILEIRAR ELEMENTOS
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
        printf("\n\nElemento Adicionado\n\n");
    }
}

/**
 * FUN��O PARA DESENFILEIRAR ELEMENTOS
 */
void desenfileirarElemento()
{
    int backup = fila[0]; // ARMAZENA A POSI��O INICIAL DO VETOR

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

int main()
{

    // ----- LIBRARY CONFIGURATION TO USE ACCENT----//
    setlocale(LC_ALL, "Portuguese_Brazil");
    // ---------------------------------------------//

    printf("::: HELLO WORD! :::\n\n\n");

    int menuOption;

    do
    {
        printf("*********************************************\n");
        printf("\t     MENU  DE OPERA��ES\n");
        printf("*********************************************\n\n");

        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Exibir Fila\n");
        printf("4 - Sair da aplica��o.\n\n");

        printf("Informe a Opera��o Deseja: ");
        scanf("%d", &menuOption);
        header();

        switch (menuOption)
        {

            int elemento; // ARMAZENA O VALOR PARA ENFILEIRAR

        // --------- ENFILEIRAR --------- //
        case 1:;

            int doneEnfileirar; // Armazena o valor da op��o (1 - Sim / 2 - N�o) para continuar Empilhando

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

                    printf("Deseja Enfileirar outro valor. (1 - Sim | 2 - N�o)? ");
                    scanf("%d", &doneEnfileirar);

                    checkContinuity(doneEnfileirar);
                }

            } while (doneEnfileirar == 1);
            break;

        // --------- DESENFILEIRAR --------- //
        case 2:;

            if (filaVazia() == 1)
            {
                filaVazia();
            }
            else
            {
                start++;
            }

            break;

        // --------- VIZUALIZAR FILA --------- //
        case 3:;
            if (filaVazia() == 1)
            {
                filaVazia();
            }
            else
            {
                for (int i = start; i < end; i++)
                {
                    printf("%d\n", fila[i]);
                }
            }

            break;

        default:
            if (menuOption != 4)
            {
                header();
                printf("\n\n## Error: Op��o Inv�lida!\n\n");
            }
            break;
            break;
        }
    } while (menuOption != 4);

    return 0;
}