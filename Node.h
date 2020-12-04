template <class T>
class Node{
    public:
        Node(T data);
        Node(T data, Node<T> *left, Node<T> *right);
        T getData();
        void setData(T data);
        Node<T>* getLeft();
        void setLeft(Node<T> *left);
        Node<T>* getRight();
        void setRight(Node<T> *right);
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
};

template <class T>
Node<T>::Node(T data){
    this->data=data;
    this->left=nullptr;
    this->right=nullptr;
}

template <class T>
Node<T>::Node(T data, Node<T> *left, Node<T> *right){ //No se va a requerir esta, por si acaso
    this->data=data;
    this->left=left;
    this->right=right;
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
void Node<T>::setData(T data){
    this->data=data;
}

template <class T>
Node<T>* Node<T>::getLeft(){
    return left;
}

template <class T>
void Node<T>::setLeft(Node<T>* left){
    this->left=left;
}

template <class T>
Node<T>* Node<T>::getRight(){
    return right;
}

template <class T>
void Node<T>::setRight(Node<T>* right){
    this->right=right;
}
