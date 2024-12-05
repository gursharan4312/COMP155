class HeritageSite {
protected:
    string siteID;
    string name;
    string location;
    string categoryID;
    
public:
    HeritageSite(string id, string n, string loc, string catID)
    : siteID(id), name(n), location(loc), categoryID(catID) {}
    
    virtual void viewSiteDetails() {
        cout << "Site ID: " << siteID << "\nName: " << name
            << "\nLocation: " << location << "\nCategory ID: " << categoryID << endl;
    }
    
    virtual void updateProfile(string newName, string newLocation) {
        name = newName;
        location = newLocation;
    }
    
    virtual string getDescription() {
      return "";
    }; 
    
    bool operator==(const HeritageSite &other) {
        return siteID == other.siteID;
    }
    
    string getSiteID() { return siteID; }
    string getCategoryID() { return categoryID; }
};

class CulturalSite : public HeritageSite {
    string culturalSignificance;
    
public:
    CulturalSite(string id, string n, string loc, string catID, string significance)
    : HeritageSite(id, n, loc, catID), culturalSignificance(significance) {}
    
    void viewSiteDetails() override {
        HeritageSite::viewSiteDetails();
        cout << "Cultural Significance: " << culturalSignificance << endl;
    }
    
    string getDescription() override {
        return "Cultural Site: " + name + ", Significance: " + culturalSignificance;
    }
};

class NaturalSite : public HeritageSite {
    string ecosystemType;
    
public:
    NaturalSite(string id, string n, string loc, string catID, string ecosystem)
    : HeritageSite(id, n, loc, catID), ecosystemType(ecosystem) {}
    
    void viewSiteDetails() override {
        HeritageSite::viewSiteDetails();
        cout << "Ecosystem Type: " << ecosystemType << endl;
    }
    
    string getDescription() override {
        return "Natural Site: " + name + ", Ecosystem: " + ecosystemType;
    }
};

