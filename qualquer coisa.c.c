#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//-----------------[<ESTRUTURAS>]-----------------//

typedef struct
{

    char user[20];
    char senha[10];

}Administrador;

typedef struct
{

    char nome[50];
    char cargo[20];
    char user[20];
    char senha[10];

}Funcionario;


typedef struct
{

    int cod;//CÓDIGO DO PRODUTO;
    char nome[30];
    float precoCompra;
    float precoVenda;
    int quantidade;
    int dia;
    int mes;
    int ano;

}Produto;


typedef struct
{

    int totalCodigo;//SOMA DA QUANTIDAE DE TODOS OS PRODUTOS DE MESMO CÓDIGO;
    float totalProdutos;//SOMA DOS VALORES DE TODOS OS PRODUTOS;

}Compra;

//-------------------------------[<DECLARAÇÃO DAS FUNÇÕES & PROCEDIMENTOS>]----------------------------------//

//-------------------------------[<FUNÇÕES & PROCEDIMENTOS: MENU PRINCIPAL>]---------------------------------//

void menuPrincipal(Administrador admt[],Funcionario func[],Produto prodt[],char login[],int *acq,int *fcq,int *pcq,int *amax,int *fmax,int *pmax);

//-------------------------------[<FUNÇÕES & PROCEDIMENTOS: ADMINISTRADOR>]----------------------------------//

void loginAdministrador (Administrador admt[],Funcionario func[],Produto prodt[],char login[],int *acq,int *fcq,int *pcq,int *amax,int *fmax,int *pmax);
void menuAdministrador (Administrador admt[],Funcionario func[],Produto prodt[],char login[],int *acq,int *fcq,int *pcq,int *amax,int *fmax,int *pmax);
void imprimirProduto (Produto prodt[],int *pcq);
void imprimirAdministrador (Administrador admt[],int *acq);
void cadProduto(Produto prodt[],int *pcq,int *pmax);
void meetProduto(Produto prodt[],int *pcq,int *pmax);
int checkLoginAdministrador(Administrador admt[],char login[],char senha[],int *amax);

//------------------------------------[<FUNÇÕES & PROCEDIMENTOS:CAIXA>]--------------------------------------//




