#include <unistd.h>

#ifndef _INPUT_FUNCTIONS
	#define _INPUT_FUNCTIONS

	/** @brief Encontra espaço vazio em uma lista de tamanho t
	 *
	 * @param lista - Ponteiro para a lista (Individuo ou Disciplina).
	 * @param tipo - Tipo da lista ('P' para individuo e 'D' para disciplina).
	 * @param t - Tamanho máximo da lista
	 *
	 * @return Index do espaço vazio em sucesso, SEM_VAGA se não houver vaga, TIPO_INVALIDO se *tipo* não for 'P' ou 'D'.
	 *
	 * @par @note
	 * Verifica um vetor (lista) de tamanho fornecido pelo código (tam) procurando por, caso seja um
	 * indivíduo, a sua matrícula, caso seja uma disciplina, o seu código (checa se o primeiro caractere é um \0 ou não).
	 *
	 * @par @note
	 * O objetivo dessa função é retornar o index para um vetor que conterá: Alunos, Professores ou Disciplinas para que
	 * possa ser cadastrado um novo item para o vetor. Caso o vetor esteja cheio (sem espaço para cadastro), irá retornar a
	 * macro de vetor cheio e caso o tipo seja especificado incorretamente, irá retornar a macro de tipo inválido.
	 * A função busca, para o tipo indivíduo, um valor de matrícula == VAGA_LIVRE (0) e, para o tipo disciplina, busca o
	 * valor codigo[0] == HORARIO_VAGO (\0)  (Busca o primeiro caractere como um NULL Terminator). Esses são os critérios
	 * para determinar se há ou não espaço para um novo Aluno/Professor ou Disciplina
	 *
	 */
	int procura_vaga(void* lista, size_t tam, char tipo);

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
