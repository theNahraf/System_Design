#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class DocumentEditor{
private:
    vector<string> documentElements;
    string renderedDocuments;

public:
    void addText(string text){
        documentElements.push_back(text);
    }

    void addImage(string imagePath){
        documentElements.push_back(imagePath);
    }

    //busness logic to render the document
    string RenderDocument(){
        if(renderedDocuments.empty()){
            string result;
            for(auto element: documentElements){
                if(element.size() > 4 && (element.substr(element.size() - 4) ==".jpg"  ||
                element.substr(element.size() - 4) == ".png")){
                    result += "[Image : " + element + "]" + "\n";
                }
                else{
                    result += element + "\n";
                }
                renderedDocuments = result;
            }
        }
        
            return renderedDocuments;
        
    }

    void savetoFile(){
    ofstream file("document.txt");
    if(file.is_open()){
        file << RenderDocument();
        file.close();
        cout<<"Document saved to document.txt" << endl;
    }
    else{
        cout<< "Error opening file for saving." << endl;
    }
    }

};

int main() {

    DocumentEditor editor;
    editor.addText("Hello world");
    editor.addImage("image1.jpg");
    editor.addText("This is a sample document.");

    cout<< editor.RenderDocument() << endl;
    editor.savetoFile();
    
    return 0;
}