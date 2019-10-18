// Biblioteca SIMD - Biblioteca com as fun�oes necess�rias para simular SIMD

// Fun��o Armazena - Fun��o que armazena quatro valores de 8 bits em uma valor de 32 bits
unsigned int Armazena(unsigned char primeiro, unsigned char segundo, unsigned char terceiro, unsigned char quarto) {
	unsigned int bit32 = primeiro; // Armazena o primeiro valor na vari�vel "bit32"
	bit32 = bit32 << 8; // Move os bits 8 locais para a esquerda
	bit32 += segundo; // Armazena o segundo valor na vari�vel "bit32"
	bit32 = bit32 << 8; // Move os bits 8 locais para a esquerda
	bit32 += terceiro; // Armazena o terceiro valor na vari�vel "bit32"
	bit32 = bit32 << 8; // Move os bits 8 locais para a esquerda
	bit32 += quarto; // Armazena o quarto valor na vari�vel "bit32"

	return bit32; // Retorna os quatro valores armazenados em uma vari�vel de 32 bits
}

// Fun��o Primeiro - Fun��o que retorna o primeiro valor de 8 bits de um valor de 32 bit
unsigned char Primeiro(unsigned int bit32) {
	unsigned char numero = bit32 >> 24; // Move os bit 24 locais para a direita, "cortando" os outros bits, e o atribui em "numero"
	return numero; // Retorna o primeiro valor de 8 bits
}

// Fun��o Segundo - Fun��o que retorna o segundo valor de 8 bits de um valor de 32 bit
unsigned char Segundo(unsigned int bit32) {
	unsigned char numero = bit32 >> 16; // Move os bit 24 locais para a direita, "cortando" os outros bits, e o atribui em "numero"
	return numero; // Retorna o segundo valor de 8 bits
}

// Fun��o Terceiro - Fun��o que retorna o terceiro valor de 8 bits de um valor de 32 bit
unsigned char Terceiro(unsigned int bit32) {
	unsigned char numero = bit32 >> 8; // Move os bit 24 locais para a direita, "cortando" os outros bits, e o atribui em "numero"
	return numero; // Retorna o terceiro valor de 8 bits
}

// Fun��o Quarto - Fun��o que retorna o quarto valor de 8 bits de um valor de 32 bit
unsigned char Quarto(unsigned int bit32) {
	unsigned char numero = bit32; // Atribui o quarto valor a "numero"
	return numero; // Retorna o quarto valor de 8 bits
}

// Fun��o Soma - Fun��o que faz as quatro somas de 8 bits dos valores retirados dos valores em 32 bits, e as retorna em um valor de 32 bits
unsigned int Soma(unsigned int valor1, unsigned int valor2) {
	unsigned int soma1, soma2, soma3, soma4; // Declara as vari�veis que guardar�o as somas
	soma1 = Primeiro(valor1) + Primeiro(valor2); // Atribui a soma dos primeiros numeros de 8 bits a "soma1"
	soma2 = Segundo(valor1) + Segundo(valor2); // Atribui a soma dos segundos numeros de 8 bits a "soma2"
	soma3 = Terceiro(valor1) + Terceiro(valor2); // Atribui a soma dos terceiros numeros de 8 bits a "soma3"
	soma4 = Quarto(valor1) + Quarto(valor2); // Atribui a soma dos quartos numeros de 8 bits a "soma4"
	return Armazena(soma1, soma2, soma3, soma4); // Retorna as quatro somas armazenadas em um valor de 32 bits
}

// Fun��o Mult - Fun��o que faz os quatro produtos de 8 bits dos valores retirados dos valores em 32 bits, e as retorna em um valor de 32 bits
unsigned int Mult(unsigned int valor1, unsigned int valor2) {
	unsigned int produto1, produto2, produto3, produto4; // Declara as vari�veis que guardar�o os produtos
	produto1 = Primeiro(valor1) * Primeiro(valor2); // Atribui o produto dos primeiros numeros de 8 bits a "produto1"
	produto2 = Segundo(valor1) * Segundo(valor2); // Atribui o produto dos segundos numeros de 8 bits a "produto2"
	produto3 = Terceiro(valor1) * Terceiro(valor2); // Atribui o produto dos terceiros numeros de 8 bits a "produto3"
	produto4 = Quarto(valor1) * Quarto(valor2); // Atribui o produto dos quartos numeros de 8 bits a "produto4"
	return Armazena(produto1, produto2, produto3, produto4); // Retorna os quatro produtos armazenados em um valor de 32 bits
}