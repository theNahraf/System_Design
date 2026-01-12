#include <bits/stdc++.h>
using namespace std;

class DocumentElement{
    public:
        virtual string render() = 0;
};

class TextElement : public DocumentElement{
private:
    string text;
public:
    TextElement(string text){
        this->text=  text;
    }
    string render() override {
        cout<<"rendring text -> " << text<<endl;
        return text;
    }
    
}; 

class ImgElement : public DocumentElement{
private:
    string path;
public:
    ImgElement(string path){
        this->path =  path;
    }
   string render() override {
        return "[Image: " +  path + "]";
    }
};

class Document{
private:
    vector<DocumentElement*> element;
public:
   void addelement(DocumentElement* el){
    element.push_back(el);
   }

   string render(){
    string result;
    for(DocumentElement* el : element){
         result += el->render();
    }
    return result;
   }
   
}; 


class Persistence{
public:
    virtual void save(string data) = 0; // Pure virtual function
};

// file  storage implementation of persistance
class FilesStorage : public Persistence {
public:
    void save(string data) override{
        ofstream file("document.txt");
        if (file.is_open()) {
            file << data;
            file.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
};


//placeholder for dbstroage implementaiton 
class DBstorage : public Persistence{
public:
    void save(string data) override{
        // Placeholder for database storage implementation
        cout << "Saving to database: " << data << endl;
    }
};

class DocumentEditor{
private:    
    Document* document;
    Persistence* db;
    string renderedDocument;
     
public:
    DocumentEditor(Document* document,Persistence* db){
        this->document = document;
        this->db =  db;
    }
    void addText(string text){
        document->addelement(new TextElement(text));
    };
    void addimage(string path){
        document->addelement(new ImgElement(path));
    }

    string renderdoc(){
        if(renderedDocument.empty()){
            renderedDocument = document->render();
        }
        return renderedDocument;
    }
    void savedocument(){
        string data = renderdoc();
        db->save(data);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Document* document = new Document();
    Persistence* storage = new FilesStorage();
    DocumentEditor* editor = new DocumentEditor(document, storage);


    editor->addText("hello dost");
    editor->addText("my name is farhan");

    editor->addimage("picture.jpg");

    //render the document
    cout<<endl;

    cout<<"******************"<<endl;
    cout<<"renderring"<<endl;

    cout<<editor->renderdoc()<<endl;

    cout<<"*********************"<<endl;
    cout<<"save the document"<<endl;

    //save the document
    editor->savedocument();


    return 0;
}