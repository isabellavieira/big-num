/*--------------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
      
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Março / 2012                                        */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* Este código possui as seguintes funções:
 
 - Inserir elementos na lista
 - Valida_lista - responsável por verificar o tamanho da lista         
                                             							    */                            
/*--------------------------------------------------------------------------*/

#include "funcoes_extras.h"

/*--------------------------------------------------------------------------*/
/* Função responsável por inserir elementos na lista.                       */
/*--------------------------------------------------------------------------*/

void inserir(int n, lista *num){

	Apontador aux;

		num->ultimo->prox = (Apontador) malloc(sizeof(celula));
		aux = num->ultimo;
		num->ultimo = num->ultimo->prox;
		num->ultimo->prox = NULL;
		num->ultimo->prev = aux;
		num->ultimo->chave = n;
		num->tam = num->tam + 1;
	
}


/*-------------------------------------------------------------------------------*/
/* Função responsável por verificar o tamanho de uma lista. Retorna 1, se uma
	lista for maior que a outra, 0 se for menor e 2 se os tamanhos forem iguais. */ 
/*-------------------------------------------------------------------------------*/

int valida_lista (lista *num1, lista *num2){

	Apontador aux1, aux2;

	/* Algarismo mais significativo */
	aux1 = num1->primeiro->prox; 
	aux2 = num2->primeiro->prox; 
	
	if (num1->tam > num2->tam){
		
		return 1;
		
	} else if (num1->tam < num2->tam){
	
		return 0;
	
	} else {
			
		while (aux1 != NULL && aux2 != NULL){
		
			if (aux1->chave > aux2->chave){
				
				return 1;
				
			} else if (aux1->chave < aux2->chave){
				
				return 0;	
				
			} else {
				
				aux1 = aux1->prox; 
				aux2 = aux2->prox;
				
			}
		}
	}
	
	/* Se os números forem iguais */
	return 2;
}
