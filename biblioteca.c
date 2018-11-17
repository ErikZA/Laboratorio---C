#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include <conio.h>
#include <stdlib.h>
#define TAM 500
/*Trab_04) Uma determinada biblioteca possui obras de ciências exatas, humanas e biomédicas,
totalizando no máximo 1500 volumes, com no máximo 500 de cada área. O proprietário resolveu
informatizá-la e para tal agrupou as informações sobre cada livro no seguinte formato:
• Código de catalogação
• Nome da obra (string)
• Nome do autor (string)
• Editora (string)
• Número de páginas (inteiro)
• Doado ("booleano" – representa sim ou não)

Defina um registro que reúna todas as informações de todas as
obras em vetores distintos para cada área. Para facilitar, o usuário pode testar com um número pequeno de
livros para cada área, podendo ser definido pelo usuário. Em seguida:

a) Elabore um algoritmo que realize consulta de informações assumindo que um certo número de obras já foi
inserido em uma determinada área. O usuário deve fornecer o código da obra e sua área e mostrar uma mensagem dizendo
se aquela obra existe ou não no catálogo.
b) Escreva um algoritmo que liste todas as obras de cada área que representem livros doados.
c) Escreva um algoritmo que liste todos os livros que sejam comprados e o número de páginas se encontre entre 100 e 300.
d) Elabore um trecho de algoritmo que faça a alteração de um registro.
Para tal, o usuário fornece o código de busca e a área. Lembre-se que somente pode ser alterado um livro existente. */

/*
Desenvolvedor: Erik Henrique RA - 1749927
*/

typedef struct livro LIVRO;

struct livro{
    int cod;
    char nomeObra[111];
    char nomeAutor[111];
    char editora[111];
    int paginas;
    bool doado;
};

typedef struct ramo link;

struct ramo{
    LIVRO medicas[TAM];
    LIVRO humanas[TAM];
    LIVRO exatas[TAM];
};

int valida(LIVRO *r, int size, int cod){
    int i;
    for(i=0;i<size;i++){
        if(r[i].cod == cod){
            return 0;
        }
    }
    return 1;
}

LIVRO cadastraRegistro(LIVRO *r, int size){
        LIVRO l;
        int opc;
        do{
        printf("\n|  1 - Codigo de Catalago:                  |\n");
        scanf("%d",&l.cod);
        if(valida(r,size,l.cod) != 1){
            system("cls");
            printf("\n| Ja ha um cadastro com este codigo nesta area, tente outro|\n");
            continue;
        } else {
            break;
        }
        }while(1);
        printf("|  2 - Nome Obra:                           |\n");
        fflush(stdin);
        gets(l.nomeObra);
        fflush(stdin);
        printf("|  3 - Nome Autor:                          |\n");
        fflush(stdin);
        gets(l.nomeAutor);
        fflush(stdin);
        printf("|  4 - Editora:                             |\n");
        fflush(stdin);
        gets(l.editora);
        fflush(stdin);
        printf("|  5 - Paginas:                             |\n");
        scanf("%d",&l.paginas);
        do{
        printf("|  6 - Doaodo? (1 sim) ou (0 nao):          |\n");
        scanf("%d",&opc);
        if(opc != 0 && opc != 1){
            printf("|  Entrada Invalida  |\n");
            continue;
        } else {
            break;
        }
        }while(1);
        if(opc == 1)
            l.doado = true;
        else
            l.doado = false;
        system("cls");
        printf("\n|-----------CADASTRO BEM SUCEDIDO!!----------|\n");
        return l;
}

void modificaRegistro(LIVRO *r, LIVRO l,int size){
        int opc,i,position;
        for(i=0;i<size;i++){
            if(r[i].cod == l.cod){
                position = i;
            }
        }
        do{
        printf("\n|  1 - Codigo de Catalago:                  |\n");
        scanf("%d",&l.cod);
        if(valida(r,size,l.cod) != 1){
            system("cls");
            printf("\n| Ja ha um cadastro com este codigo nesta area, tente outro|\n");
            continue;
        } else {
            break;
        }
        }while(1);
        printf("|  2 - Nome Obra:                           |\n");
        fflush(stdin);
        gets(l.nomeObra);
        fflush(stdin);
        printf("|  3 - Nome Autor:                          |\n");
        fflush(stdin);
        gets(l.nomeAutor);
        fflush(stdin);
        printf("|  4 - Editora:                             |\n");
        fflush(stdin);
        gets(l.editora);
        fflush(stdin);
        printf("|  5 - Paginas:                             |\n");
        scanf("%d",&l.paginas);
        do{
        printf("|  6 - Doaodo? (1 sim) ou (0 nao):          |\n");
        scanf("%d",&opc);
        if(opc != 0 && opc != 1){
            printf("|  Entrada Invalida  |\n");
            continue;
        } else {
            break;
        }
        }while(opc);
        if(opc == 1)
            l.doado = true;
        else
            l.doado = false;
        system("cls");
        r[position] = l;
        printf("\n|-----------DADOS ALTERADOS COM SUCESSO!!----------|\n");
}

