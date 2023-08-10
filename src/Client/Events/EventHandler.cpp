//
// Created by User on 6/7/2023.
//
#pragma once
#include "EventHandler.hpp"
#include "Render/RenderEvent.hpp"
#include "../../SDK/SDK.hpp"
#include "Network/PacketEvent.hpp"

void EventHandler::registerListener(Listener *listener) {
    listeners.push_back(listener);
}

void EventHandler::unregisterListener(std::string name) {

    auto it = std::find_if(listeners.begin(), listeners.end(),
                           [&](const auto &listener) { return listener->name == name; });
    if (it != listeners.end()) {
        listeners.erase(it);
    }

}

void EventHandler::unregisterAll() {

    listeners.clear();

}

void EventHandler::onTick(TickEvent &event) {

    for (Listener* &listener: listeners) {

        if(event.getActor() == SDK::clientInstance->getLocalPlayer())
        listener->onLocalTick(event);
        else listener->onTick(event);

    }

}

void EventHandler::onPacketSend(PacketEvent &event) {

    for (Listener* &listener: listeners) {

        listener->onPacketSend(event);

    }

}

void EventHandler::onPacketReceive(PacketEvent &event) {

    for (Listener* &listener: listeners) {

        listener->onPacketReceive(event);

    }

}

void EventHandler::onKey(KeyEvent &event) {

    for (Listener* &listener: listeners) {

        listener->onKey(event);

    }
}

void EventHandler::onAttack(AttackEvent& event) {

    for (Listener*& listener : listeners) {
        
        listener->onAttack(event);

    }


}

void EventHandler::onMouse(MouseEvent &event) {

    for (Listener* &listener: listeners) {

        listener->onMouse(event);

    }
}

void EventHandler::onRender(RenderEvent &event) {

    for (Listener* &listener: listeners) {
        listener->onRender(event);
    }

}

void EventHandler::onSetupAndRender(SetupAndRenderEvent &event) {

    for (Listener* &listener: listeners) {
        listener->onSetupAndRender(event);
    }

}
