// if you're using new version of C compiler.
// #include <iostream>
#include <iostream.h>
#define STACK_ARRAY_SIZE 100
#define EXP_CHAR_SIZE 255
#define POSTFIX_SIZE 255

#define AND &&
#define OR ||

// if you're using new version of C compiler.
// using namespace std;

class Stack{
	int top;
public:
	char stc_arr[STACK_ARRAY_SIZE];

	Stack(char stackArray[STACK_ARRAY_SIZE]) {
        // copying the enterd array to the stc_arr array.
		for(int i = 0; i < STACK_ARRAY_SIZE; i++)
			stc_arr[i] = stackArray[i];
        
        // initializing 'top' in the constructor.
		top = -1;
	}
	
	void push(char item){
		if(top == STACK_ARRAY_SIZE - 1) cout << "Stack OverFlow.\n";
		else{
			stc_arr[++top] = item;
			cout << "{" << stc_arr[top] << "} is pushed.\n";
		}
	}
	
	char pop(){
		if(top == -1) {
			cout << "Stack is empty.\n";
			return NULL;
		}
		else{
			cout << "{" << stc_arr[top] << "} is poped.\n";
			return stc_arr[top--];
		}
	}
	void printStack(){
		if(top == -1) cout << "Stack is empty.\n";
		else
			for(int i = top; i >= 0; i--)
				cout << "{" << stc_arr[i] << "}\n";
	}
	
	int getTop(){
		return top;
	}
	void TopDecre(){
		top--;
	}
	void TopIncre(){
		top++;
	}
};



int main() {
	char stack_arr[STACK_ARRAY_SIZE];  // used as a parameter in the Stack Class.
	char postfix[POSTFIX_SIZE];        // to collect all the of digits, chars and symbol.
	int post_index = 0;
	Stack stack(stack_arr);

    
    // (char array) the enterd expression by the user.
    // another ex: ((1+2)^(10/2)*5)
	char exp[EXP_CHAR_SIZE] = "(((A+B)^2)*3)^8";

    // loop for parsing the expression.
	for(int i = 0; i < EXP_CHAR_SIZE; i++){
		if(exp[i] >= 'A' AND exp[i] <= 'Z')
			postfix[post_index++] = exp[i];
		else if(exp[i] >= 'a' AND exp[i] <= 'z')
			postfix[post_index++] = exp[i];
		else if(exp[i] >= '0' AND exp[i] <= '9')
			postfix[post_index++] = exp[i];
		else if(exp[i] == '*'){
			while(stack.stc_arr[stack.getTop()] == '^' OR
				  stack.stc_arr[stack.getTop()] == '/' OR
				  stack.stc_arr[stack.getTop()] == '*')
				postfix[post_index++] = stack.pop();
			stack.push(exp[i]);
		}
		else if(exp[i] == '/'){
			while(stack.stc_arr[stack.getTop()] == '^' OR
				  stack.stc_arr[stack.getTop()] == '*' OR
				  stack.stc_arr[stack.getTop()] == '/'){
				postfix[post_index++] = stack.pop();
			}
			stack.push(exp[i]);
		}
		else if(exp[i] == '^'){
			while(stack.stc_arr[stack.getTop()] == '^')
				postfix[post_index++] = stack.pop();
			stack.push(exp[i]);
		}
		else if(exp[i] == '+'){
			while(stack.stc_arr[stack.getTop()] == '^' OR
				  stack.stc_arr[stack.getTop()] == '/' OR
				  stack.stc_arr[stack.getTop()] == '*' OR
				  stack.stc_arr[stack.getTop()] == '-' OR
				  stack.stc_arr[stack.getTop()] == '+')
				postfix[post_index++] = stack.pop();
			stack.push(exp[i]);
		}
		else if(exp[i] == '-'){
			while(stack.stc_arr[stack.getTop()] == '^' OR
				  stack.stc_arr[stack.getTop()] == '/' OR
				  stack.stc_arr[stack.getTop()] == '*' OR
				  stack.stc_arr[stack.getTop()] == '+' OR
				  stack.stc_arr[stack.getTop()] == '-')
				postfix[post_index++] = stack.pop();
			stack.push(exp[i]);
		}
		else if(exp[i] == '(')
			stack.push(exp[i]);
		else if (exp[i] == ')'){
			while(stack.stc_arr[stack.getTop()] != '(')
				postfix[post_index++] = stack.pop();
			stack.TopDecre();
		}
	}
	
	// if the loop stopped and there are still chars in the stack,
	// then add them to the (postfix array).
	while(stack.getTop() > -1)
		postfix[post_index++] = stack.pop();

    // finally just print the the (postfix array) out.
	cout << "\nPostfix is: ";
	for(int i = 0; i < POSTFIX_SIZE; i++)
		cout << postfix[i];

	return 0;
}












 
