#ifndef TASKTABLE_H
#define TASKTABLE_H
#include"hashtable.h"
template<class T>
class TaskTable : public HashTable<T>
{
public:
    TaskTable();
    vector<string> getAllData();

};

template<class T>
TaskTable<T>::TaskTable(){

}



#endif // TASKTABLE_H
