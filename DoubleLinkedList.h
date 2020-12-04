#include "Node.h"

template <class T>
class DoubleLinkedList{
	public:
		DoubleLinkedList();
		~DoubleLinkedList();
		void addFirst(T data);
		void addLast(T data);
		void print();
    bool isEmpty();
    int deleteAll();
    int getSize();
    T get(int pos);
    void sort();
    void printR(long long ini,long long fin);
		
	private:
		Node<T> *head, *tail;
		int size;
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	deleteAll();		// Invoco al deleteAll
}

//Complejidad: O(1)
template <class T>
void DoubleLinkedList<T>::addFirst(T data){
  if (size==0){
   	head = tail = new Node<T>(data, nullptr, nullptr) ; 
  }
	else{
		Node<T>*curr=head;
		head = new Node<T>(data, head, nullptr);
    curr->setPrev(head);
	}
	size++;
}

//Complejidad O(1)
template <class T>
void DoubleLinkedList<T>::addLast(T data){
	if (size == 0){
		addFirst(data);
	}
	else{
		Node<T> *curr = tail;
		tail=new Node<T>(data,nullptr,tail);
		curr->setNext(tail);
		size++;
	}
}

//Complejidad: O(n)
template <class T>
void DoubleLinkedList<T>::print(){
	cout << "La DoubleLinkedList contiene:" << endl;
	Node<T> *curr = head;		// curr es un alias
	while (curr != nullptr){  			// Mientras curr no sea nullptr, quiere decir que apunta a un nodo
		cout << curr->getData().IP <<endl;	// Despliego el contenido de lo que apunta curr;
		curr = curr->getNext();
	}
}

// Complejidad: O(1)
template <class T>
bool DoubleLinkedList<T>::isEmpty(){
	return head == nullptr;
}

template <class T>
int DoubleLinkedList<T>::deleteAll(){
	Node<T> *curr = head;
	while (head != nullptr){
		head = head->getNext();  // Avanzo head una pos
		delete curr;   // Libero un nodo
		curr = head;   // Pongo a curr alineado con head
	}
	int sizeAux = size;
	size = 0;
	return sizeAux;
}

template <class T>
int DoubleLinkedList<T>::getSize(){
  return size;
}

template <class T>
T DoubleLinkedList<T>::get(int pos){
	Node<T> *curr = head;			// Inicializar curr en head
	for (int i=1; i<=pos; i++){
		curr = curr->getNext();		// curr salta pos veces
	}
	return curr->getData();			// Regresar la información
}

template <class T>
void DoubleLinkedList<T>::sort(){		
	T temp;
	bool interruptor=true;
	for(int i=0;i<size-1 && interruptor;++i){
		interruptor=false;
    Node<T> *curr = head;
		for(int j=0;j<size-i-1;++j){
			if(curr->getData().IP > curr->getNext()->getData().IP){
        //d.change(j+1, j);
        T temp = curr->getNext()->getData();
        curr->getNext()->setData(curr->getData());
        curr->setData(temp);
				interruptor=true;
			}
			curr = curr->getNext();
		}  
  }
}

template <class T>
void DoubleLinkedList<T>::printR(long long ini, long long fin){
	Node<T> *curr = head;
	while(curr->getData().IP<ini){
		curr=curr->getNext();
  }
	while(curr->getData().IP>=ini && curr->getData().IP<=fin){
		cout<<curr->getData().fecha<< curr->getData().IPn << " " << curr->getData().falla <<endl;
		curr=curr->getNext();
	}
  
}

