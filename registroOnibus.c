#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include <conio.h>
#define TAM 2
#define PER 5
/*Trab_03) Defina um registro denoninado 'Onibus' que representa um um ônibus, que reúne as seguintes informações:
• Cidade de origem (string)
• Cidade de destino (string)
• Data (registro do tipo Data – possui dia, mês e ano)
• Hora (registro do tipo Hora – possui horas, minutos e segundos)
• Distância (real)
• Poltronas – vetor de registro do tipo 'Poltrona' de tamanho máximo 40 com as seguintes informações:
◦ Número da passagem (inteiro)
◦ Nome do passageiro (string)
◦ Sexo (caracter – M ou F)
Crie uma variável do tipo 'Onibus' e alimente seus dados (inclusive as poltronas, que pode
inicialmente ser testado com um número pequeno).
Em seguida construa algoritmos para as seguintes situações:
a) Defina um algoritmo para estimar o horário de chegada do ônibus e a duração da viagem em
minutos, considerando que o ônibus viaja em uma velocidade média de 80km/h.
b) Defina um algoritmo para calcular a porcentagem de ocupação e de poltronas livres do ônibus.
c) Defina um algoritmo para calcular a porcentagem de passageiros do sexo masculino e do sexo feminino do ônibus.
d) Defina um algoritmo para imprimir de modo organizado as informações do ônibus e as
informações de seus respectivos passageiros. */

/*
Desenvolvedor: Erik Henrique RA - 1749927
*/

typedef struct hora HORA;

struct hora{
    int hora;
    int minutos;
    int segundos;
};

typedef struct poltrona POL;

struct poltrona{
    int passagem;
    char passageiro[1111];
    char sexo;
};

typedef struct data DATA;

struct data{
    int dia;
    int mes;
    int ano;
    HORA time;
};

typedef struct onibus link;

struct onibus{
    char cidadeOrigem[1111];
    DATA data;
    char cidadeDestino[11111];
    float distancia;
    POL poltrona[TAM];
};


link cadastraRegistro(link r, int *ocupado, int cont){
        int check= 1;
        r.data.ano = 0;
        system("cls");
        printf("\n|  1 - Cidade de Origem:                                |\n");
        fflush(stdin);
        gets(r.cidadeOrigem);
        fflush(stdin);
        printf("|  2 - Cidade de Destino:                                |\n");
        fflush(stdin);
        gets(r.cidadeDestino);
        fflush(stdin);
        printf("|  3 - Digite a Distancia entre as cidades:              |\n");
        scanf("%f",&r.distancia);
        do{
        if(r.data.ano != 0){
        system("cls");
        printf("DADOS DO EMBARQUE IVALIDO\n");
        }
        printf("|  4 - Digite o dia do Embarque menor que 31:            |\n");
        scanf("%d",&r.data.dia);
        printf("|  5 - Digite o Mes do Embarque menor que 13:            |\n");
        scanf("%d",&r.data.mes);
        printf("|  6 - Digite o Ano do Embarque maior que 2000:          |\n");
        scanf("%d",&r.data.ano);
        printf("|  7 - Digite a Hora do Embarque menor que 24:           |\n");
        scanf("%d",&r.data.time.hora);
        printf("|  8 - Digite os minutos do Embarque menor que 60:       |\n");
        scanf("%d",&r.data.time.minutos);
        printf("|  9 - Digite a Segundos do Embarque:                    |\n");
        scanf("%d",&r.data.time.segundos);
        }while(r.data.dia>30 || r.data.ano<2000 || r.data.mes>12 || r.data.time.hora>23 || r.data.time.minutos>60);
        system("cls");
        ocupado[cont] = 0;
        printf("\n|-----------CADASTRO BEM SUCEDIDO!!----------|\n");
        return r;
}

int cadastraPassageiros2(link *p, int cont, int opc){
    system("cls");
    int i, check;
    int var = TAM-cont;
    for(i=0;i<var;i++){
        check = 1;
        printf("|  1 - Digite a Passagem:                                  |\n");
        scanf("%d",&p[opc].poltrona[i].passagem);
        printf("|  2 - Digite o nome do passageiro:                        |\n");
        fflush(stdin);
        gets(p[opc].poltrona[i].passageiro);
        fflush(stdin);
        do{
        printf("|  3 - Digite o sexo(M para masculino, F para Feminino):   |\n");
        fflush(stdin);
        scanf("%c",&p[opc].poltrona[i].sexo);
        fflush(stdin);
        if(p[opc].poltrona[i].sexo == 'M' || p[opc].poltrona[i].sexo == 'F'){
                check = 0;
            }
        }while(check);
        cont++;
        while(check != 4){
        printf("|  4 - Digite 2 para continuar 4 para sair:               |\n");
        scanf("%d",&check);
        if(check == 2 || check == 4)
            break;
        }
        system("cls");
        if(check == 4){
            //system("pause");
            return cont;
        }
    }
    return cont;
}

