#pragma once

#include <iostream>
#include <ctime>
#include <sstream>

class Ticket {
public:
    Ticket();
    Ticket(const Ticket& other);
    ~Ticket();

    uint64_t getID() const;
    double getPrice() const;
    bool isTicketValid(const Ticket& Ticket) const;
    void useTicket();
    void generateBarcode();
    void updateTicketExpiration(Ticket& Ticket);
    std::string getRemainingTime() const;
    time_t getTicketExpirationTime(const Ticket& Ticket) const;
    void checkForTickets();
    Ticket createTicket(float price);
    void Ticket::buyTicket(float price);
private:
    static int m_TicketIDCounter;
    uint64_t m_TicketID;
    float m_Price;
    int m_TicketTimer;
    time_t m_TicketExpirationTime;
    std::ostringstream m_FormattedTime;
};
