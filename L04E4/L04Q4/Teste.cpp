#include "Arvore.h"

//opções de menu
#define GERA_ARVORE 1
#define INSERE_NOH 2
#define REMOVE_NOH 3
#define IMPRIME_CENTRAL 4
#define IMPRIME_PRE 5
#define IMPRIME_POS 6
#define EXISTE 7
#define ALTURA 8
#define SAIR 0
int menu();

void main()
{
	Arvore arv;
	int opc, valor;
	while ((opc = menu()) != SAIR)
	{
		switch (opc)
		{
		case ALTURA:
			cout << "A altura da arvore eh " << arv.alturaArvore() << "\n";
			break;
		case INSERE_NOH:
			cout << " Valor? ";
			cin >> valor;
			arv.insere(valor);
			break;
		case REMOVE_NOH:
			cout << "qual o valor? ";
			cin >> valor;
			arv.remove(valor);
			cout << "Remocao executada!\n";
			break;
		case IMPRIME_CENTRAL:
			arv.imprimeCentral();
			break;
		case IMPRIME_PRE:
			arv.imprimePre();
			break;
		case IMPRIME_POS:
			arv.imprimePos();
			break;
		case EXISTE:
			cout << "Que valor?";
			cin >> valor;
			if (arv.existe(valor))
				cout << "Elemento encontrado!";
			else
				cout << "Elemento nao encontrado!\n";
			break;
		case GERA_ARVORE:
			cout << "Quantos elementos?";
			cin >> valor;
			arv.geraArvore(valor);
			cout << "Arvore gerada!\n";
			break;
		case SAIR:
			break;
		default:
			cout << " Opcao nao implementada!\n";
		}
	}
	cout << " Ateh a proxima arvore!!!!\n";
}

int menu()
{
	int op;
	cout << endl << GERA_ARVORE << " - gerar uma arvore aleatoriamente\n";
	cout << INSERE_NOH << " - inserir um elemento\n";
	cout << REMOVE_NOH << " - remove um noh da arvore\n";
	cout << IMPRIME_CENTRAL << " - imprimir com varrimento central\n";
	cout << IMPRIME_PRE << " - imprimir com varrimento Pre Fixado\n";
	cout << IMPRIME_POS << " - imprimir com varrimento Pos Fixado\n";
	cout << EXISTE << " - procura um elemento da arvore\n";
	cout << ALTURA << "- verifica o tamanho da arvore\n";
	cout << SAIR << " - sair \n";
	cin >> op;
	return op;
}