#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "header.h"
#include "keytype.h"
#include "vector2.h"


class InputManager
{
    bool _keyTable[KeyType::LAST_VALUE];
    Vector2<float> _mousePosition = Vector2<float>(0.f, 0.f); // From -1 to 1, where 0 is window center

public:
    InputManager();
    Vector2<float> getMousePosition();
    void handleMouseMove(float x, float y);
    void handleMouseButtons(int button, bool state, float x, float y);
    void handleKeyboardButtons(unsigned char key, bool state, float x, float y);
    bool isKeyPressed(KeyType key);

};

#endif // INPUTMANAGER_H
