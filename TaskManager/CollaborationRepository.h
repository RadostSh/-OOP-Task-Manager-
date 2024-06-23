#pragma once
#include "Collaboration.h"

class CollaborationsRepository {
public:
    CollaborationsRepository() = default;
    static CollaborationsRepository* getInstance();
    static void freeInstance();

    void addCollaboration(const Collaboration& collaboration);
    void deleteCollaboration(const MyString& name, const MyString& creator);
    Collaboration* findCollaboration(const MyString& name);

    void removeTaskFromCollaboration(const MyString& collaborationName, unsigned taskId);

    const MyVector<Collaboration>& getCollaborations() const;

private:
    MyVector<Collaboration> _collaborations;
    static CollaborationsRepository* instance;
};