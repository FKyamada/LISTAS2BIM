#include "arvore.h" 

//opções de menu 
#define GERA_ARVORE 	 	 	1 
#define INSERE_NOH 	 	 	 	2
#define INSERE_NOH_ORD			3
#define REMOVE_NOH 	 	 	 	4 
#define IMPRIME_CENTRAL 	 	5 
#define EXISTE 	 	 	 	 	6 
#define SAIR	 	 	 	 	0 

int menu();

void main()
{
	ArvoreDeBusca a;
	int opc, valor;

	while ((opc = menu()) != SAIR)
	{
		switch (opc)
		{
		case INSERE_NOH:  	 	 	 	
			cout << " Valor? ";  	 	 	
			cin >> valor;
			a.Arvore::insere(valor);
			break;

		case INSERE_NOH_ORD:
			cout << "Valor? ";
			cin >> valor;
			a.ArvoreDeBusca::insere(valor);
			break;

		case REMOVE_NOH:
			cout << "qual o valor? ";   	 	 	 
			cin >> valor;   	 	  	
			a.remove(valor);  	 	 	
			cout << "Remocao executada!\n";  	 	 	 
			break;

		case IMPRIME_CENTRAL:  	 	 
			a.imprimeCentral();
			break;

		case EXISTE:
			cout << "Que valor?";
			cin >> valor;

			if (a.existe(valor))
				cout << "Elemento encontrado!";   	 	 
			else
				cout << "Elemento nao encontrado!\n";  	 	 	
			break;

		case GERA_ARVORE:
			cout << "Quantos elementos?";   	 	 
			cin >> valor;
			a.geraArvore(valor);   	 	 
			cout << "Arvore gerada!\n";
			break;

		case SAIR:
		break;  	 	 
		default:
		cout << " Opcao nao implementada!\n";
		}
	} cout << " Ateh a proxima arvore!!!!\n";
}

		int menu()
	{
		int op;
		cout << endl << GERA_ARVORE << " - gerar uma arvore aleatoriamente\n";  
		cout << INSERE_NOH << " - inserir um elemento\n"; 
		cout << INSERE_NOH_ORD << "- insere um elemento ordenado\n";
		cout << REMOVE_NOH << " - remove um noh da arvore\n";   
		cout << IMPRIME_CENTRAL << " - imprimir com varrimento central\n";  	
		cout << EXISTE << " - procura um elemento da arvore\n"; 
		cout << SAIR << " - sair \n";
		cin >> op;
		return op;
	}
