#include "observable.h"
#include "observer.h"

void Observable::addObserver(Observer * obs)
{
    observers.insert(obs);
}

void Observable::removeObserver(Observer * obs)
{
    observers.erase(obs);
}


void Observable::notifyAll()
{
    for (auto i : observers)
        i->notify(this);
}
