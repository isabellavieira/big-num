/*--------------------------------------------------------------------------*/
/* 			     Universidade Federal de São João del - Rei 
			        Algoritmos e Estrutura de Dados III
		        	Ciência da Computação - 3º período
      
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Março / 2012                */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* Este código possui as seguintes funções:
 
   - Criar uma lista duplamente encadeada com descritor
   - Destruir a lista
   - Somar duas listas
   - Subtrair duas listas 
   - Multiplicar duas listas
   - Dividir duas listas
   - Imprimir  
                                                                            */
/*--------------------------------------------------------------------------*/

#include "big_num.h"

/*--------------------------------------------------------------------------*/
/* Função responsável por criar a lista duplamente encadeada com descritores.
   Possui célula cabeça.                                                    */
/*--------------------------------------------------------------------------*/

void criar(lista *num){
	
	num->primeiro = (Apontador) malloc(sizeof(celula));
	num->ultimo = num->primeiro;
	num->primeiro->prev = NULL;
	num->primeiro->prox = NULL;
	num->primeiro->chave = 111;         /*identificador para a célula cabeça.*/
	num->tam = 0;	
	
}


/*--------------------------------------------------------------------------*/
/* Função responsável por destruir a lista.                                 */
/*--------------------------------------------------------------------------*/

void destruir (lista *num) {

	Apontador aux;

	while (num->primeiro != NULL) {

		aux = num->primeiro;
		num->primeiro = num->primeiro->prox;
		free(aux);

	}
}


/*--------------------------------------------------------------------------*/
/* Função responsável por somar os elementos na lista.
   num1 = lista que contém a primeira parcela.
   num2 = lista que contém a segunda parcela.
   resultado = lista que contém o resultado da soma.                        */
/*--------------------------------------------------------------------------*/

void somar (lista *num1, lista *num2, lista *resultado){
	
	int vai = 0;
	int result = 0;

	/* Apontadores auxiliares para a primeira e segunda parcela */
	Apontador aux1, aux2;

	/* Algarismos menos significativos - número na ordem certa */
	aux1 = num1->ultimo;
	aux2 = num2->ultimo;
	
	/* Percorrendo a lista de trás para a frente - enquanto não for a célula cabeça */
	while (aux1->chave != 111 && aux2->chave != 111){
	
		if ((aux1->chave + aux2->chave + vai) > 9){
			
			result = (aux1->chave + aux2->chave + vai) - 10;
			inserir (result, &(*resultado));
			vai = 1;		
			
		} else {
			
			result = aux1->chave + aux2->chave + vai;
			inserir (result, &(*resultado));
			vai = 0;
			
		}
		
		aux1 = aux1->prev;
		aux2 = aux2->prev;	
		
	}
	
	/* Caso a primeira parcela não tenha acabado e a segunda já. */
	if (aux1->chave != 111){
	
		while (aux1->chave != 111){
			
			if ((aux1->chave + vai) > 9){
				
				result =  (aux1->chave + vai)- 10;
				inserir (result, &(*resultado));				
				vai = 1;
				
			} else {
				
				result = aux1->chave + vai;
				inserir (result, &(*resultado));
				vai = 0;
			}
			
			aux1 = aux1->prev;
			
		}
		
	} else if (aux2->chave != 111){         /* Caso a segunda parcela não tenha acabado e a primeira já. */
	
		while (aux2->chave != 111){
			
			if ((aux2->chave + vai) > 9){
				
				result = (aux2->chave + vai)-10;
				inserir (result, &(*resultado));
				vai = 1;
			
			} else {
				
				result = aux2->chave + vai;
				inserir (result, &(*resultado));
				vai = 0;
				
			}
			
			aux2 = aux2->prev;
		}
	}
	
	if (vai != 0) {
		
		inserir (vai, &(*resultado));
		vai = 0;
		
	}
	
	destruir (&(*num1));
	destruir (&(*num2));
	
}


/*--------------------------------------------------------------------------*/
/* Função responsável por subtrair os elementos da lista.                   */
/*--------------------------------------------------------------------------*/

