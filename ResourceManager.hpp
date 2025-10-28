#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource;

public:
    ResourceManager() 
    { 
        resource = new Resource(); 
    }

    ResourceManager(const ResourceManager& other)
    { 
        resource = new Resource(*other.resource);
    }

    ~ResourceManager() 
    { 
        delete resource; 
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        delete resource;
        resource = new Resource(*other.resource);
        return *this;
    }

    double get() 
    { 
        return resource->get(); 
    }
};
