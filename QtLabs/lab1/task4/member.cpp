#include "member.h"

Member::Member(const QString &name,const QString &age,const QString &growth,const QString &weight,const QString &sex,
               const QString &partnerMinAge,const QString &partnerMaxAge, const QString &partnerMinGrowth,const QString &partnerMaxGrowth,
                const QString &partnerMinWeight,const QString &partnerMaxWeight, const QString &infoAboutYourself)
{
     _name = name;
     _age = age;
     _growth = growth;
     _weight = weight;
     _sex = sex;

     _partnerMinAge = partnerMinAge;
     _partnerMaxAge = partnerMaxAge;

     _partnerMinGrowth = partnerMinGrowth;
     _partnerMaxGrowth = partnerMaxGrowth;

     _partnerMinWeight = partnerMinWeight;
     _partnerMaxWeight = partnerMaxWeight;
     _infoAboutYourself = infoAboutYourself;

}

QList<QString> Member::getInfo(){
    QList<QString> infoList;

    infoList.push_back(_name);
    infoList.push_back(_age);
    infoList.push_back(_growth);
    infoList.push_back(_weight);
    infoList.push_back(_sex);
    infoList.push_back(_partnerMinAge);
    infoList.push_back(_partnerMaxAge);
    infoList.push_back(_partnerMinGrowth);
    infoList.push_back(_partnerMaxGrowth);
    infoList.push_back(_partnerMinWeight);
    infoList.push_back(_partnerMaxWeight);
    infoList.push_back(_infoAboutYourself);

    return infoList;
}
