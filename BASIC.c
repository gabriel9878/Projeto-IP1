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

void menuPrincipal(Administrador admt[3],Produto prodt[100],Caixa cx[4],int *acq,int *ccq,int *pcq){//MOSTRA O MENU PRINCIPAL;

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
            loginAdministrador(admt,int *acq);
            break;

        case 1:
            loginCaixa(cx,int *ccq);
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");

    }
}

//--------------[<ADMINISTRADOR: FUNÇÕES & PROCEDIMENTOS>]--------------//

//LISTA DE FUNÇÕES EM ANDAMENTO:

//cadProduto(prodt,&prodCadQtd);
//meetProduto(prodt,&prodCadQtd);
//menuPrincipal()


void loginAdministrador(Administrador admt[3],int *acq){//REALIZA O LOGIN O ADMINISTRADOR.

    char login[20], senha[10];
    int i = 0;

    system("cls");
    printf("--------------[<LOGIN ADMINISTRADOR>]----------------");

    printf("\n\nDigite o seu login:\n\n");
    scanf("%s",&login);
    fflush(stdin);

    printf("\n\nDigite a sua senha:\n\n");
    scanf("%s",&senha);
    fflush(stdin);

    for(i = 0; i < *acq; i++){

        if((strcmp((admt[i]).user,login) == 0) && (strcmp((admt[i]).senha,senha) == 0)){ //Checa se existe dentro do array o login e a senha digitados pelo usuario.

            menuAdmininistrador(Produto prodt[100],&login,int *pcq);

        }else{

            printf("\n\n\nLogin ou senha incorretos, ou a conta de administrador informada nao existe.\n\n");

            system("pause");

            loginAdministrador(Administrador admt[3],int *acq);
       }

    return 0;
}


void menuAdministrador(Produto prodt[100],*lgn,int *pcq){//MOSTRA O MENU DO ADMINISTRADOR.

    int option =  0;

    system("cls");

    printf("\n");

    system("cls");

    printf("\n\n");

    printf("Welcome, %s!",*lgn);

    printf("\n\n");

    printf("'--------------------[<MENU ADMINISTRADOR>]----------------------'\n");
    printf("'                                                                '\n");
    printf("'Para CADASTRAR um novo ADMINSTRADOR: DIGITE [<1>].              '\n");
    printf("'                                                                '\n");
    printf("'Para CADASTRAR um novo FUNCIONARIO: DIGITE [<2>].               '\n");
    printf("'                                                                '\n");
    printf("'Para CADASTRAR um novo PRODUTO: DIGITE [<3>].                   '\n");
    printf("'                                                                '\n");
    printf("'Para PESQUISAR as INFORMACOES sobre um PRODUTO: DIGITE [<4>].   '\n");
    printf("'                                                                '\n");
    printf("'Para IMPRIMIR todos os PRODUTOS ARMAZENADOS: DIGITE [<5>].      '\n");
    printf("'                                                                '\n");
    printf("'Para ATUALIZAR os DADOS de PRODUTOS ARMAZENADOS: DIGITE [<6>].  '\n");
    printf("'                                                                '\n");
    printf("'Para EXCLUIR os DADOS de PRODUTOS CADASTRADOS: DIGITE [<7>].    '\n");
    printf("'                                                                '\n");
    printf("'Para SAIR do MENU ADMINISTRADOR: DIGITE [<0>].                  '\n");
    printf("'                                                                '\n");
    printf("'----------------------------------------------------------------'\n");

    printf("\n\n");

    scanf("%d",&option);

     switch(option){

        case 1:
            cadProduto(prodt,*pcq);
            break;

        case 2:
            meetProduto(prodt,*pcq);
            break;

        case 3:
            impressProduto(prodt,*pcq);
            break;

        case 4:
            atualProduto(prodt,*pcq);
            break;

        case 5:
            excProduto(prodt,*pcq);
            break;

        default:
            system("cls");
            printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
            menuPrincipal();
            break;
     }
}


//---------------[<CAIXA: FUNÇÕES & PROCEDIMENTOS>]---------------//




//--------------[<PRODUTO: FUNÇÕES & PROCEDIMENTOS>]--------------//

void excProduto(Produto prodt[100], int *pcq){//PERMITE A EXCLUSAO DAS INFORMAÇÕES DE PRODUTOS.

  Produto prodtemp;
  int i = 0, cod, option = 0, cont = 0;
  char nome[30];

  system("cls");

  printf("\n\n---------------[<EXCLUSÃO DE DADOS DO PRODUTO>]---------------\n\n");
  printf("'                                                                  '\n");
  printf("'Para EXCLUIR um PRODUTO pelo CODIGO: DIGITE [<1>].                '\n");
  printf("'                                                                  '\n");
  printf("'Para EXCLUIR um PRODUTO pelo NOME: DIGITE [<2>].                  '\n");
  printf("'                                                                  '\n");
  printf("'Para SAIR do MENU EXCLUIR: DIGITE [<0>].                          '\n");
  printf("'                                                                  '\n");
  printf("'------------------------------------------------------------------'\n");

  scanf("%d,&option");

  fflush(stdin);

  if(option == 1){

    printf("Digite o codigo do produto que deseja excluir:");
    scanf("%d",&prodtemp.cod);
    fflush(stdin);

    //VERIFICA A VALIDADE (EXISTENCIA DO CODIGO DO PRODUTO).
    for(i = 0; i < *pcq; i++){

        if((prodt[i]).cod != prodtemp.cod){

            cont++;
        }
    }
    if(cont == *pcq){

        printf("O codigo informado nao existe! Por favor, digite um codigo valido!");
        scanf("%d",&prodtemp.cod);
        fflush(stdin);

    }else{

        for(i = 0; i < *pcq; i++){

            if((prodt[i]).cod != prodtemp.cod){

                printf("\n\n[<Produto encontrado!>]\nn");

                printf("\n\nDados atuais do produto de codigo: %d\n\n", prodtemp.cod);

                printf("\nCodigo: %d",prodt[i].cod);
                printf("\nNome: %s",prodt[i].nome);
                printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].diaValidade, prodt[i].mesValidade, prodt[i].anoValidade);

                //REMOCAO DO PRODUTO.
                prodt[i].cod = 0;
                prodt[i].nome= "";
                prodt[i].precoCompra = 0;
                prodt[i].precoVenda = 0;
                prodt[i].quantidade = 0;
                prodt[i].diaValidade = 0;
                prodt[i].mesValidade = 0;
                prodt[i].anoValidade = 0;

                printf("\n\nProduto excluido com sucesso!\n\n);

                system("pause");

                fflush(stdin);
            }
        }
    }
  }

  if(option == 2){

    printf("Digite o nome do produto que deseja excluir:");
    fgets(prodtemp.nome,30,stdin);
    fflush(stdin);

    //VERIFICA A VALIDADE (EXISTENCIA DO NOME DO PRODUTO).
    for(i = 0; i < *pcq; i++){

        if((strcmp((prodt[i]).nome,prodtemp.nome) != 0){

            cont++;
        }
    }
    if(cont == *pcq){

        printf("O nome informado nao existe! Por favor, digite um nome valido!");
        scanf("%d",&prodtemp.cod);
        fflush(stdin);

    }else{

        for(i = 0; i < *pcq; i++){

            if((strcmp(prodt[i]).nome,prodtemp.nome) == 0){

                printf("\n\n[<Produto encontrado!>]\nn");

                printf("\n\nDados atuais do produto de codigo: %s\n\n", prodtemp.nome);

                printf("\nCodigo: %d",prodt[i].cod);
                printf("\nNome: %s",prodt[i].nome);
                printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].diaValidade, prodt[i].mesValidade, prodt[i].anoValidade);

                //REMOCAO DO PRODUTO.
                prodt[i].cod = 0;
                prodt[i].nome= "";
                prodt[i].precoCompra = 0;
                prodt[i].precoVenda = 0;
                prodt[i].quantidade = 0;
                prodt[i].diaValidade = 0;
                prodt[i].mesValidade = 0;
                prodt[i].anoValidade = 0;

                printf("\n\nProduto excluido com sucesso!\n\n);

                system("pause");

                fflush(stdin);
            }
        }
    }
  }
}


