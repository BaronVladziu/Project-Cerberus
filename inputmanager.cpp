#include "inputmanager.h"

InputManager::InputManager() {
    for (int i = 0; i < KeyType::LAST_VALUE; i++) {
        _keyTable[i] = false;
    }
}
void InputManager::handleMouseMove(float x, float y) {
    _mousePosition.x = x;
    _mousePosition.y = y;
}
void InputManager::handleMouseButtons(int button, bool state, float x, float y) {
    switch (button) {
        default: std::cout << "WARNING: Unknown mouse button used ("
                           << button << ")" << std::endl;
    }
    _mousePosition.x = x;
    _mousePosition.y = y;
}
void InputManager::handleKeyboardButtons(unsigned char key, bool state,
                                         float x, float y) {
    switch (key) {
        case 'w': _keyTable[KeyType::Up] = state; break;
        case 'a': _keyTable[KeyType::Left] = state; break;
        case 's': _keyTable[KeyType::Down] = state; break;
        case 'd': _keyTable[KeyType::Right] = state; break;
        default: std::cout << "WARNING: Unknown key used (" << key << ")" << std::endl;
    }
    _mousePosition.x = x;
    _mousePosition.y = y;
}
