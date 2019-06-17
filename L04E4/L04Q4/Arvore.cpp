#include "Arvore.h"

Arvore::Arvore()
{
	raiz = NULL;
}

Arvore::~Arvore()
{
	Arvore *aux = new Arvore();
	if (!eVazia())
	{
		if (raiz->getEsquerdo() != NULL)
		{//se h� uma sub�rvore � esquerda...
			aux->raiz = raiz->getEsquerdo();
			aux->~Arvore();//...remover essa �rvore
		}
		if (raiz->getDireito() != NULL)
		{//se h� uma sub�rvore � direita...
			aux->raiz = raiz->getDireito();
			aux->~Arvore();//...remover essa �rvore tamb�m
		}
		delete raiz;//remover a raiz
	}
}
bool Arvore::eVazia()
{
	if (raiz == NULL)
		return true;
	return false;
}
/*--------------------------------Altura----------------------------------*/
int Arvore::alturaArvore() {

	if (eVazia())
	{
		cout << "Arvore vazia!\n";
		return NULL;
	}
	int esq = 0;
	int dir = 0;
	Arvore* aux = new Arvore;

	//percorrendo sub-�vore � ESQUERDA
	if (raiz->getEsquerdo() != NULL)
	{
		esq++;
		aux->raiz = raiz->getEsquerdo();
		esq += aux->alturaArvore();//chamada recursiva a altura
	}

	//percorrendo sub-arvores � DIREITA
	if (raiz->getDireito() != NULL)
	{
		dir++;
		aux->raiz = raiz->getDireito();
		dir += aux->alturaArvore();//chamada recursiva a altura
	}

	if (dir >= esq)
		return dir;
	else
		return esq;
}
/*------------------------------------------------------------------------*/
bool Arvore::existe(int elem)
{
	if (eVazia())
		return false;
	if (raiz->getInfo() == elem)//procura o elemento na raiz,
		return true; //se encontrar, encerra a busca
	Arvore *pS = new Arvore();
	pS->raiz = raiz->getEsquerdo();
	if (pS->existe(elem) == true)//procura o elemento na sub�rvore esquerda
		return true; //se encontrar, encerra a busca.
	pS->raiz = raiz->getDireito(); //se n�o encontrou...
	return pS->existe(elem); //procura na sub�rvore direita
}
void Arvore::insere(int elem)
{
	if (existe(elem))
		return; //insere n�o admite a inser��o de elementos repetidos
	if (eVazia())
	{
		raiz = new No(elem);
		return;
	}
	static int preferencia = ESQUERDA;
	No* pAux = raiz;
	do {//procura repetidamente um n� vazio, com a
		//prefer�ncia dada
		if (preferencia == ESQUERDA)
		{
			if (pAux->getEsquerdo() != NULL)//o n� esquerdo n�o est� vazio
			{
				pAux = pAux->getEsquerdo();//procura agora a partir dele
				continue;
			}
			else//o n� esquerdo est� vazio
			{
				pAux->setEsquerdo(new No(elem));//insere o elemento
				preferencia *= -1;//muda a prefer�ncia na pr�xima inser��o
				break; //encerra a procura por um noh vazio
			}
		}
		else//preferencia == direita, mesmo algoritmo
		{
			if (pAux->getDireito() != NULL)
			{
				pAux = pAux->getDireito();
				continue;
			}
			else
			{
				pAux->setDireito(new No(elem));
				preferencia *= -1;
				break; //encerra a procura por um noh vazio
			}
		}
	} while (true);
}//fim de insere

void Arvore::remove(int elem)
{
	if (eVazia() || !existe(elem))
		return;
	No* pNo = procura(elem); //procura o n� na �rvore
	while (!pNo->eFolha())//enquanto o n� apontado por pNo n�o for uma folha...
	{
		if (pNo->getEsquerdo() != NULL)// o n� esquerdo n�o � vazio
		{
			pNo->setInfo((pNo->getEsquerdo())->getInfo()); //copia o valor do filho esquerdo
			pNo = pNo->getEsquerdo(); //aponta para o filho esquerdo, para remov� - lo
		}
		else//o n� direito � que n�o � vazio...
		{
			pNo->setInfo((pNo->getDireito())->getInfo()); //copia o valor do filho direito
			pNo = pNo->getDireito();//aponta para o filho direito, para remov�-lo
		}
	}
	No* pPai = procuraPai(pNo);//procura o pai do n� a ser removido
	if (pPai->getEsquerdo() == pNo)
		pPai->setEsquerdo(NULL);//anula a refer�ncia para o filho...
	else if (pPai->getDireito() == pNo)//...seja ele o esquerdo...
		pPai->setDireito(NULL); // .. ou o direito.
	else
		raiz = NULL; //se o n�o tem pai, o n� � a raiz.
	delete pNo;//remove o n� da mem�ria
}

