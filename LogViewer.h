#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include "ui_LogViewer.h"

class LogViewer : public QMainWindow
{
	Q_OBJECT

public:
	LogViewer(QWidget *parent = Q_NULLPTR);

public slots:
	void fileOpenClick();

private:
	Ui::LogViewerClass ui;

};
