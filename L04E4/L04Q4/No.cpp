#include "No.h"

No::No(int elem)
{
	info = elem;
	esquerdo = direito = NULL;
}
No::~No()
{
	cout << "No de valor " << info << " destruido!\n";
	//mensagem apenas para certificação de que o destrutor
	//esteja sendo chamado apropriadamente.
}
int No::getInfo()
{
	return info;
}
void No::setInfo(int elem)
{
	info = elem;
}
No* No::getEsquerdo()
{
	return esquerdo;
}
void No::setEsquerdo(No *novoNo)
{
	esquerdo = novoNo;
}
No* No::getDireito()
{
	return direito;
}
void No::setDireito(No* novoNo)
{
	direito = novoNo;
}
bool No::eFolha()
{
	if (esquerdo == NULL && direito == NULL)
		return true;
	return false;
}