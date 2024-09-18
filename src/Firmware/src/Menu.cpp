#include "Menu.h"
#include "DisplayControl.h"

void showMainMenu() {
    displayMessage("1. Start\n2. Settings\n3. Exit");
}

void handleMenuSelection(int selection) {
    switch (selection) {
        case 1:
            displayMessage("Starting...");
            break;
        case 2:
            displayMessage("Settings");
            break;
        case 3:
            displayMessage("Exiting...");
            break;
        default:
            displayMessage("Invalid Selection");
            break;
    }
}
