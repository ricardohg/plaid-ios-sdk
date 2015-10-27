//
//  PLDNetworkApi.h
//  Plaid
//
//  Created by Simon Levy on 9/30/15.
//  Copyright © 2015 Vouch Financial, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PLDDefines.h"

typedef void (^PLDNetworkCompletion)(id response, NSError *error);

/**
 Interface to send HTTP requests to the Plaid system. This should only be used internally within the Plaid iOS SDK.
 */
@interface PLDNetworkApi : NSObject

/**
 Initializes a 'PLDNetworkApi' with the desired Plaid environment to be queried against.
 
 @param environment The Plaid environment to be used.
 
 @return A new PLDNetworkApi instance.
 */
- (instancetype)initWithEnvironment:(PlaidEnvironment)environment;

/**
 Send an HTTP request to the Plaid system.
 
 @param path The URL path to query.
 @param method The HTTP method used for this request.
 @param parameters A dictionary of parameters to be passed along with this request. May be nil.
 @param completion The completion handler called when the HTTP request completes.
 */
- (void)executeRequestWithPath:(NSString *)path
                        method:(NSString *)method
                    parameters:(NSDictionary *)parameters
                    completion:(PLDNetworkCompletion)completion;

@end