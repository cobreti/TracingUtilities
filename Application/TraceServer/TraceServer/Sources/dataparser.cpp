#include "includes/dataparser.hpp"

#include <qtCore>

namespace TraceServer
{
    DataParser::DataParser(PrimaryStorage* pStorage, int bufferSize) :
        pBuffer_{nullptr},
        pWritePos_{nullptr},
        pBufferEnd_{nullptr},
        bufferSize_{bufferSize},
        timestampFormater_{pStorage},
        count_{0}
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
//                qDebug() << count_ << + " partial trace line : " << str;

                pWritePos_ = pBuffer_;
            }

            *pWritePos_ = *pBuffer;
            pBuffer ++;
            count_ ++;

            if ( *pWritePos_ == '\0' )
            {
                timestampFormater_.Format(pBuffer_, pWritePos_ - pBuffer_);

//                QString str(pBuffer_);
//                qDebug() << count_ << + " trace line : " << str;

                pWritePos_ = pBuffer_;
            }
            else
            {
                pWritePos_ ++;
            }

            count_ ++;
        }
    }
}
