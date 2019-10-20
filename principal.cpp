// Arquivo principal - cont�m a fun��o "main" que chama as fun��es da outras bibliotecas para simular SIMD e codifica��o 

#include <iostream> // Inclus�o da biblioteca padr�o de entrada e sa�da de dados
#include <cstdlib> // Inclus�o da biblioteca para usar fun��es "system"
#include <iomanip> // Inclus�o da biblioteca usada para manipular a sa�da de dados
#include "simd.h" // Inclus�o da biblioteca que cont�m as fun��es para simular SIMD
#include "cripto.h" // Inclus�o da biblioteca que cont�m as fun��es para codifica��o
using namespace std;

int main() {
	system("chcp 1252 > nul"); // Comando para possibilitar a sa�da de caracteres acentuados

	// Declara��o das vari�veis que ser�o atribu�das pelo usu�rio
	unsigned short xxma1, xxma2, xxma3, xxma4;
	unsigned short xxmb1, xxmb2, xxmb3, xxmb4;

	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxma1; // Atribu��o do usu�rio a uma vari�vel
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxma2; // Atribu��o do usu�rio a uma vari�vel
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxma3; // Atribu��o do usu�rio a uma vari�vel
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxma4; // Atribu��o do usu�rio a uma vari�vel
	cin.ignore(); // Comando para ignorar um caracter no buffer

	cin.ignore(); // Comando para ignorar um caracter no buffer

	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxmb1; // Atribu��o do usu�rio a uma vari�vel
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxmb2; // Atribu��o do usu�rio a uma vari�vel
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxmb3; // Atribu��o do usu�rio a uma vari�vel
	cin.ignore(); // Comando para ignorar um caracter no buffer
	cin >> xxmb4; // Atribu��o do usu�rio a uma vari�vel
	cin.ignore(); // Comando para ignorar um caracter no buffer

	unsigned int xxma = Armazena(xxma1, xxma2, xxma3, xxma4); // Armazena as vari�veis atribuidas pelo usu�rio em uma vari�vel de 32 bits
	unsigned int xxmb = Armazena(xxmb1, xxmb2, xxmb3, xxmb4); // Armazena as vari�veis atribuidas pelo usu�rio em uma vari�vel de 32 bits

	
	cout << endl; // Pula uma linha
	cout << "Operandos em 32 bit = " << xxma << endl; // Mostra o valor de 32 bits que cont�m as vari�veis atribuidas pelo usu�rio
	cout << "Operandos em 32 bit = " << xxmb << endl; // Mostra o valor de 32 bits que cont�m as vari�veis atribuidas pelo usu�rio

	unsigned int soma = Soma(xxma, xxmb); // Soma os valores armazenados nas vari�veis de 32 bits
	unsigned int mult = Mult(xxma, xxmb); // Multiplica os valores armazenados nas vari�veis de 32 bits

	cout << endl; // Pula uma linha
	cout << "Soma em 32 bit = " << soma << endl; // Mostra a soma dos valores armazenados nas vari�veis de 32 bits
	cout << "Mult em 32 bit = " << mult << endl; // Mostra a multiplica��o dos valores armazenados nas vari�veis de 32 bits

	cout << endl; // Pula uma linha
	cout << "[" << setfill('0') << setw(3) << int(Primeiro(soma))
		 << "," << setfill('0') << setw(3) << int(Segundo(soma))
		 << "," << setfill('0') << setw(3) << int(Terceiro(soma))
		 << "," << setfill('0') << setw(3) << int(Quarto(soma))
		 << "] = Somas" << endl; // Mostra os valores das somas entre os n�meros inseridos pelo usu�rio usando 3 digitos

	cout << "[" << setfill('0') << setw(3) << int(Primeiro(mult))
		 << "," << setfill('0') << setw(3) << int(Segundo(mult))
		 << "," << setfill('0') << setw(3) << int(Terceiro(mult))
		 << "," << setfill('0') << setw(3) << int(Quarto(mult))
		 << "] = Multiplica��es" << endl;  // Mostra os valores dos produtos entre os n�meros inseridos pelo usu�rio usando 3 digitos

	unsigned long long somaCripto = Codificar(soma); // Codifica o valor de 32 bits da soma
	unsigned long long multCripto = Codificar(mult); // Codifica o valor de 322 bits da multiplica��o

	cout << endl; // Pula uma linha
	cout << "Soma Cripto 64 bit = " << somaCripto << endl; // Mostra o valor codificado da soma
	cout << "Mult Cripto 64 bit = " << multCripto << endl; // Mostra o valor codificado da multiplica��o

	unsigned int somaCripto32 = somaCripto >> 32; // Guarda o valor de 32 bits codificado da soma
	unsigned int somaPosicoes = somaCripto; // Guarda as posi��es dos bits invetidos no valor de 32 bits da soma
	unsigned int multCripto32 = multCripto >> 32; // Guarda o valor de 32 bits codificado da multiplica��o
	unsigned int multPosicoes = multCripto; // Guarda as posi��es dos bits invetidos no valor de 32 bits da soma

	unsigned short somaPosicao1 = somaPosicoes >> 27; // Pega a primeira posi��o da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao2 = ((somaPosicoes << 5) >> 27); // Pega a segunda posi��o da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao3 = ((somaPosicoes << 10) >> 27); // Pega a terceira posi��o da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao4 = ((somaPosicoes << 15) >> 27); // Pega a quarta posi��o da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao5 = ((somaPosicoes << 20) >> 27); // Pega a quinta posi��o da soma transformando os bits ao seu redor em zero
	unsigned short somaPosicao6 = ((somaPosicoes << 25) >> 27); // Pega a sexta posi��o da soma transformando os bits ao seu redor em zero

	unsigned short multPosicao1 = multPosicoes >> 27; // Pega a primeira posi��o da multiplica��o transformando os bits ao seu redor em zero
	unsigned short multPosicao2 = ((multPosicoes << 5) >> 27); // Pega a segunda posi��o da multiplica��o transformando os bits ao seu redor em zero
	unsigned short multPosicao3 = ((multPosicoes << 10) >> 27); // Pega a terceira posi��o da multiplica��o transformando os bits ao seu redor em zero
	unsigned short multPosicao4 = ((multPosicoes << 15) >> 27); // Pega a quarta posi��o da multiplica��o transformando os bits ao seu redor em zero
	unsigned short multPosicao5 = ((multPosicoes << 20) >> 27); // Pega a quinta posi��o da multiplica��o transformando os bits ao seu redor em zero
	unsigned short multPosicao6 = ((multPosicoes << 25) >> 27); // Pega a sexta posi��o da multiplica��o transformando os bits ao seu redor em zero

	cout << endl; // Pula uma linha
	cout << "Valor Codificado = " << somaCripto32 << " "
		 << "(" << somaPosicao1 << " " << somaPosicao2
		 << " " << somaPosicao3 << " " << somaPosicao4
		 << " " << somaPosicao5 << " " << somaPosicao6
		 << ")\n"; // Mostra o valor da soma em 32 bits e as posi��es em que os bits foram invertidos
	cout << "Soma Decodificada = " << Decodificar(somaCripto) << endl; // Mostra o valor da soma em 32 bits decodificado

	cout << endl; // Pula uma linha
	cout << "Valor Codificado = " << multCripto32 << " "
		<< "(" << multPosicao1 << " " << multPosicao2
		<< " " << multPosicao3 << " " << multPosicao4
		<< " " << multPosicao5 << " " << multPosicao6
		<< ")\n"; // Mostra o valor da multiplica��o em 32 bits e as posi��es em que os bits foram invertidos
	cout << "Mult Decodificada = " << Decodificar(multCripto) << endl; // Mostra o valor da soma em 32 bits decodificado

	cout << endl; // Pula uma linha
	system("pause"); // Espera apra continuar o programa at� o usu�rio pressionar alguma tecla
	return 0; // Retorna zero da fun��o, e acaba o programa
}