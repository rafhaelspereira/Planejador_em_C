#include <stdio.h>
#include "materia.h"

#ifndef PROVA_H
#define PROVA_H

typedef struct {

    Materias ref;
    char dia_prova[20];
    char horario_prova[20];
    bool feita;
} Provas;

void cadastrar_prova (Provas *prv, int *n, FILE *fp);
void consultar_prova (Provas *prv, FILE *fp);
void listar_provas (Provas *prv, int n, FILE *fp);
void remover_prova (Provas *prv, FILE *fp);
void concluir_prova (Provas *prv, FILE *fp);
void alterar_prova (Provas *prv, FILE *fp);

#endif