//
//  main.c
//  bma-week-10
//
//  Created by Wally on 11/20/12.
//  Copyright (c) 2012 W M. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int main(int argc, const char * argv[])
{

    long currentTime = time(NULL);
    struct tm cTime;
    
    cTime = *localtime(&currentTime);
    struct tm fTime;
    
    printf("                   Current Date: %d-%d-%d\n\n"
           , (cTime.tm_mon + 1), cTime.tm_mday
           , (cTime.tm_year + 1900));
    
    currentTime += 4000000;
    fTime = *localtime(&currentTime);
    
    printf("Future Date (4,000,000 seconds): %d-%d-%d\n"
           , (fTime.tm_mon + 1), fTime.tm_mday
           , (fTime.tm_year + 1900));
    
    return 0;
}

