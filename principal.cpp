// Arquivo principal - contém a função "main" que chama as funções da outras bibliotecas para simular SIMD e codificação 

#include <iostream> // Inclusão da biblioteca padrão de entrada e saída de dados
#include <cstdlib> // Inclusão da biblioteca para usar funções "system"
#include <iomanip> // Inclusão da biblioteca usada para manipular a saída de dados
#include "simd.h" // Inclusão da biblioteca que contém as funções para simular SIMD
#include "cripto.h" // Inclusão da biblioteca que contém as funções para codificação
using namespace std;

int main() {
	system("chcp 1252 > nul"); // Comando para possibilitar a saída de caracteres acentuados

	// Declaração das variáveis que serão atribuídas pelo usuário
	unsigned short xxma1, xxma2, xxma3, xxma4;
	unsigned short xxmb1, xxmb2, xxmb3, xxmb4;

	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxma1; // Atribução do usuário a uma variável
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxma2; // Atribução do usuário a uma variável
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxma3; // Atribução do usuário a uma variável
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxma4; // Atribução do usuário a uma variável
	cin.ignore(); // Comando para ignorar um caracter no buffer

	cin.ignore(); // Comando para ignorar um caracter no buffer

	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxmb1; // Atribução do usuário a uma variável
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxmb2; // Atribução do usuário a uma variável
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxmb3; // Atribução do usuário a uma variável
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxmb4; // Atribução do usuário a uma variável
	cin.ignore(); // Comando para ignorar um caracter no buffer

	unsigned int xxma = Armazena(xxma1, xxma2, xxma3, xxma4); // Armazena as variáveis atribuidas pelo usuário em uma variável de 32 bits
	unsigned int xxmb = Armazena(xxmb1, xxmb2, xxmb3, xxmb4); // Armazena as variáveis atribuidas pelo usuário em uma variável de 32 bits

	
	cout << endl; // Pula uma linha
	cout << "Operandos em 32 bit = " << xxma << endl; // Mostra o valor de 32 bits que contém as variáveis atribuidas pelo usuário
	cout << "Operandos em 32 bit = " << xxmb << endl; // Mostra o valor de 32 bits que contém as variáveis atribuidas pelo usuário

	unsigned int soma = Soma(xxma, xxmb); // Soma os valores armazenados nas variáveis de 32 bits
	unsigned int mult = Mult(xxma, xxmb); // Multiplica os valores armazenados nas variáveis de 32 bits

	cout << endl; // Pula uma linha
	cout << "Soma em 32 bit = " << soma << endl; // Mostra a soma dos valores armazenados nas variáveis de 32 bits
	cout << "Mult em 32 bit = " << mult << endl; // Mostra a multiplicação dos valores armazenados nas variáveis de 32 bits

	cout << endl; // Pula uma linha
	cout << "[" << setfill('0') << setw(3) << int(Primeiro(soma))
		 << "," << setfill('0') << setw(3) << int(Segundo(soma))
		 << "," << setfill('0') << setw(3) << int(Terceiro(soma))
		 << "," << setfill('0') << setw(3) << int(Quarto(soma))
		 << "] = Somas" << endl; // Mostra os valores das somas entre os números inseridos pelo usuário usando 3 digitos

	cout << "[" << setfill('0') << setw(3) << int(Primeiro(mult))
		 << "," << setfill('0') << setw(3) << int(Segundo(mult))
		 << "," << setfill('0') << setw(3) << int(Terceiro(mult))
		 << "," << setfill('0') << setw(3) << int(Quarto(mult))
		 << "] = Multiplicações" << endl;  // Mostra os valores dos produtos entre os números inseridos pelo usuário usando 3 digitos

	unsigned long long somaCripto = Codificar(soma); // Codifica o valor de 32 bits da soma
	unsigned long long multCripto = Codificar(mult); // Codifica o valor de 322 bits da multiplicação

	cout << endl; // Pula uma linha
	cout << "Soma Cripto 64 bit = " << somaCripto << endl; // Mostra o valor codificado da soma
	cout << "Mult Cripto 64 bit = " << multCripto << endl; // Mostra o valor codificado da multiplicação

	unsigned int somaCripto32 = somaCripto >> 32; // Guarda o valor de 32 bits codificado da soma
	unsigned int somaPosicoes = somaCripto; // Guarda as posições dos bits invetidos no valor de 32 bits da soma
	unsigned int multCripto32 = multCripto >> 32; // Guarda o valor de 32 bits codificado da multiplicação
	unsigned int multPosicoes = multCripto; // Guarda as posições dos bits invetidos no valor de 32 bits da soma

	unsigned short somaPosicao1 = somaPosicoes >> 27; // Pega a primeira posição da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao2 = ((somaPosicoes << 5) >> 27); // Pega a segunda posição da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao3 = ((somaPosicoes << 10) >> 27); // Pega a terceira posição da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao4 = ((somaPosicoes << 15) >> 27); // Pega a quarta posição da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao5 = ((somaPosicoes << 20) >> 27); // Pega a quinta posição da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao6 = ((somaPosicoes << 25) >> 27); // Pega a sexta posição da soma transformando os bits ao seu redor em zero

	unsigned short multPosicao1 = multPosicoes >> 27; // Pega a primeira posição da multiplicação transformando os bits ao seu redor em zero
	unsigned short multPosicao2 = ((multPosicoes << 5) >> 27); // Pega a segunda posição da multiplicação transformando os bits ao seu redor em zero
	unsigned short multPosicao3 = ((multPosicoes << 10) >> 27); // Pega a terceira posição da multiplicação transformando os bits ao seu redor em zero
	unsigned short multPosicao4 = ((multPosicoes << 15) >> 27); // Pega a quarta posição da multiplicação transformando os bits ao seu redor em zero
	unsigned short multPosicao5 = ((multPosicoes << 20) >> 27); // Pega a quinta posição da multiplicação transformando os bits ao seu redor em zero
	unsigned short multPosicao6 = ((multPosicoes << 25) >> 27); // Pega a sexta posição da multiplicação transformando os bits ao seu redor em zero

	cout << endl; // Pula uma linha
	cout << "Valor Codificado = " << somaCripto32 << " "
		 << "(" << somaPosicao1 << " " << somaPosicao2
		 << " " << somaPosicao3 << " " << somaPosicao4
		 << " " << somaPosicao5 << " " << somaPosicao6
		 << ")\n"; // Mostra o valor da soma em 32 bits e as posições em que os bits foram invertidos
	cout << "Soma Decodificada = " << Decodificar(somaCripto) << endl; // Mostra o valor da soma em 32 bits decodificado

	cout << endl; // Pula uma linha
	cout << "Valor Codificado = " << multCripto32 << " "
		<< "(" << multPosicao1 << " " << multPosicao2
		<< " " << multPosicao3 << " " << multPosicao4
		<< " " << multPosicao5 << " " << multPosicao6
		<< ")\n"; // Mostra o valor da multiplicação em 32 bits e as posições em que os bits foram invertidos
	cout << "Mult Decodificada = " << Decodificar(multCripto) << endl; // Mostra o valor da soma em 32 bits decodificado

	cout << endl; // Pula uma linha
	system("pause"); // Espera apra continuar o programa até o usuário pressionar alguma tecla
	return 0; // Retorna zero da função, e acaba o programa
}