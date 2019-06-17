#include "arvore.h" 

//opções de menu 
#define GERA_ARVORE 	 	 	1 
#define INSERE_NOH 	 	 	 	2 
#define REMOVE_NOH 	 	 	 	3 
#define IMPRIME_CENTRAL 	 	4 
#define EXISTE 	 	 	 	 	5
#define GERA_ARVOREsl			6
#define SAIR	 	 	 	 	0 

int menu();

void main()
{
	Arvore arv;
	int opc, valor, limite;

	while ((opc = menu()) != SAIR)
	{
		switch (opc)
		{
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
		
		case GERA_ARVOREsl:
			cout << "Quantos elementos?";
			cin >> valor;
			cout << "Qual limite dos numeros a serem gerados?";
			cin >> limite;

			arv.geraArvoreSL(valor, limite);
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
	cout << EXISTE << " - procura um elemento da arvore\n";
	cout << GERA_ARVOREsl << " - gerar uma arvore aleatoriamente COM LIMITE\n";
	cout << SAIR << " - sair \n";

	cin >> op;
	return op;
}
