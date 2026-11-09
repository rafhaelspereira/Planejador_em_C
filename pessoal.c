#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {

    char materia[50];
    char dia[20];
    char horario[20];
    bool terminou;
} Materias;

typedef struct {

    Materias ref;
    char dia_prova[20];
    char horario_prova[20];
    bool feita;
} Provas;

int menu_1 (void);
int menu_2 (void);

void cadastrar_materia (Materias *mat, int n);
void consultar_materia (Materias *mat, int n);
void listar_materias (Materias *mat, int n);
void remover_materia (Materias *mat, int n);
void concluir_materia (Materias *mat, int n);
void alterar_materia (Materias *mat, int n);

void cadastrar_prova (Provas *prv, int n);
void consultar_prova (Provas *prv, int n);
void listar_provas (Provas *prv, int n);
void remover_prova (Provas *prv, int n);
void concluir_prova (Provas *prv, int n);
void alterar_prova (Provas *prv, int n);

int main () {

    Materias materias[20];
    Provas provas[20];

}

int menu_1 (void) {


}

int menu_2 (void) {



}

void cadastrar_materia (Materias *mat, int n) {



}

void consultar_materia (Materias *mat, int n) {



}

void listar_materias (Materias *mat, int n) {



}

void remover_materia (Materias *mat, int n) {



}

void concluir_materia (Materias *mat, int n) {



}

void alterar_materia (Materias *mat, int n) {



}

void cadastrar_prova (Provas *prv, int n) {



}

void consultar_prova (Provas *prv, int n) {



}

void listar_provas (Provas *prv, int n) {



}

void remover_prova (Provas *prv, int n) {



}

void alterar_prova (Provas *prv, int n) {



}

void concluir_prova (Provas *prv, int n) {



}