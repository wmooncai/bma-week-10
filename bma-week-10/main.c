//
//  main.c
//  bma-week-10
//
//  Created by W. Mooncai on 11/20/12.
//  Copyright (c) 2012 W. Mooncai All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <objc/objc.h>

#include "bma-week-10.h"

// *****************************************************************************

int printDateTime(char *message, long timeValue, BOOL date, BOOL time)
{
    struct tm compositeTime = *localtime(&timeValue);
    
    char printFormat[strlen(message) + sizeof(DATE_TIME_FMT)];
    strlcpy(printFormat, message, sizeof(printFormat));
    
    if (date && !time) {
        printf(strncat(printFormat, DATE_FMT
                       , ( sizeof(printFormat) - strlen(DATE_FMT) - 1 ))
               , (compositeTime.tm_mon + 1)
               , compositeTime.tm_mday
               , (compositeTime.tm_year + 1900));
        
    } else if (!date && time) {
        printf(strncat(printFormat, TIME_FMT
                       , ( sizeof(printFormat) - strlen(TIME_FMT) - 1 ))
               , compositeTime.tm_hour
               , compositeTime.tm_min
               , compositeTime.tm_sec);
        
    } else if (date && time) {
        printf(strncat(printFormat, DATE_TIME_FMT
                       , ( sizeof(printFormat) - strlen(DATE_TIME_FMT) - 1 ))
               
               , (compositeTime.tm_mon + 1)
               , compositeTime.tm_mday
               , (compositeTime.tm_year + 1900)
               , ( (compositeTime.tm_hour > 12)
                  ? (compositeTime.tm_hour - 12) : compositeTime.tm_hour )
               , compositeTime.tm_min
               , compositeTime.tm_sec
               , ( (compositeTime.tm_hour > 12) ? "PM" : "AM") );
        
    } else return FAIL;
    
    printf("\n");
    
    return SUCCESS;
}

// *****************************************************************************

int main(int argc, const char * argv[])
{
    
    long timeValue = time(NULL);
    
    printDateTime("                    Current Date: "
                  , timeValue, YES, NO);
    
    printDateTime("Future Date (+4,000,000 seconds): "
                  , (timeValue + 4000000), YES, NO);
    
    printf("\n------------------\n\n");
    
    printDateTime("                    Current Date/Time: "
                  , timeValue, YES, YES);
    
    printDateTime("Future Date/Time (+4,000,000 seconds): "
                  , (timeValue + 4000000), YES, YES);
    
    printf("\n------------------\n\n");
    
    if (printDateTime("No Date: "
                      , timeValue, NO, NO) == FAIL) {
        printf("ERROR: You must output date and/or time, but not neither.");
    };
    
    return SUCCESS;
}
