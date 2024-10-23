#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>

// 获取运算符的优先级
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1; // 加法和减法优先级低
    if (op == '*' || op == '/')
        return 2; // 乘法和除法优先级高
    return 0;
}

// 中缀表达式转前缀表达式
std::string infixToPrefix(const std::string &infix)
{
    std::stack<char> operators;       // 运算符栈
    std::stack<std::string> operands; // 操作数栈
    std::string prefix;               // 存储前缀表达式

    // 判断字符是运算符还是操作数的辅助函数
    auto isOperator = [](char c)
    { return precedence(c) > 0; };
    auto isOperand = [](char c)
    { return isalnum(c); };

    // 从右到左遍历中缀表达式
    for (int i = infix.size() - 1; i >= 0; --i)
    {
        char c = infix[i];

        // 如果是操作数，则将其压入操作数栈
        if (isOperand(c))
        {
            operands.push(std::string(1, c));
        }
        // 如果是右括号，则压入运算符栈
        else if (c == ')')
        {
            operators.push(c);
        }
        // 如果是左括号，则处理运算符栈中的运算符
        else if (c == '(')
        {
            while (!operators.empty() && operators.top() != ')')
            {
                // 取出操作数并构造前缀表达式
                std::string op1 = operands.top();
                operands.pop();
                std::string op2 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(op + op1 + op2); // 构造前缀表达式
            }
            operators.pop(); // 移除右括号
        }
        // 如果是运算符，处理优先级并压入栈中
        else if (isOperator(c))
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c))
            {
                std::string op1 = operands.top();
                operands.pop();
                std::string op2 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(op + op1 + op2); // 构造前缀表达式
            }
            operators.push(c); // 压入当前运算符
        }
    }

    // 处理栈中剩余的运算符
    while (!operators.empty())
    {
        std::string op1 = operands.top();
        operands.pop();
        std::string op2 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        operands.push(op + op1 + op2);
    }

    return operands.top(); // 返回前缀表达式
}

// 中缀表达式转后缀表达式
std::string infixToPostfix(const std::string &infix)
{
    std::stack<char> operators; // 运算符栈
    std::string postfix;        // 存储后缀表达式

    // 判断字符是运算符还是操作数的辅助函数
    auto isOperator = [](char c)
    {
        return precedence(c) > 0;
    };
    auto isOperand = [](char c)
    {
        return isalnum(c);
    };

    // 从左到右遍历中缀表达式
    for (char c : infix)
    {
        // 如果是操作数，则直接追加到后缀表达式
        if (isOperand(c))
        {
            postfix += c;
        }
        // 如果是左括号，压入运算符栈
        else if (c == '(')
        {
            operators.push(c);
        }
        // 如果是右括号，处理运算符栈中的运算符
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top(); // 追加运算符到后缀表达式
                operators.pop();
            }
            operators.pop(); // 移除左括号
        }
        // 如果是运算符，处理优先级并压入栈中
        else if (isOperator(c))
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c))
            {
                postfix += operators.top(); // 追加运算符到后缀表达式
                operators.pop();
            }
            operators.push(c); // 压入当前运算符
        }
    }

    // 处理栈中剩余的运算符
    while (!operators.empty())
    {
        postfix += operators.top(); // 追加剩余运算符
        operators.pop();
    }

    return postfix; // 返回后缀表达式
}

// 计算后缀表达式
int evaluatePostfix(const std::string &postfix)
{
    std::stack<int> operands; // 操作数栈

    // 遍历后缀表达式
    for (char c : postfix)
    {
        // 如果是数字，转换为整数并压入栈中
        if (isdigit(c))
        {
            operands.push(c - '0');
        }
        else
        {
            // 取出两个操作数进行运算
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();
            switch (c)
            {
            case '+':
                operands.push(op1 + op2);
                break; // 加法
            case '-':
                operands.push(op1 - op2);
                break; // 减法
            case '*':
                operands.push(op1 * op2);
                break; // 乘法
            case '/':
                operands.push(op1 / op2);
                break; // 除法
            }
        }
    }

    return operands.top(); // 返回计算结果
}

// 计算前缀表达式
int evaluatePrefix(const std::string &prefix)
{
    std::stack<int> operands; // 操作数栈

    // 从右到左遍历前缀表达式
    for (int i = prefix.size() - 1; i >= 0; --i)
    {
        char c = prefix[i];
        // 如果是数字，转换为整数并压入栈中
        if (isdigit(c))
        {
            operands.push(c - '0');
        }
        else
        {
            // 取出两个操作数进行运算
            int op1 = operands.top();
            operands.pop();
            int op2 = operands.top();
            operands.pop();
            switch (c)
            {
            case '+':
                operands.push(op1 + op2);
                break; // 加法
            case '-':
                operands.push(op1 - op2);
                break; // 减法
            case '*':
                operands.push(op1 * op2);
                break; // 乘法
            case '/':
                operands.push(op1 / op2);
                break; // 除法
            }
        }
    }

    return operands.top(); // 返回计算结果
}

int main()
{
    std::string infix = "3+4*2/(1-5)"; // 定义一个中缀表达式

    // 转换为前缀表达式和后缀表达式
    std::string prefix = infixToPrefix(infix);
    std::string postfix = infixToPostfix(infix);

    // 输出原中缀表达式
    std::cout << "中缀: " << infix << std::endl;
    // 输出前缀表达式
    std::cout << "前缀: " << prefix << std::endl;
    // 输出后缀表达式
    std::cout << "后缀: " << postfix << std::endl;

    // 计算并输出前缀表达式的结果
    int prefixResult = evaluatePrefix(prefix);
    // 计算并输出后缀表达式的结果
    int postfixResult = evaluatePostfix(postfix);

    // 输出计算结果
    std::cout << "前缀 Evaluation Result: " << prefixResult << std::endl;
    std::cout << "后缀 Evaluation Result: " << postfixResult << std::endl;

    return 0;
}