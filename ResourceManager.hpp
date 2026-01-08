#pragma once

#include "Resource.hpp"
#include <utility> 

class ResourceManager
{
private:
    Resource* resource;

public:
    ResourceManager() 
    { 
        resource = new Resource(); 
    }

    ~ResourceManager() 
    { 
        delete resource; 
    }

    ResourceManager(const ResourceManager& other)
    { 
        resource = new Resource(*other.resource);
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) { 
            Resource* temp = new Resource(*other.resource);
            delete resource;
            resource = temp;
        }
        return *this;
    }

   
    ResourceManager(ResourceManager&& other) noexcept 
        : resource(other.resource) 
    {
        other.resource = nullptr; 
    }

   
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            delete resource;          
            resource = other.resource; 
            other.resource = nullptr;
        }
        return *this;
    }

    double get() 
    { 
        return resource->get(); 
    }
};
