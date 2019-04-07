#ifndef TABLEAITOOL_H
#define TABLEAITOOL_H

#include <QStringList>
#include "FieldItem.h"

class TableAITool
{
public:
	static QStringList analyzeMixture(QString mixture, QList<FieldItem>fields);

};

#endif