#include "textBox.h"
#include <cstddef>

textBox::textBox(int x, int y, int w, int h, int max) {
    rect.x = x;
    rect.y = y;
    rect.width = w;
    rect.height = h;
    this->max = max;
    letterCount = 0;
    for(int i = 0; i < MAX_INPUT_CHARS; i++) {
        message[i] = '\0';
    }
}

void textBox::update() {

    mouseOnText = true;

    if (mouseOnText)
    {
        int key = GetKeyPressed();

        // NOTE: Only allow keys in range [32..125]
        if ((key >= 32) && (key <= 125) && (letterCount < max))
        {
            message[letterCount] = (char)key;
            letterCount++;
        }

        if (IsKeyPressed(KEY_BACKSPACE) && letterCount > 0)
        {
            letterCount--;
            message[letterCount] = '\0';

            if (letterCount < 0) letterCount = 0;
        }
    }

    if (mouseOnText) framesCounter++;
    else framesCounter = 0;
}

void textBox::draw(Color color) {
    DrawText(message, rect.x + 5, rect.y + 8, 20, color);
}

void textBox::setMessage(const char newMessage[MAX_INPUT_CHARS + 1]) {
  for(int i = 0; i < MAX_INPUT_CHARS + 1; i++) {
    if(newMessage[i] == ' ' || newMessage[i] == NULL || !newMessage[i])
      break;
    message[i] = newMessage[i];
    letterCount++;
  }
}