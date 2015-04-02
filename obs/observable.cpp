#include "observable.h"
#include "observer.h"

void Observable::add_observer(Observer * obs)
{
    this->observers_.insert(obs);
}

void Observable::remove_observer(Observer * obs)
{
    this->observers_.erase(obs);
}


void Observable::notify_all()
{
    for (auto i : this->observers_)
        i->notify(this);
}