void Arvore::imprimeCentral()
{//esquerda-raiz-direita
	if (eVazia())
	{
		cout << "Arvore vazia!\n";
		return;
	}
	Arvore* aux = new Arvore;
	//impressao da sub�rvore esquerda
	if (raiz->getEsquerdo() != NULL)
	{
		aux->raiz = raiz->getEsquerdo();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
	//impressao da raiz
	cout << " - " << raiz->getInfo();
	//impressao da sub�rvore direita
	if (raiz->getDireito() != NULL)
	{
		aux->raiz = raiz->getDireito();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
}

void Arvore::imprimePre()
{//raiz-esquerda-direita
	if (eVazia())
	{
		cout << "Arvore vazia!\n";
		return;
	}
	Arvore* aux = new Arvore;

	//impressao da raiz
	cout << " - " << raiz->getInfo();
	//impressao da sub�rvore esquerda
	if (raiz->getEsquerdo() != NULL)
	{
		aux->raiz = raiz->getEsquerdo();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
	//impressao da sub�rvore direita
	if (raiz->getDireito() != NULL)
	{
		aux->raiz = raiz->getDireito();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
}

void Arvore::imprimePos()
{//esquerda-direita-raiz
	if (eVazia())
	{
		cout << "Arvore vazia!\n";
		return;
	}
	Arvore* aux = new Arvore;


	//impressao da sub�rvore esquerda
	if (raiz->getEsquerdo() != NULL)
	{
		aux->raiz = raiz->getEsquerdo();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
	//impressao da sub�rvore direita
	if (raiz->getDireito() != NULL)
	{
		aux->raiz = raiz->getDireito();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
	//impressao da raiz
	cout << " - " << raiz->getInfo();
}

void Arvore::geraArvore(int nElementos, int limite)
{
	int valor, preferencia = ESQUERDA, tentativas = 0;
	if (limite <= 0)
		limite = LIMITE_PADRAO;
	srand((unsigned)time(NULL));
	//semente para a sequ�ncia de n�meros aleat�rios
	for (int i = 0; i<nElementos; i++)
	{
		do {
			valor = rand(); //gera��o de n�mero aleat�rio
			valor %= limite + 1; //o valor gerado � colocado dentro do limite
			if (tentativas++ > limite)//evita um loop infinito...
				return; //...caso todos os valores j� tenham sido gerados
		} while (existe(valor));//n�o permite inser��o de valores repetidos
		if (eVazia())
			raiz = new No(valor);
		else
		{
			No* pAux = raiz;
			do { //busca para um n� vazio
				if (rand() % 2 == 0) //troca ou nao a preferencia de busca
					preferencia *= -1; // essa troca � aleat�ria
				if (preferencia == ESQUERDA)
				{
					if (pAux->getEsquerdo() != NULL)// o n� esquerdo n�o � vazio
					{
						pAux = pAux->getEsquerdo();
						continue;//continua a busca
					}
					else//n� esquerdo vazio
					{
						pAux->setEsquerdo(new
							No(valor));//insere o novo n�
						break; //encerra a procura por um noh vazio
					}
				}
				else//prefer�ncia == direita, mesmo algoritmo
				{
					if (pAux->getDireito() != NULL)
					{
						pAux = pAux->getDireito();
						continue;
					}
					else
					{
						pAux->setDireito(new No(valor));
						break; //encerra a procura por um noh vazio
					}
				}
			} while (true);
		}//fim do for
	}//fim do if
}//fim de geraArvore
 /* M�todos privados da �rvore, auxiliares de remove( )
 */
No* Arvore::procura(int elem)
{
	if (eVazia())
		return NULL;
	if (raiz->getInfo() == elem)
		return raiz;//o elemento est� na raiz.
	else
	{
		Arvore *pSub = new Arvore;
		No* pN;
		pSub->raiz = raiz->getEsquerdo();//procura na sub�rvore esquerda
		pN = pSub->procura(elem);
		if (pN != NULL)
			return pN;
		//nao foi encontrado � esquerda:
		pSub->raiz = raiz->getDireito();//procura na sub�rvore direita
		pN = pSub->procura(elem);
		return pN;
	}
}
No* Arvore::procuraPai(No* umNo)
{
	if (eVazia() || raiz == umNo)
		return NULL; //o n� n�o tem pai
	Arvore* pAux = new Arvore;
	pAux->raiz = raiz;
	if (pAux->raiz->getEsquerdo() == umNo || pAux->raiz->getDireito() == umNo)
		return pAux->raiz;// o pai � a raiz.
	pAux->raiz = raiz->getEsquerdo();
	No *pN;
	if ((pN = pAux->procuraPai(umNo)) != NULL)
		return pN; //procura o pai na sub�rvore esquerda
	else
	{ //procura o pai na sub�rvore direita
		pAux->raiz = raiz->getDireito();
		return pAux->procuraPai(umNo);
	}
}