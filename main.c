#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char mat[10][10]; //declaração da matriz como global
char PalavraPesquisada[10];//declarando as variaveis como globais para facilitar no uso dos procedimentos
char matrizP[10][10];

/*Esse procedimento é o responsavel por mostrar o menu de opçôes ao usuario*/
void menuPrincial()
{
    printf("               MENU               \n");
    printf("\n1 - Criar matriz a partir do teclado\n");
    printf("2 - Criar matriz de forma aleatoria\n");
    printf("3 - Imprima a matriz\n");
    printf("4 - Solicita uma palavra para a pesquisa\n");
    printf("5 - Pesquisar\n");
    printf("6 - Executa teste padrao\n");
    printf("0 - Sair do Programa\n");
    printf("\nEscolha: ");
}
/*void leia() é um procedimento utilizado para quando o usuário deseja inserir uma matriz manualmente pelo teclado,
e os dados digitados estão sendo armazenados na matriz: mat[i][j]
note que os dados estão sendo inseridos linha por linha, para facilitar o uso ao usuario*/
void leia()
{
    for (int i=0; i < 10 ; i++)
    {
        for (int j=0 ; j < 10 ; j++ )
        {
            mat[i][j]=0;
        }
    }

    printf("Digite linha por linha com ate 10 caracteres!\n\n");

    for(int i=0; i < 10; i++)
    {

        printf("Insira linha %i: ", i);
        fflush(stdin);
        scanf("%s", mat[i]);
        fflush(stdin);
    }

}
/*Esse procedimento gera caracteres de forma aleatoria, usando a função Rand*/
void MatrizAleatoria()/*(char matriz[10][10])*/
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mat[i][j] = 97 + (char)(rand()%26);
        }
    }
}
/*matPronta() é um procedimento onde ja vem pré-definido uma matriz[10][10]*/
void matPronta(){
    mat[0][0]='a'; mat[0][1]='b'; mat[0][2]='a'; mat[0][3]='c'; mat[0][4]='a'; mat[0][5]='x'; mat[0][6]='a'; mat[0][7]='b'; mat[0][8]='a'; mat[0][9]='a';
	mat[1][0]='c'; mat[1][1]='b'; mat[1][2]='y'; mat[1][3]='f'; mat[1][4]='a'; mat[1][5]='z'; mat[1][6]='a'; mat[1][7]='a'; mat[1][8]='a'; mat[1][9]='l';
	mat[2][0]='i'; mat[2][1]='t'; mat[2][2]='a'; mat[2][3]='e'; mat[2][4]='h'; mat[2][5]='p'; mat[2][6]='e'; mat[2][7]='r'; mat[2][8]='o'; mat[2][9]='a';
	mat[3][0]='p'; mat[3][1]='i'; mat[3][2]='r'; mat[3][3]='a'; mat[3][4]='v'; mat[3][5]='e'; mat[3][6]='r'; mat[3][7]='o'; mat[3][8]='f'; mat[3][9]='f';
	mat[4][0]='o'; mat[4][1]='z'; mat[4][2]='t'; mat[4][3]='a'; mat[4][4]='z'; mat[4][5]='m'; mat[4][6]='a'; mat[4][7]='d'; mat[4][8]='i'; mat[4][9]='f';
	mat[5][0]='i'; mat[5][1]='x'; mat[5][2]='q'; mat[5][3]='m'; mat[5][4]='u'; mat[5][5]='a'; mat[5][6]='l'; mat[5][7]='a'; mat[5][8]='l'; mat[5][9]='i';
	mat[6][0]='t'; mat[6][1]='c'; mat[6][2]='w'; mat[6][3]='n'; mat[6][4]='u'; mat[6][5]='s'; mat[6][6]='u'; mat[6][7]='l'; mat[6][8]='g'; mat[6][9]='n';
	mat[7][0]='t'; mat[7][1]='e'; mat[7][2]='s'; mat[7][3]='t'; mat[7][4]='e'; mat[7][5]='d'; mat[7][6]='e'; mat[7][7]='l'; mat[7][8]='i'; mat[7][9]='n';
	mat[8][0]='h'; mat[8][1]='o'; mat[8][2]='m'; mat[8][3]='a'; mat[8][4]='r'; mat[8][5]='o'; mat[8][6]='b'; mat[8][7]='o'; mat[8][8]='b'; mat[8][9]='a';
	mat[9][0]='k'; mat[9][1]='o'; mat[9][2]='a'; mat[9][3]='z'; mat[9][4]='z'; mat[9][5]='z'; mat[9][6]='a'; mat[9][7]='m'; mat[9][8]='a'; mat[9][9]='l';
}
/*É o procedimento para a realização do teste padrão, onde se encontra a busca por todas as ocorrencias*/
void matTeste()
{
    matPronta();

    /*Esse for é responsavel por gerar a matriz[10][10], que foi inserida no procedimento matPronta,
    onde nos dá uma matriz pronta para que o usuario não digite.
    */

    printf("      CACA-PALAVRAS      \n");
    printf("\n");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%2c ", mat[i][j]);
        }
        printf("\n");
    }

    printf ("\nInforme a palavra a ser pesquisada com apenas 10 letras\n");
    scanf ("%s", PalavraPesquisada);

    int tamStr = strlen(PalavraPesquisada), auxCol, aux, contPalavra=0;

    for (int linha = 0; linha < 10; linha++)
    {
        for (int coluna = 0; coluna < 10 - tamStr + 1; coluna++)
        {
            auxCol = coluna;
            aux = 0;
            while(PalavraPesquisada[aux] == mat[linha][auxCol] && aux < tamStr)
            {
                aux++;
                auxCol++;

            }
            if(aux == tamStr)
            {
                printf("Achou a palavra %s esq -->dir: lin %d  col: %d\n",PalavraPesquisada, linha, coluna);
                contPalavra++;
            }

        }
    }
    if (contPalavra > 0)
    {
        printf("\nTotal encontrado de %s eh de: %d\n\n", PalavraPesquisada, contPalavra);

    }
    else
    {
        printf ("\nPalavra nao encontrada no esq -->dir\n");
    }

    contPalavra = 0;
    for (int linha = 0; linha < 10; linha++)
    {
        for (int coluna = 9; coluna >=0; coluna--)
        {
            auxCol = coluna;
            aux = 0;
            while(PalavraPesquisada[aux] == mat[linha][auxCol] && aux < tamStr)
            {
                aux++;
                auxCol--;

            }
            if(aux == tamStr)
            {
                printf("Achou a palavra %s dir -->esq: lin %d  col: %d\n",PalavraPesquisada, linha, coluna);
                contPalavra++;
            }


        }
    }
    if (contPalavra > 0)
    {
        printf("\nTotal encontrado de %s eh de: %d\n\n", PalavraPesquisada, contPalavra);

    }
    else
    {
        printf ("\nPalavra nao encontrada no dir -->esq\n");
    }

    contPalavra = 0;
    for (int linha = 0; linha < 10; linha++)
    {
        for (int coluna = 9; coluna >= 0; coluna--)
        {
            auxCol = coluna;
            aux = 0;
            while(PalavraPesquisada[aux] == mat[auxCol][linha] && aux < tamStr)
            {
                aux++;
                auxCol--;

            }
            if(aux == tamStr)
            {
                printf("Achou a palavra %s  baixo --> cima: lin %d  col: %d\n",PalavraPesquisada, coluna, linha );
                contPalavra++;
            }

        }

    }
    if (contPalavra > 0)
    {
        printf("\nTotal encontrado de %s eh de: %d\n\n", PalavraPesquisada, contPalavra);

    }
    else
    {
        printf ("\nPalavra nao encontrada no baixo --> cima\n");
    }

    contPalavra = 0;
    for (int linha = 0; linha < 10; linha++)
    {
        for (int coluna = 0; coluna < 10 - tamStr + 1; coluna++)
        {
            auxCol = coluna;
            aux = 0;
            while(PalavraPesquisada[aux] == mat[auxCol][linha] && aux < tamStr)
            {
                aux++;
                auxCol++;

            }
            if(aux == tamStr)
            {
                printf("Achou a palavra %s  cima --> baixo: lin %d  col: %d\n",PalavraPesquisada, coluna, linha );
                contPalavra++;
            }

        }

    }
    if (contPalavra > 0)
    {
        printf("\nTotal encontrado de %s eh de: %d\n\n", PalavraPesquisada, contPalavra);

    }
    else
    {
        printf ("\nPalavra nao encontrada no cima --> baixo\n");
    }

}
/*
void imprime() é um procedimento que exibe a matriz para o usuário. Matriz que pode ter sido digitada ou
formada aleatoriamente
*/
void imprima()
{

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            printf("%2c ", mat[i][j]);
        }
        printf("\n");
    }
}
/*solicitaPalavra() é o procedimento que pede ao usuario a palavra a ser pesquisada e armazena ela no vetor de char
PalavraPesquisada, que será comparada com a matriz futuramente*/
void solicitaPalavra()
{
    do
    {
        printf ("\nInforme a palavra a ser pesquisada com apenas 10 letras\n");
        scanf ("%s", PalavraPesquisada);
    }
    while(strlen(PalavraPesquisada) >10);

}

