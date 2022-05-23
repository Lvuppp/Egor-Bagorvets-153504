#include <QCoreApplication>

#include<iostream>
using namespace std;

struct Expression
{
public:
    virtual  ~Expression() {};
    virtual double evaluate() const = 0;

};

struct Number : Expression
{
public:
    Number(const double &num) {
        _num = num;
    };

    ~Number(){};

    double evaluate() const {
        return _num;
    };

private:
    double _num;
};

struct BinaryOperation: Expression
{
public:
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : _left(left), _op(op), _right(right)
    { };


    double evaluate() const {
        double answer;
        switch (_op)
        {
        case '+':
            answer = _left->evaluate() + _right->evaluate();
            break;
        case '-':
            answer = _left->evaluate() - _right->evaluate();
            break;
        case '*':
            answer = _left->evaluate() * _right->evaluate();
            break;
        case '/':
            answer = _left->evaluate() / _right->evaluate();
            break;
        default:
            break;
        }
        return answer;
    };

    ~BinaryOperation(){
        delete _left;
        delete _right;
    };

private:
    Expression const* _left;
    Expression const* _right;
    char _op;
};

bool checkEquals(Expression const* left, char op, Expression const* right){
    char _left[4];
    char _right[4];

    memcpy(_left,left,4);
    memcpy(_right,right,4);

    for(int i = 0; i < 4; i++){
        if(_left[i] != _right[i])
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));

    Expression* expr = new BinaryOperation(new Number(3), '+', sube);

    std::cout << expr->evaluate() << std::endl;

    delete expr;
    return a.exec();
}
