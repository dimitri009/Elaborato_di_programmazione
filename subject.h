//
// Created by dimit on 01/07/2021.
//

#ifndef ELABORATO_DI_PROGRAMMAZIONE_SUBJECT_H
#define ELABORATO_DI_PROGRAMMAZIONE_SUBJECT_H

#include "observer.h"
class subject {
public:
    virtual ~subject(){}
    virtual void subscribe(std::shared_ptr<observer>  observer) = 0;
    virtual void unsubscribe(std::shared_ptr<observer>  observer) = 0;
    virtual void notify() = 0;
};

#endif //ELABORATO_DI_PROGRAMMAZIONE_SUBJECT_H