void cadastraPassageiros( link *p, int ocupado[], int size ){
    int i,cont=0, opc;
            printf("\n|------------DADOS DOS ONIBUS CADASTRADOS-----------|\n");
    for(i=0; i< size; i++){
            printf("|Registro %d: Origem: %s - Destino: %s - Partida: %d/%d/%d - %d:%d:%d    - Vagas: %d  |\n", cont,
                   p[i].cidadeOrigem, p[i].cidadeDestino, p[i].data.dia, p[i].data.mes, p[i].data.ano,
                   p[i].data.time.hora, p[i].data.time.minutos, p[i].data.time.segundos, TAM-ocupado[i]);
            cont++;
        }
            printf("\n|  Quantidade de registros %d                 |\n\n",cont);
            if(cont == 0)
                return;
            printf("\n|  Entre com o registro que deseja preencher: |\n");
            scanf("%d", &opc);

            if(opc>=size || opc<0){
                system("cls");
                printf("\n|  Entrada invalida:                          |\n");
                cadastraPassageiros(p,ocupado,size);
            }
            else{
                if(ocupado[size] == TAM)
                    printf("\n|  Onibus Lotado:                             |\n");
                else
                    ocupado[opc] = cadastraPassageiros2(p,ocupado[opc],opc);
            }
}

void listaOcupacao( link *p, int ocupado[], int size ){
    int i,cont=0;
            printf("\n|------------DADOS DOS ONIBUS CADASTRADOS-----------|\n");
    for(i=0; i< size; i++){
            printf("|Registro %d: Origem: %s - Destino: %s - Partida: %d/%d/%d - %d:%d:%d    - Vagas: %d  |\n", cont,
                   p[i].cidadeOrigem, p[i].cidadeDestino, p[i].data.dia, p[i].data.mes, p[i].data.ano,
                   p[i].data.time.hora, p[i].data.time.minutos, p[i].data.time.segundos, TAM-ocupado[i]);
            printf("|Registro %d: Ocupado: %d%% - Livre: %d%%  |\n\n", cont, ocupado[i]*100/TAM, ((ocupado[i]-TAM)*-1)*100/TAM);
            cont++;
        }
            printf("\n|  Quantidade de registros %d                 |\n\n",cont);
}

int contaHomens(link p, int ocupado[], int size){
    int i, cont=0;
    for(i=0;i<ocupado[size];i++){
          //  printf("%d xx\n\n",p.poltrona[i].passagem);
        if(p.poltrona[i].sexo == 'M'){
            cont++;
        }
    }
    if(cont==0)
        return 0;
    else
        return cont*100/ocupado[size];
}

int contaMulheres(link p, int ocupado[], int size){
    int i, cont=0;
    for(i=0;i<ocupado[size];i++){
            //printf("%d xx\n\n",p.poltrona[i].passagem);
        if(p.poltrona[i].sexo == 'F'){
            cont++;
        }
    }
    if(cont==0)
        return 0;
    else
        return cont*100/ocupado[size];
}

void listaHomensMulhers( link *p, int ocupado[], int size ){
    int i,cont=0;
            printf("\n|------------DADOS DOS ONIBUS CADASTRADOS-----------|\n");
    for(i=0; i< size; i++){
            printf("|Registro %d: Origem: %s - Destino: %s - Partida: %d/%d/%d - %d:%d:%d    - Vagas: %d  |\n", cont,
                   p[i].cidadeOrigem, p[i].cidadeDestino, p[i].data.dia, p[i].data.mes, p[i].data.ano,
                   p[i].data.time.hora, p[i].data.time.minutos, p[i].data.time.segundos, TAM-ocupado[i]);
            printf("|Registro %d: Homens: %d%% - Mulheres: %d%%  |\n\n", cont,
                   contaHomens(p[i],ocupado,i), contaMulheres(p[i],ocupado,i));
            cont++;
        }
            printf("\n|  Quantidade de registros %d                 |\n\n",cont);
}

void imprimePoltronas(link *p,int ocupado[], int i){
    int x;
    for(x=0; x<ocupado[i];x++){
        printf("\n|_____Poltrona %d_____|\n",x+1);
        printf("| Passagem: %d          |\n",p[i].poltrona[x].passagem);
        printf("| Passageiro: %s        |\n",p[i].poltrona[x].passageiro);
        printf("| Sexo: %c              |\n",p[i].poltrona[x].sexo);
        printf("|-----------------------|");
    }
}

