#ifndef _BANCO_H_
#define _BANCO_H_

typedef struct {
	int id;
	double saldo;
}CONTA;

void consultarsaldo();
void adicionarvalor(double valor);
void fazertransferencia(double valor, int idrecebedor);
int temsaldosuficiente(double valor);
int menu();

#endif