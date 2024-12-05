class PreservationEffort {
private:
    string effortID;
    string siteID;
    string description;
    string date;
    
public:
    PreservationEffort(string eid, string sid, string desc, string d)
    : effortID(eid), siteID(sid), description(desc), date(d) {}
    
    void viewEffortDetails() {
        cout << "Effort ID: " << effortID << "\nSite ID: " << siteID
            << "\nDescription: " << description << "\nDate: " << date << endl;
    }

    string getSiteID() { return siteID; }
};
