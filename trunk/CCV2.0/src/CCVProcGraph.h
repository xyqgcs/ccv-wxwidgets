/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVProcGraph.h
// Purpose:     Deccripting a processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _PROCESS_GRAPH_H
#define _PROCESS_GRAPH_H

#include <map>
#include "moFactory.h"
#include "moPipeline.h"
#include "CCVCommon.h"

/**
    Dict for finding a module's type with its ID.
*/    
typedef std::map<std::string, std::string> ModuleTypeDict;

class CCVProcGraph : public moPipeline
{
private:
    ModuleTypeDict moduleTypeOf;
    moFactory *factory;
    Strings outputModuleIDs;
    
    /**
        Once locked, using the pipeline will be not allowed.
    */
    bool locked;
    
public:
    CCVProcGraph();
    
    /**
        Add a module. If the module is used to draw on UI, set isOutModule to true. 
    */
    int AddModule(std::string moduleID, std::string moduleType, bool isOutModule=false);
    
    /**
        Connect two modules. The first module inputs, the second outputs. 
    */
    int ConnectModules(std::string firstModuleID, std::string secondModuleID);
        
    /**
        Disconnect two modules. The first module inputs, the second outputs. 
    */
    int DisconnectModules(std::string firstModuleID, std::string secondModuleID);
        
    /**
        Remove a module. The connects will be removed as well. 
    */
    int RemoveModule(std::string moduleID);
        
    /**
        Clear graph, dicts and the pipeline..
    */
    void ClearGraph();
    
    /**
        Get a list that includes all modules that were output stream modules.
    */
    Strings GetOutputModuleIDs();
    
    /**
        Check whether the pipeline was locked.
    */
    bool hasLocked();
    
    /**
        Lock the pipeline.
    */
    int Lock();
     
    /**
        Unlock the pipeline.
    */
    void Unlock();
};

#endif
