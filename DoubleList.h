#pragma once
#include <iostream>

using namespace std;

/*
* @brief Структура для реализации класса DoubleList, в которой хранится информации об элементе, а также ссылки на предыдущий и следующий элементы.
*/
template <typename T>
struct Node 
{
	Node* prev;
	Node* next;
	T data;
	Node() : data(), prev(nullptr), next(nullptr) {};
};

/*
* @brief Класс DoubleList - двусвязный циклический список.
*/
template <typename T>
class DoubleList 
{
private:
	Node<T>* head;
	Node<T>* tail;
	size_t size;
public:
	
	/*
	* @breif Конструктор по умолчанию.
	*/
	DoubleList();
	
	/*
	* @brief Метод, позволяющий получить размер списка.
	* @return Размер списка.
	*/
	size_t Size() const;
	
	/*
	* @brief Метод, позволяющий добавить элемент в конец списка.
	* @param NewData - информация о новом элементе
	*/
	void PushB(T NewData);
	
	/*
	* @brief Метод, позволяющий добавить элемент в начало списка.
	* @param NewData - информация о новом элементе
	*/
	void PushF(T NewData);
	
	/*
	* @brief Метод, позволяющий получить данные об элементе списка.
	* @param item - определение места элемента в списке.
	* @return Информация об элементе = его размер.
	*/
	T Get(size_t item) const;
	
	/*
	* @brief Метод, позволяющий получить информацию о первом элементе списка.
	* @return Информация о первом элементе.
	*/
	T GetF() const;
	
	/*
	* @brief Метод, позволяющий получить информацию о последнем элементе списка.
	* @return Информация о последнем элементе.
	*/
	T GetB() const;
	
	/*
	* @brief Метод, удаляющий первый элемент списка.
	*/
	void PopF();
	
	/*
	* @brief Метод, удаляющий последний элемент списка.
	*/
	void PopB();
	
	/*
	* @brief Метод, удаляющий элемент списка по ключу.
	* @param item - ключ (место элемента в списке).
	*/
	void Remove(size_t item);
	
	/*
	* @brief Метод, позволяющий вставить элемент в список.
	* @param data - информация об элементе (его размер).
	* @param item - место, на которое надо поставить элемент.
	*/
	void Add(T data, size_t item);
	
	/*
	* @brief Метод, удаляющий все элементы списка.
	*/
	void Clean();
	
	/*
	* @brief Конструктор копирования.
	*/
	DoubleList(const DoubleList& another);
	
	/*
	* @brief Оператор копирования.
	*/
	DoubleList& operator = (const DoubleList& another);
	
	/*
	* @brief Конструктор перемещения.
	*/
	DoubleList(DoubleList&& another) noexcept;
	
	/*
	* @brief Оператор перемещения
	*/
	DoubleList& operator = (DoubleList&& another) noexcept;
	
	/*
	* @brief Деструктор
	*/
	~DoubleList();
};

template <typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), size(0) {};

