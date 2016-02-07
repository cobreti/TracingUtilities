#ifndef ITEMALREADYEXISTSINCONTAINER_HPP
#define ITEMALREADYEXISTSINCONTAINER_HPP

#include <stdexcept>

namespace TraceServer
{
    namespace Exceptions
    {
        class ItemAlreadyInContainer : public std::logic_error
        {
            using baseClass = std::logic_error;

        public:
            explicit ItemAlreadyInContainer(const std::string& err) :
                baseClass(err)
            {

            }

            explicit ItemAlreadyInContainer(const char* err) :
                baseClass(err)
            {

            }
        };
    }
}

#endif // ITEMALREADYEXISTSINCONTAINER_HPP