//--------------------------------------[<PROCEDIMENTO MENU PRINCIPAL>]--------------------------------------//

    //EXIBE O MENU PRINCIPAL.

    void menuPrincipal(Administrador admt[],Funcionario func[],Produto prodt[],char login[],int *acq,int *fcq,int *pcq,int *amax,int *fmax,int *pmax)
    {

        int option;

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

        do
        {
            switch(option)
            {

            case 1:
                loginAdministrador(admt,func,prodt,login,acq,fcq,pcq,amax,fmax,pmax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;

            default:
                printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");

            }
        }
        while(option != 0);
    }

//---------------------------------------[<PROCEDIMENTOS: ADMINISTRADOR>]-------------------------------------//

    //REALIZA O LOGIN DO ADMINISTRADOR.

    void loginAdministrador(Administrador admt[],Funcionario func[],Produto prodt[],char login[],int *acq,int *fcq,int *pcq,int *amax,int *fmax,int *pmax)
    {

    char senha[10];
    int i;

    system("cls");
    printf("--------------------------------[<LOGIN ADMINISTRADOR>]----------------------------------");

    //SOLICITA E RECEBE A SENHA.
    printf("\n\nDigite a sua senha:\n\n");
    fflush(stdin);
    scanf("%s",senha);


    //IMPLEMENTAÇÃO DO LAÇO PARA CONCESSÃO (OU NEGAÇAO) DE PERMISSÃO PARA ACESSAR O MENU ADMINISTRADOR.
    for(i = 0; i < *acq; i++)
    {

        //VERIFICA A EXISTENCIA DO LOGIN E SENHAS INFORMADOS NO VETOR DE ESTRUTURA ADMINISTRADOR.
        if((strcmp((admt[i]).user,login) == 0) && (strcmp((admt[i]).senha,senha) == 0))
        {

            menuAdministrador(admt,func,prodt,login,acq,fcq,pcq,amax,fmax,pmax);

        }
        else
        {

            printf("\n\n\nLogin ou senha incorretos, ou a conta de administrador inexistente.\n\n");

            printf("\n\nLogin incorreto: %s",login);
            printf("\n\nSenha incorreta: %s",senha);
            printf("\n\nContador: %d",*acq);

            printf("\n\n");

            system("pause");

            loginAdministrador(admt,func,prodt,login,acq,fcq,pcq,amax,fmax,pmax);
        }

    }

}

    //VERIFICA O LOGIN DO ADMINISTRADOR.
    int checkLoginAdministrador(Administrador admt[],char login[],char senha[],int *amax)
    {

        int i;

        admt[0]=(Administrador)
        {"Gabriel","1234"
        };
        admt[1]=(Administrador)
        {"James","4321"
        };
        admt[2]=(Administrador)
        {"Marco","2143"
        };

        printf("\n\nLogin incorreto: %s",login);
        printf("\n\nSenha incorreta: %s",senha);

        for(i = 0; i < *amax; i++){

            printf("FOR OK\n");

            if((strcmp((admt[i]).user,login) == 0) && (strcmp((admt[i]).senha,senha) == 0))
            {
                printf("1.ok");
                printf("\n\nLogin incorreto: %s",login);
                printf("\n\nSenha incorreta: %s",senha);

                return 1;


            }
        }

    return 0;

}



    //EXIBE O MENU DO ADMINISTRADOR.

    void menuAdministrador(Administrador admt[],Funcionario func[],Produto prodt[],char login[],int *acq,int *fcq,int *pcq,int *amax,int *fmax,int *pmax)
    {

        int option =  0;

        system("cls");

        printf("\n");

        system("cls");

        printf("\n\n");

        printf("Welcome, %s!",login);

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
        printf("'Para IMPRIMIR todos os ADMINISTRADORES: DIGITE [<6>].           '\n");
        printf("'                                                                '\n");
        printf("'Para IMPRIMIR todos os FUNCIONARIOS: DIGITE [<7>].              '\n");
        printf("'                                                                '\n");
        printf("'Para ATUALIZAR os DADOS de PRODUTOS ARMAZENADOS: DIGITE [<8>].  '\n");
        printf("'                                                                '\n");
        printf("'Para EXCLUIR os DADOS de PRODUTOS CADASTRADOS: DIGITE [<9>].    '\n");
        printf("'                                                                '\n");
        printf("'Para SAIR do MENU ADMINISTRADOR: DIGITE [<0>].                  '\n");
        printf("'                                                                '\n");
        printf("'----------------------------------------------------------------'\n");

        printf("\n\n");

        scanf("%d",&option);

        switch(option)
        {

        case 1:
            cadProduto(prodt,pcq,pmax);
            break;

        case 4:
            meetProduto(prodt,pcq,pmax);
            break;

        case 5:
            //impressProduto(prodt,*pcq);
            break;

        case 6:
            //atualProduto(prodt,*pcq);
            break;

        case 7:
            //excProduto(prodt,*pcq);
            break;

        case 0:
            //menuPrincipal(admt,cx,prodt,login,acq,fcq,pcq);
            break;

        default:
            system("cls");
            printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
            break;
        }
    }


    void imprimirAdministrador (Administrador admt[],int *acq)
    {
        int i;

        for(i = 0; i < *acq; i++){

             printf("\nLogin = %s", admt[i].user);
             printf("\nSenha: %s", admt[i].senha);

             printf("\n\n");

        }

    }


    //IMPRIME OS PRODUTOS CADASTRADOS.
    void imprimirProduto (Produto prodt[],int *pcq)
    {

    int i;

    for(i = 0; i < *pcq; i++){

         printf("\nCodigo = %d", prodt[i].cod);
         printf("\nNome: %s", prodt[i].nome);
         printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
         printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
         printf("\nQuantidade: %d", prodt[i].quantidade);
         printf("\nDia da validade: %d", prodt[i].dia);
         printf("\nMes da validade: %d", prodt[i].mes);
         printf("\nAno da validade: %d", prodt[i].ano);

         printf("\n\n");

        }

    }

    //CADASTRA UM NOVO PRODUTO.

    void cadProduto(Produto prodt[],int *pcq, int *pmax)
    {

        Produto prodtemp;
        int i;

        printf("\n\n--------------[<CADASTRO DE PRODUTO>]-------------------\n\n");

        //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
        printf("\n\nDigite um codigo para o produto: \n\n");
        fflush(stdin);
        scanf("%d",&prodtemp.cod);


        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        for(i = 0; i < *pmax; i++)
        {

            if((prodt[i]).cod == prodtemp.cod)
            {

                printf("\n\nCodigo de produto já cadastrado, por favor insira outro:\n\n");
                fflush(stdin);
                scanf("%d",&prodtemp.cod);


            }
        }

        fflush(stdin);

        //SOLICITAÇAO E LEITURA DO NOME DO PRODUTO.
        printf("\n\nDigite um nome para o produto: \n\n");
        fflush(stdin);
        scanf("%s",prodtemp.nome);


        //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
        for(i = 0; i < 100; i++)
        {

            if(strcmp((prodt[i]).nome,prodtemp.nome) == 0)
            {

                printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
                fflush(stdin);
                scanf("%s",prodtemp.nome);



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
        scanf("%d",&prodtemp.dia);

        //SOLICITAÇÃO E LEITURA DO MES DA VALIDADE DO PRODUTO.
        printf("\n\nDigite o mes da validade do produto: \n\n");
        scanf("%d",&prodtemp.mes);

        //SOLICITAÇÃO E LEITURA DO ANO DA VALIDADE DO PRODUTO.
        printf("\n\nDigite o ano da validade do produto: \n\n");
        scanf("%d",&prodtemp.ano);

        //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
        printf("\nCodigo: %d",prodtemp.cod);
        printf("\nNome: %s",prodtemp.nome);
        printf("\nPreco de Compra: %.2f",prodtemp.precoCompra);
        printf("\nPreco de Venda: %.2f",prodtemp.precoVenda);
        printf("\nQuantidade de produto armazenada: %d",prodtemp.quantidade);
        printf("\nData de validade do produto: %d/%d/%d\n",prodtemp.dia, prodtemp.mes, prodtemp.ano);

        (*pcq)++;

        printf("Quantidade de produtos diversos: %d",*pcq);

        prodt[*pcq] = prodtemp;

        printf("\n\nProduto cadastrado com sucesso.");

    }

    //ENCONTRA AS INFORMAÇÕES DE UM DETERMINADO PRODUTO.
    void meetProduto(Produto prodt[], int *pcq, int *pmax)
    {

        Produto prodtemp;
        int i = 0, option = 0;

        printf("\n\n----------[<BIG SIDNEY'S SUPERMARKET>]-----------\n\n");
        printf("\n'                                                   '\n");
        printf("\n'Para procura pelo CODIGO: DIGITE [<1>].            '\n");
        printf("\n'                                                   '\n");
        printf("\n'Para procura pelo NOME: DIGITE [<2>].              '\n");
        printf("\n'                                                   '\n");
        printf("\n'Para SAIR: DIGITE [<0>].                           '\n");
        printf("\n\n------------------------------------------------'\n\n");

        scanf("%d",&option);

        switch (option)
        {

        case 1:
            printf("\n\nDigite o codigo do produto:\n\n");
            scanf("%d",&prodtemp.cod);

                for(i = 0; i < *pcq; i++){

                    if(((prodt[i]).cod) == prodtemp.cod)
                    {

                        printf("\n\n-------------[<INFORMACOES DO PRODUTO>]------------------\n\n");

                        //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                        printf("\nCodigo: %d",prodt[i].cod);
                        printf("\nNome: %s",prodt[i].nome);
                        printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
                        printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
                        printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
                        printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].dia, prodt[i].mes, prodt[i].ano);

                    }

                }

            break;

        case 2:

            printf("\n\nDigite o nome do produto:\n\n");
            fflush(stdin);
            fgets(prodtemp.nome,10,stdin);



                    for(i = 0; i <*pcq; i++)
                    {

                        if(strcmp((prodt[i].nome),prodtemp.nome) == 0 )
                        {

                            printf("\n\n-------------[<INFORMAÇÕES DO PRODUTO>]------------------\n\n");

                            //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                            printf("\nCodigo: %d",prodt[i].cod);
                            printf("\nNome: %s",prodt[i].nome);
                            printf("\nPreco de Compra: %.2f",prodt[i].precoCompra);
                            printf("\nPreco de Venda: %.2f",prodt[i].precoVenda);
                            printf("\nQuantidade de produto armazenada: %d",prodt[i].quantidade);
                            printf("\nData de validade do produto: %d/%d/%d\n",prodt[i].dia, prodt[i].mes, prodt[i].ano);

                        }
                }
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");

    }

    }


int main()
    {
        char login[20], senha[10];


        printf("\nDigite o login: \n\n");
        fflush(stdin);
        scanf("%s",login);

        printf("\nDigite a senha: \n\n");
        fflush(stdin);
        scanf("%s",senha);

        //------------------------[<CONTADORES>]---------------------//

        //DEFINICAO DOS CONTADORES (POSIÇÃO DE ARMAZENAMENTO NO VETOR).
        int admtCadQtd = 0;
        int prodtCadQtd = 0;
        int funcCadQtd = 0;

        //------------------------[<CONSTANTES>]---------------------//

        int ADM_MAX = 3;      //MAXIMO DE FUNCIONARIOS TIPO ADMINISTRADOR
        int FUNC_MAX = 10;    //MAXIMO DE FUNCIONARIOS TIPO CAIXA
        int PROD_MAX = 100;   //MAXIMO DE PRODUTOS DO SUPERMERCADO

        //-----------------------------------------------------------//


        //------------------------[<VETORES>]-----------------------//


        //DECLARACAO DO VETORES ESTRUTURADOS.

        Administrador admt[ADM_MAX];
        Funcionario func[FUNC_MAX];
        Produto prodt[PROD_MAX];


        //-----------------------------------------------------------//

        //DECLARACAO DOS ADMINISTRADORES PARA TESTE DE FUNCIONAMENTO.

        admt[0]=(Administrador)
        {"Gabriel","1234"
        };
        admt[1]=(Administrador)
        {"James","4321"
        };
        admt[2]=(Administrador)
        {"Marco","2143"
        };

        admtCadQtd = 3;

        //DECLARACAO DOS PRODUTOS 1 E 2 PARA TESTE DE FUNCIONAMENTO.
        prodt[0] = (Produto)
        {
            0,"coca-cola",0.8,1.5,30,25,3,2021
        };
        prodt[1] = (Produto)
        {
            1,"chocolate",0.5,1.0,25,12,5,2020
        };

        prodtCadQtd = 2;

        //DECLARACAO DOS FUNCIONARIOS 1 E 2 PARA TESTE DE FUNCIONAMENTO.

        func[0] = (Funcionario)
        {"Jose","Caixa","jose123xx","xxjose123"
        };
        func[1] = (Funcionario)
        {"Sidney","Proprietario","sisi456","sisisi654"
        };

        funcCadQtd = 2;

        menuPrincipal(admt,func,prodt,login,&admtCadQtd,&funcCadQtd,&prodtCadQtd,&ADM_MAX,&FUNC_MAX,&PROD_MAX);
        //imprimirAdministrador (admt,&admtCadQtd);
        //imprimirProduto (prodt,&prodtCadQtd)
        //menuAdministrador(admt,func,prodt,login,&admtCadQtd,&funcCadQtd,&prodtCadQtd,&ADM_MAX,&FUNC_MAX,&PROD_MAX);
        //checkLoginAdministrador(admt,login,senha,&ADM_MAX);

        return 0;

    }

