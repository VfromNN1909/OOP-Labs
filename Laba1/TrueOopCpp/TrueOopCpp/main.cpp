#include <iostream>
#include <ctime>

using namespace std;

/* 
	��� ������,��� ������������� ����� ������ ����� ����,
	�� ��� ������ ��� ����, ����� ��� ������� ���� ������ �� ��������� �������
*/ 
template<class T>
class Queue {					// ����� �������
private:						// ��������� ����								
	class Node {				// ����� ����	
	public:						// ��������� ����
		T data;					// �������� � ����
		Node* next;				// ��������� �� ��������� �������
	};
	Node* head;					// "������" �������	
	Node* tail;					// "����� �������"	
	int size;					// ������
public:							// ��������� ����
	// �������� �� �������
	bool is_empty() 
	{ return head == nullptr;}							
	// ����������� ��� ����������
	Queue() {
		// ����������� ��������
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	// ������
	int get_size() {
		// ���������� ������ �������
		return size;
	}
	// ������� ���������� � �������
	void enqueue(T x) {
		// ��������� ����
		Node *temp = new Node;
		// ����������� ��������
		temp->data = x;
		temp->next = nullptr;
		// ���� � ������� ������
		if (is_empty()) {
			// ���������
			head = temp;
			tail = temp;
			// ����������� ������
			size++;
		}
		// ���� ������� �� ������
		else {
			// ��������� � �����
			tail->next = temp;
			tail = temp;
			// ����������� ������
			size++;
		}
	}
	
	// �������� �� �������
	T dequeue() {
		// ���������� ��������
		T data = head->data;
		// ���������� ������ �������
		Node* temp = head;
		head = head->next;
		// �������
		delete temp;
		// ��������� ������
		size--;
		// ���������� �������� ���������� ����
		return data;
	}
	// ����� � �������
	void print() {
		// ����
		Node* temp;
		// ���� ������� �� �����
		if (!is_empty()) {
			// ���� � �����
			for (temp = head; temp != nullptr; temp = temp->next) {
				// � �������
				cout << temp->data << " ";
			}
			cout << endl;
		}
		// ����� �������,��� ������� �����
		else {
			cout << endl << "������� �����!";
		}
	}
	// �������� �� ��������
	void delete_by_condition(T data) {
		// ������� ��������� �� ������ ����
		Node** temp = &head;
		// ��������� �� ������� ����
		Node* current = head;
		// ���� ������� ���� != null
		while (current) {
			// ���� �������� � ���� ������� �� �������� �� �������
			if (current->data % data == 0) {
				// ������ ���������
				*temp = current->next;
				// ������� ����
				delete current;
				// ��������� ������
				size--;
				// ����������� ����� ���������
				current = *temp;
			}
			// �����
			else {
				// ������ ���� ������
				temp = &current->next;
				current = current->next;
			}
		}		
	}
	
};



int main() {
	// ��� �������
	srand(time(NULL));
	// ������� ����
	setlocale(LC_ALL, "rus");
	// ��������
	Queue<int> queue;
	// ���������
	for (int i = 0; i < 10; i++) {
		int x = rand() % 60 + (-20);
		queue.enqueue(x);
	}
	cout << "�������: ";
	// �������
	queue.print();
	cout << "����� ��������� � ������� dequeue(): ";
	while (queue.get_size() > 0) {
		cout << queue.dequeue() << " ";
	}
	cout << endl;
	// ���������� ������� ������,�.�. ��� �������� ���� �������
	for (int i = 0; i < 10; i++) {
		int x = rand() % 60 + (-20);
		queue.enqueue(x);
	}
	cout << "������ ����������� �������: ";
	queue.print();
	cout << "����� �������� ��������� ������� 7: ";
	// �������
	queue.delete_by_condition(7);
	// ������� ����� ��������
	queue.print();

	return 0;
}