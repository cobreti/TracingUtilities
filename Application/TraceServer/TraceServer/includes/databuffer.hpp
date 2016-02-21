#ifndef DATABUFFER_HPP
#define DATABUFFER_HPP

#include <cassert>

namespace TraceServer
{
    class DataBuffer
    {
    public:
        DataBuffer(int size) : bufferSize_{size}, dataSize_{0}
        {
            pBuffer_ = new char[bufferSize_];
            pWritePos_ = pBuffer_;
        }

        ~DataBuffer()
        {
            delete[] pBuffer_;
        }

        char* getWritePosForData(int dataSize) noexcept
        {
            assert( !(dataSize_ + dataSize > bufferSize_) );

            char*   pos = pWritePos_;

            dataSize_ += dataSize;
            pWritePos_ += dataSize;

            return pos;
        }

        char* bufferPos() const noexcept { return pBuffer_; }
        int dataSize() const noexcept { return dataSize_; }
        int availableSize() const noexcept { return bufferSize_ - dataSize_; }

        bool empty() const noexcept { return dataSize_ == 0; }

        void reset() noexcept
        {
            pWritePos_ = pBuffer_;
            dataSize_ = 0;
        }

        DataBuffer(const DataBuffer&) = delete;
        const DataBuffer& operator = (const DataBuffer&) = delete;

    protected:

        char*       pBuffer_;
        char*       pWritePos_;
        const int   bufferSize_;
        int         dataSize_;
    };
}

#endif // DATABUFFER_HPP
