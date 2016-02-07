#ifndef ITEMINSERTIONFAILURE_HPP
#define ITEMINSERTIONFAILURE_HPP

#include <stdexcept>

namespace TraceServer
{
    namespace Exceptions
    {
        class ItemInsertionFailure : public std::runtime_error
        {
        public:

            using baseClass = std::runtime_error;

        public:
            ItemInsertionFailure( const std::string& err ) :
                baseClass(err)
            {
            }

            ItemInsertionFailure( const char* err ) :
                baseClass(err)
            {

            }
        };
    }
}

#endif // ITEMINSERTIONFAILURE_HPP
