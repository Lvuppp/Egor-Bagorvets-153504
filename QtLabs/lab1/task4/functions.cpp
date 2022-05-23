#include"functions.h"

bool openFile(QFile &file){

    if(!file.exists()){
        qWarning()<< "File doesnt exist";
        return false;
    }

    if(!file.open(QIODevice::ReadWrite)){
        qWarning()<< "Cant use this file";
        return false;
    }
    return true;
}

int readInfo(QFile &file, QVector<Member> &_listOfMembers){
    QTextStream stream(&file);
    _listOfMembers.clear();

    if(openFile(file)){
        while(!stream.atEnd()){
            QString str = stream.readLine();
            QVector<QString> parts = str.split("$");

            if(parts.length() != 12){
                file.close();
                qDebug() << "Broken file";
                return 1;
            }

            Member member(parts[0],parts[1],parts[2],parts[3],parts[4],parts[5],parts[6],parts[7],parts[8],parts[9],parts[10],parts[11]);
            _listOfMembers.push_back(member);
        }
    }

    file.close();

    return 0;
}

void writeInfo(QVector<Member> listOfMembers, QFile &file){
    QTextStream stream(&file);

    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate)){

        for(int j = 0; j < listOfMembers.length();j++){
        QVector<QString> infoMembers = listOfMembers[j].getInfo();

            for(int i = 0 ; i < 11; i++){
                stream << infoMembers[i] << "$";
            }

            stream << infoMembers[11]<<"\n";
        }
    }

    file.close();

    return;
}


void editInfo(QVector<Member> &listOfMembers, QFile &file){

   writeInfo(listOfMembers,file);
   readInfo(file,listOfMembers);
}

QVector<QPair<Member,Member>> findPair(QVector<Member> listOfMembers, QVector<QPair<int,int>> &pairsIndex){
    QVector<QPair<Member,Member>> pairs;
    for(int i  = 0; i < listOfMembers.length();i++){
        for(int j = i + 1; j< listOfMembers.length();j++){
            if(listOfMembers[i].getInfo()[5].toInt() < listOfMembers[j].getInfo()[1].toInt() &&
                    listOfMembers[i].getInfo()[6].toInt() > listOfMembers[j].getInfo()[1].toInt() &&
                    listOfMembers[i].getInfo()[7].toInt() < listOfMembers[j].getInfo()[2].toInt() &&
                    listOfMembers[i].getInfo()[8].toInt() > listOfMembers[j].getInfo()[2].toInt() &&
                    listOfMembers[i].getInfo()[9].toInt() < listOfMembers[j].getInfo()[3].toInt() &&
                    listOfMembers[i].getInfo()[10].toInt() > listOfMembers[j].getInfo()[3].toInt()){
                QPair<Member,Member> pair(listOfMembers[i],listOfMembers[j]);
                pairs.push_back(pair);

                QPair<int,int> indexs(i,j);
                pairsIndex.push_back(indexs);
            }
        }
    }

    return pairs;
}
