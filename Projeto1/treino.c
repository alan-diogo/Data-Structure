#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkValue(const char letter)
{
  switch (tolower((unsigned char)letter))
  {
  case 'q':
    return 1;
  case 'w':
    return 6;
  case 'e':
    return 7;
  case 'r':
    return 6;
  case 't':
    return 5;
  case 'y':
    return 2;
  case 'u':
    return 3;
  case 'i':
    return 8;
  case 'o':
    return 9;
  case 'p':
    return 4;
  case 'á':
    return 3;
  case 'ã':
    return 4;
  case 'a':
    return 2;
  case 's':
    return 5;
  case 'd':
    return 8;
  case 'f':
    return 7;
  case 'g':
    return 4;
  case 'h':
    return 1;
  case 'j':
    return 4;
  case 'k':
    return 7;
  case 'l':
    return 8;
  case 'ç':
    return 5;
  case 'é':
    return 2;
  case 'í':
    return 3;
  case 'z':
    return 3;
  case 'x':
    return 4;
  case 'c':
    return 9;
  case 'v':
    return 8;
  case 'b':
    return 3;
  case 'n':
    return 2;
  case 'm':
    return 5;
  case 'ó':
    return 6;
  case 'õ':
    return 7;
  case 'ô':
    return 6;
  case 'â':
    return 1;
  case 'ê':
    return 2;
  default:
    return 0; // Se o caractere não estiver no mapeamento
  }
}

void ReadName()
{
  char name[99]; // recebe o nome
  char *tokens;  // aponta para cada endereco da string
  int index = 0, valueTokens[20];
  char *tokensName[20];

  fgets(name, 99, stdin); // LEr nome

  tokens = strtok(name, " "); // \0 no lugar de cada espaco da minha string
  while (tokens)              // roda ate encontrar um token com valor nulo
  {
    for (int i = 0; tokens[i]; i++)
    { // objetivo é pegar token na posicao I(cada posicao tem uma string) e deixa minuscula
      tokens[i] = tolower((unsigned char)tokens[i]);
    }

    tokensName[index] = strdup(tokens); // Usando strdup para alocar memória p string  //cada item de valuename é um ponteiro para char. ou seja é uma string.
    for (int i = 0; tokens[i] != '\0'; i++)
    {
      valueTokens[index] += checkValue(tokens[i]); // Soma os valores de cada letra do nome
    }
    tokens = strtok(NULL, " "); // passamos para o proximo token;
    index++;                    // voce vai guardar o tamanho do vetor que eu quero; com base na quantidade de iteracao
  }
}

int main()
{
  ReadName();

  return 0;
}