#include<iostream>
using namespace std;
#include <string>

template<typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack&);
	~Stack();
	bool empty() const;
	T peek() const;
	void push(T value);
	T pop();
	int getSize() const;

private:
	T* elements;
	int size;
	int capacity;
	void ensureCapacity();
};

template<typename T>
Stack<T>::Stack() : size(0), capacity(16)
{
	elements = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& stack)
{
	elements = new T[stack.capacity];
	size = stack.size;
	capacity = stack.capacity;
	for (int i = 0; i < size; i++)
	{
		elements[i] = stack.elements[i];
	}
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] elements;
}

template<typename T>
bool Stack<T>::empty() const
{
	return (size == 0);
}

template<typename T>
T Stack<T>::peek() const
{
	return elements[size - 1];
}

template<typename T>
void Stack<T>::push(T value)
{
	ensureCapacity();
	elements[size++] = value;
}

template<typename T>
void Stack<T>::ensureCapacity()
{
	if (size >= capacity)
	{
		T* old = elements;
		capacity = 2 * size;
		elements = new T[size * 2];

		for (int i = 0; i < size; i++)
			elements[i] = old[i];

		delete[] old;
	}
}

template<typename T>
T Stack<T>::pop()
{
	return elements[--size];
}

template<typename T>
int Stack<T>::getSize() const
{
	return size;
}



int main()
{
	
	Stack<char> charStack;
	for (int i = 0; i < 9; i++)
	{
		char x;
		cin >> x;
		charStack.push(x);
	}
	for (int i = 0; i < 4; i++)
	{
		char a, b, c;
		a = charStack.pop();
		b = charStack.pop();
		c = charStack.pop();

		int temp = 0;
		a = a - '0';
		c = c - '0';
		if (b == '+')
			temp = c + a;
		if (b == '-')
			temp = c - a;
		if (b == '*')
			temp = c*a;
		if (b == '/')
			temp = c / a;

		cout << temp << endl;
		temp = temp + '0';
		if(i!=3)
			charStack.push(temp);
		
	}
	
	system("pause");
	return 0;
}
