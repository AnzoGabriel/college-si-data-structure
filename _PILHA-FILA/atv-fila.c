// --------- LIBRARIES ---------//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// -----------------------------//

#define SIZEFILA 6 // Define o tamanho da fila

int fila[SIZEFILA]; // Cria vetor com tamanho da fila definido
int start = 0,      // Inicializa a fila na posição 0
    end = 0;        // Informa o final da fila

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
            return;
        }
        break;
    }
}

/**
 * FUNÇÃO PARA VERIFICAR SE A FILA ESTA VAZIA
 */
int filaVazia()
{
    if (start == end)
        return 1;
    else
        return 0;
}

/**
 * FUNÇÃO PARA VERIFICAR SE A FILA ESTA CHEIA
 */
int filaCheia()
{
    if (end == start)
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
        printf("\n\nA Fila esta cheia\n\n");
        return;
    }
    else
    {
        fila[end] = elemento;
        end++;
        printf("\n\nElemento Adicionado\n\n");
    }
}

/**
 * FUNÇÃO PARA DESENFILEIRAR ELEMENTOS
 */
void desenfileirarElemento()
{
    if (filaVazia() == 1)
        printf("\n\nA Fila esta vazia!!\n\n");
    else
        start++;
}

int main()
{

    // ----- LIBRARY CONFIGURATION TO USE ACCENT----//
    setlocale(LC_ALL, "Portuguese_Brazil");
    // ---------------------------------------------//

    printf('::: HELLO WORD! :::\n\n\n');

    int menuOption;

    do
    {
        printf("*********************************************\n");
        printf("\t     MENU  DE OPERAÇÕES\n");
        printf("*********************************************\n\n");

        printf("1 - Enfileirar\n");
        printf("2 - Sesenfileirar\n");
        printf("3 - Exibir Fila\n");
        printf("4 - Sair da aplicação.\n\n");

        printf("Informe a Operação Deseja: ");
        scanf("%d", &menuOption);
        header();

        switch (menuOption)
        {

            int elemento; // ARMAZENA O VALOR PARA ENFILEIRAR

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
        case 2:;
            /* code */
            break;
        case 3:;
            /* code */
            break;

        default:
            if (menuOption != 4)
            {
                header();
                printf("\n\n## Error: Opção Inválida!\n\n");
            }
            break;
            break;
        }
    } while (menuOption != 4);

    return 0;
}