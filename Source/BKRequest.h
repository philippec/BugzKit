//
// BKRequest.h
//
// Copyright (c) 2009-2010 Lukhnos D. Liu (http://lukhnos.org)
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//

#import "BKAPIContext.h"


// TODO: Deprecate this
@class BKRequestQueue;

// TODO: Deprecate this
typedef enum {
	BKRequestCanceledState = -2,
	BKRequestFailedState = -1,
	BKRequestUnqueuedState = 0,
	BKRequestCompletedState = 1,
	BKRequestEnqueuedState = 2,
	BKRequestRunningState = 3
} BKRequestState;

@class BKRequest;

@interface BKRequest : NSObject
{
    // TODO: Deprecate this
	BKRequestState state;
	
    // TODO: Deprecate these
    id target;
    SEL actionOnSuccess;
    SEL actionOnFailure;
	
    // TODO: Deprecate these
	void (^blockWhenEnqueued)(BKRequest *);
	void (^blockBeforeRequestStart)(BKRequest *);
	void (^blockOnSuccess)(BKRequest *);
	void (^blockOnFailure)(BKRequest *);
	void (^blockOnCancel)(BKRequest *);	
	void (^blockAfterRequestEnd)(BKRequest *);

	// TODO: Deprecate this
    id userInfo;

    BKAPIContext *APIContext;
    NSDictionary *requestParameterDict;

    // TODO: Deprecate these    
	__weak BKRequestQueue *requestQueue;
	BOOL cachedResponseUsed;
	BOOL cachedResponseEverUsedInLifetime;
	NSData *rawResponseData;
	NSDictionary *rawXMLMappedResponse;
    id processedResponse;
    NSError *error;

	// TODO: Deprecate this
	NSDate *dateEnqueued;
	NSDate *dateStarted;
	NSDate *dateEnded;
}
+ (id)requestWithAPIContext:(BKAPIContext *)inAPIContext DEPRECATED_ATTRIBUTE;
- (id)initWithAPIContext:(BKAPIContext *)inAPIContext;
- (void)setTarget:(id)inTarget actionOnSuccess:(SEL)inActionOnSuccess actionOnFailure:(SEL)inActionOnFailure DEPRECATED_ATTRIBUTE;

// Keep these
@property (readonly) BKAPIContext *APIContext;
@property (readonly) NSDictionary *requestParameterDict;
@property (readonly) BOOL usesPOSTRequest;
@property (readonly) NSString *HTTPRequestContentType;
@property (readonly) NSURL *requestURL;
@property (readonly) NSData *requestData;
@property (readonly) NSUInteger requestInputStreamSize;
@property (readonly) NSInputStream *requestInputStream;

// Keep these
@property (retain) NSDictionary *rawXMLMappedResponse;
@property (retain) id processedResponse;
@property (retain) NSError *error;


// TODO: Deprecate these
@property (assign) BKRequestState state;
@property (assign) id target;
@property (assign) SEL actionOnSuccess;
@property (assign) SEL actionOnFailure;
@property (copy) void (^blockWhenEnqueued)(BKRequest *);
@property (copy) void (^blockBeforeRequestStart)(BKRequest *);
@property (copy) void (^blockOnSuccess)(BKRequest *);
@property (copy) void (^blockOnFailure)(BKRequest *);
@property (copy) void (^blockOnCancel)(BKRequest *);
@property (copy) void (^blockAfterRequestEnd)(BKRequest *);
@property (retain) id userInfo;
@property (readonly) NSString *HTTPRequestMethod;

// TODO: Deprecate these
@property (readonly) __weak BKRequestQueue *requestQueue;
@property (readonly) BOOL cachedResponseUsed;
@property (readonly) BOOL cachedResponseEverUsedInLifetime;
@property (readonly) NSData *rawResponseData;
@property (readonly) NSUInteger rawResponseDataSize;
@property (readonly) NSString *rawResponseString;

// TODO: Deprecate these
@property (readonly) NSDate *dateEnqueued;
@property (readonly) NSDate *dateStarted;
@property (readonly) NSDate *dateEnded;
@property (readonly) NSTimeInterval elapsedTimeSinceStarted;
@end
