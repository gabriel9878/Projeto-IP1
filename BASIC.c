#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//-----------------[<ESTRUTURAS>]-----------------//

typedef struct{

    char user[20];
    char senha[10];

}Administrador;


typedef struct{

    int cod;//CÓDIGO DO PRODUTO;
    char nome[30];
    float precoCompra;
    float precoVenda;
    int quantidade;
    int diaValidade;
    int mesValidade;
    int anoValidade;

}Produto;


typedef struct{

    char nome[50];
    char cargo[20];
    char user[20];
    char senha[10];

}Caixa;


typedef struct{

    int totalCodigo;//SOMA DA QUANTIDAE DE TODOS OS PRODUTOS DE MESMO CÓDIGO;
    float totalProdutos;//SOMA DOS VALORES DE TODOS OS PRODUTOS;

}Compra;

//--------------[<ADMINISTRADOR: FUNÇÕES & PROCEDIMENTOS>]--------------//

void meetProduto(Produto prodt[100], int *pcq){//ENCONTRA AS INFORMAÇÕES DE UM DETERMINADO PRODUTO.

  Produto prodtemp;
  int i = 0, cod, option = 0;
  char nome[30];

  printf("\n\n----------[<BIG SIDNEY'S SUPERMARKET>]-----------\n\n");
  printf("\n'                                                   '\n");
  printf("\n'Para procura pelo CODIGO: DIGITE [<1>].            '\n");
  printf("\n'                                                   '\n");
  printf("\n'Para procura pelo NOME: DIGITE [<2>].              '\n");
  printf("\n'                                                   '\n");
  printf("\n'Para SAIR: DIGITE [<0>].                           '\n");
  printf("\n\n------------------------------------------------'\n\n");

  scanf("%d",&option);

  switch (option){

    case 1:
        printf("\n\nDigite o codigo do produto:\n\n");
        scanf("%d",&prodtemp.cod);

        while(i < *pcq){

          if(((prodt[i]).cod) == prodtemp.cod){

            printf("\n\n-------------[<INFORMAÇÕES DO PRODUTO>]------------------\n\n");

            //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
            printf("\nCodigo: %d",prodt[i].cod);
            printf("\nNome: %s",prodt[i].nome);
            printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
            printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
            printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
            printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].diaValidade, prodt[i].mesValidade, prodt[i].anoValidade);

          }
          i++;
        }
        break;

    case 2:
        printf("\n\nDigite o nome do produto:\n\n");
        fgets(prodtemp.nome,30,stdin);

        for(i = 0; i < 100; i++){

          if(strcmp((prodt[i].nome),prodtemp.nome) == 0 ){

            printf("\n\n-------------[<INFORMAÇÕES DO PRODUTO>]------------------\n\n");

            //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
            printf("\nCodigo: %d",prodt[i].cod);
            printf("\nNome: %s",prodt[i].nome);
            printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
            printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
            printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
            printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].diaValidade, prodt[i].mesValidade, prodt[i].anoValidade);

          }
        }
        break;

    default:
        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
  }
}

