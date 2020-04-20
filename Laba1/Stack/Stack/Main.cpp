#include <iostream>
#include <ctime>

using namespace std;
/*
	��� ������,��� ������������� ����� ������ ����� ����,
	�� ��� ������ ��� ����, ����� ��� ������� ���� ������ �� ��������� �������
*/
template<class T>						
class Stack {							// ����� ����
private:								// ��������� ����
	class Node {						// ����� ����
	public:								// ��� ��������� ����
		T data;							// ��������
		Node* next;						// ��������� �� ��������� ����
	};
	int size;							// ������
	Node* top;							// ��������� �� "���"
public:
	// �����������
	Stack() {
		// �������������� ����������
		top = nullptr;
		size = 0;
	}
	//�������� �� �������
	bool is_empty() {
		return size == 0;
	}
	// ������
	int get_size() {
		return size;
	}
	// ���������� � ����
	void push(T value) {
		// ��������� ����
		Node* temp = new Node;
		// ����������� ��������
		temp->data = value;
		// ��������� � ������
		temp->next = top;
		top = temp;
		// ���������� ������
		size++;
	}
	// �������� �� �����
	T pop() {
		// ���� ���� �� ����
		if (top != nullptr) {
			// ��������
			int value = top->data;
			// ������� ����
			Node* temp = top;
			top = temp->next;
			delete temp;
			// ��������� ������
			size--;
			// ���������� �������� ���������� ����
			return value;
		}
		// ���� ���� ���� ������� ���������
		else {
			cout << "���� ����!" << endl;
			return 0;
		}
	}
	// ����� � �������
	void print() {
		// ����
		Node* temp;
		// ���� ������� �� �����
		if (!is_empty()) {
			// ���� � �����
			for (temp = top; temp != nullptr; temp = temp->next) {
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
		Node** temp = &top;
		// ��������� �� ������� ����
		Node* current = top;
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
	Stack<int> stack;
	for (int i = 0; i < 10; i++) {
		int x = rand() % 60 + (-20);
		stack.push(x);
	}
	cout << "����������� ����: ";
	stack.print();
	cout << "����� ���� ��������� � ������� pop(): ";
	while (stack.get_size() > 0) {
		cout << stack.pop() << " ";
	}
	cout << endl;
	// ���������� ����� ������,�.�. ��� �������� ���� �������
	for (int i = 0; i < 10; i++) {
		int x = rand() % 60 + (-20);
		stack.push(x);
	}
	cout << "������ ����������� ����: ";
	stack.print();
	cout << "����� �������� ��������� ������� 7: ";
	stack.delete_by_condition(7);
	stack.print();
	return 0;
}