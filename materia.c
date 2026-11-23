#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "materia.h"

void cadastrar_materia (Materias *mat, int *n, FILE *fp) {

    Materias *p = &mat[0];
    int i = 1, j = 0;
    char res_bool[10], res_final[10];
    fp = fopen ("PLANEJADOR.txt", "a");
    if(fp == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    do {

        system("clear");

        printf("Nome: ");
        scanf(" %[^\n]", p->nome);

        printf("Dia(s) de aula: ");
        scanf(" %[^\n]", p->dia);

        printf("Horário: ");
        scanf(" %[^\n]", p->horario);

        printf("Já terminou: ");
        scanf(" %[^\n]", res_bool);

        while (res_bool[j] != '\0') {
            res_bool[j] = tolower (res_bool[j]);
            j++;
        }

        if(strcmp(res_bool, "sim") == 0) {
            p->terminou = true;
        } else {
            p->terminou = false;
        }
        j = 0;

        fprintf(fp, "%s\t%s\t%s\t%s\n------------------------------------------------------------\n",
        p->nome, p->dia, p->horario, (p->terminou == 1) ? "CONCLUIDA" : "CURSANDO");
    
        i++;
        p++;
        *n++;

        printf("\nDeseja adicionar mais uma matéria? ");
        scanf(" %[^\n]", res_final);
        while (res_final[j] != '\0') {
            res_final[j] = tolower (res_final[j]);
            j++;
        }

    } while (strcmp(res_final, "sim") == 0);
    fclose(fp);

}

void consultar_materia (Materias *mat, int n, FILE *fp) {

    Materias *p = &mat[0];
    char nome_mat[50];
    int i = 0;
    fp = fopen ("PLANEJADOR.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    printf("Digite o nome da matéria: ");
    scanf(" %[^\n]", nome_mat);

    char nome_encontrado[50];
    int encontrou = 0;

    while(fgets(nome_encontrado, 50, fp) != NULL) {

        if(strcmp(nome_mat, nome_encontrado) == 0)
            encontrou = 1;
    }


    if(encontrou == 0) {
        printf("Matéria não encontrada\n");
        return;
    }

    char *pmat = strstr(nome_mat, nome_encontrado);

    printf("----------MATERIA ENCONTRADA----------\n");
    printf("NOME: %s\nDIAS: %s\nHORARIO: %s\n%s\n",
        p->nome, p->dia, p->horario, (p->terminou == 1) ? "CONCLUIDA" : "CURSANDO");

    fclose(fp);

}

void listar_materias (Materias *mat, int n, FILE *fp) {

    Materias *p = &mat[0];
    int i;

    for(i = 0; i < n; i++) {

        printf("NOME: %s\nDIAS: %s\nHORARIO: %s\n%s\n----------",
            p->nome, p->dia, p->horario, (p->terminou == 1) ? "CONCLUIDA" : "CURSANDO");

        p++;
    }

}

void remover_materia (Materias *mat, FILE *fp) {



}

void concluir_materia (Materias *mat, FILE *fp) {



}

void alterar_materia (Materias *mat, FILE *fp) {



}