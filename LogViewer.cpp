#include "LogViewer.h"
#include <qfiledialog.h>

LogViewer::LogViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Connect MainMenu SIGNALs to SLOTs
	connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(fileOpenClick()));

}

void LogViewer::fileOpenClick()
{
	// Create an file select dialog in opening mode
	// Set it to accept only one existing file at a time
	QFileDialog OpenDialog;
	OpenDialog.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);
	OpenDialog.setFileMode(QFileDialog::ExistingFile);
	if (OpenDialog.exec())
	{
		// Set the MainWindow title with the name of the file, using the plataform native path separator
		QString fname = OpenDialog.selectedFiles().first();
		this->setWindowTitle("LogViewer - " + QDir::toNativeSeparators(fname));

		// Open the file and add it's contents to the textEdit
		QFile file;
		file.setFileName(fname);
		file.open(QIODevice::OpenModeFlag::ReadOnly);
		QByteArray fdata = file.readAll();
		file.close();
		ui.textEdit->setText(QString(fdata));
	}
}