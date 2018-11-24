#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include <conio.h>
//#define TAM 2
#define PER 5

/*Trab_05) Considerar um sistema de controle de estoque contendo:

a) produto (id do produto; nome do produto; preco; qtde estoque);
b) cliente (id do cliente; nome do cliente; cpf);
c) item (produto comprado; quantidade comprada; valor);
d) nota fiscal (número da nota; id do cliente; itens [vetor de até 5]).

- No estabelecimento comercial pode existir até 50 produtos.
- No estabelecimento comercial pode existir até 20 clientes.
- Um mesmo cliente pode realizar várias compras.


- Criar um menu de opções para o bom funcionamento do sistema (pode criar submenus).
- Validar campos.
- ids e número da nota são autoincremental ("eterno").

Funções obrigatórias:
1) função para cadastrar produtos;
2) função para consultar produtos, por nome e por id;
3) função para excluir produto;
4) função para listar todos os produtos (ordem alfabética);

5) função para cadastrar cliente;
6) função para consultar clientes, por nome e por id;
7) função para excluir cliente;
8) função para listar todos os clientes (ordem alfabética);
9) função para validar CPF do cliente.

10) função para fazer venda. Lembrar de descontar do estoque. Não pode vender quantidades que não existe em estoque; */

/*
Desenvolvedor: Erik Henrique RA - 1749927
*/

typedef struct produto PROD;

struct produto{
    int id;
    char nome[1111];
    float preco;
    int quantidade;
} ;

typedef struct cliente CLI;

struct cliente{
    int id;
    char nome[1111];
    char cpf[111]
} ;

typedef struct item ITEM;

struct item{
    PROD  produto;
    int   quantidadeCompra;
    float  valorCompra;
} ;

typedef struct nota NOTA;

struct nota{
    int numero;
    CLI   cliente;
    ITEM  item[5];
} ;

ITEM novoItem(PROD *r, int size, int *contT){
        ITEM item;
        PROD link;
        char nome[1111];
        int id, i, check=1, quant, pos;
        //system("cls");
        do{
        printf("\n|  1 - Nome do Produto:            |\n");
        fflush(stdin);
        gets(nome);
        fflush(stdin);
        printf("|  2 - ID Produto:                   |\n");
        scanf("%d", &id);
        for(i=0; i< size; i++){
            if(id == r[i].id && strcmp(nome,r[i].nome)==0){
            printf("\n| ID Produto: %d\n| Nome Produto: %s\n| Preco Produto: %.2f\n| Quantidade: %d\n\n", r[i].id,r[i].nome,r[i].preco,r[i].quantidade);
            check--;
            link = r[i];
            pos = i;
            break;
            }
        }
            if(check == 1)
            printf("\n|-----Produto nao encontrado ou sem estoque-----|\n");

        }while(check);
        do{
        printf("|  3 - Quantidade comprada:          |\n");
        scanf("%d", &quant);
        if(link.quantidade == 0){
            printf("|---Produto indisponivel no estoque 0 unidades---|\n");
            item.quantidadeCompra = -1;
            return item;
        }
        if(r[i].quantidade<quant || quant<=0){
            printf("|---Quantidade indisponivel no estoque---|\n|--Existem %d produtos em estoque--|\n",link.quantidade);
            continue;
        } else {
            r[pos].quantidade = r[pos].quantidade - quant;
            break;
        }
        }while(1);
        item.produto = link;
        item.quantidadeCompra = quant;
        item.valorCompra = (quant*link.preco);
        *contT = *contT + 1;
        return item;
}

int validaCliente(CLI cl, CLI *r, int size){
        int i;
        for(i=0; i< size; i++){
            if(strcmp(cl.cpf,r[i].cpf)==0 && strcmp(cl.nome,r[i].nome)==0){
            printf("\n|---CLIENTE LIBERADO PARA COMPRA---|");
            //system("pause");
            return i;
            }
        }
        printf("\n|-----Cliente nao encontrado-----|\n");
        return -1;
}

