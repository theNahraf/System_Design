#include <iostream>
#include <vector>
#include<fstream>
using namespace std;
class DocumentElement {
    public:
    virtual string render() = 0; // Pure virtual function
};
class TextElement : public DocumentElement{
private:
    string text;
public: 
    TextElement(string text){
        this->text = text;
    }
    string render() override{
        return text;
    }
};
class ImageElement : public DocumentElement {
private:
    string imagePath;
public:
    ImageElement(string imagePath) {
        this->imagePath = imagePath;
    }
    string render() override {
        return "[Image: " +  imagePath + "]";
    }
};
//newlinelement represetn a line break in the document

class NewLineElement : public DocumentElement {
public:
    string render() override{
        return "\n";
    }
};

//tabspace element represents a tab space in the document

class TabSpaceElement : public DocumentElement {
public:
    string render() override {
        return "\t";
    }
};

class Document {
private:
    vector<DocumentElement*> elements;
public:
    void addElement(DocumentElement* el){
        elements.push_back(el);
    }
    string render(){
        string result;
        for(auto el : elements){
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
    Document * document;
    Persistence * storage;
    string renderedDocument;
public:
    DocumentEditor(Document * doc, Persistence * storage){
        this->document = doc;
        this->storage = storage;
    }
    
    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    void addTabSpace() {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument(){
        string data = renderDocument();
        storage->save(data);
    }
};


//client usage example
int main() {    
    Document* document = new Document();
    Persistence* storage = new FilesStorage(); // or DBstorage for database storage

    DocumentEditor * editor = new DocumentEditor(document, storage);

    //simulate a client useing the editor with common text fomratting 
    editor->addText("Hello, World!");
    editor->addNewLine();
    editor->addText("This is a simple document editor.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("indented text after a tab space. ");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    //render the document
    cout<<endl;
    cout<<"*****************"<<endl;
    cout << "Rendered Document:" << endl;

   cout<< editor->renderDocument()<<endl;

    cout<<"*****************"<<endl;
    cout<<"save the document"<<endl;
    //save the document
    editor->saveDocument();

    return 0;
}