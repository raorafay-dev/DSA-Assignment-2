/*
Assignment # 02

Name : Roa Muhammad Rafay
Roll #: P20-0636
*/

#include <iostream>
using namespace std;

// class stack
// we will be using this class for the further implementation of tasks
class Stack
{
    // private:
    int size;
    int top;
    char *arr;

public:
    // default constructor
    Stack();

    // functions
    bool isEmpty();
    bool isFull();
    void Push(char);
    char Pop();
    char stackTop(); // will return top most character of stack

    // destructor
    ~Stack();
};
// implementation for class Stack
// default constructor
Stack ::Stack()
{
    size = 100;
    top = -1;
    arr = new char[size];
}
// functions
bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    // else
    return false;
}
bool Stack::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    // else
    return false;
}
void Stack ::Push(char ch)
{
    // checking
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        arr[top] = ch;
    }
}
char Stack ::Pop()
{
    char x;
    // checking
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        x = arr[top];
        top--;
    }
    return x;
}
char Stack ::stackTop()
{
    char x;
    // checking
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        x = arr[top];
    }
    return x;
}
Stack ::~Stack()
{
    delete arr;
}
// ----- class ends -----

// class stack of data int
// defining this class for evalution purpose
// we will be using this class for the further implementation of tasks
class intStack
{
    // private:
    int size;
    int top;
    int *arr;

public:
    // default constructor
    intStack();

    // functions
    bool isEmpty();
    bool isFull();
    void Push(int);
    int Pop();
    int stackTop(); // will return top most character of stack

    // destructor
    ~intStack();
};
// implementation for class Stack
// default constructor
intStack ::intStack()
{
    size = 100;
    top = -1;
    arr = new int[size];
}
// functions
bool intStack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    // else
    return false;
}
bool intStack::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    // else
    return false;
}
void intStack ::Push(int x)
{
    // checking
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        arr[top] = x;
    }
}
int intStack ::Pop()
{
    int x;
    // checking
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        x = arr[top];
        top--;
    }
    return x;
}
int intStack ::stackTop()
{
    int x;
    // checking
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        x = arr[top];
    }
    return x;
}
intStack ::~intStack()
{
    delete arr;
}
// ----- class ends -----

// ----- GLOBAL FUNCTIONS -----

