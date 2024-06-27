#include <iostream> 
using namespace std;

struct node
{
char data; node *next;

} *tos = NULL;

void push(char ch)
{
node *p = new node; p->data = ch;

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


int main()
{
cout << "Akshara Rathore (0901AD231008)" << endl; char epr[30];
bool vl = true;


tos = NULL;
cout << "Enter the Exp.: "; cin >> epr;


for (int i = 0; epr[i] != '\0'; i++)
 
{
if ((epr[i] == '(') || (epr[i] == '[') || (epr[i] == '{'))
{
push(epr[i]);
}
else if ((epr[i] == ')') || (epr[i] == ']') || (epr[i] == '}'))
{
if (tos == NULL)
{
vl = false;

break;
}
else if (((tos->data == '(') && epr[i] == ')') || ((tos->data == '[') &&
epr[i] == ']') || ((tos->data == '{') && epr[i] == '}'))
{
tos = tos->next;
}
else
{
vl = false;

break;
}
}
}

if (vl)
{
cout << "EXP IS VALID" << endl;
}
else
{
cout << "EXP IS INVALID" << endl;
}

return 0;
}