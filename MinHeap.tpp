template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while (i > 0) {
        int p = parent(i);
        if (data[i] >= data[p]) {
            break;
        }
        swap(data[i], data[p]);
        i = p;
    }

}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored

     while (true) {
        int small = i;
        int leftie = left(i);
        int rightie = right(i);

        if (leftie < data.size() && data[leftie] < data[small]) {
            small = leftie;
        }
        if (rightie < data.size() && data[rightie] < data[small]) {
            small = rightie;
        }
        if (small == i) {
            break;
        }
        swap(data[i], data[small]);
        i = small;
        //return
     }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    siftUp(size() - 1);
    data.push_back(value);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.
    if (empty()){
        throw runtime_error("remove root: the heap is empty");}

    T v = data[0];
    data[0] = data.back();
    data.pop_back();

    if (!empty()){
        siftDown(0);
    }
    return v;

}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property

     if (index < size()) {
        siftUp(index);
        siftDown(index);
    }
}
