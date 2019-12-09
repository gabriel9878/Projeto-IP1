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
    char user[20];
    char senha[10];
    int cpf;

}Socio;


typedef struct
{

    char nome[50];
    int matricula;
    char cargo[20];
    char user[20];
    char senha[10];
    int dia;
    int mes;
    int ano;

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
    int codProduto;
    float quantProduto;//SOMA DA QUANTIDADE DE TODOS OS PRODUTOS DE MESMO CÓDIGO;
    float valorTotal;//SOMA DOS VALORES DE TODOS OS PRODUTOS;

}Compra;


//-------------------------------[<DECLARAÇÃO DAS FUNÇÕES & PROCEDIMENTOS>]----------------------------------//

//-------------[<MENU PRINCIPAL, PROCEDIMENTO DE INICIALIZAÇÃO E DE REMOÇÃO DE QUEBRA DE LINHA>]-------------//

    void removeQuebraLinha(char *string);
    void init (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], int *admtCadQtd,  int *compCadQtd, int *funcCadQtd, int *prodtCadQtd, int *socioCadQtd);
    void menuPrincipal (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);


//---------------------------------------[<FUNÇÕES & PROCEDIMENTOS>]-----------------------------------------//

    //Administrador:


    int checkLoginAdministrador (Administrador admt[], char login[], char senha[], int *acq);
    void cadAdministrador (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void impressAdministrador (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void loginAdministrador (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void menuAdministrador (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);


    //Funcionário:


    int checkLoginFuncionario (Funcionario func[], char login[], char senha[], int *fcq);
    void cadFuncionario (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void impressFuncionario (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void loginFuncionario (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void menuFuncionario (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);


    //Produto:

    int checkCodProduto (Produto prodt[], int *pcq, int *pc);
    int checkMatFuncionario (Funcionario func[], int *fcq, int *mat);
    int checkMeetCodProduto (Produto prodt[], int *pcq, int *pc);
    int checkMeetCodProdutoAt (Produto prodt[], int *pcq, int *pc);
    int checkMeetCodProdutoDel (Produto prodt[], int *pcq, int *pc);
    int checkMeetNomeProduto (Produto prodt[], int *pcq, char pn[]);
    int checkMeetNomeProdutoAt (Produto prodt[], int *pcq, char pn[]);
    int checkMeetNomeProdutoDel (Produto prodt[], int *pcq, char pn[]);
    int checkMeetParteNomeProduto (Produto prodt[], int *pcq, char ppn[]);
    int checkNomeProduto (Produto prodt[], int *pcq, char nome[]);
    void addProdutoCar (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void atualProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void atualProdtCod (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void atualProdtNome (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void buyProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void cadProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void canBuyProdtuto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void excProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void excProdtCod (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void excProdtNome (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void impressProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void meetProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);


    //Sócio:

    int checkCpfSocio (Socio sc[], int *scq, int *cpf);
    int checkLoginSocio (Socio sc[], char login[], char senha[], int *scq);
    void cadSocio (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void impressSocio (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void meetSocio (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);
    void buySocio (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax);


//----------[<PROCEDIMENTO P/ REMOVE QUEBRA DE LINHA NO FINAL DA STRING>]------------//


    void removeQuebraLinha(char *string)
    {
        if(string != NULL && strlen(string) > 0)
        {
            short tamanho = strlen(string);

            if(string[tamanho-1] == '\n')
            {
                string[tamanho-1] = '\0';
            }
        }
    }


//----------[<PROCEDIMENTO P/ INTRODUÇÃO DOS VALORES INICIAIS PARA TESTE DO PROGRAMA>]------------//


     void init (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], int *admtCadQtd,  int *compCadQtd, int *funcCadQtd, int *prodtCadQtd, int *socioCadQtd)
    {

        //DECLARACAO DOS ADMINISTRADORES PARA TESTE DE FUNCIONAMENTO.
        admt[0] = (Administrador)
        {"Gabriel","1234"
        };
        admt[1] = (Administrador)
        {"James","4321"
        };
        admt[2] = (Administrador)
        {"Marco","2143"
        };

        *admtCadQtd = 3;

        //DECLARACAO DAS COMPRAS 1 E 2 PARA TESTE DE FUNCIONAMENTO.

        comp[0] = (Compra)
        {0,10,15
        };

        comp[1] = (Compra)
        {1,10,10
        };

        *compCadQtd = 2;

        //DECLARACAO DOS FUNCIONARIOS 1 E 2 PARA TESTE DE FUNCIONAMENTO.

        func[0] = (Funcionario)
        {"Jose",9856,"Caixa","jose123","jose123",02,05,2015
        };
        func[1] = (Funcionario)
        {"Sidney",7745,"Proprietario","sisi","456",15,12,2018
        };

        *funcCadQtd = 2;

        //DECLARACAO DOS PRODUTOS 1 E 2 PARA TESTE DE FUNCIONAMENTO.
        prodt[0] = (Produto)
        {
            0,"coca-cola",0.8,1.5,30,25,3,2021
        };
        prodt[1] = (Produto)
        {
            1,"chocolate",0.5,1.0,25,12,5,2020
        };

        *prodtCadQtd = 2;

        //DECLARACAO DOS SOCIOS 1 E 2 PARA TESTE DE FUNCIONAMENTO.

        sc[0] = (Socio)
        {"Alexandre","alx","6789",456985
        };
        sc[1] = (Socio)
        {"Karina","kar","9876",15122
        };

        *socioCadQtd = 2;
    }


//--------------------------------------[<PROCEDIMENTO MENU PRINCIPAL>]--------------------------------------//

    //EXIBE O MENU PRINCIPAL.
    void menuPrincipal (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option;

        printf("\n\n----------[<BIG SIDNEY'S SUPERMARKET>]-----------\n\n");
        printf("\n\n------------------[<WELCOME>]--------------------\n\n");
        printf("\n'                                                   '\n");
        printf("\n'Para logar-se como ADMINISTRADOR: DIGITE [<1>].    '\n");
        printf("\n'                                                   '\n");
        printf("\n'Para logar-se como FUNCIONARIO: DIGITE [<2>].      '\n");
        printf("\n'                                                   '\n");
        printf("\n'Para SAIR: DIGITE [<0>].                           '\n");
        printf("\n\n------------------------------------------------'\n\n");

        scanf("%d", &option);

        do
        {
            switch(option)
            {
            case 1:
                loginAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;
            case 2:
                loginFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
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


    //VERIFICA A EXISTENCIA DO LOGIN E SENHAS INFORMADOS NO VETOR DE ESTRUTURA ADMINISTRADOR.
    int checkLoginAdministrador (Administrador admt[], char login[], char senha[], int *acq)
    {
        int i;

        for(i = 0; i < *acq; i++)
        {
            if((strcmp((admt[i]).user,login) == 0) || (strcmp((admt[i]).senha,senha) == 0))
            {
                return 1;
            }
        }
    return 0;
    }


    void cadAdministrador (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        Administrador admtemp;
        int i = 0, option;

        while((i < *amax) & (option != 0))
        {
            printf("\nDigite o login:\n");
            fflush(stdin);
            fgets(admtemp.user,20,stdin);
            removeQuebraLinha(admtemp.user);

            printf("\nDigite a senha:\n");
            fflush(stdin);
            fgets(admtemp.senha,10,stdin);
            removeQuebraLinha(admtemp.senha);

            for(i = 0; i < *acq; i++)
            {
                if(checkLoginAdministrador (admt, admtemp.user, admtemp.senha, acq) == 1)
                {
                    printf("\n\nO login ou a senha informadas ja existem! Por favor, insira dados diferentes!\n\n");

                    cadAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                }
            }
            printf("\n\nAdministrador cadastrado com sucesso!\n\n");
            printf("\nLogin: %s\n", admtemp.user);
            printf("\nSenha: %s\n", admtemp.senha);

            admt[*acq] = admtemp;

            (*acq)++;

            printf("\nQuantidade de administradores cadastrados: %d\n", *acq);

            printf("\n\nDeseja cadastrar outro administrador?\n\n");

            printf("'---------------[<SUB MENU CADASTRO ADMINISTRADOR>]--------------'\n");
            printf("'                                                                '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
            printf("'                                                                '\n");
            printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<1>].                  '\n");
            printf("'                                                                '\n");
            printf("'SIM: DIGITE [<2>].                                              '\n");
            printf("'                                                                '\n");
            printf("'----------------------------------------------------------------'\n");

            scanf("%d", &option);

            switch(option)
            {
            case 1:
                menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 2:
                cadAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;

            default:
            system("cls");
            printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
            break;
            }
        }
    }


    //IMPRIME AS INFORMAÇÕES DOS ADMINISTRADORES CADASTRADOS.
    void impressAdministrador (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int i, option = 0;

        for(i = 0; i < *acq; i++)
        {
             printf("\nLogin: %s", admt[i].user);
             printf("\nSenha: %s", admt[i].senha);
             printf("\n\n");
        }

        system ("pause");

        do
        {
            printf("\n\nEscolha uma das opcoes abaixo:\n\n");

            printf("\n'-----------------[<SUB MENU LISTAGEM ADMINISTRADOR>]----------------'\n");
            printf("\n\n'                                                                '\n\n");
            printf("\n'RETORNAR AO MENU FUNCIONARIO: DIGITE [<1>].                         '\n");
            printf("\n'                                                                    '\n");
            printf("\n'RETORNAR AO MENU ADMINISTRADOR: DIGITE [<2>].                       '\n");
            printf("\n'                                                                    '\n");
            printf("\n'RETORNAR AO MENU PRINCIPAL: DIGITE [<3>].                           '\n");
            printf("\n'                                                                    '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                                  '\n");
            printf("\n'                                                                    '\n");
            printf("'\n--------------------------------------------------------------------'\n");

            scanf("%d", &option);

            switch(option)
            {
            case 1:
                menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 2:
                menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 3:
                menuPrincipal (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;
            }
        }
        while(option != 0);
    }


    //REALIZA O LOGIN DO ADMINISTRADOR.
    void loginAdministrador (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
    char senha[10];
    int i;

    system("cls");
    printf("--------------------------------[<LOGIN ADMINISTRADOR>]----------------------------------");

    //SOLICITA E RECEBE A SENHA.
    printf("\n\nDigite a sua senha:\n\n");
    fflush(stdin);
    fgets(senha,10,stdin);
    removeQuebraLinha(senha);

    //IMPLEMENTAÇÃO DO LAÇO PARA CONCESSÃO (OU NEGAÇAO) DE PERMISSÃO PARA ACESSAR O MENU ADMINISTRADOR.
    for(i = 0; i < *acq; i++)
    {
        //VERIFICA A EXISTENCIA DO LOGIN E SENHAS INFORMADOS NO VETOR DE ESTRUTURA ADMINISTRADOR.
        if(checkLoginAdministrador (admt, login, senha, acq) == 1)
        {
            menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
        }
        else
        {
            printf("\n\n\nLogin ou senha incorretos, ou a conta de administrador inexistente.\n\n");

            system("pause");

            printf("\n\nDigite o seu login:\n\n");
            fflush(stdin);
            fgets(login,20,stdin);
            removeQuebraLinha(login);

            loginAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
        }
    }
}


    //EXIBE O MENU DO ADMINISTRADOR.
    void menuAdministrador (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option =  0;

        system("cls");

        printf("\n");

        system("cls");

        printf("\n\n");

        printf("Welcome, %s!", login);

        printf("\n\n");

        printf("'--------------------[<MENU ADMINISTRADOR>]----------------------'\n");
        printf("'                                                                '\n");
        printf("'                                                                '\n");
        printf("'                                                                '\n");
        printf("'Para CADASTRAR um novo ADMINISTRADOR: DIGITE [<1>].             '\n");
        printf("'                                                                '\n");
        printf("'Para CADASTRAR um novo FUNCIONARIO: DIGITE [<2>].               '\n");
        printf("'                                                                '\n");
        printf("'Para CADASTRAR um novo PRODUTO: DIGITE [<3>].                   '\n");
        printf("'                                                                '\n");
        printf("'Para PESQUISAR as INFORMACOES sobre um PRODUTO: DIGITE [<4>].   '\n");
        printf("'                                                                '\n");
        printf("'Para IMPRIMIR todos os ADMINISTRADORES: DIGITE [<5>].           '\n");
        printf("'                                                                '\n");
        printf("'Para IMPRIMIR todos os FUNCIONARIOS: DIGITE [<6>].              '\n");
        printf("'                                                                '\n");
        printf("'Para IMPRIMIR todos os PRODUTOS ARMAZENADOS: DIGITE [<7>].      '\n");
        printf("'                                                                '\n");
        printf("'Para ATUALIZAR os DADOS de PRODUTOS ARMAZENADOS: DIGITE [<8>].  '\n");
        printf("'                                                                '\n");
        printf("'Para EXCLUIR os DADOS de PRODUTOS CADASTRADOS: DIGITE [<9>].    '\n");
        printf("'                                                                '\n");
        printf("'Para RETORNAR ao MENU PRINCIPAL: DIGITE [<0>].                  '\n");
        printf("'                                                                '\n");
        printf("'----------------------------------------------------------------'\n");

        printf("\n\n");

        scanf("%d", &option);

        system("cls");

        switch(option)
        {
        case 1:
            cadAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 2:
            cadFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 3:
            cadProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 4:
            meetProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 5:
            impressAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 6:
            impressFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 7:
            impressProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 8:
            atualProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 9:
            excProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 0:
            menuPrincipal (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
            break;
        }
    }


//---------------------------------------[<PROCEDIMENTOS: FUNCIONÁRIO>]-------------------------------------//




    //VERIFICA A VALIDADE DO LOGIN E SENHA DO FUNCIONARIO.
    int checkLoginFuncionario (Funcionario func[], char login[], char senha[], int *fcq)
    {
        int i;

        for(i = 0; i < *fcq; i++)
        {
            if((strcmp((func[i]).user,login) == 0) && (strcmp((func[i]).senha,senha) == 0))
            {
                return 1;
            }
        }
    return 0;
    }


    //VERIFICA A VALIDADE DA MATRÍCULA DO FUNCIONARIO.
    int checkMatFuncionario (Funcionario func[], int *fcq, int *mat)
    {
        int i = 0;

        for(i = 0; i < *fcq; i++)
        {
            if((func[i]).matricula == *mat)
            {
                return 1;
            }
        }
    return 0;
    }


    //CADASTRA UM NOVO FUNCIONARIO.
    void cadFuncionario (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        Funcionario functemp;
        int option;

        system("cls");



            printf("\n\n--------------[<CADASTRO DE FUNCIONARIO>]-------------------\n\n");

           //SOLICITAÇÃO E LEITURA DO NOME DO FUNCIONARIO.
            printf("\n\nDigite um nome para o funcionario: \n\n");
            fflush(stdin);
            fgets(functemp.nome,50,stdin);
            removeQuebraLinha(functemp.nome);

            //SOLICITAÇÃO E LEITURA DA MATRICULA DO FUNCIONARIO.
            printf("\n\nDigite uma matricula para o funcionario: \n\n");
            fflush(stdin);
            scanf("%d", &functemp.matricula);

            while(checkMatFuncionario (func, fcq, &functemp.matricula) == 1)
            {
                printf("\n\nMatricula de funcionario já cadastrada. Por favor, insira outra:\n\n");
                fflush(stdin);
                scanf("%d", &functemp.matricula);
            }

            //SOLICITAÇÃO E LEITURA DO CARGO DO FUNCIONARIO.
            printf("\n\nDigite um cargo para o funcionario: \n\n");
            fflush(stdin);
            fgets(functemp.cargo,20,stdin);
            removeQuebraLinha(functemp.cargo);

            //SOLICITAÇÃO E LEITURA DO LOGIN DO FUNCIONARIO.
            printf("\n\nDigite um login para o funcionario: \n\n");
            fflush(stdin);
            fgets(functemp.user,20,stdin);
            removeQuebraLinha(functemp.user);

            //SOLICITAÇÃO E LEITURA A SENHA DO FUNCIONARIO.
            printf("\n\nDigite uma senha para o funcionario: \n\n");
            fflush(stdin);
            fgets(functemp.senha,20,stdin);
            removeQuebraLinha(functemp.senha);

            //CHECAGEM DA VALIDADE DO LOGIN E SENHA DO FUNCIONARIO.
            while(checkLoginFuncionario (func, functemp.user, functemp.senha, fcq) == 1)
            {
                printf("\n\nO login e/ou a senha informados ja existem. Tente novamente.\n");

                //SOLICITAÇÃO E LEITURA DO LOGIN DO FUNCIONARIO.
                printf("\n\nDigite um login para o funcionario: \n\n");
                fflush(stdin);
                fgets(functemp.user,20,stdin);
                removeQuebraLinha(functemp.user);

                //SOLICITAÇÃO E LEITURA A SENHA DO FUNCIONARIO.
                printf("\n\nDigite uma senha para o funcionario: \n\n");
                fflush(stdin);
                fgets(functemp.senha,20,stdin);
                removeQuebraLinha(functemp.senha);
            }
            fflush(stdin);

            //SOLICITAÇÃO E LEITURA DO DIA DA VALIDADE DO PRODUTO.
            printf("\n\nDigite o dia da admissao do funcionario: \n\n");
            scanf("%d", &functemp.dia);

            //SOLICITAÇÃO E LEITURA DO MES DA VALIDADE DO PRODUTO.
            printf("\n\nDigite o mes da admissao do funcionario: \n\n");
            scanf("%d", &functemp.mes);

            //SOLICITAÇÃO E LEITURA DO ANO DA VALIDADE DO PRODUTO.
            printf("\n\nDigite o ano da admissao do funcionario: \n\n");
            scanf("%d", &functemp.ano);

            //IMPRESSÃO DOS DADOS DO FUNCIONARIO CADASTRADO.
            printf("\nNome: %s", functemp.nome);
            printf("\nMatricula: %d", functemp.matricula);
            printf("\nCargo %s", functemp.cargo);
            printf("\nLogin: %s", functemp.user);
            printf("\nSenha: %s", functemp.senha);
            printf("\nData de admissao do funcionario: %d/%d/%d\n", functemp.dia, functemp.mes, functemp.ano);

            func[*fcq] = functemp;

            printf("\n\nFuncionario cadastrado com sucesso.");

            (*fcq)++;

            printf("\n\nQuantidade de funcionarios cadastrados: %d", *fcq);

            do
            {
                printf("\n\nDeseja cadastrar outro funcionario?\n\n");

                printf("\n'-----------------[<SUB MENU CADASTRO FUNCIONARIO>]------------------'\n");
                printf("\n\n'                                                                '\n\n");
                printf("\n'SIM: DIGITE [<1>].                                                  '\n");
                printf("\n'                                                                    '\n");
                printf("\n'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                      '\n");
                printf("\n'                                                                    '\n");
                printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                                  '\n");
                printf("\n'                                                                    '\n");
                printf("'\n--------------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                case 1:
                    menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                    break;

                case 2:
                    cadFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                    break;

                case 0:
                    printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                    printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                    break;

                default:
                system("cls");
                printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
                break;
                }
            }
            while (option != 0);
    }


    //IMPRIME AS INFORMAÇÕES DOS FUNCIONARIOS CADASTRADOS.
    void impressFuncionario (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int i, option = 0;

        for(i = 0; i < *fcq; i++)
        {
             printf("\nNome: %s", func[i].nome);
             printf("\nMatricula: %d", func[i].matricula);
             printf("\nCargo = %s", func[i].cargo);
             printf("\nLogin: %s", func[i].user);
             printf("\nSenha: %s", func[i].senha);
             printf("\nData de admissao: %d/%d/%d", func[i].dia, func[i].mes, func[i].ano);

             printf("\n\n");
        }
        system ("pause");

        do
        {
            printf("\n\nEscolha uma das opcoes abaixo:\n\n");

            printf("\n'-----------------[<SUB MENU LISTAGEM FUNCIONARIO>]----------------'\n");
            printf("\n\n'                                                                '\n\n");
            printf("\n'RETORNAR AO MENU FUNCIONARIO: DIGITE [<1>].                         '\n");
            printf("\n'                                                                    '\n");
            printf("\n'RETORNAR AO MENU ADMINISTRADOR: DIGITE [<2>].                       '\n");
            printf("\n'                                                                    '\n");
            printf("\n'RETORNAR AO MENU PRINCIPAL: DIGITE [<3>].                           '\n");
            printf("\n'                                                                    '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                                  '\n");
            printf("\n'                                                                    '\n");
            printf("'\n--------------------------------------------------------------------'\n");

            scanf("%d", &option);

            switch(option)
            {
            case 1:
                menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 2:
                menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 3:
                menuPrincipal (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;
            }
        }
        while(option != 0);
    }


     void loginFuncionario (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        char senha[10];
        int i;

        system("cls");
        printf("--------------------------------[<LOGIN FUNCIONARIO>]----------------------------------");

        //SOLICITA E RECEBE A SENHA.
        printf("\n\nDigite a sua senha:\n\n");
        fflush(stdin);
        fgets(senha,10,stdin);
        removeQuebraLinha(senha);

        //IMPLEMENTAÇÃO DO LAÇO PARA CONCESSÃO (OU NEGAÇAO) DE PERMISSÃO PARA ACESSAR O MENU FUNCIONARIO.
        for(i = 0; i < *fcq; i++)
        {
            //VERIFICA A EXISTENCIA DO LOGIN E SENHAS INFORMADOS NO VETOR DE ESTRUTURA FUNCIONARIO.
            if(checkLoginFuncionario(func, login, senha, fcq) == 1)
            {
                menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            }
            else
            {
                printf("\n\n\nLogin ou senha incorretos, ou a conta de funcionario inexistente.\n\n");

                system("pause");

                printf("\n\nDigite o seu login:\n\n");
                fflush(stdin);
                fgets(login,20,stdin);
                removeQuebraLinha(login);

                loginFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            }
        }
    }


    //EXIBE O MENU FUNCIONARIO.
    void menuFuncionario (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option =  0;

        system("cls");

        printf("\n");

        system("cls");

        printf("\n\n");

        printf("Welcome, %s!", login);

        printf("\n\n");

        printf("'----------------------[<MENU FUNCIONARIO>]----------------------'\n");
        printf("'                                                                '\n");
        printf("'Para PESQUISAR as INFORMACOES sobre um PRODUTO: DIGITE [<1>].   '\n");
        printf("'                                                                '\n");
        printf("'Para IMPRIMIR todos os PRODUTOS ARMAZENADOS: DIGITE [<2>].      '\n");
        printf("'                                                                '\n");
        printf("'Para PESQUISAR as INFORMACOES sobre um SOCIO: DIGITE [<3>].     '\n");
        printf("'                                                                '\n");
        printf("'Para IMPRIMIR todos os SOCIOS CADASTRADOS: DIGITE [<4>].        '\n");
        printf("'                                                                '\n");
        printf("'Para CADASTRAR novos SOCIOS: DIGITE [<5>].                      '\n");
        printf("'                                                                '\n");
        printf("'Para COMPRAR PRODUTOS ARMAZENADOS: DIGITE [<6>].                '\n");
        printf("'                                                                '\n");
        printf("'Para IMPRIMIR LISTA DE PRODUTOS COMPRADOS: DIGITE [<7>].        '\n");
        printf("'                                                                '\n");
        printf("'Para RETORNAR ao MENU PRINCIPAL: DIGITE [<0>].                  '\n");
        printf("'                                                                '\n");
        printf("'----------------------------------------------------------------'\n");

        printf("\n\n");

        scanf("%d", &option);

        system("cls");

        switch(option)
        {
        case 1:
            meetProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 2:
            impressProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 3:
            meetSocio (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 4:
            impressSocio (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 5:
            cadSocio (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 6:
            buyProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;
        case 7:
            //listCompra (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 0:
            menuPrincipal (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        default:
            system("cls");
            printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
            break;
        }
    }


 //---------------------------------------[<PROCEDIMENTOS: SOCIO>]-------------------------------------//


    void cadSocio (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        Socio sctemp;
        int option = 0;

            printf("\n\n--------------[<CADASTRO DE SOCIO>]-------------------\n\n");

           //SOLICITAÇÃO E LEITURA DO NOME DO SOCIO.
            printf("\n\nDigite um nome para o socio: \n\n");
            fflush(stdin);
            fgets(sctemp.nome,50,stdin);
            removeQuebraLinha(sctemp.nome);

            //SOLICITAÇÃO E LEITURA DO LOGIN DO SOCIO.
            printf("\n\nDigite um login para o socio: \n\n");
            fflush(stdin);
            fgets(sctemp.user,20,stdin);
            removeQuebraLinha(sctemp.user);

            //SOLICITAÇÃO E LEITURA A SENHA DO SOCIO.
            printf("\n\nDigite uma senha para o socio: \n\n");
            fflush(stdin);
            fgets(sctemp.senha,10,stdin);
            removeQuebraLinha(sctemp.senha);

            //CHECAGEM DA VALIDADE DO LOGIN E SENHA DO SOCIO.
            while(checkLoginSocio (sc, sctemp.user, sctemp.senha, fcq) == 1)
            {
                printf("\n\nO login e/ou a senha informados ja existem. Tente novamente.\n");

                //SOLICITAÇÃO E LEITURA DO LOGIN DO SOCIO.
                printf("\n\nDigite um login para o socio: \n\n");
                fflush(stdin);
                fgets(sctemp.user,20,stdin);
                removeQuebraLinha(sctemp.user);

                //SOLICITAÇÃO E LEITURA A SENHA DO SOCIO.
                printf("\n\nDigite uma senha para o socio: \n\n");
                fflush(stdin);
                fgets(sctemp.senha,20,stdin);
                removeQuebraLinha(sctemp.senha);
            }
            fflush(stdin);

            //SOLICITAÇÃO E LEITURA DO CPF DO SOCIO.
            printf("\n\nDigite um CPF para o socio: \n\n");
            fflush(stdin);
            scanf("%d", &sctemp.cpf);

            while(checkCpfSocio (sc, scq, &sctemp.cpf) == 1)
            {
                printf("\n\nCPF de socio já cadastrado. Por favor, insira outro:\n\n");
                fflush(stdin);
                scanf("%d", &sctemp.cpf);
            }

            //IMPRESSÃO DOS DADOS DO SOCIO CADASTRADO.
            printf("\nNome: %s", sctemp.nome);
            printf("\nLogin: %s", sctemp.user);
            printf("\nSenha: %s", sctemp.senha);
            printf("\nCPF: %d", sctemp.cpf);

            sc[*scq] = sctemp;

            (*scq)++;

            printf("\n\nQuantidade de socios cadastrados: %d", *scq);

            printf("\n\nSocio cadastrado com sucesso.");

            do
            {
                printf("\n\nDeseja cadastrar outro socio?\n\n");

                printf("\n'-----------------[<SUB MENU CADASTRO SOCIO>]------------------'\n");
                printf("\n\n'                                                                '\n\n");
                printf("\n'SIM: DIGITE [<1>].                                                  '\n");
                printf("\n'                                                                    '\n");
                printf("\n'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                      '\n");
                printf("\n'                                                                    '\n");
                printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                                  '\n");
                printf("\n'                                                                    '\n");
                printf("'\n--------------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                case 1:
                    cadSocio (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                    break;

                case 2:
                    menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                    break;

                case 0:
                    printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                    printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                    break;
                }
            }
            while(option != 0);
    }

    //VERIFICA A VALIDADE DO CPF.
    int checkCpfSocio (Socio sc[], int *scq, int *cpf)
    {
        int i = 0;

        for(i = 0; i < *scq; i++)
        {
            if((sc[i]).cpf == *cpf)
            {
                return 1;
            }
        }
    return 0;
    }

    int checkLoginSocio (Socio sc[], char login[], char senha[], int *scq)
    {
        int i;

        for(i = 0; i < *scq; i++)
        {
            if((strcmp((sc[i]).user,login) == 0) && (strcmp((sc[i]).senha,senha) == 0))
            {
                return 1;
            }
        }
    return 0;
    }


    //IMPRIME OS SOCIOS CADASTRADOS.
    void impressSocio (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int i, option = 0, contador, pag = 1, esc = 0;

        for(i = 0; i < *scq; i++)
        {
             printf("\nNome: %s", sc[i].nome);
             printf("\nLogin: %s", sc[i].user);
             printf("\nSenha: %s", sc[i].senha);
             printf("\nCPF: %d", sc[i].cpf);

             printf("\n[<------------------------------------------->]\n");

             contador++;

             if(contador == 5)
            {
                printf("\n\nPagina [<%d>]\n", pag);
                printf("\n\nDigite 1 para pagina seguinte ou 0 para sair:");
                scanf("%d", &esc);
                if(esc == 0)
                {
                    break;
                }
                contador = 0;

                pag++;

                system("pause");
                system("cls");
            }
        }

        system ("pause");
        system("cls");

        do
        {
            printf("\n\nEscolha uma das opcoes abaixo:\n\n");

            printf("\n'-----------------[<SUB MENU LISTAGEM SOCIO>]----------------'\n");
            printf("\n\n'                                                                '\n\n");
            printf("\n'RETORNAR AO MENU FUNCIONARIO: DIGITE [<1>].                         '\n");
            printf("\n'                                                                    '\n");
            printf("\n'RETORNAR AO MENU ADMINISTRADOR: DIGITE [<2>].                       '\n");
            printf("\n'                                                                    '\n");
            printf("\n'RETORNAR AO MENU PRINCIPAL: DIGITE [<3>].                           '\n");
            printf("\n'                                                                    '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                                  '\n");
            printf("\n'                                                                    '\n");
            printf("'\n--------------------------------------------------------------------'\n");

            scanf("%d", &option);

            switch(option)
            {
            case 1:
                menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 2:
                menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 3:
                menuPrincipal (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;
            }
        }
        while(option != 0);
    }


    //ENCONTRA INFORMAÇÕES ACERCA DE UM DETERMINADO SOCIO.
    void meetSocio (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        Socio sctemp;
        int i = 0, option;

        //SOLICITAÇÃO E LEITURA DO CPF DO SOCIO.
        printf("\n\nDigite um CPF para o socio: \n\n");
        fflush(stdin);
        scanf("%d", &sctemp.cpf);

        //CHECAGEM DA VALIDADE DO CPF DO SOCIO.
        while (checkCpfSocio (sc, scq, &sctemp.cpf) != 1)
        {
            printf("\n\nCPF do socio nao cadastrado. Por favor, insira um cpf valido:\n\n");
            fflush(stdin);
            scanf("%d", &sctemp.cpf);
        }
        fflush(stdin);

        for(i = 0; i < *scq; i++)
        {
            if((sc[i]).cpf == sctemp.cpf)
            {
            //IMPRESSÃO DOS DADOS DO SOCIO CADASTRADO.
            printf("\n\n-------------[<INFORMACOES DO SOCIO>]------------------\n\n");

            //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
            printf("\nNome: %s", sc[i].nome);
            printf("\nLogin: %s", sc[i].user);
            printf("\nSenha: %s", sc[i].senha);
            printf("\nCPF: %d", sc[i].cpf);
            }
        }

        do
        {
            printf("\n\nDeseja procurar outro socio?\n\n");

            printf("'-----------------[<SUB MENU INFORMACAO SOCIO>]------------------'\n");
            printf("'                                                                '\n");
            printf("'SIM: DIGITE [<1>].                                              '\n");
            printf("'                                                                '\n");
            printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
            printf("'                                                                '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
            printf("'                                                                '\n");
            printf("'----------------------------------------------------------------'\n");

            scanf("%d", &option);

            switch(option)
            {
                case 1:
                    meetSocio (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                    break;

                case 2:
                    menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                    break;

                case 0:
                    printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                    printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                    break;

                default:
                    printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                    break;
            }
        }
        while(option != 0);
    }


    //---------------------------------------[<PROCEDIMENTOS: PRODUTO>]-------------------------------------//



    //VERIFICA SE O CODIGO DO PRODUTO ESTA CADASTRADO.
    int checkCodProduto (Produto prodt[], int *pcq, int *pc)
    {
        int i = 0;

        for(i = 0; i < *pcq; i++)
        {
            if((prodt[i]).cod == *pc)
            {
                return 1;
            }
        }
    return 0;
    }


    //int meetBuyProduto (prodt, pcq, pmax);


    int checkMeetCodProduto (Produto prodt[], int *pcq, int *pc)
    {
        int i = 0;

        for(i = 0; i < *pcq; i++)
        {
            if((prodt[i]).cod == *pc)
            {
                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                printf("\n\n-------------[<INFORMACOES DO PRODUTO>]------------------\n\n");

                printf("\nCodigo: %d", prodt[i].cod);
                printf("\nNome: %s", prodt[i].nome);
                printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);
            }
        }
    return 0;
    }


    int checkMeetCodProdutoAt (Produto prodt[], int *pcq, int *pc)
    {
        int i = 0;
        Produto prodtemp;

        for(i = 0; i < *pcq; i++)
        {
            if((prodt[i]).cod == *pc)
            {

            printf("\n\nRealize as alteraçoes desejadas.\n\n");

                //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
                printf("\n\nDigite um codigo para o produto: \n\n");
                fflush(stdin);
                scanf("%d", &prodtemp.cod);

                //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
                while (checkCodProduto (prodt, pcq, &prodtemp.cod) == 1)
                {
                    printf("\n\nCodigo do produto já cadastrado. Por favor, insira outro:\n\n");
                    fflush(stdin);
                    scanf("%d", &prodtemp.cod);
                }
                fflush(stdin);

                //SOLICITAÇAO E LEITURA DO NOME DO PRODUTO.
                printf("\n\nDigite um nome para o produto: \n\n");
                fflush(stdin);
                fgets(prodtemp.nome,30,stdin);
                removeQuebraLinha(prodtemp.nome);

                //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
                while (checkNomeProduto (prodt, pcq, prodtemp.nome) == 1)
                {
                    printf("\n\nNome do produto já cadastrado. Por favor, insira outro:\n\n");
                    fflush(stdin);
                    fgets(prodtemp.nome,30,stdin);
                    removeQuebraLinha(prodtemp.nome);
                }
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO PRECO DE COMPRA DO PRODUTO.
                printf("\n\nDigite o preco de compra para o produto: \n\n");
                scanf("%f", &prodtemp.precoCompra);

                //SOLICITAÇÃO E LEITURA DO PRECO DE VENDA DO PRODUTO.
                printf("\n\nDigite o preco de venda para o produto: \n\n");
                scanf("%f", &prodtemp.precoVenda);

                //SOLICITAÇÃO E LEITURA DA QUANTIDADE ARMAZENADA DO PRODUTO.
                printf("\n\nDigite a quantidade do produto: \n\n");
                scanf("%d", &prodtemp.quantidade);

                //SOLICITAÇÃO E LEITURA DO DIA DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o dia da validade do produto: \n\n");
                scanf("%d", &prodtemp.dia);

                //SOLICITAÇÃO E LEITURA DO MES DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o mes da validade do produto: \n\n");
                scanf("%d", &prodtemp.mes);

                //SOLICITAÇÃO E LEITURA DO ANO DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o ano da validade do produto: \n\n");
                scanf("%d", &prodtemp.ano);

                prodt[i] = prodtemp;

                //IMPRESSÃO DAS INFORMACOES DO PRODUTO ATUALIZADO.
                printf("\nCodigo: %d", prodt[i].cod);
                printf("\nNome: %s", prodt[i].nome);
                printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);

                printf("\n\nInformacoes atualizadas com sucesso!\n\n");
            }
        }
        return 0;
    }


    int checkMeetNomeProdutoAt (Produto prodt[], int *pcq, char pn[])
    {
        int i = 0;
        Produto prodtemp;

        for(i = 0; i < *pcq; i++)
        {
            if(strcmp((prodt[i]).nome, pn) == 0)
            {

            printf("\n\nRealize as alteraçoes desejadas.\n\n");

                //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
                printf("\n\nDigite um codigo para o produto: \n\n");
                fflush(stdin);
                scanf("%d", &prodtemp.cod);

                //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
                while (checkCodProduto (prodt, pcq, &prodtemp.cod) == 1)
                {
                    printf("\n\nCodigo do produto já cadastrado. Por favor, insira outro:\n\n");
                    fflush(stdin);
                    scanf("%d", &prodtemp.cod);
                }
                fflush(stdin);

                //SOLICITAÇAO E LEITURA DO NOME DO PRODUTO.
                printf("\n\nDigite um nome para o produto: \n\n");
                fflush(stdin);
                fgets(prodtemp.nome,30,stdin);
                removeQuebraLinha(prodtemp.nome);

                //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
                while (checkNomeProduto (prodt, pcq, prodtemp.nome) == 1)
                {
                    printf("\n\nNome do produto já cadastrado. Por favor, insira outro:\n\n");
                    fflush(stdin);
                    fgets(prodtemp.nome,30,stdin);
                    removeQuebraLinha(prodtemp.nome);
                }
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO PRECO DE COMPRA DO PRODUTO.
                printf("\n\nDigite o preco de compra para o produto: \n\n");
                scanf("%f", &prodtemp.precoCompra);

                //SOLICITAÇÃO E LEITURA DO PRECO DE VENDA DO PRODUTO.
                printf("\n\nDigite o preco de venda para o produto: \n\n");
                scanf("%f", &prodtemp.precoVenda);

                //SOLICITAÇÃO E LEITURA DA QUANTIDADE ARMAZENADA DO PRODUTO.
                printf("\n\nDigite a quantidade do produto: \n\n");
                scanf("%d", &prodtemp.quantidade);

                //SOLICITAÇÃO E LEITURA DO DIA DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o dia da validade do produto: \n\n");
                scanf("%d", &prodtemp.dia);

                //SOLICITAÇÃO E LEITURA DO MES DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o mes da validade do produto: \n\n");
                scanf("%d", &prodtemp.mes);

                //SOLICITAÇÃO E LEITURA DO ANO DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o ano da validade do produto: \n\n");
                scanf("%d", &prodtemp.ano);

                prodt[i] = prodtemp;

                //IMPRESSÃO DAS INFORMACOES DO PRODUTO ATUALIZADO.
                printf("\nCodigo: %d", prodt[i].cod);
                printf("\nNome: %s", prodt[i].nome);
                printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);

                printf("\n\nInformacoes atualizadas com sucesso!\n\n");
            }
        }
        return 0;
    }


    int checkMeetCodProdutoDel (Produto prodt[], int *pcq, int *pc)
    {
        int i, j;

        for(i = 0; i < *pcq; i++)
        {
            if((prodt[i]).cod == *pc)
            {
                printf("\n\n-------------[<INFORMACOES A SEREM DELETADAS>]------------------\n\n");

                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO A SERES EXCLUIDAS.
                printf("\nCodigo: %d", prodt[i].cod);
                printf("\nNome: %s", prodt[i].nome);
                printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);

                printf("\n\nDigite qualquer tecla para confirmar exclusao das informacoes.\n\n");

                system ("pause");

                prodt[i].cod = 0;
                strcpy((prodt[i]).nome, "");
                prodt[i].precoCompra = 0;
                prodt[i].precoVenda = 0;
                prodt[i].cod = 0;
                prodt[i].cod = 0;
                prodt[i].cod = 0;

                j = i;
            }
            printf("\n\nInformacoes deletadas com sucesso.\n\n");

            while (j < *pcq + 1)
            {
                for(j = i; j < *pcq; j++)
                {
                    prodt[j] = prodt[j+1];
                }
            }
        }
        return 0;
    }

    int checkMeetNomeProdutoDel (Produto prodt[], int *pcq, char pn[])
    {
        int i, j;

        for(i = 0; i < *pcq; i++)
        {
            if(strcmp((prodt[i]).nome, pn) == 0)
            {
                printf("\n\n-------------[<INFORMACOES A SEREM DELETADAS>]------------------\n\n");

                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO A SERES EXCLUIDAS.
                printf("\nCodigo: %d", prodt[i].cod);
                printf("\nNome: %s", prodt[i].nome);
                printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);

                printf("\n\nDigite qualquer tecla para confirmar exclusao das informacoes.\n\n");

                system ("pause");

                prodt[i].cod = 0;
                strcpy((prodt[i]).nome, "");
                prodt[i].precoCompra = 0;
                prodt[i].precoVenda = 0;
                prodt[i].dia = 0;
                prodt[i].mes = 0;
                prodt[i].ano = 0;
            }
            printf("\n\nInformacoes deletadas com sucesso.\n\n");

            j = i;

            while (j < *pcq)
            {
                for(j = i; j < *pcq; j++)
                {
                    prodt[j] = prodt[j+1];
                }
            }
        }
        return 0;
    }


    int checkMeetParteNomeProduto (Produto prodt[], int *pcq, char ppn[])
    {
        int i = 0;

        for(i = 0; i < *pcq; i++)
        {
            if(strstr((prodt[i]).nome, ppn) != 0)
            {
                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                printf("\n\n-------------[<INFORMACOES DO PRODUTO>]------------------\n\n");

                printf("\nCodigo: %d", prodt[i].cod);
                printf("\nNome: %s", prodt[i].nome);
                printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);
            }
        }
    return 0;

    }

    int checkMeetNomeProduto (Produto prodt[], int *pcq, char pn[])
    {
        int i = 0;

        for(i = 0; i < *pcq; i++)
        {
            if(strcmp((prodt[i]).nome, pn) == 0)
            {
                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                printf("\n\n-------------[<INFORMACOES DO PRODUTO>]------------------\n\n");

                printf("\nCodigo: %d", prodt[i].cod);
                printf("\nNome: %s", prodt[i].nome);
                printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);
            }
        }
    return 0;
    }


    //VERIFICA SE O NOME DO PRODUTO ESTA CADASTRADO.
    int checkNomeProduto (Produto prodt[], int *pcq, char pn[])
    {
        int i = 0;

        for(i = 0; i < *pcq; i++)
        {
            if(strcmp((prodt[i]).nome, pn) == 0)
            {
                return 1;
            }
        }
    return 0;
    }


    void addProdutoCar (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int i = 0,  j = 0, option;
        float Total = 0;
        Produto prodtemp;
        Compra comptemp;

        //SOLICITAÇÃO E LEITURA DO NOME DO PRODUTO.
        printf("\n\nDigite o nome do produto: \n\n");
        fflush(stdin);
        fgets(prodtemp.nome,30,stdin);
        removeQuebraLinha(prodtemp.nome);

        //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
        while (checkNomeProduto (prodt, pcq, prodtemp.nome) != 1)
        {
            printf("\n\nNome do produto nao cadastrado. Por favor, insira um nome valido:\n\n");
            fflush(stdin);
            fgets(prodtemp.nome,30,stdin);
            removeQuebraLinha(prodtemp.nome);
        }
        fflush(stdin);

        for(i = 0; i < *pcq + 1; i++)
        {
            if(strcmp((prodt[i]).nome, prodtemp.nome) == 0)
            {
                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                printf("\n\n-------------[<INFORMACOES DO PRODUTO>]------------------\n\n");

                printf("\nCodigo: %d", prodt[i].cod);
                printf("\nNome: %s", prodt[i].nome);
                printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);

                prodtemp.cod = prodt[i].cod;
                prodtemp.precoVenda = prodt[i].precoVenda;
            }
        }

        printf("\n\nDeseja incluir este produto o carrinho de compras?\n\n");

        system ("pause");

        do{

            printf("\n\n-------------[<CONFIRMAR COMPRA DO PRODUTO>]------------------------\n\n");

            printf("\n\n-------------------[<BIG SIDNEY'S SUPERMARKET>]---------------------\n\n");
            printf("\n'                                                                      '\n");
            printf("\n'Para CONFIRMAR COMPRA de PRODUTO: DIGITE [<1>].                       '\n");
            printf("\n'                                                                      '\n");
            printf("\n'Para CANCELAR COMPRA de PRODUTO: DIGITE [<2>].                        '\n");
            printf("\n'                                                                      '\n");
            printf("\n'Para FINALIZAR COMPRA de PRODUTOS(S) & IMPRIMIR NOTA: DIGITE [<3>].   '\n");
            printf("\n'                                                                      '\n");
            printf("\n'Para SAIR: DIGITE [<0>].                                              '\n");
            printf("\n\n-------------------------------------------------------------------'\n\n");

            scanf("%d", &option);

            switch (option)
            {
            case 1:
                printf("\n\nCompra confirmada!\n\n");
                printf("Digite a quantidade de produto desejada:\n\n");
                scanf("%f", &comptemp.quantProduto);

                (prodt[i].quantidade) -= comptemp.quantProduto;

                comptemp.valorTotal = ((comptemp.quantProduto)*(prodtemp.precoVenda));

                printf("\n\nValor da compra do produto de codigo (%d): %.2f", prodtemp.cod, comptemp.valorTotal);

                comptemp.codProduto = prodt[i].cod;
                comp[*ccq] = comptemp;
                (*ccq)++;

                printf("\n\nQuantidade de compras cadastradas: %d", *ccq);
                printf("\n\nCompra cadastrada com sucesso.");
                printf("\n\nDeseja imprimir a nota fiscal?\n\n");

                system("pause");

                do
                {
                    printf("\n\n-------------[<SUB MENU IMPRESSAO DA NOTA FISCAL>]------------------\n\n");

                    printf("\n\n-------------------[<BIG SIDNEY'S SUPERMARKET>]---------------------\n\n");
                    printf("\n'                                                                      '\n");
                    printf("\n'Para CONFIRMAR IMPRESSAO da NOTA: DIGITE [<1>].                       '\n");
                    printf("\n'                                                                      '\n");
                    printf("\n'Para CONTINUAR COMPRA de PRODUTO: DIGITE [<2>].                       '\n");
                    printf("\n'                                                                      '\n");
                    printf("\n'Para RETORNAR ao MENU FUNCIONARIO: DIGITE [<3>].                      '\n");
                    printf("\n'                                                                      '\n");
                    printf("\n'Para RETORNAR ao MENU PRINCIPAL: DIGITE [<4>].                        '\n");
                    printf("\n'                                                                      '\n");
                    printf("\n'Para SAIR: DIGITE [<0>].                                              '\n");
                    printf("\n\n-------------------------------------------------------------------'\n\n");

                    scanf("%d", &option);

                    switch (option)
                    {
                        case 1:

                            printf("\n\n//--------------[<NOTA FISCAL>]-----------------//\n\n");
                            printf("\n\n//-----------[<PRODUTOS COMPRADOS>]-------------//\n\n");

                            for(i = 0; i < *ccq; i++)
                            {
                                prodtemp.cod = comp[i].codProduto;
                                comptemp.quantProduto = comp[i].quantProduto;

                                Total = comp[i].valorTotal + Total;

                                for(j = 0; j < *pcq; j++)
                                {
                                    if((prodt[j]).cod == prodtemp.cod)
                                    {
                                        //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                                        printf("\n\n-------------[<INFORMACOES DO PRODUTO>]------------------\n\n");

                                        printf("\nCodigo: %s", prodt[j].cod);
                                        printf("\nNome: %s", prodt[j].nome);
                                        printf("\nPreco de Compra: %.2f", prodt[j].precoCompra);
                                        printf("\nPreco de Venda: %.2f", prodt[j].precoVenda);
                                        printf("\nQuantidade de produto armazenada: %d", prodt[j].quantidade);
                                        printf("\nData de validade do produto: %d/%d/%d\n", prodt[j].dia, prodt[j].mes, prodt[j].ano);

                                        prodtemp.precoVenda = prodt[j].precoVenda;
                                        printf("\nPreco da unidade: %.2f x %.2f unidade(s)", prodtemp.precoVenda, comptemp.quantProduto);
                                    }
                                }
                            }

                            printf("\n O valor total da compra foi: %.2f\n", Total);

                            printf("\nObrigado e volte sempre!");
                        break;

                    case 2:
                        addProdutoCar (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 3:
                        menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 4:
                        menuPrincipal (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 0:
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                        break;

                    default:
                        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                        break;
                    }

                }
                while (option != 0);

            case 2:
                canBuyProdtuto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;

            default:
                printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
            }
        }
        while (option =! 0);
    }


    void atualProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option;

        do{

            printf("\n\n-------------[<ATUALIZAR INFORMACOES DO PRODUTO>]------------------\n\n");

            printf("\n\n-------------------[<BIG SIDNEY'S SUPERMARKET>]--------------------\n\n");
            printf("\n'                                                                     '\n");
            printf("\n'Para ATUALIZAR pelo CODIGO: DIGITE [<1>].                             '\n");
            printf("\n'                                                                      '\n");
            printf("\n'Para ATUALIZAR pelo NOME: DIGITE [<2>].                               '\n");
            printf("\n'                                                                      '\n");
            printf("\n'Para SAIR: DIGITE [<0>].                                              '\n");
            printf("\n\n-------------------------------------------------------------------'\n\n");

            scanf("%d", &option);

            switch (option)
            {
            case 1:
                atualProdtCod (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 2:
                atualProdtNome (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;

            default:
                printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
            }
        }
        while (option != 0);
    }


    void atualProdtCod (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option;
        Produto prodtemp;

        printf("\n\nDigite um codigo para o produto: \n\n");
        fflush(stdin);
        scanf("%d", &prodtemp.cod);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkCodProduto (prodt, pcq, &prodtemp.cod) != 1)
        {
            printf("\n\nCodigo do produto nao cadastrado. Por favor, insira um codigo valido:\n\n");
            fflush(stdin);
            scanf("%d", &prodtemp.cod);
        }
        fflush(stdin);

        if (checkMeetCodProdutoAt (prodt, pcq, &prodtemp.cod) == 1)
        {

        }

        printf("\n\n");

        do
        {
            printf("\n\nDeseja atualizar outro produto?\n\n");

            printf("'-----------[<SUB MENU ATUALIZAR INFORMACAO PRODUTO>]------------'\n");
            printf("'                                                                '\n");
            printf("'SIM: DIGITE [<1>].                                              '\n");
            printf("'                                                                '\n");
            printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
            printf("'                                                                '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
            printf("'                                                                '\n");
            printf("'----------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        atualProdtCod (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 0:
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                        break;

                    default:
                        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                        break;
                }
            }
            while(option != 0);
    }


    void atualProdtNome (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option = 0;
        Produto prodtemp;

        printf("\n\nDigite o nome do produto: \n\n");
        fflush(stdin);
        fgets(prodtemp.nome,30,stdin);
        removeQuebraLinha(prodtemp.nome);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkNomeProduto (prodt, pcq, prodtemp.nome) != 1)
        {
            printf("\n\nNome do produto nao cadastrado. Por favor, insira um nome valido:\n\n");
            fflush(stdin);
            fgets(prodtemp.nome,30,stdin);
            removeQuebraLinha(prodtemp.nome);
        }
        fflush(stdin);

        if (checkMeetNomeProdutoAt (prodt, pcq, prodtemp.nome) == 1)
        {

        }

        printf("\n\n");

        do
        {
            printf("\n\nDeseja atualizar outro produto?\n\n");

            printf("'-----------[<SUB MENU ATUALIZAR INFORMACAO PRODUTO>]------------'\n");
            printf("'                                                                '\n");
            printf("'SIM: DIGITE [<1>].                                              '\n");
            printf("'                                                                '\n");
            printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
            printf("'                                                                '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
            printf("'                                                                '\n");
            printf("'----------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        atualProdtNome (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 0:
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                        break;

                    default:
                        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                        break;
                }
            }
            while(option != 0);
    }


    //REALIZA A OPERAÇÃO DE COMPRA.
    void buyProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int i = 0, option;
        Produto prodtemp;
        Socio sctemp;
        system("cls");

        printf("\n\n--------------[<CADASTRO DE COMPRA>]-------------------\n\n");

        //SOLICITAÇÃO E LEITURA DO LOGIN DO SOCIO.
        printf("\n\nDigite um login para o socio: \n\n");
        fflush(stdin);
        fgets(sctemp.user,20,stdin);
        removeQuebraLinha(sctemp.user);

        //SOLICITAÇÃO E LEITURA A SENHA DO SOCIO.
        printf("\n\nDigite uma senha para o socio: \n\n");
        fflush(stdin);
        fgets(sctemp.senha,10,stdin);
        removeQuebraLinha(sctemp.senha);

        //CHECAGEM DA VALIDADE DO LOGIN E SENHA DO SOCIO.
        while(checkLoginSocio (sc, sctemp.user, sctemp.senha, fcq) != 1)
        {
            printf("\n\nO login e/ou a senha informados estao incorretos. Tente novamente.\n");

            //SOLICITAÇÃO E LEITURA DO LOGIN DO SOCIO.
            printf("\n\nDigite um login para o socio: \n\n");
            fflush(stdin);
            fgets(sctemp.user,20,stdin);
            removeQuebraLinha(sctemp.user);

            //SOLICITAÇÃO E LEITURA A SENHA DO SOCIO.
            printf("\n\nDigite uma senha para o socio: \n\n");
            fflush(stdin);
            fgets(sctemp.senha,10,stdin);
            removeQuebraLinha(sctemp.senha);
        }
        fflush(stdin);

        //SOLICITAÇÃO E LEITURA DO CPF DO SOCIO.
        printf("\n\nDigite um CPF para o socio: \n\n");
        fflush(stdin);
        scanf("%d", &sctemp.cpf);

        //CHECAGEM DA VALIDADE DO CPF DO SOCIO.
        while (checkCpfSocio (sc, scq, &sctemp.cpf) != 1)
        {
            printf("\n\nCPF do socio nao cadastrado. Por favor, insira um cpf valido:\n\n");
            fflush(stdin);
            scanf("%d", &sctemp.cpf);
        }
        fflush(stdin);

        printf("\n\n-------------[<Ola! Boas compras e divirta-se! >]--------------\n\n");

        for(i = 0; i < *scq; i++)
        {
            if((sc[i]).cpf == sctemp.cpf)
            {
            //IMPRESSÃO DOS DADOS DO SOCIO CADASTRADO.
            printf("\n\n-------------[<INFORMACOES DO SOCIO>]------------------\n\n");

            //IMPRESSÃO DOS DADOS DO SOCIO CADASTRADO.
            printf("\nNome: %s", sc[i].nome);
            printf("\nCPF: %d", sc[i].cpf);
            }
        }

        do
        {
            printf("\n\nDeseja adicionar um produto ao carrinho de compras?\n\n");

            printf("'------------------[<SUB MENU COMPRA DE PRODUTO>]----------------'\n");
            printf("'                                                                '\n");
            printf("'SIM: DIGITE [<1>].                                              '\n");
            printf("'                                                                '\n");
            printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
            printf("'                                                                '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
            printf("'                                                                '\n");
            printf("'----------------------------------------------------------------'\n");

            scanf("%d", &option);

            switch(option)
            {
                case 1:
                    addProdutoCar (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                    break;

                case 2:
                    menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                    break;

                case 0:
                    printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                    printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                    break;

                default:
                    printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                    break;
            }
        }
        while (option =! 0);
    }


    //CADASTRA UM NOVO PRODUTO.
    void cadProduto(Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        Produto prodtemp;
        int option;

        system("cls");

        printf("\n\n--------------[<CADASTRO DE PRODUTO>]-------------------\n\n");

                //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
                printf("\n\nDigite um codigo para o produto: \n\n");
                fflush(stdin);
                scanf("%d", &prodtemp.cod);

                //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
                while (checkCodProduto (prodt, pcq, &prodtemp.cod) == 1)
                {
                    printf("\n\nCodigo do produto já cadastrado. Por favor, insira outro:\n\n");
                    fflush(stdin);
                    scanf("%d", &prodtemp.cod);
                }
                fflush(stdin);

                //SOLICITAÇAO E LEITURA DO NOME DO PRODUTO.
                printf("\n\nDigite um nome para o produto: \n\n");
                fflush(stdin);
                fgets(prodtemp.nome,30,stdin);
                removeQuebraLinha(prodtemp.nome);

                //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
                while (checkNomeProduto (prodt, pcq, prodtemp.nome) == 1)
                {
                    printf("\n\nNome do produto já cadastrado. Por favor, insira outro:\n\n");
                    fflush(stdin);
                    fgets(prodtemp.nome,30,stdin);
                    removeQuebraLinha(prodtemp.nome);
                }
                fflush(stdin);

                //SOLICITAÇÃO E LEITURA DO PRECO DE COMPRA DO PRODUTO.
                printf("\n\nDigite o preco de compra para o produto: \n\n");
                scanf("%f", &prodtemp.precoCompra);

                //SOLICITAÇÃO E LEITURA DO PRECO DE VENDA DO PRODUTO.
                printf("\n\nDigite o preco de venda para o produto: \n\n");
                scanf("%f", &prodtemp.precoVenda);

                //SOLICITAÇÃO E LEITURA DA QUANTIDADE ARMAZENADA DO PRODUTO.
                printf("\n\nDigite a quantidade do produto: \n\n");
                scanf("%d", &prodtemp.quantidade);

                //SOLICITAÇÃO E LEITURA DO DIA DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o dia da validade do produto: \n\n");
                scanf("%d", &prodtemp.dia);

                //SOLICITAÇÃO E LEITURA DO MES DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o mes da validade do produto: \n\n");
                scanf("%d", &prodtemp.mes);

                //SOLICITAÇÃO E LEITURA DO ANO DA VALIDADE DO PRODUTO.
                printf("\n\nDigite o ano da validade do produto: \n\n");
                scanf("%d", &prodtemp.ano);

                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                printf("\nCodigo: %d", prodtemp.cod);
                printf("\nNome: %s", prodtemp.nome);
                printf("\nPreco de Compra: %.2f", prodtemp.precoCompra);
                printf("\nPreco de Venda: %.2f", prodtemp.precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodtemp.quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodtemp.dia, prodtemp.mes, prodtemp.ano);

                prodt[*pcq] = prodtemp;

                printf("\n\nQuantidade de produtos diversos: %d", *pcq);

                (*pcq)++;

                printf("\n\nProduto cadastrado com sucesso.");

                do
                {
                    printf("\n\nDeseja cadastrar outro produto?\n\n");

                    printf("'-----------------[<SUB MENU CADASTRO PRODUTO>]------------------'\n");
                    printf("'                                                                '\n");
                    printf("'SIM: DIGITE [<1>].                                              '\n");
                    printf("'                                                                '\n");
                    printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
                    printf("'                                                                '\n");
                    printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
                    printf("'                                                                '\n");
                    printf("'----------------------------------------------------------------'\n");

                    scanf("%d", &option);

                    switch(option)
                    {
                    case 1:
                        cadProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;
                    case 2:
                        menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
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


    //CONFIRMA CANCELAMENTO DE COMPRA DO PRODUTO.
    void canBuyProdtuto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option;

        do
        {
            printf("\n\nPara confirmar o cancelamento da compra, escolha uma opcao!\n\n");

            printf("'-------------[<CANCELAMENTO DE COMPRA DO PRODUTO>]--------------'\n");
            printf("'                                                                '\n");
            printf("'SIM: DIGITE [<1>].                                              '\n");
            printf("'                                                                '\n");
            printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
            printf("'                                                                '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
            printf("'                                                                '\n");
            printf("'----------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        printf("\n\nCompra Cancelada!\n\n");
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");

                        do
                        {
                            printf("\n\nEscolha uma das opcoes abaixo:\n\n");

                            printf("\n'------------------[<SUB MENU CANCELAMENTO PRODUTO>]-----------------'\n");
                            printf("\n\n'                                                                '\n\n");
                            printf("\n'RETORNAR AO MENU FUNCIONARIO: DIGITE [<1>].                         '\n");
                            printf("\n'                                                                    '\n");
                            printf("\n'RETORNAR AO MENU ADMINISTRADOR: DIGITE [<2>].                       '\n");
                            printf("\n'                                                                    '\n");
                            printf("\n'RETORNAR AO MENU PRINCIPAL: DIGITE [<3>].                           '\n");
                            printf("\n'                                                                    '\n");
                            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                                  '\n");
                            printf("\n'                                                                    '\n");
                            printf("'\n--------------------------------------------------------------------'\n");

                            scanf("%d", &option);

                            switch(option)
                            {
                            case 1:
                                menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                                break;

                            case 2:
                                menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                                break;

                            case 3:
                                menuPrincipal (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                                break;

                            case 0:
                                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                                break;
                            }
                        }
                        while(option != 0);
                        break;

                    case 2:
                        addProdutoCar (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 0:
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                        break;

                    default:
                        system("cls");
                        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                        break;
                }
            }
            while(option != 0);
    }


    void excProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option;

        printf("\n\n-------------------------[<EXCLUIR PRODUTO>]-----------------------\n\n");

        printf("\n\n-------------------[<BIG SIDNEY'S SUPERMARKET>]--------------------\n\n");
        printf("\n'                                                                     '\n");
        printf("\n'Para EXCLUIR pelo CODIGO: DIGITE [<1>].                              '\n");
        printf("\n'                                                                     '\n");
        printf("\n'Para EXCLUIR pelo NOME: DIGITE [<2>].                                '\n");
        printf("\n'                                                                     '\n");
        printf("\n'Para SAIR: DIGITE [<0>].                                             '\n");
        printf("\n\n------------------------------------------------------------------'\n\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            excProdtCod (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 2:
            excProdtNome (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
            break;

        case 0:
            printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
            printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
        }
    }


    void excProdtCod (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int option;
        Produto prodtemp;

        printf("\n\nDigite um codigo para o produto: \n\n");
        fflush(stdin);
        scanf("%d", &prodtemp.cod);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkCodProduto (prodt, pcq, &prodtemp.cod) != 1)
        {
            printf("\n\nCodigo do produto nao cadastrado. Por favor, insira um codigo valido:\n\n");
            fflush(stdin);
            scanf("%d", &prodtemp.cod);
        }
        fflush(stdin);

        if (checkMeetCodProdutoDel (prodt, pcq, &prodtemp.cod) == 1)
        {

        }
        printf("\n\n");

        do
        {
            printf("\n\nDeseja excluir outro produto?\n\n");

            printf("'-----------[<SUB MENU ATUALIZAR INFORMACAO PRODUTO>]------------'\n");
            printf("'                                                                '\n");
            printf("'SIM: DIGITE [<1>].                                              '\n");
            printf("'                                                                '\n");
            printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
            printf("'                                                                '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
            printf("'                                                                '\n");
            printf("'----------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        atualProdtNome (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 0:
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                        break;

                    default:
                        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                        break;
                }
            }
            while(option != 0);
    }


    void excProdtNome (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        Produto prodtemp;

        printf("\n\nDigite um nome para o produto: \n\n");
        fflush(stdin);
        fgets(prodtemp.nome,30,stdin);
        removeQuebraLinha(prodtemp.nome);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkNomeProduto (prodt, pcq, prodtemp.nome) != 1)
        {
            printf("\n\nCodigo do produto nao cadastrado. Por favor, insira um codigo valido:\n\n");
            fflush(stdin);
            fgets(prodtemp.nome,30,stdin);
            removeQuebraLinha(prodtemp.nome);
        }
        fflush(stdin);

        if (checkMeetNomeProdutoDel (prodt, pcq, prodtemp.nome) == 1)
        {

        }
    }


    //IMPRIME OS PRODUTOS CADASTRADOS.
    void impressProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        int i, option = 0, pag = 1, contador, esc = 0;

        for(i = 0; i < *pcq; i++)
        {
             printf("\nCodigo: %d", prodt[i].cod);
             printf("\nNome: %s", prodt[i].nome);
             printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
             printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
             printf("\nQuantidade: %d", prodt[i].quantidade);
             printf("\nDia da validade: %d", prodt[i].dia);
             printf("\nMes da validade: %d", prodt[i].mes);
             printf("\nAno da validade: %d", prodt[i].ano);

             printf("\n[<------------------------------------------->]\n");

             contador++;

             if(contador == 5)
            {
                printf("\n\nPagina [<%d>]\n", pag);
                printf("\n\nDigite 1 para pagina seguinte ou 0 para sair:");
                scanf("%d", &esc);
                if(esc == 0)
                {
                    break;
                }
                contador = 0;

                pag++;

                system("pause");
                system("cls");

            }
        }
        system("pause");
        system("cls");

        do
        {
            printf("\n\nEscolha uma das opcoes abaixo:\n\n");

            printf("\n'-----------------[<SUB MENU LISTAGEM PRODUTO>]----------------'\n");
            printf("\n\n'                                                                '\n\n");
            printf("\n'RETORNAR AO MENU FUNCIONARIO: DIGITE [<1>].                         '\n");
            printf("\n'                                                                    '\n");
            printf("\n'RETORNAR AO MENU ADMINISTRADOR: DIGITE [<2>].                       '\n");
            printf("\n'                                                                    '\n");
            printf("\n'RETORNAR AO MENU PRINCIPAL: DIGITE [<3>].                           '\n");
            printf("\n'                                                                    '\n");
            printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                                  '\n");
            printf("\n'                                                                    '\n");
            printf("'\n--------------------------------------------------------------------'\n");

            scanf("%d", &option);

            switch(option)
            {
            case 1:
                menuFuncionario (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 2:
                menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 3:
                menuPrincipal (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;
            }
        }
        while(option != 0);
    }



    //ENCONTRA AS INFORMAÇÕES DE UM DETERMINADO PRODUTO.
    void meetProduto (Administrador admt[], Compra comp[], Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *ccq, int *fcq, int *pcq, int *scq, int *amax, int *cmax, int *fmax, int *pmax, int *smax)
    {
        Produto prodtemp, prodtemparte;
        int option;

        printf("\n\n----------[<BIG SIDNEY'S SUPERMARKET>]-----------\n\n");
        printf("\n'                                                   '\n");
        printf("\n'Para procura pelo CODIGO: DIGITE [<1>].            '\n");
        printf("\n'                                                   '\n");
        printf("\n'Para procura pelo NOME: DIGITE [<2>].              '\n");
        printf("\n'                                                   '\n");
        printf("\n'Para procura por parte do NOME: DIGITE [<3>].      '\n");
        printf("\n'                                                   '\n");
        printf("\n'Para SAIR: DIGITE [<0>].                           '\n");
        printf("\n\n------------------------------------------------'\n\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
            printf("\n\nDigite um codigo para o produto: \n\n");
            fflush(stdin);
            scanf("%d", &prodtemp.cod);

            //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
            while (checkCodProduto (prodt, pcq, &prodtemp.cod) != 1)
            {
                printf("\n\nCodigo do produto nao cadastrado. Por favor, insira um codigo valido:\n\n");
                fflush(stdin);
                scanf("%d", &prodtemp.cod);
            }
            fflush(stdin);

            if (checkMeetCodProduto (prodt, pcq, &prodtemp.cod) == 1)
            {

            }

            do
            {
                printf("\n\nDeseja procurar outro produto?\n\n");

                printf("'-----------------[<SUB MENU INFORMACAO PRODUTO>]------------------'\n");
                printf("'                                                                '\n");
                printf("'SIM: DIGITE [<1>].                                              '\n");
                printf("'                                                                '\n");
                printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
                printf("'                                                                '\n");
                printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
                printf("'                                                                '\n");
                printf("'----------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        meetProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 0:
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                        break;

                    default:
                        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                        break;
                }
            }
            while(option != 0);

            break;

        case 2:

            //SOLICITAÇAO E LEITURA DO NOME DO PRODUTO.
            printf("\n\nDigite um nome para o produto: \n\n");
            fflush(stdin);
            fgets(prodtemp.nome,30,stdin);
            removeQuebraLinha(prodtemp.nome);

            //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
            while (checkNomeProduto (prodt, pcq, prodtemp.nome) != 1)
            {
                printf("\n\nNome do produto nao cadastrado. Por favor, insira um nome valido:\n\n");
                fflush(stdin);
                fgets(prodtemp.nome,30,stdin);
                removeQuebraLinha(prodtemp.nome);
            }
            fflush(stdin);
            if (checkMeetNomeProduto (prodt, pcq, prodtemp.nome) == 1)
            {

            }

            do
            {
                printf("\n\nDeseja procurar outro produto?\n\n");

                printf("'-----------------[<SUB MENU INFORMACAO PRODUTO>]----------------'\n");
                printf("'                                                                '\n");
                printf("'SIM: DIGITE [<1>].                                              '\n");
                printf("'                                                                '\n");
                printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
                printf("'                                                                '\n");
                printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
                printf("'                                                                '\n");
                printf("'----------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        meetProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 0:
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                        break;

                    default:
                        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                        break;
                }
            }
            while(option != 0);

        break;

        case 3:

            //SOLICITAÇAO E LEITURA DE PARTE DO NOME DO PRODUTO.
            printf("\n\nDigite um nome (ou parte do nome) para o produto: \n\n");
            fflush(stdin);
            fgets(prodtemp.nome,30,stdin);
            removeQuebraLinha(prodtemparte.nome);

            if (checkMeetParteNomeProduto (prodt, pcq, prodtemparte.nome) == 1)
            {

            }

            do
            {
                printf("\n\nDeseja procurar outro produto?\n\n");

                printf("'-----------------[<SUB MENU INFORMACAO PRODUTO>]----------------'\n");
                printf("'                                                                '\n");
                printf("'SIM: DIGITE [<1>].                                              '\n");
                printf("'                                                                '\n");
                printf("'NAO & RETORNAR AO MENU ANTERIOR: DIGITE [<2>].                  '\n");
                printf("'                                                                '\n");
                printf("'NAO & SAIR do SISTEMA: DIGITE [<0>].                            '\n");
                printf("'                                                                '\n");
                printf("'----------------------------------------------------------------'\n");

                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        meetProduto (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, comp, func, prodt, sc, login, acq, ccq, fcq, pcq, scq, amax, cmax, fmax, pmax, smax);
                        break;

                    case 0:
                        printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                        printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                        break;

                    default:
                        printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
                        break;
                }
            }
            while(option != 0);

        break;

        case 0:
            printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
            printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
            break;
        }
    }




int main()
    {
        char login[20], senha[10];

        printf("\nDigite o login: \n\n");
        fflush(stdin);
        fgets(login,30,stdin);
        removeQuebraLinha(login);

        printf("\nDigite a senha: \n\n");
        fflush(stdin);
        fgets(senha,30,stdin);
        removeQuebraLinha(senha);

        //------------------------[<CONTADORES>]---------------------//

        //DEFINICAO DOS CONTADORES (POSIÇÃO DE ARMAZENAMENTO NO VETOR).
        int admtCadQtd = 0;
        int compCadQtd = 0;
        int prodtCadQtd = 0;
        int funcCadQtd = 0;
        int socioCadQtd = 0;

        //------------------------[<CONSTANTES>]---------------------//

        int ADM_MAX = 4;       //MAXIMO DE FUNCIONARIOS TIPO ADMINISTRADOR
        int COMP_MAX = 1000;  //MAXIMO DE COMPRAS DO SOCIO
        int FUNC_MAX = 10;     //MAXIMO DE FUNCIONARIOS
        int PROD_MAX = 10000;  //MAXIMO DE PRODUTOS DO SUPERMERCADO
        int SOCIO_MAX = 1000;  //MAXIMO DE SOCIOS DO SUPERMERCADO

        //-----------------------------------------------------------//



        //------------------------[<VETORES>]-----------------------//


        //DECLARACAO DOS VETORES ESTRUTURADOS.

        Administrador admt[ADM_MAX];
        Compra comp[COMP_MAX];
        Funcionario func[FUNC_MAX];
        Produto prodt[PROD_MAX];
        Socio sc[SOCIO_MAX];

         //-----------------------------------------------------------//


         //TESTES DE FUNÇOES E PROCEDIMENTOS.

        init (admt, comp, func, prodt, sc, &admtCadQtd, &compCadQtd, &funcCadQtd, &prodtCadQtd, &socioCadQtd);
        menuPrincipal (admt, comp, func, prodt, sc, login, &admtCadQtd, &compCadQtd, &funcCadQtd, &prodtCadQtd, &socioCadQtd, &ADM_MAX, &COMP_MAX, &FUNC_MAX, &PROD_MAX, &SOCIO_MAX);

        return 0;
    }




