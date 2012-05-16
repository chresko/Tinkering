#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> gContactList;

class ContactTreeNode {
public:
    ContactTreeNode()
    :mContactIndex(-1)
    {
        for (int i = 0; i < 10; ++i) {
            mChildren[i] = NULL;
        }
    }
    
    ContactTreeNode(const std::string& number, const std::string& name)
    :mContactIndex(-1)
    {
        for (int i = 0; i < 10; ++i) {
            mChildren[i] = NULL;
        }
        
        if (!number.empty()) {
            const char c = number[0];
            unsigned int index = atoi(&c);
            std::string substring = number.substr(1, number.length()-1);
            mChildren[index] = new ContactTreeNode(substring, name);
        } else {
            gContactList.push_back(name);
            mContactIndex = gContactList.size()-1;
        }
    }
    
    ~ContactTreeNode()
    {
    }
    
    void insert(const std::string& number, const std::string& name)
    {
        if (!number.empty()) {
            const char c = number[0];
            unsigned int index = atoi(&c);
            std::string substring = number.substr(1, number.length()-1);
            if (mChildren[index]) {
                mChildren[index]->insert(substring, name);
            } else {
                mChildren[index] = new ContactTreeNode(substring, name);
            }
        }
    }
    
    std::string find(const std::string& number)
    {
        std::string name;
        if (!number.empty()){ 
            const char c = number[0];
            unsigned int index = atoi(&c);
            std::string substring = number.substr(1, number.length()-1);
            if (mChildren[index]) {
                name = mChildren[index]->find(substring);
            }
        } else {
            if (mContactIndex != -1) {
                name = gContactList[mContactIndex];
            }
        }
        
        return name;
    }
    
private:
    ContactTreeNode* mChildren[10];
    int mContactIndex;
};

class ContactTree {
public:
    ContactTree()
    :mRoot(NULL)
    {
    }
    
    ~ContactTree()
    {
    }
    
    void insert(const std::string& number, const std::string& name)
    {
        if (!mRoot) {
            mRoot = new ContactTreeNode(number, name);
        } else {
            mRoot->insert(number, name);
        }
    }
    
    std::string find(const std::string& number)
    {
        std::string name;
        if (mRoot) {
            name = mRoot->find(number);
        }
        
        return name;
    }
    
private:
    ContactTreeNode* mRoot;
};

int main()
{
    // assume phone number is given to you in reverse order
    
    ContactTree ct;
    // 4152386210
    ct.insert("0126832514", "Christian Hresko");
    std::string name = ct.find("0126832514");
    std::cout << name << std::endl;
    // 5152386210
    ct.insert("0126832515", "Anonymous Person");
    name = ct.find("0126832515");
    std::cout << name << std::endl;
    
    return 0;
}