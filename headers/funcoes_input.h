#include <unistd.h>

#ifndef _INPUT_FUNCTIONS
	#define _INPUT_FUNCTIONS

	/** @brief Limpa o buffer de escrita para remover o caractere de quebra de linha que remanece após certas funções.
	 *
	 *	@par @warning
	 *  Se utilizada após funções que não abandonem o caractere de quebra de linha, irá travar o código até que algum input seja fornecido,
	 *  tal qual um getchar() comum.
	 */
	void clean_buffer(void);


	/** @brief Recebe string do usuário t e remove o caractere de nova linha \n do final da string.
	 *
	 * @param string	<- Ponteiro pra string que irá receber a entrada.
	 * @param t		<- Tamanho máximo de string.
	 *
	 */
	void input_string(char *string, size_t tam);


	/** @brief: Recebe um caractere, tal qual o getchar(). Entretanto, sem a necessidade de apertar enter pra enviar o caractere.
	 *
	 *	@par @note:
	 * Desativa o buffer de linha temporariamente para ler um caractere sem o enter para enviar o input.
	 *
	 */
	int input_char(void);

#endif
