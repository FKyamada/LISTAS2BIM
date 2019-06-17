#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

class No
{
	int info;
	No* esquerdo;
	No* direito;

public:
	No(int elem);//construtor
	~No();//Destrutor
		  /* Métodos de Acesso
		  */
	int getInfo();
	void setInfo(int elem);
	No *getEsquerdo();
	void setEsquerdo(No *novoNo);
	No *getDireito();
	void setDireito(No* novoNo);
	//Fim dos métodos de acesso
	bool eFolha();
	/* Verifica se os filhos esquerdo e direito do
	* nó são nulos
	*/
};