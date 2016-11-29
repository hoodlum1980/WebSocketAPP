#include "infothread.h"

#include <QtCore>
#include <QObject>



infoThread::infoThread()
{
    m_stop = false;
}

infoThread::~infoThread()
{
;
}



void infoThread::run()
{
    qDebug()<<"From script thread: "<<currentThreadId();
    while (1) {
        {
            //QMutexLocker locker(&m_mutex);
            if (m_stop) break;
            char buf[BUFSIZE];
            FILE *fp;

            if ((fp = popen(this->script, "r")) == NULL) {
                printf("Error opening pipe!\n");

            }

            while (fgets(buf, BUFSIZE, fp) != NULL ) {
                // Do whatever you want here...
                int pokus = 1000;
                emit sendOutput(buf);
                printf("OUTPUT: %s", buf);
                qDebug() << "stop? " << m_stop;
                if (m_stop){
                    //pclose(fp);
                    break;
                }

            }

            if(pclose(fp))  {
                printf("Command not found or exited with error status\n");
                emit sendOutput("dokonceno");
            }
        }
        msleep(1000);
    }
}

