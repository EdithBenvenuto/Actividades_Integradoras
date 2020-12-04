template <class T>
class Node{
	public:
		Node(T data);
		Node(T data, Node<T> *next, Node<T> *prev);
		T getData();
		Node<T>* getNext();
		Node<T>* getPrev();
		void setData(T data);
		void setNext(Node<T> *next);
    void setPrev(Node<T> *prev);
	private:
		T data;
		Node<T> *next;
		Node<T> *prev;
};

template <class T>
Node<T>::Node(T data){
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}

template <class T>
Node<T>::Node(T data, Node<T> *next, Node<T> *prev){
	this->data = data;
	this->next = next;
	this->prev = prev;
}

template <class T>
T Node<T>::getData(){
	return data;
}

template <class T>
Node<T>* Node<T>::getNext(){
	return next;
}
template <class T>
Node<T>* Node<T>::getPrev(){
  return prev;
}

template <class T>
void Node<T>::setData(T data){
	this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T> *next){
	this->next = next;
}

template <class T>
void Node<T>::setPrev(Node<T> *prev){
	this->prev = prev;
}

