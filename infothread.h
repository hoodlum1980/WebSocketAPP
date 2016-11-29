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

    bool m_stop;
    int test;

public slots:
    void stop()
    {
        qDebug()<<"Thread::stop called from main thread: "<<currentThreadId();
        //QMutexLocker locker(&m_mutex);
        m_stop = true;
    }


signals:
    void sendOutput(int data);

private:
    QMutex m_mutex;


    void run();
};

#endif // INFOTHREAD_H

