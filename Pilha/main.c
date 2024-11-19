#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int id;
    char nome[50];

    struct no *next, *back;
}no;

struct no *topo, *auxiliar;

int contador = 0;

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){
    auxiliar=NULL;
    topo=NULL;

    int opcao;

    do{
        system("cls");

        printf("\n\tPilha");

        printf("\n\n|1|Inserir. PUSH");
        printf("\n|2|Consultar topo da Pilha. TOP");
        printf("\n|3|Remover item da lista. POP");
        printf("\n|4|Sair.");

        printf("\n\nDigite sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            push();
        break;
        case 2:
            system("cls");
            top();
        break;
        case 3:
            system("cls");
            pop();
        break;
        case 4:
            system("cls");
            printf("\n\tSaindo...\n");
            exit(0);
        break;
        default:
            system("cls");
            printf("\n\tOpcao nao encontrada!!\n\tTente novamente...\n\n");
            system("pause");
            main();
        }

    }while(opcao < 5);
    return;
}

void push(){
    if(contador >=3){
        printf("\nA pilha esta cheia. STACK OVERFLOW\n\n");
        system("pause");
        main();
    }else if(topo == NULL){
        topo = (no*)malloc(sizeof(no));
        topo->next = NULL;
        topo->back = NULL;
        auxiliar = topo;

    }else{
        topo = (no*)malloc(sizeof(no));
        auxiliar->next = topo;
        topo->back = auxiliar;
        auxiliar = topo;
        topo->next = NULL;
    }

    printf("\nInsira o ID: ");
    scanf("%d", &topo->id);

    limparBuffer();

    printf("\nInsira o Nome: ");
    gets(topo->nome);

    contador++;
}

void top(){
    if(topo == NULL){
        printf("\nPilha vazia\n");
        system("pause");
    }else{
        printf("\nID: %d | Nome: %s\n\n", topo->id, topo->nome);
        system("pause");
    }
}

void pop(){
    if(topo == NULL){
        printf("\nA Pilha ja esta vazia.\n");
        system("pause");
    }else if(topo->next == NULL && topo->back == NULL){
        free(topo);
        topo=NULL;

        contador = 0;

        printf("\nItem removido com sucesso.");
        printf("\nPilha vazia\n");
        system("pause");
        main();
    }else{
        auxiliar = topo;
        topo = topo->back;
        free(auxiliar);
        topo->next=NULL;
        contador--;

        printf("\nItem removido com sucesso.\n");
        system("pause");
    }
}
