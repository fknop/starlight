
#ifndef __OBSERVER__H__
#define __OBSERVER__H__

class Observable;


class Observer
{
public:
    virtual void notify(Observable * sdo) = 0;

    virtual ~Observer() = default;
};

#endif
