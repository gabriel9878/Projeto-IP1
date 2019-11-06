#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <locale.h>


//-----------------[<ESTRUTURAS>]-----------------//

typedef struct{

char user[20];
char senha[10];

}Administrador;


typedef struct{

    int dia;
    int mes;
    int ano;

}Validade;


typedef struct{

    int cod;//CÓDIGO DO PRODUTO;
    char nome[30];
    float preco_compra;
    float preco_venda;
    int quantidade;
    Validade dataValidade;

}Produto;


typedef struct{

    char nome[50];
    char cargo[20];
    char user[20];
    char senha[10];

}Funcionario;


typedef struct{

    int cod_produto;//SOMA DA QUANTIDAE DE TODOS OS PRODUTOS DE MESMO CÓDIGO;
    float total_produtos;//SOMA DOS VALORES DE TODOS OS PRODUTOS;

}ProdutoCompra;


typedef struct{

    ProdutoCompra itemCompra;
    int total_codigo;//SOMA DA QUANTIDAE DE TODOS OS PRODUTOS DE MESMO CÓDIGO;
    float total_produtos;//SOMA DOS VALORES DE TODOS OS PRODUTOS;

}Compra;


//--------------[<MENU PRINCIPAL: PROCEDIMENTO>]-----------------//


void menuPrincipal(){//MOSTRA O MENU PRINCIPAL;

    int option = 0;

    printf("\n\n----------[<BIG SIDNEY'S SUPERMARKET>]-----------\n\n");
    printf("\n\n------------------[<WELCOME>]--------------------\n\n");
    printf("\n'                                                   '\n");
    printf("\n'Para logar-se como ADMINISTRADOR: DIGITE [<1>].    '\n");
    printf("\n'                                                   '\n");
    printf("\n'Para logar-se como CAIXA: DIGITE [<2>].            '\n");
    printf("\n'                                                   '\n");
    printf("\n'Para SAIR: DIGITE [<0>].                           '\n");
    printf("\n\n------------------------------------------------'\n\n");

    scanf("%d",&option);

    switch(option){

        case 1:
            loginAdm();
            break;

        case 2:
            loginCaixa();
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");

    }
}

//--------------[<ADMINISTRADOR: FUNÇÕES & PROCEDIMENTOS>]--------------//

void menuAdm(char login[20]){//MOSTRA O MENU DO ADMINISTRADOR.

    int option =  0;

    system("cls");

    printf("\n");

    system("cls");

    printf("\n\n");

    printf("Welcome, %s!",login);

    printf("\n\n");

    printf("'--------------------[<MENU ADMINISTRADOR>]----------------------'\n");
    printf("'                                                                '\n");
    printf("'Para INSERIR um novo PRODUTO: DIGITE [<1>].                     '\n");
    printf("'                                                                '\n");
    printf("'Para SAIR do MENU ADMINISTRADOR: DIGITE [<0>].                  '\n");
    printf("'                                                                '\n");
    printf("'----------------------------------------------------------------'\n");

    printf("\n\n");

    scanf("%d",&option);

     switch(option){

        case 1:
            insProduto();
            break;

        default:
            system("cls");
            printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
            menuPadrao();
            break;

     }
}

void insProduto(){//ADICIONA UM PRODUTO A LISTA DE ITENS DISPONIVEIS PARA VENDA NO SUPERMERCADO.

    Produto prodt;

    int prodCadQtd = 1;

    system("cls");

    printf("--------------CADASTRO DE PRODUTO-------------------\n\n\n");

    printf("Digite um codigo numerico de produto: \n\n");
    scanf("%d",&prodt.cod);
    fflush(stdin);

    while(checkCodProduto(prodt.cod) == 1){
        printf("\nCodigo de produto já cadastrado, por favor insira outro:\n\n");
        scanf("%d",&prodt.cod);
        fflush(stdin);
    }

    printf("\nDigite o nome do produto: \n\n");
    fgets(prodt.nome,30,stdin);
    fflush(stdin);
    fflush(stdin);

    while(checkNomeProduto(prodt.nome) == 1){
        printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
        fgets(prodt.nome,100,stdin);
        fflush(stdin);
        fflush(stdin);
    }

    fflush(stdin);

    printf("\nDigite o preço de compra do produto: \n\n");
    scanf("%lf",&prodt.preco_compra);
    fflush(stdin);

    printf("\nDigite o preço de venda do produto: \n\n");
    scanf("%lf",&prodt.preco_venda);
    fflush(stdin);

    printf("\nDigite a quantidade do produto: \n\n");
    scanf("%d",&prodt.quantidade);
    fflush(stdin);

    printf("\nDigite o dia da data de validade do produto: \n\n");
    scanf("%d",&prodt.dataValidade.dia);
    fflush(stdin);

    printf("\nDigite o mes da data de validade do produto: \n\n");
    scanf("%d",&prodt.dataValidade.mes);
    fflush(stdin);

    printf("\nDigite o ano da data de validade do produto: \n\n");
    scanf("%d",&prodt.dataValidade.ano);
    fflush(stdin);

    prodt[prodCadQtd] = prodt;

    prodCadQtd++;

    printf("\n\nProduto cadastrado com sucesso.");

    system("pause");

}

