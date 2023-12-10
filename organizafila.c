#include<ctype.h>
#include<string.h>
#include "pilha.h"
#include "fila.h"


void organizafila(tp_fila *fila_main, int z){
    tp_pilha pilha_aux;
    tp_item e;
    
    inicializa_pilha(&pilha_aux);
    for(int i = 0; i<z; i++){
    remove_fila(fila_main, &e);
    if(!isdigit(e)){
        insere_fila(fila_main, e);
    }
    else{
        push(&pilha_aux, e);
    }
    }
    
    while(!pilha_vazia(&pilha_aux)){
        pop(&pilha_aux, e);
        insere_fila(fila_main, e);
    }
    imprime_fila(fila_main);

}

int main(){
    char string[50];
    tp_fila fila_main;
    
    inicializa_fila(&fila_main);
    printf("digite uma sequencia de caracteres: \n");
    scanf(" %s", &string);
    strlen(string);
    for(int i = 0; i<strlen(string); i++){
        insere_fila(&fila_main, string[i]);
    }
    
    organizafila(&fila_main, strlen(string));
    
        
    return 0;
}