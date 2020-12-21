#include <initializer_list>
template <typename variableType>
class Vector
{
private:
	enum exites
	{
		EMPTY = true,
		FULL = false
	};

	unsigned short length = 0;
	unsigned int counter = 0;
	variableType* p_arr = new variableType[length];
public:

	//Конструктор по умолчанию.
	Vector()
	{

	}

	//Конструктор для ввода одного элемента.
	Vector(variableType value)
	{
		length = 1;
		variableType* p_buff_arr = new variableType[length];
		p_buff_arr[0] = value;
		delete[] p_arr;
		p_arr = p_buff_arr;
	}

	//Конструктор для ввода списка аргументов.
	Vector(std::initializer_list<variableType> value)
	{
		length = value.size();
		variableType* p_buff_arr = new variableType[length];
		for (unsigned short step(0); step < length; step++)
		{
			p_buff_arr[step] = *(value.begin() + step);
		}
		delete[] p_arr;
		p_arr = p_buff_arr;
	}

	//Деструктор
	~Vector()
	{
		delete[] p_arr;
	}

	//Выводит длину массива.
	short size()
	{
		return length;
	}

	//Изменяет длину массива до Pos элементов. Заменяет пустые элементы на значение Value.
	void resize(short pos, variableType value = variableType())
	{
		if (pos != length)
		{
			variableType* p_buffer_arr = new variableType[pos];
			if (pos < length)
			{
				for (short step(0); step < pos; step++)
				{
					p_buffer_arr[step] = p_arr[step];
				}
			}
			else
			{
				for (short step(0); step < length; step++)
				{
					p_buffer_arr[step] = p_arr[step];
				}
				for (short step(length); step < pos; step++)
				{
					p_buffer_arr[step] = value;
				}
			}
			length = pos;
			delete[] p_arr;
			p_arr = p_buffer_arr;
		}
	}

	//Определяет пустой ли контейнер или нет.
	bool empty()
	{
		if (length == 0) return EMPTY;
		else return FULL;
	}

	//Добавляет элемент в конец массива.
	void push_back(variableType value)
	{
		length++;
		variableType* p_buffer_arr = new variableType[length];
		for (short step(0); step < length-1; step++)
		{
			p_buffer_arr[step] = p_arr[step];
		}
		p_buffer_arr[length - 1] = value;
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//Удаляет элемент в конце массива.
	void pop_back()
	{
		length--;
		variableType* p_buffer_arr = new variableType[length];
		for (short step(0); step < length; step++)
		{
			p_buffer_arr[step] = p_arr[step];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//Добавляет элемент в начало массива.
	void insert(variableType value)
	{
		length++;
		variableType* p_buffer_arr = new variableType[length];
		p_buffer_arr[0] = value;
		for (short step(1); step < length; step++)
		{
			p_buffer_arr[step] = p_arr[step - 1];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//Добавляет Elem элементов в массив начиная с Pos_Start со значением Value.
	void insert(short pos_start, short elem, variableType value)
	{
		length += elem;
		variableType* p_buffer_arr = new variableType[length];
		for (short step(0); step < pos_start; step++)
		{
			p_buffer_arr[step] = p_arr[step];
		}
		for (short step(pos_start); step < pos_start+elem; step++)
		{
			p_buffer_arr[step] = value;
		}
		for (short step(pos_start + elem); step < length; step++)
		{
			p_buffer_arr[step] = p_arr[step - elem];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//Позволяет просматривать содержимое первой ячейки.
	variableType front()
	{
		return p_arr[0];
	}

	//Позволяет просматривать содержимое последней ячейки.
	variableType back()
	{
		return p_arr[length - 1];
	}

	//Удаляет однин выбранный элемент вектора.
	void erase(short pos)
	{
		length--;
		variableType* p_buffer_arr = new variableType[length];
		for (short step(0); step < pos; step++)
		{
			p_buffer_arr[step] = p_arr[step];
		}
		for (short step(pos); step < length; step++)
		{
			p_buffer_arr[step] = p_arr[step + 1];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//Служит для полной очистки массива.
	void clear()
	{
		length = 0;
		delete[] p_arr;
		p_arr = nullptr;
	}

	//Служит для сортировки элементов массива. Выбрана нетрудная и экономичная сортировка выбором.
	void swap()
	{
		if (typeid(variableType) != typeid(bool))
		{
			unsigned int M;
			unsigned int temp;
			for (unsigned short i(0); i < length; i++)
			{
				M = i;
				for (unsigned short j(i + 1); j < length; j++)
				{
					counter++;
					if (p_arr[j] < p_arr[M])
					{
						M = j;
					}
				}
				if (M != i)
				{
					temp = p_arr[i];
					p_arr[i] = p_arr[M];
					p_arr[M] = temp;
					counter++;
				}
			}
		}
		else
		{
			setlocale(LC_ALL, "russian");
			std::cout << "Метод swap не может работать с булевыми переменными.\n\a";
		}
	}

	//Демонстрирует все элементы массива.(!!ВРЕМЕННЫЙ - ПОТОМ УДАЛИТЬ!!)
	void show()
	{
		for (short step(0); step < length; step++)
		{
			std::cout << p_arr[step] << " ";
		}
		std::cout << "\nQuantity of elements = " << length << "\n";
		std::cout << "\nCounter = " << counter << "\n";
	}
};