int validaCPF(CLI p){
    int i;
    if(strlen(p.cpf)==9){
        for(i=0;i<strlen(p.cpf);i++){
        if(isdigit(p.cpf[i])){
            continue;
        } else{
            printf("|--------CPF invalido--------|\n\n");
            printf("|---CPF DEVE TER 9 DIGITOS---|\n");
            return 1;
        }
        }
    } else {
        printf("|--------CPF invalido--------|\n\n");
        printf("|---CPF DEVE TER 9 DIGITOS---|\n");
        return 1;
    }
    return 0;
}

void printNota(NOTA nota, int size){
    int i;
    float total = 0;
    printf("\n|---NOTA GERADA---|\n");
    printf("| NUMERO NOTA: %d\n", nota.numero);
    printf("| CLIENTE: %s\n", nota.cliente.nome);
    printf("| CPF: %s\n",nota.cliente.cpf);
    printf("|____________________________\n");
    printf("|---DESCRICAO DOS ITENS---|\n");
    for(i=0; i< size; i++){
        printf("ITEM %d - %s - QUANTIDADE - %d - VALOR - %.2f\n",i+1,nota.item[i].produto.nome,nota.item[i].quantidadeCompra,nota.item[i].valorCompra);
        total += nota.item[i].valorCompra;
    }
    printf("|____________________________\n");
    printf("|---TOTAL A PAGAR---|\n");
    printf("TOTAL: %.2f\n",total);
    system("pause");
    printf("|---NOTA FECHADA---|\n");
}

NOTA abreNota(CLI *cl , int sizeC, int *idC, PROD *pr, int sizeP,int *idP,NOTA nota, int *id){
        int cont=0, check=2, *contT = malloc(sizeof(int)), aux;
        CLI r;
        *id = *id + 1;
        nota.numero = *id;
        *contT = 0;
        system("cls");
        do{
        printf("\n|  1 - Nome do Cliente:                 |\n");
        fflush(stdin);
        gets(r.nome);
        fflush(stdin);
        do{
        printf("|  2 - CPF Cliente:                       |\n");
        fflush(stdin);
        gets(r.cpf);
        fflush(stdin);
        }while(validaCPF(r));
        aux = validaCliente(r,cl,sizeC);
        }while( -1 == aux);
        nota.cliente = cl[aux];
        while(check != 4){
        if(cont != 0){
        printf("\n|----Digite 4 para nao cadastrar mais itens ou 2 para continuar----|\n\n");
        scanf("%d",&check);
        system("cls");
        }

        if(check == 4){
            break;
        } else{
            if(check == 2) {
                if(cont < 5){
                    nota.item[cont] = novoItem(pr,sizeP,contT);
                } else{
                    printf("\n|----Numero de itens maximos atingidos----|\n\n");
                    break;
                }

                if(nota.item[cont].quantidadeCompra == -1){
                    printf("\n|----Item invalido----|\n\n");
                } else{
                    printf("\n|----Item cadastrado----|\n\n");
                    cont++;
                }
            }
        }
        }
        printNota(nota,*contT);
        return nota;
}

PROD cadastraProdutos(PROD r, int cont, int *id){
        *id = *id + 1;
        r.id = *id;
        system("cls");
        printf("\n|  1 - Nome do Produto:                 |\n");
        fflush(stdin);
        gets(r.nome);
        fflush(stdin);
        printf("|  2 - Preco Produto:                     |\n");
        scanf("%f", &r.preco);
        do{
        printf("|  3 - Quantidade em estoque:             |\n");
        scanf("%d",&r.quantidade);
        if(r.quantidade>=0)
                break;
        system("cls");
        printf("Quantidade informada menor que 0\n");
        }while(1);
        system("cls");
        printf("\n|-----------CADASTRO BEM SUCEDIDO!!----------|\n");
        return r;
}


