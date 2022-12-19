#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QMessageBox>
#include <QPushButton>

#include "server.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog {
  Q_OBJECT

 public:
  Dialog(QWidget *parent = nullptr);
  ~Dialog();

 private slots:
  void on_btnStart_clicked();

  void on_btnStop_clicked();

  void next();
  void back();
  void changed();

 private:
  Ui::Dialog *ui;

  QPushButton *btnBack;
  QPushButton *btnNext;
  Server server;

  void init();
  void enableButtons();
};
#endif  // DIALOG_HPP