void cadProduto(Produto prodt[100],int *pcq){//CADASTRA UM NOVO PRODUTO.

    Produto prodtemp;
    int i, cod;
    char nome[30];

    printf("\n\n--------------[<CADASTRO DE PRODUTO>]-------------------\n\n");

    //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
    printf("\n\nDigite um codigo para o produto: \n\n");
    scanf("%d",&prodtemp.cod);

    //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
    for(i = 0; i < 100; i++){

        if((prodt[i]).cod == prodtemp.cod){

            printf("\n\nCodigo de produto já cadastrado, por favor insira outro:\n\n");
            scanf("%d",&prodtemp.cod);

        }
    }

    fflush(stdin);

    //SOLICITAÇAO E LEITURA DO NOME DO PRODUTO.
    printf("\n\nDigite um nome para o produto: \n\n");
    fgets(prodtemp.nome,30,stdin);

    //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
    for(i = 0; i < 100; i++){

        if(strcmp((prodt[i]).nome,prodtemp.nome) == 0){

            printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
            fgets(prodtemp.nome,30,stdin);

        }
    }

    //SOLICITAÇÃO E LEITURA DO PRECO DE COMPRA DO PRODUTO.
    printf("\n\nDigite o preco de compra para o produto: \n\n");
    scanf("%f",&prodtemp.precoCompra);

    //SOLICITAÇÃO E LEITURA DO PRECO DE VENDA DO PRODUTO.
    printf("\n\nDigite o preco de venda para o produto: \n\n");
    scanf("%f",&prodtemp.precoVenda);

    //SOLICITAÇÃO E LEITURA DA QUANTIDADE ARMAZENADA DO PRODUTO.
    printf("\n\nDigite a quantidade do produto: \n\n");
    scanf("%d",&prodtemp.quantidade);

    //SOLICITAÇÃO E LEITURA DO DIA DA VALIDADE DO PRODUTO.
    printf("\n\nDigite o dia da validade do produto: \n\n");
    scanf("%d",&prodtemp.diaValidade);

    //SOLICITAÇÃO E LEITURA DO MES DA VALIDADE DO PRODUTO.
    printf("\n\nDigite o mes da validade do produto: \n\n");
    scanf("%d",&prodtemp.mesValidade);

    //SOLICITAÇÃO E LEITURA DO ANO DA VALIDADE DO PRODUTO.
    printf("\n\nDigite o ano da validade do produto: \n\n");
    scanf("%d",&prodtemp.anoValidade);

    //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
    printf("\nCodigo: %d",prodtemp.cod);
    printf("\nNome: %s",prodtemp.nome);
    printf("\nPreco de Compra: %.2f",prodtemp.precoCompra);
    printf("\nPreco de Venda: %.2f",prodtemp.precoVenda);
    printf("\nQuantidade de produto armazenada: %d",prodtemp.quantidade);
    printf("\nData de validade do produto: %d/%d/%d\n",prodtemp.diaValidade, prodtemp.mesValidade, prodtemp.anoValidade);

    prodt[*pcq] = prodtemp;

    (*pcq)++;

    printf("Quantidade de produtos diversos: %d",*pcq);

    printf("\n\nProduto cadastrado com sucesso.");

}



int main(){

    //------------------------[<CONTADORES>]---------------------//

    //DEFINICAO DOS CONTADORES (POSIÇÃO DE ARMAZENAMENTO NO VETOR).
    int admCadQtd = 0;
    int prodCadQtd = 0;
    int caixaCadQtd = 0;

    //------------------------[<CONSTANTES>]---------------------//

    int ADM_MAX = 3;      //MAXIMO DE FUNCIONARIOS TIPO ADMINISTRADOR
    int CAIXA_MAX = 4;    //MAXIMO DE FUNCIONARIOS TIPO CAIXA
    int PROD_MAX = 100;  //MAXIMO DE PRODUTOS DO SUPERMERCADO

    //-----------------------------------------------------------//


    //------------------------[<VETORES>]-----------------------//


    //DECLARACAO DO VETORES ESTRUTURADOS.
    Administrador admt[ADM_MAX];
    Caixa cx[CAIXA_MAX];
    Produto prodt[PROD_MAX];

    //-----------------------------------------------------------//

    //DECLARACAO DOS PRODUTOS 1 E 2 PARA TESTE DE FUNCIONAMENTO DO SUPERMERCADO.
    Produto prodt1;

    prodt1.cod = 1;
    strcpy(prodt1.nome,"coca-cola");
    prodt1.precoCompra = 3.5;
    prodt1.precoVenda = 4.5;
    prodt1.quantidade = 50;
    prodt1.diaValidade = 10;
    prodt1.mesValidade = 10;
    prodt1.anoValidade = 2020;

    Produto prodt2;

    prodt2.cod = 5;
    strcpy(prodt2.nome,"chocolate");
    prodt2.precoCompra = 1.5;
    prodt2.precoVenda = 6.5;
    prodt2.quantidade = 100;
    prodt2.diaValidade = 20;
    prodt2.mesValidade = 10;
    prodt2.anoValidade = 2022;

    prodCadQtd = 2;

    cadProduto(prodt,&prodCadQtd);

    meetProduto(prodt,&prodCadQtd);

    return 0;

}
