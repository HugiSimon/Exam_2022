#include <iostream>
#include <Windows.h>
#include <stdio.h>

#include "Menu.h"

int main() {

	Menu Home;

	Home.ChoixInit();

	while (Home.Run()) {

	}

	return 0;
}