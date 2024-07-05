#include <iostream>
#include "vector"
#include "cassert"

using namespace std;

//大顶堆
class Heap{
public:
    Heap(initializer_list<int> list){
        for(auto& i : list)
            m_heap.push_back(i);
        buildHeap();
    }

    void push(int i){
        m_heap.push_back(i);
        heapifyUp(m_heap.size() - 1);
    }

    int pop(){
        assert(!m_heap.empty());

        swap(m_heap[0], m_heap[m_heap.size() - 1]);
        int res = m_heap.back();
        m_heap.pop_back();
        heapifyDown(m_heap.size(), 0);
        return res;
    }

    int size(){
        return m_heap.size();
    }

    void print(){
        for(int i : m_heap)
            cout << i << " ";
        cout << endl;
    }

    void debug(){
        heapifyDown(m_heap.size(), 0);
        print();
    }

private:
    void heapifyDown(int heapSize, int k){
        int ch1 = 2 * k + 1;
        int ch2 = 2 * k + 2;
        int max = k;
        if(ch1 < heapSize && m_heap[max] < m_heap[ch1])
            max = ch1;
        if(ch2 < heapSize && m_heap[max] < m_heap[ch2])
            max = ch2;
        if(max != k){
            swap(m_heap[k], m_heap[max]);
            heapifyDown(heapSize, max);
        }
    }

    void heapifyUp(int k){
        int p = (k - 1) / 2;
        if(p >= 0 && m_heap[p] < m_heap[k]){
            swap(m_heap[p], m_heap[k]);
            heapifyUp(p);
        }
    }

    void buildHeap(){
        int lastNode = m_heap.size() - 1;
        int lastParent = (lastNode - 1) / 2;
        while(lastParent >= 0){
            heapifyDown(m_heap.size(), lastParent);
            lastParent--;
        }
    }

    vector<int> m_heap;
};

int main() {
    Heap heap({4, 5, 1, 3, 2, 4});
    int size = heap.size();
    for(int i = 0;i < size;i++)
        cout << heap.pop() << endl;


    return 0;
}
