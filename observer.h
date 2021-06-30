//
// Created by dimit on 01/07/2021.
//

#ifndef ELABORATO_DI_PROGRAMMAZIONE_OBSERVER_H
#define ELABORATO_DI_PROGRAMMAZIONE_OBSERVER_H

class observer {
public:
    virtual ~observer(){}
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;
};

#endif //ELABORATO_DI_PROGRAMMAZIONE_OBSERVER_H
