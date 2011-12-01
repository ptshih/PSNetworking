/*
 *  PSNetworkOperationDelegate.h
 *  SevenMinuteLibrary
 *
 *  Created by Peter Shih on 1/28/11.
 *  Copyright 2011 Seven Minute Labs. All rights reserved.
 *
 */

@class PSNetworkOperation;

@protocol PSNetworkOperationDelegate <NSObject>

@optional
- (void)networkOperationDidStart:(PSNetworkOperation *)operation;
- (void)networkOperationDidFinish:(PSNetworkOperation *)operation;

- (void)networkOperationDidFail:(PSNetworkOperation *)operation;
- (void)networkOperationDidCancel:(PSNetworkOperation *)operation;
- (void)networkOperationDidTimeout:(PSNetworkOperation *)operation;

- (void)networkOperation:(PSNetworkOperation *)operation didReceiveResponseHeaders:(NSDictionary *)responseHeaders;

@end
