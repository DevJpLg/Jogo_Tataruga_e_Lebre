#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Jogo Tartaruga & Lebre

void atualizarPosicaoTartaruga(int *posicaoTartaruga)
{
    int numeroAleatorio = (rand () % 10) + 1;
    if(*posicaoTartaruga < 1)
    {
       *posicaoTartaruga = 1;
    }
    else
    {
        if ((numeroAleatorio >= 1) && (numeroAleatorio <= 5))
        {
            *posicaoTartaruga = *posicaoTartaruga + 3;
        }
        else
        {
            if ((numeroAleatorio >= 6) && (numeroAleatorio <= 7))
            {
                *posicaoTartaruga = *posicaoTartaruga - 6;
            }
            else
            {
                if ((numeroAleatorio >= 8) && (numeroAleatorio <= 10))
                 {
                    *posicaoTartaruga = *posicaoTartaruga + 1;
                }
            }
        }
    }
}

void atualizarPosicaoLebre(int *posicaoLebre)
{
    int numeroAleatorio = (rand () % 10) + 1;
    if(*posicaoLebre < 1)
    {
        *posicaoLebre = 1;
    }
    else
    {
        if ((numeroAleatorio >= 1) && (numeroAleatorio <= 2))
        {
            *posicaoLebre = *posicaoLebre + 0;
        }
        else
        {
            if ((numeroAleatorio >= 3) && (numeroAleatorio <= 4))
            {
                *posicaoLebre = *posicaoLebre + 9;
            }
            else
            {
                if (numeroAleatorio == 5)
                {
                    *posicaoLebre = *posicaoLebre - 12;
                }
                else
                {
                    if ((numeroAleatorio >= 6) && (numeroAleatorio <= 8))
                    {
                        *posicaoLebre = *posicaoLebre + 1;
                    }
                    else
                    {
                        if ((numeroAleatorio >= 9) && (numeroAleatorio <= 10))
                        {
                            *posicaoLebre = *posicaoLebre - 2;
                        }
                    }
                }
            }
        }
    }
}

int validarPosicao(int posicaoAnimal)
{
    if(posicaoAnimal < 1)
    {
        return 1;
    }
    if(posicaoAnimal > 70)
    {
        return 70;
    }
    return posicaoAnimal;
}

void imprimirCorrida(int posicaoTartaruga, int posicaoLebre)
{
    int posicaoAtual;
    for (posicaoAtual  = 1; posicaoAtual <= 70; posicaoAtual ++)
    {
        if ((posicaoLebre == posicaoAtual ) && (posicaoTartaruga == posicaoAtual))
        {
            printf("Ouch!");
        }
        else
        {
            if (posicaoTartaruga == posicaoAtual )
            {
                printf("T");
            }
            else
            {
                if (posicaoLebre == posicaoAtual )
                {
                    printf("L");
                }
                else
                {
                    printf("-");
                }
            }
        }
    }
    fflush(stdout);
    system("sleep 0.2");
    system("clear");
    printf("\n");
}

void imprimirResultado(int posicaoLebre, int posicaoTartaruga)
{
    if(posicaoLebre == 70)
    {
        printf("\nLEBRE VENCEU!!! YUCH!!!");
    }
    else
    {
        if(posicaoTartaruga == 70)
        {
            printf("\nTARTARUGA VENCEU!!! YAY!!!");
        }
        else
        {
            printf("\nHouve um Empate!");
        }
    }
}

int main ()
{
    int posicaoTartaruga = 1, posicaoLebre = 1;
    system("clear");
    srand(time(NULL));
    printf("\nBANG!!!! E ELES PARTIRAM!!!!\n");
    while ((posicaoTartaruga < 70) && (posicaoLebre < 70))
    {
        atualizarPosicaoTartaruga(&posicaoTartaruga);
        posicaoTartaruga = validarPosicao(posicaoTartaruga);
        atualizarPosicaoLebre(&posicaoLebre);
        posicaoLebre = validarPosicao(posicaoLebre);
        imprimirCorrida(posicaoTartaruga, posicaoLebre);
    }
    imprimirResultado(posicaoTartaruga, posicaoLebre);
    return 0;
}