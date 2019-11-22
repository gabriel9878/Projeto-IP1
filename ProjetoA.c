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

    void menuPrincipal(Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq,int *fcq, int *pcq, int *amax, int *fmax, int *pmax);
    void init(Administrador admt[], Funcionario func[], Produto prodt[], int *acq,  int *fcq, int *pcq);

//-------------------------------[<FUNÇÕES & PROCEDIMENTOS: ADMINISTRADOR>]----------------------------------//

    void loginAdministrador (Administrador admt[],Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax);
    void menuAdministrador (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax);
    void imprimirProduto (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax);
    void imprimirAdministrador (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax);
    void cadProduto (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax);
    void meetProduto (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax);
    int checkLoginAdministrador (Administrador admt[], char login[], char senha[], int *acq);
    void cadAdministrador (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax);
    void cadFuncionario (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax);

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
    void menuPrincipal(Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax)
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
                loginAdministrador(admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
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
    fgets(senha,30,stdin);
    removeQuebraLinha(senha);

    //IMPLEMENTAÇÃO DO LAÇO PARA CONCESSÃO (OU NEGAÇAO) DE PERMISSÃO PARA ACESSAR O MENU ADMINISTRADOR.
    for(i = 0; i < *acq; i++)
    {
        //VERIFICA A EXISTENCIA DO LOGIN E SENHAS INFORMADOS NO VETOR DE ESTRUTURA ADMINISTRADOR.
        if(checkLoginAdministrador(admt, login, senha, acq) == 1)
        {
            menuAdministrador(admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
        }
        else
        {
            printf("\n\n\nLogin ou senha incorretos, ou a conta de administrador inexistente.\n\n");

            system("pause");

            printf("\n\nDigite o seu login:\n\n");
            fflush(stdin);
            fgets(login,30,stdin);
            removeQuebraLinha(login);

            loginAdministrador(admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
        }
    }
}

    //VERIFICA A EXISTENCIA DO LOGIN E SENHAS INFORMADOS NO VETOR DE ESTRUTURA ADMINISTRADOR.
    int checkLoginAdministrador(Administrador admt[], char login[], char senha[], int *acq)
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
    void menuAdministrador(Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax)
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

        scanf("%d", &option);

        switch(option)
        {
        case 1:
            cadAdministrador (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
            break;

        case 2:
            cadFuncionario (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
            break;

        case 4:
            meetProduto (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);;
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

    void cadAdministrador(Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax)
    {
        Administrador admtemp;
        int i = 0, option;

        if(*amax == 10)
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

                    cadAdministrador (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
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
                menuAdministrador (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
                break;

            case 2:
                cadAdministrador (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
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


    //IMPRIME AS INFORMAÇÕES DOS OS ADMINISTRADORES CADASTRADOS.
    void imprimirAdministrador (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax)
    {
        int i;

        for(i = 0; i < *acq; i++)
        {
             printf("\nLogin = %s", admt[i].user);
             printf("\nSenha: %s", admt[i].senha);
             printf("\n\n");
        }
    }


    //IMPRIME OS PRODUTOS CADASTRADOS.
    void imprimirProduto (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax)
    {
        int i;

        for(i = 0; i < *pcq; i++)
        {
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


    //CADASTRA UM NOVO FUNCIONARIO.
    void cadFuncionario (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax)
    {
        Funcionario functemp;
        int i, x, option;

        printf("\n\n--------------[<CADASTRO DE FUNCIONARIO>]-------------------\n\n");

        //CHECAGEM DA VALIDADE DO NOME DO FUNCIONARIO.
        while((i < *fmax) & (option != 0))
        {
            //SOLICITAÇÃO E LEITURA DO NOME DO FUNCIONARIO.
            printf("\n\nDigite um login para o funcionario: \n\n");
            fflush(stdin);
            fgets(functemp.nome,50,stdin);
            removeQuebraLinha(functemp.nome);

            //SOLICITAÇÃO E LEITURA DA MATRICULA DO FUNCIONARIO.
            printf("\n\nDigite uma matricula para o funcionario: \n\n");
            fflush(stdin);
            scanf("%d", &functemp.matricula);

            //VERIFICA SE A MATRICULA TEM VALIDADE.
            for(i = 0; i < *fcq; i++)
            {
                if((func[i]).matricula == functemp.matricula)
                {
                    printf("\n\nMatricula de funcionario já cadastrada! Por favor insira outra:\n\n");
                    fflush(stdin);
                    scanf("%d", &functemp.matricula);
                    x = i;
                    func[x] = func[i];
                    i = 0;
                }
            }
            fflush(stdin);

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

            for(i = 0; i < *fcq; i++)
            {
                //VERIFICA SE O LOGIN TEM VALIDADE.
                if(strcmp((func[i]).user, functemp.user) == 0)
                {
                    printf("\n\nLogin de funcionario já cadastrado, por favor insira outro:\n\n");
                    fflush(stdin);
                    fgets(functemp.user,20,stdin);
                    removeQuebraLinha(functemp.user);
                    x = i;
                    func[x] = func[i];
                    i = 0;
                }
            }
            fflush(stdin);

            //SOLICITAÇÃO E LEITURA A SENHA DO FUNCIONARIO.
            printf("\n\nDigite uma senha para o funcionario: \n\n");
            fflush(stdin);
            fgets(functemp.senha,20,stdin);
            removeQuebraLinha(functemp.senha);

            for(i = 0; i < *fcq; i++)
            {
                //VERIFICA SE A SENHA TEM VALIDADE.
                if(strcmp((func[i]).senha, functemp.senha) == 0)
                {
                    printf("\n\nSenha de funcionario já cadastrada, por favor insira outro:\n\n");
                    fflush(stdin);
                    fgets(functemp.senha,20,stdin);
                    removeQuebraLinha(functemp.senha);
                    x = i;
                    func[x] = func[i];
                    i = 0;
                }
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

            printf("Quantidade de funcionarios cadastrados: %d", *fcq);

            func[*fcq] = functemp;

            printf("\n\nFuncionario cadastrado com sucesso.");
            printf("\n\nDeseja cadastrar outro funcionario?");

            printf("'-----------------[<SUB MENU CADASTRO FUNCIONARIO>]------------------'\n");
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
                menuAdministrador (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
                break;

            case 2:
                cadFuncionario (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;
            }
        }
    }



    //CADASTRA UM NOVO PRODUTO.
    void cadProduto (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax)
    {
        Produto prodtemp;
        int i, x, option;

        printf("\n\n--------------[<CADASTRO DE PRODUTO>]-------------------\n\n");


        while((i < *pmax) & (option != 0))
        {
            //SOLICITAÇÃO E LEITURA DO CÓDIGO DO PRODUTO.
            printf("\n\nDigite um codigo para o produto: \n\n");
            fflush(stdin);
            scanf("%d", &prodtemp.cod);

            //CHECAGEM DA VALIDADE DO CODIGO DO PRODUTO.
            for(i = 0; i < *pcq; i++)
            {
                if((prodt[i]).cod == prodtemp.cod)
                {
                    printf("\n\nCodigo de produto já cadastrado, por favor insira outro:\n\n");
                    fflush(stdin);
                    scanf("%d", &prodtemp.cod);
                }
            }
            fflush(stdin);

            //SOLICITAÇAO E LEITURA DO NOME DO PRODUTO.
            printf("\n\nDigite um nome para o produto: \n\n");
            fflush(stdin);
            fgets(prodtemp.nome,30,stdin);
            removeQuebraLinha(prodtemp.nome);

            //CHECAGEM DA VALIDADE DO NOME DO PRODUTO.
            for(i = 0; i < *pcq; i++)
            {
                if(strcmp((prodt[i]).nome,prodtemp.nome) == 0)
                {
                    printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
                    fflush(stdin);
                    fgets(prodtemp.nome,30,stdin);
                    removeQuebraLinha(prodtemp.nome);
                    x = i;
                    prodt[x] = prodt[i];
                    i = 0;
                }
            }
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

            printf("Quantidade de produtos diversos: %d", *pcq);

            prodt[*pcq] = prodtemp;

            printf("\n\nProduto cadastrado com sucesso.");
            printf("\n\nDeseja cadastrar outro produto?");

            printf("'-----------------[<SUB MENU CADASTRO PRODUTO>]------------------'\n");
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
                menuAdministrador (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
                break;

            case 2:
                meetProduto (admt, func, prodt, login, acq, fcq, pcq, amax, fmax, pmax);
                break;

            case 0:
                printf("\n\n------------------[<Thank you. So long!>]--------------------\n\n");
                printf("\n\n---------------[<Feliz Natal e Boas Ferias!>]----------------\n\n");
                break;
            }
        }
    }

    //ENCONTRA AS INFORMAÇÕES DE UM DETERMINADO PRODUTO.
    void meetProduto (Administrador admt[], Funcionario func[], Produto prodt[], char login[], int *acq, int *fcq, int *pcq, int *amax, int *fmax, int *pmax)
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
            printf("\n\nDigite o codigo do produto:\n\n");
            scanf("%d", &prodtemp.cod);

                for(i = 0; i < *pcq; i++)
                {
                    if(((prodt[i]).cod) == prodtemp.cod)
                    {
                        printf("\n\n-------------[<INFORMACOES DO PRODUTO>]------------------\n\n");

                        //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                        printf("\nCodigo: %d", prodt[i].cod);
                        printf("\nNome: %s", prodt[i].nome);
                        printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                        printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                        printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                        printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);
                    }
                }
            break;

        case 2:

            printf("\n\nDigite o nome do produto:\n\n");
            fflush(stdin);
            fgets(prodtemp.nome,30,stdin);
            removeQuebraLinha(prodtemp.nome);

                    for(i = 0; i <*pcq; i++)
                    {
                        if(strcmp(prodt[i].nome,prodtemp.nome) == 0 )
                        {
                            printf("\n\n-------------[<INFORMAÇÕES DO PRODUTO>]------------------\n\n");

                            //IMPRESSÃO DOS DADOS DO PRODUTO CADASTRADO.
                            printf("\nCodigo: %d", prodt[i].cod);
                            printf("\nNome: %s", prodt[i].nome);
                            printf("\nPreco de Compra: %.2f", prodt[i].precoCompra);
                            printf("\nPreco de Venda: %.2f", prodt[i].precoVenda);
                            printf("\nQuantidade de produto armazenada: %d", prodt[i].quantidade);
                            printf("\nData de validade do produto: %d/%d/%d\n", prodt[i].dia, prodt[i].mes, prodt[i].ano);
                        }
                }
            break;

        default:
            printf("\nOpcao invalida! Digite uma das opcoes propostas. Obrigado!\n");
        }
    }

void init(Administrador admt[], Funcionario func[], Produto prodt[], int *admtCadQtd,  int *funcCadQtd, int *prodtCadQtd){

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
        {"Sidney",7745,"Proprietario","sisi456","sisisi654",15,12,2018
        };

        *funcCadQtd = 2;
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

        //------------------------[<CONSTANTES>]---------------------//

        int ADM_MAX = 4;      //MAXIMO DE FUNCIONARIOS TIPO ADMINISTRADOR
        int FUNC_MAX = 10;    //MAXIMO DE FUNCIONARIOS TIPO CAIXA
        int PROD_MAX = 100;   //MAXIMO DE PRODUTOS DO SUPERMERCADO

        //-----------------------------------------------------------//



        //------------------------[<VETORES>]-----------------------//


        //DECLARACAO DO VETORES ESTRUTURADOS.

        Administrador admt[ADM_MAX];
        Funcionario func[FUNC_MAX];
        Produto prodt[PROD_MAX];

        init(admt, func, prodt, &admtCadQtd, &funcCadQtd, &prodtCadQtd);
        menuPrincipal(admt, func, prodt, login, &admtCadQtd, &funcCadQtd, &prodtCadQtd, &ADM_MAX, &FUNC_MAX, &PROD_MAX);

        //menuAdministrador(admt, func, prodt, login, &admtCadQtd, &funcCadQtd, &prodtCadQtd, &ADM_MAX, &FUNC_MAX, &PROD_MAX);


        return 0;
    }


