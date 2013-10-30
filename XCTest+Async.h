//
//  XCTest+Async.h
//
//  Created by Saül Baró on 10/29/13.
//  Copyright (c) 2013 Wide Eyes Solutions SL. All rights reserved.
//

#import <XCTest/XCTest.h>

#define ASYNC_TEST_START    __block BOOL hasCalledBack = NO;
#define ASYNC_TEST_DONE     hasCalledBack = YES;
#define ASYNC_TEST_END      NSDate *loopUntil = [NSDate dateWithTimeIntervalSinceNow:10]; \
                            while (hasCalledBack == NO && [loopUntil timeIntervalSinceNow] > 0) { \
                                [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:loopUntil]; \
                            } \
                            if (!hasCalledBack) { XCTFail(@"Timeout"); }

#define ASYNC_TEST_END_LONG_TIMEOUT \
                            NSDate *loopUntil = [NSDate dateWithTimeIntervalSinceNow:120]; \
                            while (hasCalledBack == NO && [loopUntil timeIntervalSinceNow] > 0) { \
                                [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:loopUntil]; \
                            } \
                            if (!hasCalledBack) { XCTFail(@"Timeout"); }

@interface XCTest (Async)

@end
