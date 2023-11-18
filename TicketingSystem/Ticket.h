#pragma once
// Ticket.h
#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <ctime>
#include <sstream>

class Ticket {
public:
    Ticket(double price, int durationMinutes);
    ~Ticket();

    uint64_t getID() const;
    double getPrice() const;
    bool isValid() const;
    void useTicket();
    void generateBarcode();
    void updateExpiration();
    std::string getRemainingTime() const;
    time_t getTicketExpirationTime() const;
private:
    static int ticketIDCounter;
    uint64_t ticketID;
    double price;
    int TicketTimer;
    time_t TicketExpirationTime;
    std::ostringstream formattedTime;

 
};

#endif // TICKET_H
