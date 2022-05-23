#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QtWidgets>
#include"member.h"

bool openFile(QFile &file);

int readInfo(QFile &file,QVector<Member> &_listOfMembers);

void writeInfo(QVector<Member> _listOfMembers, QFile &file);

QVector<QPair<Member,Member>> findPair(QVector<Member> listOfMembers,QVector<QPair<int,int>> &pairsIndex);

#endif // FUNCTIONS_H
