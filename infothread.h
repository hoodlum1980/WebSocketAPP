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
    int idx;
    bool m_stop;

public slots:
    void stop()
    {
        qDebug()<<"Thread::stop called from main thread: "<<currentThreadId();
        //QMutexLocker locker(&m_mutex);
        this->m_stop = true;
    }


signals:
    void sendOutput(char* data, int idx_th);

private:
    QMutex m_mutex;


    void run();
};

#endif // INFOTHREAD_H

