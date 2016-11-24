#ifndef INFOTHREAD_H
#define INFOTHREAD_H

#include <QtCore>

#define BUFSIZE 128


class infoThread : public QThread
{
public:
    infoThread();

public slots:
    // mozna nebude signal
    void stop(){
        qDebug()<<"Thread::stop called from main thread: "<<currentThreadId();
        QMutexLocker locker(&m_mutex);
        m_stop=true;
    }

private:
    QMutex m_mutex;
    bool m_stop;

    void run();
};

#endif // INFOTHREAD_H