CLI cadastroCliente(CLI r, int cont, int *id){
        *id = *id + 1;
        r.id = *id;
        system("cls");
        printf("\n|  1 - Nome do Cliente:                 |\n");
        fflush(stdin);
        gets(r.nome);
        fflush(stdin);
        do{
        printf("|  2 - CPF Cliente:                       |\n");
        fflush(stdin);
        gets(r.cpf);
        fflush(stdin);
        }while(validaCPF(r));
        system("cls");
        printf("\n|-----------CADASTRO BEM SUCEDIDO!!----------|\n");
        return r;
}

void listaClientes(CLI *r, int size, int *idCli){
        char nome[1111];
        int id, i;
        system("cls");
        printf("\n|  1 - Nome do Cliente:            |\n");
        fflush(stdin);
        gets(nome);
        fflush(stdin);
        printf("|  2 - ID Cliente:                   |\n");
        scanf("%d", &id);
        for(i=0; i< size; i++){
            if(id == r[i].id && strcmp(nome,r[i].nome)==0)
            printf("\n| ID Cliente: %d\n| Nome Cliente: %s\n| CPF Cliente: %s|\n\n", r[i].id,r[i].nome,r[i].cpf);
        }
        printf("\n|-----Cliente nao encontrado-----|\n");
}



void listaprodutos(PROD *r, int size, int *idProd){
        char nome[1111];
        int id, i;
        system("cls");
        printf("\n|  1 - Nome do Produto:            |\n");
        fflush(stdin);
        gets(nome);
        fflush(stdin);
        printf("|  2 - ID Produto:                   |\n");
        scanf("%d", &id);
        for(i=0; i< size; i++){
            if(id == r[i].id && strcmp(nome,r[i].nome)==0)
            printf("\n| ID Produto: %d\n| Nome Produto: %s\n| Preco Produto: %.2f|\n| Quantidade: %d|\n\n|", r[i].id,r[i].nome,r[i].preco,r[i].quantidade);
        }
        printf("\n|-----Produto nao encontrado-----|\n");
}

int excluiProduto(PROD *r, int size, int *idProd){
        PROD link;
        char nome[1111];
        int id, i;
        system("cls");
        printf("\n|  1 - Nome do Produto:             |\n");
        fflush(stdin);
        gets(nome);
        fflush(stdin);
        printf("|  2 - ID Produto:                   |\n");
        scanf("%d", &id);
        for(i=0; i< size; i++){
            if(id == r[i].id && strcmp(nome,r[i].nome)==0){
                link = r[i];
                r[i] = r[size-1];
                r[size-1] = link;
                printf("\n| Produto Excluido");
                printf("\n| ID Produto: %d\n| Nome Produto: %s\n| Preco: %.2f\n| Quantidade: %d      \n\n", link.id,link.nome,link.preco,link.quantidade);
                return size-1;
            }
        }
        printf("\n|-----Produto nao encontrado-----|\n");
        return size;
}


int excluiCliente(CLI *r, int size, int *idCli){
        CLI link;
        char nome[1111];
        int id, i;
        system("cls");
        printf("\n|  1 - Nome do Cliente:             |\n");
        fflush(stdin);
        gets(nome);
        fflush(stdin);
        printf("|  2 - ID Cliente:                   |\n");
        scanf("%d", &id);
        for(i=0; i< size; i++){
            if(id == r[i].id && strcmp(nome,r[i].nome)==0){
                link = r[i];
                r[i] = r[size-1];
                r[size-1] = link;
                printf("\n| Cliente Excluido");
                printf("\n| ID Produto: %d\n| Nome Cliente: %s\n| CPF Cliente: %s      \n\n", link.id,link.nome,link.cpf);
                return size-1;
            }
        }
        printf("\n|-----Cliente nao encontrado-----|\n");
        return size;
}

