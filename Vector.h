#ifndef VECTOR_H
#define VECTOR_H

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

	//����������
	~Vector()
	{
		delete[] p_arr;
	}

	//������� ����� �������.
	short size()
	{
		return length;
	}

	//�������� ����� ������� �� Pos ���������. ������ �������� ���������, � ����� �������� ����������� ���������.
	void resize(short pos)
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
			}
			length = pos;
			delete[] p_arr;
			p_arr = p_buffer_arr;
		}
	}

	//�������� ����� ������� �� Pos ���������. �������� ������ �������� �� �������� Value.
	void resize(int pos, variableType value)
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

	//���������� ������ �� ��������� ��� ���.
	bool empty()
	{
		if (length == 0) return EMPTY;
		else return FULL;
	}

	//��������� ������� � ����� �������.
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

	//������� ������� � ����� �������.
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

	//��������� ������� � ������ �������.
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

	//��������� Elem ��������� � ������ ������� � Pos_Start �� ��������� Value. 
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

	//��������� ������������� ���������� ������ ������.
	variableType front()
	{
		return p_arr[0];
	}

	//��������� ������������� ���������� ��������� ������.
	variableType back()
	{
		return p_arr[length - 1];
	}

	//������� ����� ��������� ������� �������.
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

	//������ ��� ������ ������� �������.
	void clear()
	{
		length = 0;
		variableType* p_buffer_arr = new variableType[length];
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//������ ��� ���������� ��������� �������.
	void swap()
	{
		//still empty
	}

	//������������� ��� �������� �������.(!!��������� - ����� �������!!)
	void show()
	{
		for (short i(0); i < length; i++)
		{
			std::cout << p_arr[i];
		}
	}
};
#endif
