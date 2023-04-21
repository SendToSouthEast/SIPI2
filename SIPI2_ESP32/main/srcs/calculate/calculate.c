#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_EXPR_LEN 100

// 栈结构体
typedef struct Stack {
    int top;
    double arr[MAX_EXPR_LEN];
} Stack;

// 初始化栈
void init(Stack *stack) {
    stack->top = -1;
}

// 判断栈是否为空
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// 压栈
void push(Stack *stack, double value) {
    if (stack->top == MAX_EXPR_LEN - 1) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

// 出栈
double pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// 获取栈顶元素
double peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

// 获取操作符的优先级
int get_priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

// 执行计算
double evaluate(double op1, double op2, char op) {
    switch (op) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '^':
            return pow(op1, op2);
        default:
            printf("Invalid operator!\n");
            exit(EXIT_FAILURE);
    }
}

// 解析字符串表达式并计算结果
double calculate(char *expr) {
    Stack operand_stack; // 操作数栈
    Stack operator_stack; // 操作符栈
    init(&operand_stack);
    init(&operator_stack);

    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(*token)) { // 如果是数字，则压入操作数栈
            push(&operand_stack, atof(token));
        } else if (*token == '(') { // 如果是左括号，则压入操作符栈
            push(&operator_stack, *token);
        } else if (*token == ')') { // 如果是右括号，则弹出操作符栈中的操作符，并执行计算
            while (peek(&operator_stack) != '(') {
                char op = pop(&operator_stack);
                double op2 = pop(&operand_stack);
                double op1 = pop(&operand_stack);
                push(&operand_stack, evaluate(op1, op2, op));
            }
            pop(&operator_stack); // 弹出左括号
        } else if (*token == '+' || *token == '-' || *token == '*' || *token == '/' || *token == '^') {
            // 如果是操作符
	        // 如果当前操作符的优先级小于等于操作符栈顶元素的优先级，则弹出操作符栈顶元素并执行计算，直到当前操作符的优先级大于栈顶元素的优先级
	        while (!is_empty(&operator_stack) && get_priority(*token) <= get_priority(peek(&operator_stack))) {
	            char op = pop(&operator_stack);
	            double op2 = pop(&operand_stack);
	            double op1 = pop(&operand_stack);
	            push(&operand_stack, evaluate(op1, op2, op));
	        }
	        push(&operator_stack, *token);
	    } else {
	        printf("Invalid input!\n");
	        exit(EXIT_FAILURE);
	    }
	    token = strtok(NULL, " ");
	}
	
	// 处理剩余的操作符
	while (!is_empty(&operator_stack)) {
	    char op = pop(&operator_stack);
	    double op2 = pop(&operand_stack);
	    double op1 = pop(&operand_stack);
	    push(&operand_stack, evaluate(op1, op2, op));
	}
	
	// 最后操作数栈中只剩下一个元素，即计算结果
	double result = pop(&operand_stack);
	if (!is_empty(&operand_stack)) {
	    printf("Invalid input!\n");
	    exit(EXIT_FAILURE);
	}
	return result;
}