/*
esqDir é um procedimento que identifica as palavras no caça palavras no sentido esquerda-direita, utilizadando de estruturas de
repetição e estruturas condicionais para as comparação.
*/

void esqDir()
{
    imprima(); //invocando a função imprima para que mostre a matriz ao usuario.
    int tamStr = strlen(PalavraPesquisada), auxCol, aux, contPalavra=0; //criando as variaveis que irá precisar para a estrutura de repetição e condição.

    for (int linha = 0; linha < 10; linha++) //uma repetição que vai de linha=0 até linha < 10 para que ele percorra todas as linhas da matriz
    {
        for (int coluna = 0; coluna < 10 - tamStr + 1; coluna++)//uma repetição que  percorre todas as colunas da matriz, de 0 até < 10. Quando se usa (coluna < 10 - tamStr + 1), está falando para coluna ir 0 até o tamanho da palavra digitada,
//e o (+1) é porque no final do vetor sempre terá o caracter "\n" que é o do enter.
        {
            auxCol = coluna; //atribuindo o valor de coluna ao auxCol, onde vai começar por 0 e vai aumentando de 1 em 1.
            aux = 0; //atribuindo o valor de aux igual a 0, para efetuar a verificação.

            while(PalavraPesquisada[aux] == mat[linha][auxCol] && aux < tamStr)
            {
                aux++;//as variaveis estão sendo somadas mais 1.
                auxCol++;
                //aux é encrementado para +1 para realizar a busca pela letra no próximo indice de PalavraPesquisada.

            }
            /*Quando as condições satisfazerem o while, auxCol é somado a 1 para que a matriz procure na próxima coluna (mat [i] [auxCol+1]*/
            if(aux == tamStr)//Uma estrutura de condição para checar se o aux corresponde ao tamanho da palavra pesquisada. Se essa condição for satisfeita mostrará na tela a sua ocorrencia.
            {
                printf("Achou a palavra %s esq -->dir: lin %d  col: %d\n",PalavraPesquisada, linha, coluna);//imprimindo ao usuario a posição onde a palavra foi encontrada na matriz.
                contPalavra++;//essa variavel é responsavél por somar quantas palavras foram encontradas.
            }

        }
    }
    if (contPalavra > 0)// uma verificação para saber quantas palavras foram encontradas.
    {
        printf("\nTotal encontrado de %s eh de: %d\n", PalavraPesquisada, contPalavra);

    }
    else
    {
        printf ("\nPalavra nao encontrada!\n"); // se contPalavra for menor que 0 não haverá nenhuma palavra encontrada.
    }


}

