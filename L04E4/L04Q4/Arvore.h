#include "No.h"

const int ESQUERDA = -1;
const int DIREITA = 1;
const int ARVORE_VAZIA = -1;
const int LIMITE_PADRAO = 100;

class Arvore
{
	No* raiz;
public:
	Arvore();//construtor
	~Arvore();//destrutor
	bool eVazia();
	/* verifica se a árvore é uma árvore vazia
	*/
	void insere(int elem);
	/* Insere um elemento na árvore, se ele nao existir,
	* de acordo com o seguinte algoritmo:
	* começando pela preferencia de inserir à esquerda, procura
	* o nó nulo com nível mais baixo possível para inserir o
	* novo nó. Ao inserir, a preferencia é invertida para a próxima
	* inserção.
	*/
	void remove(int elem);
	/* Remove da árvore o nó com o valor dado por "elem",
	* se ele existir
	*/
	void imprimeCentral();
	/* Imprime os nós da árvore que é varrida de forma central:
	* esquerda - raiz - direita
	*/
	void imprimePre();
	/* Imprime os nós da árvore que é varrida de forma pre fixada:
	* raiz - esquerda - direita
	*/
	void imprimePos();
	/* Imprime os nós da árvore que é varrida de forma pos fixada:
	* esquerda - direita - raiz
	*/
	bool existe(int elem);
	/* Verifica se o nó de valor "elem" existe na árvore
	*/
	void geraArvore(int nElementos, int limite = LIMITE_PADRAO);
	/* Gera uma árvore com nElementos aleatórios cujo valor vai de 0 até limite.
	* A inserção de cada elemento gerado é feita também de forma aletatória.
	* A preferência de inserção à esquerda ou à direita pode ser
	* invertida ou não a cada nível descido na busca de um nó vazio.
	*/
	int alturaArvore();
	/* verifica o tamanho da ávore. 
	*/
private:
	No * procura(int elem);
	/* Procura pelo nó de valor "elem", retornando um ponteiro para
	* este nó. Retorna NULL caso esse nó não exista.
	*/
	No* procuraPai(No* umNo);
	/* Procura o pai de "umNo" dentro da árvore. Se umNo não
	* existir, ou for a raiz da árvore, retorna NULL.
	*/
};