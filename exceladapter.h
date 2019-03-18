#ifndef EXCELADAPTER_H
#define EXCELADAPTER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QList>
#include <QFile>

class exceladapter
{
public:
	exceladapter();
	QList<QVariant> valuelist;
	QList<QString> stringlist;
	void readfile(QString filename, QString sheetname = "[Sheet1$]", int colNo = 0);
    void readfile2(QString filename, QString sheetname = "[Sheet1$]", int colNo = 0);
};

#endif // EXCELADAPTER_H
