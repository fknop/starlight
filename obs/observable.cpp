#include "observable.h"
#include "observerinterface.h"

#include <iostream>

void Observable::add_observer(ObserverInterface * obs)
{
    observers_.insert(obs);
}

void Observable::remove_observer(ObserverInterface * obs)
{
    observers_.erase(obs);
}

void Observable::notify_all()
{
    for (auto i : observers_)
        i->notify(this);
}
