//
//  PSNetworkOperation.h
//  SevenMinuteLibrary
//
//  Created by Peter Shih on 1/27/11.
//  Copyright 2011 Seven Minute Labs. All rights reserved.
//
//  Things to test:
//  Test GZIP compression/decompression
//  Test all error codes
//  Test cookies
//  Test all delegate callbacks

#import <Foundation/Foundation.h>
#import "PSNetworkOperationDelegate.h"

typedef enum {
  NetworkOperationStateIdle = -1,
  NetworkOperationStateStart = 0,
  NetworkOperationStateFinished = 1,
  NetworkOperationStateFailed = 2,
  NetworkOperationStateTimeout = 3,
  NetworkOperationStateCancelled = 4
} NetworkOperationState;

typedef enum {
  NetworkOperationAttachmentTypeNone = -1,
  NetworkOperationAttachmentTypePNG = 0,
  NetworkOperationAttachmentTypeJPEG = 1,
  NetworkOperationAttachmentTypeMP4 = 2
} NetworkOperationAttachmentType;

@interface PSNetworkOperation : NSOperation {
  // Connection
  NSURLConnection *_connection;
  BOOL _isExecuting;
  BOOL _isFinished;
  BOOL _isCancelled;
  BOOL _isConcurrent;
  
  // Request
  NSMutableURLRequest *_request;
  NSURL *_requestURL;
  NSString *_requestMethod;
  NSString *_requestContentType;
  unsigned long long _requestContentLength;
  NSString *_requestAccept;
  NSMutableDictionary *_requestHeaders;
  NSMutableDictionary *_requestParams; // A dictionary of parameters
  NSMutableData *_requestData;
  NSMutableString *_encodedParameterPairs;
  
  // Response
  NSDictionary *_responseHeaders;
  NSMutableData *_responseData;
  NSURLResponse *_urlResponse;
  NSError *_responseError;
  NSArray *_responseCookies;
  NSString *_responseStatusMessage;
  NSInteger _responseStatusCode;
  unsigned long long _responseContentLength;
  NSStringEncoding _responseEncoding;
  
  // Config
  NSStringEncoding _defaultResponseEncoding;
  NSTimeInterval _timeoutInterval;
  NSInteger _numberOfTimesToRetryOnTimeout;
  NSURLRequestCachePolicy _cachePolicy; // defaults to ignore local
  BOOL _shouldCompressRequestBody;
  BOOL _allowCompressedResponse;
  BOOL _shouldTimeout; // defaults to YES
  BOOL _hasAttachment; // defaults to NO
  CGFloat _jpegCompression;
  NetworkOperationAttachmentType _attachmentType;
  
  // Request State
  NetworkOperationState _operationState;
  
  // Delegate
  id <PSNetworkOperationDelegate> _delegate;
  
  // Stuff to reuse from NSOperation
  // queuePriority
  // addDependency:(NSOperation *)operation
}

// Connection
@property (retain) NSURLConnection *connection;
@property (readonly) BOOL isExecuting;
@property (readonly) BOOL isFinished;
@property (readonly) BOOL isCancelled;
@property (readonly) BOOL isConcurrent;

// Request
@property (nonatomic, retain) NSMutableURLRequest *request;
@property (nonatomic, copy) NSURL *requestURL;
@property (nonatomic, retain) NSString *requestMethod;
@property (nonatomic, retain) NSString *requestContentType;
@property (nonatomic, assign) unsigned long long requestContentLength;
@property (nonatomic, retain) NSString *requestAccept;
@property (nonatomic, retain) NSMutableDictionary *requestHeaders;
@property (nonatomic, retain) NSMutableDictionary *requestParams;
@property (nonatomic, retain) NSMutableData *requestData;
@property (nonatomic, retain) NSMutableString *encodedParameterPairs;

// Response
@property (retain) NSDictionary *responseHeaders;
@property (retain) NSMutableData *responseData;
@property (retain) NSURLResponse *urlResponse;
@property (retain) NSError *responseError;
@property (retain) NSArray *responseCookies;
@property (retain) NSString *responseStatusMessage;
@property (assign) NSInteger responseStatusCode;
@property (assign) unsigned long long responseContentLength;
@property (assign) NSStringEncoding responseEncoding;

// Config
@property (nonatomic, assign) NSStringEncoding defaultResponseEncoding;
@property (nonatomic, assign) NSTimeInterval timeoutInterval;
@property (nonatomic, assign) NSInteger numberOfTimesToRetryOnTimeout;
@property (nonatomic, assign) NSURLRequestCachePolicy cachePolicy;
@property (nonatomic, assign) BOOL shouldCompressRequestBody;
@property (nonatomic, assign) BOOL allowCompressedResponse;
@property (nonatomic, assign) BOOL shouldTimeout;
@property (nonatomic, assign) BOOL hasAttachment;
@property (nonatomic, assign) CGFloat jpegCompression;
@property (nonatomic, assign) NetworkOperationAttachmentType attachmentType;

// Delegate
@property (assign) id delegate;

#pragma mark Init
- (id)initWithURL:(NSURL *)URL;

#pragma mark get information about this request
// Returns the contents of the result as an NSString (not appropriate for binary data - used responseData instead)
- (NSString *)responseString;

#pragma mark Configuring Request
- (void)addRequestHeader:(NSString *)header value:(NSString *)value;
- (void)addRequestParam:(NSString *)param value:(id)value;

#pragma mark Cleanup
- (void)clearDelegatesAndCancel;

+ (NSUInteger)activeOperationCount;

@end
