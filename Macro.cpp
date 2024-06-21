#include <iostream>
#include <cmath>
using namespace std;

struct node
{

   long double data;
    node *next;

} *tos = NULL;

int priority(char x)
{
    if (x == '^')
        return 5;
    else if (x == '/')
        return 4;
    else if (x == '*')
        return 3;
    else if (x == '-')
        return 2;
    else if (x == '+')
        return 1;
    else
        return 0;
}

void push(int ch)
{
    node *p = new node;
    p->data = ch;

    if (tos == NULL)
    {

        p->next = NULL;
    }
    else
    {
        p->next = tos;
    }
    tos = p;
}

int pop()
{
    node *p = tos;
    if (tos == NULL)
    {

    }
    else
    {

        tos = tos->next;
    }
    return p->data;
}

bool valid(string expression)
{
    bool validity = true;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{'))
        {
            push(expression[i]);
        }
        else if ((expression[i] == ')') || (expression[i] == ']') || (expression[i] == '}'))
        {
            if (tos == NULL)
            {
                validity = false;

                break;
            }
            else if (((tos->data == '(') && expression[i] == ')') || ((tos->data == '[') && expression[i] == ']') || ((tos->data == '{') && expression[i] == '}'))
            {
                pop();
            }
            else
            {
                validity = false;

                break;
            }
        }
    }

    return validity;
}

string infixToPostfix(string expression)
{
    tos = NULL;
    string postfix;
    for (int i = 0; expression[i] != '\0'; i++)
    {

        if (((expression[i]) >= '0' && int(expression[i]) <= '9'))
        {
            postfix = postfix + expression[i];
        }
        else if ((expression[i] == ')') || (expression[i] == ']') || (expression[i] == '}'))
        {
            while ((tos->data != '(') && (tos->data != '[') && (tos->data != '{'))
            {
                char t = pop();
                postfix = postfix + t;

            }
            pop();
        }
        else
        {

            if (priority(expression[i]) > 0)
            {

                if (tos != NULL)
                {
                    while (tos != NULL && (priority(expression[i]) < priority(tos->data)))
                    {

                        char t = pop();
                        postfix += t;

                    }
                }
            }
            push(expression[i]);

        }
    }

    while (tos != NULL)
    {

        char t = pop();
        postfix = postfix + t;

    }

    return postfix;
}

double calculatePostFix(string expression)
{

    tos = NULL;

    for (int i = 0; expression[i] != '\0'; i++)
    {

        if ((int(expression[i]) >= 48 && int(expression[i]) <= 57))
        {
            push(int(expression[i]) - 48);
        }

        else
        {

            int a = (tos->data);

            pop();
            int b = (tos->data);

            pop();

            switch (expression[i])
            {
            case '+':
                push(a + b);
                break;
            case '-':
                push(b - a);
                break;

            case '*':
                push(a * b);

                break;

            case '/':
                if (a == 0)
                {
                    cout << "Division by 0 is not possible" << endl;
                }
                else
                {
                    push(b / a);
                }
                break;
            case '^':
                push(pow(b, a));
                break;
            default:
                cout << "Invalid expression." << endl;
            }
        }
    }

    return tos->data;
}

int main()
{

    string expression;
    bool ch;

    do
    {
        cout << endl
             << "SKILL BASED MACRO PROJECT BY: " << endl
             << "AKSHARA RATHORE (0901AD231008)" << endl
             << "VAIBHAV SHARMA (0901AD231069)" << endl
             << endl;

        cout << "Enter Expression to calculate: ";
        cin >> expression;

        if (valid(expression))
        {
            cout << "EXPRESSION IS VALID" << endl;

            cout << "PostFix: " << infixToPostfix(expression) << endl;
            cout << "The evaluated value is: " << calculatePostFix(infixToPostfix(expression)) << endl;
        }
        else
        {
            cout << "EXPRESSION IS INVALID" << endl;
        }

        cout << "Do you want to evaluate another expression? (1/0): ";
        cin >> ch;

    } while (ch != 0);

    cout << endl
         << "SKILL BASED MACRO PROJECT BY: " << endl
         << "AKSHARA RATHORE (0901AD231008)" << endl
         << "VAIBHAV SHARMA (0901AD231069)" << endl
         << endl
         << "PROGRAM EXITED!!";

    return 0;
}