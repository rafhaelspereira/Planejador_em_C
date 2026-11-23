#include <stdio.h>
#include <stdlib.h>

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