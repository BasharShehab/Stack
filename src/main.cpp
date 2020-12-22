#include <iostream>
using namespace std;
int length = 10, top = -1;
int *stack = new int[length];
void incStack(int *&stack) {
    int tempArr[length];
    for (int i = 0; i <= top; i++) {
        tempArr[i] = stack[i];
    }
    length += 10;
    stack = new int[length];
    for (int i = 0; i < length; i++) {
        stack[i] = NULL;
    }
    for (int i = 0; i <= top; i++) {
        stack[i] = tempArr[i];
    }
}

void push(int x) {
    if (top >= length - 1) {
        cout << "Extending stack array . . ." << endl;
        incStack(stack);
        push(x);
    } else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << stack[top] << " popped!" << endl;
        top--;
    }
}

void printStack() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    } else
        cout << "Elements in stack are: " << endl;
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "1) Push in stack" << endl;
        cout << "2) Pop from stack" << endl;
        cout << "3) Display stack" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter choice: " << endl;

        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter value to be pushed:" << endl;
                cin >> value;
                push(value);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                printStack();
                break;
            }
            case 4: {
                delete stack;
                cout << "Exit" << endl;
                break;
            }
            default: {
                cout << "Invalid Choice" << endl;
            }
        }
    } while (choice != 4);
    return 0;
}
