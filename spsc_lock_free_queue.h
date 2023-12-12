#ifndef SPSC_LOCK_FREE_QUEUE_H
#define SPSC_LOCK_FREE_QUEUE_H

/*
 *  Based on Timur Doumler's talk in ACCU 2017
 */

#include <array>
#include <atomic>
#include <cstddef>

//maybe i would make it multiconsumer
template<typename T, size_t size>
class SPSC_LockFreeQueue
{
public:
    //SPSC_LockFreeQueue();
    bool pop(T& returnedElement)
    {
        auto oldWritePos = writePos.load();
        auto oldReadPos = readPos.load();

        if(oldWritePos == oldReadPos) //queue is full
            return false;

        returnedElement = std::move( ringBuffer[oldReadPos] );
        readPos.store( getNextPosition( oldReadPos ) ); //to store elements in a circular manner instead of linear
        return true;
    }
    bool push (T&& insertElement)
    {
        auto oldWritePos = writePos.load();
        auto newWritePos = getNextPosition( oldWritePos );

        if(newWritePos == readPos.load()) //queue is full
            return false;

        ringBuffer[oldWritePos] = insertElement;
        writePos.store( newWritePos );
        return true;
    }

private:
    static constexpr size_t ringBufferSize = size+1;
    static constexpr size_t getNextPosition(size_t pos) noexcept
    {
        return ++pos == ringBufferSize ? 0 : pos;
    }
    std::array<T,ringBufferSize> ringBuffer;
    std::atomic<size_t> readPos{0}, writePos{0};
};

#endif // SPSC_LOCK_FREE_QUEUE_H