void atualProduto(Produto prodt[100], int *pcq){//PERMITE A ATUALIZAÇÃO DAS INFORMAÇÕES DOS PRODUTOS.

  Produto prodtemp;
  int i = 0, cod, option = 0, cont = 0;
  char nome[30];

  system("cls");


  printf("\n\n---------------[<ATUALIZAR DADOS DO PRODUTO>]---------------\n\n");
  printf("'                                                                '\n");
  printf("'Para ATUALIZAR um PRODUTO pelo CODIGO: DIGITE [<1>].            '\n");
  printf("'                                                                '\n");
  printf("'Para ATUALIZAR um PRODUTO pelo NOME: DIGITE [<2>].              '\n");
  printf("'                                                                '\n");
  printf("'Para SAIR do MENU ATUALIZAR: DIGITE [<0>].                      '\n");
  printf("'                                                                '\n");
  printf("'----------------------------------------------------------------'\n");

  scanf("%d,&option");

  fflush(stdin);

  if(option == 1){

    printf("Digite o codigo do produto que deseja atualizar:");
    scanf("%d",&prodtemp.cod);
    fflush(stdin);

    //VERIFICA A VALIDADE (EXISTENCIA DO CODIGO DO PRODUTO).
    for(i = 0; i < *pcq; i++){

        if((prodt[i]).cod != prodtemp.cod){

            cont++;
        }
    }
    if(cont == *pcq){

        printf("O codigo informado nao existe! Por favor, digite um codigo valido!");
        scanf("%d",&prodtemp.cod);
        fflush(stdin);

    }else{

        for(i = 0; i < *pcq; i++){

            if((prodt[i]).cod != prodtemp.cod){

                printf("\n\n[<Produto encontrado!>]\nn");

                printf("\n\nDados atuais do produto de codigo: %d\n\n", prodtemp.cod);

                printf("\nCodigo: %d",prodt[i].cod);
                printf("\nNome: %s",prodt[i].nome);
                printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].diaValidade, prodt[i].mesValidade, prodt[i].anoValidade);

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
                fflush(stdin);

                //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
                for(i = 0; i < 100; i++){

                    if(strcmp((prodt[i]).nome,prodtemp.nome) == 0){

                        printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
                        fgets(prodtemp.nome,30,stdin);
                        fflush(stdin);

                    }
                }

                //SOLICITAÇÃO E LEITURA DO PRECO DE COMPRA DO PRODUTO.
                printf("\n\nDigite o preco de compra para o produto: \n\n");
                scanf("%f",&prodtemp.precoCompra);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO PRECO DE VENDA DO PRODUTO.
                printf("\n\nDigite o preco de venda para o produto: \n\n");
                scanf("%f",&prodtemp.precoVenda);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DA QUANTIDADE ARMAZENADA DO PRODUTO.
                printf("\n\nDigite a quantidade do produto: \n\n");
                scanf("%d",&prodtemp.quantidade);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO DIA DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o dia da validade do produto: \n\n");
                scanf("%d",&prodtemp.diaValidade);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO MES DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o mes da validade do produto: \n\n");
                scanf("%d",&prodtemp.mesValidade);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO ANO DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o ano da validade do produto: \n\n");
                scanf("%d",&prodtemp.anoValidade);
                fflush(stdin);

                //IMPRESSÃO DOS DADOS DO PRODUTO ATUALIZADO.
                printf("\nOs dados do produto foram atualizados!\n");

                printf("\nCodigo: %d",prodtemp.cod);
                printf("\nNome: %s",prodtemp.nome);
                printf("\nPreco de Compra: %.2f",prodtemp.precoCompra);
                printf("\nPreco de Venda: %.2f",prodtemp.precoVenda);
                printf("\nQuantidade de produto armazenada: %d",prodtemp.quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n",prodtemp.diaValidade, prodtemp.mesValidade, prodtemp.anoValidade);

                printf("\n\nInformacoes atualizadas com sucesso.\n\n");

                system("pause");

                fflush(stdin);
            }
        }
    }
  }

  if(option == 2){

    printf("Digite o nome do produto que deseja atualizar:");
    fgets(nome,30,stdin);
    fflush(stdin);

    //VERIFICA A VALIDADE (EXISTENCIA DO NOME DO PRODUTO).
    for(i = 0; i < *pcq; i++){

        if((strcmp((prodt[i]).nome,prodtemp.nome) != 0){

            cont++;
        }
    }
    if(cont == *pcq){

        printf("O nome informado nao existe! Por favor, digite um nome valido!");
        scanf("%d",&prodtemp.cod);
        fflush(stdin);

    }else{

        for(i = 0; i < *pcq; i++){

            if((strcmp(prodt[i]).nome,prodtemp.nome) == 0){

                printf("\n\n[<Produto encontrado!>]\nn");

                printf("\n\nDados atuais do produto de codigo: %s\n\n", prodtemp.nome);

                printf("\nCodigo: %d",prodt[i].cod);
                printf("\nNome: %s",prodt[i].nome);
                printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].diaValidade, prodt[i].mesValidade, prodt[i].anoValidade);

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
                fflush(stdin);

                //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
                for(i = 0; i < 100; i++){

                    if(strcmp((prodt[i]).nome,prodtemp.nome) == 0){

                        printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
                        fgets(prodtemp.nome,30,stdin);
                        fflush(stdin);

                    }
                }

                //SOLICITAÇÃO E LEITURA DO PRECO DE COMPRA DO PRODUTO.
                printf("\n\nDigite o preco de compra para o produto: \n\n");
                scanf("%f",&prodtemp.precoCompra);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO PRECO DE VENDA DO PRODUTO.
                printf("\n\nDigite o preco de venda para o produto: \n\n");
                scanf("%f",&prodtemp.precoVenda);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DA QUANTIDADE ARMAZENADA DO PRODUTO.
                printf("\n\nDigite a quantidade do produto: \n\n");
                scanf("%d",&prodtemp.quantidade);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO DIA DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o dia da validade do produto: \n\n");
                scanf("%d",&prodtemp.diaValidade);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO MES DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o mes da validade do produto: \n\n");
                scanf("%d",&prodtemp.mesValidade);
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO ANO DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o ano da validade do produto: \n\n");
                scanf("%d",&prodtemp.anoValidade);
                fflush(stdin);

                //IMPRESSÃO DOS DADOS DO PRODUTO ATUALIZADO.
                printf("\nOs dados do produto foram atualizados!\n");

                printf("\nCodigo: %d",prodtemp.cod);
                printf("\nNome: %s",prodtemp.nome);
                printf("\nPreco de Compra: %.2f",prodtemp.precoCompra);
                printf("\nPreco de Venda: %.2f",prodtemp.precoVenda);
                printf("\nQuantidade de produto armazenada: %d",prodtemp.quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n",prodtemp.diaValidade, prodtemp.mesValidade, prodtemp.anoValidade);

                printf("\n\nInformacoes atualizadas com sucesso.\n\n");

                system("pause");

                fflush(stdin);
            }
        }
    }
  }
}


