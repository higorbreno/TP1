// Biblioteca CRIPTO - Biblioteca que cont�m as fun��es necess�rias para codificar e decoficar um valor de 32 bits

#include <random> // Inclus�o da biblioteca necess�ria para cria��o de n�meros pseudoaleat�rios usando o m�todo mersenne twister

// Fun��o para ligar um bit em uma posi��o espec�fica
unsigned int LigarBit(unsigned int bit32, unsigned int posicao) {
	unsigned int mascara = 1 << posicao; // Move o bit ligado para a posi��o especificada
	return (bit32 | mascara); // Retorna o valor de 32 bits com o bit da posi��o especificada ligado
}

// Fun��o para desligar um bit em uma posi��o espec�fica
unsigned int DesligarBit(unsigned int bit32, unsigned int posicao) {
	unsigned int mascara = ~(1 << posicao); // Move o bit ligado para a posi��o especificada, e inverte todos os bits para deslig�-lo
	return (bit32 & mascara); // Retorna o valor de 32 bits com o bit da posi��o especificada desligado
}

// Fun��o para testar um bit em uma posi��o espec�fica
bool TestarBit(unsigned int bit32, unsigned int posicao) {
	unsigned int mascara = 1 << posicao; // Move o bit ligado para a posi��o especificada
	return (bit32 & mascara); // Retorna o valor l�gico do bit na posi��o especificada
}

// Fun��o que recebe um valor de 32 bits, codifica-o, e retorna um valor de 64 bits
unsigned long long Codificar(unsigned int bit32) {
	std::random_device rd; // Cria um "random device" chamado rd que gera um n�mero verdadeiramente aleat�rio
	std::mt19937 mt(rd()); // Usa o n�mero gerado aleat�riamente como sementes para uma gera��o pseudoaleat�ria mersenne twister
	std::uniform_int_distribution<int> dist(0, 31); // Distribui uniformemente os n�meros e faz com que os n�meros psudoaleat�rios fiquem na faixa de 0 a 31
	unsigned int posicao1 = dist(mt); // Escolhe uma n�mero pseudoaleat�rio entre 0 e 31
	bit32 = TestarBit(bit32, posicao1) ? DesligarBit(bit32, posicao1) : LigarBit(bit32, posicao1); // Inverte o bit na posi��o referente ao n�mero escolhido acima
	unsigned int posicao2 = dist(mt); // Escolhe uma n�mero pseudoaleat�rio entre 0 e 31
	bit32 = TestarBit(bit32, posicao2) ? DesligarBit(bit32, posicao2) : LigarBit(bit32, posicao2); // Inverte o bit na posi��o referente ao n�mero escolhido acima
	unsigned int posicao3 = dist(mt); // Escolhe uma n�mero pseudoaleat�rio entre 0 e 31
	bit32 = TestarBit(bit32, posicao3) ? DesligarBit(bit32, posicao3) : LigarBit(bit32, posicao3); // Inverte o bit na posi��o referente ao n�mero escolhido acima
	unsigned int posicao4 = dist(mt); // Escolhe uma n�mero pseudoaleat�rio entre 0 e 31
	bit32 = TestarBit(bit32, posicao4) ? DesligarBit(bit32, posicao4) : LigarBit(bit32, posicao4); // Inverte o bit na posi��o referente ao n�mero escolhido acima
	unsigned int posicao5 = dist(mt); // Escolhe uma n�mero pseudoaleat�rio entre 0 e 31
	bit32 = TestarBit(bit32, posicao5) ? DesligarBit(bit32, posicao5) : LigarBit(bit32, posicao5); // Inverte o bit na posi��o referente ao n�mero escolhido acima
	unsigned int posicao6 = dist(mt); // Escolhe uma n�mero pseudoaleat�rio entre 0 e 31
	bit32 = TestarBit(bit32, posicao6) ? DesligarBit(bit32, posicao6) : LigarBit(bit32, posicao6); // Inverte o bit na posi��o referente ao n�mero escolhido acima

	unsigned long long bit64 = unsigned long long(bit32) << 32; // Guarda o valor modificado em uma vari�vel de 64 bits
	unsigned int posicoes = (posicao1 << 27) | (posicao2 << 22) | (posicao3 << 17) | (posicao4 << 12) | (posicao5 << 7) | (posicao6 << 2); // Guarda as posi��es dos n�meros invertidos em uma vari�vel de 32 bits

	bit64 = bit64 | posicoes; // Guarda as posi��es junto com o n�mero modificado
	return bit64; // Retorna o valor de 64 bits que cont�m o valor de 32 bits codificado e as posi��es dos bits invertidos
}

// Fun��o que recebe um valor de 64 bits, decodifica-o, e retorna um valor de 32 bits
unsigned int Decodificar(unsigned long long bit64) {
	unsigned int bit32 = bit64 >> 32; // Guarda o valor codificaddo em uma vari�vel de 32 bits
	unsigned int posicoes = bit64; // Guarda as posi��es dos bits invertidos em uma vari�vel de 32 bits

	unsigned short posicao1 = posicoes >> 27; // Pega a primeira posi��o transformando os bits ao seu redor em zero
	unsigned short posicao2 = ((posicoes << 5) >> 27); // Pega a segunda posi��o transformando os bits ao seu redor em zero
	unsigned short posicao3 = ((posicoes << 10) >> 27); // Pega a terceira posi��o transformando os bits ao seu redor em zero
	unsigned short posicao4 = ((posicoes << 15) >> 27); // Pega a quarta posi��o transformando os bits ao seu redor em zero
	unsigned short posicao5 = ((posicoes << 20) >> 27); // Pega a quinta posi��o transformando os bits ao seu redor em zero
	unsigned short posicao6 = ((posicoes << 25) >> 27); // Pega a sexta posi��o transformando os bits ao seu redor em zero

	bit32 = TestarBit(bit32, posicao1) ? DesligarBit(bit32, posicao1) : LigarBit(bit32, posicao1); // Inverte o bit do valor codificado na primeira posi��o especificada
	bit32 = TestarBit(bit32, posicao2) ? DesligarBit(bit32, posicao2) : LigarBit(bit32, posicao2); // Inverte o bit do valor codificado na segunda posi��o especificada
	bit32 = TestarBit(bit32, posicao3) ? DesligarBit(bit32, posicao3) : LigarBit(bit32, posicao3); // Inverte o bit do valor codificado na terceira posi��o especificada
	bit32 = TestarBit(bit32, posicao4) ? DesligarBit(bit32, posicao4) : LigarBit(bit32, posicao4); // Inverte o bit do valor codificado na quarta posi��o especificada
	bit32 = TestarBit(bit32, posicao5) ? DesligarBit(bit32, posicao5) : LigarBit(bit32, posicao5); // Inverte o bit do valor codificado na quinta posi��o especificada
	bit32 = TestarBit(bit32, posicao6) ? DesligarBit(bit32, posicao6) : LigarBit(bit32, posicao6); // Inverte o bit do valor codificado na sexta posi��o especificada

	return bit32; // Retorna o valor em 32 bits decodificado
}