void consultaRegistro(LIVRO *r, int size, int cod){
    int i;
    system("cls");
    for(i=0;i<size;i++){
        if(cod == r[i].cod){
            printf("| Livro Encontrado |\n");
            printf("|   COD: %d        |\n",r[i].cod);
            printf("|   OBRA: %s       |\n",r[i].nomeObra);
            printf("|   AUTOR: %s      |\n",r[i].nomeAutor);
            printf("___________________________\n");
            return;
        }
    }
    printf("| Nenhum Livro encontrado com este codigo nesta Area |\n");
}

LIVRO consultaRegistro2(LIVRO *r, int size, int cod){
    int i;
    system("cls");
    for(i=0;i<size;i++){
        if(cod == r[i].cod){
            printf("\n| Livro Doados        |\n");
            printf("|   COD: %d           |\n",r[i].cod);
            printf("|   OBRA: %s          |\n",r[i].nomeObra);
            printf("|   AUTOR: %s         |\n",r[i].nomeAutor);
            printf("|   EDITORA: %s       |\n",r[i].editora);
            printf("|   PAGINAS: %d       |\n",r[i].paginas);
            printf("___________________________\n | PRONTO PARA EDITAR |\n");
            return r[i];
        }
    }
    printf("| Nenhum Livro encontrado com este codigo nesta Area |\n");
}

void listaDoados(LIVRO *r, int size){
    int i;
    //system("cls");
    for(i=0;i<size;i++){
        if(r[i].doado){
            printf("\n| Livro Doados        |\n");
            printf("|   COD: %d           |\n",r[i].cod);
            printf("|   OBRA: %s          |\n",r[i].nomeObra);
            printf("|   AUTOR: %s         |\n",r[i].nomeAutor);
            printf("|   EDITORA: %s       |\n",r[i].editora);
            printf("|   PAGINAS: %d       |\n",r[i].paginas);
        }
    }
}

void listaDoadosComprados(LIVRO *r, int size){
    int i;
    //system("cls");
    for(i=0;i<size;i++){
        if(r[i].doado){

        }else{
            if(r[i].paginas>100 && r[i].paginas<300 ){
                printf("\n| Livro Comprados de 100 a 300 PG   |\n");
                printf("|   COD: %d                           |\n",r[i].cod);
                printf("|   OBRA: %s                          |\n",r[i].nomeObra);
                printf("|   AUTOR: %s                         |\n",r[i].nomeAutor);
                printf("|   EDITORA: %s                       |\n",r[i].editora);
                printf("|   PAGINAS: %d                       |\n",r[i].paginas);
            }
        }
    }
}

void novaCapacidade(int  *TH, int *TE, int *TM){
    do{
    printf("|---Defina a capacidade de Aramzenamento maximo 500 registros por area---|\n");
    printf("|---Registro de Humanas---|\n");
    scanf("%d",TH);
    printf("|---Registro de Exatas---|\n");
    scanf("%d",TE);
    printf("|---Registro de Biomedicas---|\n");
    scanf("%d",TM);
    if(*TH> 500 || *TM > 500 || *TE > 500){
        system("cls");
        printf("Algum registro excedeu a capacidade\n");
        continue;
    } else {
        break;
    }
    }while(1);
    printf("|--CAPACIDADES DEFINIDAS--|\n");
    printf("| HUMANS %d               |\n", *TH);
    printf("| EXATAS %d               |\n", *TE);
    printf("| BIOMEDICAS %d           |\n", *TM);
    return;

}

