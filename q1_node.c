/*Escreva uma função que receba como
parâmetro uma lista encadeada e retorne a
quantidade de células da lista.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{ //criando o nó e definindo ele como um tipo.
    int dado;//campo para atribuir o dado ao nó.
    struct node* proximo;//campo para atribuir o endereço do próximo nó.
}node;

//inserir novo nó no final da lista
void inserirfim(node** head, int novodado){ //traçando parâmetros para o novo dado e para o ponteiro de ponteiro da cabeça da lista.
    node *novonode = malloc(sizeof(node)); //determinando um novo nó a partir do tamanho do nó ja criado.
    novonode->dado = novodado; //inserindo o valor por parâmetro no campo do novo nó.
    novonode->proximo = NULL; //aterrando o campo de endereço a 'NULL".

    if(*head == NULL){ //verificando se a cabeça da lista está vazia. Caso esteja, a cabeça apontará para o próximo nó.
        *head = novonode;
    }else{//caso não esteja, a lista percorrerá até que encontre o último nó.
        node *aux = *head; //criando uma variável auxiliar para percorrer a lista e verificar, fazendo com que ela receba as propriedades de um novo nó.
        while(aux->proximo != NULL){
            aux = aux->proximo;//inserindo o endereço do novo nó no nó atual.
        }
        aux->proximo = novonode;//quando chega ao final da lista, ele é definido como o último nó.
    }
}

int contagem(node *head){
    node *aux =  head;
    int i=0;
    while(aux != NULL){
        i++;
        aux = aux->proximo;
    }
    
    return i;
}

int main(){
    node* lista = NULL;
    char c;
    int num;

    do{
        printf("Digite um número: ");
        scanf("%d", &num);
        inserirfim(&lista, num);

        printf("\nDeseja inserir mais?[s/n]\n");
        scanf(" %c", &c);

        system("cls");
    }while(c != 'n');

    int quantidade = contagem(lista);
    
    printf("Há %d celulas dentro da lista\n", quantidade);

    node* atual = lista;

    while(atual != NULL){
        node* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}