void impressProduto(Produto prodt[100], int *pcq){//IMPRIME AS INFORMAÇÕES DE TODOS OS PRODUTOS.

  Produto prodtemp;
  int i = 0, cont = 0, option = 0, pag = 1;

  system("cls");

  printf("\n\n----------[<PRODUTOS ARMAZENADOS>]-----------\n\n");

  for(i = 0; i < *pcq; i++){

    if((prodt[i]).quantidade > 0){

        printf("\nCodigo: %d",prodt[i].cod);
        printf("\nNome: %s",prodt[i].nome);
        printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
        printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
        printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
        printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].diaValidade, prodt[i].mesValidade, prodt[i].anoValidade);

        cont++;
    }

          if(cont == 10){

            printf("\n\nPagina [%d]\n",pag);
            printf("\n\nDigite 1 para proxima página ou 0 para sair.");
            scanf("%d",&option);

            if(option == 0){

                break;
            }

            cont = 0;
            pag++;
            system("pause");
            system("cls");
          }
  }
  system("pause");
}

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

    //DECLARACAO DOS ADMINISTRADORES.

    admt[0]=(Administrador){"Gabriel","1234"};
    admt[1]=(Administrador){"James","4321"};
    admt[2]=(Administrador){"Marco","2143"};

    admCadQtd = 3;

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

    menuPrincipal(admt,prodt,cx,&admCadQtd,&cxCadQtd,&prodtCadQtd);

    return 0;

}
