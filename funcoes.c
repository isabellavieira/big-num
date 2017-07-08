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
 
   - Desinverte
   - Fatorial
   - Combinação
																			*/				                            
/*--------------------------------------------------------------------------*/

#include "funcoes.h"

/*--------------------------------------------------------------------------*/
/* Função responsável por guardar em uma lista os resultados desivertidos, 
	pois algumas operações guardam na lista o resultado invertido (de trás 
	para frente).                                                           */ 
/*--------------------------------------------------------------------------*/

void desinverte (lista *num1, lista *resultado_desinvertido) {
	
	Apontador aux;	

	aux = num1->ultimo;
	
	while (aux->chave != 111){
		
		inserir (aux->chave, &(*resultado_desinvertido));
		aux = aux->prev;
	
	}
	
	destruir (&(*num1));
}


/*--------------------------------------------------------------------------*/
/* Função responsável por calcular o fatorial de um número na lista.	    */ 
/*--------------------------------------------------------------------------*/

void fatorial (int n, lista *result) {         

	lista num1,num2;
	int i,vai,resto, x;
	Apontador aux, aux1,aux2;
	
	criar (&num1);
	criar (&num2);
	
	if (n == 1 || n == 0){
		
		inserir (1, &(*result));
		return;
		
	}
			
	if (n <= 9 && n != 0 && n != 1) {
		
		inserir(n, &num1);
		
	} else if (n <= 99 && n >= 10) {
		
		vai = n/10;
		resto = n%10;  
		
		inserir(vai,&num1);
		inserir(resto,&num1);
		
	} else if ( n <= 999 && n >= 100) {
		
		vai = n/100;
		inserir(vai,&num1);
		
		resto = n%100;		
		vai =  resto / 10;
		inserir(vai,&num1);		
		
		resto = resto % 10;
		inserir(resto,&num1);
		
	} else if (n <= 9999 && n >= 1000) {
		
		vai = n/1000;
		inserir(vai,&num1);
				
		resto = n%1000;
		vai = resto/100;
		inserir(vai,&num1);
				
		resto = resto%100;
		vai = resto/10;
		inserir(vai,&num1);
				
		resto = resto % 10;
		inserir(resto,&num1);
		
	}
	else {
		
		printf("Não é possível calcular o fatorial, número com mais de 4 digitos!\n");
		
	}
		
	if (n != 0 && n != 1) { 	
		
		x = n-1;
		
		for (i=x; i>=1; i--) {
		
			if (i <= 9) {
		
			inserir(i, &num2);
		
			} else if (i <= 99 && i >= 10) {
			
				vai = i/10;
				resto = i%10;  
			
				inserir(vai,&num2);
				inserir(resto,&num2);
		
			} else if ( i <= 999 && i >= 100) {
		
				vai = n/100;
				inserir(vai,&num2);
		
				resto = n%100;		
				vai =  resto / 10;
				inserir(vai,&num2);		
			
				resto = resto % 10;
				inserir(resto,&num2);
		
			} else if (i <= 9999 && i >= 1000) {
	
				vai = n/1000;
				inserir(vai,&num2);
				
				resto = n%1000;
				vai = resto/100;
				inserir(vai,&num2);
				
				resto = resto%100;
				vai = resto/10;
				inserir(vai,&num2);
				
				resto = resto % 10;
				inserir(resto,&num2);
		
			} else {
		
			printf("Não é possível calcular o fatorial, número com mais de 4 digitos! \n");
			break;
		
			}
	
			criar (&(*result));
			
			multiplicar(&num1, &num2, &(*result));
			
			destruir(&num1);
			destruir (&num2);
		
			criar (&num1);		
			criar (&num2);
				
			//Para nao ser a celular cabeca (111)
			aux = result->ultimo;
		
			while (aux->chave != 111) {
			
				inserir(aux->chave, &num1);
				aux = aux->prev;
				
			}
		}
	}
	
		destruir(&num1);
		destruir (&num2);
	
}


/*--------------------------------------------------------------------------*/
/* Função responsável por calcular a combinação.                            */ 
/*--------------------------------------------------------------------------*/

void combinacao (int n, int m, lista *resultado_fatorial) {	
	
	lista fatorial_subtracao, resultado,fatorial_m,fatorial_n;
	
	lista auxiliar1, auxiliar2, auxiliar3;
	
	int subtracao;
	
	
	if (n == m){
	
		inserir (1, &(*resultado_fatorial));
	
	
	}else{
	
		criar(&fatorial_subtracao);
		criar (&fatorial_m);
		criar(&fatorial_n);
		criar(&resultado);
		criar(&auxiliar1);
		criar(&auxiliar2);
		criar(&auxiliar3);
	

		/* Fatorial da parte de baixo da fórmula */
		subtracao = n - m;
	
		fatorial(subtracao, &fatorial_subtracao);
	
		desinverte (&fatorial_subtracao, &auxiliar1);

		fatorial (m, &fatorial_m);
	
		desinverte(&fatorial_m, &auxiliar2);
		
		multiplicar(&auxiliar1,&auxiliar2, &resultado);
	
		destruir(&auxiliar1);
	
		destruir(&auxiliar2);
	
		desinverte(&resultado, &auxiliar3);
	
		criar(&auxiliar1);
	
		/* Fatorial da parte de cima da formula */
		fatorial (n, &fatorial_n);
	
		desinverte(&fatorial_n,&auxiliar1);
	

		/* Calculando a combinação */
		divisao(&auxiliar1, &auxiliar3, &(*resultado_fatorial));
	}
}
