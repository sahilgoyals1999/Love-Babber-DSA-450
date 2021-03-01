// https://www.tutorialspoint.com/javaexamples/data_stack.htm

class MyStack {
private:
	int maxSize;
	int *stackArray;
	int top;
public:
	MyStack(int s) {
		maxSize = s;
		stackArray = new int[maxSize];
		top = -1;
	}
	void push(int j) {
		stackArray[++top] = j;
	}
	int pop() {
		return stackArray[top--];
	}
	int top() {
		return stackArray[top];
	}
	bool isEmpty() {
		return (top == -1);
	}
	bool isFull() {
		return (top == maxSize - 1);
	}
};