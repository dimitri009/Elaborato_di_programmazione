//
// Created by dimit on 01/07/2021.
//

#ifndef ELABORATO_DI_PROGRAMMAZIONE_UNREADMESSAGENOTIFICATION_H
#define ELABORATO_DI_PROGRAMMAZIONE_UNREADMESSAGENOTIFICATION_H

#include <utility>
#include <vector>
#include <list>
#include <memory>
#include "observer.h"
#include "chat.h"
#include "subject.h"


class unreadMessageNotification: public observer {
public:
    explicit unreadMessageNotification(std::shared_ptr<chat> sub):subject(std::move(sub)){}

    ~unreadMessageNotification() override= default;

    void attach() override;

    void update() override;

    static void draw(int um);

private:
    std::shared_ptr<chat> subject;
};

#endif //ELABORATO_DI_PROGRAMMAZIONE_UNREADMESSAGENOTIFICATION_H
