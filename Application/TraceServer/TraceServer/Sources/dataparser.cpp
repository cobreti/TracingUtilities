#include "includes/dataparser.hpp"

#include <qtCore>

namespace TraceServer
{
    DataParser::DataParser(int bufferSize) :
        pBuffer_{nullptr},
        pWritePos_{nullptr},
        pBufferEnd_{nullptr},
        bufferSize_{bufferSize}
    {
        pBuffer_ = new char[bufferSize_];
        pWritePos_ = pBuffer_;
        pBufferEnd_ = pBuffer_ + bufferSize_ - 1;
    }

    DataParser::~DataParser()
    {
        delete[] pBuffer_;
    }

    void DataParser::parse(char *pBuffer, int bufferSize)
    {
        char* pSrcEnd = pBuffer + bufferSize;

        while ( pBuffer != pSrcEnd )
        {
            if ( pWritePos_ == pBufferEnd_ )
            {
                *pWritePos_ = '\0';

                timestampFormater_.Format(pBuffer_, pWritePos_ - pBuffer_);
//                QString str(pBuffer_);

//                qDebug() << "partial trace line : " << str;

                pWritePos_ = pBuffer_;
            }

            *pWritePos_ = *pBuffer;
            pBuffer ++;

            if ( *pWritePos_ == '\0' )
            {
                timestampFormater_.Format(pBuffer_, pWritePos_ - pBuffer_);
//                QString str(pBuffer_);
//                qDebug() << "trace line : " << str;
                pWritePos_ = pBuffer_;
            }
            else
            {
                pWritePos_ ++;
            }
        }
    }
}