template <typename T>
DoubleList<T>::DoubleList(const DoubleList& another) : DoubleList()
{
	Node<T>* temp = another.head;
	for (size_t i = 0; i < another.Size(); i++)
	{
		this->PushB(temp->data);
		temp = temp->next;
	}
	this->size = another.size;
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator = (const DoubleList& another) 
{
	if (this == &another)
		return *this;
	DoubleList<T> copy(another);
	std::swap(this->tail, copy.tail);
	std::swap(this->head, copy.head);
	std::swap(this->size, copy.size);

	return *this;
}

template <typename T>
size_t DoubleList<T>::Size() const 
{
	return this->size;
}

template <typename T>
void DoubleList<T>::PushB(T NewData) 
{
	Node<T>* temp = new Node<T>();
	temp->data = NewData;
	if (this->Size() == 0) 
	{
		temp->prev = temp;
		temp->next = temp;
		this->head = temp;
		this->tail = temp;
	}
	else if (this->Size() == 1) 
	{
		temp->prev = this->head;
		temp->next = this->head;
		this->tail = temp;
		this->head->next = temp;
		this->head->prev = temp;
	}
	else 
	{
		temp->prev = this->tail;
		temp->next = this->head;
		tail->next = temp;
		this->tail = temp;
		this->head->prev = this->tail;
	}
	++this->size;
}

template <typename T>
void DoubleList<T>::PushF(T NewData) 
{
	Node<T>* temp = new Node<T>();
	temp->data = NewData;
	if (this->Size() == 0) 
	{
		temp->next = temp;
		temp->prev = temp;
		this->head = temp;
		this->tail = temp;
	}
	else if (this->Size() == 1) 
	{
		temp->prev = this->tail;
		temp->next = this->tail;
		this->head = temp;
		this->tail->next = temp;
		this->tail->prev = temp;
	}
	else 
	{
		temp->next = this->head;
		temp->prev = this->tail;
		head->prev = temp;
		this->head = temp;
		this->tail->next = this->head;
	}
	++this->size;
}

template <typename T>
T DoubleList<T>::GetF() const 
{
	return this->head->data;
}

template <typename T>
T DoubleList<T>::GetB() const 
{
	return this->tail->data;
}

template <typename T>
void DoubleList<T>::PopB() 
{
	if (this->Size() == 0)
		throw std::logic_error("Невозможно удалить элемент, список пуст!");
	if (this->Size() == 1) 
	{
		delete this->tail;
		this->head = nullptr;
		this->tail = nullptr;
		--this->size;
		return;
	}
	else if (this->Size() == 2) 
	{
		delete this->tail;
		this->head->next = this->tail;
		this->tail = this->head;
		--this->size;
		return;
	}
	auto temp = this->tail;
	this->tail = this->tail->prev;
	this->tail->next = this->head;
	this->head->prev = this->tail;
	delete temp;
	--this->size;
}

template <typename T>
void DoubleList<T>::PopF() 
{
	if (this->Size() == 0)
		throw std::logic_error("Невозможно удалить элемент, список пуст!");
	if (this->Size() == 1) 
	{
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		--this->size;
		return;
	}
	else if (this->Size() == 2) 
	{
		delete this->head;
		this->tail->prev = nullptr;
		this->head = this->tail;
		--this->size;
		return;
	}
	auto temp = this->head;
	this->head = this->head->next;
	this->head->prev = this->tail;
	this->tail->next = this->head;
	delete temp;
	--this->size;
}

template <typename T>
void DoubleList<T>::Remove(size_t item) 
{
	if (item >= this->Size())
		throw std::out_of_range("Позиция больше размера списка");
	if (item == 0) 
	{
		this->PopF();
		return;
	}
	else if (item == this->Size() - 1) 
	{
		this->PopB();
		return;
	}
	auto temp = this->head;
	for (size_t i = 0; i < item; i++)
	{
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
	--this->size;
}

template <typename T>
void DoubleList<T>::Add(T data, size_t item) 
{
	if (item > this->Size())
		throw std::out_of_range("Введенное значение больше размера списка");
	if (item == 0) {
		this->PushF(data);
		return;
	}
	else if (item == this->Size()) {
		this->PushB(data);
		return;
	}
	auto add = this->head;
	for (size_t i = 0; i < item; i++)
	{
		add = add->next;
	}
	Node<T>* temp = new Node<T>();
	temp->data = data;
	if (add->prev != nullptr && this->Size() != 1)
		add->prev->next = temp;
	temp->next = add;
	temp->prev = add->prev;
	add->prev = temp;

	++this->size;
}

template <typename T>
T DoubleList<T>::Get(size_t item) const 
{
	if (item >= this->Size())
		throw std::out_of_range("Введенное значение больше размера списка");
	auto get = this->head;
	for (size_t i = 0; i < item; i++)
	{
		get = get->next;
	}
	return get->data;
}

template <typename T>
void DoubleList<T>::Clean() 
{
	while (this->Size() != 0)
		this->PopB();
}

template <typename T>
DoubleList<T>::~DoubleList() 
{
	this->Clean();
}


template <typename T>
DoubleList<T>::DoubleList(DoubleList&& another) noexcept : DoubleList()
{
	*this = another;
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator = (DoubleList&& another) noexcept 
{
	std::swap(this->tail, another.tail);
	std::swap(this->head, another.head);
	std::swap(this->size, another.size);
	return *this;
}

template <typename T>
std::ostream& operator << (std::ostream& os, const DoubleList<T>& DoubleList) 
{
	for (size_t i = 0; i < DoubleList.Size(); i++)
	{
		os << DoubleList.Get(i) << " ";
	}
	return os;
}
