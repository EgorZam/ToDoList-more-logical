#include <iostream>
#include <string>
#include <list>
#include <ctime>

class ToDoItem { // класс
private: 
	int Id;
	std::string Description;
	bool Completed;

public:
	ToDoItem() : Id(0), Description(""), Completed(false) {} // конструктор по умолчанию
	~ToDoItem() = default; // деструктор по умолчанию

	bool create(std::string description) { // создание элемента
		Id = rand() % 100 + 1;	// генерация случайного числа от 1 до 100
		Description = description; // присваивание
		return true;
	}


	int getId() { return Id; } // геттер
	std::string getDescription() { return Description; } // геттер
	bool isCompleted() { return Completed; } // геттер

	void setCompleted(bool val) { Completed = val; }
};



int main()
{
	char input_option;
	int input_id;
	std::string input_desc;
	std::string version = "v0.1.0";
	std::list<ToDoItem> ToDoItems; // вектор хз
	std::list<ToDoItem>::iterator it; // итератор
	srand(time(NULL));
	ToDoItems.clear(); // очистка
	
	while (1) { // бесконечный цикл
		system("cls"); // очистка консоли перед каждый циклом
		std::cout << "ToDo List Maker\n" << version << std::endl;

		std::cout << std::endl << std::endl; // пустая строка

		for (it = ToDoItems.begin(); it != ToDoItems.end(); it++) { // перебор
			
			std::string completed = it->isCompleted() ? "done:" : "undone"; // проверка выполнения

			std::cout << it->getId() << " | " << it->getDescription() << " | " << completed<< std::endl; // вывод
		}
		
		if (ToDoItems.empty()) { // если список пуст
			std::cout << "Add your first todo" << std::endl;
		}

		
		std::cout << std::endl << std::endl; // пустая строка
		std::cout << "1. Add new item" << std::endl;
		std::cout << "2. Completed" << std::endl;
		std::cout << "3. Exit" << std::endl;

		std::cout << "choose: ";
		std::cin >> input_option;
		
		if (input_option == '3') {
			std::cout << "Bye!" << std::endl; 
			break;
		}
		else if (input_option=='1'){
			std::cout << "Enter description: ";
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin , input_desc);
			ToDoItem new_item;
			new_item.create(input_desc); // создание элемента 
			ToDoItems.push_back(new_item); // добавление элемента в список


		}
		else if (input_option == '2') {
			std::cout << "Enter id: " << std::endl;
			std::cin >> input_id;
			for (it = ToDoItems.begin(); it != ToDoItems.end(); it++) { // перебор
				if (input_id == it->getId()) { // если id совпадает с элементом в списке 
					it->setCompleted(true); // смена статуса выполнения
					break;
				}
				
			}
		}
			
		
		
		
		
	}

	
	
	return 0;
}