#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETRAS 26
#define NUMEROS 10
#define SEPARADORES 4
#define PALAVRA_RESERVADA 19
#define ESPECIAIS 14

const char letras[LETRAS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                             's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const char numeros[NUMEROS] = {'0', '1', '2', '3', '4',
                               '5', '6', '7', '8', '9'};
const char separadores[SEPARADORES] = {'\t', '\n', ' ', '\b'};

const char *palavras_reservadas[PALAVRA_RESERVADA] = {
    "program", "label", "type", "array", "of", "var", "procedure",
    "function", "begin", "end", "if", "then", "else", "while",
    "do", "or", "and", "div", "not"};

const char simbolos_especiais[ESPECIAIS] = {'.', ',', ';', '(', ')', ':', '=',
                                            '<', '>', '+', '-', '*', '[', ']'};

int contains(char letra, const char *alfabeto, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (letra == alfabeto[i])
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    char *input = "isso1 [aqui] e not program 12s\0";
    char *token, *palavra_atual;
    int posicao, comeco_palavra;
    int indice = 0, qtd_tokens = 0, tem_numero = 0, tem_letra = 0,
        tem_especial = 0, qtd_identificador = 0, qtd_palavras_reservadas = 0,
        qtd_erro = 0, qtd_numero = 0, qtd_especiais = 0;

    // enquanto a letra for diferente de \0
    while (input[indice] != '\0')
    {
        // iniciando o token
        token = &input[indice]; // endereco de memoria
        // enquanto a letra for diferente do separador e diferente de \0
        while (contains(input[indice], separadores, SEPARADORES) == 0 &&
               input[indice] != '\0')
        {
            // COMEÇO COM LETRA
            if (contains(input[indice], letras, LETRAS) == 1)
            {
                // percorrendo a palavra, coletando letra e numero
                while (contains(input[indice], letras, LETRAS) == 1 ||
                       contains(input[indice], numeros, NUMEROS) == 1)
                {
                    // se tiver numero...
                    if (contains(input[indice], numeros, NUMEROS) == 1)
                        tem_numero = 1;
                    // se tiver letra...
                    if (contains(input[indice], letras, LETRAS) == 1)
                        tem_letra = 1;
                    // proxima letra
                    indice++;
                }
                // neste momento input[indice] = SEPARADORES
                // posicao da palavra atual
                posicao = (&input[indice] - token);
                comeco_palavra = indice - posicao;
                palavra_atual = (char *)calloc(
                    (posicao + 1), sizeof(char)); // aloca memória para palavra
                // preenchendo letra por letra na palavra_atual
                for (int i = 0; i < posicao; i++)
                {
                    palavra_atual[i] = input[comeco_palavra + i];
                }
                palavra_atual[posicao] = '\0'; // uma boa prática
                printf("'%s'\n", palavra_atual);

                for (int j = 0; j < posicao; j++)
                {
                    if (contains(palavra_atual[j], simbolos_especiais, ESPECIAIS) == 1)
                    {
                        tem_especial = 1;
                    }
                }

                if (tem_especial == 1)
                {
                    qtd_especiais++;
                    tem_especial = 0;
                }
                if (tem_numero == 1)
                {
                    qtd_identificador++;
                    qtd_tokens++;
                    tem_numero = 0;
                }
                // se não tiver número
                else
                {
                    for (int i = 0; i < PALAVRA_RESERVADA; i++)
                    {
                        // se for palavra reservada
                        if (strcmp(palavra_atual, palavras_reservadas[i]) == 0)
                        {
                            qtd_palavras_reservadas++;
                            qtd_tokens++;
                            break;
                        }
                        // se não for palavra reservada
                        else
                        {
                            if (i == PALAVRA_RESERVADA - 1)
                            {
                                qtd_identificador++;
                                qtd_tokens++;
                            }
                        }
                    }
                }
                free(palavra_atual); // libera memória alocada
            }
            // COMEÇO COM NÚMERO
            if (contains(input[indice], numeros, NUMEROS) == 1)
            {
                // percorrendo a palavra, coletando letra e numero
                while (contains(input[indice], letras, LETRAS) == 1 ||
                       contains(input[indice], numeros, NUMEROS) == 1)
                {
                    // se tiver letra...
                    if (contains(input[indice], letras, LETRAS) == 1)
                        tem_letra = 1;
                    // proxima letra
                    indice++;
                }
                // neste momento input[indice] = SEPARADORES
                // posicao da palavra atual
                posicao = (&input[indice] - token);
                comeco_palavra = indice - posicao;
                palavra_atual = (char *)calloc(
                    (posicao + 1), sizeof(char)); // aloca memória para palavra
                // preenchendo letra por letra na palavra_atual
                for (int i = 0; i < posicao; i++)
                {
                    palavra_atual[i] = input[comeco_palavra + i];
                }
                palavra_atual[posicao] = '\0'; // uma boa prática
                printf("'%s'\n", palavra_atual);

                if (tem_letra == 1)
                {
                    qtd_erro++;
                    tem_letra = 0;
                }
                else
                {
                    qtd_numero++;
                    qtd_tokens++;
                }
                free(palavra_atual); // libera memória alocada
            }

            // VERIFICAÇÃO DE CARACTERES ESPECIAIS
            if (contains(input[indice], simbolos_especiais, ESPECIAIS) == 1)
            {

                qtd_especiais++;
                qtd_tokens++;
                indice++;
            }
        }
        // adicionando um apos encontrar o separador
        indice++;
    }
    printf("quantidade identificador = %d\nquantidade palavras reservadas = "
           "%d\nquantidade de numeros = %d\nquantidade de especiais = "
           "%d\nquantidade tokens = %d\nquantidade de erros = %d\n",
           qtd_identificador, qtd_palavras_reservadas, qtd_numero,
           qtd_especiais - 1, qtd_tokens, qtd_erro);

    return 0;
}