void dirEsq()
{
    imprima();//imprimindo a função para que o usuario visualiza a palavra que ele pesquisou.
    int tamStr = strlen(PalavraPesquisada), auxCol, aux, contPalavra=0; //criando as variaveis locais para auxiliar na busca.

    for (int linha = 0; linha < 10; linha++) //uma estrutura de repetição para percorrer todas as linhas da matriz, onde linha se inicia com zero e vai até 10.
    {
        for (int coluna = 9; coluna >=0; coluna--)/*estrutura de repetição para percorrer todas as colunas da matriz, como é da direita para a esquerda,
        temos que ir decrementando a variavel coluna para que assim percorra no sentido dirEsq*/
        {
            auxCol = coluna;//auxCol recebe o valor de coluna
            aux = 0;
            while(PalavraPesquisada[aux] == mat[linha][auxCol] && aux < tamStr)/*Se as condições satisfazer aux é somado a +1 e o auxCol a -1,
            para que procure da direita para a esquerda.*/
            {
                aux++;//incrementando aux, para realizar a busca pelo proximo indice
                auxCol--;//decrementando auxCol

            }
            if(aux == tamStr)//caso aux tenha o tamanho da string, a palavra foi encontrada.
            {
                printf("Achou a palavra %s dir -->esq: lin %d  col: %d\n",PalavraPesquisada, linha, coluna);
                //mostrando ao usuario a palavra encontrada, e os indices.
                contPalavra++;
                //somando +1 a contPalavra, que está responsavel por armazenar a quantidade de palavra que foi encontrada.
            }


        }
    }
    if (contPalavra > 0)//caso contPalavra seja maior que zero, então encontrou a palavra.
    {
        printf("\nTotal encontrado de %s eh de: %d\n", PalavraPesquisada, contPalavra);

    }
    else//se for menor que zero não encontrou.
    {
        printf ("\nPalavra nao encontrada!\n");
    }

}
void baixoCima(){

    imprima();//exibindo a matriz ao usuario.
    int tamStr = strlen(PalavraPesquisada), auxCol = 0, aux = 0, contPalavra = 0;//criando as variaveis auxiliares e atribuindo valores a elas.

    for (int linha = 0; linha < 10; linha++)//for para percorrer linha por linha da matriz, començando em 0 e indo até 9.
    {
        for (int coluna = 9; coluna >= 0; coluna--)//Estrutura de repedição responsavel por percorrer as colunas da matriz, començando em 9 e decrementando ate 0.
        {
            auxCol = coluna;//atribuindo o valor da coluna para a variavel auxCol
            aux = 0;//atribuindo 0 para a variavel
            while(PalavraPesquisada[aux] == mat[auxCol][linha] && aux < tamStr)//Caso todas as condições seja satisfeitas, a variavel aux é somada a +1
            //e a variavel auxCol é subtraida a -1.
            {
                aux++;
                auxCol--;

            }
            if(aux == tamStr)//comparando os valores das duas variaveis, se a variavel aux tiver o mesmo valor da tamStr, quer dizer que a palavra foi encontrada.
            {
                printf("Achou a palavra %s  baixo --> cima: lin %d  col: %d\n",PalavraPesquisada, coluna, linha );//mostrando ao usuario as informações
                contPalavra++;//somando +1 a variavel contPalavra, que está responsavel por carregar o valor da quantidade de palavras encontradas.
            }

        }

    }

    if (contPalavra > 0)//caso a variavel seja maior que 0, irá mostrar o total de palavras encontrada.
    {
        printf("\nTotal encontrado de %s eh de: %d\n", PalavraPesquisada, contPalavra);

    }
    else//caso seja menor que 0 irá mostrar esse printf, dizendo que não encontrou nada
    {
        printf ("\nPalavra nao encontrada!\n");
    }
}

