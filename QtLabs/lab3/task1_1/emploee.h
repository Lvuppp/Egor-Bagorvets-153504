#ifndef Employee_H
#define Employee_H
#include<QString>

class Employee
{
public:
    Employee(){};
    Employee(QString firstName,QString secondName,QString number,int workHours,int payment,int salary) :
        firstName(firstName),secondName(secondName),number(number),workHours(workHours),payment(payment),salary(salary){};
    QString firstName;
    QString secondName;
    QString number;
    int workHours;
    int payment;
    int salary;
    ~Employee(){};
};

#endif // Employee_H
