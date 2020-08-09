//------------------------------------------------------------------------------
// version.h:
//
// SetDefTool version information
//------------------------------------------------------------------------------
// Copyright (C) 2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef VERSION_H_
#define VERSION_H_

#define MAJ 1
#define MIN 0
#define REV 0
#define STY(X) #X
#define VER(X) STY(X)

#define VER_STR "\0$VER: " __EXE__ " " VER(MAJ) "." VER(MIN) "." \
        VER(REV) " " __AMIGADATE__ ""

#endif
