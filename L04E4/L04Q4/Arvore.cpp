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
		{//se há uma subárvore à esquerda...
			aux->raiz = raiz->getEsquerdo();
			aux->~Arvore();//...remover essa árvore
		}
		if (raiz->getDireito() != NULL)
		{//se há uma subárvore à direita...
			aux->raiz = raiz->getDireito();
			aux->~Arvore();//...remover essa árvore também
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

	//percorrendo sub-ávore á ESQUERDA
	if (raiz->getEsquerdo() != NULL)
	{
		esq++;
		aux->raiz = raiz->getEsquerdo();
		esq += aux->alturaArvore();//chamada recursiva a altura
	}

	//percorrendo sub-arvores á DIREITA
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
	if (pS->existe(elem) == true)//procura o elemento na subárvore esquerda
		return true; //se encontrar, encerra a busca.
	pS->raiz = raiz->getDireito(); //se não encontrou...
	return pS->existe(elem); //procura na subárvore direita
}
void Arvore::insere(int elem)
{
	if (existe(elem))
		return; //insere não admite a inserção de elementos repetidos
	if (eVazia())
	{
		raiz = new No(elem);
		return;
	}
	static int preferencia = ESQUERDA;
	No* pAux = raiz;
	do {//procura repetidamente um nó vazio, com a
		//preferência dada
		if (preferencia == ESQUERDA)
		{
			if (pAux->getEsquerdo() != NULL)//o nó esquerdo não está vazio
			{
				pAux = pAux->getEsquerdo();//procura agora a partir dele
				continue;
			}
			else//o nó esquerdo está vazio
			{
				pAux->setEsquerdo(new No(elem));//insere o elemento
				preferencia *= -1;//muda a preferência na próxima inserção
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
	No* pNo = procura(elem); //procura o nó na árvore
	while (!pNo->eFolha())//enquanto o nó apontado por pNo não for uma folha...
	{
		if (pNo->getEsquerdo() != NULL)// o nó esquerdo não é vazio
		{
			pNo->setInfo((pNo->getEsquerdo())->getInfo()); //copia o valor do filho esquerdo
			pNo = pNo->getEsquerdo(); //aponta para o filho esquerdo, para removê - lo
		}
		else//o nó direito é que não é vazio...
		{
			pNo->setInfo((pNo->getDireito())->getInfo()); //copia o valor do filho direito
			pNo = pNo->getDireito();//aponta para o filho direito, para removê-lo
		}
	}
	No* pPai = procuraPai(pNo);//procura o pai do nó a ser removido
	if (pPai->getEsquerdo() == pNo)
		pPai->setEsquerdo(NULL);//anula a referência para o filho...
	else if (pPai->getDireito() == pNo)//...seja ele o esquerdo...
		pPai->setDireito(NULL); // .. ou o direito.
	else
		raiz = NULL; //se o não tem pai, o nó é a raiz.
	delete pNo;//remove o nó da memória
}

void Arvore::imprimeCentral()
{//esquerda-raiz-direita
	if (eVazia())
	{
		cout << "Arvore vazia!\n";
		return;
	}
	Arvore* aux = new Arvore;
	//impressao da subárvore esquerda
	if (raiz->getEsquerdo() != NULL)
	{
		aux->raiz = raiz->getEsquerdo();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
	//impressao da raiz
	cout << " - " << raiz->getInfo();
	//impressao da subárvore direita
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
	//impressao da subárvore esquerda
	if (raiz->getEsquerdo() != NULL)
	{
		aux->raiz = raiz->getEsquerdo();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
	//impressao da subárvore direita
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


	//impressao da subárvore esquerda
	if (raiz->getEsquerdo() != NULL)
	{
		aux->raiz = raiz->getEsquerdo();
		aux->imprimeCentral();//chamada recursiva a imprimeCentral
	}
	//impressao da subárvore direita
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
	//semente para a sequência de números aleatórios
	for (int i = 0; i<nElementos; i++)
	{
		do {
			valor = rand(); //geração de número aleatório
			valor %= limite + 1; //o valor gerado é colocado dentro do limite
			if (tentativas++ > limite)//evita um loop infinito...
				return; //...caso todos os valores já tenham sido gerados
		} while (existe(valor));//não permite inserção de valores repetidos
		if (eVazia())
			raiz = new No(valor);
		else
		{
			No* pAux = raiz;
			do { //busca para um nó vazio
				if (rand() % 2 == 0) //troca ou nao a preferencia de busca
					preferencia *= -1; // essa troca é aleatória
				if (preferencia == ESQUERDA)
				{
					if (pAux->getEsquerdo() != NULL)// o nó esquerdo não é vazio
					{
						pAux = pAux->getEsquerdo();
						continue;//continua a busca
					}
					else//nó esquerdo vazio
					{
						pAux->setEsquerdo(new
							No(valor));//insere o novo nó
						break; //encerra a procura por um noh vazio
					}
				}
				else//preferência == direita, mesmo algoritmo
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
 /* Métodos privados da árvore, auxiliares de remove( )
 */
No* Arvore::procura(int elem)
{
	if (eVazia())
		return NULL;
	if (raiz->getInfo() == elem)
		return raiz;//o elemento está na raiz.
	else
	{
		Arvore *pSub = new Arvore;
		No* pN;
		pSub->raiz = raiz->getEsquerdo();//procura na subárvore esquerda
		pN = pSub->procura(elem);
		if (pN != NULL)
			return pN;
		//nao foi encontrado à esquerda:
		pSub->raiz = raiz->getDireito();//procura na subárvore direita
		pN = pSub->procura(elem);
		return pN;
	}
}
No* Arvore::procuraPai(No* umNo)
{
	if (eVazia() || raiz == umNo)
		return NULL; //o nó não tem pai
	Arvore* pAux = new Arvore;
	pAux->raiz = raiz;
	if (pAux->raiz->getEsquerdo() == umNo || pAux->raiz->getDireito() == umNo)
		return pAux->raiz;// o pai é a raiz.
	pAux->raiz = raiz->getEsquerdo();
	No *pN;
	if ((pN = pAux->procuraPai(umNo)) != NULL)
		return pN; //procura o pai na subárvore esquerda
	else
	{ //procura o pai na subárvore direita
		pAux->raiz = raiz->getDireito();
		return pAux->procuraPai(umNo);
	}
}