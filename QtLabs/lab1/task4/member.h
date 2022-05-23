#ifndef MEMBER_H
#define MEMBER_H
#include<QWidget>

class Member{
public:
    Member(const QString &name,const QString &age,const QString &growth,const QString &weight,const QString &sex,
           const QString &partnerMinAge,const QString &partnerMaxAge, const QString &partnerMinGrowth,const QString &partnerMaxGrowth,
            const QString &partnerMinWeight,const QString &partnerMaxWeight,const QString &infoAboutYourself);
    QList<QString> getInfo();
private:
    QString _name;
    QString _age;
    QString _growth;
    QString _weight;
    QString _sex;
    QString _infoAboutYourself;

    QString _partnerMinAge;
    QString _partnerMaxAge;

    QString _partnerMinGrowth;
    QString _partnerMaxGrowth;

    QString _partnerMinWeight;
    QString _partnerMaxWeight;
};

#endif // MEMBER_H
