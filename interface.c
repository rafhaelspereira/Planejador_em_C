#include <stdio.h>
#include <string.h>

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