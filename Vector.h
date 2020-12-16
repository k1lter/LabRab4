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
	variableType* p_arr = new variableType[length];
public:

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
				for (short i(0); i < pos; i++)
				{
					p_buffer_arr[i] = p_arr[i];
				}
			}
			else
			{
				for (short i(0); i < length; i++)
				{
					p_buffer_arr[i] = p_arr[i];
				}
				for (short i(length); i < pos; i++)
				{
					p_buffer_arr[i] = value;
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
		for (short i(0); i < length-1; i++)
		{
			p_buffer_arr[i] = p_arr[i];
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
		for (short i(0); i < length; i++)
		{
			p_buffer_arr[i] = p_arr[i];
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
		for (short i(1); i < length; i++)
		{
			p_buffer_arr[i] = p_arr[i - 1];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//Добавляет Elem элементов в массив начиная с Pos_Start со значением Value. 
	void insert(short pos_start, short elem, variableType value)
	{
		length += elem;
		variableType* p_buffer_arr = new variableType[length];
		for (short i(0); i < pos_start; i++)
		{
			p_buffer_arr[i] = p_arr[i];
		}
		for (short i(pos_start); i < pos_start+elem; i++)
		{
			p_buffer_arr[i] = value;
		}
		for (short i(pos_start + elem); i < length; i++)
		{
			p_buffer_arr[i] = p_arr[i - elem];
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
		for (short i(0); i < pos; i++)
		{
			p_buffer_arr[i] = p_arr[i];
		}
		for (short i(pos); i < length; i++)
		{
			p_buffer_arr[i] = p_arr[i + 1];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//Служит для полной очистки массива.
	void clear()
	{
		length = 0;
		variableType* p_buffer_arr = new variableType[length];
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//Служит для сортировки элементов массива. Выбрана нетрудная и экономичная сортировка выбором.
	void swap()
	{
		if (typeid(variableType) != typeid(char))
		{
			unsigned short M;
			unsigned short temp;
			for (unsigned short i(0); i < length; i++)
			{
				M = i;
				for (unsigned short j(i + 1); j < length; j++)
				{
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
				}
			}
		}
		else
		{
			setlocale(LC_ALL, "russian");
			std::cout << "Метод swap не может работать с символьными типами данных.\n\a";
		}
	}

	//Демонстрирует все элементы массива.(!!ВРЕМЕННЫЙ - ПОТОМ УДАЛИТЬ!!)
	void show()
	{
		for (short i(0); i < length; i++)
		{
			std::cout << p_arr[i];
		}
	}
};
