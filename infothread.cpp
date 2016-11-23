#include "infothread.h"

#include <QtCore>



infoThread::infoThread()
{
    m_stop = false;
}

void infoThread::run()
{
    qDebug()<<"From script thread: "<<currentThreadId();
    while (1) {
        {
            QMutexLocker locker(&m_mutex);
            if (m_stop) break;

            char buf[BUFSIZE];
            FILE *fp;

            if ((fp = popen("./writeToCout", "r")) == NULL) {
                printf("Error opening pipe!\n");

            }

            while (fgets(buf, BUFSIZE, fp) != NULL) {
                // Do whatever you want here...
                printf("OUTPUT: %s", buf);
            }

            if(pclose(fp))  {
                printf("Command not found or exited with error status\n");

            }
        }
        msleep(10);
    }
}
