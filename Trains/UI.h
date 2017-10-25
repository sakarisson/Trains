#ifndef UI_H
#define UI_H

#include <memory>
#include <vector>
#include <string>
#include <iostream>

enum MenuType {
    MAIN,
    SIMULATION,
    TRAIN,
    STATION,
    VEHICLE
};

using std::cout;
using std::endl;

class Simulation;

class MenuItem {
public:
    MenuItem(Simulation* sim) : _sim(sim) {}
    virtual ~MenuItem() {}
    
    std::string getHeader() const;
    void setItemNumber(int);
    virtual std::string getTitle() const = 0;
    int getItemNumber() const;
    virtual void run() = 0;
protected:
    Simulation* _sim;
    int _itemNumber;
    int _menuWidth = 50;
};

// ----------------------------------------------------------
// --------------- START MENU ITEMS -------------------------
// ----------------------------------------------------------

class ChangeStartTime : public MenuItem {
public:
    ChangeStartTime(Simulation* sim) : MenuItem(sim) {}
    virtual ~ChangeStartTime() {}

    std::string getTitle() const override { return "Change start time[00:00]"; }
    void run() override;
};

class ChangeEndTime : public MenuItem {
public:
    ChangeEndTime(Simulation* sim) : MenuItem(sim) {}
    virtual ~ChangeEndTime() {}

    std::string getTitle() const override { return "Change end time[23:59]"; }
    void run() override;
};

class StartSimulation : public MenuItem {
public:
    StartSimulation(Simulation* sim) : MenuItem(sim) {}
    virtual ~StartSimulation() {}

    std::string getTitle() const override { return "Start simulation"; }
    void run() override;
};

class Exit : public MenuItem {
public:
    Exit(Simulation* sim) : MenuItem(sim) {}
    virtual ~Exit() {}

    std::string getTitle() const override { return "Exit"; }
    void run() override;
};

// ----------------------------------------------------------
// ------------- SIMULATION MENU ITEMS ----------------------
// ----------------------------------------------------------

class ChangeInterval : public MenuItem {
public:
    ChangeInterval(Simulation* sim) : MenuItem(sim) {}
    virtual ~ChangeInterval() {}

    std::string getTitle() const override;
    void run() override;
};

class RunNextInterval : public MenuItem {
public:
    RunNextInterval(Simulation* sim) : MenuItem(sim) {}
    virtual ~RunNextInterval() {}

    std::string getTitle() const override { return "Run next interval"; }
    void run() override;
};

class NextEvent : public MenuItem {
public:
    NextEvent(Simulation* sim) : MenuItem(sim) {}
    virtual ~NextEvent() {}

    std::string getTitle() const override { return "Next event"; }
    void run() override;
};

class Finish : public MenuItem {
public:
    Finish(Simulation* sim) : MenuItem(sim) {}
    virtual ~Finish() {}

    std::string getTitle() const override { return "Finish (complete simulation)"; }
    void run() override;
};

class ChangeLogLevel : public MenuItem {
public:
    ChangeLogLevel(Simulation* sim) : MenuItem(sim) {}
    virtual ~ChangeLogLevel() {}

    std::string getTitle() const override { return "Change log level"; }
    void run() override;
};

class TrainMenu : public MenuItem {
public:
    TrainMenu(Simulation* sim) : MenuItem(sim) {}
    virtual ~TrainMenu() {}

    std::string getTitle() const override { return "Train menu"; }
    void run() override;
};

class StationMenu : public MenuItem {
public:
    StationMenu(Simulation* sim) : MenuItem(sim) {}
    virtual ~StationMenu() {}

    std::string getTitle() const override { return "Station menu"; }
    void run() override;
};

class VehicleMenu : public MenuItem {
public:
    VehicleMenu(Simulation* sim) : MenuItem(sim) {}
    virtual ~VehicleMenu() {}