// this is the global function taking the pointer to expression as parameter and will check for its validity in terms of (balanced Paranthesis)
bool checkBalance(char *exp)
{
    // using stack
    Stack st;

    // scannig through the expression by iteration
    for (int i = 0; exp[i] != '\0'; i++)
    {
        // pushin when character is ')' and poping when ')'
        if (exp[i] == '(')
        {
            st.Push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            // condition where validity declared (when stack becomes empty and expression isn't scanned completely)
            if (st.isEmpty())
            {
                return false;
            }
            st.Pop();
        }
    }
    // checking stack if empty then valid if not then invalid
    if (st.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ----- Helper Functions for "Postfix Conversion" -----

// this function is used in further implementation and created for purpose of ease
// will check if the character is operand or operator
bool OperandCheck(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%' || ch == '(' || ch == ')')
    {
        return false;
    }
    // else
    return true;
}

// this function is basically used to seperate the operands through spaces for ease of readablity and evaluation
// this will take an expression as argument and add spaces after operands and return new converted expression
char *AddSpaces(char *exp)
{
    // declaring and initializing a character array for storing converted expression
    char *newexp = new char[100];

    // making variables for iteration purpose
    int i, j;
    i = j = 0;

    // iterating through expression
    while (exp[i] != '\0')
    {
        // if operand
        if (OperandCheck(exp[i]))
        {
            // iterate further until operator arrives or expression ends
            while (OperandCheck(exp[i]))
            {
                // if expression ends
                if (exp[i] == '\0')
                {
                    break;
                }

                // store operand in new array character by character
                newexp[j] = exp[i];
                i++;
                j++;
            }
            // add a space after each operand
            newexp[j] = ' ';
            j++;
        }

        // if operator or else
        else
        {
            // simply store into the new array
            newexp[j] = exp[i];
            i++;
            j++;
        }
    }
    // add an terminating symbol of charaacter array
    newexp[j] = '\0';

    // returning converted expression
    return newexp;
}

/*

Precedence Table: (According to the stated instructions in assignment statement)

op      ou  in
+, -    1   2
*,/,^   3   4
%       6   5
(       7   0
)       0   -

*/

// this function is used in further implementation in Postfix conversion and created for purpose of ease
// this will give the precedence of an operand inside the stack
// precendences of operators have been declared randomly to the accociativity and rules of precendences
int PrecedenceIn(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else if (ch == '*' || ch == '/' || ch == '^')
    {
        return 4;
    }
    else if (ch == '%')
    {
        return 5;
    }
    else if (ch == '(')
    {
        return 0;
    }
    // else
    return -1;
}

// this function is used in further implementation in Postfix conversion and created for purpose of ease
// this will give the precedence of an operand outside the stack
// precendences of operators have been declared according to the accociativity and rules of precendences
int PrecedenceOut(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/' || ch == '^')
    {
        return 3;
    }
    else if (ch == '%')
    {
        return 6;
    }
    else if (ch == '(')
    {
        return 7;
    }
    else if (ch == ')')
    {
        return 0;
    }
    // else
    return -1;
}
// ----- Helper Functions ends -----

// this function will use above funtions and stack as well
// its globally declared and taking the pointer to expression as parameter then returning poiter to the (converted to postfix) expression
char *ConvertPostfix(char *exp)
{
    // using stack
    Stack st;

    // declaring and initializing a dynamic array for storing the converted expression
    char *postfix = new char[100];

    // for ease of impletation of futher used logic we are pushing (space character ' ') into the stack
    // hence it will be at the end of converted (pstfix) expression, which will not interupt any proceedings
    st.Push(' ');

    // declaring and initializing variables for iteration purpose
    int i, j;
    i = j = 0;

    // scannig through expression and storing in above declared postfix character array
    while (exp[i] != '\0')
    {
        // if operand -> send it directly to postfix expression
        if (OperandCheck(exp[i]))
        {
            postfix[j] = exp[i];
            j++;
            i++;
        }
        // if not operand or if operator
        else
        {
            // chcking the precendences in term of out of the stack and into the stack
            /* if character outside stack or character from expression is having higher precedence than precedence of character inside the
            stack -> push it into the stack and move further to next character of expression */
            if (PrecedenceOut(exp[i]) > PrecedenceIn(st.stackTop()))
            {
                st.Push(exp[i]);
                i++;
            }
            /* if character outside stack or character from expression is having equal precedence than precedence of character inside the
            stack -> just pop out from stack and move further to next character of expression */
            // this condition will work for paranthesis in the expression ('(', ')')
            else if (PrecedenceOut(exp[i]) == PrecedenceIn(st.stackTop()))
            {
                st.Pop();
                i++;
            }
            /* else character outside stack or character from expression is having lower precedence than precedence of character inside the
            stack -> pop out from stack and add it to postfix expression and move further to next character of postfix istead of expression */
            else
            {
                postfix[j] = st.Pop();
                j++;
            }
        }
    }
    // the final step is to add all the remaining characters of stack into the post fix ((if applicable) or (!isEmpty()))
    while (st.isEmpty() != true)
    {
        postfix[j] = st.Pop();
        j++;
    }
    postfix[j] = '\0';

    // returning converted postfix expresion
    return postfix;
}

// ----- Helper Functions for "Prefix Conversion" -----

// this function is used in further implementation in Prefix conversion and created for purpose of ease
// this will reverse a character array and retruns new character array
char *Reverse(char *exp)
{
    // declaring and initializing a character array for storing and retruning
    char *arr = new char[100];

    // taking length by of given array (will use while traversing purpose)
    int len = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        len++;
    }

    // traversing through given expression and storing reversed array in newly created array
    int j = 0;
    for (int i = len - 1; i > -1; i--)
    {
        arr[j] = exp[i];
        j++;
    }
    arr[j] = '\0';

    // returning reversed array
    return arr;
}
// this function is used in further implementation in Prefix conversion and created for purpose of ease
// this function will reverse paranthesis '(' -> ')', ')' -> '('
void ParanthesisReversing(char *exp)
{
    // reversing paranthesis
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            exp[i] = ')';
        }
        else if (exp[i] == ')')
        {
            exp[i] = '(';
        }

        else
        {
            continue;
        }
    }
}
// ----- Helper Functions ends -----

// this function will use above funtions and stack as well
// its globally declared and taking the pointer to expression as parameter then returning poiter to the (converted to prefix) expression
char *ConvertPrefix(char *exp)
{
    /* for Prefix conversion we will first reverse the given string and then we will reverse all the paranthesis (if any), then we will
    convert that into postfix and finally reversing that again will convert it into prefix */

    // reversing
    char *rev1 = Reverse(exp);

    // reversing paranthesis
    ParanthesisReversing(rev1);

    // converting to postfix
    char *con1 = ConvertPostfix(rev1);

    // reversing again
    char *rev2 = Reverse(con1);

    // returning converted Prefix expression
    return rev2;
}

// ----- Helper Functions for "Evaluation of Expression" -----

// this is a helping functions further used in evaluation purpose
// this will convert a character into integer number
int ConvertToNumber(char *arr)
{
    int output = 0;
    int temp = 1;
    int intArray[10];
    for (int i = 0; arr[i] != 0; i++)
    {
        temp *= 10;
    }
    temp /= 10;

    for (int i = 0; arr[i] != 0; i++)
    {
        int num = arr[i] - '0';
        output += num * temp;
        temp /= 10;
    }
    return output;
}
// this will be used for evaluating power ^
int pow(int val, int p)
{
    int ans = 1;
    for (int i = 0; i < p; i++)
    {
        ans = ans * val;
    }
    return ans;
}
// ----- Helper Functions ends -----

