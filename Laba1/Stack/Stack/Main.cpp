#include <iostream>
#include <ctime>

using namespace std;
/*
	Это шаблон,при ининиализации можно пихать любые типы,
	но это больше для виду, чтобы эта очередь была похожа на настоящую очередь
*/
template<class T>						
class Stack {							// класс стэк
private:								// приватные поля
	class Node {						// класс узел
	public:								// его публичные поля
		T data;							// значение
		Node* next;						// указатель на следующий узел
	};
	int size;							// размер
	Node* top;							// указатель на "топ"
public:
	// конструктор
	Stack() {
		// инициализируем переменные
		top = nullptr;
		size = 0;
	}
	//проверка на пустоту
	bool is_empty() {
		return size == 0;
	}
	// геттер
	int get_size() {
		return size;
	}
	// добавление в стек
	void push(T value) {
		// временный узел
		Node* temp = new Node;
		// присваиваем значения
		temp->data = value;
		// добавляем в начало
		temp->next = top;
		top = temp;
		// уеличиваем размер
		size++;
	}
	// удаление из стека
	T pop() {
		// если стек не пуст
		if (top != nullptr) {
			// значение
			int value = top->data;
			// удаляем узел
			Node* temp = top;
			top = temp->next;
			delete temp;
			// уменьшаем размер
			size--;
			// возвращаем значение удаленного узла
			return value;
		}
		// если стек пуст выводим сообщение
		else {
			cout << "Стэк пуст!" << endl;
			return 0;
		}
	}
	// вывод в консоль
	void print() {
		// узел
		Node* temp;
		// если очередь не пуста
		if (!is_empty()) {
			// идем в цикле
			for (temp = top; temp != nullptr; temp = temp->next) {
				// и выводим
				cout << temp->data << " ";
			}
			cout << endl;
		}
		// иначе выводим,что очередь пуста
		else {
			cout << endl << "Очередь пуста!";
		}
	}
	// удаление по значению
	void delete_by_condition(T data) {
		// двойной указатель на первый узел
		Node** temp = &top;
		// указатель на текущий узел
		Node* current = top;
		// пока текущий узел != null
		while (current) {
			// если значение в узле делится на значение по условию
			if (current->data % data == 0) {
				// меняем указатель
				*temp = current->next;
				// удаляем ноду
				delete current;
				// уменьшаем размер
				size--;
				// присваиваем новый указатель
				current = *temp;
			}
			// иначе
			else {
				// просто идем дальше
				temp = &current->next;
				current = current->next;
			}
		}
	}
};


int main() {
	// для рандома
	srand(time(NULL));
	// русский язык
	setlocale(LC_ALL, "rus");
	Stack<int> stack;
	for (int i = 0; i < 10; i++) {
		int x = rand() % 60 + (-20);
		stack.push(x);
	}
	cout << "Заполненный стэк: ";
	stack.print();
	cout << "Вывод всех элементов с помощью pop(): ";
	while (stack.get_size() > 0) {
		cout << stack.pop() << " ";
	}
	cout << endl;
	// заполнение стэка заново,т.к. все элементы были удалены
	for (int i = 0; i < 10; i++) {
		int x = rand() % 60 + (-20);
		stack.push(x);
	}
	cout << "Заново заполненный стэк: ";
	stack.print();
	cout << "После удаления элементов кратных 7: ";
	stack.delete_by_condition(7);
	stack.print();
	return 0;
}