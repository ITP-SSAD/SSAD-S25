

#include <iostream>
#include <vector>
#include <string>

class Component {
public:
    virtual void display() = 0;
    virtual std::string getName() = 0;
};

class File : public Component {
private:
    std::string name;
public:
    File(std::string name) : name(name) {}

    void display() override {
        std::cout << "File: " << name << std::endl;
    }

    std::string getName() override {
        return name;
    }
};

class Directory : public Component {
private:
    std::string name;
    std::vector<Component*> components;
public:
    Directory(std::string name) : name(name) {}

    void addComponent(Component* component) {
        components.push_back(component);
    }

    void display() override {
        std::cout << "Directory: " << name << std::endl;
        for (Component* component : components) {
            component->display();
        }
    }
    std::string getName() override {
        return name;
    }
};

int main() {
    Directory root("Root");
    File* file1 = new File("File1.txt");
    File* file2 = new File("File2.txt");
    Directory* dir1 = new Directory("Dir1");
    File* file3 = new File("File3.txt");
    File* file4 = new File("File4.txt");
    Directory* dir2 = new Directory("Dir2");

    root.addComponent(file1);
    root.addComponent(file2);
    root.addComponent(dir1);
    dir1->addComponent(file3);
    dir1->addComponent(file4);
    dir1->addComponent(dir2);

    root.display();

    delete file1;
    delete file2;
    delete dir1;
    delete file3;
    delete file4;
    delete dir2;

    return 0;
}

