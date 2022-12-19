#ifndef SERVER_HPP
#define SERVER_HPP

#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer {
  Q_OBJECT
 public:
  explicit Server(QObject *parent = nullptr);

  int count();
  void close();

  QString message() const;
  void setMessage(const QString &message);

 public slots:
  void disconnected();
  void readyRead();

 signals:

  void changed();

  // QTcpServer interface
 protected:
  void incomingConnection(qintptr handle);

 private:
  QList<QTcpSocket *> m_list;
  QString m_message;
};

#endif  // SERVER_HPP