void cimaBaixo(){
    imprima();//chamando a função para imprimir a matriz.

    int tamStr = strlen(PalavraPesquisada), auxCol = 0, aux = 0, contPalavra = 0;//criando as variaveis locais

    for (int linha = 0; linha < 10; linha++)//for responsavel por percorrer as linhas da matriz
    {
        for (int coluna = 0; coluna < 10 - tamStr + 1; coluna++)//for para percorrer as colunas da matriz, indo de 0 até 10 - (o tamanho da palavra +1)

        {
            //atribuindo valores as variaveis
            auxCol = coluna;
            aux = 0;
            while(PalavraPesquisada[aux] == mat[auxCol][linha] && aux < tamStr)//se todas as condições forem realizadas, as variaveis serão somadas a +1
            {
                aux++;//incrementando as variaveis
                auxCol++;

            }
            if(aux == tamStr)//comparando o tamanho das duas variaveis, se for igual mostrará ao usuario o indice que foi encontrada
            {
                printf("Achou a palavra %s  cima --> baixo: lin %d  col: %d\n",PalavraPesquisada, coluna, linha );
                contPalavra++;//incrementando a variavel
            }

        }

    }

    if (contPalavra > 0)//se a variavel for maior que 0, então encontrou-se algo
    {
        printf("\nTotal encontrado de %s eh de: %d\n", PalavraPesquisada, contPalavra);

    }
    else//se for menor que 0 não encontrou nada.
    {
        printf ("\nPalavra nao encontrada!\n");
    }
}
void menuPesquisa()
{
    /*procedimento para mostrar as opções de pesquisa ao usuario*/

    printf("\n\n    OPCAO DE BUSCAS     \n");
    printf ("1- Esquerda -> Direita\n");
    printf ("2- Direita  -> Esquerda\n");
    printf ("3- Baixo    -> Cima\n");
    printf ("4- Cima     -> Baixo\n");
    printf("0- Voltar ao menu principal\n");
    printf("\n\nDigite a opcao: ");

}
void opBusca(int op)
{
    /*Procedimento para verificar o numero digitado e determinar qual a funcionalidade de cada numero, utilizando o swith case*/
    switch(op)
    {
        //caso o numero digitado seja 1, irá mostrar a pesquisa no sentido esquerda - direita
    case 1:
        esqDir();
        system("pause");
        printf("\n\n");
        break;
        //caso o numero digitado seja 2, irá mostrar a pesquisa no sentido direta - esquerda
    case 2:
        dirEsq();
        system("pause");
        printf("\n\n");
        break;
        //caso o numero digitado seja 3, irá mostrar a pesquisa no sentido baixo - cima
    case 3:
        baixoCima();
        system("pause");
        printf("\n\n");
        break;
        //caso o numero digitado seja 4, irá mostrar a pesquisa no sentido cima - baixo
    case 4:
        cimaBaixo();
        system("pause");
        printf("\n\n");
        break;
        //caso seja 0 retornará ao menu principal
    case 0:
        menuPrincial();
        break;
        //E se o numero for diferente dos citados acima, mostrará o printf abaixo
    default:
        printf("Opcao invalida\n");
        system("pause");
        break;
    }
    system("cls");//comando para limpar a tela
}

