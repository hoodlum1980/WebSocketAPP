#include "getdatathread.h"

#include <QtCore>

class getDataThread : public QThread
{
    Q_OBJECT

public:
    Thread():m_stop(false){}

public slots:
    void stop()
    {
        qDebug()<<"Thread::stop called from main thread: "<<currentThreadId();
        QMutexLocker locker(&m_mutex);
        m_stop=true;
    }

private:
    QMutex m_mutex;
    bool m_stop;

    void run()
    {
        qDebug()<<"From worker thread: "<<currentThreadId();
        while (1) {
            QMutexLocker locker(&m_mutex);
            if (m_stop) break;
            msleep(10);
        }
    }
};
