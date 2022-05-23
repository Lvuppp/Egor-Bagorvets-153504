#ifndef FLIGHT_H
#define FLIGHT_H

#include"QDate"

class Flight{

public:
    QDate date;
    QTime dispatchTime;
    QString number;
    QString destination;
    int freePlaces;
    ~Flight(){};
};

#endif // FLIGHT_H
