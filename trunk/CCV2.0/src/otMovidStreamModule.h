#ifndef _OTSTEAMMODULE_H
#define _OTSTEAMMODULE_H

#include <cv.h>
#include "moDaemon.h"
#include "moPipeline.h"
#include "moFactory.h"
#include "moDataStream.h"

class otStreamModule : public moModule
{
public:
    otStreamModule();
    void stop();
    void notifyData(moDataStream *source);
    bool copy();
    virtual void update() {}
    virtual std::string getName() { return "Stream"; }
    virtual std::string getDescription() { return ""; }
    virtual std::string getAuthor() { return ""; }

    moDataStream *input;
    IplImage* output_buffer;
    
    static moModule *createModule();
};

#endif // _OTSTEAMMODULE_H
