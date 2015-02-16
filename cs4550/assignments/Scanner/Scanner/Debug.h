//
//  Debug.h
//  Scanner
//
//  Created by Nate Armstrong on 2/9/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#ifndef Scanner_Debug_h
#define Scanner_Debug_h

#define ShowMessages 0 // 0 or 1

#include <iostream>

#if ShowMessages
#define MSG(X) cout << X << endl;
#else
#define MSG(X) ;
#endif

#endif