void listaClientesAlfa(CLI *r, int size){
    int i,j;
    CLI aux;
    for (i = 0; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (strcmp(r[j - 1].nome, r[j].nome) > 0) {
                aux = r[j-1];
                r[j-1] = r[j];
                r[j] = aux;
            }
        }
    }
    printf("\n| Clientes em Ordens Alfabetica");
    for(i=0; i < size; i++){
        printf("\n| ID Cliente: %d\n| Nome Cliente: %s\n| CPF Cliente: %s\n\n", r[i].id,r[i].nome,r[i].cpf);
    }
}

void listaProdutosAlfa(PROD *r, int size){
    int i,j;
    PROD aux;
    for (i = 0; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (strcmp(r[j - 1].nome, r[j].nome) > 0) {
                aux = r[j-1];
                r[j-1] = r[j];
                r[j] = aux;
            }
        }
    }
    printf("\n| Produtos em Ordens Alfabetica");
    for(i=0; i < size; i++){
        printf("\n| ID Produto: %d\n| Nome Produto: %s\n| Preco: %.2f\n| Quantidade: %d      \n\n", r[i].id,r[i].nome,r[i].preco,r[i].quantidade);
    }
}

int main(){
    int *idPro = malloc(sizeof(int)), *idCli = malloc(sizeof(int)), *idNotas = malloc(sizeof(int));
    *idPro = 0;
    *idCli = 0;
    *idNotas = 0;
    CLI clientes[20], cli;
    PROD produtos[50], prod;
    NOTA notas[PER], nota;
    char opc;
    int cont=0,contC=0,contN=0;

     do{
        printf("\n");
        printf("|  1 - Cadastrar produtos                                       |\n");
        printf("|  2 - Consultar produtos, por nome e por id                    |\n");
        printf("|  3 - Excluir produto                                          |\n");
        printf("|  4 - Listar todos os produtos (ordem alfabética)              |\n");
        printf("|  5 - Cadastrar cliente.                                       |\n");
        printf("|  6 - Consultar clientes, por nome e por id                    |\n");
        printf("|  7 - Excluir cliente                                          |\n");
        printf("|  8 - Listar todos os clientes (ordem alfabética)              |\n");
        printf("|  9 - Vender.                                                  |\n");
        printf("|  0 - Sair.                                                    |\n");
        printf("\n");
        fflush(stdin);
        scanf("%c",&opc);
        fflush(stdin);
        switch(opc){
            case '1':
                if(cont < 50){
                    produtos[cont] = cadastraProdutos(prod,cont,idPro);
                    cont++;
                } else {
                    system("cls");
                    printf("Lista de Produtos cheia.\n\n");
                }
                break;
            case '2':
                system("cls");
                listaprodutos(produtos,cont,idPro);
                break;
            case '3':
                system("cls");
                cont = excluiProduto(produtos,cont,idPro);
                break;
            case '4':
                system("cls");
                listaProdutosAlfa(produtos,cont);
                break;
            case '5':
                system("cls");
                if(cont < 20){
                    clientes[contC] = cadastroCliente(cli,contC,idCli);
                    contC++;
                } else {
                    system("cls");
                    printf("Lista de Clientes cheia.\n\n");
                }
                break;
            case '6':
                system("cls");
                listaClientes(clientes,contC,idCli);
                break;
            case '7':
                system("cls");
                contC = excluiCliente(clientes,contC,idCli);
                break;
            case '8':
                system("cls");
                listaClientesAlfa(clientes,contC);
                break;
            case '9':
                system("cls");
                if(cont == 0)
                    printf("\n|---ATENCAO NAO HA PRODUTOS CADASTRADOS---|\n\n");
                else if(contC == 0)
                    printf("\n|---ATENCAO NAO HA CLIENTES CADASTRADOS---|\n");
                else{
                notas[contN] = abreNota(clientes,contC,idCli,produtos,cont,idPro,nota,idNotas);
                contN++;
                }
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
