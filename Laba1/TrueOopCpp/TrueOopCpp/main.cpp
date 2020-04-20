#include <iostream>
#include <ctime>

using namespace std;

/* 
	Это шаблон,при ининиализации можно пихать любые типы,
	но это больше для виду, чтобы эта очередь была похожа на настоящую очередь
*/ 
template<class T>
class Queue {					// класс очередь
private:						// приватные поля								
	class Node {				// класс узла	
	public:						// публичные поля
		T data;					// значение в узле
		Node* next;				// указатель на следующий элемент
	};
	Node* head;					// "голова" очереди	
	Node* tail;					// "хвост очереди"	
	int size;					// размер
public:							// публичные поля
	// проверка на пустоту
	bool is_empty() 
	{ return head == nullptr;}							
	// конструктор без параметров
	Queue() {
		// присваиваем значения
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	// геттер
	int get_size() {
		// возвращает размер очереди
		return size;
	}
	// функция добавления в очередь
	void enqueue(T x) {
		// временный узел
		Node *temp = new Node;
		// присваиваем значение
		temp->data = x;
		temp->next = nullptr;
		// если в очередь пустая
		if (is_empty()) {
			// добавляем
			head = temp;
			tail = temp;
			// увеличиваем размер
			size++;
		}
		// если очередь не пустая
		else {
			// добавляем в конец
			tail->next = temp;
			tail = temp;
			// увеличиваем размер
			size++;
		}
	}
	
	// удаление из очереди
	T dequeue() {
		// запоминаем значение
		T data = head->data;
		// запоминаем первый элемент
		Node* temp = head;
		head = head->next;
		// удаляем
		delete temp;
		// уменьшаем размер
		size--;
		// возвращаем значение удаленного узла
		return data;
	}
	// вывод в консоль
	void print() {
		// узел
		Node* temp;
		// если очередь не пуста
		if (!is_empty()) {
			// идем в цикле
			for (temp = head; temp != nullptr; temp = temp->next) {
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
		Node** temp = &head;
		// указатель на текущий узел
		Node* current = head;
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
	// созлдаем
	Queue<int> queue;
	// заполняем
	for (int i = 0; i < 10; i++) {
		int x = rand() % 60 + (-20);
		queue.enqueue(x);
	}
	cout << "Очередь: ";
	// выводим
	queue.print();
	cout << "Вывод элементов с помощью dequeue(): ";
	while (queue.get_size() > 0) {
		cout << queue.dequeue() << " ";
	}
	cout << endl;
	// заполнение очереди заново,т.к. все элементы были удалены
	for (int i = 0; i < 10; i++) {
		int x = rand() % 60 + (-20);
		queue.enqueue(x);
	}
	cout << "Заново заполненная очередь: ";
	queue.print();
	cout << "После удаления элементов кратных 7: ";
	// удаляем
	queue.delete_by_condition(7);
	// выводим после удаления
	queue.print();

	return 0;
}