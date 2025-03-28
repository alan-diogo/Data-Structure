#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DISCIPLINAS 50
#define TAM_CODIGO 10
#define TAM_NOME 50
#define MAX_PRE_REQ 3
#define DIAS_AULA 2
#define TAM_LINHA 512

typedef struct
{
  char codigo[TAM_CODIGO];
  char nome[TAM_NOME];
  int turno;
  int carga_horaria;
  int semestre;
  char pre_requisitos[MAX_PRE_REQ][TAM_CODIGO];
  int qtd_pre_requisitos;
  char dias_aula[DIAS_AULA][4];
  char horarios[DIAS_AULA][12];
  bool obrigatoria;
} Disciplina;

int main()
{
  int i = 0; // Inicializa o índice
  char *tok;
  FILE *fp;
  char S[40];
  Disciplina disciplinas[MAX_DISCIPLINAS];

  fp = fopen("disciplinas.csv", "r");
  if (fp == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  while (fgets(S, sizeof(S), fp) != NULL && i < MAX_DISCIPLINAS)
  {
    tok = strtok(S, ";");
    if (tok != NULL)
    {
      strncpy(disciplinas[i].codigo, tok, TAM_CODIGO - 1);
      disciplinas[i].codigo[TAM_CODIGO - 1] = '\0'; // Garante terminação da string
    }

    disciplinas[i].codigo[strcspn(disciplinas[i].codigo, "\r\n")] = '\0'; // Remove \n e \r

    printf("Código: %s\n", disciplinas[i].codigo);
    i++; // Incrementa o índice corretamente
  }

  fclose(fp);
  return 0;
}