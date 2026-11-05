#include <iostream>
#include <string>

using namespace std;

#define MAX 100

struct Student {
    string id;
    string name;

    void inthongtin() const {
        cout << "MSSV: " << id << " | Ho ten: " << name << endl;
    }
};

struct Queue {
    Student a[MAX];
    int front, rear;
};

void init(Queue& q) {
    q.front = 0;
    q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.front > q.rear;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue& q, Student x) {
    if (isFull(q)) return;
    q.a[++q.rear] = x;
}

Student dequeue(Queue& q) {
    if (isEmpty(q)) {
        return {"", ""};
    }
    return q.a[q.front++];
}

Student front(Queue q) {
    if (isEmpty(q)) {
        return {"", ""};
    }
    return q.a[q.front];
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong!\n";
        return;
    }
    cout << "\n--- DANH SACH SINH VIEN TRONG HANG DOI ---\n";
    for (int i = q.front; i <= q.rear; i++) {
        q.a[i].inthongtin();
    }
}

int main() {
    Queue q;
    init(q);

    enqueue(q, {"SV01", "Pham Hoang Nam"});
    enqueue(q, {"SV02", "Do Mai Phuong"});
    enqueue(q, {"SV03", "Bui Hai Dang"});

    display(q);

    cout << "\n[Xem sinh vien dau hang - Front]\n";
    Student stFront = front(q);
    stFront.inthongtin();

    cout << "\n[Phuc vu sinh vien dau tien - Dequeue]\n";
    Student stServed = dequeue(q);
    cout << "Da xu ly xong ho so cho: ";
    stServed.inthongtin();

    display(q);

    return 0;
}
