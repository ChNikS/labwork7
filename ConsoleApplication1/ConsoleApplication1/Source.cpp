#include <iostream>
#include <string>


using namespace std;

/** \Шаблонный тип, отвечающий за подаваемые в метода класса типы int и string
*/
template <typename T>

/** \class List

*/
class List {
public:
	///Указатель на следующий элемент
	List* pNext;
	///Значение элемента шаблонного типа
	T value;
	///Пустой конструктор
	List(){}
	///Конструктор с параметром
	List(T value) {
		this->value = value;
	}
	///Метод добавления элемента в список
	void add(List* p, List* &pF) {
		p->pNext = pF;
		pF = p;
	}
	List * delFirst(List *&pF)	{
		if (pF == 0) return 0;
		List *p = pF;
		pF = pF->pNext;
		return p;

	}

	List * del(List*& pF, List *p)
	{
		if (pF == 0) return 0;
		if (pF == p) // Удаляем первый элемент
		{
			pF = pF->pNext;
			return p;
		}
		else
		{
			List *pPred = pF; // Указатель на предыдущий элемент перед p
			while (pPred->pNext != p && pPred->pNext)
				pPred = pPred->pNext;
			if (pPred->pNext == 0) return 0; // Элемента p нет в списке
			pPred->pNext = p->pNext;
			return p;
		}
	//while (delFirst(pF)); 
	}
	///Метод вывода
	void printAll(List *pF) {
		List* p = pF;
		int i = 0;
		while (p != NULL) {
			cout << "Element #" << ++i << ": ";
			cout << p->value << endl;
			p = p->pNext;
		}
	}
};


/// Функция main()
int main() {
	int N, n;
	char type;
	int find;
	///- Вводим количество действий
	cout << "Enter the number of actions: N = ";
	cin >> N;
	///Реализация N-го количества действий
	for (int i = 1; i <= N; ++i) {
		///Вводим количество элементов списка
		cout << endl << "Enter the number of list elements: n = ";
		cin >> n;
		///Вводим тип элементов списка
		cout << "Enter the type of list elements ('i' - integer, 's' - string): ";
		cin >> type;
		// В зависимости от типа выбираем определенную ветвь case. В случае ошибки выбираем ветвь default
		switch (type) {
		case 's': {
			List<string>* pF = NULL;
			///Вводим элементы
			for (int k = 1; k <= n; ++k) {
				string str = "";
				cout << "Element #" << k << ": ";
				cin >> str;
				List<string>* list = new List<string>(str);
				pF->add(list, pF);
			}
			cout << "enter element number to delete";
			cin >> find;
			find--;
			List<string>pi;
			for (List<string> *pi = pF; pi; pi = pi->pNext){
				
				if (i == find){
					pF->del(pF, pi);
				}

			}
			///Вызываем метод вывода элементов списка
			cout << endl << "Test #" << i << endl;
			pF->printAll(pF);
			delete pF;
			break;
		}
		case 'i': {
			List<int>* pF = NULL;
			///Вводим элементы
			for (int k = 1; k <= n; ++k) {
				int num;
				cout << "Element #" << k << ": ";
				cin >> num;
				List<int>* list = new List<int>(num);
				pF->add(list, pF);
			}
			///Вызываем метод вывода элементов списка
			cout << endl << "Test #" << i << endl;
			pF->printAll(pF);
			delete pF;
			break;
		}
		default:
			cout << "Undefined type" << endl;
			break;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}