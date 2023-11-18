#include <iostream>
#include "Ticket.h"



int main()
{
    Ticket MyTicket(0.33, 30); // Reduced duration for testing
    std::cout << "Ticket ID: " << MyTicket.getID() << std::endl;
    MyTicket.generateBarcode();
    MyTicket.updateExpiration();
  
    return 0;
}
