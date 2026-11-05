#include <iostream>
#include <string>

using namespace std;

struct Student{
	string id;
	string name;
	
	void inthongtin() const{
		cout << "MSSV: "<< id << " | Ho ten: "<<name<< endl;
	}
};

class StudentQueue{
	private:
		Student*data;
		int capacity;
		int size;
	public:
		StudentQueue(int cap = 100) : capacity(cap) , size(0){
			data = new Student[capacity];
		} 
		~StudentQueue(){
			delete[] data;
		}
		bool isFull() const{
			return size == capacity;
		}
		bool isEmpty() const{
	        return size == 0;	
		}
	void enqueue(const Student& s) {
        if (isFull()) {
            cout << "[!] Hang doi da day. Khong thê them!\n";
            return;
        }
        data[size] = s;
        size++;
        cout << "[+] Da them sinh vien: " << s.name << " (" << s.id << ") vao hang doi.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "[!] Hang doi rong. Khong co sinh vien de phuc vu!\n";
            return;
        }
        cout << "[-] Da phuc vu xong sinh vien: " << data[0].name << " (" << data[0].id << ")\n";

        for (int i = 0; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }
    void front() const {
        if (isEmpty()) {
            cout << "[!] Hang doi rong.\n";
            return;
        }
        cout << "[*] Sinh vien dang cho o dau hang: ";
        data[0].inthongtin();
    }
    void display() const {
        if (isEmpty()) {
            cout << "[!] Hang doi hien dang rong!\n";
            return;
        }
        cout << "\n=== DANH SACH SINH VIEN DANG CHO (" << size << " sinh vien) ===\n";
        for (int i = 0; i < size; ++i) {
            cout << i + 1 << ". ";
            data[i].inthongtin();
        }
        cout << "========================================================\n\n";
    }
};
int main() {
    StudentQueue q(5);

    q.enqueue({"SV001", "Nguyen Van A"});
    q.enqueue({"SV002", "Tran Thi B"});
    q.enqueue({"SV003", "Le Van C"});

    q.display();

    q.front();

    q.dequeue();

    q.display();

    return 0;
}
