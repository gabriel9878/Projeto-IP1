#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//estrutura de um produto.

typedef struct{

int id;
char nome[15];
float preco;
int quantidade;

}PRODUTO;

int main (){

//declara��o da variavel que controla o menu.
int key;

//declara��o do produto1 para teste do funcionamento do mercado.

PRODUTO produto1;

strncpy(produto1.nome,"coca-cola",9);
produto1.id = 1;
produto1.preco = 4.5;
produto1.quantidade = 50;

//declara��o do produto2 para teste do funcionamento do mercado.

PRODUTO produto2;

strncpy(produto2.nome,"chocolate",9);
produto2.id = 2;
produto2.preco = 2.0;
produto2.quantidade = 30;

//loop que far� com que o menu apare�a constantemente enquanto o programa estiver rodando.

do{

//armazenamento da vari�vel que controla o menu.
scanf("%i",&key);

//MENU
switch(key){
//op��o 1.
case 1 :{

printf("voce escolheu a opcao 1\n");
break;
}

//op��o 2.
case 2 : {

printf("voce escolheu a opcao 2\n");
break;
}

//op��o 3.
case 3 : {

printf("voce escolheu a opcao 3\n");
break;
}


}
}while(key!=0);

}
