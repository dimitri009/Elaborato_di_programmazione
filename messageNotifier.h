//
// Created by dimit on 01/07/2021.
//

#ifndef ELABORATO_DI_PROGRAMMAZIONE_MESSAGENOTIFIER_H
#define ELABORATO_DI_PROGRAMMAZIONE_MESSAGENOTIFIER_H

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <list>
#include <ctime>

#include "message.h"
#include "observer.h"
#include "chat.h"


class messageNotifier: public observer{
public:
    explicit messageNotifier(bool act, std::shared_ptr<chat> sub) : active(act), subject(std::move(sub)){}
    ~messageNotifier() override= default;

    void attach() override;

    void detach() override;

    void update() override ;

    static void draw(const message &ms);

    bool isActive() const {
        return active;
    }

    void setActive(bool a) {
        messageNotifier::active = a;
    }

private:
    bool active;
    std::shared_ptr<chat> subject;
};

#endif //ELABORATO_DI_PROGRAMMAZIONE_MESSAGENOTIFIER_H