void subtrair (lista *minuendo, lista *subtraendo, lista *diferenca) {
	
	int vai = 0;
	int result = 0;

	Apontador aux1, aux2;
	
	if (valida_lista(&(*minuendo), &(*subtraendo)) == 1) {

		aux1 = minuendo->ultimo;    
		aux2 = subtraendo->ultimo; 		
	
	} else {
			
		aux1 = subtraendo->primeiro->prox; 
		aux1->chave = (0 - aux1->chave );
		
		aux2 = minuendo->primeiro->prox;		
		aux2->chave = (0 - aux2->chave );
		
		aux1 = subtraendo->ultimo;	
		aux2 = minuendo->ultimo;
	}
	
   while (aux1->chave != 111 && aux2->chave != 111) {

			if (((aux1->chave - vai) >= aux2->chave) && (aux2->chave >= 0)) {
				
				result = (aux1->chave - vai) - aux2->chave;
				inserir (result, &(*diferenca)); 
				vai = 0;
				
			} else if (aux1->chave < 0) {           /* Se a chave for negativa*/
				
				result = (aux1->chave + vai) - aux2->chave;
				
				if (result == 0) {          /* Se for zero, o sinal de negativo é colocado no nº anterior */
					
					diferenca->ultimo->chave = (0 - diferenca->ultimo->chave);
				
				} else {
					inserir (result, &(*diferenca));
				}
			
			} else if (aux2->chave < 0){
				
				if ((aux1->chave - vai) < (0 - aux2->chave)){
					
					result = ((aux1->chave - vai) + 10) - (0 - aux2->chave);
					inserir (result, &(*diferenca));
					vai = 1;
				
				} else {
				
					result = (aux1->chave - vai)  - (0 - aux2->chave);
					inserir (result, &(*diferenca));
					vai = 0;
				
				}
			
			} else { 				
				
				result = ((aux1->chave - vai) + 10)- aux2->chave;	
				inserir (result, &(*diferenca)); 
				vai = 1;
				
			}
			
			aux1 = aux1->prev;  
			aux2 = aux2->prev; 
			 
	} 
	
	if (aux1->chave != 111) {
		
		while (aux1->chave != 111) {
		
			if (aux1->chave < 0) {

			      result = aux1->chave + vai;
			      vai = 0;			
					
			} else if (aux1->chave < vai) {
								
				result = (aux1->chave + 10)- vai;
				vai = 1;
				
			} else { 
				result = aux1->chave - vai;
				vai = 0;
			}			
			
			inserir (result, &(*diferenca));
			aux1 = aux1->prev; 
		
		}
	}
	
	destruir (&(*minuendo));
	destruir (&(*subtraendo));
}	


/*--------------------------------------------------------------------------*/
/* Função responsável por multiplicar os elementos da lista.                */ 
/*--------------------------------------------------------------------------*/

