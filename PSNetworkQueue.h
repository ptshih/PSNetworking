//
//  PSNetworkQueue.h
//  SevenMinuteLibrary
//
//  Created by Peter Shih on 1/27/11.
//  Copyright 2011 Seven Minute Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASIHTTPRequest.h"
#import "ASINetworkQueue.h"
#import "PSConstants.h"

@interface PSNetworkQueue : ASINetworkQueue {
}

// Access shared instance
+ (id)sharedQueue;

@end
