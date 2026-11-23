#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "materia.h"
#include "prova.h"
#include "interface.h"

int main () {

    FILE *arquivo = fopen("PLANEJADOR.txt", "a");

    if(arquivo == NULL) {

        printf("ERRO AO ABRIR ARQUIVO\n");
        exit(1);

    }
    fclose(arquivo);

    Materias materias[20];
    int qntd_mat = 0, qntd_prv = 0;
    
    Provas provas[20], *q;

    while (1) {

        int escolha1 = menu_1();
        
        if (escolha1 == 3)
        break;

        else if (escolha1 == 1) {

            while (1) {

                int escolha2 = menu_2();

                if (escolha2 == 0)
                break;

                else if (escolha2 == 1) {

                    cadastrar_materia (materias, &qntd_mat, arquivo);  

                } else if (escolha2 == 2) {

                    consultar_materia (materias, qntd_mat, arquivo);

                } else if (escolha2 == 3) {

                    listar_materias (materias, qntd_mat, arquivo);

                } else if (escolha2 == 4) {

                    remover_materia (materias, arquivo);

                } else if (escolha2 == 5) {

                    concluir_materia (materias, arquivo);

                } else if (escolha2 == 6) {

                    alterar_materia (materias, arquivo);
                }
            }

        } else {

            while (1) {

                int escolha3 = menu_3();

                if (escolha3 == 0)
                break;

                else if (escolha3 == 1) {

                    cadastrar_prova (provas, &qntd_prv, arquivo);  

                } else if (escolha3 == 2) {

                    consultar_prova (provas, arquivo);

                } else if (escolha3 == 3) {

                    listar_provas (provas, qntd_prv, arquivo);

                } else if (escolha3 == 4) {

                    remover_prova (provas, arquivo);

                } else if (escolha3 == 5) {

                    concluir_prova (provas, arquivo);

                } else if (escolha3 == 6) {

                    alterar_prova (provas, arquivo);
                }
            }
        }
    }
}

int menu_1 (void) {

    char res[10], adc;
    int resposta;

    printf("\n----------MENU----------\n1.Máterias\n");
    printf("2.Provas\n3.Sair\nEscolha: ");
    scanf(" %s", res);

    int aux = sscanf (res, " %d %c", &resposta, &adc);

    while (aux != 1) {
        
        if(resposta == 1 || resposta == 2 || resposta == 3)
        break;

        printf("Resposta inválida.\n");
        printf("\n----------MENU INICIAL----------\n1.Máterias\n");
        printf("2.Provas\n3.Sair\nEscolha: ");
        scanf(" %s", res);
        aux = sscanf (res, " %d %c", &resposta, &adc);
    
    }
    
    return resposta;

}

int menu_2 (void) {

    char res[10], adc;
    int resposta;
    system("clear");

    printf("\n----------MENU MATÉRIAS----------\n");
    printf("1.Cadastrar\n2.Consultar\n3.Listar\n4.Remover\n5.Concluir\n6.Alterar\n0.Voltar\n");

    scanf(" %s", res);
    int aux = sscanf (res, " %d %c", &resposta, &adc);

    while (aux != 1) {
        
        if(resposta >= 0 && resposta <= 6)
        break;  

        printf("Resposta inválida.\n");
        printf("\n----------MENU MATÉRIAS----------\n");
        printf("1.Cadastrar\n2.Consultar\n3.Listar\n4.Remover\n5.Concluir\n6.Alterar\nEscolha: ");
        scanf(" %s", res);
        aux = sscanf (res, " %d %c", &resposta, &adc);
    
    }
    
    return resposta;

}

int menu_3 (void) {

    char res[10], adc;
    int resposta;
    system("clear");

    printf("\n----------MENU PROVAS----------\n");
    printf("1.Cadastrar\n2.Consultar\n3.Listar\n4.Remover\n5.Concluir\n6.Alterar\n0.Voltar\n");

    scanf(" %s", res);
    int aux = sscanf (res, " %d %c", &resposta, &adc);

    while (aux != 1) {
        
        if(resposta >= 0 && resposta <= 6)
        break;
            

        printf("Resposta inválida.\n");
        printf("\n----------MENU MATÉRIAS----------\n");
        printf("1.Cadastrar\n2.Consultar\n3.Listar\n4.Remover\n5.Concluir\n6.Alterar\nEscolha: ");
        scanf(" %s", res);
        aux = sscanf (res, " %d %c", &resposta, &adc);
    
    }
    
    return resposta;

}

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

void cadastrar_prova (Provas *prv, int *n, FILE *fp) {



}

void consultar_prova (Provas *prv, FILE *fp) {



}

void listar_provas (Provas *prv, int n, FILE *fp) {



}

void remover_prova (Provas *prv, FILE *fp) {



}

void alterar_prova (Provas *prv, FILE *fp) {



}

void concluir_prova (Provas *prv, FILE *fp) {



}