#pragma once
#include <string>
#include <functional>


using namespace std;

struct asset
{
    asset(string keyName,const char* fileDirectory) :m_keyName(keyName),m_fileDirectory(fileDirectory)
    {

    }
    virtual string getKeyName()
    {
        return m_keyName;
    }
    virtual const char* getFileDirectory()
    {
        return m_fileDirectory;
    }
    protected:
    string m_keyName;
    const char* m_fileDirectory;
};