int checkCodProduto(int cod){//CHECA SE O CODIGO DO PRODUTO JA ESTA CADASTRADO.
    int i = 0;

    for(i = 0; i < prodCadQtd; i++){
        if(prodts[i].cod == cod){
            return 1;
        }
    }

    return 0;
}

int checkNomeProduto(char nome[30]){

    int i = 0;

    for(i = 0; i < prodtCadQtd; i++){
        if(strcmp(prodt[i].nome,nome) == 0){
            return 1;
        }
    }

    return 0;
}


//estrutura de um produto.
typedef struct
{

    int id;
    char nome[15];
    float preco;
    int quantidade;

}PRODUTO;



//imprime a interface do menu.
void menu(){

        printf("mercadinho do sidney!!\n\n");
        printf("1-Inserir um produto\n");
        printf("2-Buscar um produto\n");
        printf("3-\n");
        printf("4-\n");
        printf("5-\n");

}

/*Função que insere um produto no mercado(primeiro parametro passa a estrutura produto a ser preenchida e o segundo passa
 um ponteiro que contém o numero da posição do produto no vetor de estrutura).*/
PRODUTO inserirProduto(int *posicaoP)
{
    PRODUTO produto;

    printf("digite o id do produto que deseja registrar\n");
    scanf("%d",&produto.id);

    printf("digite o nome do produto que deseja registrar\n");
    scanf("%s",produto.nome);

    printf("digite o preco do produto que deseja registrar\n");
    scanf("%f",&produto.preco);

    printf("digite a quantidade do produto que deseja registrar\n");
    scanf("%d",&produto.quantidade);
    printf("\n");

    (*posicaoP)++;
    return produto;

}

//Função que busca um produto do mercado.

void buscarProduto(PRODUTO produtosptr[20],int *quantp){

PRODUTO comparadorS;

printf("Digite o id do produto que deseja buscar!\n");
scanf("%d",&comparadorS.id);
int cont = 0;
int i;

while(cont<(*quantp)){

if((produtosptr[cont]).id == comparadorS.id) {

    printf("Produto encontrado!!\n");
    printf("NOME: %s\n",(produtosptr[cont]).nome);
    printf("ID : %d\n",(produtosptr[cont]).id);
    printf("PRECO : %f\n",(produtosptr[cont]).preco);
    printf("QUANTIDADE : %d\n",(produtosptr[cont]).quantidade);

}
cont++;
}

}

int main (){


//------------------------[<CONSTANTES>]---------------------//

    int ADM_MAX = 3;      //MAXIMO DE FUNCIONARIOS TIPO ADMINISTRADOR
    int CAIXA_MAX = 10;    //MAXIMO DE FUNCIONARIOS TIPO CAIXA
    int PROD_MAX = 1000;  //MAXIMO DE PRODUTOS DO SUPERMERCADO

//-----------------------------------------------------------//

//inicializa variável que contém a posição do produto que será armazenado no vetor.

    int quantp = 0;//RETIRAR

    //DEFINICAO DOS CONTADORES (POSIÇÃO DE ARMAZENAMENTO NO VETOR).
    int admCadQtd = 0;
    int prodCadQtd = 0;
    int caixaCadQtd = 0;

//DECLARACAO DO VETORES ESTRUTURADOS.

    Administrador admt[ADM_MAX];
    Caixa cx[CAIXA_MAX];
    Produto prodt[PROD_MAX];

//Declaração da variavel que controla o menu.


    int key;

//DECLARACAO DOS ADMINISTRADORES.

    admt[0]=(Administrador){"Gabriel","1234"};
    admt[1]=(Administrador){"James","4321"};
    admt[2]=(Administrador){"Marco","2143"};

    admCadQtd = 2;

//DECLARACAO DOS FUNCCIONARIOS DO CAIXA.

    cx[0]=(Caixa){"Maria","caixa","maria","9876"};
    cx[1]=(Caixa){"Carlos","caixa","carlos","9876"};
    cx[2]=(Caixa){"Marcio","caixa","marcio","9876"};

    caixaCadQtd = 3;

//DECLARACAO DOS PRODUTOS 0 E 1 PARA TESTE DE FUNCIONAMENTO DO SUPERMERCADO.

    prodt[0] = {1,"coca-cola",3.5,4.5,50,{10,10,2020}};
    prodt[1] = {5,"chocolate",1.5,6.5,100,{20,10,2022}};

    prodCadQtd = 2;

//IMPRESSÃO DA TELA INICIAL.

    printf("#########################################################");
    printf("\n\n-------Welcome to BIG SIDNEY'S SUPERMARKET!------\n\n");
    printf("#########################################################");

    menuPrincipal();

    printf("#########################################################");
    printf("\n-------------Obrigado pela preferencia!------------!-\n");
    printf("\n'                                                   '\n");
    printf("#########################################################");


    return 0;

}