void opcao()
{
    //procedimento responsavel por ler as opções do menu principal
    int op;
    int opPes;

    scanf("%d", &op);

    //ultilizando a estrutura de repetição (while) e a de condição switch case.
    while(op)
    {

        switch (op)
        {

        //caso o numero digitado seja 1, irá chamar o procedimento leia().
        case 1:
            leia();
            system("pause");
            printf("\n\n");
            break;
        //caso o numero digitado seja 2, irá chamar o procedimento MatrizAleatoria().
        case 2:
            MatrizAleatoria();
            system("pause");
            printf("\n\n");
            break;

        //caso o numero digitado seja 3, irá chamar o procedimento imprima().
        case 3:
            imprima();
            system("pause");
            printf("\n\n");
            break;
        //caso o numero digitado seja 4, irá chamar os procedimentos imprima() e solicitaPalavra().
        case 4:
            imprima();
            solicitaPalavra();
            system("pause");
            printf("\n\n");
            break;
        //caso o numero digitado seja 5, irá chamar os procedimentos imprima(), menuPesquisa() e opBusca().
        case 5:
            imprima();
            menuPesquisa();
            scanf ("%i", &opPes);
            opBusca(opPes);
            system("pause");
            break;
        //caso o numero digitado seja 6, irá chamar o procedimento matTest().
        case 6:
            matTeste();
            system("pause");
            break;
        //caso seja 0 irá fechar o programa
        case 0:
            break;
            //return 0;
        //E se não for nenhum desses irá mostrar o printf.
        default:
            printf("Opcao invalida\n");
            system("pause");
            break;
        }
        system("cls");
        menuPrincial();
        scanf("%d", &op);
    }

}
int main()
{

    menuPrincial();//invocando o procedimento menu
    opcao();//invocando o procedimento opcao


    return 0;
}