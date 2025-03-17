#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *x;
  x = malloc(sizeof(int));
  if (x) // diferente de null
    printf("MEmoria alocada com sucesso");
  *x = 50;
  printf("x :%d", *x);
  else printf("Erro para alocar memoria!");

  return 0;
}