    std::string getTitle() const override { return "Vehicle menu"; }
    void run() override;
};

class Return : public MenuItem {
public:
    Return(Simulation* sim) : MenuItem(sim) {}
    virtual ~Return() {}

    std::string getTitle() const override { return "Return"; }
    void run() override;
};

class PrintStatistics : public MenuItem {
public:
    PrintStatistics(Simulation* sim) : MenuItem(sim) {}
    virtual ~PrintStatistics() {}

    std::string getTitle() const override { return "Print statistics"; }
    void run() override;
};

// ----------------------------------------------------------
// ---------------- TRAIN MENU ITEMS ------------------------
// ----------------------------------------------------------

class SearchTrainByNumber : public MenuItem {
public:
    SearchTrainByNumber(Simulation* sim) : MenuItem(sim) {}
    virtual ~SearchTrainByNumber() {}

    std::string getTitle() const override { return "Search train by number"; }
    void run() override;
};

class SearchTrainByVehicleId : public MenuItem {
public:
    SearchTrainByVehicleId(Simulation* sim) : MenuItem(sim) {}
    virtual ~SearchTrainByVehicleId() {}

    std::string getTitle() const override { return "Search train by vehicle ID"; }
    void run() override;
};

class ShowAllTrains : public MenuItem {
public:
    ShowAllTrains(Simulation* sim) : MenuItem(sim) {}
    virtual ~ShowAllTrains() {}

    std::string getTitle() const override { return "Show all trains"; }
    void run() override;
};

// ----------------------------------------------------------
// ---------------- STATION MENU ITEMS ----------------------
// ----------------------------------------------------------

class ShowStationNames : public MenuItem {
public:
    ShowStationNames(Simulation* sim) : MenuItem(sim) {}
    virtual ~ShowStationNames() {}

    std::string getTitle() const override { return "Show station names"; }
    void run() override;
};

class ShowStationByName : public MenuItem {
public:
    ShowStationByName(Simulation* sim) : MenuItem(sim) {}
    virtual ~ShowStationByName() {}

    std::string getTitle() const override { return "Show station by name"; }
    void run() override;
};

class ShowAllStations : public MenuItem {
public:
    ShowAllStations(Simulation* sim) : MenuItem(sim) {}
    virtual ~ShowAllStations() {}

    std::string getTitle() const override { return "Show all stations"; }
    void run() override;
};

// ----------------------------------------------------------
// ---------------- VEHICLE MENU ITEMS ----------------------
// ----------------------------------------------------------

class ShowVehicleById : public MenuItem {
public:
    ShowVehicleById(Simulation* sim) : MenuItem(sim) {}
    virtual ~ShowVehicleById() {}

    std::string getTitle() const override { return "Show vehicle by ID"; }
    void run() override;
};

class ShowAllVehicles : public MenuItem {
public:
    ShowAllVehicles(Simulation* sim) : MenuItem(sim) {}
    virtual ~ShowAllVehicles() {}

    std::string getTitle() const override { return "Show all vehicles"; }
    void run() override;
};

// ----------------------------------------------------------
// ------------------------ MENU ----------------------------
// ----------------------------------------------------------

class Menu {
public:
    Menu() {}
    void addItem(std::unique_ptr<MenuItem>);
    void printItems();
    void userInteract();
private:
    int getChoice() const;
    bool processChoice(int);
    std::vector<std::unique_ptr<MenuItem>> _menuItems;
};

class UI {
public:
    UI() {}
    ~UI() {}

    void setMenu(std::unique_ptr<Menu>&, MenuType);
    void accessMenu(MenuType);
private:
    std::unique_ptr<Menu> _mainMenu;
    std::unique_ptr<Menu> _simulationMenu;
    std::unique_ptr<Menu> _trainMenu;
    std::unique_ptr<Menu> _stationMenu;
    std::unique_ptr<Menu> _vehicleMenu;
};

#endif // !UI_H
