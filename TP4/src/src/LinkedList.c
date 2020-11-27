#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if (this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
 }

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

	if (this != NULL)
	{
		returnAux = this->size;
	}
	return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode;
	int indice;

	if ( this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		auxNode = this->pFirstNode;
		indice = 0;
		do
		{
			if (indice == nodeIndex)
			{
				return auxNode;
				break;
			}
			else
			{
				auxNode = auxNode->pNextNode;
				indice++;
			}
		}while (auxNode != NULL);
	}
    return NULL;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	Node* nuevo_nodo = NULL;
	Node* auxNode = NULL;

	int returnAux = -1;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= this->size)
		{
				nuevo_nodo = (Node*)malloc(sizeof(Node));
				if (nuevo_nodo != NULL)
				{
					nuevo_nodo->pElement = pElement;

					if (nodeIndex == 0)
					{
						//escribo en NextNode el que era el primer nodo para no perder la direccion de memoria.
						nuevo_nodo->pNextNode = this->pFirstNode;
						//ahora si reemplazo por el nuevo nodo.
						this->pFirstNode = nuevo_nodo;
					}
					else if (nodeIndex == this->size)
					{
						nuevo_nodo->pNextNode = NULL;
						auxNode = getNode(this, nodeIndex -1);
						auxNode->pNextNode = nuevo_nodo;
					}
					else{
							auxNode = getNode(this, nodeIndex -1);
							nuevo_nodo->pNextNode = auxNode->pNextNode;
							auxNode->pNextNode = nuevo_nodo;
						}
					}
				this->size++;
				returnAux = 0;
			}

				return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int auxReturn = -1;

	if(this!=NULL)
	{
		addNode(this, this->size, pElement);
		auxReturn = 0;
	}
	return auxReturn;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	Node* auxNode = NULL;
	void* returnAux = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this, index);

		if (auxNode != NULL)
		{
			returnAux = auxNode->pElement;
		}
	}
	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	Node* auxNode = NULL;
	int returnAux = -1;

	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this, index);
		auxNode->pElement = pElement;
		returnAux = 0;
	}
	return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    Node* nodeRemove = NULL;
    Node* auxNode = NULL;
    int returnAux = -1;

    if (this != NULL && index >= 0 && index < ll_len(this))
    {
    	nodeRemove = getNode(this, index);

    	if (nodeRemove != NULL && this->pFirstNode != NULL)
    	{
    		if(index == 0)
    		{
			auxNode = nodeRemove->pNextNode;
			auxNode = this->pFirstNode;
    		}
			else if (index == this->size-1)
			{
				auxNode = getNode(this, index -1);
				auxNode->pNextNode = NULL;
			}
			else
			{
				auxNode = getNode(this, index -1);
				auxNode->pNextNode = nodeRemove->pNextNode;
			}
			free(nodeRemove);
			this->size--;
			returnAux = 0;
    	}
    	if (this->size == 0)
    	{
    		this->pFirstNode = NULL;
    	}
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if (this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		ll_remove(this, i);
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
    	ll_clear(this);

    	if (this->pFirstNode == NULL)
    	{
    		free(this);
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	Node* auxNode = NULL;
    int returnAux = -1;
    int i;

    if (this != NULL)
    {
    	for (i=0;i<ll_len(this);i++)
    	{
    		auxNode = getNode(this, i);
    		if (auxNode->pElement == pElement)
    		{
    			returnAux = i;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
    	if (this->pFirstNode == NULL)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if (!addNode(this, index, pElement))
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	Node* auxNode = NULL;
	Node* returnAux = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this, index);
		returnAux = auxNode->pElement;
		ll_remove(this, index);
	}
	return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	Node* auxNode = NULL;
    int returnAux = -1;
    int i;

    if (this != NULL)
    {
    	returnAux = 0;
		for(i=0;i<ll_len(this);i++)
		{
			auxNode = getNode(this, i);
			if (auxNode->pElement == pElement)
			{
				returnAux = 1;
				break;
			}
		}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int tamThis2;
    Node* nodo;

    if(this != NULL && this2 != NULL)
    {
        tamThis2 = ll_len(this2);
        returnAux = 1;
        for(i=0;i<tamThis2;i++)
        {
            nodo = getNode(this2,i);
            returnAux = ll_contains(this,nodo->pElement);
            if(returnAux == 0)
            {
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;

    if(this != NULL && from >= 0 && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        for(i=from;i<to;i++)
        {
            pElement = ll_get(this,i);
            ll_add(cloneArray,pElement);
        }
    }



    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        cloneArray = ll_subList(this,0,size);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* pElemento1;
    void* pElemento2;
    void* pAux;
    int size;
    int i;
    int j;

    if(this != NULL && pFunc != NULL && (order==0||order==1))
    {
        returnAux = 0;
        size = ll_len(this);

        for(i=0;i<size-1;i++)
        {
            for(j=i+1;j<size;j++)
            {
                pElemento1 = (void*)ll_get(this,i);
                pElemento2 = (void*)ll_get(this,j);
                if(order == 0)
                {
                    if(pFunc((void*)pElemento1,(void*)pElemento2)<0)
                    {
                        pAux = pElemento1;
                        ll_set(this,i,pElemento2);
                        ll_set(this,j,pAux);
                    }
                }
                else
                {
                    if(pFunc((void*)pElemento1,(void*)pElemento2)>0)
                    {
                        pAux = pElemento1;
                        ll_set(this,i,pElemento2);
                        ll_set(this,j,pAux);
                    }
                }
            }
        }
    }
    return returnAux;
}
