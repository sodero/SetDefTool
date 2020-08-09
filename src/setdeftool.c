//------------------------------------------------------------------------------
// setdeftool.c:
//
// Set project default tool
//------------------------------------------------------------------------------
// Copyright (C) 2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <proto/dos.h>
#include <proto/icon.h>

#include "version.h"

static char version[]
#ifdef __GNUC__
    __attribute__((used))
#endif
    = VER_STR;

//------------------------------------------------------------------------------
// Name:        set_default_tool
// Description: Set default tool of project.
// Input:       char *proj: project
//              char *tool: default tool
// Return:      EXIT_SUCCESS or EXIT_FAILURE
//------------------------------------------------------------------------------
static int set_default_tool(char *proj, char *tool)
{
    struct DiskObject *obj = (struct DiskObject *) GetDiskObject(proj);

    if(!obj)
    {
        // Could not read.
        PrintFault(IoErr(), proj);
        return EXIT_FAILURE;
    }

    // Preserve current object.
    char *old = obj->do_DefaultTool;
    obj->do_DefaultTool = (char *) tool;

    // Save new default tool.
    int ret = PutDiskObject(proj, obj) ? EXIT_SUCCESS : EXIT_FAILURE;

    if(!obj)
    {
        // Could not write.
        PrintFault(IoErr(), proj);
    }

    // Restore before free.
    obj->do_DefaultTool = old;
    FreeDiskObject(obj);

    return ret;
}

//------------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
    // Not used.
    (void) argc;
    (void) argv;

    // Parameter template and argv output.
    static char *args[2], *tmpl = "PROJECT/A,TOOL/A";

    // Parse input parameters.
    struct RDArgs *rda = ReadArgs(tmpl, (IPTR *) args, NULL);

    if(!rda)
    {
        // Invalid parameters.
        fprintf(stderr, "%s\n", tmpl);
        return EXIT_FAILURE;
    };

    int ret = set_default_tool(args[0], args[1]);
    FreeArgs(rda);

    // Success or failure.
    return ret;
}