// evaluation of expression through postfix
// this is a global function using integer stack class and above helping functions taking a postfix converted expression as argument and evaluating it
int Evalution(char *postfix)
{
    // declaring object of declared integer type stack class
    intStack st;

    // taking variables for evaluation purpose and storing results
    int x1, x2 = 0;
    int result;

    // iterating through the expression
    int i = 0;
    while (postfix[i] != '\0')
    {
        // leaving spaces
        if (postfix[i] == ' ')
        {
            i++;
        }

        // if operand
        else if (OperandCheck(postfix[i]))
        {
            // declaring and initializing a character type array to store complete operand until operator comes
            char *tmparr;
            tmparr = new char[20];

            // iterating again for storing complete operand (which is stored character by charater in array)
            int j = 0;
            while (postfix[i] != ' ')
            {
                tmparr[j] = postfix[i];
                i++;
                j++;
            }
            tmparr[j] = '\0';

            // converting that operand character array into integer by passing into helping function
            int num;
            num = ConvertToNumber(tmparr);

            // finally [ushing it into stack
            st.Push(num);
        }

        // if operator -> poping out last two operands from stack and performing operations accordingly
        else if (!OperandCheck(postfix[i]))
        {
            // poping last two operands
            x2 = st.Pop();
            x1 = st.Pop();

            // performing operations accordingly and storing it into result
            if (postfix[i] == '+')
            {
                result = x1 + x2;
            }
            else if (postfix[i] == '-')
            {
                result = x1 - x2;
            }
            else if (postfix[i] == '*')
            {
                result = x1 * x2;
            }
            else if (postfix[i] == '/')
            {
                result = x1 / x2;
            }
            else if (postfix[i] == '^')
            {
                result = pow(x1, x2);
            }
            else if (postfix[i] == '%')
            {
                result = x1 % x2;
            }
            // pushing into the stack
            st.Push(result);
            i++;
        }
        else
        {
            i++;
        }
    }
    // returning evaluated result
    return (st.stackTop());
}

// this function is for overall implementation, istead of using main() we are creating a function
void implementation()
{
    // declaring and initializing a character array dynamically which will take expression
    char *exp;
    exp = new char[100];

    cout << "\n--------------------------------------" << endl;
    cout << "INFIX TO PREFIX AND POSTFIX CONVERSION" << endl;
    cout << "--------------------------------------" << endl;

    cout << "\nNote:" << endl;
    cout << "1. Enter Expression without spaces." << endl;
    cout << "2. Expression can have only following operators." << endl;
    cout << "\t-Paranthesis ()" << endl;
    cout << "\t-Operands can be Integers only." << endl;
    cout << "\t-Addition (+), Subtration(-), Multiplication (*), Division(/), Power(^) and Modulo(%)." << endl;

    // creating loop until user don't want to terminate
    while (true)
    {
        cout << "\n\n------------------------------" << endl;
        // taking expression as input
        cout << "Enter expression: ";
        cin >> exp;

        // adding spaces after every operand for seperation and ease of evaluation and readablity
        exp = AddSpaces(exp);

        // if valid
        if (checkBalance(exp) == true)
        {
            // telling validity

            // converting to prefix and printing converted expression
            char *conpre = ConvertPrefix(exp);
            cout << "------------------------------" << endl;
            cout << "\nValidity: Valid" << endl;
            cout << "\nPrefix:" << conpre << endl;

            // converting to postfix and printing converted expression
            char *conpost = ConvertPostfix(exp);
            cout << "\nPostfix: " << conpost << endl;

            // evaluating and printing result
            int eval = Evalution(conpost);
            cout << "\nResult: " << eval << endl;
            cout << "------------------------------" << endl;

            // asking user for choice and taking input
            cout << "\n\nPress: " << endl;
            cout << "1: For Reentering the expression." << endl;
            cout << "2: For Termination." << endl;
            cout << "Enter: ";
            int chk;
            cin >> chk;

            // implementing according to choice
            if (chk == 1)
            {
                continue;
            }
            else if (chk == 2)
            {
                cout << "\nTerminated!\n"
                     << endl;
                break;
            }
            // terminating on wrong choice or input
            else
            {
                cout << "\nTerminated!\n"
                     << endl;
                break;
            }
        }

        // if not valid
        else if (checkBalance(exp) != true)
        {
            // telling validity
            cout << "\nValidity: Not Valid" << endl;

            // asking user for choice and taking input
            cout << "Press: " << endl;
            cout << "1: For Reentering the expression." << endl;
            cout << "2: For Termination." << endl;
            cout << "Enter: ";
            int chk;
            cin >> chk;

            // implementing according to choice
            if (chk == 1)
            {
                continue;
            }
            else if (chk == 2)
            {
                cout << "\nTerminated!" << endl;
                break;
            }
            // terminating on wrong choice or input
            else
            {
                cout << "\nTerminated!\n"
                     << endl;
                break;
            }
        }
    }
}

int main()
{
    implementation();
    return 0;
}