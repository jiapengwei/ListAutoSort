#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ListAutoSort.h"
#include <QClipboard>
#include <QMimeData>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include <QMenu>
#include <QPoint>
#include <QAction>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QDesktopServices>
#include "FieldItem.h"
#include "FileUtil.h"
#include "Global.h"
#include "StringUtil.h"
#include "ListItemDelegate.h"
#include "TableAITool.h"

class ListAutoSort : public QMainWindow
{
	Q_OBJECT

public:
	ListAutoSort(QWidget *parent = Q_NULLPTR);
	QString getDefaultRegex(QString field);

private:
	void initView();
	void setTableHeader();

	void readFIeldsInfo();
	void writeFieldsInfo();
	void refreshFieldsInfo();

	bool setTableARow(int row, QString mixture, QList<FieldItem>fields);
	QStringList analyzeMixture(QString mixture, QList<FieldItem>fields);

	void moveListItem(int from, int to);
	void moveTableItem(int from, int to);

	public slots :
	void slotInputButtonClicked();
	void slotInsertButtonClicked();
	void slotPasteButtonClicked();
	void slotResortButtonClicked();
	void slotExcelButtonClicked();

	void slotFieldItemAdd();
	void slotFieldItemRowChanged();
	void slotFieldItemTextModified(int row, QString text);
	void slotFieldItemPatternModified(QString text);

	void slotFieldItemMenu(QPoint p);
	void slotFieldItemRename();
	void slotFieldItemDelete();
	void slotFieldItemMoveUp();
	void slotFieldItemMoveDown();
	void slotFieldItemMoveTop();
	void slotFieldItemMoveBottom();

	void slotWorkSpaceActionTriggered();
	void slotHelpActionTriggered();
	void slotAboutActionTriggered();

signals:

private:
	Ui::ListAutoSortClass ui;

	QString savedPath;
	QList<FieldItem> fields;
	QStringList mixtures;

	QMap<QString, QString>defaultRegexp;
};