void multiplicar (lista *multiplicando, lista *multiplicador, lista *produto) {

	int vai = 0, result = 0, x = 0;	
	
	/* Apontadores auxiliares para o multiplicando, multiplicador e produto, respectivamente */
	Apontador aux1, aux2, aux3;	
	
	Apontador shift;


	inserir (0, &(*produto));
	
	shift = produto->primeiro->prox;   
	
	/* Caso o multiplicando seja de tamanho menor que o multiplicador, inverte a ordem */
	if (multiplicando->tam == 1) {
		
		aux1 = multiplicador->ultimo; 
		aux2 = multiplicando->ultimo;  
		
	} else {
		
		aux1 = multiplicando->ultimo;  
		aux2 = multiplicador->ultimo; 
	
	}

	aux3 = produto->primeiro->prox;
	
	/* Enquanto o multiplicador não acabar, multiplica. */
	while (aux2->chave != 111) {
	
		/* Enquanto o multiplicando não acabar, multiplica. */
		while(aux1->chave != 111) {

			if ((aux1->chave * aux2->chave + vai) > 9) {
			
				x = aux1->chave * aux2->chave + vai;
				vai = x / 10;
				result = (x % 10);
				
				if (aux3 == NULL){					
					
					inserir (result, &(*produto));

				} else {
					
					if (aux3->chave + result > 9) {
			
						result = (aux3->chave + result) - 10;
						aux3->chave = result;
						vai = vai + 1;
						aux3 = aux3->prox;
								
					} else {
															
						aux3->chave =  aux3->chave + result;
						aux3 = aux3->prox;
						
					}
				}

			} else {
				
				result = aux1->chave * aux2->chave + vai;
				vai = 0;
				
				if (aux3 == NULL){		
								
					inserir (result, &(*produto));
				
				} else	if (aux3->chave + result > 9) {
			
						result = (aux3->chave + result) - 10;
						aux3->chave = result;
						vai = vai + 1;
						aux3 = aux3->prox;		
			
				} else {
															
						aux3->chave =  aux3->chave + result;
						aux3 = aux3->prox;
						
					}
					
				}

				aux1 = aux1->prev;				

			}
			
			aux2 = aux2->prev;
			aux1 = multiplicando->ultimo;
			shift = shift->prox;        
			aux3 = shift;

			if (vai != 0){
				
				inserir (vai, &(*produto));
				vai = 0;
				
			}
	} 	
			
}


/*--------------------------------------------------------------------------*/
/* Função responsável por dividir os elementos da lista.  
/*--------------------------------------------------------------------------*/

