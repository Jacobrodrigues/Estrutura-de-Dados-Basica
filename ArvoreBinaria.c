	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	// Defini��o dos tipos 'itemDaLista' e 'listaEncadeada'
	typedef struct item {
		int codigo;
		struct item *pMaior;
		struct item *pMenor;
	} itemDaArvore;

	typedef struct arvore{
		itemDaArvore *root;
		int tamanho;
	} arvoreBinaria;

	// Prototipa��o das fun��es
	void inicializacao (arvoreBinaria*);
	itemDaArvore minimo(itemDaArvore);


	// Desenvolvimento das fun��es

	// Inicializa um lista vazia.
	void inicializacao (arvoreBinaria *arvore){
		arvore->root = NULL;
		arvore->tamanho = 0;
	}

	int inserirroot(arvoreBinaria* arvore,int codigo)
	{
		itemDaArvore* novoItem;	
		novoItem = (itemDaArvore* ) malloc (sizeof (itemDaArvore));
		if (novoItem == NULL) {
			return -1;
		}
		novoItem->codigo = codigo;
		arvore->root = novoItem;
		arvore->root->pMaior = NULL;
		arvore->root->pMenor = NULL;
		arvore->tamanho++;
		return 0;
	}

	int inserir(arvoreBinaria* arvore, int codigo)
	{
		itemDaArvore* novoItem;	
		itemDaArvore* atualItem;	
		novoItem = (itemDaArvore* ) malloc (sizeof (itemDaArvore));
		if (novoItem == NULL) {
			return -1;
		}
		novoItem->codigo = codigo;
		
		if(novoItem->codigo > arvore->root->codigo){
			atualItem = arvore->root;			
			while(atualItem->codigo < novoItem->codigo)
				{
					if(atualItem->pMaior == NULL)
					{
						atualItem->pMaior = novoItem;
						atualItem->pMaior->pMaior  = NULL;
						atualItem->pMaior->pMenor  = NULL; 						
						break;
					} 
					atualItem = atualItem->pMaior;
				}
			if(atualItem->codigo > novoItem->codigo)
				atualItem->pMenor = novoItem;		
			
		}
		else{
			atualItem = arvore->root;			
			while(atualItem->codigo > novoItem->codigo)
				{
					if(atualItem->pMenor == NULL)
					{
						atualItem->pMenor = novoItem;
						atualItem->pMenor->pMaior  = NULL;
						atualItem->pMenor->pMenor  = NULL; 						
						break;
					} 
					atualItem = atualItem->pMenor;
				}
			if(atualItem->codigo < novoItem->codigo)
				atualItem->pMaior = novoItem;		
			
		}
		arvore->tamanho++;
		return 0;
	}

	void percorrer(itemDaArvore* root)
	{
		if(root != NULL){
		percorrer(root->pMenor);
		printf("%d ",root->codigo);
		percorrer(root->pMaior);
		}
	}

	void percorrerPreOrdem(itemDaArvore* root)
	{
		if(root != NULL){
		printf("%d ",root->codigo);
		percorrerPreOrdem(root->pMenor);
		percorrerPreOrdem(root->pMaior);
		}
	}

	void remover(itemDaArvore *root, int valor){   
	    itemDaArvore aux;   
	    if(root != NULL){   
	       // se o valor que ser� removido for menor que o n� atual,   
	       if(valor < root->codigo){    
	           remover(root->pMenor, valor); // faz recursividade � pMenoruerda   
	       }else{   
	            // se o valor que ser� removido for maior que o n� atual,   
	            if(valor > root->codigo){    
	                 remover(root->pMaior, valor); // faz recursividade � pMaioreita.   
	             }else{ // encontrou   
	                // quando o n� a ser removido for encontrado,   
	                if(root->pMenor != NULL && root->pMaior !=NULL ){    
	                     // verificamos se os n�s filhos da pMenoruerda e pMaioreita n�o s�o null.   
	                     // se n�o forem null, buscamos o menor n� a partir do n� da pMaioreita.   
	                     aux = minimo(*root->pMaior);
	                     root->codigo = aux->codigo;   
	                     remover(root->pMaior, root->codigo);   
	                }else{    
	                       // caso os n� da pMaioreita e da pMenorueda, ou somente o da pMaioreita for null,    
	                       // precisamos apenas remover   
	                       aux = *root;    
	                       // o n� atual e fazer ajustar os ponteiros    
	                       if(root->pMenor == NULL){    
	                           // se o n� da pMenoruerda for vazio   
	                           // o n� pai do atual, apontar� para o filho da pMaioreita do n� atual.   
	                           root = root->pMaior;   
	                       }    
	                       else {   
	                            // se o n� da pMenoruerda n�o for vazio.   
	                            // o n� pai do atual, apontar� para o filho da pMenoruerda do n� atual.   
	                            *root = *root->pMenor;                          
	                       }   
	                free(aux);   
	                }   
	            }        
	       }    
	    }     
	}

	itemDaArvore minimo(itemDaArvore no){// procura o n� com valor m�nimo   
    if(no == NULL){   
       return NULL;   
    }else{   
          if( no->pMenor == NULl){   
              return no;   
          }else{   
              return minimo(no->pMenor);   
          }   
    }   
} 


	int main(){
		arvoreBinaria *minhaArvore;
		minhaArvore = (arvoreBinaria*) malloc (sizeof (arvoreBinaria));
		if (minhaArvore == NULL) {
			printf("N�o foi poss�vel alocar mem�ria\n");
			return -1;
		}
		inicializacao(minhaArvore);
		inserirroot(minhaArvore, 50);
		inserir(minhaArvore, 40);
		inserir(minhaArvore, 30);
		inserir(minhaArvore, 22);
		inserir(minhaArvore, 35);
		inserir(minhaArvore, 45);
		inserir(minhaArvore, 43);
		inserir(minhaArvore, 48);
		inserir(minhaArvore, 68);
		inserir(minhaArvore, 63);
		inserir(minhaArvore, 62);
		inserir(minhaArvore, 65);
		inserir(minhaArvore, 70);
		inserir(minhaArvore, 69);
		inserir(minhaArvore, 80);
		percorrerPreOrdem	(minhaArvore->root;
		return 0;
	}