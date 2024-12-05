class Category {
    string categoryID;
    string categoryName;
    vector<HeritageSite *> siteList;
    
public:
    Category(string id, string name) : categoryID(id), categoryName(name) {}
    
    void addSite(HeritageSite *site) {
        siteList.push_back(site);
    }
    
    void viewCategoryDetails() {
        cout << "Category ID: " << categoryID << "\nCategory Name: " << categoryName << "\nSites: " ;
        for (HeritageSite *site : siteList) {
            cout<<site->getSiteID()<<",";
        }
        cout<<endl;
    }

    string getCategoryID(){
        return categoryID;
    }
};
