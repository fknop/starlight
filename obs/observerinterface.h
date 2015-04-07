
#ifndef __OBSERVER__H__
#define __OBSERVER__H__

#include <string>

class Observable;


class ObserverInterface
{
public:
    virtual void notify(Observable * sdo, std::string msg="UPDATE_RAYS") = 0;
    virtual ~ObserverInterface() = default;
};

#endif
