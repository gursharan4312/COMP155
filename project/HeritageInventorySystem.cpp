class HeritageInventorySystem {
    vector<HeritageSite *> heritageSites;
    vector<Category *> categories;
    vector<PreservationEffort *> efforts;
    
public:
    void addSite(HeritageSite *site) {
        heritageSites.push_back(site);
        for(Category *category:categories){
            if(category->getCategoryID() == site->getCategoryID()){
                category->addSite(site);
            }
        }
    }
    
    void addCategory(Category *category) {
        categories.push_back(category);
    }

    bool hasCategory(string categoryId) {
        for(Category *category:categories){
            if(category->getCategoryID() == categoryId){
                return true;
            }
        }
        return false;
    }

    void viewAllCategories() {
        cout<<"\nAll Categories: \n"<<endl;
        for(Category *category: categories) {
            category->viewCategoryDetails();
            cout << "-------------------------" << endl;
        }
    }
    
    void viewAllSites() {
        cout<<"\nAll Sites: \n"<<endl;
        for(HeritageSite *site : heritageSites) {
            site->viewSiteDetails();
            cout << "-------------------------" << endl;
        }
    }

    void processPreservationEfforts(string siteID, string desc, string date) {
        PreservationEffort *effort = new PreservationEffort(to_string(efforts.size() + 1), siteID, desc, date);
        efforts.push_back(effort);
    }
    
    void viewPreservationHistory(string siteID) {
        cout<<"\nPreservation History for site: "<< siteID <<endl<<endl;
        for (PreservationEffort *effort : efforts) {
            if (effort->getSiteID() == siteID) {
                effort->viewEffortDetails();
                cout << "-------------------------" << endl;
            }
        }
    }
};
