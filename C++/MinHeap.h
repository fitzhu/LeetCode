/*
堆排序：
	主要是用二叉堆来进行排序。代码也就是实现堆。

	二叉堆的定义：
	二叉堆是完全二叉树或者是近似完全二叉树。
	二叉堆满足二个特性：
	1．父结点的键值总是大于或等于（小于或等于）任何一个子节点的键值。
	2．每个结点的左子树和右子树都是一个二叉堆（都是最大堆或最小堆）。
	当父结点的键值总是大于或等于任何一个子节点的键值时为最大堆。当父结点的键值总是小于或等于任何一个子节点的键值时为最小堆。
*/
template<class T>
class MinHeap
{
private:
    T *m_Heap;
    int m_Capacity;
    int m_Size;

private:
    MinHeap(const MinHeap&);
    MinHeap& operator=(const MinHeap&);

public:
    MinHeap() : m_Heap(nullptr), m_Capacity(0), m_Size(0) {}
    explicit MinHeap(int capacity) : m_Heap(NULL), m_Capacity(capacity), m_Size(0) { m_Heap = new T[capacity]; }
    ~MinHeap();

    void insert(T data);
    T deleteMin();
    void print(T nums[], int n);

private:
    void filterup(int pos);
};

template<class T>
MinHeap<T>::~MinHeap()
{
    delete[] m_Heap;
    m_Heap = nullptr;
}

template<class T>
void MinHeap<T>::insert(T data) {
    if (m_Heap == nullptr) {
        m_Heap = new T[20];     // 20个作为初始容量
        m_Capacity = 20;
        m_Heap[++m_Size] = data;
        return;
    }

    if (m_size + 1 == m_Capacity) {     // 容量满了
        T *tmp = new T[m_Capacity * 2]; // 容量扩张为2倍
        memcpy(tmp, m_Heap, m_Capacity*sizeof(T));
        delete[] m_Heap;
        m_Heap = tmp;
        tmp = nullptr;
        m_Capacity = m_Capacity * 2;
        m_Heap[++m_Size] = data;
        filterup(m_Size);
        return;
    }

    m_Heap[++m_Size] = data;
    filterup(m_Size);
    return;
}

// 对于最小堆和最大堆而言，删除是针对于根节点而言。
// 对于删除操作，将二叉树的最后一个节点替换到根节点，然后自顶向下，递归调整。
template<class T>
T MinHeap<T>::deleteMin() {
    if (m_Heap == nullptr) {
        return m_Heap[0];
    }

    int i, Child;
    T Min, Last;
    Min = m_Heap[1];
    Last = m_Heap[m_Size--];
    
    for (i = 1; i * 2 <= m_Size; i = Child) {
        // 找到最小的数
        Child = i * 2;
        if (Child != m_Size && m_Heap[Child + 1] < m_Heap[Child]) {
            ++Child;
        }

        if (Last > m_Heap[Child]) {
            m_Heap[i] = m_Heap[Child];
        } else {
            break;
        }
    }
    m_Heap[i] = Last;
    return Min;
}

template <class T>
void MinHeap<T>::filterup(int pos) {
    int cur = pos;              // 当前结点的位置
    int parent = cur / 2;       // 父结点的位置
    T tmp = m_Heap[cur];        // 当前结点的值

    while (cur > 0) {
        if (m_Heap[parent] <= tmp) {
            break;
        } else {
            m_Heap[cur] = m_Heap[parent];
            cur = parent;
            parent = parent / 2;
        }
    }
    m_Heap[cur] = tmp;
}

template <class T>
void MinHeap<T>::print(T nums[], int n) {
    if (n != m_Size) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        nums[i] = deleteMin();
    }
}
