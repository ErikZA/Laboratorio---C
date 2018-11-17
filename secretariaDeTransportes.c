#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>


/*
Trab_02) Para o controle de veículos que circulam em uma determinada cidade, a Secretaria dos
Transportes criou um registro padrão de veículos com as seguintes informações:

• Proprietário (string - indicando o nome)
• Combustível (string - álcool, diesel ou gasolina)
• Modelo (string)
• Cor (string)
• Número de chassi (inteiro)
• Ano (inteiro)
• Placa (3 primeiros valores alfabéticos e os 4 restantes números)
OK
Construa um algoritmo que leia uma quantidade arbitrária de veículos, limitado a 20. Em seguida:

a) Liste todos os proprietários cujos carros são do ano de 1980 ou posterior e que sejam movidos a diesel.
OK
b) Liste todos os proprietários cujos carros são movidos a álcool ou a gasolina e que sejam do ano de 2000 para cima.
OK
c) Liste todos os veículos cujas placas comecem com a letra 'A' e que o último dígito da placa seja um número par.
OK
*** Sugestão: considere a informação da placa como um outro registro
*/


typedef struct registro link;

struct registro{
    char proprietario[1111];
    char combustivel[1111];
    char modelo[1111];
    char cor[1111];
    int chassi;
    int ano;
    char placa[7];
};

int validaPlaca(link r){
    int i;
    //printf("caracter %d\n\n%s\n\n",strlen(p.cpf),p.cpf);
    if(strlen(r.placa)==7){
        for(i=3;i<strlen(r.placa);i++){
        if(isdigit(r.placa[i])){
                //printf("caracter %c\n",r.placa[i]);
            continue;
        } else{
            return 0;
        }
        }

        for(i=0;i<3;i++){
        if(isalpha(r.placa[i])){
                //printf("caracter %c\n",r.placa[i]);
            continue;
        } else{
            return 0;
        }
        }
    } else {
        return 0;
    }
    return 1;
}

link cadastraRegistro(link r){
        int check= 1;
        printf("\n|  1 - Digite o nome:                                          |\n");
        fflush(stdin);
        gets(r.proprietario);
        fflush(stdin);
        do{
        printf("|  2 - Digite o Combustivelo 'alcool', 'gasolina' ou 'diesel'  |\n");
        fflush(stdin);
        gets(r.combustivel);
        fflush(stdin);
        if( strcmp(r.combustivel,"alcool")==0 ||
            strcmp(r.combustivel,"gasolina")==0 ||
            strcmp(r.combustivel,"diesel")==0)
            {
                check = 0;
            }
        }while(check);
        printf("|  3 - Digite o modelo:                                        |\n");
        fflush(stdin);
        gets(r.modelo);
        fflush(stdin);
        printf("|  4 - Digite a cor:                                           |\n");
        fflush(stdin);
        gets(r.cor);
        fflush(stdin);
        printf("|  4 - Digite o chassi:                                        |\n");
        scanf("%d",&r.chassi);
        printf("|  4 - Digite o ano:                                           |\n");
        scanf("%d",&r.ano);
        printf("|  5 - Digite a placa, somente 3 letras e 4 numeros:           |\n");
        fflush(stdin);
        gets(r.placa);
        fflush(stdin);

        if(validaPlaca(r)){
            system("cls");
            printf("PLACA VALIDA\n\n");
            printf("Cadastro Realizado com sucesso\n");
            return r;
        }else{
            system("cls");
            printf("PLACA IVALIDA CADASTRE NOVAMENTE\n\n");
            return cadastraRegistro(r);
        }
}

void lista1980(link *p, int size){
    int i,cont=0;
    system("cls");
            printf("\n|  Registros de 1980 e Diesel |\n\n");
    for(i=0; i< size; i++){
        if(p[i].ano >= 1980 && strcmp(p[i].combustivel,"diesel" ) == 0){
            printf("|  DADOS DO USUARIO           |\n");
            printf("|  Proprietario: %s           |\n", p[i].proprietario);
            printf("|  Cor: %s                    |\n", p[i].cor);
            printf("|  Modelo: %s                 |\n", p[i].modelo);
            printf("|  Combustivel: %s            |\n", p[i].combustivel);
            printf("|  Ano: %d                    |\n", p[i].ano);
            printf("|  Chassi: %d                 |\n", p[i].chassi);
            printf("|  Placa: %s                  |\n\n", p[i].placa);
            cont++;
        }
    }
            printf("|  Quantidade de registros %d |\n\n",cont);
}

void listaAlcool(link *p, int size){
    int i,cont=0;
    system("cls");
            printf("\n|  Registros Acima de 2000, gasol. e Alcool |\n\n");
    for(i=0; i< size; i++){
        if( p[i].ano > 2000 &&
            strcmp(p[i].combustivel,"alcool" ) == 0 ||
            strcmp(p[i].combustivel,"gasolina" ) == 0){
            printf("|  DADOS DO USUARIO           |\n");
            printf("|  Proprietario: %s           |\n", p[i].proprietario);
            printf("|  Cor: %s                    |\n", p[i].cor);
            printf("|  Modelo: %s                 |\n", p[i].modelo);
            printf("|  Combustivel: %s            |\n", p[i].combustivel);
            printf("|  Ano: %d                    |\n", p[i].ano);
            printf("|  Chassi: %d                 |\n", p[i].chassi);
            printf("|  Placa: %s                  |\n\n", p[i].placa);
            cont++;
        }
    }
            printf("|  Quantidade de registros %d |\n\n",cont);
}

void listaPlacaA(link *p, int size){
    int i,cont=0;
    int digt7;
    system("cls");
    for(i=0; i< size; i++){
        digt7 =  p[i].placa[6] - '0';
        //printf("%d\n%c\n", digt7,p[i].placa[0]);
        if(digt7%2==0 && p[i].placa[0]=='a' || p[i].placa[0]=='A'){
            printf("|  DADOS DO USUARIO           |\n");
            printf("|  Proprietario: %s           |\n", p[i].proprietario);
            printf("|  Cor: %s                    |\n", p[i].cor);
            printf("|  Modelo: %s                 |\n", p[i].modelo);
            printf("|  Combustivel: %s            |\n", p[i].combustivel);
            printf("|  Ano: %d                    |\n", p[i].ano);
            printf("|  Chassi: %d                 |\n", p[i].chassi);
            printf("|  Placa: %s                  |\n\n", p[i].placa);
            cont++;
        }
    }
            printf("|  Quantidade de registros %d |\n\n",cont);
}

int main(){

    link persist[20], registro;
    char opc;
    int cont=0;

     do{
        printf("\n");
        printf("|  1 - Cadastrar                                                   |\n");
        printf("|  2 - Listar usuarios 1980 e movidos a diesel                     |\n");
        printf("|  3 - Lista Veicolos ha Alcool ou gasolina acima de 2000          |\n");
        printf("|  4 - Lista veicolos Placa inicio 'A' e ultimo numero a PAR       |\n");
        printf("|  0 - Sair.                                                       |\n");
        printf("\n");
        fflush(stdin);
        scanf("%c",&opc);
        fflush(stdin);
        switch(opc){
            case '1':
                if(cont < 20){
                    persist[cont] = cadastraRegistro(registro);
                    cont++;
                } else {
                    system("cls");
                    printf("Persistencia cheia.\n\n");
                }
                break;
            case '2':
                lista1980(persist,cont);
                break;
            case '3':
                listaAlcool(persist,cont);
                break;
            case '4':
                listaPlacaA(persist,cont);
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
