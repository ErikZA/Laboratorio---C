#include <stdint.h>
#include <stdio.h>
#include <string.h>
/*
Trab_01) Considere o seguinte modelo de registro que representa uma pessoa:

• Nome (string)
• Data de nascimento (registro do tipo 'Data' – possui dia, mês e ano)
• CPF (string – contêm dígitos numéricos, pontos e tracinho)
OK
a) Crie um registro do tipo acima. Os campos nome e CPF são do tipo string.
A data de nascimento é um outro registro do tipo Data (dia, mês e ano) a ser definido também.
OK
b) Crie um algoritmo para calcular a idade da pessoa de acordo com sua data de nascimento.
OK
c) Crie um algoritmo também para validar o CPF da pessoa
(um CPF válido neste caso é se o seu tamanho é igual a 11 e se existem somente números na string).
OK
*/
/*

Desenvolvedor: Erik Henrique RA - 1749927

*/


typedef struct data DATA;

struct data{
    int dia;
    int mes;
    int ano;
};
typedef struct pessoa link;

struct pessoa{
    char nome[1111];
    DATA dataNasc;
    char cpf[14];
};

int validaCPF(link p){
    int i;
    //printf("caracter %d\n\n%s\n\n",strlen(p.cpf),p.cpf);
    if(strlen(p.cpf)==9){
        for(i=0;i<strlen(p.cpf);i++){
        if(isdigit(p.cpf[i])){
                //printf("caracter %c\n",p.cpf[i]);
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

link cadastraPessoa(link p){
        p.dataNasc.ano = 0;
        printf("|  1 - Digite o nome:                                        |\n");
        fflush(stdin);
        gets(p.nome);
        fflush(stdin);
        do{
        if(p.dataNasc.ano != 0){
        system("cls");
        printf("DADOS INVALIDOS\n");
        }
        printf("|  2 - Digite o dia do aniversario:                          |\n");
        scanf("%d",&p.dataNasc.dia);
        printf("|  3 - Digite o mes de seu aniversario:                      |\n");
        scanf("%d",&p.dataNasc.mes);
        printf("|  4 - Digite o ano em que nasceu:                           |\n");
        scanf("%d",&p.dataNasc.ano);
        }while(p.dataNasc.dia> 31 || p.dataNasc.mes>12 || p.dataNasc.ano<1900);
        printf("|  5 - Digite o numero do CPF com apenas numeros:            |\n");
        fflush(stdin);
        scanf("%s",p.cpf);
        fflush(stdin);
        if(validaCPF(p)){
            system("cls");
            printf("CPF VALIDADO\n\n");
            printf("Cadastro Realizado com sucesso\n");
            return p;
        }else{
            system("cls");
            printf("CPF IVALIDO CADASTRE NOVAMENTE\n\n");
            return cadastraPessoa(p);
        }
}

int calculaIdade(link p){
return 2018-p.dataNasc.ano;
}

void imprimePessoa(link p){
    printf("\n|  DADOS DO USUARIO     |\n");
    printf("|  Nome: %s             |\n", p.nome);
    printf("|  Dia: %d              |\n", p.dataNasc.dia);
    printf("|  Mes: %d              |\n", p.dataNasc.mes);
    printf("|  Ano: %d              |\n", p.dataNasc.ano);
    printf("|  CPF: %s              |\n", p.cpf);
    printf("|  Idade: %d anos       |\n\n", calculaIdade(p));

}

int main(){
    char opc;
    link pessoa;

    do{
        printf("\n");
        printf("|  1 - Testa progama                     |\n");
        printf("|  0 - Sair.                             |\n");
        printf("\n");
        scanf("%c",&opc);
        switch(opc){
            case '1':
                imprimePessoa(cadastraPessoa(pessoa));
                break;
            case '0':
                break;
            default:
                system("cls");
                printf("\nEntrada invalida\n");
        }
    }while(opc != '0');


return 0;
}