void divisao (lista *dividendo, lista *divisor, lista *quociente) {
	 
	 lista lista_aux_dividendo, multiplicador, resultado_multiplicacao, resto, desinvertido;
	 
	 Apontador aux_dividendo, aux_quociente, aux_divisor, aux_lista_dividendo, aux_resto;
	 
	 int x, divisao, num, flag = 0;
	 
	
	 aux_dividendo = dividendo->primeiro->prox;	 
	 
	 aux_quociente = quociente->primeiro;	 
	 
	 aux_divisor = divisor->primeiro->prox;
	  
	 x = valida_lista(&(*dividendo), &(*divisor));
	 
	/* se o tamanho da lista do dividendo for menor que a do divisor */
 	if (x == 0) {   
		 
		inserir (0,&(*quociente));
		
	} else if (x == 2) {      //se os dois numeros forem iguais
		
		inserir (1,&(*quociente));
		
	} else {     /* se o tamanho da lista do dividendo for maior que a do divisor, entao, divide */
		
		criar (&lista_aux_dividendo);
		
		criar (&multiplicador);		
		
		inserir (0, &multiplicador);	
		
		while (aux_dividendo != NULL) {
			
			aux_lista_dividendo = lista_aux_dividendo.primeiro->prox;

			while (aux_lista_dividendo == NULL && aux_dividendo->chave == 0 ){ 
			
				inserir (0, &(*quociente));
				
				aux_dividendo = aux_dividendo->prox;	

				if (aux_dividendo == NULL){
					
					destruir (&lista_aux_dividendo);
					destruir (&multiplicador);	
					destruir (&(*dividendo));		
					destruir (&(*divisor));
					
					return;
			
				}
		
			}
						
			inserir(aux_dividendo->chave, &lista_aux_dividendo);	
			
			aux_dividendo = aux_dividendo->prox;	
			
			aux_lista_dividendo = lista_aux_dividendo.primeiro->prox;
							
			x = valida_lista(&lista_aux_dividendo, &(*divisor));
			
			/* se o primeiro que pegar nao der p dividir, continua percorrendo o dividendo */
			while (x == 0) {
				
				if (flag == 1){
				
					inserir (0, &(*quociente));
				
				}
				
				if (aux_dividendo == NULL){
			
					destruir (&lista_aux_dividendo);
					destruir (&multiplicador);	
					destruir (&(*dividendo));		
					destruir (&(*divisor));			
			
					return;
								
				} else {
				
				inserir(aux_dividendo->chave, &lista_aux_dividendo);
				
				aux_dividendo = aux_dividendo->prox;			
				
				x = valida_lista(&lista_aux_dividendo, &(*divisor));
				
				}
			}
		
			
			if (aux_lista_dividendo->chave > aux_divisor->chave){
				
				divisao = aux_lista_dividendo->chave / aux_divisor->chave;
				
				multiplicador.primeiro->prox->chave = divisao;
			
				criar (&resultado_multiplicacao);
				
				multiplicar (&(*divisor), &multiplicador, &resultado_multiplicacao);
			
				criar (&desinvertido);
				
				desinverte (&resultado_multiplicacao, &desinvertido);				
			
			} else if (aux_lista_dividendo->chave == aux_divisor->chave) {
				
			  multiplicador.primeiro->prox->chave = 10;
       		
       		  x = 1;

				while (x == 1){
					
					criar (&resultado_multiplicacao);
					
					multiplicador.primeiro->prox->chave = multiplicador.primeiro->prox->chave - 1;
					
					multiplicar (&(*divisor), &multiplicador, &resultado_multiplicacao);
					
					criar (&desinvertido);				
					
					desinverte (&resultado_multiplicacao, &desinvertido);
					
					x = valida_lista (&desinvertido, &lista_aux_dividendo);
					
					if (x == 1){
						
						destruir (&desinvertido);
						
					}
				}
				
			} else { /* se (aux_lista_dividendo->chave < aux_divisor->chave */
			
				num = aux_lista_dividendo->chave * 10;
				
				aux_lista_dividendo = aux_lista_dividendo->prox;
				
				divisao = (num + aux_lista_dividendo->chave)/ aux_divisor->chave;
				
				multiplicador.primeiro->prox->chave = divisao;
				
				criar (&resultado_multiplicacao);
				
				multiplicar (&(*divisor), &multiplicador, &resultado_multiplicacao);
			
				criar (&desinvertido);
				
				desinverte (&resultado_multiplicacao, &desinvertido);			
			}
		
			/* Se for maior */
			while (valida_lista (&desinvertido, &lista_aux_dividendo) == 1){
				
				destruir (&desinvertido);
				
				criar (&resultado_multiplicacao);
				
				multiplicador.primeiro->prox->chave = multiplicador.primeiro->prox->chave - 1;
				
				multiplicar (&(*divisor), &multiplicador, &resultado_multiplicacao);
				
				criar (&desinvertido);	
							
				desinverte (&resultado_multiplicacao, &desinvertido);
				
			}

			inserir (multiplicador.primeiro->prox->chave, &(*quociente));
				
			criar (&resto);
			
			subtrair (&lista_aux_dividendo, &desinvertido, &resto);
		
			flag = 1;
			
			destruir (&desinvertido);
			
			destruir (&lista_aux_dividendo);
			
			criar (&lista_aux_dividendo);
			
			aux_resto = resto.ultimo;
			
			while (aux_resto->chave == 0){
			
				aux_resto = aux_resto->prev; 
			
			}
			
			while (aux_resto->chave != 111){
			
				inserir (aux_resto->chave, &lista_aux_dividendo);
				aux_resto = aux_resto->prev; 
			
			}
			
			destruir (&resto);
		
		}/* enquanto o dividendo não acabar */
		
	destruir (&lista_aux_dividendo);
	destruir (&multiplicador);	
	destruir (&(*dividendo));		
	destruir (&(*divisor));
	
	}/* senão dá para dividir */
	
}/* função */


/*--------------------------------------------------------------------------*/
/*Função responsável por imprimir o resultado da combinação em um arquivo.  */
/*--------------------------------------------------------------------------*/

void imprimir (lista resultado_final, FILE *saida) {   /* resultado_final é o que vem da subtracao */
	
	Apontador aux_resultado;
	
	aux_resultado = resultado_final.ultimo;
	
	
	while (aux_resultado->chave == 0 ){
	
		aux_resultado = aux_resultado->prev;
	
	}
	
	while (aux_resultado->chave != 111) {
		
		fprintf (saida, "%d", aux_resultado->chave);
		aux_resultado = aux_resultado->prev;
		
	}
	
}
