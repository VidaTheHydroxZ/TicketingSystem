// Ticket.cpp
#include "Ticket.h"
#include <random>
#include <iomanip>
#include <Windows.h>
#include <thread>
#include <chrono>

int Ticket::m_TicketIDCounter = 0;

Ticket::Ticket() 
{

}

Ticket::~Ticket() 
{
    // Clean up if needed
}

uint64_t Ticket::getID() const 
{
    return m_TicketID;
}

Ticket Ticket::createTicket(float price)
{
    Ticket newTicket;
    newTicket.m_Price = price;
    if (price == 0.53)
    {
        newTicket.m_TicketTimer = 1800;
    }
    m_TicketIDCounter++;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<uint64_t> distribution(1, 9999999999999999);

    // Generating a random number
    uint64_t random_number = distribution(generator);

    newTicket.m_TicketID = random_number;

    // Calculate expiration time based on current time and duration
    newTicket.m_TicketExpirationTime = newTicket.m_TicketTimer;

    return newTicket;
}

void Ticket::buyTicket(float price)
{
    Ticket Ticket = createTicket(price);
}

double Ticket::getPrice() const
{
    return m_Price;
}

time_t Ticket::getTicketExpirationTime(const Ticket& Ticket) const
{
    return Ticket.m_TicketExpirationTime;
}

bool Ticket::isTicketValid(const Ticket& Ticket) const
{
    return time(nullptr) < Ticket.m_TicketExpirationTime;
}

void Ticket::useTicket()
{
    // Perform actions when the ticket is used (optional)
}

void Ticket::generateBarcode()
{
    // Generate barcode logic (you may need an external library for this)
    // For simplicity, let's just print the barcode for now
    std::cout << "Barcode for Ticket ID " << m_TicketID << ": **********" << std::endl;
}

void Ticket::updateTicketExpiration(Ticket& Ticket)
{

    while(Ticket.m_TicketExpirationTime > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --Ticket.m_TicketExpirationTime;
        std::cout << Ticket::getTicketExpirationTime(Ticket) << std::endl;
    }
}

 void Ticket::checkForTickets()
 {

 }

