#ifndef INFOTHREAD_H
#define INFOTHREAD_H

#include <QtCore>

#define BUFSIZE 128

class infoThread : public QThread
{
Q_OBJECT

public:
    infoThread();
    ~infoThread();

    const char *script;
    void stop();
    bool m_stop;

public slots:



signals:
    void sendOutput();

private:
    QMutex m_mutex;


    void run();
};

#endif // INFOTHREAD_H

