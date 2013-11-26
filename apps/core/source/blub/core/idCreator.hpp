#ifndef IDCREATOR_HPP
#define IDCREATOR_HPP

#include "blub/async/mutex.hpp"
#include "blub/async/mutexLocker.hpp"

namespace blub
{

/** creates ids */
template <typename idType>
class idCreator : public async::mutex
{
public:

    idCreator()
        : m_idCounter(0)
    {;}

    /** if gets called by multiple threads lock class before or call createIdThreadSafe */
    idType createId(void)
    {
        return ++m_idCounter;
    }

    /** returns threadsafe a new id, call createId if class only gets called by one thread */
    idType createIdThreadSafe(void)
    {
        async::mutexLocker locker(*this); (void)locker;
        return createId();
    }

private:
    idType m_idCounter;
};


}

#endif // IDCREATOR_HPP
