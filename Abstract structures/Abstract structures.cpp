#include <iostream>


class stack {

private:
	const static int size = 50;

	int arr[size] = { 10, 20, 30, 40, 50 };
	int get_sp() {
		int lenght = 0;
		for (int i = 0; i < size; i++){
			if (arr[i] != '\0')
				lenght++;
		}

		return (lenght - 1);
	}
	int sp = get_sp();

public:

	void pop() { //pops the item on top of the stack
		int item_popped = arr[sp];
		arr[sp] = '\0';
		//std::cout << "The item popped is " << item_popped << "\n";
		sp = get_sp();
		print_stack();
	}

	void push_back(int object) { //pushes the item on top, and adds a new item
		arr[sp + 1] = object;
		//std::cout << "The item pushed is " << object << "\n";
		sp = get_sp();
		print_stack();
	}

	void print_stack() { // iterates the hole stack and prints every item
		std::cout << "The array content is: " << "\n";
		for (int i = 0; i <= sp; i++){
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
};

int main() {

	stack Stack;
	Stack.print_stack();

	Stack.pop();
	Stack.pop();
	Stack.push_back(32);
	Stack.pop();
	Stack.pop();
	Stack.push_back(100);
	Stack.pop();;
	Stack.push_back(23);
	Stack.push_back(90);

	std::cout << "\n\n\n\n\n";
	
}