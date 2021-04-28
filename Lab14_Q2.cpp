/*
    ID          : 63011119
    Name        : Chakrin Deesit
    Lab No      : 14
    Question No : 2
    Date        : 29/04/2021
*/

#include <iostream>
using namespace std;

class ScheduleServer
{
public:
    void startBooting() { cout << "Starts booting..." << endl; }
    void readSystemConfigFile() { cout << "Reading system config files..." << endl; }
    void init() { cout << "Initializing..." << endl; }
    void initializeContext() { cout << "Initializing context..." << endl; }
    void initializeListeners() { cout << "Initializing listeners..." << endl; }
    void createSystemObjects() { cout << "Creating system objects..." << endl; }
    void releaseProcesses() { cout << "Releasing processes..." << endl; }
    void destory() { cout << "Destorying..." << endl; }
    void destroySystemObjects() { cout << "Destroying system objects..." << endl; }
    void destoryListeners() { cout << "Destroying listeners..." << endl; }
    void destoryContext() { cout << "Destroying context..." << endl; }
    void shutdown() { cout << "Shutting down..." << endl; }
};

class MyFacade
{
private:
    static MyFacade* obj;
    MyFacade() {}
public:
    static MyFacade* getMyFacade()
    {
        if (obj == nullptr) { obj = new MyFacade(); }
        return obj;
    }
    void startServer()
    {
        ScheduleServer scheduleServer;
        scheduleServer.startBooting();
        scheduleServer.readSystemConfigFile();
        scheduleServer.init();
        scheduleServer.initializeContext();
        scheduleServer.initializeListeners();
        scheduleServer.createSystemObjects();
        cout << "Start working......" << endl;
    }
    void stopServer()
    {
        ScheduleServer scheduleServer;
        cout << "After work done........." << endl;
        scheduleServer.releaseProcesses();
        scheduleServer.destory();
        scheduleServer.destroySystemObjects();
        scheduleServer.destoryListeners();
        scheduleServer.destoryContext();
        scheduleServer.shutdown();
    }
};
MyFacade* MyFacade::obj = nullptr;

int main()
{
    MyFacade* scheduleServer = MyFacade::getMyFacade();
    scheduleServer->startServer();
    scheduleServer->stopServer();
    return 0;
}