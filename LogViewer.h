#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LogViewer.h"

class LogViewer : public QMainWindow
{
	Q_OBJECT

public:
	LogViewer(QWidget *parent = Q_NULLPTR);

private:
	Ui::LogViewerClass ui;
};
