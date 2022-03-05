// --------- LIBRARIES ---------//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// -----------------------------//

#define SIZEPILHA 5   // Tamanho da Pilha
int pilha[SIZEPILHA]; // Pilha
int topoPilha = -1;   // Inicialização da Pilha

/**
 * FUNÇÃO PARA CABEÇALHO
 */
void header()
{
    system("clear||cls");
    printf("\n\n");
}

/**
 * FUNÇÃO PARA EMPILHAR ELEMENTO
 */
void empilharElemento(int elemento)
{
    pilha[topoPilha + 1] = elemento;
    topoPilha++;
}

/**
 * FUNÇÃO PARA DESEMPILHAR ELEMENTO
 */
void desempilharElemento(int elemento)
{
    // --------- PILHA AUXÍLIAR --------- //
    int pilhaAux[1000];    // Tamanho da Pilha
    int topoPilhaAux = -1; // Inicialização da Pilha

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
 * FUNÇÃO PARA VERIFICAR SE A PILHA ESTÁ VAZIA
 */
int pilhaVazia()
{
    if (topoPilha == -1)
    {
        header();
        printf(">> A PILHA ESTÁ VAZIA! << \n\n\n");
        return -1;
    }
    else
    {
        return 0;
    }
}

/**
 * FUNÇÃO PARA VERIFICAR SE A PILHA ESTÁ CHEIA
 */
int pilhaCheia()
{

    if (topoPilha == SIZEPILHA - 1)
    {
        header();
        printf("\n\n\n>> A PILHA ESTÁ CHEIA! << \n\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * FUNÇÃO PARA A EXIBIR PILHA
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
        printf("%dº\t%d\n", x, pilha[x - 1]);
    }
    printf("\n:::::::::::::::::::::::::::::::::::::::::\n\n\n");
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
            printf("\n\n## Error: Entrada Inválida!\n\n");
            return;
        }
        break;
    }
}

/**
 * FUNÇÃO PRINCIPAL
 */
int main()
{

    // ----- LIBRARY CONFIGURATION TO USE ACCENT----//
    setlocale(LC_ALL, "Portuguese_Brazil");
    // ---------------------------------------------//

    printf("____________________________________________\n\n");
    printf("\tEXERCÍCIO DE PILHAS E FILAS\n");
    printf("____________________________________________\n\n");

    int menuOption;

    // ----- MENU DE OPÇÕES ----//
    do
    {

        printf("*********************************************\n");
        printf("\t     MENU  DE OPERAÇÕES\n");
        printf("*********************************************\n\n");

        printf("1 - Empilha\n");
        printf("2 - Desempilha\n");
        printf("3 - Exibir elementos da pilha\n");
        printf("4 - Sair da aplicação.\n\n");

        printf("Informe a Operação Deseja: ");
        scanf("%d", &menuOption);

        header();

        switch (menuOption)
        {

            int elemento; // Armazena o valor há ser EMPILHADO

        // --------- EMPILHAR VALORES --------- //
        case 1:;

            int doneEmpilhar; // Armazena o valor da opção (1 - Sim / 2 - Não) para continuar Empilhando

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

                    printf("Deseja continuar EMPILHANDO valores. (1 - Sim | 2 - Não)? ");
                    scanf("%d", &doneEmpilhar);

                    checkContinuity(doneEmpilhar);
                }

            } while (doneEmpilhar == 1);

            break;

        // --------- DESEMPILHAR VALORES --------- //
        case 2:;

            int doneDesempilhar; // Armazena o valor da opção (1 - Sim / 2 - Não) para continuar Desempilhando

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

                    printf("\n\nDeseja continuar DESEMPILHANDO valores. (1 - Sim | 2 - Não)? ");
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
                printf("\n\n## Error: Opção Inválida!\n\n");
            }
            break;
        }

    } while (menuOption != 4);

    return 0;
}
