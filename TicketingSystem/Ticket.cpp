// Ticket.cpp
#include "Ticket.h"
#include <random>
#include <iomanip>
#include <Windows.h>
#include <thread>
#include <chrono>

int Ticket::ticketIDCounter = 0;

Ticket::Ticket(double price, int durationMinutes) : price(price), TicketTimer(durationMinutes) 
{
    ticketIDCounter++;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<uint64_t> distribution(1, 9999999999999999);

    // Generating a random number
    uint64_t random_number = distribution(generator);

    ticketID = random_number;

    // Calculate expiration time based on current time and duration
    TicketExpirationTime = (TicketTimer * 60);
}

Ticket::~Ticket() 
{
    // Clean up if needed
}

uint64_t Ticket::getID() const 
{
    return ticketID;
}

double Ticket::getPrice() const
{
    return price;
}

time_t Ticket::getTicketExpirationTime() const
{
    return TicketExpirationTime;
}

bool Ticket::isValid() const
{
    return time(nullptr) < TicketExpirationTime;
}

void Ticket::useTicket()
{
    // Perform actions when the ticket is used (optional)
}

void Ticket::generateBarcode()
{
    // Generate barcode logic (you may need an external library for this)
    // For simplicity, let's just print the barcode for now
    std::cout << "Barcode for Ticket ID " << ticketID << ": **********" << std::endl;
}

void Ticket::updateExpiration()
{
    for (int i = 0; i < TicketExpirationTime+1; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --TicketExpirationTime;
        std::cout << Ticket::getTicketExpirationTime() << std::endl;
    }
}

