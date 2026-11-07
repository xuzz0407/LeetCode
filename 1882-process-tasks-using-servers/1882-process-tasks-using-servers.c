typedef struct {
    long long finish;
    int weight;
    int id;
} Node;

typedef struct {
    Node *data;
    int size;
    int isBusy;
} Heap;

// 比較兩個 Node，回傳 1 代表 a 優先於 b
int less(Node a, Node b, int isBusy) {
    if (isBusy && a.finish != b.finish)
        return a.finish < b.finish;

    if (a.weight != b.weight)
        return a.weight < b.weight;

    return a.id < b.id;
}

// Push：插入並往上調整
void push(Heap *h, Node x) {
    int i = h->size++;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (!less(x, h->data[p], h->isBusy))
            break;

        h->data[i] = h->data[p];
        i = p;
    }

    h->data[i] = x;
}

// Pop：取出最小值並往下調整
Node pop(Heap *h) {
    Node result = h->data[0];
    Node last = h->data[--h->size];

    int i = 0;

    while (2 * i + 1 < h->size) {
        int child = 2 * i + 1;
        int right = child + 1;

        // 選擇兩個子節點中較小的
        if (right < h->size &&
            less(h->data[right], h->data[child], h->isBusy))
            child = right;

        if (!less(h->data[child], last, h->isBusy))
            break;

        h->data[i] = h->data[child];
        i = child;
    }

    if (h->size > 0)
        h->data[i] = last;

    return result;
}

int* assignTasks(int* servers, int serversSize,
                 int* tasks, int tasksSize,
                 int* returnSize) {

    int n = serversSize;
    int m = tasksSize;

    Heap available = {malloc(n * sizeof(Node)), 0, 0};
    Heap busy = {malloc(n * sizeof(Node)), 0, 1};

    int *ans = malloc(m * sizeof(int));
    *returnSize = m;

    // 初始化所有伺服器
    for (int i = 0; i < n; i++) {
        Node x = {0, servers[i], i};
        push(&available, x);
    }

    long long time = 0;

    for (int i = 0; i < m; i++) {

        // 任務 i 在時間 i 抵達
        if (time < i)
            time = i;

        // 沒有空閒伺服器，跳到最早完成時間
        if (available.size == 0 &&
            time < busy.data[0].finish)
            time = busy.data[0].finish;

        // 釋放所有已完成的伺服器
        while (busy.size > 0 &&
               busy.data[0].finish <= time) {
            Node x = pop(&busy);
            push(&available, x);
        }

        // 選擇最小權重的伺服器
        Node x = pop(&available);
        ans[i] = x.id;

        // 計算完成時間並加入 Busy Heap
        x.finish = time + tasks[i];
        push(&busy, x);
    }

    free(available.data);
    free(busy.data);

    return ans;
}
