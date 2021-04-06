// m1tack1_ChornayaAlina.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//Зчитати послідовно з файлу послідовність цифр та знаків +, - та *. Якщо зчитується цифра – помістити її у стек, якщо зчитується знак операції//
//– вилучається 2 числа зі стеку та результат записується у стек. Після зчитування останнього символу вивести весь вміст стеку на екран.//
//Коректно обробляти помилки у випадку намагання зчитати зі стеку неіснуюче значення.//
#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;
const int Size = 50;

struct Stack
{
	int data[Size];
	size_t size;
}Stack_t;

int pop()
{
	if (Stack_t.size == 0)
	{
		return 0;
	}
	Stack_t.size--;
	return Stack_t.data[Stack_t.size];

}

void push(const int value)
{
	if (Stack_t.size >= Size)
	{
		cout << "Error. Full Stack." << endl;
	}
	else
	{
		Stack_t.data[Stack_t.size] = value;
		Stack_t.size++;
	}
}

//возращает текущий елемент с вершины
//int peek() 
//{
//	if (Stack_t.size <= 0)
//	{
//		cout << "Error. Empty Stack." << endl;
//		return 0;
//	}
//	Stack_t.size--;
//	return Stack_t.data[Stack_t.size];
//}

void printStack(const int value)
{
	cout << value;
}

int main()
{
	Stack Stack_t;
	char str[100];
	int result = 0;
	FILE* fp;
	fp = fopen("1.txt", "r");
	if (fp == NULL)
	{
		perror("Error");
	}
	else
	{
		if (fgets(str, 100, fp) != NULL)
			cout << str << endl;
	}

	int digit;
	bool isnotoper = false;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isdigit(str[i])) {
			digit = (int)str[i] - '0';
			push(digit);
		}
		else {
			int digit1 = pop();
			int digit2 = pop();
			
			switch (str[i]) {
			case '+': {
				result = digit1 + digit2;
				break;
			}
			case '-': {
				result = digit1 - digit2;
				break;
			}
			case '*':
			{
				result = digit1 * digit2;
				break;
			}
				default: {
					cout << "This symbol is not a sign of an operation" << endl;
					isnotoper = true;
					break;
				}

			}
			if (!isnotoper)
				push(result);
		}
	}
	cout << "Result: " << pop() << endl;


	return 0;

}
