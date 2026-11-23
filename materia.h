#include <stdio.h>
#ifndef MATERIA_H
#define MATERIA_H

typedef struct {

    char nome[50];
    char dia[20];
    char horario[20];
    bool terminou;
} Materias;

void cadastrar_materia (Materias *mat, int *n, FILE *arquivo);
void consultar_materia (Materias *mat, int n, FILE *fp);
void listar_materias (Materias *mat, int n, FILE *fp);
void remover_materia (Materias *mat, FILE *fp);
void concluir_materia (Materias *mat, FILE *fp);
void alterar_materia (Materias *mat, FILE *fp);

#endif