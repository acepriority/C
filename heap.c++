#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;

class MaxHeap {
    private:
        int _size{};
        vector<int> vect = {-1};

        int p(int i) {return i >>  1;};
        int l(int i) {return i <<  1;};
        int r(int i) {return (i <<  1);};

    public:
        bool isEmpty() const {return _size == 0;};
        int getMax() const {return vect[1];};
        void insertItem(int val);
        void shiftUp(int i);
        int extractMax();
        void shiftDown(int i);
};

void MaxHeap::shiftUp(int i){

    if (i > _size) return;
    if (i == 1) return;
    if (vect[i] > vect[p(i)]){
        std::swap(vect[p(i)], vect[i]);
    }
    shiftUp(p(i));
}

void MaxHeap::insertItem(int val) {
    if (_size + 1 >= vect.size()){
        vect.push_back(0);
    }
    vect[++ _size] = val;
    shiftUp(_size);
    return;
}

void MaxHeap::shiftDown(int i) {
    if (i > _size) return;

    int swapId = i;

    if (l(i) <= _size && vect[i] < vect[l(i)]) {
        swapId = l(i);
    }

    if (r(i) <= _size && vect[swapId] < vect[r(i)]) {
        swapId = r(i);
    }

    if (swapId != i) {
        std::swap(vect[i], vect[swapId]);
        shiftDown(swapId);
    }

    return;
}

int MaxHeap::extractMax() {
    int maxNum = vect[1];
    std::swap(vect[1], vect[_size--]);
    shiftDown(1);
    return maxNum;
}

int main() {
    MaxHeap* PriorityQueue = new MaxHeap();
    if (PriorityQueue->isEmpty()) {
        cout << "correct function" << endl;
    }
    else {
        cout << "the function is wrong" << endl;
    }

    int array[10];

    // enter your data here
    // array[0] = 15;
    // array[1] = 11;
    // array[2] = 70;
    // array[3] = 49;
    // array[4] = 51; 
    // .
    // .
    // .
    // array[9] = 80;

    // this is to Heapfy

    // PriorityQueue->insertItem(array[0]);
    // PriorityQueue->insertItem(array[1]);
    // PriorityQueue->insertItem(array[2]);
    // PriorityQueue->insertItem(array[3]);
    // PriorityQueue->insertItem(array[4]);
    // .
    // .
    // .
    //PriorityQueue->insertItem(array[9]);

    cout << PriorityQueue->getMax() << endl;
    PriorityQueue->extractMax();
    cout << PriorityQueue->getMax() << endl;
    
    if (PriorityQueue->isEmpty()) {
        cout << "there's still a problem!" << endl;
    }
    else {
        cout << "well done" << endl;
    }
    return 0;
}