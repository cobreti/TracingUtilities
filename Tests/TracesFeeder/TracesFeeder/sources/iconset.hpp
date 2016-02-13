#ifndef ICONSET_HPP
#define ICONSET_HPP

#include <map>
#include <QtCore>


template <typename STATES>
class IconSet
{
public:
    IconSet() {}

    IconSet(const IconSet&) = delete;
    const IconSet& operator = (const IconSet&) = delete;

    void set( STATES state, QIcon icon )
    {
        icons_.insert( std::make_pair(state, icon) );
    }

    QIcon get( STATES state ) const
    {
        auto pos = icons_.find(state);

        if (pos != icons_.end())
            return pos->second;

        return QIcon();
    }

protected:

    using IconsSet_T = std::map<STATES, QIcon>;

protected:

    IconsSet_T      icons_;
};

#endif // ICONSET_HPP
