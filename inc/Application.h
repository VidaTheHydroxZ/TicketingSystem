class Application
{
public:
    Application();
    ~Application();
    inline bool isRunning() {return isRunning;}
    void checkForTickets();
private:
    bool isRunning = false;
};