// Biblioteca CRIPTO - Biblioteca que contém as funções necessárias para codificar e decoficar um valor de 32 bits

#include <random> // Inclusão da biblioteca necessária para criação de números pseudoaleatórios usando o método mersenne twister

// Função para ligar um bit em uma posição específica
unsigned int LigarBit(unsigned int bit32, unsigned int posicao) {
	unsigned int mascara = 1 << posicao; // Move o bit ligado para a posição especificada
	return (bit32 | mascara); // Retorna o valor de 32 bits com o bit da posição especificada ligado
}

// Função para desligar um bit em uma posição específica
unsigned int DesligarBit(unsigned int bit32, unsigned int posicao) {
	unsigned int mascara = ~(1 << posicao); // Move o bit ligado para a posição especificada, e inverte todos os bits para desligá-lo
	return (bit32 & mascara); // Retorna o valor de 32 bits com o bit da posição especificada desligado
}

// Função para testar um bit em uma posição específica
bool TestarBit(unsigned int bit32, unsigned int posicao) {
	unsigned int mascara = 1 << posicao; // Move o bit ligado para a posição especificada
	return (bit32 & mascara); // Retorna o valor lógico do bit na posição especificada
}

// Função que recebe um valor de 32 bits, codifica-o, e retorna um valor de 64 bits
unsigned long long Codificar(unsigned int bit32) {
	std::random_device rd; // Cria um "random device" chamado rd que gera um número verdadeiramente aleatório
	std::mt19937 mt(rd()); // Usa o número gerado aleatóriamente como sementes para uma geração pseudoaleatória mersenne twister
	std::uniform_int_distribution<int> dist(0, 31); // Distribui uniformemente os números e faz com que os números psudoaleatórios fiquem na faixa de 0 a 31
	unsigned int posicao1 = dist(mt); // Escolhe uma número pseudoaleatório entre 0 e 31
	bit32 = TestarBit(bit32, posicao1) ? DesligarBit(bit32, posicao1) : LigarBit(bit32, posicao1); // Inverte o bit na posição referente ao número escolhido acima
	unsigned int posicao2 = dist(mt); // Escolhe uma número pseudoaleatório entre 0 e 31
	bit32 = TestarBit(bit32, posicao2) ? DesligarBit(bit32, posicao2) : LigarBit(bit32, posicao2); // Inverte o bit na posição referente ao número escolhido acima
	unsigned int posicao3 = dist(mt); // Escolhe uma número pseudoaleatório entre 0 e 31
	bit32 = TestarBit(bit32, posicao3) ? DesligarBit(bit32, posicao3) : LigarBit(bit32, posicao3); // Inverte o bit na posição referente ao número escolhido acima
	unsigned int posicao4 = dist(mt); // Escolhe uma número pseudoaleatório entre 0 e 31
	bit32 = TestarBit(bit32, posicao4) ? DesligarBit(bit32, posicao4) : LigarBit(bit32, posicao4); // Inverte o bit na posição referente ao número escolhido acima
	unsigned int posicao5 = dist(mt); // Escolhe uma número pseudoaleatório entre 0 e 31
	bit32 = TestarBit(bit32, posicao5) ? DesligarBit(bit32, posicao5) : LigarBit(bit32, posicao5); // Inverte o bit na posição referente ao número escolhido acima
	unsigned int posicao6 = dist(mt); // Escolhe uma número pseudoaleatório entre 0 e 31
	bit32 = TestarBit(bit32, posicao6) ? DesligarBit(bit32, posicao6) : LigarBit(bit32, posicao6); // Inverte o bit na posição referente ao número escolhido acima

	unsigned long long bit64 = unsigned long long(bit32) << 32; // Guarda o valor modificado em uma variável de 64 bits
	unsigned int posicoes = (posicao1 << 27) | (posicao2 << 22) | (posicao3 << 17) | (posicao4 << 12) | (posicao5 << 7) | (posicao6 << 2); // Guarda as posições dos números invertidos em uma variável de 32 bits

	bit64 = bit64 | posicoes; // Guarda as posições junto com o número modificado
	return bit64; // Retorna o valor de 64 bits que contém o valor de 32 bits codificado e as posições dos bits invertidos
}

// Função que recebe um valor de 64 bits, decodifica-o, e retorna um valor de 32 bits
unsigned int Decodificar(unsigned long long bit64) {
	unsigned int bit32 = bit64 >> 32; // Guarda o valor codificaddo em uma variável de 32 bits
	unsigned int posicoes = bit64; // Guarda as posições dos bits invertidos em uma variável de 32 bits

	unsigned short posicao1 = posicoes >> 27; // Pega a primeira posição transformando os bits ao seu redor em zero
	unsigned short posicao2 = ((posicoes << 5) >> 27); // Pega a segunda posição transformando os bits ao seu redor em zero
	unsigned short posicao3 = ((posicoes << 10) >> 27); // Pega a terceira posição transformando os bits ao seu redor em zero
	unsigned short posicao4 = ((posicoes << 15) >> 27); // Pega a quarta posição transformando os bits ao seu redor em zero
	unsigned short posicao5 = ((posicoes << 20) >> 27); // Pega a quinta posição transformando os bits ao seu redor em zero
	unsigned short posicao6 = ((posicoes << 25) >> 27); // Pega a sexta posição transformando os bits ao seu redor em zero

	bit32 = TestarBit(bit32, posicao1) ? DesligarBit(bit32, posicao1) : LigarBit(bit32, posicao1); // Inverte o bit do valor codificado na primeira posição especificada
	bit32 = TestarBit(bit32, posicao2) ? DesligarBit(bit32, posicao2) : LigarBit(bit32, posicao2); // Inverte o bit do valor codificado na segunda posição especificada
	bit32 = TestarBit(bit32, posicao3) ? DesligarBit(bit32, posicao3) : LigarBit(bit32, posicao3); // Inverte o bit do valor codificado na terceira posição especificada
	bit32 = TestarBit(bit32, posicao4) ? DesligarBit(bit32, posicao4) : LigarBit(bit32, posicao4); // Inverte o bit do valor codificado na quarta posição especificada
	bit32 = TestarBit(bit32, posicao5) ? DesligarBit(bit32, posicao5) : LigarBit(bit32, posicao5); // Inverte o bit do valor codificado na quinta posição especificada
	bit32 = TestarBit(bit32, posicao6) ? DesligarBit(bit32, posicao6) : LigarBit(bit32, posicao6); // Inverte o bit do valor codificado na sexta posição especificada

	return bit32; // Retorna o valor em 32 bits decodificado
}