
#ifndef __OBSERVER__H__
#define __OBSERVER__H__

class Observable;


class ObserverInterface
{
public:
    virtual void notify(Observable * sdo) = 0;

    virtual ~ObserverInterface() = default;
};

#endif
