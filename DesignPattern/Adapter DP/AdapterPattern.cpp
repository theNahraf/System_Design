#include <iostream>
using namespace std;

// target interface expected by the client 
class IReports{
public:
    virtual string getJsonData(const string & data)=0;
    virtual ~IReports() {}
};

//2 adapter : proficer xml data from a raw input 
class XMLDataProvider{
public:
    string getXmlData(const string& data) {
        size_t sep = data.find(':');
        string name = data.substr(0, sep);
        string id= data.substr(sep + 1);

        // build an xml represetnatoin 
        return "<user"
                "<name>" + name + "</name>"
                "<id>" + id + "</id>"
                "</user>";
    }
};

// 3 adapter : implements Ireporst by converting xml - json
class XmlDataProviderAdapter: public IReports {
private:
    XMLDataProvider*  xmlprovider; 
public:
    XmlDataProviderAdapter(XMLDataProvider* provider){
        this->xmlprovider = provider;
    }

    string getJsonData(const string & data) override{
        //1 get xml data from the provider
        string xml = xmlprovider->getXmlData(data);
        //2 naively convert xml to json
        size_t startName = xml.find("<name>") + 6;
        size_t endName = xml.find("</name>");
        string name = xml.substr(startName, endName-startName);

        size_t startId = xml.find("<id>") + 4;
        size_t endId = xml.find("</id>");
        string id = xml.substr(startId, endId-startId);
    

        //build and return json 
        return "{ \"user\": { \"name\": \"" + name + "\", \"id\": \"" + id + "\" } }";
    }
};


//client code works only wihh ireports interface
class Client{
public:
    void getReport(IReports* report, string rawData){
        cout<<"process json : " << report->getJsonData(rawData) << endl;    
    }
};


int main() {
    //create the adapteee 
    XMLDataProvider* xmlProvider = new XMLDataProvider();

    //2 make our adapter
    IReports* adapter = new XmlDataProviderAdapter(xmlProvider);
    
    //3 give it some raw data
    string rawData = "Urraf : 21";

    //4 create client and get report
    Client* client = new Client();
    client->getReport(adapter, rawData);

    //processed json 

    //clean up
    delete adapter;
    delete xmlProvider;
    delete client;
    
   
    return 0;
}