int main(){
    int *TH = malloc(sizeof(int)), *TE = malloc(sizeof(int)), *TM = malloc(sizeof(int));
    link registro;
    char opc, area[111];
    int contH=0, contE=0, contM=0, cod;
    novaCapacidade(TH,TE,TM);
     do{
        printf("\n");
        printf("|  1 - Cadastrar Livro Humanas                   |\n");
        printf("|  2 - Cadastrar Livro Exatas                    |\n");
        printf("|  3 - Cadastrar Livro biomedicas                |\n");
        printf("|  4 - Consultar Obras existentes                |\n");
        printf("|  5 - Livros doados por Area                    |\n");
        printf("|  6 - Alterar Registro                          |\n");
        printf("|  7 - Alterar Capacidade de Armazenamento.      |\n");
        printf("|  8 - Livros comprados de 100 a 300 paginas.    |\n");
        printf("|  0 - Sair.                                     |\n");
        printf("\n");
        fflush(stdin);
        scanf("%c",&opc);
        fflush(stdin);
        switch(opc){
            case '1':
                if(contH < *TH){
                    registro.humanas[contH] = cadastraRegistro(registro.humanas,contH);
                    contH++;
                } else {
                    system("cls");
                    printf("Persistencia cheia.\n\n");
                }
                break;
            case '2':
                 if(contE < *TE){
                    registro.exatas[contE] = cadastraRegistro(registro.exatas,contE);
                    contE++;
                } else {
                    system("cls");
                    printf("Persistencia cheia.\n\n");
                }
                break;
            case '3':
                 if(contM < *TM){
                    registro.medicas[contM] = cadastraRegistro(registro.medicas,contM);
                    contM++;
                } else {
                    system("cls");
                    printf("Persistencia cheia.\n\n");
                }
                break;
            case '4':
                system("cls");
                printf("|   ENTRE COM O CODIGO DA OBRA                                 |\n");
                scanf("%d", &cod);
                do{
                printf("|   ENTRE COM A AREA DE ESTUDO 'exatas' - 'humanas' - medicas  |\n");
                fflush(stdin);
                gets(area);
                fflush(stdin);
                if(strcmp(area,"exatas")==0 || strcmp(area,"humanas")==0 || strcmp(area,"medicas")== 0)
                   break;
                else{
                    printf("|  ENTRADA INVALIDA PARA AREA DE PESQUISA  |\n");
                    continue;
                }
                }while(area);
                if(strcmp(area,"exatas")==0)
                    consultaRegistro(registro.exatas,contE,cod);
                    if(strcmp(area,"humanas")==0)
                        consultaRegistro(registro.humanas,contH,cod);
                        if(strcmp(area,"medicas")== 0)
                            consultaRegistro(registro.medicas,contM,cod);
                break;
            case '5':
                system("cls");
                printf("\n--------------------------\nAREA DE EXATAS\n");
                listaDoados(registro.exatas,contE);
                printf("\n--------------------------\n");
                printf("\n--------------------------\nAREA DE HUMANAS\n");
                listaDoados(registro.humanas,contH);
                printf("\n--------------------------\n");
                printf("\n--------------------------\nAREA DE BIOMEDICAS\n");
                listaDoados(registro.medicas,contM);
                printf("\n--------------------------\n");
                break;
            case '6':
                system("cls");
                printf("|   ENTRE COM O CODIGO DA OBRA                                 |\n");
                scanf("%d", &cod);
                do{
                printf("|   ENTRE COM A AREA DE ESTUDO 'exatas' - 'humanas' - medicas  |\n");
                fflush(stdin);
                gets(area);
                fflush(stdin);
                if(strcmp(area,"exatas")==0 || strcmp(area,"humanas")==0 || strcmp(area,"medicas")== 0)
                   break;
                else{
                    printf("|  ENTRADA INVALIDA PARA AREA DE PESQUISA  |\n");
                    continue;
                }
                }while(area);
                if(strcmp(area,"exatas")==0)
                    modificaRegistro(registro.exatas,consultaRegistro2(registro.exatas,contE,cod),contE);
                    if(strcmp(area,"humanas")==0)
                        modificaRegistro(registro.humanas,consultaRegistro2(registro.humanas,contH,cod),contH);
                        if(strcmp(area,"medicas")== 0)
                            modificaRegistro(registro.medicas,consultaRegistro2(registro.medicas,contM,cod),contM);
                break;
            case '7':
                system("cls");
                printf("\nPODE-SE PERDER REGISTROS COM ESSA OPERACAO\n");
                novaCapacidade(TH,TE,TM);
                break;
            case '8':
                system("cls");
                printf("\n--------------------------\nAREA DE EXATAS\n");
                listaDoadosComprados(registro.exatas,contE);
                printf("\n--------------------------\n");
                printf("\n--------------------------\nAREA DE HUMANAS\n");
                listaDoadosComprados(registro.humanas,contH);
                printf("\n--------------------------\n");
                printf("\n--------------------------\nAREA DE BIOMEDICAS\n");
                listaDoadosComprados(registro.medicas,contM);
                printf("\n--------------------------\n");
                break;
            case '0':
                break;
            default:
                system("cls");
                printf("\nEntrada invalida\n");
                break;
        }
    }while(opc != '0');


return 0;
}