void listaTodos(link *p,int ocupado[], int size){
    int i,cont=0;
            printf("\n|------------DADOS DOS ONIBUS CADASTRADOS-----------|\n");
    for(i=0; i< size; i++){
            printf("\n\n|Registro %d: Origem: %s - Destino: %s - Partida: %d/%d/%d - %d:%d:%d    - Vagas: %d  |\n", cont,
                   p[i].cidadeOrigem, p[i].cidadeDestino, p[i].data.dia, p[i].data.mes, p[i].data.ano,
                   p[i].data.time.hora, p[i].data.time.minutos, p[i].data.time.segundos, TAM-ocupado[i]);
                   imprimePoltronas(p,ocupado,i);
            cont++;
        }
            printf("\n\n|  Quantidade de registros %d                 |\n\n",cont);
}

void calcula(link *p, int size){
    int i, cont;
    int minutos =  60*(p[size].distancia/80);
    int horas = (p[size].distancia/80) +1;

    if(p[size].data.time.hora + horas > 24){
        for(horas;0<horas;horas--){
            p[size].data.time.hora++;
            if(p[size].data.time.hora == 24){
                p[size].data.dia++;
                p[size].data.time.hora = 0;
                if(p[size].data.dia == 31){
                    p[size].data.mes++;
                    p[size].data.dia = 1;
                    if(p[size].data.mes == 13){
                        p[size].data.mes = 1;
                        p[size].data.ano++;
                    }
                }
            }
        }
    } else{
        p[size].data.time.hora + horas;
    }
    printf("| DURACAO DA VIAGEM: %d MINUTOS                       |\n", minutos);
    printf("| PREVISAO ESTIMADA DE CHEGADA  %d/%d/%d - %d:%d:%d   |\n",
            p[size].data.dia, p[size].data.mes, p[size].data.ano,
            p[size].data.time.hora, p[size].data.time.minutos, p[size].data.time.segundos);
}


void listaChegada( link *p, int ocupado[], int size ){
     int i,cont=0;
            printf("\n|------------DADOS DOS ONIBUS CADASTRADOS-----------|\n");
    for(i=0; i< size; i++){
            printf("|Registro %d: Origem: %s - Destino: %s - Partida: %d/%d/%d - %d:%d:%d    - Vagas: %d  |\n", cont,
                   p[i].cidadeOrigem, p[i].cidadeDestino, p[i].data.dia, p[i].data.mes, p[i].data.ano,
                   p[i].data.time.hora, p[i].data.time.minutos, p[i].data.time.segundos, TAM-ocupado[i]);
            calcula(p,i);
            cont++;
        }
            printf("\n|  Quantidade de registros %d                 |\n\n",cont);
}

int main(){

    link persist[PER], registro;
    char opc;
    int cont=0,i, ocupado[PER];

    if(TAM<40)
        printf("ALTERE A VARIAVEL GLOBAL PARA UTILIZAR 100%% OU OS 40 REGISTROS \nATUALMENTE ESTA DEFINIDA EM %d REGISTROS PARA POLTRONAS\nO VETOR DE PERSISTENCIA PODE SER ALTERADO COMO DESEJAR\nATUALMENTE SUPORTA 50 REGISTROS\n",TAM);

     do{
        for(i =0; i<PER; i++)
            printf("BOSTAS %d\n", ocupado[i]);

        printf("\n");
        printf("|  1 - Cadastrar Onibus                          |\n");
        printf("|  2 - Cadastrar Passageiros                     |\n");
        printf("|  3 - Percentual Ocupacao do veiculo            |\n");
        printf("|  4 - Percentual de Homens e Mulheres           |\n");
        printf("|  5 - Imprimir Informacoes dos Onibus           |\n");
        printf("|  6 - Calcular horario de chegada.              |\n");
        printf("|  0 - Sair.                                     |\n");
        printf("\n");
        fflush(stdin);
        scanf("%c",&opc);
        fflush(stdin);
        switch(opc){
            case '1':
                if(cont < PER){
                    persist[cont] = cadastraRegistro(registro,ocupado,cont);
                    cont++;
                } else {
                    system("cls");
                    printf("Persistencia cheia.\n\n");
                }
                break;
            case '2':
                system("cls");
                cadastraPassageiros(persist,ocupado,cont);
                break;
            case '3':
                system("cls");
                listaOcupacao(persist,ocupado,cont);
                break;
            case '4':
                system("cls");
                listaHomensMulhers(persist,ocupado,cont);
                break;
            case '5':
                system("cls");
                listaTodos(persist,ocupado,cont);
                break;
            case '6':
                system("cls");
                listaChegada(persist,ocupado,cont);
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
