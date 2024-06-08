#include <iostream>

#include "Ticket.h"
#include "Application.h"

int main()
{
    Application app;
    while(app.isRunning())
    {
        app.Run();
    }
}
