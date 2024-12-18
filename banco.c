#include <stdio.h>
#include "banco.h"

CONTA conta;

int menu() {
	int opcao;

	printf("Bem-vindo à NOMAD, sua solução financeira!\n");
	printf("1- Consultar saldo\n");
	printf("2- Adicionar valor\n");
	printf("3- Fazer uma transferência\n");
	printf("4- Sair\n");
	printf("Escolha uma opção: ");
	scanf("%d", &opcao);

	return opcao;
}

void consultarsaldo() {
	printf("Saldo atual: %f\n", conta.saldo);
}

void adicionarvalor(double valor) {
	conta.saldo += valor;
	printf("Valor de R$%.2lf adicionado com sucesso!\n", valor);
}

int temsaldosuficiente(double valor) {
	if (conta.saldo < valor) return 0;
	return 1;
}

void fazertransferencia(double valor, int idrecebedor) {
	if (!temsaldosuficiente(valor)) printf("Saldo insuficiente\n");
	else{
		conta.saldo -= valor;
		printf("Transferência de R$%2.lf feita com sucesso!", valor);
	}
	
}
int main() {
	conta.id = 1;
	conta.saldo = 0.0;
	int opcao = menu();
	double valor;

	switch(opcao) {
	case 1:
		consultarsaldo();
		break;
	case 2:
		printf("Qual o valor que você deseja adicionar? ");
		scanf("%lf", &valor);
		adicionarvalor(valor);
		break;
	case 3:
		int idrecebedor;
		printf("Qual o valor que você deseja transferir? ");
		scanf("%lf", &valor);
		printf("Qual o id do recebedor? ");
		scanf("%d", &idrecebedor);
		fazertransferencia(valor, idrecebedor);
		break;
	case 4:
		printf("Saindo...");
		break;
	}
}