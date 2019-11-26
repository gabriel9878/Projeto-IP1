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

    int totalCodigo;//SOMA DA QUANTIDAE DE TODOS OS PRODUTOS DE MESMO CÓDIGO;
    float totalProdutos;//SOMA DOS VALORES DE TODOS OS PRODUTOS;

}Compra;


//-------------------------------[<DECLARAÇÃO DAS FUNÇÕES & PROCEDIMENTOS>]----------------------------------//

//-------------------------------[<FUNÇÕES & PROCEDIMENTOS: MENU PRINCIPAL>]---------------------------------//

    void menuPrincipal (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void init (Administrador admt[], Funcionario func[], Produto prodt[], Socio sc[], int *admtCadQtd,  int *funcCadQtd, int *prodtCadQtd, int *socioCadQtd);

//-------------------------------[<FUNÇÕES & PROCEDIMENTOS: ADMINISTRADOR>]----------------------------------//

    void loginAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void menuAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void impressProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void impressSocio (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void impressAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void impressFuncionario (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void cadProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void meetProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void meetSocio (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void atualProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void excProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    int checkLoginAdministrador (Administrador admt[], char login[], char senha[], int *acq);
    void loginFuncionario (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void menuFuncionario (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    int checkLoginFuncionario (Funcionario func[], char login[], char senha[], int *fcq);
    int checkLoginSocio (Socio sc[], char login[], char senha[], int *scq);
    int checkCodProduto (Produto prodt[], int *pcq, int *cod);
    int checkCpfSocio (Socio sc[], int *scq, int *cpf);
    int checkMatFuncionario (Funcionario func[], int *fcq, int *mat);
    int checkNomeProduto (Produto prodt[], int *pcq, char nome[]);
    void cadAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void cadSocio (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void cadFuncionario (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void atualProdtCod (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void atualProdtNome (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void excProdtCod (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);
    void excProdtNome (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax);

//------------------------------------[<FUNÇÕES & PROCEDIMENTOS:CAIXA>]--------------------------------------//

//REMOVE QUEBRA DE LINHA NO FINAL DA STRING.
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


//--------------------------------------[<PROCEDIMENTO MENU PRINCIPAL>]--------------------------------------//

    //EXIBE O MENU PRINCIPAL.
    void menuPrincipal (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
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

        scanf("%d", &option);

        do
        {
            switch(option)
            {
            case 1:
                loginAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                break;
            case 2:
                loginFuncionario (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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
    void loginAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
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
            menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
        }
        else
        {
            printf("\n\n\nLogin ou senha incorretos, ou a conta de administrador inexistente.\n\n");

            system("pause");

            printf("\n\nDigite o seu login:\n\n");
            fflush(stdin);
            fgets(login,10,stdin);
            removeQuebraLinha(login);

            loginAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);;
        }
    }
}

    //VERIFICA A EXISTENCIA DO LOGIN E SENHAS INFORMADOS NO VETOR DE ESTRUTURA ADMINISTRADOR.
    int checkLoginAdministrador (Administrador admt[], char login[], char senha[], int *acq)
    {
        int i;

        for(i = 0; i < *acq; i++)
        {
            if((strcmp((admt[i]).user,login) == 0) && (strcmp((admt[i]).senha,senha) == 0))
            {
                return 1;
            }
        }
    return 0;
    }

    //EXIBE O MENU DO ADMINISTRADOR.
    void menuAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
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
        printf("'Para CADASTRAR um novo ADMINISTRADOR: DIGITE [<1>].              '\n");
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
            cadAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 2:
            cadFuncionario (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 3:
            cadProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 4:
            meetProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 5:
            impressAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 6:
            impressFuncionario (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 7:
            impressProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 8:
            atualProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 9:
            excProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 0:
            menuPrincipal (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        default:
            system("cls");
            printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
            break;
        }
    }

    void cadAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        Administrador admtemp;
        int i = 0, option;

        if(*amax == 3)
        {
            printf("\nNumero maximo de administradores cadastrados ja foi atingido!\n");
        }

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

            for(i = 0; i < *acq; i++)//LAÇO ERRADO.
            {
                if(checkLoginAdministrador (admt, admtemp.user, admtemp.senha, acq) == 1)
                {
                    printf("\n\nO login ou a senha informadas ja existem! Por favor, insira dados diferentes!\n\n");

                    cadAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                }
            }
            printf("\n\nAdministrador cadastrado com sucesso!\n\n");
            printf("\nLogin: %s\n", admtemp.user);
            printf("\nSenha: %s\n", admtemp.senha);

            (*acq)++;//ERRO NO NUMERO DE ADMS CADASTRADOS.

            printf("\nQuantidade de administradores cadastrados: %d\n", *acq);

            admt[*acq] = admtemp;

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
                menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                break;

            case 2:
                cadAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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
    void impressAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        int i;

        for(i = 0; i < *acq; i++)
        {
             printf("\nLogin: %s", admt[i].user);
             printf("\nSenha: %s", admt[i].senha);
             printf("\n\n");
        }
        system ("pause");
    }


    //IMPRIME AS INFORMAÇÕES DOS FUNCIONARIOS CADASTRADOS.
    void impressFuncionario (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        int i;

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
    }


    //IMPRIME OS SOCIOS CADASTRADOS.
    void impressSocio (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        int i;

        for(i = 0; i < *scq; i++)
        {
             printf("\nNome: %s", sc[i].nome);
             printf("\nLogin: %s", sc[i].user);
             printf("\nSenha: %s", sc[i].senha);
             printf("\nCPF: %d", sc[i].cpf);

             printf("\n\n");
        }
        system ("pause");
    }

    //IMPRIME OS PRODUTOS CADASTRADOS.
    void impressProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        int i;

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

             printf("\n\n");
            }
            system ("pause");
    }

    void cadSocio (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        Socio sctemp;
        int i = 0, option = 0;

        while((i < *smax) & (option != 0))
        {
            if(*smax == 10000)
            {
                printf("\nNumero maximo de socios cadastrados ja foi atingido!\n");
            }

            printf("\n\n--------------[<CADASTRO DE SOCIO>]-------------------\n\n");

           //SOLICITAÇÃO E LEITURA DO NOME DO SOCIO.
            printf("\n\nDigite um nome para o socio: \n\n");
            fflush(stdin);
            fgets(sctemp.nome,50,stdin);
            removeQuebraLinha(sctemp.nome);

            //SOLICITAÇÃO E LEITURA DO LOGIN DO FUNCIONARIO.
            printf("\n\nDigite um login para o socio: \n\n");
            fflush(stdin);
            fgets(sctemp.user,20,stdin);
            removeQuebraLinha(sctemp.user);

            //SOLICITAÇÃO E LEITURA A SENHA DO FUNCIONARIO.
            printf("\n\nDigite uma senha para o funcionario: \n\n");
            fflush(stdin);
            fgets(sctemp.senha,10,stdin);
            removeQuebraLinha(sctemp.senha);

            //CHECAGEM DA VALIDADE DO LOGIN E SENHA DO FUNCIONARIO.
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

            while(checkCpfSocio (sc, scq, sctemp.cpf) == 1)
            {
                printf("\n\nCPF de socio já cadastrado. Por favor, insira outro:\n\n");
                fflush(stdin);
                scanf("%d", sctemp.cpf);
            }

            //IMPRESSÃO DOS DADOS DO SOCIO CADASTRADO.
            printf("\nNome: %s", sctemp.nome);
            printf("\nLogin: %s", sctemp.user);
            printf("\nSenha: %s", sctemp.senha);
            printf("\nCPF: %d", sctemp.cpf);

            (*scq)++;

            printf("\n\nQuantidade de socios cadastrados: %d", *scq);

            sc[*scq] = sctemp;

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
                    menuFuncionario (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                    break;

                case 2:
                    cadSocio (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                    break;

                case 0:
                    printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                    printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                    break;
                }
            }
            while(option != 0);
        }
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


    //ENCONTRA INFORMAÇÕES ACERCA DE UM DETERMINADO SOCIO.
    void meetSocio (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        Socio sctemp;
        int i = 0, option = 0;

        //SOLICITAÇÃO E LEITURA DO CPF DO SOCIO.
        printf("\n\nDigite um CPF para o socio: \n\n");
        fflush(stdin);
        scanf("%d", sctemp.cpf);

        //CHECAGEM DA VALIDADE DO CPF DO SOCIO.
        while (checkCpfSocio (sc, scq, sctemp.cpf) != 1)
        {
            printf("\n\nCPF do socio nao cadastrado. Por favor, insira um cpf valido:\n\n");
            fflush(stdin);
            scanf("%d", sctemp.cpf);
        }
        fflush(stdin);

        //IMPRESSÃO DOS DADOS DO SOCIO CADASTRADO.
        printf("\n\n-------------[<INFORMAÇÕES DO SOCIO>]------------------\n\n");

        //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
        printf("\nNome: %s", sc[i].nome);
        printf("\nLogin: %s", sc[i].user);
        printf("\nSenha: %s", sc[i].senha);
        printf("\nCPF:", sc[i].cpf);

        do
        {
            printf("\n\nDeseja procuar outro socio?\n\n");

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
                    meetSocio (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                    break;

                case 2:
                    menuFuncionario (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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
        while(option != 0)
    }


    void loginFuncionario (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
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
        for(i = 0; i < *acq; i++)
        {
            //VERIFICA A EXISTENCIA DO LOGIN E SENHAS INFORMADOS NO VETOR DE ESTRUTURA FUNCIONARIO.
            if(checkLoginFuncionario(func, login, senha, fcq) == 1)
            {
                menuFuncionario (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            }
            else
            {
                printf("\n\n\nLogin ou senha incorretos, ou a conta de funcionario inexistente.\n\n");

                system("pause");

                printf("\n\nDigite o seu login:\n\n");
                fflush(stdin);
                fgets(login,20,stdin);
                removeQuebraLinha(login);

                loginFuncionario (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            }
        }
    }

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

    //EXIBE O MENU FUNCIONARIO.
    void menuFuncionario (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
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
        printf("'Para COMPRAR PRODUTOS ARMAZENADOS: DIGITE [<5>].                '\n");
        printf("'                                                                '\n");
        printf("'Para IMPRIMIR LISTA DE PRODUTOS COMPRADOS: DIGITE [<6>].        '\n");
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
            meetProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 2:
            impressProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 3:
            meetSocio (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 4:
            impressSocio (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 5:
            //buyProduto (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
            break;

        case 6:
            //listCompra (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
            break;

        case 0:
            menuPrincipal (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        default:
            system("cls");
            printf("\nOpcao invalida! Digite uma das opções sugeridas. Obrigado!\n");
            break;
        }
    }


    //CADASTRA UM NOVO FUNCIONARIO.
    void cadFuncionario (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        Funcionario functemp;
        int i = 0, option = 0;

        while((i < *fmax) & (option != 0))
        {
            if(*fmax == 10)
            {
                printf("\nNumero maximo de funcionarios cadastrados ja foi atingido!\n");
            }

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

            while(checkMatFuncionario (func, fcq, functemp.matricula) == 1)
            {
                printf("\n\nMatricula de funcionario já cadastrada. Por favor, insira outra:\n\n");
                fflush(stdin);
                scanf("%d", functemp.matricula);
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

            (*fcq)++;

            printf("\n\nQuantidade de funcionarios cadastrados: %d", *fcq);

            func[*fcq] = functemp;

            printf("\n\nFuncionario cadastrado com sucesso.");

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
                    menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                    break;

                case 2:
                    cadFuncionario (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                    break;

                case 0:
                    printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                    printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                    break;
                }
            }
            while(option != 0);
        }
    }


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


    //CADASTRA UM NOVO PRODUTO.
    void cadProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        Produto prodtemp;
        int i = 0, option = 0;

        while((i < *pmax) & (option != 0))
        {

            if(*pmax == 1000)
            {
                printf("\nNumero maximo de produtos cadastrados ja foi atingido!\n");
            }

            printf("\n\n--------------[<CADASTRO DE PRODUTO>]-------------------\n\n");

                //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
                printf("\n\nDigite um codigo para o produto: \n\n");
                fflush(stdin);
                scanf("%d", prodtemp.cod);

                //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
                while (checkCodProduto (prodt, pcq, prodtemp.cod) == 1)
                {
                    printf("\n\nCodigo do produto já cadastrado. Por favor, insira outro:\n\n");
                    fflush(stdin);
                    scanf("%d", prodtemp.cod);
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

                (*pcq)++;

                printf("\n\nQuantidade de produtos diversos: %d", *pcq);

                prodt[*pcq] = prodtemp;

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
                        cadProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                        break;
                    case 2:
                        menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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
    }


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

    //ENCONTRA AS INFORMAÇÕES DE UM DETERMINADO PRODUTO.
    void meetProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
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

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
            printf("\n\nDigite um codigo para o produto: \n\n");
            fflush(stdin);
            scanf("%d", prodtemp.cod);

            //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
            while (checkCodProduto (prodt, pcq, prodtemp.cod) == 1)
            {
                printf("\n\nCodigo do produto já cadastrado. Por favor, insira outro:\n\n");
                fflush(stdin);
                scanf("%d", prodtemp.cod);
            }
            fflush(stdin);

            //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
            printf("\n\n-------------[<INFORMAÇÕES DO PRODUTO>]------------------\n\n");

            //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
            printf("\nCodigo: %d", prodt[i].cod);
            printf("\nNome: %s", prodt[i].nome);
            printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
            printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
            printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
            printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);

            do
            {
                printf("\n\nDeseja procuar outro produto?\n\n");

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
                        meetProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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
            while (checkNomeProduto (prodt, pcq, prodtemp.nome) == 1)
            {
                printf("\n\nNome do produto já cadastrado. Por favor, insira outro:\n\n");
                fflush(stdin);
                fgets(prodtemp.nome,30,stdin);
                removeQuebraLinha(prodtemp.nome);
            }
            fflush(stdin);
            printf("\n\n-------------[<INFORMAÇÕES DO PRODUTO>]------------------\n\n");

            //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
            printf("\nCodigo: %d", prodt[i].cod);
            printf("\nNome: %s", prodt[i].nome);
            printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
            printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
            printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
            printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);

            do
            {
                printf("\n\nDeseja procuar outro produto?\n\n");

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
                        meetProduto (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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

    void atualProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        Produto prodtemp;
        int i = 0, option = 0;

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
            atualProdtCod (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 2:
            atualProdtNome (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 0:
            printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
            printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
        }
    }


    void atualProdtCod (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        int x, i = 0, option = 0;
        Produto prodtemp;

        printf("\n\nDigite um codigo para o produto: \n\n");
        fflush(stdin);
        scanf("%d", prodtemp.cod);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkCodProduto (prodt, pcq, prodtemp.cod) != 1)
        {
            printf("\n\nCodigo do produto nao cadastrado. Por favor, insira um codigo valido:\n\n");
            fflush(stdin);
            scanf("%d", prodtemp.cod);
        }
        fflush(stdin);

        for(i = 0; i < *pcq; i++)
        {
            if((prodt[i]).cod == prodtemp.cod)
            {
                x = i;

                printf("\n\n-------------[<INFORMACOES ATUAIS DO PRODUTO>]------------------\n\n");

                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                printf("\nCodigo: %d", prodt[x].cod);
                printf("\nNome: %s", prodt[x].nome);
                printf("\nPreco de Compra: %.2f", prodt[x].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[x].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[x].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[x].dia, prodt[x].mes, prodt[x].ano);
            }

        }

        printf("\n\nRealize as alteraçoes desejadas.\n\n");

        //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
        printf("\n\nDigite um codigo para o produto: \n\n");
        fflush(stdin);
        scanf("%d", prodtemp.cod);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkCodProduto (prodt, pcq, prodtemp.cod) == 1)
        {
            printf("\n\nCodigo do produto já cadastrado. Por favor, insira outro:\n\n");
            fflush(stdin);
            scanf("%d", prodtemp.cod);
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

        prodt[x] = prodtemp;

        printf("\n\n");

        //IMPRESSÃO DAS INFORMACOES DO PRODUTO ATUALIZADO.
        printf("\nCodigo: %d", prodt[x].cod);
        printf("\nNome: %s", prodt[x].nome);
        printf("\nPreco de Compra: %.2f", prodt[x].precoCompra);
        printf("\nPreco de Venda: %.2f", prodt[x].precoVenda);
        printf("\nQuantidade de produto armazenada: %d", prodt[x].quantidade);
        printf("\nData de validade do produto: %d/%d/%d\n", prodt[x].dia, prodt[x].mes, prodt[x].ano);

        printf("\n\nInformacoes atuallizadas com sucesso!\n\n");

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
                        atualProdtCod (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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


    void atualProdtNome (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        int x, i = 0, option = 0;
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

        for(i = 0; i < *pcq; i++)
        {
            if(strcmp((prodt[i]).nome, prodtemp.nome) == 0)

                x = i;

                printf("\n\n-------------[<INFORMACOES ATUAIS DO PRODUTO>]------------------\n\n");

                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                printf("\nCodigo: %d", prodt[x].cod);
                printf("\nNome: %s", prodt[x].nome);
                printf("\nPreco de Compra: %.2f", prodt[x].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[x].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[x].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[x].dia, prodt[x].mes, prodt[x].ano);
        }

        printf("\n\nRealize as alteraçoes desejadas.\n\n");

        //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
        printf("\n\nDigite um codigo para o produto: \n\n");
        fflush(stdin);
        scanf("%d", prodtemp.cod);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkCodProduto (prodt, pcq, prodtemp.cod) == 1)
        {
            printf("\n\nCodigo do produto já cadastrado. Por favor, insira outro:\n\n");
            fflush(stdin);
            scanf("%d", prodtemp.cod);
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

        prodt[x] = prodtemp;

        printf("\n\n");

        //IMPRESSÃO DAS INFORMACOES DO PRODUTO ATUALIZADO.
        printf("\nCodigo: %d", prodt[x].cod);
        printf("\nNome: %s", prodt[x].nome);
        printf("\nPreco de Compra: %.2f", prodt[x].precoCompra);
        printf("\nPreco de Venda: %.2f", prodt[x].precoVenda);
        printf("\nQuantidade de produto armazenada: %d", prodt[x].quantidade);
        printf("\nData de validade do produto: %d/%d/%d\n", prodt[x].dia, prodt[x].mes, prodt[x].ano);

        printf("\n\nInformacoes atuallizadas com sucesso!\n\n");

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
                        atualProdtNome (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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


    void excProduto (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        Produto prodtemp;
        int i = 0, option = 0;

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
            excProdtCod (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 2:
            excProdtNome (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
            break;

        case 0:
            printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
            printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
        }
    }


    void excProdtCod (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        int i = 0, x, option;
        Produto prodtemp;

        printf("\n\nDigite um codigo para o produto: \n\n");
        fflush(stdin);
        scanf("%d", prodtemp.cod);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkCodProduto (prodt, pcq, prodtemp.cod) != 1)
        {
            printf("\n\nCodigo do produto nao cadastrado. Por favor, insira um codigo valido:\n\n");
            fflush(stdin);
            scanf("%d", prodtemp.cod);

        }
        fflush(stdin);

        for(i = 0; i < *pcq; i++)
        {
            if((prodt[i]).cod == prodtemp.cod)
            {
                x = i;

                printf("\n\n-------------[<INFORMACOES A SEREM DELETADAS>]------------------\n\n");

                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO A SERES EXCLUIDAS.
                printf("\nCodigo: %d", prodt[x].cod);
                printf("\nNome: %s", prodt[x].nome);
                printf("\nPreco de Compra: %.2f", prodt[x].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[x].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[x].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[x].dia, prodt[x].mes, prodt[x].ano);

                printf("\n\nDigite qualquer tecla para confirmar exclusao das informacoes.\n\n");

                system ("pause");

                prodt[x].cod = 0;
                strcpy((prodt[x]).nome, "");
                prodt[x].precoCompra = 0;
                prodt[x].precoVenda = 0;
                prodt[x].dia = 0;
                prodt[x].mes = 0;
                prodt[x].ano = 0;
        }

        printf("\n\nInformacoes deletadas com sucesso.\n\n");

        while (i < *pcq + 1)
        {
            for(i = x; i < *pmax; i++)
            {
                prodt[i] = prodt[i+1];
            }
        }

        do
        {
            printf("\n\nDeseja deletar outro produto?\n\n");

            printf("'-----------[<SUB MENU DELETAR INFORMACAO PRODUTO>]------------'\n");
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
                        excProdtCod (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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
    }


    void excProdtNome (Administrador admt[],Funcionario func[], Produto prodt[], Socio sc[], char login[], int *acq, int *fcq, int *pcq, int *scq, int *amax, int *fmax, int *pmax, int *smax)
    {
        int i = 0, x, option = 0;
        Produto prodtemp;

        printf("\n\nDigite um codigo para o produto: \n\n");
        fflush(stdin);
        fgets(prodtemp.nome,30,stdin);
        removeQuebraLinha(prodtemp.nome);

        //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
        while (checkCodProduto (prodt, pcq, prodtemp.nome) != 1)
        {
            printf("\n\nCodigo do produto nao cadastrado. Por favor, insira um codigo valido:\n\n");
            fflush(stdin);
            fgets(prodtemp.nome,30,stdin);
            removeQuebraLinha(prodtemp.nome);
        }
        fflush(stdin);

        for(i = 0; i < *pcq; i++)
        {
             if(strcmp((prodt[i]).nome, prodtemp.nome) == 0)
            {
                x = i;

                printf("\n\n-------------[<INFORMACOES A SEREM DELETADAS>]------------------\n\n");

                //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO A SERES EXCLUIDAS.
                printf("\nCodigo: %d", prodt[x].cod);
                printf("\nNome: %s", prodt[x].nome);
                printf("\nPreco de Compra: %.2f", prodt[x].precoCompra);
                printf("\nPreco de Venda: %.2f", prodt[x].precoVenda);
                printf("\nQuantidade de produto armazenada: %d", prodt[x].quantidade);
                printf("\nData de validade do produto: %d/%d/%d\n", prodt[x].dia, prodt[x].mes, prodt[x].ano);

                printf("\n\nDigite qualquer tecla para confirmar exclusao das informacoes.\n\n");

                system ("pause");

                prodt[x].cod = 0;
                strcpy((prodt[x]).nome, "");
                prodt[x].precoCompra = 0;
                prodt[x].precoVenda = 0;
                prodt[x].cod = 0;
                prodt[x].cod = 0;
                prodt[x].cod = 0;
        }
        printf("\n\nInformacoes deletadas com sucesso.\n\n");

        while (i < *pcq + 1)
        {
            for(i = x; i < *pmax; i++)
            {
                prodt[i] = prodt[i+1];
            }
        }

        do
        {
            printf("\n\nDeseja deletar outro produto?\n\n");

            printf("'-------------[<SUB MENU DELETAR INFORMACAO PRODUTO>]------------'\n");
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
                        excProdtNome (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
                        break;

                    case 2:
                        menuAdministrador (admt, func, prodt, sc, login, acq, fcq, pcq, scq, amax, fmax, pmax, smax);
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
    }


void init(Administrador admt[], Funcionario func[], Produto prodt[], Socio sc[], int *admtCadQtd,  int *funcCadQtd, int *prodtCadQtd, int *socioCadQtd){

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

        //DECLARACAO DOS FUNCIONARIOS 1 E 2 PARA TESTE DE FUNCIONAMENTO.

        func[0] = (Funcionario)
        {"Jose",9856,"Caixa","jose123xx","xxjose123",02,05,2015
        };
        func[1] = (Funcionario)
        {"Sidney",7745,"Proprietario","sisi456","si456",15,12,2018
        };

        *funcCadQtd = 2;

        //DECLARACAO DOS SOCIOS 1 E 2 PARA TESTE DE FUNCIONAMENTO.

        sc[0] = (Socio)
        {"Alexandre","alx","6789",45698578423
        };
        sc[1] = (Socio)
        {"Karina","kar","9876",15122018435
        };

        *socioCadQtd = 2;
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
        int prodtCadQtd = 0;
        int funcCadQtd = 0;
        int socioCadQtd = 0;

        //------------------------[<CONSTANTES>]---------------------//

        int ADM_MAX = 4;      //MAXIMO DE FUNCIONARIOS TIPO ADMINISTRADOR
        int FUNC_MAX = 10;    //MAXIMO DE FUNCIONARIOS TIPO CAIXA
        int PROD_MAX = 10000;   //MAXIMO DE PRODUTOS DO SUPERMERCADO
        int SOCIO_MAX = 1000; //MAXIMO DE SOCIOS DO SUPERMERCADO

        //-----------------------------------------------------------//



        //------------------------[<VETORES>]-----------------------//


        //DECLARACAO DOS VETORES ESTRUTURADOS.

        Administrador admt[ADM_MAX];
        Funcionario func[FUNC_MAX];
        Produto prodt[PROD_MAX];
        Socio sc[SOCIO_MAX];

         //-----------------------------------------------------------//


         //TESTES DE FUNÇOES E PROCEDIMENTOS.

        init(admt, func, prodt, sc, &admtCadQtd, &funcCadQtd, &prodtCadQtd, &socioCadQtd);
        menuPrincipal(admt, func, prodt, sc, login, &admtCadQtd, &funcCadQtd, &prodtCadQtd, &socioCadQtd, &ADM_MAX, &FUNC_MAX, &PROD_MAX, &SOCIO_MAX);

        return 0;
    }



