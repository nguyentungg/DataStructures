// A queue is a FIFO (First In First Out — the element placed at first can be accessed at first) structure.
template <typename T>
class Node
{
    public:
    T value;
    Node *next;
    Node *previous;

    Node(T value)
    {
        this->value = value;
    }
};

template <typename T>
class Queue
{
    private:
    int size_;
    Node<T> *head_ = NULL;
    Node<T> *tail_ = NULL;

    public:
    Queue()
    {
        this->size_ = 0;
    }

    void enqueue(T value)
    {
        if (this->head_ == NULL)
        {
            this->head_ = new Node<T>(value);
            this->tail_ = this->head_;
        }
        else
        {
            this->tail_->next = new Node<T>(value);
            this->tail_->next->previous = this->tail_;
            this->tail_ = this->tail_->next;
        }
        this->size_ += 1;
    }

    Node<T> dequeue()
    {
        Node<T> *tmp = this->tail_;

        this->tail_ = this->tail->previous;
        this->tail_->next = NULL;        this->size_ -= 1;        return tmp;
    }
};